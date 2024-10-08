#ifndef __EKVM_H
#define __EKVM_H
#include "ekdarray.h"
#include "ekbytecode.h"

#include "ektypes.h"
#include "eksymbol.h"

CREATE_DARRAY(Lval, Stack)

typedef struct {
    Objfunc * function;
    intptr_t slots;
    void ** pc;

} Call_frame;

#define NFRAME 1000

typedef struct _vm {
    /* Vm stack */
    Stack stack;
    /* contains the vm bytecode */
    Code  instructions;
    Object * objects;
    Call_frame frame[NFRAME];
    Call_frame * fp;
    Symbol strings;
    Symbol globals;
} VM;

extern VM vm;

void push(Lval val);
Lval peek(int n);
void vm_init(void);
double check_err(double d);
void vm_cleanup(void);
typedef void (* Opfunc)(void);
intptr_t write_code(void * data, int line);
void * write_constant(Lval value);
void vm_run(void);
void initialize_code(void);
int get_err_no(void);


/* OPCODES */
void constpush(void), sub(void), mod(void), add(void), ppop(void),
     mul(void), power(void), eq(void), le(void), lt(void), gt(void), ge(void),
     neg(void), divide(void), ooto(void), iro(void), gvarpush(void), gvarstore(void), jz(void), jmp(void), andjmp(void), orjmp(void), forloop(void), call(void), ret(void), lvarpush(void), lvarstore(void), index_store_2(void), index_store_1(void), index_push(void), build_array(void);

#define STOP NULL
#endif
