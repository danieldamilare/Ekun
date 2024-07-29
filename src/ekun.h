#ifndef __EKUN_H
#define __EKUN_H

#define EkFree(ptr) (ptr) && free((ptr)) && (ptr) = NULL


#define Ekerror(line, message, ...) fprintf(stderr, "%s:%d: " message "\n", \
        Global_state.filename, Global_state.line_no, ##__VA_ARGS__), Global_state.error_state = 1

typedef struct EkGlobalState{
    char * filename;
    int line_no;
    int error_state;
    int options;
} EkGstate;

extern EkGstate Global_state;

#define CMP_EQUAL(S, val) strcmp((s), (val)) == 0

#endif
