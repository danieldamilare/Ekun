#ifndef __EKUN_H
#define __EKUN_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Supported data type

typedef enum{
    OPT_TOKENIZE = 1 << 0,
    OPT_DISASSEMBLE = 1 << 1,
} Opt;

/* Macro for displaying error message and setting error state */
#define EK_ERROR(line, message, ...) do { \
    fprintf(stderr, "%s:%d: " message "\n", \
        (ek_state.filename? ek_state.filename : "stdin"), line, ##__VA_ARGS__); \
} while (0)

/* Global state structure */
typedef struct EkGlobalState{
    char * progname;
    char * filename;
    FILE * file_handler;
    int line_no;
    bool interactive;
    int has_error;
    unsigned options;
} EkGstate;

extern EkGstate ek_state;
void tokenize(char * source);
#define CMP_EQUAL(s, val) (strcmp((s), (val)) == 0)
#define SET_OPT(opt) ek_state.options |= (opt)
#define IS_SET_OPT(opt) (ek_state.options & (opt))

#endif
