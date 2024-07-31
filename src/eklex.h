#ifndef __EKLEX__H
#define __EKLEX__H
#include <stdio.h>


typedef struct lexer {
    const char * start;
    const char * current;
    int * line_no;
} Lexer;

typedef enum token_type {
    EKEOF = EOF,
/*     NEWLINE, */
/*     NUMBER, */
/*     IDENT, */
/*     STRING, */
/*     SEMI, */

/*     //keywords */
/*     TI  , */
/*     PARI, */
/*     SE, */
/*     FI, */
/*     DOGBA, */
/*     NIGBATI, */
/*     PADA, */
/*     ISE, */
/*     SI, */
/*     ATI, */
/*     TABI, */
/*     BIBEEKO, */

/*     //OPERATOR */
/*     EQ, */
/*     LPAR, */
/*     ASTERISK, */
/*     RPAR, */
/*     PLUS, */
/*     CARET, */
/*     MODULUS, */
/*     MINUS, */
/*     EQEQ, */
/*     SLASH, */
/*     LT, */
/*     LTEQ, */
/*     GT, */
/*     GTEQ, */
/*     NEQ, */
/*     EKEOF, */

} Ttype;

typedef struct token {
    Ttype token_type;
    const char * start;
    int length;
    int line;
} Token;

Token get_token(void);
void init_lexer(char *);
void print_type(int);
int yylex(void);
#endif
