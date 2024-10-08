 /* Copyright (C) 2024 Joseph Daniel*/

%{
#include <stdlib.h>
#include <stdint.h>
#include "utils.h"
#include "ekun.h"
#include "eklex.h"
#include "ekbytecode.h"
#include "ekmem.h"
#include "ekparser.h"
#include "ektypes.h"
#include "dbg.h"
#include "ekvm.h"

#define CODEGEN(C) write_code(C, ek_state.line_no)

#define CODEGEN2(C1, C2)                \
write_code(C1, ek_state.line_no);       \
write_code(C2, ek_state.line_no)

#define CODEGEN3(C1, C2, C3)            \
    write_code(C1, ek_state.line_no);   \
    write_code(C2, ek_state.line_no);   \
    write_code(C3, ek_state.line_no)

#define IN_SCOPE() (current.scope_depth > 0)

enum opt{
    STORE,
    PUSH
};

/* generate instructions for both local and global variables */
static long int gen_var(const char *, int, enum opt);

/* begin the scope of a block of statments */
static void begin_scope(void);

/* exit the scope of block of statments */
static void end_scope(void);

/* define a function object and generate the instructions for it */
static void def_func(Token name, int arity);

static intptr_t check_local(Objstring * name);
static void add_local(Objstring * str);
static int in_current_scope(Objstring * string);
Compiler  current;

%}

%union {
    Token tok;
    int args;
    long int ptr;
}

%token <tok> NEWLINE NOOMBA IDENT ORO OOTO IRO
%type <ptr> expr stmt ifstmt assignstmt ifblk elsestmt stmtlist  whilestmt forstmt ifikun funcstmt funccall returnstmt
%type <ptr> elsepatch andpatch orpatch ifpatch loopatch loopatch2 forpatch funcpatch
%type <args> paramlist arglist

//keywords
%token <tok> TI PARI SE FI DOGBA NIGBATI PADA ISE SI BIBEEKO LATI FUN IFIKUN PE COLON DE
%token <tok> LPAR RPAR SEMI COMMA LBRACKET RBRACKET LBRACES RBRACES

//OPERATOR
%right EQ
%left  TABI
%left  ATI
%left  GT GTEQ LT LTEQ EQEQ DOGBA NEQ
%left  PLUS MINUS
%left  ASTERISK SLASH MODULUS
%nonassoc  UNARYMINUS
%nonassoc  NOT
%right CARET

%%

program: stmtlist { 
       DEBUG_PRINT("program stmt stat_end"); 
       CODEGEN(STOP);
       }
       | program error stat_end{ DEBUG_PRINT("program error stat_end"); yyerrok; }
       ;

stmt   : expr  
       { DEBUG_PRINT("stmt: expr"); 
         CODEGEN(ppop);
       }
       | assignstmt
       { DEBUG_PRINT("stmt: assignstmt"); }
       | ifstmt
       { DEBUG_PRINT("stmt: ifstmt"); }
       | whilestmt
       { DEBUG_PRINT("stmt: whilestmt"); }
       | forstmt {
        DEBUG_PRINT("stmt: forstmt");}
       | funcstmt {
         DEBUG_PRINT("stmt: funcstmt");
       }
       | returnstmt {
         DEBUG_PRINT("stmt: returnstmt");
       }
       ;


stmtlist: /* empty */ { $$ =  code_get_count(&vm.instructions);}
        | stmtlist stat_end
        | stmtlist stmt { DEBUG_PRINT("stmtlist: stmlist stmt"); }
        ;

