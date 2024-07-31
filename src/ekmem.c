#include "ekmem.h"
#include <stdlib.h>
#include <stdio.h>
#include "ekun.h"
#include "dbg.h"

void * ek_malloc(size_t nbytes){
    DEBUG_PRINT("in ek_malloc");
    assert(nbytes);
    void * ptr = malloc(nbytes);
    if(ptr == NULL){
        fprintf(stderr, "%s: Unable to allocate memory", ek_state.progname);
        exit(1);
    }
    return ptr;
}
