/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "ekparser.y"

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


#line 121 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    SI = 272,                      /* SI  */
    BIBEEKO = 273,                 /* BIBEEKO  */
    LATI = 274,                    /* LATI  */
    FUN = 275,                     /* FUN  */
    IFIKUN = 276,                  /* IFIKUN  */
    PE = 277,                      /* PE  */
    COLON = 278,                   /* COLON  */
    DE = 279,                      /* DE  */
    LPAR = 280,                    /* LPAR  */
    RPAR = 281,                    /* RPAR  */
    SEMI = 282,                    /* SEMI  */
    COMMA = 283,                   /* COMMA  */
    LBRACKET = 284,                /* LBRACKET  */
    RBRACKET = 285,                /* RBRACKET  */
    LBRACES = 286,                 /* LBRACES  */
    RBRACES = 287,                 /* RBRACES  */
    EQ = 288,                      /* EQ  */
    TABI = 289,                    /* TABI  */
    ATI = 290,                     /* ATI  */
    GT = 291,                      /* GT  */
    GTEQ = 292,                    /* GTEQ  */
    LT = 293,                      /* LT  */
    LTEQ = 294,                    /* LTEQ  */
    EQEQ = 295,                    /* EQEQ  */
    NEQ = 296,                     /* NEQ  */
    PLUS = 297,                    /* PLUS  */
    MINUS = 298,                   /* MINUS  */
    ASTERISK = 299,                /* ASTERISK  */
    SLASH = 300,                   /* SLASH  */
    MODULUS = 301,                 /* MODULUS  */
    UNARYMINUS = 302,              /* UNARYMINUS  */
    NOT = 303,                     /* NOT  */
    CARET = 304                    /* CARET  */
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
#define LATI 274
#define FUN 275
#define IFIKUN 276
#define PE 277
#define COLON 278
#define DE 279
#define LPAR 280
#define RPAR 281
#define SEMI 282
#define COMMA 283
#define LBRACKET 284
#define RBRACKET 285
#define LBRACES 286
#define RBRACES 287
#define EQ 288
#define TABI 289
#define ATI 290
#define GT 291
#define GTEQ 292
#define LT 293
#define LTEQ 294
#define EQEQ 295
#define NEQ 296
#define PLUS 297
#define MINUS 298
#define ASTERISK 299
#define SLASH 300
#define MODULUS 301
#define UNARYMINUS 302
#define NOT 303
#define CARET 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "ekparser.y"

    Token tok;
    int args;
    long int ptr;