expr    : NOOMBA  
        { DEBUG_PRINT("expr: NUMBER"); 
          double num = check_err(strtod($1.start, NULL));
          void * data = write_constant(CREATE_NUM(num));
          $$ = CODEGEN2(constpush, data);
        }
        | OOTO
          { DEBUG_PRINT("expr: OOTO");
            $$ = CODEGEN(ooto);
          }
        | IRO
          { DEBUG_PRINT("expr: IRO");
            $$ = CODEGEN(iro);
          }
        | IDENT {
            
            DEBUG_PRINT("expr: IDENT");
            $$ = gen_var($1.start, $1.length, PUSH);
          }

        | ORO
         {
            DEBUG_PRINT("expr: ORO");
            Objstring * string = make_string($1.start+1, $1.length - 2);
            void * data = write_constant(CREATE_STR(string));
            $$ = CODEGEN2(constpush, data);
          }

        | LBRACKET loopatch arglist RBRACKET
        {
            $$ = $2;
            CODEGEN2(build_array, $3);
        }

        | funccall
        
        | expr LBRACKET expr RBRACKET 
        {
           
           CODEGEN(index_push);
        }

        | MINUS expr %prec UNARYMINUS
        { DEBUG_PRINT("expr: MINUS expr");
          CODEGEN(neg);
          $$ = $2;
        }
        | expr PLUS expr 
        { DEBUG_PRINT("expr: expr + expr");
          CODEGEN(add);
        }
        | expr GTEQ expr 
        { DEBUG_PRINT("expr: expr >= expr");
          CODEGEN(ge);
        }
        | expr GT expr 
        { DEBUG_PRINT("expr: expr > expr");
          CODEGEN(gt);
        }
        | expr LT expr 
        { DEBUG_PRINT("expr: expr < expr");
          CODEGEN(lt);
        }
        | expr EQEQ expr 
        { DEBUG_PRINT("expr: expr == expr");
          CODEGEN(eq);
        }
        | expr DOGBA expr
          { DEBUG_PRINT("expr: expr DOGBA expr ");
            CODEGEN(eq);
          }
        | expr LTEQ expr 
        { DEBUG_PRINT("expr: expr <= expr");
          CODEGEN(le);
        }
        | expr MINUS expr 
        { DEBUG_PRINT("expr: expr - expr"); 
          CODEGEN(sub);
        }
        | expr ASTERISK expr 
        { DEBUG_PRINT("expr: expr * expr"); 
          CODEGEN(mul);
        }
        | expr SLASH expr 
        { DEBUG_PRINT("expr: expr / expr"); 
          CODEGEN(divide);
        }
        | expr ATI andpatch expr {
            /* if expr is true jump to evaluate next expr */
            vm.instructions.data[$3+1] = (void *) $4;
            /* if expr is false jmp to the end of the production */
            vm.instructions.data[$3+2] = (void *) code_get_count(
                &vm.instructions);
        }
        | expr TABI orpatch expr {
            /* patch if expr is true jump to the end of the rule */
            vm.instructions.data[$3+1] = (void *) code_get_count(&vm.instructions);
            /* if expr is false jump to the next expr */
            vm.instructions.data[$3+2] = (void *) $4;
        }
        | expr CARET expr 
        { DEBUG_PRINT("expr: expr ^ expr"); 
          CODEGEN(power);
        }
        | expr MODULUS expr { 
        DEBUG_PRINT("expr: expr %% expr"); 
        CODEGEN(mod);
        }
        | LPAR expr RPAR 
        { DEBUG_PRINT("expr: (expr)"); 
          $$ = $2;
         }
        ;


funccall : PE LPAR IDENT loopatch {gen_var($3.start, $3.length, PUSH); } COMMA arglist RPAR 
         {
             CODEGEN2(call, (void *) ((intptr_t) $7)); 
             $$ = $4;
          } 
         | PE LPAR IDENT RPAR {
            $$ = gen_var($3.start, $3.length, PUSH); 
            CODEGEN2(call, (void *) ((intptr_t) 0));
         }
         ;

arglist  : /* empty */ { $$ = 0; }
         | expr {$$ = 1; }
         | expr COMMA arglist {$$ = $3 + 1; }


assignstmt: IDENT EQ expr 
          {
             DEBUG_PRINT("assignstmt:\
             IDENT EQ expr");
             $$ = $3;
             gen_var($1.start, $1.length, STORE);
           }
           | FI expr SI IDENT 
           {
             $$ = $2;
             gen_var($4.start, $4.length, STORE);
           }
           | expr LBRACKET expr RBRACKET EQ expr
           {
               CODEGEN(index_store_1);
           }
           | FI expr SI expr LBRACKET expr RBRACKET{
                CODEGEN(index_store_2);
                $$ = $2;
           }
           ;

