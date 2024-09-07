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


#line 120 "y.tab.c"

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

#line 269 "y.tab.c"

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
  YYSYMBOL_SOPE = 17,                      /* SOPE  */
  YYSYMBOL_SI = 18,                        /* SI  */
  YYSYMBOL_BIBEEKO = 19,                   /* BIBEEKO  */
  YYSYMBOL_LATI = 20,                      /* LATI  */
  YYSYMBOL_FUN = 21,                       /* FUN  */
  YYSYMBOL_IFIKUN = 22,                    /* IFIKUN  */
  YYSYMBOL_PE = 23,                        /* PE  */
  YYSYMBOL_COLON = 24,                     /* COLON  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_RPAR = 26,                      /* RPAR  */
  YYSYMBOL_SEMI = 27,                      /* SEMI  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_TABI = 30,                      /* TABI  */
  YYSYMBOL_ATI = 31,                       /* ATI  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GTEQ = 33,                      /* GTEQ  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_LTEQ = 35,                      /* LTEQ  */
  YYSYMBOL_EQEQ = 36,                      /* EQEQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 40,                  /* ASTERISK  */
  YYSYMBOL_SLASH = 41,                     /* SLASH  */
  YYSYMBOL_MODULUS = 42,                   /* MODULUS  */
  YYSYMBOL_UNARYMINUS = 43,                /* UNARYMINUS  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_CARET = 45,                     /* CARET  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_stmt = 48,                      /* stmt  */
  YYSYMBOL_stmtlist = 49,                  /* stmtlist  */
  YYSYMBOL_expr = 50,                      /* expr  */
  YYSYMBOL_funccall = 51,                  /* funccall  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_arglist = 53,                   /* arglist  */
  YYSYMBOL_printstmt = 54,                 /* printstmt  */
  YYSYMBOL_assignstmt = 55,                /* assignstmt  */
  YYSYMBOL_ifstmt = 56,                    /* ifstmt  */
  YYSYMBOL_ifblk = 57,                     /* ifblk  */
  YYSYMBOL_elsestmt = 58,                  /* elsestmt  */
  YYSYMBOL_whilestmt = 59,                 /* whilestmt  */
  YYSYMBOL_forstmt = 60,                   /* forstmt  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_ifikun = 62,                    /* ifikun  */
  YYSYMBOL_returnstmt = 63,                /* returnstmt  */
  YYSYMBOL_funcstmt = 64,                  /* funcstmt  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_paramlist = 67,                 /* paramlist  */
  YYSYMBOL_loopatch = 68,                  /* loopatch  */
  YYSYMBOL_funcpatch = 69,                 /* funcpatch  */
  YYSYMBOL_loopatch2 = 70,                 /* loopatch2  */
  YYSYMBOL_ifpatch = 71,                   /* ifpatch  */
  YYSYMBOL_orpatch = 72,                   /* orpatch  */
  YYSYMBOL_andpatch = 73,                  /* andpatch  */
  YYSYMBOL_forpatch = 74,                  /* forpatch  */
  YYSYMBOL_elsepatch = 75,                 /* elsepatch  */
  YYSYMBOL_stat_end = 76                   /* stat_end  */
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
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    84,    87,    91,    93,    95,    97,    99,
     101,   104,   110,   111,   112,   115,   121,   125,   129,   135,
     143,   145,   150,   154,   158,   162,   166,   170,   174,   178,
     182,   186,   190,   197,   203,   207,   211,   218,   218,   223,
     229,   230,   231,   234,   241,   247,   254,   258,   274,   279,
     284,   291,   297,   297,   305,   309,   312,   321,   330,   332,
     330,   351,   352,   356,   364,   369,   371,   377,   383,   388,
     393,   398,   404,   405
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
  "NIGBATI", "PADA", "ISE", "SOPE", "SI", "BIBEEKO", "LATI", "FUN",
  "IFIKUN", "PE", "COLON", "LPAR", "RPAR", "SEMI", "COMMA", "EQ", "TABI",
  "ATI", "GT", "GTEQ", "LT", "LTEQ", "EQEQ", "NEQ", "PLUS", "MINUS",
  "ASTERISK", "SLASH", "MODULUS", "UNARYMINUS", "NOT", "CARET", "$accept",
  "program", "stmt", "stmtlist", "expr", "funccall", "$@1", "arglist",
  "printstmt", "assignstmt", "ifstmt", "ifblk", "elsestmt", "whilestmt",
  "forstmt", "$@2", "ifikun", "returnstmt", "funcstmt", "$@3", "$@4",
  "paramlist", "loopatch", "funcpatch", "loopatch2", "ifpatch", "orpatch",
  "andpatch", "forpatch", "elsepatch", "stat_end", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -70,     6,   160,   -70,    -1,   -70,   -70,   -26,   -70,   -70,
     -70,   184,   184,   -70,    -8,   -70,   184,    14,    -5,   184,
     -70,   184,    -1,   343,   -70,   -70,   -70,   -70,    11,   -70,
     -70,   -70,   -70,   -70,   -70,   184,   -70,   195,   225,   184,
     184,    18,   343,     5,    28,   249,    -9,   -70,   184,   -70,
     -70,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   -70,   343,   -70,    29,   343,   343,    26,   184,
      13,   -70,   -27,   184,   184,   -27,   -27,   -27,   -27,   -27,
     -10,   -10,    -9,    -9,    -9,    -9,   -70,   -70,    42,    50,
     279,   -70,   -70,   358,   373,   160,   -70,    31,    30,   184,
      33,    38,    64,    50,   -70,   303,   184,    55,   -70,   -70,
     -70,   -70,   184,   -70,   319,    39,   160,   -70,    66,   343,
     -70,   184,   -70,   -70,   -70,   -70,   108,    71,   -70,   -70,
     134,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      12,     0,     2,     1,     0,    72,    15,    18,    19,    16,
      17,     0,     0,    64,    56,    58,     0,     0,     0,     0,
      73,     0,     0,     4,    20,     7,     5,     6,     0,     8,
       9,    11,    10,    13,     3,     0,    18,     0,     0,     0,
       0,     0,    43,     0,     0,     0,    21,    14,     0,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    44,    67,     0,    66,    57,     0,     0,
      64,    36,    27,     0,     0,    24,    23,    25,    28,    26,
      22,    29,    30,    31,    35,    34,    12,    45,     0,    61,
       0,    39,    37,    33,    32,    71,    12,    62,     0,     0,
       0,    48,     0,    61,    59,    54,    40,    12,    47,    51,
      63,    65,     0,    64,    41,     0,    50,    49,     0,    55,
      70,    40,    38,    12,    52,    42,     0,     0,    60,    12,
       0,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -69,   -11,   -70,   -70,   -55,   -70,   -70,
     -70,   -32,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -20,   -61,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    22,     2,    23,    24,   100,   115,    25,    26,
      27,    28,   108,    29,    30,   127,   113,    31,    32,    41,
     111,    98,    39,   118,    88,    86,    73,    74,   124,   101,
      33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    38,     5,    35,    34,    42,     3,     4,    45,    92,
      46,    56,    57,    58,    59,    60,    40,    95,    61,    43,
      44,    62,    47,    68,    63,    69,    20,   102,    66,    67,
      58,    59,    60,    70,    87,    61,    61,    72,   116,    91,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    89,   120,    96,   126,    97,   104,   107,    90,   103,
     130,   106,    93,    94,    11,   122,   125,     5,     6,     7,
       8,     9,    10,    11,   109,   117,    12,   123,    13,    14,
      15,    16,   129,   110,     0,    17,     0,    18,   105,    19,
       0,    20,     0,     0,     0,   114,     0,     0,     0,     0,
       0,   119,     0,    21,     0,     0,     0,     0,     0,     0,
     114,     5,     6,     7,     8,     9,    10,    11,   128,     0,
      12,     0,    13,    14,    15,    16,     0,     0,     0,    17,
       0,    18,     0,    19,     0,    20,     0,     5,     6,     7,
       8,     9,    10,    11,   131,     0,    12,    21,    13,    14,
      15,    16,     0,     0,     0,    17,     0,    18,     0,    19,
       0,    20,     0,     5,     6,     7,     8,     9,    10,    11,
       0,     0,    12,    21,    13,    14,    15,    16,     0,     0,
       0,    17,     0,    18,     0,    19,     0,    20,     6,    36,
       8,     9,    10,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    64,    18,    48,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    49,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    48,     0,
      61,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    48,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,    71,     0,     0,     0,    49,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    48,     0,    61,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      50,    51,    52,    53,    54,    55,    48,    56,    57,    58,
      59,    60,     0,     0,    61,   112,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,     0,   121,    61,    49,
      50,    51,    52,    53,    54,    55,    48,    56,    57,    58,
      59,    60,     0,     0,    61,     0,     0,     0,     0,     0,
       0,    48,     0,    49,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    48,     0,    61,    50,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,     0,     0,    61,     0,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      11,    12,     3,    29,     4,    16,     0,     1,    19,    70,
      21,    38,    39,    40,    41,    42,    24,    86,    45,     5,
      25,    10,    22,     5,    35,    20,    27,    96,    39,    40,
      40,    41,    42,     5,     5,    45,    45,    48,   107,    26,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    25,   113,    11,   123,     5,    26,    19,    69,    28,
     129,    28,    73,    74,     9,    26,   121,     3,     4,     5,
       6,     7,     8,     9,    10,   107,    12,    11,    14,    15,
      16,    17,    11,   103,    -1,    21,    -1,    23,    99,    25,
      -1,    27,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
     121,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      -1,    23,    -1,    25,    -1,    27,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    39,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    -1,    23,    -1,    25,
      -1,    27,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    39,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    -1,    23,    -1,    25,    -1,    27,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    23,    13,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    13,    -1,
      45,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    13,    38,    39,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    13,    -1,    45,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    13,    38,    39,    40,
      41,    42,    -1,    -1,    45,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    28,    45,    30,
      31,    32,    33,    34,    35,    36,    13,    38,    39,    40,
      41,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    13,    -1,    45,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    45,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    49,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    12,    14,    15,    16,    17,    21,    23,    25,
      27,    39,    48,    50,    51,    54,    55,    56,    57,    59,
      60,    63,    64,    76,    76,    29,     5,    50,    50,    68,
      24,    65,    50,     5,    25,    50,    50,    76,    13,    30,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    45,    10,    50,    11,    18,    50,    50,     5,    20,
       5,    26,    50,    72,    73,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    71,     5,    70,    25,
      50,    26,    68,    50,    50,    49,    11,     5,    67,    18,
      52,    75,    49,    28,    26,    50,    28,    19,    58,    10,
      67,    66,    22,    62,    50,    53,    49,    57,    69,    50,
      68,    28,    26,    11,    74,    53,    49,    61,    10,    11,
      49,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    52,    51,    51,
      53,    53,    53,    54,    55,    55,    56,    57,    58,    58,
      58,    59,    61,    60,    62,    62,    63,    63,    65,    66,
      64,    67,    67,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     3,     3,     0,     8,     4,
       0,     1,     3,     2,     3,     4,     2,     7,     0,     2,
       2,     7,     0,    13,     0,     2,     1,     3,     0,     0,
      11,     0,     1,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     1
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
#line 80 "ekparser.y"
                  { 
       DEBUG_PRINT("program stmt stat_end"); 
       CODEGEN(STOP);
       }
