#include "ekvm.h"
#include "utils.h"

static struct opnames {
    Opfunc func;
    char *name;
    int nargs;
    char *comments;
} match_func[] = {
    {constpush, "Constpush", 1, "Push constant onto stack"},
    {sub, "sub", 0, "Subtract top two values on stack, push result"},
    {mod, "mod", 0, "Modulus of top two values on stack, push result"},
    {add, "add", 0, "Add top two values on stack, push result"},
    {gt, "gt", 0, "Push true if second value > top value"},
    {mul, "mul", 0, "Multiply top two values on stack, push result"},
    {power, "power", 0, "Raise second value to top value, push result"},
    {eq, "eq", 0, "Push true if top two values are equal"},
    {le, "le", 0, "Push true if second value <= top value"},
    {lt, "lt", 0, "Push true if second value < top value"},

    /* {print, "print", 0, "Pop and print top value on stack"}, */
    {neg, "neg", 0, "Negate top value on stack"},
    {divide, "divide", 0, "Divide second value by top value, push result"},
    {ooto, "ooto", 0, "Push true onto stack"},
    {iro, "iro", 0, "Push false onto stack"},
    {gvarstore, "gvarstore", 1, "Store top value in global var"},
    {gvarpush, "gvarpush", 1, "Push global var onto stack"},
    {jz, "jz", 1, "Jump to given location if top value is false"},
    {jmp, "jmp", 1, "Unconditional jump to location"},
    {andjmp, "andjmp", 2, "Short-circuit 'and' with jump"},
    {orjmp, "orjmp", 2, "Short-circuit 'or' with jump"},
    {forloop, "forloop", 1, "Set up and start a for loop"},
    {call, "call", 1, "Call function and push new call frame"},
    {ret, "ret", 0, "Return from function, pop the function call frame"},
    {lvarpush, "lvarpush", 1, "Push local var onto stack"},
    {lvarstore, "lvarstore", 1, "Store top value in local var"},
    {ppop, "ppop", 0, "Pop and discard top value on stack"},
    {NULL, NULL, 0, NULL}
};

void print_disassemble(Lval value){
    switch(value.type){
        case  LVAL_NUM:
            printf("%.8g ", value.val.number);
            break;
        case LVAL_BOOL:
            printf("%s ", value.val.boolean?"ooto": "iro");
            break;
        case LVAL_NIL:
            printf("korofo ");
            break;
        case LVAL_OBJ:
            {
                Object * obj = value.val.obj;

            switch(obj->type){
                case OBJ_STRING:
                    printf("\"%s\" ", 
                            ((Objstring *)obj)->ch);
                    break;
                case OBJ_FUNC:
                    printf("<function %s> ", ((Objfunc *) obj)->name->ch);
                    break;
                case OBJ_BLTIN:
                    printf("<builtin function> ");
                    break;
                default:
                    break;
            }
                        
            }
            break;
    }
}

static struct opnames *get_instruction(Opfunc function){
    for(int i  = 0;  match_func[i].func != NULL; i++){
        if(match_func[i].func == function)
            return &match_func[i];
    }
    return NULL;
}

void disassemble(void){
    void ** instructions = vm.instructions.data;
    int i = 0;

    while(instructions[i] != NULL){
        struct opnames * inst = get_instruction((Opfunc) instructions[i]);
        if(inst == NULL) break;

        printf("%03d:%3s", i, "");
        printf("%-11s ", inst->name);
        bool is_integer_args = (inst->func == jz || inst->func == jmp 
                || inst->func == andjmp || inst->func == orjmp 
                || inst->func == forloop|| inst->func == lvarpush
                || inst->func == lvarstore || inst->func == call);

        for(int j = 0; j < inst->nargs; j++){
            if (is_integer_args){
                printf("%03ld", (intptr_t)instructions[++i]);
            }
            else{
                print_disassemble(*(Lval *)instructions[++i]);
            }
            printf("%5s", "");
        }
        printf("\n");
        /* printf(" %10s;%s\n", "", inst->comments); */

        i++;
    }
}
