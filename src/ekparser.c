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


#line 101 "y.tab.c"

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
    LPAR = 278,                    /* LPAR  */
    RPAR = 279,                    /* RPAR  */
    SEMI = 280,                    /* SEMI  */
    EQ = 281,                      /* EQ  */
    TABI = 282,                    /* TABI  */
    ATI = 283,                     /* ATI  */
    GT = 284,                      /* GT  */
    GTEQ = 285,                    /* GTEQ  */
    LT = 286,                      /* LT  */
    LTEQ = 287,                    /* LTEQ  */
    EQEQ = 288,                    /* EQEQ  */
    NEQ = 289,                     /* NEQ  */
    PLUS = 290,                    /* PLUS  */
    MINUS = 291,                   /* MINUS  */
    ASTERISK = 292,                /* ASTERISK  */
    SLASH = 293,                   /* SLASH  */
    MODULUS = 294,                 /* MODULUS  */
    UNARYMINUS = 295,              /* UNARYMINUS  */
    NOT = 296,                     /* NOT  */
    CARET = 297                    /* CARET  */
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
#define LPAR 278
#define RPAR 279
#define SEMI 280
#define EQ 281
#define TABI 282
#define ATI 283
#define GT 284
#define GTEQ 285
#define LT 286
#define LTEQ 287
#define EQEQ 288
#define NEQ 289
#define PLUS 290
#define MINUS 291
#define ASTERISK 292
#define SLASH 293
#define MODULUS 294
#define UNARYMINUS 295
#define NOT 296
#define CARET 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "ekparser.y"

    Token tok;
    long int ptr;

