#ifndef __EKUN_H
#define __EKUN_H
#include <stdio.h>
typedef enum{
    OPT_TOKENIZE = 1 << 0,
    OPT_DISASSEMBLE = 1 << 1,
} Opt;


typedef struct EkGlobalState{
    char * progname;
    char * filename;
    FILE * file_handler;
    int line_no;
    int has_error;
    unsigned options;
} EkGstate;

extern EkGstate ek_state;

#define CMP_EQUAL(S, val) strcmp((s), (val)) == 0

#endif