#line 278 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_NOOMBA = 4,                     /* NOOMBA  */
  YYSYMBOL_IDENT = 5,                      /* IDENT  */
  YYSYMBOL_ORO = 6,                        /* ORO  */
  YYSYMBOL_OOTO = 7,                       /* OOTO  */
  YYSYMBOL_IRO = 8,                        /* IRO  */
  YYSYMBOL_TI = 9,                         /* TI  */
  YYSYMBOL_PARI = 10,                      /* PARI  */
  YYSYMBOL_SE = 11,                        /* SE  */
  YYSYMBOL_FI = 12,                        /* FI  */
  YYSYMBOL_DOGBA = 13,                     /* DOGBA  */
  YYSYMBOL_NIGBATI = 14,                   /* NIGBATI  */
  YYSYMBOL_PADA = 15,                      /* PADA  */
  YYSYMBOL_ISE = 16,                       /* ISE  */
  YYSYMBOL_SI = 17,                        /* SI  */
  YYSYMBOL_BIBEEKO = 18,                   /* BIBEEKO  */
  YYSYMBOL_LATI = 19,                      /* LATI  */
  YYSYMBOL_FUN = 20,                       /* FUN  */
  YYSYMBOL_IFIKUN = 21,                    /* IFIKUN  */
  YYSYMBOL_PE = 22,                        /* PE  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_DE = 24,                        /* DE  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_RPAR = 26,                      /* RPAR  */
  YYSYMBOL_SEMI = 27,                      /* SEMI  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_LBRACKET = 29,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 30,                  /* RBRACKET  */
  YYSYMBOL_LBRACES = 31,                   /* LBRACES  */
  YYSYMBOL_RBRACES = 32,                   /* RBRACES  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_TABI = 34,                      /* TABI  */
  YYSYMBOL_ATI = 35,                       /* ATI  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_GTEQ = 37,                      /* GTEQ  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_LTEQ = 39,                      /* LTEQ  */
  YYSYMBOL_EQEQ = 40,                      /* EQEQ  */
  YYSYMBOL_NEQ = 41,                       /* NEQ  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 44,                  /* ASTERISK  */
  YYSYMBOL_SLASH = 45,                     /* SLASH  */
  YYSYMBOL_MODULUS = 46,                   /* MODULUS  */
  YYSYMBOL_UNARYMINUS = 47,                /* UNARYMINUS  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_CARET = 49,                     /* CARET  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_stmtlist = 53,                  /* stmtlist  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_funccall = 55,                  /* funccall  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_arglist = 57,                   /* arglist  */
  YYSYMBOL_assignstmt = 58,                /* assignstmt  */
  YYSYMBOL_ifstmt = 59,                    /* ifstmt  */
  YYSYMBOL_ifblk = 60,                     /* ifblk  */
  YYSYMBOL_elsestmt = 61,                  /* elsestmt  */
  YYSYMBOL_whilestmt = 62,                 /* whilestmt  */
  YYSYMBOL_forstmt = 63,                   /* forstmt  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_ifikun = 65,                    /* ifikun  */
  YYSYMBOL_returnstmt = 66,                /* returnstmt  */
  YYSYMBOL_funcstmt = 67,                  /* funcstmt  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_69_4 = 69,                      /* $@4  */
  YYSYMBOL_paramlist = 70,                 /* paramlist  */
  YYSYMBOL_loopatch = 71,                  /* loopatch  */
  YYSYMBOL_funcpatch = 72,                 /* funcpatch  */
  YYSYMBOL_loopatch2 = 73,                 /* loopatch2  */
  YYSYMBOL_ifpatch = 74,                   /* ifpatch  */
  YYSYMBOL_orpatch = 75,                   /* orpatch  */
  YYSYMBOL_andpatch = 76,                  /* andpatch  */
  YYSYMBOL_forpatch = 77,                  /* forpatch  */
  YYSYMBOL_elsepatch = 78,                 /* elsepatch  */
  YYSYMBOL_stat_end = 79                   /* stat_end  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    85,    88,    92,    94,    96,    98,   100,
     103,   109,   110,   111,   114,   120,   124,   128,   134,   142,
     148,   150,   156,   161,   165,   169,   173,   177,   181,   185,
     189,   193,   197,   201,   208,   214,   218,   222,   229,   229,
     234,   240,   241,   242,   245,   252,   257,   261,   267,   271,
     287,   292,   297,   304,   310,   310,   318,   322,   325,   335,
     344,   345,   344,   364,   365,   369,   377,   380,   383,   389,
     395,   400,   405,   410,   416,   417
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "NOOMBA",
  "IDENT", "ORO", "OOTO", "IRO", "TI", "PARI", "SE", "FI", "DOGBA",
  "NIGBATI", "PADA", "ISE", "SI", "BIBEEKO", "LATI", "FUN", "IFIKUN", "PE",
  "COLON", "DE", "LPAR", "RPAR", "SEMI", "COMMA", "LBRACKET", "RBRACKET",
  "LBRACES", "RBRACES", "EQ", "TABI", "ATI", "GT", "GTEQ", "LT", "LTEQ",
  "EQEQ", "NEQ", "PLUS", "MINUS", "ASTERISK", "SLASH", "MODULUS",
  "UNARYMINUS", "NOT", "CARET", "$accept", "program", "stmt", "stmtlist",
  "expr", "funccall", "$@1", "arglist", "assignstmt", "ifstmt", "ifblk",
  "elsestmt", "whilestmt", "forstmt", "$@2", "ifikun", "returnstmt",
  "funcstmt", "$@3", "$@4", "paramlist", "loopatch", "funcpatch",
  "loopatch2", "ifpatch", "orpatch", "andpatch", "forpatch", "elsepatch",
  "stat_end", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -91,    13,   177,   -91,     2,   -91,   -91,   -27,   -91,   -91,
     -91,   203,   203,   -91,   -14,   -91,     6,   -10,   203,   -91,
     -91,   203,   -91,   443,   -91,   -91,   -91,     8,   -91,   -91,
     -91,   -91,   -91,   -91,   203,   -91,   218,   252,   203,   203,
      -9,     3,    20,   280,   203,   -17,   203,   203,   -91,   -91,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   -91,   462,   -91,   203,   208,   462,   462,    25,   203,
      11,   -91,   299,    26,    28,   317,   203,   203,    28,    28,
      28,    28,    28,   -25,   -25,   -17,   -17,   -17,   -17,   -91,
     345,   480,   499,    27,    -2,   373,   -91,   -91,   203,   -91,
      17,   536,   554,   177,   -91,   203,   -91,    -2,    50,    33,
     203,    32,   -91,   203,    44,   391,    76,   -91,   -91,   -91,
     425,   203,   462,    54,   -91,   517,   -91,   -91,   203,   -91,
      38,   177,   -91,   -91,   462,   -91,   -91,   117,   -91,   -91,
      56,   -91,   147,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,     2,     1,     0,    74,    14,    17,    18,    15,
      16,     0,     0,    66,    58,    60,     0,     0,     0,    75,
      66,     0,    13,     4,    20,     5,     6,     0,     7,     8,
      10,     9,    12,     3,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    22,     0,     0,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    44,    69,     0,     0,    68,    59,     0,     0,
      66,    37,    42,     0,    28,     0,     0,     0,    25,    24,
      26,    29,    27,    23,    30,    31,    32,    36,    35,    11,
       0,    45,     0,     0,    63,     0,    40,    38,    41,    19,
      21,    34,    33,    73,    21,     0,    11,    63,     0,     0,
       0,     0,    43,     0,    50,     0,     0,    65,    64,    61,
      56,    41,    46,    11,    49,    47,    53,    67,     0,    66,
       0,    52,    51,    11,    57,    72,    39,     0,    54,    62,
       0,    11,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -72,   -11,   -91,   -91,   -90,   -91,   -91,
     -55,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -32,   -18,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    22,     2,    23,    24,   111,    73,    25,    26,
      27,   124,    28,    29,   140,   129,    30,    31,    40,   127,
     109,    38,   133,    93,    89,    76,    77,   138,   114,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    37,    44,   107,    64,     5,    34,    43,   112,    39,
      45,    41,    64,     3,     4,    42,    68,   103,    61,    57,
      58,    59,    69,    62,    60,    70,   108,    66,    67,    19,
      94,   130,    60,    72,   116,    74,    75,    96,   106,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     113,   131,    97,    90,    92,   118,    99,    64,    95,   119,
     121,   137,   123,    11,   136,   101,   102,   141,   132,   142,
      55,    56,    57,    58,    59,   117,    33,    60,     0,     5,
       6,     7,     8,     9,    10,    11,   126,    72,    12,     0,
      13,    14,    15,     0,   115,     0,    16,     0,    17,   120,
       0,    18,   122,    19,     0,    20,     0,     0,     0,     0,
      72,   135,     0,     0,     0,     0,     0,   134,     0,    21,
       5,     6,     7,     8,     9,    10,    11,   139,     0,    12,
       0,    13,    14,    15,     0,     0,     0,    16,     0,    17,
       0,     0,    18,     0,    19,     0,    20,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,   143,     0,    12,
      21,    13,    14,    15,     0,     0,     0,    16,     0,    17,
       0,     0,    18,     0,    19,     0,    20,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,     0,     0,    12,
      21,    13,    14,    15,     0,     0,     0,    16,     0,    17,
       0,     0,    18,     0,    19,     0,    20,     6,    35,     8,
       9,    10,     6,    91,     8,     9,    10,     0,     0,     0,
      21,     0,     0,     0,     0,    17,     0,     0,    18,    63,
      17,    46,    20,    18,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    64,     0,     0,
       0,    21,    48,    49,    50,    51,    52,    53,    54,     0,
      55,    56,    57,    58,    59,    46,     0,    60,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    46,    55,    56,    57,    58,    59,     0,
       0,    60,     0,     0,     0,     0,    71,     0,     0,    64,
       0,     0,    46,     0,    48,    49,    50,    51,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    98,    64,    60,
      46,     0,     0,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    58,    59,    64,   100,    60,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    46,    55,
      56,    57,    58,    59,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,    64,   104,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    46,    55,    56,    57,
      58,    59,     0,     0,    60,     0,     0,   110,     0,     0,
       0,     0,    64,     0,    46,     0,     0,    48,    49,    50,
      51,    52,    53,    54,     0,    55,    56,    57,    58,    59,
      64,   125,    60,     0,     0,    48,    49,    50,    51,    52,
      53,    54,     0,    55,    56,    57,    58,    59,    46,     0,
      60,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    46,     0,     0,    48,
      49,    50,    51,    52,    53,    54,     0,    55,    56,    57,
      58,    59,    47,     0,    60,    46,     0,    48,    49,    50,
      51,    52,    53,    54,     0,    55,    56,    57,    58,    59,
       0,    64,    60,   -17,     0,     0,    48,    49,    50,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,   -17,
       0,    60,    46,     0,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,     0,   -17,   -17,   -17,   -17,   -17,     0,   105,   -17,
     -21,     0,     0,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    58,    59,   -21,     0,    60,    46,
       0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
     -21,   -21,   -21,   -21,     0,    64,   -21,    46,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    64,     0,    60,     0,     0,     0,     0,
      50,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      11,    12,    20,     5,    29,     3,    33,    18,    98,    23,
      21,     5,    29,     0,     1,    25,    25,    89,    10,    44,
      45,    46,    19,    34,    49,     5,    28,    38,    39,    27,
       5,   121,    49,    44,   106,    46,    47,    26,    11,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      33,   123,    70,    64,    65,     5,    30,    29,    69,    26,
      28,   133,    18,     9,    26,    76,    77,    11,   123,   141,
      42,    43,    44,    45,    46,   107,     4,    49,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    98,    12,    -1,
      14,    15,    16,    -1,   105,    -1,    20,    -1,    22,   110,
      -1,    25,   113,    27,    -1,    29,    -1,    -1,    -1,    -1,
     121,   129,    -1,    -1,    -1,    -1,    -1,   128,    -1,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      43,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      43,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    29,     4,     5,     6,
       7,     8,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,    11,
      22,    13,    29,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    29,    -1,    -1,
      -1,    43,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    45,    46,    13,    -1,    49,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    13,    42,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    13,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    28,    29,    49,
      13,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    29,    30,    49,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    13,    42,
      43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    13,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    13,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      29,    30,    49,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    13,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    13,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    29,    -1,    49,    13,    -1,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      -1,    29,    49,    13,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    29,
      -1,    49,    13,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    -1,    29,    49,
      13,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    29,    -1,    49,    13,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    -1,    29,    49,    13,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    29,    -1,    49,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      46,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    53,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    12,    14,    15,    16,    20,    22,    25,    27,
      29,    43,    52,    54,    55,    58,    59,    60,    62,    63,
      66,    67,    79,    79,    33,     5,    54,    54,    71,    23,
      68,     5,    25,    54,    71,    54,    13,    29,    34,    35,
      36,    37,    38,    39,    40,    42,    43,    44,    45,    46,
      49,    10,    54,    11,    29,    17,    54,    54,    25,    19,
       5,    26,    54,    57,    54,    54,    75,    76,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    74,
      54,     5,    54,    73,     5,    54,    26,    71,    28,    30,
      30,    54,    54,    53,    30,    29,    11,     5,    28,    70,
      24,    56,    57,    33,    78,    54,    53,    70,     5,    26,
      54,    28,    54,    18,    61,    30,    10,    69,    21,    65,
      57,    53,    60,    72,    54,    71,    26,    53,    77,    10,
      64,    11,    53,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    56,    55,
      55,    57,    57,    57,    58,    58,    58,    58,    59,    60,
      61,    61,    61,    62,    64,    63,    65,    65,    66,    66,
      68,    69,    67,    70,    70,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     2,     1,     1,     1,     1,     1,     4,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     3,     3,     3,     0,     8,
       4,     0,     1,     3,     3,     4,     6,     7,     2,     7,
       0,     2,     2,     7,     0,    13,     0,     2,     1,     3,
       0,     0,    10,     0,     2,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmtlist  */
