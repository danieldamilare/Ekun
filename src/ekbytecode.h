#ifndef __EKBYTECODE_H
#define __EKBYTECODE_H

#include "ekdarray.h"
#include "ektypes.h"

typedef struct {
    int offset;
    int line;
} Codeline;

CREATE_DARRAY(Lval, Const);

typedef struct code{                              
    int count;                  
    int capacity;            
    int line_count;
    int line_capacity;
    void ** data;   
    Const const_table;
    Codeline * lines;
} Code;             

void code_append(Code * array, void * data, int line);
void code_free(Code * array);
void code_init(Code * array);

#endif
