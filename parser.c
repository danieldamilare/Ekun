#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "eklex.h"
#include "y.tab.h"

typedef enum {
    OP_RETURN,

} Bytes;

typedef struct {
    Token current;
    Token previous;
} Parser;

typedef enum {
    PREC_NONE,
    PREC_ASSIGNMENT, //=
    PREC_OR,  // or
    PREC_AND, // and
    PREC_EQUALITY, // == !=
    PREC_COMPARISION, // < > <= >=
    PREC_TERM,       // + -
    PREC_FACTOR,     // * /
    PREC_UNARY,     // ! -
    PREC_CALL,     // . ()
    PREC_PRIMARY
} Precedence;

typedef void (* ParseFn)();

typedef struct {
    ParseFn prefix;
    ParseFn infix;
    Precedence precedence;
} parse_rule;

extern parse_rule rules[];
Parser parser;

static void advance(){
    parser.previous = parser.current;
    for(;;){
        parser.current = get_token();
        break;
    }
}

static void consume(short type, const char * message){
    if(parser.current.token_type == type){
        advance();
        return;
    }
}
static parse_rule * get_rule(short type){
    return &rules[type];
}


static void parse_precedence(Precedence precedence){
    advance();
    ParseFn prefixRule = get_rule(parser.previous.token_type)->prefix;
    if (prefixRule == NULL){
        fprintf(stderr, "Expect expression.");
        return;
    }
    prefixRule();
    while(precedence <= get_rule(parser.current.token_type)->precedence)
        advance();
    ParseFn infixRule = get_rule(parser.previous.token_type)->infix;
    infixRule();
}


static void expression(){
    parse_precedence(PREC_ASSIGNMENT);
}

static void binary(){
    short operator_type = parser.previous.token_type;
    parse_rule * rule = get_rule(operator_type);
    parse_precedence((Precedence)(rule->precedence+1));

    switch (operator_type) {
        case PLUS: printf("OP_ADD\n");
                   break;
        case MINUS: printf("OP_SUBTRACT\n");
                    break;
        case ASTERISK: printf(
                               "OP_MULTIPLY\n");
                       break;
        case SLASH:  printf("OP_DIVIDE\n");
                     break;
        default:
                     return;
    }
}

static void emitReturn(){
    printf(OP_RETURN);
}

static void number(){
    double value = strtod(parser.previous.start, NULL);
    printf("OP_CONSTANT, %lf\n", value);
}

static void unary(){
    short operator_type = parser.previous.token_type;
    parse_precedence(PREC_UNARY);
    switch(operator_type){
        case MINUS:
            printf("OP_NEGATE\n");
            break;
        default:
            return;
    }

}

static void grouping(){
    expression();
    consume(RPAR, "Expect ')', after expression.");
}


bool compile(void){
advance();
expression();
consume(EKEOF, "Expect end of expression.");
}

parse_rule rules[] ={
    [LPAR] =  { grouping, NULL, PREC_NONE },
    [RPAR] = { NULL, NULL, PREC_NONE },
    [MINUS] = { unary, binary, PREC_TERM},
    [PLUS] = { unary, binary, PREC_TERM},
    [ASTERISK] = { unary, binary, PREC_FACTOR},
    [SLASH] = { unary, binary, PREC_FACTOR},
    [SEMI] = { NULL, NULL, PREC_NONE },
    [EQ] = { NULL, NULL, PREC_NONE },
    [NUMBER] = { number, NULL, PREC_NONE },
    [EQEQ] = { NULL, NULL, PREC_NONE },
    [DOGBA] = { NULL, NULL, PREC_NONE },
    [GT] = { NULL, NULL, PREC_NONE },
    [GTEQ] = { NULL, NULL, PREC_NONE },
    [LT] = { NULL, NULL, PREC_NONE },
    [LTEQ] = { NULL, NULL, PREC_NONE },
    [STRING] = { NULL, NULL, PREC_NONE },
    [ATI] = { NULL, NULL, PREC_NONE },
    [TABI] = { NULL, NULL, PREC_NONE },
    [NIGBATI] = { NULL, NULL, PREC_NONE },
    [FI] = { NULL, NULL, PREC_NONE },
    [SE] = { NULL, NULL, PREC_NONE },
    [PARI] = { NULL, NULL, PREC_NONE },
    [TI] = { NULL, NULL, PREC_NONE },
    [BIBEEKO] = { NULL, NULL, PREC_NONE },
    [NEWLINE] = { NULL, NULL, PREC_NONE },
    [PADA] = { NULL, NULL, PREC_NONE },
    [IDENT] = { NULL, NULL, PREC_NONE },
};
