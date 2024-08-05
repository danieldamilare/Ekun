#include "ekmem.h"
#include "ekbytecode.h"
#include <stdlib.h>


IMPLEMENT_DARRAY(Lval, Const, const)

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
    int new_capacity = RESIZE(array->capacity);
    array->data = realloc(array->data, new_capacity *               
            sizeof(*(array->data)));                           
    array->capacity = new_capacity;                      
}

void code_append(Code * array, void * data, int line){
    if(array->count >= array->capacity)
        code_resize(array);
    array->data[array->count++] =data;
    
    if(array->line_count > 0 && 
            array->lines[array->line_count-1].line == line)
        return;

    if(array->line_count >= array->line_capacity){
        int new_capacity = RESIZE(array->line_capacity);
        array->lines = realloc(array->lines, new_capacity);
    }
      Codeline* lines = &array->lines[array->line_count++];
      lines->offset = array->count - 1;
      lines->line = line;
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
        } else if (mid == array->line_count -1 ||
                offset < array->lines[mid +1].offset){
            return line->line;
        } else{
            start = mid + 1;
        }
    }
}
 