ifstmt: ifblk  PARI {DEBUG_PRINT("ifstmt: ifblk PARI");}
      ;


ifblk: TI expr SE ifpatch stmtlist elsepatch elsestmt {

      DEBUG_PRINT("ifblk: TI expr \
        SE ifpatch stmtlist elsepatch elsestmt ");
      //fix backpatch

      vm.instructions.data[$4 + 1] = (void *) $7;
      DEBUG_PRINT("if patch: %ld %ld\n", $4, $7);
      vm.instructions.data[$6+1] = (void *) code_get_count(&vm.instructions);

      DEBUG_PRINT("elsepatch: %ld %ld\n", $6, code_get_count(&vm.instructions));
      $$ = $2;
     DEBUG_PRINT("ifblk return count: %ld\n", $$);
      }
   ;

elsestmt:  /* emtpy */ {
         DEBUG_PRINT("elsestmt: /*nothing*/");
         $$ =  code_get_count(&vm.instructions); 
         DEBUG_PRINT(" elsestmt return count: %ld\n", $$);
        }
        | BIBEEKO  ifblk { /* else if */
         DEBUG_PRINT("elsestmt: BIBEEKO ifblk");
         $$ = $2;
         DEBUG_PRINT(" bibeeko ifblk return count: %ld\n", $$);
         }
        | BIBEEKO  stmtlist {
         DEBUG_PRINT("elsestmt: BIBEEKO SE stmtlist");
         $$ = $2;
         DEBUG_PRINT(" bibeeko stmtlist return count: %ld\n", $$);
         }
        ;

whilestmt: NIGBATI loopatch expr loopatch2 SE stmtlist PARI {
         CODEGEN2(jmp, (void *) $2);
         vm.instructions.data[$4+1] = (void *) code_get_count(&vm.instructions);
         $$ = $2;
}

forstmt: FUN IDENT LATI expr DE expr ifikun loopatch forpatch {
        gen_var($2.start, $2.length, STORE); } SE stmtlist PARI {
        CODEGEN2(jmp, (void *) $8);
        vm.instructions.data[$8+1] = 
           (void *) code_get_count(&vm.instructions);
        $$ = $4;}
        ;

ifikun: /* empty */ { 
      void * data = write_constant(CREATE_NUM(1));
      $$ = CODEGEN2(constpush, data);
      }
      | IFIKUN expr  {$$ = $2;}
      ;

returnstmt: PADA {
            if(!IN_SCOPE()){
                EK_ERROR(ek_state.line_no, 
                "Return statement is not allowed outside a function");
                exit(1);
            }
            void * data = write_constant(KOROFO);
            $$ = CODEGEN2(constpush, data);
            CODEGEN(ret);
          }
          | PADA COLON expr { 
                if(!IN_SCOPE()){
                 EK_ERROR(ek_state.line_no, 
                 "Return statement is not allowed outside a function");
                }
                $$ = $3;  CODEGEN(ret); 
           }
          ;

funcstmt: ISE { begin_scope(); DEBUG_PRINT("matching ise"); }
          LPAR IDENT paramlist RPAR { 
          /* this hack allows function to be define in its real scope 
           * since function is bound to an outer scoe */
          current.scope_depth--; def_func($4, $5); current.scope_depth++;
          } funcpatch 
          stmtlist PARI{
            DEBUG_PRINT("funcstmt: ISE IDENT \
            LPAR paramlist RPAR stmt PARI");
            /* function call are expression and therefore must return a value.
            * Every function call return a value. if the user does not return from the
            * function. An implicit return statement is declared with a nil value
            * This won't be called if the user return from the function */
           void * data = write_constant(KOROFO);
           CODEGEN3(constpush, data, ret);
           end_scope();
          vm.instructions.data[$8 + 1] = (void *) code_get_count(&vm.instructions);
        }
        ;

paramlist:  /* empty */ {$$ = 0;}
         | COMMA IDENT {
            Objstring * name = make_string($2.start, $2.length);
            add_local(name);
            $$ = 1; }
         | IDENT paramlist { 
            Objstring * name = make_string($1.start, $1.length);
            add_local(name);
            $$ = $2 + 1;}
         ;