#line 1475 "y.tab.c"
    break;

  case 3: /* program: program error stat_end  */
#line 84 "ekparser.y"
                               { DEBUG_PRINT("program error stat_end"); yyerrok; }
#line 1481 "y.tab.c"
    break;

  case 4: /* stmt: expr  */
#line 88 "ekparser.y"
       { DEBUG_PRINT("stmt: expr"); 
         CODEGEN(pop);
       }
#line 1489 "y.tab.c"
    break;

  case 5: /* stmt: assignstmt  */
#line 92 "ekparser.y"
       { DEBUG_PRINT("stmt: assignstmt"); }
#line 1495 "y.tab.c"
    break;

  case 6: /* stmt: ifstmt  */
#line 94 "ekparser.y"
       { DEBUG_PRINT("stmt: ifstmt"); }
#line 1501 "y.tab.c"
    break;

  case 7: /* stmt: printstmt  */
#line 96 "ekparser.y"
       { DEBUG_PRINT("stmt: printstmt"); }
#line 1507 "y.tab.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 98 "ekparser.y"
       { DEBUG_PRINT("stmt: whilestmt"); }
#line 1513 "y.tab.c"
    break;

  case 9: /* stmt: forstmt  */
#line 99 "ekparser.y"
                 {
        DEBUG_PRINT("stmt: forstmt");}
