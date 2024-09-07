#ifndef __UTILS__H
#define __UTILS__H
#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#ifdef EMSCRIPTEN
void custom_printf(const char * format, ...);
#endif
#endif