#line 81 "ekparser.y"
                  { 
       DEBUG_PRINT("program stmt stat_end"); 
       CODEGEN(STOP);
       }
#line 1527 "y.tab.c"
    break;

  case 3: /* program: program error stat_end  */
#line 85 "ekparser.y"
                               { DEBUG_PRINT("program error stat_end"); yyerrok; }
#line 1533 "y.tab.c"
    break;

  case 4: /* stmt: expr  */
#line 89 "ekparser.y"
       { DEBUG_PRINT("stmt: expr"); 
         CODEGEN(ppop);
       }
#line 1541 "y.tab.c"
    break;

  case 5: /* stmt: assignstmt  */
#line 93 "ekparser.y"
       { DEBUG_PRINT("stmt: assignstmt"); }
#line 1547 "y.tab.c"
    break;

  case 6: /* stmt: ifstmt  */
#line 95 "ekparser.y"
       { DEBUG_PRINT("stmt: ifstmt"); }
#line 1553 "y.tab.c"
    break;

  case 7: /* stmt: whilestmt  */
#line 97 "ekparser.y"
       { DEBUG_PRINT("stmt: whilestmt"); }
#line 1559 "y.tab.c"
    break;

  case 8: /* stmt: forstmt  */
#line 98 "ekparser.y"
                 {
        DEBUG_PRINT("stmt: forstmt");}