#line 1520 "y.tab.c"
    break;

  case 10: /* stmt: funcstmt  */
#line 101 "ekparser.y"
                  {
         DEBUG_PRINT("stmt: funcstmt");
       }
#line 1528 "y.tab.c"
    break;

  case 11: /* stmt: returnstmt  */
#line 104 "ekparser.y"
                    {
         DEBUG_PRINT("stmt: returnstmt");
       }
#line 1536 "y.tab.c"
    break;

  case 12: /* stmtlist: %empty  */
#line 110 "ekparser.y"
                        { (yyval.ptr) =  code_get_count(&vm.instructions);}
#line 1542 "y.tab.c"
    break;

  case 14: /* stmtlist: stmtlist stmt stat_end  */
#line 112 "ekparser.y"
                                 { DEBUG_PRINT("stmtlist: stmlist stmt"); }
#line 1548 "y.tab.c"
    break;

  case 15: /* expr: NOOMBA  */
#line 116 "ekparser.y"
        { DEBUG_PRINT("expr: NUMBER"); 
          double num = check_err(strtod((yyvsp[0].tok).start, NULL));
          void * data = write_constant(CREATE_NUM(num));
          (yyval.ptr) = CODEGEN2(constpush, data);
        }
#line 1558 "y.tab.c"
    break;

  case 16: /* expr: OOTO  */