#line 243 "y.tab.c"

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
  YYSYMBOL_LPAR = 23,                      /* LPAR  */
  YYSYMBOL_RPAR = 24,                      /* RPAR  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_TABI = 27,                      /* TABI  */
  YYSYMBOL_ATI = 28,                       /* ATI  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_GTEQ = 30,                      /* GTEQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LTEQ = 32,                      /* LTEQ  */
  YYSYMBOL_EQEQ = 33,                      /* EQEQ  */
  YYSYMBOL_NEQ = 34,                       /* NEQ  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 37,                  /* ASTERISK  */
  YYSYMBOL_SLASH = 38,                     /* SLASH  */
  YYSYMBOL_MODULUS = 39,                   /* MODULUS  */
  YYSYMBOL_UNARYMINUS = 40,                /* UNARYMINUS  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_CARET = 42,                     /* CARET  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_stmtlist = 46,                  /* stmtlist  */
  YYSYMBOL_expr = 47,                      /* expr  */
  YYSYMBOL_printstmt = 48,                 /* printstmt  */
  YYSYMBOL_assignstmt = 49,                /* assignstmt  */
  YYSYMBOL_ifstmt = 50,                    /* ifstmt  */
  YYSYMBOL_ifblk = 51,                     /* ifblk  */
  YYSYMBOL_elsestmt = 52,                  /* elsestmt  */
  YYSYMBOL_whilestmt = 53,                 /* whilestmt  */
  YYSYMBOL_forstmt = 54,                   /* forstmt  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_ifikun = 56,                    /* ifikun  */
  YYSYMBOL_funcstmt = 57,                  /* funcstmt  */
  YYSYMBOL_arglist = 58,                   /* arglist  */
  YYSYMBOL_loopatch = 59,                  /* loopatch  */
  YYSYMBOL_loopatch2 = 60,                 /* loopatch2  */
  YYSYMBOL_ifpatch = 61,                   /* ifpatch  */
  YYSYMBOL_orpatch = 62,                   /* orpatch  */
  YYSYMBOL_andpatch = 63,                  /* andpatch  */
  YYSYMBOL_forpatch = 64,                  /* forpatch  */
  YYSYMBOL_elsepatch = 65,                 /* elsepatch  */
  YYSYMBOL_stat_end = 66                   /* stat_end  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    63,    66,    70,    72,    74,    76,    78,
      80,    86,    87,    88,    91,    97,   101,   105,   112,   120,
     124,   128,   132,   136,   140,   144,   148,   152,   156,   160,
     164,   170,   176,   180,   184,   190,   197,   203,   210,   214,
     229,   233,   237,   242,   248,   248,   257,   261,   265,   270,
     275,   280,   286,   292,   297,   302,   307,   313,   314
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
  "IFIKUN", "LPAR", "RPAR", "SEMI", "EQ", "TABI", "ATI", "GT", "GTEQ",
  "LT", "LTEQ", "EQEQ", "NEQ", "PLUS", "MINUS", "ASTERISK", "SLASH",
  "MODULUS", "UNARYMINUS", "NOT", "CARET", "$accept", "program", "stmt",
  "stmtlist", "expr", "printstmt", "assignstmt", "ifstmt", "ifblk",
  "elsestmt", "whilestmt", "forstmt", "$@1", "ifikun", "funcstmt",
  "arglist", "loopatch", "loopatch2", "ifpatch", "orpatch", "andpatch",
  "forpatch", "elsepatch", "stat_end", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,    10,   110,   -25,     2,   -25,   -25,   -24,   -25,   -25,
     -25,    75,    75,   -25,     4,    75,     7,    75,   -25,    75,
       2,   238,   -25,   -25,   -25,    -3,   -25,   -25,   -25,   -25,
     -25,    75,   -25,   121,   148,    75,     5,   238,    13,   169,
     -20,   -25,    75,   -25,   -25,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,   -25,   238,   -25,    24,
     238,   -25,    75,   -25,    11,    75,    75,    11,    11,    11,
      11,    11,   100,   100,   -20,   -20,   -20,   -20,   -25,   -25,
      41,    40,   196,   259,   273,   110,   -25,     9,    75,    47,
      53,    58,   217,    62,   -25,   -25,   -25,    75,   -25,   110,
     -25,   238,   -25,   -25,    61,   -25,    87,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,     2,     1,     0,    57,    14,    17,    18,    15,
      16,     0,     0,    50,     0,     0,     0,     0,    58,     0,
       0,     4,     7,     5,     6,     0,     8,     9,    10,    12,
       3,     0,    17,     0,     0,     0,     0,    35,     0,     0,
      19,    13,     0,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    36,    52,     0,
      51,    49,     0,    34,    25,     0,     0,    22,    21,    23,
      26,    24,    20,    27,    28,    29,    33,    32,    11,    37,
       0,     0,     0,    31,    30,    56,    11,     0,     0,    40,
       0,     0,    46,    11,    39,    43,    48,     0,    50,    42,
      41,    47,    55,    44,     0,    11,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -14,    50,   -11,   -25,   -25,   -25,   -18,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -13,   -25,   -25,   -25,
     -25,   -25,   -25,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    20,     2,    21,    22,    23,    24,    25,    94,
      26,    27,   104,    98,    28,    81,    35,    80,    78,    65,
      66,   103,    89,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    34,    31,    30,    37,     5,    39,    56,    40,    36,
       3,     4,    38,     6,     7,     8,     9,    10,    11,    41,
      57,    12,    55,    13,    60,    14,    15,    18,    61,    79,
      16,    64,    17,    62,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    19,    50,    51,    52,    53,
      54,    82,    86,    55,    83,    84,     5,     6,     7,     8,
       9,    10,    11,    95,    87,    12,    93,    13,    96,    14,
      15,    11,   105,    91,    16,   100,    17,    92,    18,     6,
      32,     8,     9,    10,     0,   102,   101,     0,     0,    19,
       5,     6,     7,     8,     9,    10,    11,   107,    17,    12,
       0,    13,     0,    14,    15,     0,     0,     0,    16,     0,
      17,    19,    18,     5,     6,     7,     8,     9,    10,    11,
       0,     0,    12,    19,    13,     0,    14,    15,    85,     0,
       0,    16,    58,    17,    42,    18,    90,    52,    53,    54,
       0,     0,    55,    99,     0,     0,    19,     0,    43,    44,
      45,    46,    47,    48,    49,   106,    50,    51,    52,    53,
      54,    42,     0,    55,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,    42,    50,    51,    52,    53,    54,     0,     0,
      55,     0,     0,    63,     0,     0,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,    42,
       0,    55,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      42,    50,    51,    52,    53,    54,     0,     0,    55,    97,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,    42,    50,    51,    52,    53,    54,     0,     0,    55,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,    42,    50,    51,    52,    53,    54,     0,     0,
      55,     0,     0,     0,     0,     0,    42,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,     0,
       0,    55,    45,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,     0,     0,    55
};

static const yytype_int8 yycheck[] =
{
      11,    12,    26,     4,    15,     3,    17,    10,    19,     5,
       0,     1,     5,     4,     5,     6,     7,     8,     9,    20,
      31,    12,    42,    14,    35,    16,    17,    25,    23,     5,
      21,    42,    23,    20,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    36,    35,    36,    37,    38,
      39,    62,    11,    42,    65,    66,     3,     4,     5,     6,
       7,     8,     9,    10,    24,    12,    19,    14,    10,    16,
      17,     9,    11,    87,    21,    93,    23,    88,    25,     4,
       5,     6,     7,     8,    -1,    98,    97,    -1,    -1,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    23,    12,
      -1,    14,    -1,    16,    17,    -1,    -1,    -1,    21,    -1,
      23,    36,    25,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    36,    14,    -1,    16,    17,    78,    -1,
      -1,    21,    11,    23,    13,    25,    86,    37,    38,    39,
      -1,    -1,    42,    93,    -1,    -1,    36,    -1,    27,    28,
      29,    30,    31,    32,    33,   105,    35,    36,    37,    38,
      39,    13,    -1,    42,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    13,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    13,
      -1,    42,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      13,    35,    36,    37,    38,    39,    -1,    -1,    42,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    13,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    13,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    13,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    42,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    46,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    12,    14,    16,    17,    21,    23,    25,    36,
      45,    47,    48,    49,    50,    51,    53,    54,    57,    66,
      66,    26,     5,    47,    47,    59,     5,    47,     5,    47,
      47,    66,    13,    27,    28,    29,    30,    31,    32,    33,
      35,    36,    37,    38,    39,    42,    10,    47,    11,    18,
      47,    23,    20,    24,    47,    62,    63,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    61,     5,
      60,    58,    47,    47,    47,    46,    11,    24,    18,    65,
      46,    45,    47,    19,    52,    10,    10,    22,    56,    46,
      51,    47,    59,    64,    55,    11,    46,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    50,    51,
      52,    52,    52,    53,    55,    54,    56,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     3,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     3,     3,     3,     2,     3,     4,     2,     7,
       0,     2,     2,     7,     0,    13,     0,     2,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     1
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
#line 59 "ekparser.y"
                  { 
       DEBUG_PRINT("program stmt stat_end"); 
       CODEGEN(STOP);
       }
#line 1400 "y.tab.c"
    break;

  case 3: /* program: program error stat_end  */