#line 1566 "y.tab.c"
    break;

  case 9: /* stmt: funcstmt  */
#line 100 "ekparser.y"
                  {
         DEBUG_PRINT("stmt: funcstmt");
       }
#line 1574 "y.tab.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 103 "ekparser.y"
                    {
         DEBUG_PRINT("stmt: returnstmt");
       }
#line 1582 "y.tab.c"
    break;

  case 11: /* stmtlist: %empty  */
#line 109 "ekparser.y"
                      { (yyval.ptr) =  code_get_count(&vm.instructions);}
#line 1588 "y.tab.c"
    break;

  case 13: /* stmtlist: stmtlist stmt  */
#line 111 "ekparser.y"
                        { DEBUG_PRINT("stmtlist: stmlist stmt"); }
#line 1594 "y.tab.c"
    break;

  case 14: /* expr: NOOMBA  */
#line 115 "ekparser.y"
        { DEBUG_PRINT("expr: NUMBER"); 
          double num = check_err(strtod((yyvsp[0].tok).start, NULL));
          void * data = write_constant(CREATE_NUM(num));
          (yyval.ptr) = CODEGEN2(constpush, data);
        }
#line 1604 "y.tab.c"
    break;

  case 15: /* expr: OOTO  */
#line 121 "ekparser.y"
          { DEBUG_PRINT("expr: OOTO");
            (yyval.ptr) = CODEGEN(ooto);
          }
