#include <stdio.h>
#include <stdlib.h>

#include "dbg.h"
#include "ekvm.h"
#include "eksymbol.h"
#include "ektypes.h"
#include "ekun.h"
#include "math.h"
#include "ekmem.h"
#include "ekbytecode.h"

IMPLEMENT_DARRAY(Lval, Stack, stack)

VM vm;

#define VM_STACK_TOP (&vm.stack.data[vm.stack.count -1])
                                                        
/* pop current value from stack  */
Lval pop(void){

    //>todo Update error handling
    if(vm.stack.count <= 0){
        fprintf(stderr, "Error: Stack underflow\n");
        // exit(1);
        abort();
    }

    vm.stack.count--;
    return vm.stack.data[vm.stack.count];
}

void push(Lval val){
    stack_append(&vm.stack, val);
}


Lval peek(int i){
    return vm.stack.data[vm.stack.count - 1 -i];
}

void vm_init(void){
    stack_init(&vm.stack);
    code_init(&vm.instructions);
    init_table(&vm.globals);
    init_table(&vm.strings);
    vm.objects = NULL;
    vm.fp = vm.frame;
}

static void free_objects(){
    for(Object * obj = vm.objects; obj != NULL;){
        Object * next = obj->next;
        switch(obj->type){
            case OBJ_FUNC:
                free((Objfunc *) obj);
                break;
            case OBJ_BLTIN:
                free((Objbltin *) obj);
                break;
            default:
                free(obj);
        }
        obj = next;
    }
}

void vm_cleanup(void){
    stack_free(&vm.stack);
    code_free(&vm.instructions);
    free_objects();
    free_entries(&vm.globals);
    free_entries(&vm.strings);
}

static void add_builtin(const char * name, bltin_func function){
    push(CREATE_OBJ(make_string(name, strlen(name))));
    push(CREATE_OBJ(make_bltin(function)));
    table_put(&vm.globals, GET_STR(peek(1)), peek(0));
    pop();
    pop();
}

intptr_t write_code(void * data, int line){
    return code_append(&vm.instructions, data, line);
}

void execute(void ** instructions){
    vm.fp->pc = instructions;
    Opfunc function;

    for(; *vm.fp->pc != NULL; ){
        function = *(vm.fp->pc)++;
        function();
    }
}

void vm_run(void){
    //iniitialize the starting function.
    Objfunc * function = make_func();
    function->start_address = 0; //initial bytecode starts at zero address
    vm.fp->slots = 0;
    vm.fp->pc = vm.instructions.data;
    vm.fp->function =  function;
    execute(vm.instructions.data);
}

void * vm_advance(void){
    void * data = *vm.fp->pc;
    vm.fp->pc++;
    return data;
}

void initialize_code(void){
    code_free(&vm.instructions);
    code_init(&vm.instructions);
}


static void concat_string(void){
    Objstring * str2 = GET_STR(pop());
    Objstring * str1 = GET_STR(pop());
    int length = str1->length + str2->length;
    char word[length];
    memcpy(word, str1->ch, str1->length);
    memcpy(word + str1->length, str2->ch, str2->length);;
   uint32_t str_hash = hash(word, length);
    Objstring * new_str = table_find_string(&vm.strings, word, length, str_hash);

    if(new_str != NULL){
        push(CREATE_STR(new_str));
        return;
    }

    new_str = (Objstring *) make_obj(sizeof(*new_str)+length+1, OBJ_STRING);
    memcpy(new_str->ch, word, length);

    new_str->ch[length] = '\0';
    new_str->length = length;
    new_str->hash = str_hash;
    table_put(&vm.strings, new_str, KOROFO);
    push(CREATE_STR(new_str));
}

void constpush(void){
    Lval  val = * (Lval *) vm_advance();
    push(val);
}

/* store global variable */
void gvarstore(void){
    Objstring * var = GET_STR(*((Lval *)vm_advance()));
    table_put(&vm.globals, var, peek(0));
    pop();
}

