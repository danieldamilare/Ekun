#include "ektypes.h"
#include "ekvm.h"
#include "ekmem.h"
#include <string.h>

 Objstring * make_string(const char * s, int length){
    uint32_t str_hash = hash(s, length);

    Objstring * new_str = table_find_string(&vm.strings, s, length, str_hash);

    if(new_str != NULL) return new_str;

    new_str = (Objstring *) make_obj(sizeof(*new_str) + length + 1, OBJ_STRING);
    memcpy(new_str->ch, s, length);
    new_str->ch[length] = '\0';
    new_str->length = length;
    new_str->hash = str_hash;
    table_put(&vm.strings, new_str, KOROFO);
    return new_str;
}

Object * make_obj(int obj_length, Otype type){
    Object * obj = ek_malloc(obj_length);
    obj->type = type;
    obj->next = vm.objects;
    vm.objects = obj;
    return obj;
}

