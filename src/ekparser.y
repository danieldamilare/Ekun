 /* Copyright (C) 2024 Joseph Daniel*/

%{
#include <stdlib.h>
#include <stdint.h>
#include "ekun.h"
#include "eklex.h"
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

static void gen_var(const char *, int);
static void begin_scope(void);
static void end_scope(void);

Compiler * current;

%}

%union {
    Token tok;
    long int ptr;
}

%token <tok> NEWLINE NOOMBA IDENT ORO OOTO IRO
%type <ptr> expr stmt ifstmt assignstmt  printstmt ifblk elsestmt stmtlist  whilestmt forstmt ifikun funcstmt arglist
%type <ptr> elsepatch andpatch orpatch ifpatch loopatch loopatch2 forpatch

//keywords
%token <tok> TI PARI SE FI DOGBA NIGBATI PADA ISE SOPE SI BIBEEKO LATI FUN IFIKUN
%token <tok> LPAR RPAR SEMI

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
            Objstring * string = make_string($1.start, $1.length);
            void * data = write_constant(CREATE_STR(string));
            $$ = CODEGEN2(gvarpush, data);
          }

        | ORO
         {
            DEBUG_PRINT("expr: ORO");
            Objstring * string = make_string($1.start+1, $1.length - 2);
            void * data = write_constant(CREATE_STR(string));
            $$ = CODEGEN2(constpush, data);
          }

        | MINUS expr %prec UNARYMINUS
        { DEBUG_PRINT("expr: MINUS expr");
          CODEGEN(neg);
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
            vm.instructions.data[$3+2] = (void *) code_get_count(&vm.instructions);
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
           gen_var($1.start, $1.length);
           }
           | FI expr SI IDENT 
           {
           $$ = $2;
           gen_var($4.start, $4.length);
           }
           ;

ifstmt: ifblk  PARI {DEBUG_PRINT("ifstmt: ifblk PARI");}
      ;


ifblk: TI expr SE ifpatch stmtlist elsepatch elsestmt {

      DEBUG_PRINT("ifblk: TI expr \
        SE ifpatch stmtlist elsepatch elsestmt ");
      //fix backpatch

      vm.instructions.data[$4 + 1] = (void *) $7;
      /* printf("if patch: %ld %ld\n", $4, $7); */
      vm.instructions.data[$6+1] = (void *) code_get_count(&vm.instructions);

      /* printf("elsepatch: %ld %ld\n", $6, code_get_count(&vm.instructions)); */
      $$ = $2;
      }
   ;

elsestmt:  /* nothing */ {
         DEBUG_PRINT("elsestmt: /*nothing*/");
         $$ =  code_get_count(&vm.instructions); 
        }
        | BIBEEKO  ifblk { /* else if */
         DEBUG_PRINT("elsestmt: BIBEEKO ifblk");
         $$ = $2;
         }
        | BIBEEKO  stmtlist {
         DEBUG_PRINT("elsestmt: BIBEEKO SE stmtlist");
         $$ = $2;}
        ;

whilestmt: NIGBATI loopatch expr loopatch2 SE stmtlist PARI {
         CODEGEN2(jmp, (void *) $2);
         vm.instructions.data[$4+1] = (void *) code_get_count(&vm.instructions);
         $$ = $2;
}

forstmt: FUN IDENT LATI expr SI expr ifikun loopatch forpatch {
        gen_var($2.start, $2.length);
       } SE stmtlist PARI {
       CODEGEN2(jmp, (void *) $8);
       vm.instructions.data[$8+1] = 
           (void *) code_get_count(&vm.instructions);
       $$ = $4;
}

ifikun: /* nothing */ { 
      void * data = write_constant(CREATE_NUM(1));
      $$ = CODEGEN2(constpush, data);
      }
      | IFIKUN expr  {$$ = $2;
      }
      ;

funcstmt: ISE IDENT LPAR arglist RPAR stmt PARI{
        DEBUG_PRINT("funcstmt: ISE IDENT LPAR \
            arglist RPAR stmt PARI");
        }

arglist: 
       ;

/* patches */

loopatch  : {
          $$ = code_get_count(&vm.instructions);
          }
          ;

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

static void gen_var(const char * str, int length){
         Objstring * string = 
         make_string(str, length);
             void * data = write_constant(
         CREATE_STR(string));
        CODEGEN2(gvarstore, data);
}

static void init_compiler(Compiler * compiler){
    compiler->function = NULL;
    compiler->local_count = 0;
    compiler->scope_depth = 0;
    current = compiler;
}

static void begin_scope(){
    current->scope_depth++;
}

static void end_scope(){
    current->scope_depth--;
}

void yyerror(char * message){
    EK_ERROR(ek_state.line_no, "%s", message);
}

int compiler(){

}
