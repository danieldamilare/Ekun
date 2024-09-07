/* Memory Interface for the Yoruba programming language
 * Copyright (C) 2024 Joseph Daniel
 */

#include "ekmem.h"
#include <stdlib.h>
#include <stdio.h>
#include "ekun.h"
#include "utils.h"
#include "dbg.h"

void * ek_malloc(size_t nbytes){
    DEBUG_PRINT("in ek_malloc");
    void * ptr = malloc(nbytes);
    if(ptr == NULL){
        EK_ERROR(ek_state.line_no, "%s: Unable to allocate memory", ek_state.progname);
        exit(1);
    }
    return ptr;
}
