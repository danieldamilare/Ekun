#include "ektypes.h"
#include "ekmem.h"
#include <string.h>

 Objstring * make_string(const char * s, int length){
    Objstring * new_str = ek_malloc(sizeof(*new_str) + length + 1);
    new_str->obj.type = OBJ_STRING;
    memcpy(new_str->ch, s, length);
    new_str->ch[length] = '\0';
    new_str->length = length;
    return new_str;
}