/* patches */

loopatch  : /* empty */ { $$ = code_get_count(&vm.instructions); }
          ;

funcpatch : { $$ = CODEGEN2(jmp, NULL); }
          ;

loopatch2 : /* emtpty */{
          $$ = CODEGEN2(jz, NULL);
          CODEGEN(ppop);
          }
          ;

ifpatch  : /* empty */ {
         DEBUG_PRINT("in if patch");
         $$ =CODEGEN2(jz, NULL); 
         CODEGEN(ppop);}
         ;

orpatch  : /* empty */{
         $$ = CODEGEN3(orjmp, NULL, NULL);
         }
         ;

andpatch : /* empty */ {
         $$ = CODEGEN3(andjmp, NULL, NULL);
          }
         ;

forpatch: /* empty */ {
        $$ =CODEGEN2(forloop, NULL);
        }
        ;

elsepatch: /* empty */ {
         DEBUG_PRINT("in elsepatch");
         $$ = CODEGEN2(jmp, NULL); 
         CODEGEN(ppop);}
         ;

stat_end: NEWLINE
        |  SEMI
        ;

%%

static long int gen_var(const char * str, int length, enum opt option){
         Objstring * string = make_string(str, length);
         long int start;

         //since definition is also the declaration of the variable. We check
         // if we are currently in a scope. if we are and the current variable is 
         // not in the current scope we declare it.

         if(IN_SCOPE() && !in_current_scope(string) && option == STORE){
            add_local(string);
         }

        intptr_t check = check_local(string);

        if(check != -1){
            if(option == STORE){
                start = CODEGEN2(lvarstore, (void *) check);
            }
            else{
                start = CODEGEN2(lvarpush, (void *) check);
            }
        }

        else{

            void * data = write_constant(
                 CREATE_STR(string));
            if(option == PUSH){
                start = CODEGEN2(gvarpush, data);
            }
            else {
                start = CODEGEN2(gvarstore, data);
            }
        }

        return start;
}

static int in_current_scope(Objstring * string){
    for(int i = current.local_count -1; i >= 0; i--){
        Local * local = &current.locals[i];
        if (local->depth < current.scope_depth)
            break;
        if (local->name == string)
            return i;
    }
    return 0;
}

static void add_local(Objstring * str){
    if (current.local_count >= UINT8_COUNT){
        EK_ERROR(ek_state.line_no, "Too many local variables in function.");
        exit(1);
    }

    Local * local = &current.locals[current.local_count++];
    local->name = str;
    local->depth = current.scope_depth;
}

static intptr_t check_local(Objstring * name){
    for (int i = current.local_count -1; i >= 0; i--){
        Local * local = &current.locals[i];
        if (name == local->name){
            return i;
        }
    }
    return -1;
}
            

static void def_func(Token name, int arity){
    if(arity > 255){
        EK_ERROR(ek_state.line_no, "Function can't have more than 255 parameters");
        exit(1);
    }
    Objfunc * function = make_func();
    function->name = make_string(name.start, name.length);
    function->arity = arity;

    /* Starting address 
     * The starting address of the function is 6 instructions after 
     * the current. The six accounts for the two instructions for 
     * pushing the constant to the stack, the two instructions for 
     * defining the function variable and the two instructions for
     * the jmp to skip the function body until it is called
     * I'm guessing it is bad to calculate it like that. but 
     * I don't  know a better way
     */
    function->start_address = code_get_count(&vm.instructions) + 6;
    void * data = write_constant(CREATE_OBJ(function));
    CODEGEN2(constpush, data);
    gen_var(name.start, name.length, STORE);
}

static void begin_scope(void){
    current.scope_depth++;
}


static void end_scope(void){
    current.scope_depth--;
    while(current.local_count > 0 &&
        current.locals[current.local_count -1].depth > current.scope_depth){
        current.local_count--;
    }
}
        

static void compiler_init(Compiler * compiler){
    compiler->local_count = 0;
    compiler->scope_depth = 0;
}

int compile(void){
    compiler_init(&current);
    return yyparse();
}

void yyerror(char * message){
    EK_ERROR(ek_state.line_no, "%s", message);
}
