//Testing struct inheritance
//
typedef struct Obj Obj;
typedef struct ObjString ObjString;

#define OBJ_TYPE(value)

typedef enum {
    OBJ_STRING,
} ObjType;

struct Obj{
    ObjType type;
};

struct ObjString {
    Obj obj;
    int length;
    char * chars;
}
