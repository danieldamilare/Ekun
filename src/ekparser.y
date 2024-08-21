%{
/* Yacc parser for the Yoruba programming language
 * Copyright (C) 2024 Joseph Daniel
 */

#include <stdlib.h>
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

%}

%union {
    Token tok;
    void  ** ptr;
}

%token <tok> NEWLINE NOOMBA IDENT ORO OOTO IRO
%type <ptr> expr stmt assignstmt

//keywords
%token <tok> TI PARI SE FI DOGBA NIGBATI PADA ISE
%token <tok> SI BIBEEKO 
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
         CODEGEN(print);
       }
       | assignstmt
       ;

stmtlist:  /* nothing */
        | stmtlist stat_end
        | stmtlist stmt stat_end { DEBUG_PRINT("stmtlist: stmlist stmt"); }
        ;

expr    : NOOMBA  
        { DEBUG_PRINT("expr: NUMBER"); 
          double num = check_err(strtod($1.start, NULL));
          void * data = write_constant(CREATE_NUM(num));
          CODEGEN2(constpush, data);
        }
        | OOTO
          { DEBUG_PRINT("expr: OOTO");
            CODEGEN(ooto);
          }
        | IRO
          { DEBUG_PRINT("expr: IRO");
            CODEGEN(iro);
          }
        | IDENT {
            Objstring * string = make_string($1.start, $1.length);
            void * data = write_constant(CREATE_STR(string));
            CODEGEN2(gvarpush, data);
          }

        | ORO
         {
            Objstring * string = make_string($1.start+1, $1.length - 2);
            void * data = write_constant(CREATE_STR(string));
            CODEGEN2(constpush, data);
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
          $$ = $2;}
        ;

 assignstmt: IDENT EQ expr {
           gen_var($1.start, $1.length);
           }
           | FI expr SI IDENT 
           {
           gen_var($4.start, $4.length);
           }

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
/* yydebug = 1; */
void yyerror(char * message){
    EK_ERROR(ek_state.line_no, "%s", message);
}
