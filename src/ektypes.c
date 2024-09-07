#include "ektypes.h"
#include "ekun.h"
#include "ekvm.h"
#include "ekmem.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static const char *  Type_info[] = {
    [LVAL_NIL] = "korofo",
    [LVAL_NUM] = "noomba",
    [OBJ_STRING] = "oro",
    [OBJ_FUNC] = "ise",
    [OBJ_BLTIN] = "ise abawa",
    [OBJ_ARRAY] = "apere"
};



char * translate_char(int word){
    char seq[] = "n\nb\br\rt\tf\fv\v\"\"a\a";
    char * c = strchr(seq, word);
    return c? c+1: c;
}

 Objstring * make_string(const char * s, int length){
    uint32_t str_hash = hash(s, length);

    Objstring * new_str = table_find_string(&vm.strings, s, length, str_hash);

    if(new_str != NULL) return new_str;

    new_str = (Objstring *) make_obj(sizeof(*new_str) + length + 1, OBJ_STRING);

    int i = 0, j = 0;
    for(; i < length; i++){
        if(s[i] == '\\'){
            char c = s[++i];
            char * ret = translate_char(c);
            if(ret == NULL){
                new_str->ch[j++] = '\\';
                new_str->ch[j++] = c;
            }
            else new_str->ch[j++] = *ret;
        }
        else new_str->ch[j++] =s[i];
    }
    new_str->ch[j++] = '\0';
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

Objfunc * make_func(void){
    Objfunc * func = (Objfunc *) make_obj(sizeof(*func), OBJ_FUNC);
    func->arity = 0;
    func->name = NULL;
    return func;
}

Objbltin * make_bltin(bltin_func function){
    Objbltin * func = (Objbltin *) make_obj(sizeof(*func), OBJ_BLTIN);
    func->function  = function;
    return func;
}

static bool is_false_obj(Object * obj){

    switch(obj->type){
        case OBJ_STRING:
        {
            return ((Objstring *) obj)->length == 0;
        }
        case OBJ_FUNC:
        case OBJ_BLTIN:
            return false;
        case OBJ_ARRAY:
            return ((Objarray *)obj)->length == 0;
    }
    return false;
}

Objarray * make_array(int arr_count, Lval * start){
    Objarray * arr = (Objarray *)make_obj(sizeof(*arr), OBJ_ARRAY);

#define ARR_INIT 8
#define ARR_RATE 1.5

    int capacity = arr_count < ARR_INIT ? ARR_INIT : arr_count * ARR_RATE;

    arr->valuearray = ek_malloc(capacity * sizeof(Lval));
    for(int i = 0; i < arr_count; i++){
        arr->valuearray[i] = start[i];
    }
    arr->capacity = capacity;
    arr->length = arr_count;
    return arr;

#undef ARR_INIT
#undef ARR_RATE
}

bool get_string_index(Objstring * iter, Lval index, Lval * value){
    int length = iter->length;

    int indx = GET_NUM(index);
    indx = indx< 0? length + indx: indx;
    if (indx < 0 || indx >= length){
        return false;
    }
    *value =  CREATE_STR(make_string(&iter->ch[indx], 1));
    return true;
}

bool get_array_index(Objarray * iter, Lval index, Lval * value){
    int length = iter->length;
    int indx = GET_NUM(index);
    indx = indx< 0? length + indx: indx;
    if (indx < 0 || indx >= length){
        return false;
    }
    *value = iter->valuearray[indx];
    return true;
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

bool is_iter(Lval value){
    if (value.type != LVAL_OBJ) return false;
    int type = value.val.obj->type;
    if (type == OBJ_STRING || type == OBJ_ARRAY)
        return true;
    return false;
}

const char * which_type(Lval obj){
    if(obj.type == LVAL_BOOL){
        return obj.val.boolean? "ooto" : "iro";
    }
    int type = obj.type;
    if(type == LVAL_OBJ){
        type = obj.val.obj->type;
    }
    return Type_info[type];
}