#line 63 "ekparser.y"
                               { DEBUG_PRINT("program error stat_end"); yyerrok; }
#line 1406 "y.tab.c"
    break;

  case 4: /* stmt: expr  */
#line 67 "ekparser.y"
       { DEBUG_PRINT("stmt: expr"); 
         CODEGEN(pop);
       }
#line 1414 "y.tab.c"
    break;

  case 5: /* stmt: assignstmt  */
#line 71 "ekparser.y"
       { DEBUG_PRINT("stmt: assignstmt"); }
#line 1420 "y.tab.c"
    break;

  case 6: /* stmt: ifstmt  */
#line 73 "ekparser.y"
       { DEBUG_PRINT("stmt: ifstmt"); }
#line 1426 "y.tab.c"
    break;

  case 7: /* stmt: printstmt  */
#line 75 "ekparser.y"
       { DEBUG_PRINT("stmt: printstmt"); }
#line 1432 "y.tab.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 77 "ekparser.y"
       { DEBUG_PRINT("stmt: whilestmt"); }
#line 1438 "y.tab.c"
    break;

  case 9: /* stmt: forstmt  */
#line 78 "ekparser.y"
                 {
        DEBUG_PRINT("stmt: forstmt");}
#line 1445 "y.tab.c"
    break;

  case 10: /* stmt: funcstmt  */
#line 80 "ekparser.y"
                  {
         DEBUG_PRINT("stmt: funcstmt");
       }
#line 1453 "y.tab.c"
    break;

  case 11: /* stmtlist: %empty  */
#line 86 "ekparser.y"
                        { (yyval.ptr) =  code_get_count(&vm.instructions);}
#line 1459 "y.tab.c"
    break;

  case 13: /* stmtlist: stmtlist stmt stat_end  */
