#ifndef __EKTYPE_H
#define __EKTYPE_H
#include <stdbool.h>
#include <stdint.h>
typedef enum {
    LVAL_NUM,
    LVAL_OBJ,
    LVAL_BOOL,
} Dtype;

typedef enum{
    OBJ_STRING,
} Otype;

typedef struct object {
    Otype type;
} Object;

typedef struct obj_string{
    Object obj;
    uint32_t hash;
    int length;
    char * ch;

}Objstring;

typedef struct {
    Dtype type;
    union{
        bool boolean;
        double number;
        Object * obj;
    } val;
} Lval;

#endif