#line 122 "ekparser.y"
          { DEBUG_PRINT("expr: OOTO");
            (yyval.ptr) = CODEGEN(ooto);
          }
#line 1566 "y.tab.c"
    break;

  case 17: /* expr: IRO  */
#line 126 "ekparser.y"
          { DEBUG_PRINT("expr: IRO");
            (yyval.ptr) = CODEGEN(iro);
          }
#line 1574 "y.tab.c"
    break;

  case 18: /* expr: IDENT  */
#line 129 "ekparser.y"
                {
            
            DEBUG_PRINT("expr: IDENT");
            (yyval.ptr) = gen_var((yyvsp[0].tok).start, (yyvsp[0].tok).length, PUSH);
          }
#line 1584 "y.tab.c"
    break;

  case 19: /* expr: ORO  */
#line 136 "ekparser.y"
         {
            DEBUG_PRINT("expr: ORO");
            Objstring * string = make_string((yyvsp[0].tok).start+1, (yyvsp[0].tok).length - 2);
            void * data = write_constant(CREATE_STR(string));
            (yyval.ptr) = CODEGEN2(constpush, data);
          }
#line 1595 "y.tab.c"
    break;

  case 21: /* expr: MINUS expr  */
#line 146 "ekparser.y"
        { DEBUG_PRINT("expr: MINUS expr");
          CODEGEN(neg);
          (yyval.ptr) = (yyvsp[0].ptr);
        }
#line 1604 "y.tab.c"
    break;

  case 22: /* expr: expr PLUS expr  */
#line 151 "ekparser.y"
        { DEBUG_PRINT("expr: expr + expr");
          CODEGEN(add);
        }
#line 1612 "y.tab.c"
    break;

  case 23: /* expr: expr GTEQ expr  */
#line 155 "ekparser.y"
        { DEBUG_PRINT("expr: expr >= expr");
          CODEGEN(ge);
        }
#line 1620 "y.tab.c"
    break;

  case 24: /* expr: expr GT expr  */
#line 159 "ekparser.y"
        { DEBUG_PRINT("expr: expr > expr");
          CODEGEN(gt);
        }
#line 1628 "y.tab.c"
    break;

  case 25: /* expr: expr LT expr  */
#line 163 "ekparser.y"
        { DEBUG_PRINT("expr: expr < expr");
          CODEGEN(lt);
        }
#line 1636 "y.tab.c"
    break;

  case 26: /* expr: expr EQEQ expr  */
#line 167 "ekparser.y"
        { DEBUG_PRINT("expr: expr == expr");
          CODEGEN(eq);
        }
#line 1644 "y.tab.c"
    break;

  case 27: /* expr: expr DOGBA expr  */
