#include "ekmem.h"
#include "ekbytecode.h"
#include "dbg.h"
#include <stdlib.h>
#include "ekvm.h"

static void const_init(Const *array) {
    array->count = 0; 
    array->capacity = 0;
    array->data = NULL;
} 


static void const_free(Const  *array) {               
    for(int i = 0; i < array->count; i++)
        EK_FREE(array->data[i]);
    array->count = 0; 
    array->capacity = 0; 
    EK_FREE(array->data); 
}


static void const_resize(Const *array) {
    DEBUG_PRINT("in const_resize");
    DEBUG_PRINT("former array size: %d", array->capacity);
    int new_capacity = RESIZE(array->capacity);
    DEBUG_PRINT("new size: %d", new_capacity);
    array->data = realloc(array->data,  new_capacity * sizeof(*(array->data))); 
    if(array->data == NULL){
        DEBUG_PRINT("Error allocating memory\n");
        exit(104);
    }
    array->capacity = new_capacity;                         
}


static void const_append(Const  *array,  Lval * data){ 
    DEBUG_PRINT("In constant append");
    DEBUG_PRINT("printing constant\n\n\n");
    for(int i = 0; i < array->count; i++){
        DEBUG_PRINT("%g\n", GET_NUM(array->data[i]));
    }
    DEBUG_PRINT("End of Constant\n\n\n");
    if(array->count >= array->capacity) 
          const_resize(array); 
    DEBUG_PRINT("current_array count: %d", array->count);
    array->data[array->count++]= data; 
    DEBUG_PRINT("new count: %d", array->count);
} 


void code_init(Code * array){ 
    array->count = 0; 
    array->capacity = 0; 
    array->line_count = 0;
    array->line_capacity = 0;
    array->lines = NULL;
    array->line_capacity = 0;
    array->data = NULL; 
    const_init(&array->const_table);
}                                                

void code_free(Code * array){ 
    array->count = 0; 
    array->capacity = 0;
    array->line_count = 0;
    array->line_capacity = 0;
    EK_FREE(array->data); 
    EK_FREE(array->lines);
    const_free(&array->const_table);
}                                                        

                                 
static void code_resize(Code * array){              
    DEBUG_PRINT("in code_resize");
    DEBUG_PRINT("former array size: %d", array->capacity);
    int new_capacity = RESIZE(array->capacity);
    DEBUG_PRINT("new size: %d", new_capacity);
    array->data = realloc(array->data, new_capacity *               
            sizeof(*(array->data)));                           
    array->capacity = new_capacity;                      
}


void ** code_append(Code * array, void * data, int line){
    DEBUG_PRINT("appending to code\n");
    if(array->count >= array->capacity)
        code_resize(array);
    array->data[array->count++] =data;
    
    if(array->line_count > 0 && 
            array->lines[array->line_count-1].line == line)
        goto RETURN;

    if(array->line_count >= array->line_capacity){
        array->line_capacity = RESIZE(array->line_capacity);
        array->lines = realloc(array->lines, array->line_capacity * sizeof(*array->lines));
    }
      Codeline* lines = &array->lines[array->line_count++];
      lines->offset = array->count - 1;
      lines->line = line;
RETURN:
      return &(array->data[array->count-1]);

}

int get_codeline(Code * array, int offset){
    int start = 0;
    int end = array->line_count -1;
    int mid;

    for(;;){
        mid = (start + end) / 2;
        Codeline * line = &array->lines[mid];

        if (offset < line->offset){
            end = mid -1;
        }

        else if (mid == array->line_count -1 ||
                offset < array->lines[mid +1].offset){
            return line->line;
        }

        else{
            start = mid + 1;
        }
    }
}


void * store_constant(Code * array, Lval value){
    Lval * temp = malloc(sizeof(*temp));
    memcpy(temp, &value, sizeof(*temp));
    DEBUG_PRINT("%g", GET_NUM(*temp));
    DEBUG_PRINT("storing constant\n");
    Const * val = &(array->const_table);
    const_append(val, temp);
    return val->data[val->count -1];
}

