#ifndef __EKPARSER_H
#define __EKPARSER_H
#include <stdint.h>
#include "ektypes.h"
#include "eklex.h"
void yyerror(char *);

#define UINT8_COUNT  (UINT8_MAX + 1)


typedef struct Local {
    Objstring * name; 
    int depth;
} Local;

typedef enum {
    func_type,
    script_type
} Func_type;

typedef struct Compiler {
    Local locals [UINT8_COUNT];
    int local_count;
    int scope_depth;
} Compiler;

extern Compiler  current;
int compile(void);

#endif