#line 1612 "y.tab.c"
    break;

  case 16: /* expr: IRO  */
#line 125 "ekparser.y"
          { DEBUG_PRINT("expr: IRO");
            (yyval.ptr) = CODEGEN(iro);
          }
#line 1620 "y.tab.c"
    break;

  case 17: /* expr: IDENT  */
#line 128 "ekparser.y"
                {
            
            DEBUG_PRINT("expr: IDENT");
            (yyval.ptr) = gen_var((yyvsp[0].tok).start, (yyvsp[0].tok).length, PUSH);
          }
#line 1630 "y.tab.c"
    break;

  case 18: /* expr: ORO  */
#line 135 "ekparser.y"
         {
            DEBUG_PRINT("expr: ORO");
            Objstring * string = make_string((yyvsp[0].tok).start+1, (yyvsp[0].tok).length - 2);
            void * data = write_constant(CREATE_STR(string));
            (yyval.ptr) = CODEGEN2(constpush, data);
          }
#line 1641 "y.tab.c"
    break;

  case 19: /* expr: LBRACKET loopatch arglist RBRACKET  */
#line 143 "ekparser.y"
        {
            (yyval.ptr) = (yyvsp[-2].ptr);
            CODEGEN2(build_array, (yyvsp[-1].args));
        }
#line 1650 "y.tab.c"
    break;

  case 21: /* expr: expr LBRACKET expr RBRACKET  */
#line 151 "ekparser.y"
        {
           
           CODEGEN(index_push);
        }
#line 1659 "y.tab.c"
    break;

  case 22: /* expr: MINUS expr  */
#line 157 "ekparser.y"
        { DEBUG_PRINT("expr: MINUS expr");
          CODEGEN(neg);
          (yyval.ptr) = (yyvsp[0].ptr);
        }
#line 1668 "y.tab.c"
    break;

  case 23: /* expr: expr PLUS expr  */
#line 162 "ekparser.y"
        { DEBUG_PRINT("expr: expr + expr");
          CODEGEN(add);
        }
#line 1676 "y.tab.c"
    break;

  case 24: /* expr: expr GTEQ expr  */
#line 166 "ekparser.y"
        { DEBUG_PRINT("expr: expr >= expr");
          CODEGEN(ge);
        }
#line 1684 "y.tab.c"
    break;

  case 25: /* expr: expr GT expr  */
#line 170 "ekparser.y"
        { DEBUG_PRINT("expr: expr > expr");
          CODEGEN(gt);
        }
#line 1692 "y.tab.c"
    break;

  case 26: /* expr: expr LT expr  */
#line 174 "ekparser.y"
        { DEBUG_PRINT("expr: expr < expr");
          CODEGEN(lt);
        }
#line 1700 "y.tab.c"
    break;

  case 27: /* expr: expr EQEQ expr  */
#line 178 "ekparser.y"
        { DEBUG_PRINT("expr: expr == expr");
          CODEGEN(eq);
        }
#line 1708 "y.tab.c"
    break;

  case 28: /* expr: expr DOGBA expr  */
#line 182 "ekparser.y"
          { DEBUG_PRINT("expr: expr DOGBA expr ");
            CODEGEN(eq);
          }
#line 1716 "y.tab.c"
    break;

  case 29: /* expr: expr LTEQ expr  */
#line 186 "ekparser.y"
        { DEBUG_PRINT("expr: expr <= expr");
          CODEGEN(le);
        }
