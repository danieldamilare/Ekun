#ifndef __EKDARRAY_H
#define __EKDARRAY_H

#define INIT_SIZE 8
#define RESIZE_FACTOR 0.5

#define RESIZE(cap) ((cap)? (cap) + (cap) * RESIZE_FACTOR: INIT_SIZE)

#define CREATE_DARRAY(obj_type, type_name)                      \
    typedef struct {                                            \
        int count;                                              \
        int capacity;                                           \
        obj_type *data;                                         \
    } type_name;                                                \

#define IMPLEMENT_DARRAY(obj_type, type_name, prefix)           \
    static void prefix##_init(type_name *array) {               \
        array->count = 0;                                       \
        array->capacity = 0;                                    \
        array->data = NULL;                                     \
    }                                                           \
                                                                \
    static void prefix##_free(type_name *array) {               \
        array->count = 0;                                       \
        array->capacity = 0;                                    \
        EK_FREE(array->data);                                   \
    }                                                           \
                                                                \
    static void prefix##_resize(type_name *array) {             \
        int new_capacity = RESIZE(array->capacity);             \
        array->data = realloc(array->data,                      \
                new_capacity * sizeof(obj_type));               \
        array->capacity = new_capacity;                         \
    }                                                           \
                                                                \
    static void prefix##_append(type_name *array,               \
            obj_type data) {                                  \
        if(array->count >= array->capacity)                     \
              prefix##_resize(array);                           \
        array->data[array->count++]= data;                      \
    }                                                           
#endif
