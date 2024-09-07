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
    OBJ_FUNC,
    OBJ_BLTIN,
    OBJ_ARRAY
} Otype;

typedef struct object {
    Otype type;
    struct object * next;
} Object;

typedef struct {
    Dtype type;
    union{
        bool boolean;
        double number;
        Object * obj;
    } val;
} Lval;


typedef struct obj_string{
    Object obj;
    uint32_t hash;
    int length;
    char ch[];
}Objstring;

typedef struct obj_arr {
    Object obj;
    int length;
    int capacity;
    Lval * valuearray;
} Objarray;

typedef Lval (* bltin_func)(int argcount, Lval * args);

typedef struct {
    Object obj;
    bltin_func function;
} Objbltin;

typedef struct {
    Object obj;
    int arity;
    intptr_t start_address;
    Objstring * name;
} Objfunc;


#define KOROFO ((Lval){LVAL_NIL, .val.number = 0})

#define CHECK_TYPE(value, cmp_type) ((value).type == (cmp_type))

#define CREATE_NUM(value) ((Lval){LVAL_NUM, .val.number = (value)})

#define CREATE_BOOL(value) ((Lval){LVAL_BOOL, .val.boolean =(value) })

#define CREATE_STR(value) ((Lval){LVAL_OBJ, .val.obj = (Object *) (value)})

#define CREATE_OBJ(value) ((Lval){LVAL_OBJ, .val.obj = (Object *) (value)})


#define GET_NUM(value) ((value).val.number)
#define GET_BOOL(value) ((value).val.boolean)
#define GET_STR(value)  ((Objstring *)((value).val.obj))
#define GET_CHAR(value) (value->ch) 
#define GET_FUNC(value)  ((Objfunc *)((value).val.obj))
#define GET_OBJ(value) ((Object *)(((value).val.obj)))

#define GET_BLTIN(value) (((Objbltin *) GET_OBJ((value)))->function)

#define GET_ARR(value) ((Objarray *) ((value).val.obj))

#define IS_STR(value) (CHECK_TYPE((value), LVAL_OBJ) &&    \
        GET_OBJ((value))->type == OBJ_STRING)

#define IS_ARR(value) (CHECK_TYPE((value), LVAL_OBJ) && \
        GET_OBJ((value))->type == OBJ_ARRAY)


const char * which_type(Lval obj);

Objstring * make_string(const char * s, int length);
Object * make_obj(int obj_lenght, Otype type);
Objfunc * make_func(void);
Objbltin * make_bltin(bltin_func function);
Objarray * make_array(int arg_count, Lval *start);

bool get_string_index(Objstring * iter, Lval index, Lval * value);
bool get_array_index(Objarray * iter, Lval index, Lval * value);

bool is_false(Lval val);
bool is_iter(Lval val);

#endif