#line 1724 "y.tab.c"
    break;

  case 30: /* expr: expr MINUS expr  */
#line 190 "ekparser.y"
        { DEBUG_PRINT("expr: expr - expr"); 
          CODEGEN(sub);
        }
#line 1732 "y.tab.c"
    break;

  case 31: /* expr: expr ASTERISK expr  */
#line 194 "ekparser.y"
        { DEBUG_PRINT("expr: expr * expr"); 
          CODEGEN(mul);
        }
#line 1740 "y.tab.c"
    break;

  case 32: /* expr: expr SLASH expr  */
#line 198 "ekparser.y"
        { DEBUG_PRINT("expr: expr / expr"); 
          CODEGEN(divide);
        }
#line 1748 "y.tab.c"
    break;

  case 33: /* expr: expr ATI andpatch expr  */
#line 201 "ekparser.y"
                                 {
            /* if expr is true jump to evaluate next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) (yyvsp[0].ptr);
            /* if expr is false jmp to the end of the production */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) code_get_count(
                &vm.instructions);
        }
#line 1760 "y.tab.c"
    break;

  case 34: /* expr: expr TABI orpatch expr  */
#line 208 "ekparser.y"
                                 {
            /* patch if expr is true jump to the end of the rule */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) code_get_count(&vm.instructions);
            /* if expr is false jump to the next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) (yyvsp[0].ptr);
        }
#line 1771 "y.tab.c"
    break;

  case 35: /* expr: expr CARET expr  */
#line 215 "ekparser.y"
        { DEBUG_PRINT("expr: expr ^ expr"); 
          CODEGEN(power);
        }
#line 1779 "y.tab.c"
    break;

  case 36: /* expr: expr MODULUS expr  */
#line 218 "ekparser.y"
                            { 
        DEBUG_PRINT("expr: expr %% expr"); 
        CODEGEN(mod);
        }
#line 1788 "y.tab.c"
    break;

  case 37: /* expr: LPAR expr RPAR  */
#line 223 "ekparser.y"
        { DEBUG_PRINT("expr: (expr)"); 
          (yyval.ptr) = (yyvsp[-1].ptr);
         }
#line 1796 "y.tab.c"
    break;

  case 38: /* $@1: %empty  */
#line 229 "ekparser.y"
                                  {gen_var((yyvsp[-1].tok).start, (yyvsp[-1].tok).length, PUSH); }
#line 1802 "y.tab.c"
    break;

  case 39: /* funccall: PE LPAR IDENT loopatch $@1 COMMA arglist RPAR  */
#line 230 "ekparser.y"
         {
             CODEGEN2(call, (void *) ((intptr_t) (yyvsp[-1].args))); 
             (yyval.ptr) = (yyvsp[-4].ptr);
          }
#line 1811 "y.tab.c"
    break;

  case 40: /* funccall: PE LPAR IDENT RPAR  */
#line 234 "ekparser.y"
                              {
            (yyval.ptr) = gen_var((yyvsp[-1].tok).start, (yyvsp[-1].tok).length, PUSH); 
            CODEGEN2(call, (void *) ((intptr_t) 0));
         }
#line 1820 "y.tab.c"
    break;

  case 41: /* arglist: %empty  */
#line 240 "ekparser.y"
                       { (yyval.args) = 0; }
#line 1826 "y.tab.c"
    break;

  case 42: /* arglist: expr  */
#line 241 "ekparser.y"
                {(yyval.args) = 1; }
#line 1832 "y.tab.c"
    break;

  case 43: /* arglist: expr COMMA arglist  */
#line 242 "ekparser.y"
                              {(yyval.args) = (yyvsp[0].args) + 1; }
#line 1838 "y.tab.c"
    break;

  case 44: /* assignstmt: IDENT EQ expr  */
#line 246 "ekparser.y"
          {
             DEBUG_PRINT("assignstmt:\
             IDENT EQ expr");
             (yyval.ptr) = (yyvsp[0].ptr);
             gen_var((yyvsp[-2].tok).start, (yyvsp[-2].tok).length, STORE);
           }
#line 1849 "y.tab.c"
    break;

  case 45: /* assignstmt: FI expr SI IDENT  */
#line 253 "ekparser.y"
           {
             (yyval.ptr) = (yyvsp[-2].ptr);
             gen_var((yyvsp[0].tok).start, (yyvsp[0].tok).length, STORE);
           }
#line 1858 "y.tab.c"
    break;

  case 46: /* assignstmt: expr LBRACKET expr RBRACKET EQ expr  */
#line 258 "ekparser.y"
           {
               CODEGEN(index_store_1);
           }
