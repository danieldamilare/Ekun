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
# define YYDEBUG 0
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
    SI = 272,                      /* SI  */
    BIBEEKO = 273,                 /* BIBEEKO  */
    LPAR = 274,                    /* LPAR  */
    RPAR = 275,                    /* RPAR  */
    SEMI = 276,                    /* SEMI  */
    EQ = 277,                      /* EQ  */
    TABI = 278,                    /* TABI  */
    ATI = 279,                     /* ATI  */
    GT = 280,                      /* GT  */
    GTEQ = 281,                    /* GTEQ  */
    LT = 282,                      /* LT  */
    LTEQ = 283,                    /* LTEQ  */
    EQEQ = 284,                    /* EQEQ  */
    NEQ = 285,                     /* NEQ  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    ASTERISK = 288,                /* ASTERISK  */
    SLASH = 289,                   /* SLASH  */
    MODULUS = 290,                 /* MODULUS  */
    UNARYMINUS = 291,              /* UNARYMINUS  */
    NOT = 292,                     /* NOT  */
    CARET = 293                    /* CARET  */
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
#define SI 272
#define BIBEEKO 273
#define LPAR 274
#define RPAR 275
#define SEMI 276
#define EQ 277
#define TABI 278
#define ATI 279
#define GT 280
#define GTEQ 281
#define LT 282
#define LTEQ 283
#define EQEQ 284
#define NEQ 285
#define PLUS 286
#define MINUS 287
#define ASTERISK 288
#define SLASH 289
#define MODULUS 290
#define UNARYMINUS 291
#define NOT 292
#define CARET 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "ekparser.y"

    Token tok;
    void  ** ptr;

#line 148 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
