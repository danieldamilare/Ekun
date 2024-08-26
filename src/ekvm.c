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
                                                        
/* pop current value from stack  */
Lval pop(void){

    //>todo Update error handling
    if(vm.stack.count <= 0){
        fprintf(stderr, "Error: Stack underflow\n");
        exit(1);
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
}

static void free_objects(){
    for(Object * obj = vm.objects; obj != NULL;){
        Object * next = obj->next;
        free(obj);
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

intptr_t write_code(void * data, int line){
    return code_append(&vm.instructions, data, line);
}

void execute(void ** instructions){
    vm.pc = instructions;
    for(; *vm.pc != NULL; ){
        Opfunc function = *vm.pc++;
        function();
    }
}

void * vm_advance(void){
    void * data = *vm.pc;
    vm.pc++;
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

void vm_run(void){
    vm.progbase = vm.instructions.data;
    execute(vm.progbase);
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
        vm.pc = &vm.instructions.data[num];
    }
}


void jmp(void){
    intptr_t num = (intptr_t) vm_advance();
    /* printf("regained patch: patch is now: %ld\n", num); */
    vm.pc = &vm.instructions.data[num];
}

void andjmp(void){
    intptr_t expr_true = (intptr_t) vm_advance();
    intptr_t expr_false = (intptr_t) vm_advance();
    if(is_false(peek(0))){ //leave the value on the stack as the result of the expr
        vm.pc = &vm.instructions.data[expr_false];
    } else {  
    //if true we need to evaluate the next value and use as the result of the expr
        pop();
        vm.pc = &vm.instructions.data[expr_true];
    }
}

void orjmp(void){
    intptr_t expr_true = (intptr_t) vm_advance();
    intptr_t expr_false = (intptr_t) vm_advance();

    if(is_false(peek(0))){ //
        pop();
        vm.pc = &vm.instructions.data[expr_false];
    } else{ //leave the value on the stack as the result of the expr
        vm.pc= &vm.instructions.data[expr_true];
    }

}

void forloop(void){
    int jmp_addr = (intptr_t) vm_advance();
    EQUAL_TYPE(LVAL_NUM);
    double incr = GET_NUM(peek(0));
    double num2 = GET_NUM(peek(1));
    double num1 = GET_NUM(peek(2));
    if(num1 > num2){
        vm.pc = &vm.instructions.data[jmp_addr];
    } else {
        push(CREATE_NUM(num1));
        num1 += incr;
        vm.stack.data[vm.stack.count -4] = CREATE_NUM(num1);
    }
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
        EK_ERROR(ek_state.line_no, "error trying to divide by zero");
    }
    push(CREATE_NUM(num1/num2));
}

void mod(void){
    EQUAL_TYPE(LVAL_NUM);
    double num2 = GET_NUM(pop());
    double num1 = GET_NUM(pop());
    if(num2 == 0){
        EK_ERROR(ek_state.line_no, "error trying to divide by zero");
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
    else if(CHECK_TYPE(*peek(0).val.obj, OBJ_STRING) &&
            CHECK_TYPE(*peek(1).val.obj, OBJ_STRING)){
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
    int offset = vm.pc -vm.instructions.data -1;
    return get_codeline(&vm.instructions, offset);
}


double check_err(double d){
    if (errno == EDOM || errno == ERANGE){
        errno = 0; 
        EK_ERROR(get_err_no(), "Number out of range");
    }
    return d;
}