#line 171 "ekparser.y"
          { DEBUG_PRINT("expr: expr DOGBA expr ");
            CODEGEN(eq);
          }
#line 1652 "y.tab.c"
    break;

  case 28: /* expr: expr LTEQ expr  */
#line 175 "ekparser.y"
        { DEBUG_PRINT("expr: expr <= expr");
          CODEGEN(le);
        }
#line 1660 "y.tab.c"
    break;

  case 29: /* expr: expr MINUS expr  */
#line 179 "ekparser.y"
        { DEBUG_PRINT("expr: expr - expr"); 
          CODEGEN(sub);
        }
#line 1668 "y.tab.c"
    break;

  case 30: /* expr: expr ASTERISK expr  */
#line 183 "ekparser.y"
        { DEBUG_PRINT("expr: expr * expr"); 
          CODEGEN(mul);
        }
#line 1676 "y.tab.c"
    break;

  case 31: /* expr: expr SLASH expr  */
#line 187 "ekparser.y"
        { DEBUG_PRINT("expr: expr / expr"); 
          CODEGEN(divide);
        }
#line 1684 "y.tab.c"
    break;

  case 32: /* expr: expr ATI andpatch expr  */
#line 190 "ekparser.y"
                                 {
            /* if expr is true jump to evaluate next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) (yyvsp[0].ptr);
            /* if expr is false jmp to the end of the production */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) code_get_count(
                &vm.instructions);
        }
#line 1696 "y.tab.c"
    break;

  case 33: /* expr: expr TABI orpatch expr  */
#line 197 "ekparser.y"
                                 {
            /* patch if expr is true jump to the end of the rule */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) code_get_count(&vm.instructions);
            /* if expr is false jump to the next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) (yyvsp[0].ptr);
        }
#line 1707 "y.tab.c"
    break;

  case 34: /* expr: expr CARET expr  */
#line 204 "ekparser.y"
        { DEBUG_PRINT("expr: expr ^ expr"); 
          CODEGEN(power);
        }
#line 1715 "y.tab.c"
    break;

  case 35: /* expr: expr MODULUS expr  */
#line 207 "ekparser.y"
                            { 
        DEBUG_PRINT("expr: expr %% expr"); 
        CODEGEN(mod);
        }
#line 1724 "y.tab.c"
    break;

  case 36: /* expr: LPAR expr RPAR  */
#line 212 "ekparser.y"
        { DEBUG_PRINT("expr: (expr)"); 
          (yyval.ptr) = (yyvsp[-1].ptr);
         }
#line 1732 "y.tab.c"
    break;

  case 37: /* $@1: %empty  */
#line 218 "ekparser.y"
                                  {gen_var((yyvsp[-1].tok).start, (yyvsp[-1].tok).length, PUSH); }
#line 1738 "y.tab.c"
    break;

  case 38: /* funccall: PE LPAR IDENT loopatch $@1 COMMA arglist RPAR  */
#line 219 "ekparser.y"
         {
             CODEGEN2(call, (void *) ((intptr_t) (yyvsp[-1].args))); 
             (yyval.ptr) = (yyvsp[-4].ptr);
          }
#line 1747 "y.tab.c"
    break;

  case 39: /* funccall: PE LPAR IDENT RPAR  */
#line 223 "ekparser.y"
                              {
            (yyval.ptr) = gen_var((yyvsp[-1].tok).start, (yyvsp[-1].tok).length, PUSH); 
            CODEGEN2(call, (void *) ((intptr_t) 0));
         }
#line 1756 "y.tab.c"
    break;

  case 40: /* arglist: %empty  */
#line 229 "ekparser.y"
                         { (yyval.args) = 0; }
#line 1762 "y.tab.c"
    break;

  case 41: /* arglist: expr  */
#line 230 "ekparser.y"
                {(yyval.args) = 1; }
#line 1768 "y.tab.c"
    break;

  case 42: /* arglist: expr COMMA arglist  */
#line 231 "ekparser.y"
                              {(yyval.args) = (yyvsp[0].args) + 1; }
#line 1774 "y.tab.c"
    break;

  case 43: /* printstmt: SOPE expr  */
#line 234 "ekparser.y"
                     {
         DEBUG_PRINT("printstmt: SOPE expr");
         CODEGEN(print);
         (yyval.ptr) = (yyvsp[0].ptr);
         }