#line 1866 "y.tab.c"
    break;

  case 47: /* assignstmt: FI expr SI expr LBRACKET expr RBRACKET  */
#line 261 "ekparser.y"
                                                   {
                CODEGEN(index_store_2);
                (yyval.ptr) = (yyvsp[-5].ptr);
           }
#line 1875 "y.tab.c"
    break;

  case 48: /* ifstmt: ifblk PARI  */
#line 267 "ekparser.y"
                    {DEBUG_PRINT("ifstmt: ifblk PARI");}
#line 1881 "y.tab.c"
    break;

  case 49: /* ifblk: TI expr SE ifpatch stmtlist elsepatch elsestmt  */
#line 271 "ekparser.y"
                                                      {

      DEBUG_PRINT("ifblk: TI expr \
        SE ifpatch stmtlist elsepatch elsestmt ");
      //fix backpatch

      vm.instructions.data[(yyvsp[-3].ptr) + 1] = (void *) (yyvsp[0].ptr);
      DEBUG_PRINT("if patch: %ld %ld\n", (yyvsp[-3].ptr), (yyvsp[0].ptr));
      vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) code_get_count(&vm.instructions);

      DEBUG_PRINT("elsepatch: %ld %ld\n", (yyvsp[-1].ptr), code_get_count(&vm.instructions));
      (yyval.ptr) = (yyvsp[-5].ptr);
     DEBUG_PRINT("ifblk return count: %ld\n", (yyval.ptr));
      }
#line 1900 "y.tab.c"
    break;

  case 50: /* elsestmt: %empty  */
#line 287 "ekparser.y"
                       {
         DEBUG_PRINT("elsestmt: /*nothing*/");
         (yyval.ptr) =  code_get_count(&vm.instructions); 
         DEBUG_PRINT(" elsestmt return count: %ld\n", (yyval.ptr));
        }
#line 1910 "y.tab.c"
    break;

  case 51: /* elsestmt: BIBEEKO ifblk  */
#line 292 "ekparser.y"
                         { /* else if */
         DEBUG_PRINT("elsestmt: BIBEEKO ifblk");
         (yyval.ptr) = (yyvsp[0].ptr);
         DEBUG_PRINT(" bibeeko ifblk return count: %ld\n", (yyval.ptr));
         }
#line 1920 "y.tab.c"
    break;

  case 52: /* elsestmt: BIBEEKO stmtlist  */
#line 297 "ekparser.y"
                            {
         DEBUG_PRINT("elsestmt: BIBEEKO SE stmtlist");
         (yyval.ptr) = (yyvsp[0].ptr);
         DEBUG_PRINT(" bibeeko stmtlist return count: %ld\n", (yyval.ptr));
         }
#line 1930 "y.tab.c"
    break;

  case 53: /* whilestmt: NIGBATI loopatch expr loopatch2 SE stmtlist PARI  */
#line 304 "ekparser.y"
                                                            {
         CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
         vm.instructions.data[(yyvsp[-3].ptr)+1] = (void *) code_get_count(&vm.instructions);
         (yyval.ptr) = (yyvsp[-5].ptr);
}
#line 1940 "y.tab.c"
    break;

  case 54: /* $@2: %empty  */
#line 310 "ekparser.y"
                                                              {
        gen_var((yyvsp[-7].tok).start, (yyvsp[-7].tok).length, STORE); }
#line 1947 "y.tab.c"
    break;

  case 55: /* forstmt: FUN IDENT LATI expr DE expr ifikun loopatch forpatch $@2 SE stmtlist PARI  */
#line 311 "ekparser.y"
                                                                {
        CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
        vm.instructions.data[(yyvsp[-5].ptr)+1] = 
           (void *) code_get_count(&vm.instructions);
        (yyval.ptr) = (yyvsp[-9].ptr);}
#line 1957 "y.tab.c"
    break;

  case 56: /* ifikun: %empty  */
#line 318 "ekparser.y"
                    { 
      void * data = write_constant(CREATE_NUM(1));
      (yyval.ptr) = CODEGEN2(constpush, data);
      }
#line 1966 "y.tab.c"
    break;

  case 57: /* ifikun: IFIKUN expr  */
