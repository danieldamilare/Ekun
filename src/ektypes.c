#include "ektypes.h"
#include "ekvm.h"
#include "ekmem.h"
#include <string.h>
#include <stdbool.h>

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

Objfunc * make_func(){
    Objfunc * func = (Objfunc *) make_obj(sizeof(*func), OBJ_FUNC);
    func->arity = 0;
    func->name = NULL;
    return func;
}

static bool is_false_obj(Object * obj){

    switch(obj->type){
        case OBJ_STRING:
        {
            return ((Objstring *) obj)->length == 0;
        }
        case OBJ_FUNC:
            return false;
    }
    return false;
}

bool is_false(Lval val){
    switch(val.type){
        case LVAL_NUM:
            return val.val.number == 0;
        case LVAL_BOOL:
            return val.val.boolean == false;
        case LVAL_NIL:
            return true;
        case LVAL_OBJ:
            return is_false_obj((Object *) val.val.obj);
    }
    return false;
}
