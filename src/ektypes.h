#ifndef __EKTYPE_H
#define __EKTYPE_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
    LVAL_NUM,
    LVAL_OBJ,
    LVAL_NIL,
    LVAL_BOOL,
} Dtype;

typedef enum{
    OBJ_STRING = 300,
} Otype;

typedef struct object {
    Otype type;
    struct object * next;
} Object;

typedef struct obj_string{
    Object obj;
    uint32_t hash;
    int length;
    char ch[];
}Objstring;

typedef struct {
    Dtype type;
    union{
        bool boolean;
        double number;
        Object * obj;
    } val;
} Lval;

#define KOROFO (Lval){LVAL_NIL, .val.number = 0}

#define CHECK_TYPE(value, cmp_type) ((value).type == (cmp_type))

#define CREATE_NUM(value) (Lval){LVAL_NUM, .val.number = (value)}

#define CREATE_BOOL(value) (Lval){LVAL_BOOL, .val.boolean =(value) }

#define CREATE_STR(value) (Lval){LVAL_OBJ, .val.obj = (Object *) (value)}

#define GET_NUM(value) ((value).val.number)
#define GET_BOOL(value) ((value).val.boolean)
#define GET_STR(value)  (Objstring *)((value).val.obj)

#define EQUAL_TYPE(type)                                            \
    do{                                                             \
        if(!CHECK_TYPE(peek(0), (type))  ||                       \
                !CHECK_TYPE(peek(1), (type))){                    \
            EK_ERROR(get_err_no(), "operands must be %s", gettype((type)));    \
            exit(1); \
        }                                                           \
    }while(0);                                      


static inline const char * gettype(short type){
    switch(type){
        case LVAL_NUM:
            return "number";
        case LVAL_BOOL:
            return "boolean";
        case OBJ_STRING:
            return "string";
        default:
            return NULL;
    }
}

Objstring * make_string(const char * s, int length);
Object * make_obj(int obj_lenght, Otype type);

#endif
