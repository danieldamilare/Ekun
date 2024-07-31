#ifndef __EKMEM_H
#define __EKMEM_H
#include "utils.h"
/* free memory and set pointer to NULL */
#define ek_free(ptr) do { \
    if ((ptr) != NULL) { \
        free((ptr)); \
        (ptr) = NULL; \
    } \
} while (0)

/* Display error message and set the error state of the program */
#define ek_error(line, message, ...) do { \
    fprintf(stderr, "%s:%d: " message "\n", \
        (ek_state.filename? ek_state.filename : "stdin"), line, ##__VA_ARGS__); \
    ek_state.has_error = 1; \
} while (0)

/* Memory allocation function */
void * ek_malloc(size_t nbytes);


#endif
