#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dbg.h"
#include "ekun.h"

EkGstate Global_state;

void * EkMalloc(size_t nbytes){
    assert(nbytes);
    void * ptr = malloc(nbytes);
    if(ptr == NULL)
        Ekerror(Global_state.line_no, "Unable to allocate memory");
    return ptr;
}

typedef struct Ekcode {
    char * source;
    int current;
} Ekcode;

int main(int argc, char * argv){
    Ekcode code_obj;
    code_obj.source = 
}

/* void Ekerror(int line, char *message_fmt, ...){ */
/*     va_list args; */
/*     va_start(args, message_fmt); */
/*     printf("%s:%d", Global_state.filename, line); */
/*     vprintf(message_fmt, args); */
/* } */