#line 88 "ekparser.y"
                                 { DEBUG_PRINT("stmtlist: stmlist stmt"); }
#line 1465 "y.tab.c"
    break;

  case 14: /* expr: NOOMBA  */
#line 92 "ekparser.y"
        { DEBUG_PRINT("expr: NUMBER"); 
          double num = check_err(strtod((yyvsp[0].tok).start, NULL));
          void * data = write_constant(CREATE_NUM(num));
          (yyval.ptr) = CODEGEN2(constpush, data);
        }
#line 1475 "y.tab.c"
    break;

  case 15: /* expr: OOTO  */
#line 98 "ekparser.y"
          { DEBUG_PRINT("expr: OOTO");
            (yyval.ptr) = CODEGEN(ooto);
          }
#line 1483 "y.tab.c"
    break;

  case 16: /* expr: IRO  */
#line 102 "ekparser.y"
          { DEBUG_PRINT("expr: IRO");
            (yyval.ptr) = CODEGEN(iro);
          }
#line 1491 "y.tab.c"
    break;

  case 17: /* expr: IDENT  */
#line 105 "ekparser.y"
                {
            DEBUG_PRINT("expr: IDENT");
            Objstring * string = make_string((yyvsp[0].tok).start, (yyvsp[0].tok).length);
            void * data = write_constant(CREATE_STR(string));
            (yyval.ptr) = CODEGEN2(gvarpush, data);
          }
#line 1502 "y.tab.c"
    break;

  case 18: /* expr: ORO  */
#line 113 "ekparser.y"
         {
            DEBUG_PRINT("expr: ORO");
            Objstring * string = make_string((yyvsp[0].tok).start+1, (yyvsp[0].tok).length - 2);
            void * data = write_constant(CREATE_STR(string));
            (yyval.ptr) = CODEGEN2(constpush, data);
          }
#line 1513 "y.tab.c"
    break;

  case 19: /* expr: MINUS expr  */
#line 121 "ekparser.y"
        { DEBUG_PRINT("expr: MINUS expr");
          CODEGEN(neg);
        }
#line 1521 "y.tab.c"
    break;

  case 20: /* expr: expr PLUS expr  */
#line 125 "ekparser.y"
        { DEBUG_PRINT("expr: expr + expr");
          CODEGEN(add);
        }
#line 1529 "y.tab.c"
    break;

  case 21: /* expr: expr GTEQ expr  */
#line 129 "ekparser.y"
        { DEBUG_PRINT("expr: expr >= expr");
          CODEGEN(ge);
        }
#line 1537 "y.tab.c"
    break;

  case 22: /* expr: expr GT expr  */
#line 133 "ekparser.y"
        { DEBUG_PRINT("expr: expr > expr");
          CODEGEN(gt);
        }
#line 1545 "y.tab.c"
    break;

  case 23: /* expr: expr LT expr  */
#line 137 "ekparser.y"
        { DEBUG_PRINT("expr: expr < expr");
          CODEGEN(lt);
        }
#line 1553 "y.tab.c"
    break;

  case 24: /* expr: expr EQEQ expr  */
#line 141 "ekparser.y"
        { DEBUG_PRINT("expr: expr == expr");
          CODEGEN(eq);
        }
#line 1561 "y.tab.c"
    break;

  case 25: /* expr: expr DOGBA expr  */
#line 145 "ekparser.y"
          { DEBUG_PRINT("expr: expr DOGBA expr ");
            CODEGEN(eq);
          }
#line 1569 "y.tab.c"
    break;

  case 26: /* expr: expr LTEQ expr  */
#line 149 "ekparser.y"
        { DEBUG_PRINT("expr: expr <= expr");
          CODEGEN(le);
        }
#line 1577 "y.tab.c"
    break;

  case 27: /* expr: expr MINUS expr  */
#line 153 "ekparser.y"
        { DEBUG_PRINT("expr: expr - expr"); 
          CODEGEN(sub);
        }
#line 1585 "y.tab.c"
    break;

  case 28: /* expr: expr ASTERISK expr  */
#line 157 "ekparser.y"
        { DEBUG_PRINT("expr: expr * expr"); 
          CODEGEN(mul);
        }