#line 1784 "y.tab.c"
    break;

  case 44: /* assignstmt: IDENT EQ expr  */
#line 241 "ekparser.y"
                          {
          DEBUG_PRINT("assignstmt:\
          IDENT EQ expr");
           (yyval.ptr) = (yyvsp[0].ptr);
           gen_var((yyvsp[-2].tok).start, (yyvsp[-2].tok).length, STORE);
           }
#line 1795 "y.tab.c"
    break;

  case 45: /* assignstmt: FI expr SI IDENT  */
#line 248 "ekparser.y"
           {
           (yyval.ptr) = (yyvsp[-2].ptr);
           gen_var((yyvsp[0].tok).start, (yyvsp[0].tok).length, STORE);
           }
#line 1804 "y.tab.c"
    break;

  case 46: /* ifstmt: ifblk PARI  */
#line 254 "ekparser.y"
                    {DEBUG_PRINT("ifstmt: ifblk PARI");}
#line 1810 "y.tab.c"
    break;

  case 47: /* ifblk: TI expr SE ifpatch stmtlist elsepatch elsestmt  */
#line 258 "ekparser.y"
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
#line 1829 "y.tab.c"
    break;

  case 48: /* elsestmt: %empty  */
#line 274 "ekparser.y"
                         {
         DEBUG_PRINT("elsestmt: /*nothing*/");
         (yyval.ptr) =  code_get_count(&vm.instructions); 
         DEBUG_PRINT(" elsestmt return count: %ld\n", (yyval.ptr));
        }
#line 1839 "y.tab.c"
    break;

  case 49: /* elsestmt: BIBEEKO ifblk  */
#line 279 "ekparser.y"
                         { /* else if */
         DEBUG_PRINT("elsestmt: BIBEEKO ifblk");
         (yyval.ptr) = (yyvsp[0].ptr);
         DEBUG_PRINT(" bibeeko ifblk return count: %ld\n", (yyval.ptr));
         }
#line 1849 "y.tab.c"
    break;

  case 50: /* elsestmt: BIBEEKO stmtlist  */
#line 284 "ekparser.y"
                            {
         DEBUG_PRINT("elsestmt: BIBEEKO SE stmtlist");
         (yyval.ptr) = (yyvsp[0].ptr);
         DEBUG_PRINT(" bibeeko stmtlist return count: %ld\n", (yyval.ptr));
         }
#line 1859 "y.tab.c"
    break;

  case 51: /* whilestmt: NIGBATI loopatch expr loopatch2 SE stmtlist PARI  */
#line 291 "ekparser.y"
                                                            {
         CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
         vm.instructions.data[(yyvsp[-3].ptr)+1] = (void *) code_get_count(&vm.instructions);
         (yyval.ptr) = (yyvsp[-5].ptr);
}
#line 1869 "y.tab.c"
    break;

  case 52: /* $@2: %empty  */
#line 297 "ekparser.y"
                                                              {
        gen_var((yyvsp[-7].tok).start, (yyvsp[-7].tok).length, STORE); }
#line 1876 "y.tab.c"
    break;

  case 53: /* forstmt: FUN IDENT LATI expr SI expr ifikun loopatch forpatch $@2 SE stmtlist PARI  */
#line 298 "ekparser.y"
                                                                {
        CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
        vm.instructions.data[(yyvsp[-5].ptr)+1] = 
           (void *) code_get_count(&vm.instructions);
        (yyval.ptr) = (yyvsp[-9].ptr);}
#line 1886 "y.tab.c"
    break;

  case 54: /* ifikun: %empty  */
#line 305 "ekparser.y"
                      { 
      void * data = write_constant(CREATE_NUM(1));
      (yyval.ptr) = CODEGEN2(constpush, data);
      }
#line 1895 "y.tab.c"
    break;

  case 55: /* ifikun: IFIKUN expr  */
