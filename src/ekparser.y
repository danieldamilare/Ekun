 /* Copyright (C) 2024 Joseph Daniel*/

%{
#include <stdlib.h>
#include <stdint.h>
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
Compiler  current;

%}

%union {
    Token tok;
    int args;
    long int ptr;
}

%token <tok> NEWLINE NOOMBA IDENT ORO OOTO IRO
%type <ptr> expr stmt ifstmt assignstmt  printstmt ifblk elsestmt stmtlist  whilestmt forstmt ifikun funcstmt funccall returnstmt
%type <ptr> elsepatch andpatch orpatch ifpatch loopatch loopatch2 forpatch funcpatch
%type <args> paramlist 

//keywords
%token <tok> TI PARI SE FI DOGBA NIGBATI PADA ISE SOPE SI BIBEEKO LATI FUN IFIKUN PE COLON
%token <tok> LPAR RPAR SEMI COMMA

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
         CODEGEN(pop);
       }
       | assignstmt
       { DEBUG_PRINT("stmt: assignstmt"); }
       | ifstmt
       { DEBUG_PRINT("stmt: ifstmt"); }
       | printstmt
       { DEBUG_PRINT("stmt: printstmt"); }
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


stmtlist: /* nothing */ { $$ =  code_get_count(&vm.instructions);}
        | stmtlist stat_end
        | stmtlist stmt stat_end { DEBUG_PRINT("stmtlist: stmlist stmt"); }
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

        | funccall

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


funccall : PE LPAR IDENT loopatch {gen_var($3.start, $3.length, PUSH); } COMMA paramlist RPAR {
             CODEGEN2(call, (void *) ((intptr_t) $7)); 
             $$ = $4;
          } 
         | PE LPAR IDENT RPAR {
            $$ = gen_var($3.start, $3.length, PUSH); 
            CODEGEN2(call, (void *) ((intptr_t) 0));
         }
         ;

printstmt: SOPE expr {
         DEBUG_PRINT("printstmt: SOPE expr");
         CODEGEN(print);
         $$ = $2;
         }
         ;

assignstmt: IDENT EQ expr {
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

elsestmt:  /* nothing */ {
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

forstmt: FUN IDENT LATI expr SI expr ifikun loopatch forpatch {
        gen_var($2.start, $2.length, STORE); } SE stmtlist PARI {
        CODEGEN2(jmp, (void *) $8);
        vm.instructions.data[$8+1] = 
           (void *) code_get_count(&vm.instructions);
        $$ = $4;}
        ;

ifikun: /* nothing */ { 
      void * data = write_constant(CREATE_NUM(1));
      $$ = CODEGEN2(constpush, data);
      }
      | IFIKUN expr  {$$ = $2;}
      ;

returnstmt: PADA {
            void * data = write_constant(KOROFO);
            $$ = CODEGEN2(constpush, data);
            CODEGEN(ret);
          }
          | PADA COLON expr { $$ = $3;  CODEGEN(ret); }
          ;

funcstmt: ISE { begin_scope(); DEBUG_PRINT("matching ise"); }
        IDENT LPAR paramlist
        RPAR { def_func($3, $5);} funcpatch SE 
        stmtlist PARI{
          DEBUG_PRINT("funcstmt: ISE IDENT \
          LPAR arglist RPAR stmt PARI");
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

paramlist:  /* nothing */ {$$ = 0;}
         | IDENT {gen_var($1.start, $1.length, STORE), $$ = 1; }
         | IDENT COMMA paramlist {gen_var($1.start, $1.length, STORE); $$ = $3 + 1;}
         ;

/* patches */

loopatch  : {
          $$ = code_get_count(&vm.instructions);
          }
          ;

funcpatch : { $$ = CODEGEN2(jmp, NULL); }

loopatch2 : {
          $$ = CODEGEN2(jz, NULL);
          CODEGEN(pop);
          }
          ;

ifpatch  : {
         DEBUG_PRINT("in if patch");
         $$ =CODEGEN2(jz, NULL); 
         CODEGEN(pop);}
         ;

orpatch  : {
         $$ = CODEGEN3(orjmp, NULL, NULL);
         }
         ;

andpatch : {
         $$ = CODEGEN3(andjmp, NULL, NULL);
          }
         ;

forpatch: {
        $$ =CODEGEN2(forloop, NULL);
        }
        ;

elsepatch: {
         DEBUG_PRINT("in elsepatch");
         $$ = CODEGEN2(jmp, NULL); 
         CODEGEN(pop);}
         ;

stat_end: NEWLINE
        |  SEMI
        ;

%%

static long int gen_var(const char * str, int length, enum opt option){
         Objstring * string = 
         make_string(str, length);
         void * data = write_constant(
         CREATE_STR(string));
         long int start;
        if(option == STORE){
           start = CODEGEN2(gvarstore, data);
        }
        else {
           start = CODEGEN2(gvarpush, data);
        }
        return start;
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
}

static void end_scope(void){
}


void yyerror(char * message){
    EK_ERROR(ek_state.line_no, "%s", message);
}