#line 1593 "y.tab.c"
    break;

  case 29: /* expr: expr SLASH expr  */
#line 161 "ekparser.y"
        { DEBUG_PRINT("expr: expr / expr"); 
          CODEGEN(divide);
        }
#line 1601 "y.tab.c"
    break;

  case 30: /* expr: expr ATI andpatch expr  */
#line 164 "ekparser.y"
                                 {
            /* if expr is true jump to evaluate next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) (yyvsp[0].ptr);
            /* if expr is false jmp to the end of the production */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) code_get_count(&vm.instructions);
        }
#line 1612 "y.tab.c"
    break;

  case 31: /* expr: expr TABI orpatch expr  */
#line 170 "ekparser.y"
                                 {
            /* patch if expr is true jump to the end of the rule */
            vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) code_get_count(&vm.instructions);
            /* if expr is false jump to the next expr */
            vm.instructions.data[(yyvsp[-1].ptr)+2] = (void *) (yyvsp[0].ptr);
        }
#line 1623 "y.tab.c"
    break;

  case 32: /* expr: expr CARET expr  */
#line 177 "ekparser.y"
        { DEBUG_PRINT("expr: expr ^ expr"); 
          CODEGEN(power);
        }
#line 1631 "y.tab.c"
    break;

  case 33: /* expr: expr MODULUS expr  */
#line 180 "ekparser.y"
                            { 
        DEBUG_PRINT("expr: expr %% expr"); 
        CODEGEN(mod);
        }
#line 1640 "y.tab.c"
    break;

  case 34: /* expr: LPAR expr RPAR  */
#line 185 "ekparser.y"
        { DEBUG_PRINT("expr: (expr)"); 
          (yyval.ptr) = (yyvsp[-1].ptr);
         }
#line 1648 "y.tab.c"
    break;

  case 35: /* printstmt: SOPE expr  */
#line 190 "ekparser.y"
                     {
         DEBUG_PRINT("printstmt: SOPE expr");
         CODEGEN(print);
         (yyval.ptr) = (yyvsp[0].ptr);
         }
#line 1658 "y.tab.c"
    break;

  case 36: /* assignstmt: IDENT EQ expr  */
#line 197 "ekparser.y"
                           {
          DEBUG_PRINT("assignstmt:\
          IDENT EQ expr");
           (yyval.ptr) = (yyvsp[0].ptr);
           gen_var((yyvsp[-2].tok).start, (yyvsp[-2].tok).length);
           }
#line 1669 "y.tab.c"
    break;

  case 37: /* assignstmt: FI expr SI IDENT  */
#line 204 "ekparser.y"
           {
           (yyval.ptr) = (yyvsp[-2].ptr);
           gen_var((yyvsp[0].tok).start, (yyvsp[0].tok).length);
           }
#line 1678 "y.tab.c"
    break;

  case 38: /* ifstmt: ifblk PARI  */
#line 210 "ekparser.y"
                    {DEBUG_PRINT("ifstmt: ifblk PARI");}
#line 1684 "y.tab.c"
    break;

  case 39: /* ifblk: TI expr SE ifpatch stmtlist elsepatch elsestmt  */
#line 214 "ekparser.y"
                                                      {

      DEBUG_PRINT("ifblk: TI expr \
        SE ifpatch stmtlist elsepatch elsestmt ");
      //fix backpatch

      vm.instructions.data[(yyvsp[-3].ptr) + 1] = (void *) (yyvsp[0].ptr);
      /* printf("if patch: %ld %ld\n", $4, $7); */
      vm.instructions.data[(yyvsp[-1].ptr)+1] = (void *) code_get_count(&vm.instructions);

      /* printf("elsepatch: %ld %ld\n", $6, code_get_count(&vm.instructions)); */
      (yyval.ptr) = (yyvsp[-5].ptr);
      }
#line 1702 "y.tab.c"
    break;

  case 40: /* elsestmt: %empty  */
#line 229 "ekparser.y"
                         {
         DEBUG_PRINT("elsestmt: /*nothing*/");
         (yyval.ptr) =  code_get_count(&vm.instructions); 
        }
#line 1711 "y.tab.c"
    break;

  case 41: /* elsestmt: BIBEEKO ifblk  */
