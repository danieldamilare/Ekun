/* Lexical analyzer for the Yoruba programming language
 * Copyright (C) 2024 Joseph Daniel 
 *
 */

#include <stdio.h>
#include "eklex.h"
#include "ekun.h"
#include <stdlib.h>
#include "dbg.h"
#include "ctype.h"
#include "y.tab.h"

/* global variable for the lexer */
static Lexer lex;


void init_lexer(char * source){
    DEBUG_PRINT("inside init_lexer");
    lex.start = source;
    lex.current = source;
    lex.line_no = &ek_state.line_no;
    DEBUG_PRINT("lexer current: %s", lex.current);
    DEBUG_PRINT("lexer start: %s", lex.start);
    DEBUG_PRINT("lexer line_no: %d", *lex.line_no);
}


static Token initialize_token(Ttype token_type){
    Token new;
    new.line = *lex.line_no;
    new.length = (int) (lex.current - lex.start);
    new.start = lex.start;
    new.token_type = token_type;
    return new;
}


static int next_char(void){
    return *lex.current++;
}


static int peek(void){
    return *lex.current;
}


int ek_isalpha(int c){
    if (isalpha(c) || c == '_') return 1;
    return 0;
}


static Token follow(int expect, Ttype follow, Ttype first){
    if(peek() == expect){
        next_char();
        return initialize_token(follow);
    }
    else
    {
        next_char();
        return initialize_token(first);
    }
}


static void skip_space(void){
    while(peek() == ' ' || peek() == '\t')
        next_char();
}


static int peek_count(int n){
    return *(lex.current + n);
}


static void skip_comment(void){
    if(peek() == '-' && peek_count(1) == '-'){
        while(peek() != '\n' && peek() != '\0')
            next_char();
    }
}


Token token_number(void){
    while(isdigit(peek())){
        next_char();
    }
    if(peek() == '.' && isdigit(peek_count(1))){
        next_char();
        while(isdigit(peek()))
            next_char();
    }
    if (peek() == '.' || ek_isalpha(peek())) {
        EK_ERROR(*lex.line_no, "error in digit %.*s", (int)(lex.current - lex.start) + 1, lex.start);
        exit(1);
    }
    return initialize_token(NOOMBA);
}


Token token_string(void){

    while(peek() != '"'  || peek() == '\0' 
            || peek() == '\n') {// does not support multiline string
        next_char();
    }

    if(peek() == '\n' || peek() == '\0'){
        EK_ERROR(*lex.line_no, "Sting unterminated before %s",
                (peek() == '\n')? "newline" : "end of file");
        exit(1);
    }
    next_char(); // skip to the beginning of the next token;
    return initialize_token(ORO);
}

Token check_keyword(char * keyword, char * expect, Ttype ifexpect){
    if(strlen(keyword) != strlen(expect))
        return initialize_token(IDENT);
    if(strncmp(keyword, expect, strlen(expect)) == 0)
        return initialize_token(ifexpect);
    else return initialize_token(IDENT);
}

Token token_identifier(char * word){
    // no keyword with a length of 1
    if(strlen(word) == 1) return initialize_token(IDENT); 

    switch(word[0]){

        case 't':
            switch(word[1]){
                case 'a':
                    return check_keyword(word+2, "bi", TABI);
                case 'i':
                    if(strlen(word) == 2)
                        return initialize_token(TI);
                    else return initialize_token(IDENT);
                default:
                    return initialize_token(IDENT);
            }
            break;

        case 'p':
            switch(word[1]){
                case 'a':
                    if (*(word+2) == 'd')
                        return check_keyword(word+3, "a", PADA);

                    else if (*(word+2) == 'r')
                        return check_keyword(word+3, "i", PARI);
                    else
                        return initialize_token(IDENT);
                default:
                    return initialize_token(IDENT);
            }
            break;

        case 'n': return check_keyword(word+1, "igbati", NIGBATI);
        case 'd': return check_keyword(word+1, "ogba", DOGBA);
        case 'f': return check_keyword(word+1, "i", FI);
        case 'a': return check_keyword(word+1, "ti", ATI);
        case 'o': return check_keyword(word+1, "oto", OOTO);

        case 'i': 
                  switch(word[1]){
                      case 'r': return check_keyword(word+2, "o", IRO);
                      case 's': return check_keyword(word+2, "e", ISE);
                      default: return initialize_token(IDENT);
                  }
                  break;

        case 'b': return check_keyword(word+1, "ibeeko", BIBEEKO);

        case 's': 
                  switch(word[1]){
                      case 'i': 
                          if(strlen(word) == 2)
                              return initialize_token(SI);
                          else
                              return initialize_token(IDENT);
                      case 'e':
                          if (strlen(word) == 2)
                              return initialize_token(SE);
                          else
                              return initialize_token(IDENT);
                     default:
                          return initialize_token(IDENT);
                  }
                  break;

        default:
                  return initialize_token(IDENT);
    }
}