void gvarpush(void){
    Objstring * var = GET_STR(*((Lval *)vm_advance()));
    Lval value;
    if(table_get(&vm.globals, var, &value))
        push(value);
    else {
        table_put(&vm.globals, var, KOROFO);
        push(KOROFO);
    }
}

/* control flow functions */
void jz(void){
    intptr_t num = (intptr_t) vm_advance();
    /* printf("regained patch: patch is now: %ld\n", num); */
    /* printf("condition is %s\n", is_false(peek(0))? "false": "true"); */
    if (is_false(peek(0))){
        /* printf("condition is 0... skipping\n"); */
        vm.fp->pc = &vm.instructions.data[num];
    }
}


void jmp(void){
    intptr_t num = (intptr_t) vm_advance();
    /* printf("regained patch: patch is now: %ld\n", num); */
    vm.fp->pc = &vm.instructions.data[num];
}

void andjmp(void){
    intptr_t expr_true = (intptr_t) vm_advance();
    intptr_t expr_false = (intptr_t) vm_advance();
    if(is_false(peek(0))){ //leave the value on the stack as the result of the expr
        vm.fp->pc = &vm.instructions.data[expr_false];
    } else {  
    //if true we need to evaluate the next value and use as the result of the expr
        pop();
        vm.fp->pc = &vm.instructions.data[expr_true];
    }
}

void orjmp(void){
    intptr_t expr_true = (intptr_t) vm_advance();
    intptr_t expr_false = (intptr_t) vm_advance();

    if(is_false(peek(0))){ //
        pop();
        vm.fp->pc = &vm.instructions.data[expr_false];
    } else{ //leave the value on the stack as the result of the expr
        vm.fp->pc= &vm.instructions.data[expr_true];
    }

}

void forloop(void){
    int jmp_addr = (intptr_t) vm_advance();
    EQUAL_TYPE(LVAL_NUM);
    double incr = GET_NUM(peek(0));
    double num2 = GET_NUM(peek(1));
    double num1 = GET_NUM(peek(2));
    if(num1 > num2){
        vm.fp->pc = &vm.instructions.data[jmp_addr];
    } else {
        push(CREATE_NUM(num1));
        num1 += incr;
        vm.stack.data[vm.stack.count -4] = CREATE_NUM(num1);
    }
}

static void callval(Objfunc * function, int arg_count){

    if(function->arity != arg_count){
        EK_ERROR(get_err_no(), "function: %s takes %d %s"                "instead of %d",
        GET_CHAR(function->name), function->arity,
        function->arity == 1? "argument": "arguments" , arg_count);
    }
    //initialize Call frame
    //check for stack overflow
    if(vm.fp+1 >= &vm.frame[NFRAME]){
        EK_ERROR(get_err_no(), "Stack Overflow");
        exit(1);
    }
    Call_frame * fp = ++vm.fp;
    fp->function = function;
    fp->slots = vm.stack.count - arg_count;
    fp->pc = &vm.instructions.data[function->start_address];
}

void call(void){
    int arg_count = (intptr_t) vm_advance();
    Lval val = peek(arg_count);
    if(CHECK_TYPE(val, LVAL_OBJ)){
        switch(val.val.obj->type){
            case OBJ_FUNC:
                callval(GET_FUNC(val), arg_count);
                return;

            case OBJ_BLTIN:
            {
                bltin_func function = GET_BLTIN(val);
                Lval value =function(arg_count,
                        VM_STACK_TOP - arg_count);
                vm.stack.count -= arg_count -1; //reset the stack minus 1 to remove the function on the stack
                push(value);
                return;
           }

            default:
                break;
        }
    }
    EK_ERROR(get_err_no(), "Can only call function type ");
    exit(1);
}


void ret(void){
    Lval  result = pop();
    //pop all locals from stack and store return value
    vm.stack.count = vm.fp->slots - 1; 
    push(result);
    vm.fp--;
}


/* binary operation */