#line 233 "ekparser.y"
                         { /* else if */
         DEBUG_PRINT("elsestmt: BIBEEKO ifblk");
         (yyval.ptr) = (yyvsp[0].ptr);
         }
#line 1720 "y.tab.c"
    break;

  case 42: /* elsestmt: BIBEEKO stmtlist  */
#line 237 "ekparser.y"
                            {
         DEBUG_PRINT("elsestmt: BIBEEKO SE stmtlist");
         (yyval.ptr) = (yyvsp[0].ptr);}
#line 1728 "y.tab.c"
    break;

  case 43: /* whilestmt: NIGBATI loopatch expr loopatch2 SE stmtlist PARI  */
#line 242 "ekparser.y"
                                                            {
         CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
         vm.instructions.data[(yyvsp[-3].ptr)+1] = (void *) code_get_count(&vm.instructions);
         (yyval.ptr) = (yyvsp[-5].ptr);
}
#line 1738 "y.tab.c"
    break;

  case 44: /* $@1: %empty  */
#line 248 "ekparser.y"
                                                              {
        gen_var((yyvsp[-7].tok).start, (yyvsp[-7].tok).length);
       }
#line 1746 "y.tab.c"
    break;

  case 45: /* forstmt: FUN IDENT LATI expr SI expr ifikun loopatch forpatch $@1 SE stmtlist PARI  */
#line 250 "ekparser.y"
                          {
       CODEGEN2(jmp, (void *) (yyvsp[-5].ptr));
       vm.instructions.data[(yyvsp[-5].ptr)+1] = 
           (void *) code_get_count(&vm.instructions);
       (yyval.ptr) = (yyvsp[-9].ptr);
}
#line 1757 "y.tab.c"
    break;

  case 46: /* ifikun: %empty  */
#line 257 "ekparser.y"
                      { 
      void * data = write_constant(CREATE_NUM(1));
      (yyval.ptr) = CODEGEN2(constpush, data);
      }
#line 1766 "y.tab.c"
    break;

  case 47: /* ifikun: IFIKUN expr  */
#line 261 "ekparser.y"
                     {(yyval.ptr) = (yyvsp[0].ptr);
      }
#line 1773 "y.tab.c"
    break;

  case 48: /* funcstmt: ISE IDENT LPAR arglist RPAR stmt PARI  */
#line 265 "ekparser.y"
                                               {
        DEBUG_PRINT("funcstmt: ISE IDENT LPAR \
            arglist RPAR stmt PARI");
        }
#line 1782 "y.tab.c"
    break;

  case 50: /* loopatch: %empty  */
#line 275 "ekparser.y"
            {
          (yyval.ptr) = code_get_count(&vm.instructions);
          }
#line 1790 "y.tab.c"
    break;

  case 51: /* loopatch2: %empty  */
#line 280 "ekparser.y"
            {
          (yyval.ptr) = CODEGEN2(jz, NULL);
          CODEGEN(pop);
          }
#line 1799 "y.tab.c"
    break;

  case 52: /* ifpatch: %empty  */
#line 286 "ekparser.y"
           {
         DEBUG_PRINT("in if patch");
         (yyval.ptr) =CODEGEN2(jz, NULL); 
         CODEGEN(pop);}
#line 1808 "y.tab.c"
    break;

  case 53: /* orpatch: %empty  */
#line 292 "ekparser.y"
           {
         (yyval.ptr) = CODEGEN3(orjmp, NULL, NULL);
         }
#line 1816 "y.tab.c"
    break;

  case 54: /* andpatch: %empty  */
#line 297 "ekparser.y"
           {
         (yyval.ptr) = CODEGEN3(andjmp, NULL, NULL);
          }
#line 1824 "y.tab.c"
    break;

  case 55: /* forpatch: %empty  */
#line 302 "ekparser.y"
          {
        (yyval.ptr) =CODEGEN2(forloop, NULL);
        }
#line 1832 "y.tab.c"
    break;

  case 56: /* elsepatch: %empty  */
#line 307 "ekparser.y"
           {
         DEBUG_PRINT("in elsepatch");
         (yyval.ptr) = CODEGEN2(jmp, NULL); 
         CODEGEN(pop);}
#line 1841 "y.tab.c"
    break;


#line 1845 "y.tab.c"

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

#line 317 "ekparser.y"


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