#line 309 "ekparser.y"
                     {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1901 "y.tab.c"
    break;

  case 56: /* returnstmt: PADA  */
#line 312 "ekparser.y"
                 {
            if(!IN_SCOPE()){
                EK_ERROR(ek_state.line_no, 
                "Return statement is not allowed outside a function");
            }
            void * data = write_constant(KOROFO);
            (yyval.ptr) = CODEGEN2(constpush, data);
            CODEGEN(ret);
          }
#line 1915 "y.tab.c"
    break;

  case 57: /* returnstmt: PADA COLON expr  */
#line 321 "ekparser.y"
                            { 
                if(!IN_SCOPE()){
                 EK_ERROR(ek_state.line_no, 
                 "Return statement is not allowed outside a function");
                }
                (yyval.ptr) = (yyvsp[0].ptr);  CODEGEN(ret); 
           }
#line 1927 "y.tab.c"
    break;

  case 58: /* $@3: %empty  */
#line 330 "ekparser.y"
              { begin_scope(); DEBUG_PRINT("matching ise"); }
#line 1933 "y.tab.c"
    break;

  case 59: /* $@4: %empty  */
#line 332 "ekparser.y"
               { 
          /* this hack allows function to be define in its real scope 
           * since function is bound to an outer scoe */
          current.scope_depth--; def_func((yyvsp[-3].tok), (yyvsp[-1].args)); current.scope_depth++;
          }
#line 1943 "y.tab.c"
    break;

  case 60: /* funcstmt: ISE $@3 IDENT LPAR paramlist RPAR $@4 funcpatch SE stmtlist PARI  */
#line 337 "ekparser.y"
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
          vm.instructions.data[(yyvsp[-3].ptr) + 1] = (void *) code_get_count(&vm.instructions);
        }
#line 1960 "y.tab.c"
    break;

  case 61: /* paramlist: %empty  */
#line 351 "ekparser.y"
                          {(yyval.args) = 0;}
#line 1966 "y.tab.c"
    break;

  case 62: /* paramlist: IDENT  */
#line 352 "ekparser.y"
                 {
            Objstring * name = make_string((yyvsp[0].tok).start, (yyvsp[0].tok).length);
            add_local(name);
            (yyval.args) = 1; }
#line 1975 "y.tab.c"
    break;

  case 63: /* paramlist: IDENT COMMA paramlist  */
#line 356 "ekparser.y"
                                 { 
            Objstring * name = make_string((yyvsp[-2].tok).start, (yyvsp[-2].tok).length);
            add_local(name);
            (yyval.args) = (yyvsp[0].args) + 1;}
#line 1984 "y.tab.c"
    break;

  case 64: /* loopatch: %empty  */
#line 364 "ekparser.y"
            {
          (yyval.ptr) = code_get_count(&vm.instructions);
          }
#line 1992 "y.tab.c"
    break;

  case 65: /* funcpatch: %empty  */
#line 369 "ekparser.y"
            { (yyval.ptr) = CODEGEN2(jmp, NULL); }
#line 1998 "y.tab.c"
    break;

  case 66: /* loopatch2: %empty  */
#line 371 "ekparser.y"
            {
          (yyval.ptr) = CODEGEN2(jz, NULL);
          CODEGEN(pop);
          }
#line 2007 "y.tab.c"
    break;

  case 67: /* ifpatch: %empty  */
#line 377 "ekparser.y"
           {
         DEBUG_PRINT("in if patch");
         (yyval.ptr) =CODEGEN2(jz, NULL); 
         CODEGEN(pop);}
#line 2016 "y.tab.c"
    break;

  case 68: /* orpatch: %empty  */
#line 383 "ekparser.y"
           {
         (yyval.ptr) = CODEGEN3(orjmp, NULL, NULL);
         }
#line 2024 "y.tab.c"
    break;

  case 69: /* andpatch: %empty  */
#line 388 "ekparser.y"
           {
         (yyval.ptr) = CODEGEN3(andjmp, NULL, NULL);
          }
#line 2032 "y.tab.c"
    break;

  case 70: /* forpatch: %empty  */
#line 393 "ekparser.y"
          {
        (yyval.ptr) =CODEGEN2(forloop, NULL);
        }
#line 2040 "y.tab.c"
    break;

  case 71: /* elsepatch: %empty  */
#line 398 "ekparser.y"
           {
         DEBUG_PRINT("in elsepatch");
         (yyval.ptr) = CODEGEN2(jmp, NULL); 
         CODEGEN(pop);}
#line 2049 "y.tab.c"
    break;


#line 2053 "y.tab.c"

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

#line 408 "ekparser.y"


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
