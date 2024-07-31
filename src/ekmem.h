#ifndef __EKMEM_H
#define __EKMEM_H
#include "utils.h"
/* free memory and set pointer to NULL */
#define EK_FREE(ptr) do { \
    if ((ptr) != NULL) { \
        free((ptr)); \
        (ptr) = NULL; \
    } \
} while (0)

/* Memory allocation function */
void * ek_malloc(size_t nbytes);


#endif