void sub(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    push(CREATE_NUM(num1 - num2));
}

void divide(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    if(num2 == 0){
        EK_ERROR(get_err_no(), "error trying to divide by zero");
    }
    push(CREATE_NUM(num1/num2));
}

void mod(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    if(num2 == 0){
        EK_ERROR(get_err_no(), "error trying to divide by zero");
    }
    long quotient = (long)(num1) / (long)(num2);
    double remainder = num1 - quotient * num2;
    push(CREATE_NUM(remainder));
}

void mul(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    push(CREATE_NUM(check_err(num1 * num2)));
}

void power(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    push(CREATE_NUM(check_err(pow(num1, num2))));
}

void add(void){
    if(CHECK_TYPE(peek(0), LVAL_NUM) && CHECK_TYPE(peek(1), LVAL_NUM)){
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    push(CREATE_NUM(num1 + num2));
    }
    else if(IS_STR(peek(0)) && IS_STR(peek(1))){
        concat_string();
    }
}


void eq(void){
    Lval num2 = pop();
    Lval num1 = pop();
    bool op = true;
    if(num2.type != num1.type)
        op = false;
    else{
        switch((short) num2.type){
            case LVAL_NUM:
                op = GET_NUM(num1) == GET_NUM(num2);
                break;
            case LVAL_BOOL:
                op = GET_BOOL(num1) == GET_BOOL(num2);
                break;
            case LVAL_OBJ:
                if(num2.val.obj->type == OBJ_STRING){
                    op = GET_STR(num1) == GET_STR(num2);
                }
        }
    }
    push(CREATE_BOOL(op));
}


void le(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2= GET_NUM(pop());
    double num1= GET_NUM(pop());
    push(CREATE_BOOL(num1 <= num2));
}


void lt(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2= GET_NUM(pop());
    double num1= GET_NUM(pop());
    push(CREATE_BOOL(num1 < num2));
}

void neg(void){
    Lval num = peek(0);

    if(!CHECK_TYPE(num, LVAL_NUM)){
        EK_ERROR(get_err_no(), "Error attempting to negate a data type not number");
    }

    vm.stack.data[vm.stack.count -1] = CREATE_NUM(-GET_NUM(num));
}

void ooto(void){
    push(CREATE_BOOL(true));
}

void iro(void){
    push(CREATE_BOOL(false));
}

void gt(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2= GET_NUM(pop());
    double num1= GET_NUM(pop());
    push(CREATE_BOOL(num1 > num2));
}


void ge(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2= GET_NUM(pop());
    double num1= GET_NUM(pop());
    push(CREATE_BOOL(num1 >= num2));
}


void print(void){
    Lval value = pop();
    switch(value.type){
        case  LVAL_NUM:
            printf("%.8g\n", value.val.number);
            break;
        case LVAL_BOOL:
            printf("%s\n", value.val.boolean?"ooto": "iro");
            break;
        case LVAL_NIL:
            printf("korofo\n");
            break;
        case LVAL_OBJ:
            {
                Object * obj = value.val.obj;

            switch(obj->type){
                case OBJ_STRING:
                    printf("%s\n", 
                            ((Objstring *)obj)->ch);
                    break;
                case OBJ_FUNC:
                    printf("<ise %s>\n", ((Objfunc *) obj)->name->ch);
                    break;
                case OBJ_BLTIN:
                    printf("<ise abawa >\n");
                    break;
                default:
                    break;
            }
                        
            }
            break;
    }
}

void * write_constant(Lval value){
    return store_constant(&vm.instructions, value);
}

int get_err_no(void){
    // the program counter is pointing to the next instruction
    // so we subtract one to get the distance from the program base
    int offset = vm.fp->pc -vm.instructions.data -1;
    return get_codeline(&vm.instructions, offset);
}


double check_err(double d){
    if (errno == EDOM || errno == ERANGE){
        errno = 0; 
        EK_ERROR(get_err_no(), "Number out of range");
    }
    return d;
}