#line 322 "ekparser.y"
                     {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1972 "y.tab.c"
    break;

  case 58: /* returnstmt: PADA  */
#line 325 "ekparser.y"
                 {
            if(!IN_SCOPE()){
                EK_ERROR(ek_state.line_no, 
                "Return statement is not allowed outside a function");
                exit(1);
            }
            void * data = write_constant(KOROFO);
            (yyval.ptr) = CODEGEN2(constpush, data);
            CODEGEN(ret);
          }
#line 1987 "y.tab.c"
    break;

  case 59: /* returnstmt: PADA COLON expr  */
#line 335 "ekparser.y"
                            { 
                if(!IN_SCOPE()){
                 EK_ERROR(ek_state.line_no, 
                 "Return statement is not allowed outside a function");
                }
                (yyval.ptr) = (yyvsp[0].ptr);  CODEGEN(ret); 
           }
#line 1999 "y.tab.c"
    break;

  case 60: /* $@3: %empty  */
#line 344 "ekparser.y"
              { begin_scope(); DEBUG_PRINT("matching ise"); }
#line 2005 "y.tab.c"
    break;

  case 61: /* $@4: %empty  */
#line 345 "ekparser.y"
                                    { 
          /* this hack allows function to be define in its real scope 
           * since function is bound to an outer scoe */
          current.scope_depth--; def_func((yyvsp[-2].tok), (yyvsp[-1].args)); current.scope_depth++;
          }
#line 2015 "y.tab.c"
    break;

  case 62: /* funcstmt: ISE $@3 LPAR IDENT paramlist RPAR $@4 funcpatch stmtlist PARI  */
#line 350 "ekparser.y"
                       {
            DEBUG_PRINT("funcstmt: ISE IDENT \
            LPAR paramlist RPAR stmt PARI");
            /* function call are expression and therefore must return a value.
            * Every function call return a value. if the user does not return from the
            * function. An implicit return statement is declared with a nil value
            * This won't be called if the user return from the function */
           void * data = write_constant(KOROFO);
           CODEGEN3(constpush, data, ret);
           end_scope();
          vm.instructions.data[(yyvsp[-2].ptr) + 1] = (void *) code_get_count(&vm.instructions);
        }
#line 2032 "y.tab.c"
    break;

  case 63: /* paramlist: %empty  */
#line 364 "ekparser.y"
                        {(yyval.args) = 0;}
#line 2038 "y.tab.c"
    break;

  case 64: /* paramlist: COMMA IDENT  */
#line 365 "ekparser.y"
                       {
            Objstring * name = make_string((yyvsp[0].tok).start, (yyvsp[0].tok).length);
            add_local(name);
            (yyval.args) = 1; }
#line 2047 "y.tab.c"
    break;

  case 65: /* paramlist: IDENT paramlist  */
#line 369 "ekparser.y"
                           { 
            Objstring * name = make_string((yyvsp[-1].tok).start, (yyvsp[-1].tok).length);
            add_local(name);
            (yyval.args) = (yyvsp[0].args) + 1;}
#line 2056 "y.tab.c"
    break;

  case 66: /* loopatch: %empty  */
#line 377 "ekparser.y"
                        { (yyval.ptr) = code_get_count(&vm.instructions); }
#line 2062 "y.tab.c"
    break;

  case 67: /* funcpatch: %empty  */
#line 380 "ekparser.y"
            { (yyval.ptr) = CODEGEN2(jmp, NULL); }
#line 2068 "y.tab.c"
    break;

  case 68: /* loopatch2: %empty  */
#line 383 "ekparser.y"
                        {
          (yyval.ptr) = CODEGEN2(jz, NULL);
          CODEGEN(ppop);
          }
#line 2077 "y.tab.c"
    break;

  case 69: /* ifpatch: %empty  */
#line 389 "ekparser.y"
                       {
         DEBUG_PRINT("in if patch");
         (yyval.ptr) =CODEGEN2(jz, NULL); 
         CODEGEN(ppop);}
#line 2086 "y.tab.c"
    break;

  case 70: /* orpatch: %empty  */
#line 395 "ekparser.y"
                      {
         (yyval.ptr) = CODEGEN3(orjmp, NULL, NULL);
         }
#line 2094 "y.tab.c"
    break;

  case 71: /* andpatch: %empty  */
#line 400 "ekparser.y"
                       {
         (yyval.ptr) = CODEGEN3(andjmp, NULL, NULL);
          }
#line 2102 "y.tab.c"
    break;

  case 72: /* forpatch: %empty  */
#line 405 "ekparser.y"
                      {
        (yyval.ptr) =CODEGEN2(forloop, NULL);
        }
#line 2110 "y.tab.c"
    break;

  case 73: /* elsepatch: %empty  */
#line 410 "ekparser.y"
                       {
         DEBUG_PRINT("in elsepatch");
         (yyval.ptr) = CODEGEN2(jmp, NULL); 
         CODEGEN(ppop);}
#line 2119 "y.tab.c"
    break;


#line 2123 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 420 "ekparser.y"


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
