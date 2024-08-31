/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEWLINE = 258,                 /* NEWLINE  */
    NOOMBA = 259,                  /* NOOMBA  */
    IDENT = 260,                   /* IDENT  */
    ORO = 261,                     /* ORO  */
    OOTO = 262,                    /* OOTO  */
    IRO = 263,                     /* IRO  */
    TI = 264,                      /* TI  */
    PARI = 265,                    /* PARI  */
    SE = 266,                      /* SE  */
    FI = 267,                      /* FI  */
    DOGBA = 268,                   /* DOGBA  */
    NIGBATI = 269,                 /* NIGBATI  */
    PADA = 270,                    /* PADA  */
    ISE = 271,                     /* ISE  */
    SOPE = 272,                    /* SOPE  */
    SI = 273,                      /* SI  */
    BIBEEKO = 274,                 /* BIBEEKO  */
    LATI = 275,                    /* LATI  */
    FUN = 276,                     /* FUN  */
    IFIKUN = 277,                  /* IFIKUN  */
    PE = 278,                      /* PE  */
    COLON = 279,                   /* COLON  */
    LPAR = 280,                    /* LPAR  */
    RPAR = 281,                    /* RPAR  */
    SEMI = 282,                    /* SEMI  */
    COMMA = 283,                   /* COMMA  */
    EQ = 284,                      /* EQ  */
    TABI = 285,                    /* TABI  */
    ATI = 286,                     /* ATI  */
    GT = 287,                      /* GT  */
    GTEQ = 288,                    /* GTEQ  */
    LT = 289,                      /* LT  */
    LTEQ = 290,                    /* LTEQ  */
    EQEQ = 291,                    /* EQEQ  */
    NEQ = 292,                     /* NEQ  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    ASTERISK = 295,                /* ASTERISK  */
    SLASH = 296,                   /* SLASH  */
    MODULUS = 297,                 /* MODULUS  */
    UNARYMINUS = 298,              /* UNARYMINUS  */
    NOT = 299,                     /* NOT  */
    CARET = 300                    /* CARET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NEWLINE 258
#define NOOMBA 259
#define IDENT 260
#define ORO 261
#define OOTO 262
#define IRO 263
#define TI 264
#define PARI 265
#define SE 266
#define FI 267
#define DOGBA 268
#define NIGBATI 269
#define PADA 270
#define ISE 271
#define SOPE 272
#define SI 273
#define BIBEEKO 274
#define LATI 275
#define FUN 276
#define IFIKUN 277
#define PE 278
#define COLON 279
#define LPAR 280
#define RPAR 281
#define SEMI 282
#define COMMA 283
#define EQ 284
#define TABI 285
#define ATI 286
#define GT 287
#define GTEQ 288
#define LT 289
#define LTEQ 290
#define EQEQ 291
#define NEQ 292
#define PLUS 293
#define MINUS 294
#define ASTERISK 295
#define SLASH 296
#define MODULUS 297
#define UNARYMINUS 298
#define NOT 299
#define CARET 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "ekparser.y"

    Token tok;
    int args;
    long int ptr;

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
