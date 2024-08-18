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
    vm.globals = new_table();
}

void vm_cleanup(void){
    stack_free(&vm.stack);
    code_free(&vm.instructions);
    free_entries(vm.globals);
    EK_FREE(vm.globals);
}

void ** write_code(void * data, int line){
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

void vm_run(void){
    vm.progbase = vm.instructions.data;
    execute(vm.progbase);
}

void constpush(void){
    Lval  val = * (Lval *) vm_advance();
    push(val);
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
}


void eq(void){
    Lval num2 = pop();
    Lval num1 = pop();
    bool op;
    if(num2.type != num1.type)
        op = false;
    else{
        switch((short) num2.type){
            case LVAL_NUM:
                op = GET_NUM(num1) == GET_NUM(num2);
                break;
            case LVAL_BOOL:
                op = GET_BOOL(num1) == GET_BOOL(num2);
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
    push(CREATE_BOOL(num1 <= num2));
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
        case LVAL_OBJ:
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