Token token_ident(void){
    while(ek_isalpha(peek()) || isdigit(peek()))
        next_char();
    char word[512] = {0};
    strncpy(word, lex.start, lex.current - lex.start);
    return token_identifier(word);
}

Token get_token(void){
    DEBUG_PRINT("In get_token");

    /* set the beginning of the next token */
    skip_space();
    skip_comment();
    lex.start = lex.current;
    int c = next_char(); //declared as int to handle eof
                         //
    switch(c){
        case '+': return initialize_token(PLUS);
        case ')': return initialize_token(RPAR);
        case '(': return initialize_token(LPAR);
        case '-': return initialize_token(MINUS);
        case '*': return initialize_token(ASTERISK);
        case ';': return initialize_token(SEMI);
        case '%': return initialize_token(MODULUS);
        case '^': return initialize_token(CARET);
        case '/': return initialize_token(SLASH);
        case '>': return follow('=', GTEQ, GT);
        case '!': return follow('=', NEQ, NOT);
        case '<': return follow('=', LTEQ, LT);
        case '=': return follow('=', EQEQ, EQ);
        case '"': return token_string();
        case '\n': 
                  (*lex.line_no)++;
                  return initialize_token(NEWLINE);
        case '\0': return initialize_token(EKEOF);
        default:
            if (isdigit(c)) return token_number();
            else if(ek_isalpha(c)) return token_ident();
            else {
                EK_ERROR(*lex.line_no, "Unknown token: %.*s", (int)(lex.current - lex.start)+1, lex.start);
                exit(1);
            }
    }
}


void print_type(int type){
    switch(type){
        case NEWLINE:
            printf("NEWLINE");
            break;
        case NOOMBA:
            printf("NOOMBA");
            break;
        case IDENT:
            printf("IDENT");
            break;
        case TI:
            printf("TI");
            break;
        case PARI:
            printf("PARI");
            break;
        case FI:
            printf("FI");
            break;
        case SE:
            printf("SE");
            break;
        case DOGBA:
            printf("DOGBA");
            break;
        case NIGBATI:
            printf("NIGBATI");
            break;
        case PADA:
            printf("PADA");
            break;
        case ISE:
            printf("ISE");
            break;
        case SI:
            printf("SI");
            break;
        case ATI:
            printf("ATI");
            break;
        case TABI:
            printf("TABI");
            break;
        case BIBEEKO:
            printf("BIBEEKO");
            break;
        case EQ:
            printf("EQ");
            break;
        case LPAR:
            printf("LPAR");
            break;
        case ASTERISK:
            printf("ASTERISK");
            break;
        case RPAR:
            printf("RPAR");
            break;
        case PLUS:
            printf("PLUS");
            break;
        case MINUS:
            printf("MINUS");
            break;
        case EQEQ:
            printf("EQEQ");
            break;
        case SLASH:
            printf("SLASH");
            break;
        case LT:
            printf("LT");
            break;
        case LTEQ:
            printf("LTEQ");
            break;
        case GT:
            printf("GT");
            break;
        case GTEQ:
            printf("GTEQ");
            break;
        case NEQ:
            printf("NEQ");
            break;
        case EKEOF:
            printf("EKEOF");
            break;
        case ORO:
            printf("ORO");
            break;
        case OOTO:
            printf("OOTO");
            break;
        case IRO:
            printf("IRO");
            break;
    }
}


int yylex(void){
    Token tok = get_token();
    yylval.tok = tok;
    return tok.token_type;
}
