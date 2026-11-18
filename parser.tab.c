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
#line 1 "parser.y"

#include <stdio.h>

int yylex(void);
void yyerror(const char *msg);
void report_syntax_error(const char *msg);

FILE *prodf;
int nprod;

static void prod(const char *text) {
    nprod++;
    fprintf(prodf, "%d. %s\n", nprod, text);
}

#line 87 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FRIEND = 3,                     /* FRIEND  */
  YYSYMBOL_TREATS = 4,                     /* TREATS  */
  YYSYMBOL_ADOPT = 5,                      /* ADOPT  */
  YYSYMBOL_PAW = 6,                        /* PAW  */
  YYSYMBOL_CUDDLE = 7,                     /* CUDDLE  */
  YYSYMBOL_SCRATCH = 8,                    /* SCRATCH  */
  YYSYMBOL_PURR = 9,                       /* PURR  */
  YYSYMBOL_BABY = 10,                      /* BABY  */
  YYSYMBOL_ZOOMIES = 11,                   /* ZOOMIES  */
  YYSYMBOL_MEOW = 12,                      /* MEOW  */
  YYSYMBOL_SNIFF = 13,                     /* SNIFF  */
  YYSYMBOL_HISS = 14,                      /* HISS  */
  YYSYMBOL_BISCUITS = 15,                  /* BISCUITS  */
  YYSYMBOL_MADE = 16,                      /* MADE  */
  YYSYMBOL_UP = 17,                        /* UP  */
  YYSYMBOL_DOWN = 18,                      /* DOWN  */
  YYSYMBOL_CHUNKY = 19,                    /* CHUNKY  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_TIMES = 25,                     /* TIMES  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 35,                     /* ARROW  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 38,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 39,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 41,                    /* RBRACE  */
  YYSYMBOL_SEMI = 42,                      /* SEMI  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_ID = 44,                        /* ID  */
  YYSYMBOL_NUMBER = 45,                    /* NUMBER  */
  YYSYMBOL_STRING = 46,                    /* STRING  */
  YYSYMBOL_UNKNOWN = 47,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_stmt_list = 50,                 /* stmt_list  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_list_decl = 52,                 /* list_decl  */
  YYSYMBOL_num_decl = 53,                  /* num_decl  */
  YYSYMBOL_assign = 54,                    /* assign  */
  YYSYMBOL_input_stmt = 55,                /* input_stmt  */
  YYSYMBOL_add_stmt = 56,                  /* add_stmt  */
  YYSYMBOL_map_stmt = 57,                  /* map_stmt  */
  YYSYMBOL_filter_stmt = 58,               /* filter_stmt  */
  YYSYMBOL_sort_stmt = 59,                 /* sort_stmt  */
  YYSYMBOL_unique_stmt = 60,               /* unique_stmt  */
  YYSYMBOL_join_stmt = 61,                 /* join_stmt  */
  YYSYMBOL_output_stmt = 62,               /* output_stmt  */
  YYSYMBOL_out_list = 63,                  /* out_list  */
  YYSYMBOL_out_item = 64,                  /* out_item  */
  YYSYMBOL_if_stmt = 65,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 66,                  /* for_stmt  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_order = 68,                     /* order  */
  YYSYMBOL_list_literal = 69,              /* list_literal  */
  YYSYMBOL_arith_list = 70,                /* arith_list  */
  YYSYMBOL_cond = 71,                      /* cond  */
  YYSYMBOL_and_cond = 72,                  /* and_cond  */
  YYSYMBOL_not_cond = 73,                  /* not_cond  */
  YYSYMBOL_comparison = 74,                /* comparison  */
  YYSYMBOL_comp_op = 75,                   /* comp_op  */
  YYSYMBOL_arith = 76,                     /* arith  */
  YYSYMBOL_term = 77,                      /* term  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_ref = 79                        /* ref  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    32,    33,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    51,    54,
      55,    58,    61,    64,    67,    70,    73,    76,    79,    82,
      85,    86,    89,    90,    93,    94,    97,   100,   103,   104,
     107,   108,   111,   112,   115,   116,   119,   120,   123,   124,
     127,   130,   131,   132,   133,   134,   135,   138,   139,   140,
     143,   144,   145,   146,   149,   150,   151,   152,   155,   156
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FRIEND", "TREATS",
  "ADOPT", "PAW", "CUDDLE", "SCRATCH", "PURR", "BABY", "ZOOMIES", "MEOW",
  "SNIFF", "HISS", "BISCUITS", "MADE", "UP", "DOWN", "CHUNKY", "AND", "OR",
  "NOT", "PLUS", "MINUS", "TIMES", "DIV", "MOD", "EQ", "NE", "LT", "LE",
  "GT", "GE", "ASSIGN", "ARROW", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "SEMI", "COMMA", "ID", "NUMBER",
  "STRING", "UNKNOWN", "$accept", "program", "stmt_list", "statement",
  "list_decl", "num_decl", "assign", "input_stmt", "add_stmt", "map_stmt",
  "filter_stmt", "sort_stmt", "unique_stmt", "join_stmt", "output_stmt",
  "out_list", "out_item", "if_stmt", "for_stmt", "block", "order",
  "list_literal", "arith_list", "cond", "and_cond", "not_cond",
  "comparison", "comp_op", "arith", "term", "factor", "ref", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      29,   -22,     5,     9,    21,    23,    25,    30,    42,    46,
     -16,    26,    62,    76,    84,    29,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
      97,    98,   -15,    75,    32,    74,    86,    39,    91,    88,
      99,    32,   -93,   -93,    18,   -93,    81,    83,   -93,   -93,
      26,    38,   116,   -93,   -93,    96,   121,    32,   -93,   -93,
      32,   100,    32,   -93,   -93,    40,   104,   105,   -93,   -93,
     101,   -93,   102,   103,    79,   -93,   -16,    32,    32,    32,
      32,    32,   -93,    26,    29,   127,    26,   -93,   -93,   -93,
     -93,   -93,   -93,    32,   106,    73,    65,    36,   107,    69,
     -93,    32,    26,   -93,   -93,   108,   -93,   -93,    83,    83,
     -93,   -93,   -93,   116,     2,   111,   -93,    81,   111,   -93,
     -93,   -93,   -18,    81,   -93,   -93,    71,    37,   -93,   -93,
     -93,   -93,   -93,    32,   -93,   -93,    81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     2,     3,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    32,     0,    30,    33,    57,    60,    65,
       0,     0,    44,    46,    49,     0,     0,     0,     1,     4,
       0,     0,     0,    19,    22,     0,     0,     0,    38,    39,
       0,    27,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    34,     0,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,    26,    28,     0,    67,    31,    58,    59,
      61,    62,    63,    45,     0,     0,    47,    50,     0,    69,
      21,    40,     0,    42,    18,    20,     0,     0,    66,    37,
      35,    36,    41,     0,    24,    25,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,    58,   -13,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,    70,   -93,   -93,   -92,
     -93,   -93,   -93,    50,    72,   -32,   -93,   -93,   -10,    44,
      19,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    44,    45,    28,    29,    85,
      70,    98,   122,    51,    52,    53,    54,    93,    55,    47,
      48,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    30,    59,    40,    33,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    30,    12,    82,    62,
      41,   132,    31,   130,    65,   133,   131,    63,    13,    42,
      43,    74,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   129,    12,    40,    13,    95,    50,    32,
      96,    40,    99,    13,   116,    40,    68,    69,    83,    83,
      75,    76,    41,    77,    78,    34,    46,    35,    41,    36,
      13,    42,    41,    13,    37,   121,    13,    42,    84,   135,
      13,    42,   100,   117,    58,    30,    38,   123,    77,    78,
      39,   126,    77,    78,    77,    78,    77,    78,   110,   111,
     112,    59,    77,    78,    77,    78,    56,   120,    79,    80,
      81,   125,   119,   134,    57,    30,   106,    64,    66,    77,
      78,   108,   109,   136,    87,    88,    89,    90,    91,    92,
      67,    60,    61,    71,    72,    73,    86,    94,    97,   101,
     102,   115,   114,   103,   104,   128,   107,   105,     0,   124,
     118,    84,   127,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
      10,     0,    15,    19,     3,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    15,    15,    50,    34,
      36,    39,    44,   115,    34,    43,   118,    42,    44,    45,
      46,    41,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    41,    15,    19,    44,    57,    22,    44,
      60,    19,    62,    44,    86,    19,    17,    18,    21,    21,
      42,    43,    36,    23,    24,    44,    76,    44,    36,    44,
      44,    45,    36,    44,    44,    39,    44,    45,    40,    42,
      44,    45,    42,    93,     0,    84,    44,    97,    23,    24,
      44,   101,    23,    24,    23,    24,    23,    24,    79,    80,
      81,   114,    23,    24,    23,    24,    44,    42,    25,    26,
      27,    42,    39,    42,    38,   114,    37,    42,    44,    23,
      24,    77,    78,   133,    28,    29,    30,    31,    32,    33,
      44,    34,    34,    42,    46,    36,    20,    16,    38,    35,
      35,    14,    84,    42,    42,    37,    76,    44,    -1,    42,
      44,    40,   102,    -1,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    15,    44,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    65,    66,
      79,    44,    44,    79,    44,    44,    44,    44,    44,    44,
      19,    36,    45,    46,    63,    64,    76,    77,    78,    79,
      22,    71,    72,    73,    74,    76,    44,    38,     0,    51,
      34,    34,    34,    42,    42,    76,    44,    44,    17,    18,
      68,    42,    46,    36,    76,    42,    43,    23,    24,    25,
      26,    27,    73,    21,    40,    67,    20,    28,    29,    30,
      31,    32,    33,    75,    16,    76,    76,    38,    69,    76,
      42,    35,    35,    42,    42,    44,    37,    64,    77,    77,
      78,    78,    78,    72,    50,    14,    73,    76,    44,    39,
      42,    39,    70,    76,    42,    42,    76,    71,    37,    41,
      67,    67,    39,    43,    42,    42,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       5,     4,     3,     4,     6,     6,     4,     3,     4,     3,
       1,     3,     1,     1,     3,     5,     5,     3,     1,     1,
       2,     3,     1,     3,     1,     3,     1,     3,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     4,     3,     1,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: stmt_list  */
#line 29 "parser.y"
                                                  { prod("program -> stmt_list"); }
#line 1517 "parser.tab.c"
    break;

  case 3: /* stmt_list: statement  */
#line 32 "parser.y"
                                                  { prod("stmt_list -> statement"); }
#line 1523 "parser.tab.c"
    break;

  case 4: /* stmt_list: stmt_list statement  */
#line 33 "parser.y"
                                                  { prod("stmt_list -> stmt_list statement"); }
#line 1529 "parser.tab.c"
    break;

  case 5: /* statement: list_decl  */
#line 36 "parser.y"
                                                  { prod("statement -> list_decl"); }
#line 1535 "parser.tab.c"
    break;

  case 6: /* statement: num_decl  */
#line 37 "parser.y"
                                                  { prod("statement -> num_decl"); }
#line 1541 "parser.tab.c"
    break;

  case 7: /* statement: assign  */
#line 38 "parser.y"
                                                  { prod("statement -> assign"); }
#line 1547 "parser.tab.c"
    break;

  case 8: /* statement: input_stmt  */
#line 39 "parser.y"
                                                  { prod("statement -> input_stmt"); }
#line 1553 "parser.tab.c"
    break;

  case 9: /* statement: add_stmt  */
#line 40 "parser.y"
                                                  { prod("statement -> add_stmt"); }
#line 1559 "parser.tab.c"
    break;

  case 10: /* statement: map_stmt  */
#line 41 "parser.y"
                                                  { prod("statement -> map_stmt"); }
#line 1565 "parser.tab.c"
    break;

  case 11: /* statement: filter_stmt  */
#line 42 "parser.y"
                                                  { prod("statement -> filter_stmt"); }
#line 1571 "parser.tab.c"
    break;

  case 12: /* statement: sort_stmt  */
#line 43 "parser.y"
                                                  { prod("statement -> sort_stmt"); }
#line 1577 "parser.tab.c"
    break;

  case 13: /* statement: unique_stmt  */
#line 44 "parser.y"
                                                  { prod("statement -> unique_stmt"); }
#line 1583 "parser.tab.c"
    break;

  case 14: /* statement: join_stmt  */
#line 45 "parser.y"
                                                  { prod("statement -> join_stmt"); }
#line 1589 "parser.tab.c"
    break;

  case 15: /* statement: output_stmt  */
#line 46 "parser.y"
                                                  { prod("statement -> output_stmt"); }
#line 1595 "parser.tab.c"
    break;

  case 16: /* statement: if_stmt  */
#line 47 "parser.y"
                                                  { prod("statement -> if_stmt"); }
#line 1601 "parser.tab.c"
    break;

  case 17: /* statement: for_stmt  */
#line 48 "parser.y"
                                                  { prod("statement -> for_stmt"); }
#line 1607 "parser.tab.c"
    break;

  case 18: /* list_decl: FRIEND ID ASSIGN list_literal SEMI  */
#line 51 "parser.y"
                                                  { prod("list_decl -> friend ID = list_literal ;"); }
#line 1613 "parser.tab.c"
    break;

  case 19: /* num_decl: TREATS ID SEMI  */
#line 54 "parser.y"
                                                  { prod("num_decl -> treats ID ;"); }
#line 1619 "parser.tab.c"
    break;

  case 20: /* num_decl: TREATS ID ASSIGN arith SEMI  */
#line 55 "parser.y"
                                                  { prod("num_decl -> treats ID = arith ;"); }
#line 1625 "parser.tab.c"
    break;

  case 21: /* assign: ref ASSIGN arith SEMI  */
#line 58 "parser.y"
                                                  { prod("assign -> ref = arith ;"); }
#line 1631 "parser.tab.c"
    break;

  case 22: /* input_stmt: ADOPT ref SEMI  */
#line 61 "parser.y"
                                                  { prod("input_stmt -> adopt ref ;"); }
#line 1637 "parser.tab.c"
    break;

  case 23: /* add_stmt: PAW ID arith SEMI  */
#line 64 "parser.y"
                                                  { prod("add_stmt -> paw ID arith ;"); }
#line 1643 "parser.tab.c"
    break;

  case 24: /* map_stmt: CUDDLE ID ID ARROW arith SEMI  */
#line 67 "parser.y"
                                                  { prod("map_stmt -> cuddle ID ID => arith ;"); }
#line 1649 "parser.tab.c"
    break;

  case 25: /* filter_stmt: SCRATCH ID ID ARROW cond SEMI  */
#line 70 "parser.y"
                                                  { prod("filter_stmt -> scratch ID ID => cond ;"); }
#line 1655 "parser.tab.c"
    break;

  case 26: /* sort_stmt: PURR ID order SEMI  */
#line 73 "parser.y"
                                                  { prod("sort_stmt -> purr ID order ;"); }
#line 1661 "parser.tab.c"
    break;

  case 27: /* unique_stmt: BABY ID SEMI  */
#line 76 "parser.y"
                                                  { prod("unique_stmt -> baby ID ;"); }
#line 1667 "parser.tab.c"
    break;

  case 28: /* join_stmt: ZOOMIES ID STRING SEMI  */
#line 79 "parser.y"
                                                  { prod("join_stmt -> zoomies ID STRING ;"); }
#line 1673 "parser.tab.c"
    break;

  case 29: /* output_stmt: MEOW out_list SEMI  */
#line 82 "parser.y"
                                                  { prod("output_stmt -> meow out_list ;"); }
#line 1679 "parser.tab.c"
    break;

  case 30: /* out_list: out_item  */
#line 85 "parser.y"
                                                  { prod("out_list -> out_item"); }
#line 1685 "parser.tab.c"
    break;

  case 31: /* out_list: out_list COMMA out_item  */
#line 86 "parser.y"
                                                  { prod("out_list -> out_list , out_item"); }
#line 1691 "parser.tab.c"
    break;

  case 32: /* out_item: STRING  */
#line 89 "parser.y"
                                                  { prod("out_item -> STRING"); }
#line 1697 "parser.tab.c"
    break;

  case 33: /* out_item: arith  */
#line 90 "parser.y"
                                                  { prod("out_item -> arith"); }
#line 1703 "parser.tab.c"
    break;

  case 34: /* if_stmt: SNIFF cond block  */
#line 93 "parser.y"
                                                  { prod("if_stmt -> sniff cond block"); }
#line 1709 "parser.tab.c"
    break;

  case 35: /* if_stmt: SNIFF cond block HISS block  */
#line 94 "parser.y"
                                                  { prod("if_stmt -> sniff cond block hiss block"); }
#line 1715 "parser.tab.c"
    break;

  case 36: /* for_stmt: BISCUITS ID MADE ID block  */
#line 97 "parser.y"
                                                  { prod("for_stmt -> biscuits ID made ID block"); }
#line 1721 "parser.tab.c"
    break;

  case 37: /* block: LBRACE stmt_list RBRACE  */
#line 100 "parser.y"
                                                  { prod("block -> { stmt_list }"); }
#line 1727 "parser.tab.c"
    break;

  case 38: /* order: UP  */
#line 103 "parser.y"
                                                  { prod("order -> up"); }
#line 1733 "parser.tab.c"
    break;

  case 39: /* order: DOWN  */
#line 104 "parser.y"
                                                  { prod("order -> down"); }
#line 1739 "parser.tab.c"
    break;

  case 40: /* list_literal: LBRACKET RBRACKET  */
#line 107 "parser.y"
                                                  { prod("list_literal -> [ ]"); }
#line 1745 "parser.tab.c"
    break;

  case 41: /* list_literal: LBRACKET arith_list RBRACKET  */
#line 108 "parser.y"
                                                  { prod("list_literal -> [ arith_list ]"); }
#line 1751 "parser.tab.c"
    break;

  case 42: /* arith_list: arith  */
#line 111 "parser.y"
                                                  { prod("arith_list -> arith"); }
#line 1757 "parser.tab.c"
    break;

  case 43: /* arith_list: arith_list COMMA arith  */
#line 112 "parser.y"
                                                  { prod("arith_list -> arith_list , arith"); }
#line 1763 "parser.tab.c"
    break;

  case 44: /* cond: and_cond  */
#line 115 "parser.y"
                                                  { prod("cond -> and_cond"); }
#line 1769 "parser.tab.c"
    break;

  case 45: /* cond: cond OR and_cond  */
#line 116 "parser.y"
                                                  { prod("cond -> cond or and_cond"); }
#line 1775 "parser.tab.c"
    break;

  case 46: /* and_cond: not_cond  */
#line 119 "parser.y"
                                                  { prod("and_cond -> not_cond"); }
#line 1781 "parser.tab.c"
    break;

  case 47: /* and_cond: and_cond AND not_cond  */
#line 120 "parser.y"
                                                  { prod("and_cond -> and_cond and not_cond"); }
#line 1787 "parser.tab.c"
    break;

  case 48: /* not_cond: NOT not_cond  */
#line 123 "parser.y"
                                                  { prod("not_cond -> not not_cond"); }
#line 1793 "parser.tab.c"
    break;

  case 49: /* not_cond: comparison  */
#line 124 "parser.y"
                                                  { prod("not_cond -> comparison"); }
#line 1799 "parser.tab.c"
    break;

  case 50: /* comparison: arith comp_op arith  */
#line 127 "parser.y"
                                                  { prod("comparison -> arith comp_op arith"); }
#line 1805 "parser.tab.c"
    break;

  case 51: /* comp_op: EQ  */
#line 130 "parser.y"
                                                  { prod("comp_op -> =="); }
#line 1811 "parser.tab.c"
    break;

  case 52: /* comp_op: NE  */
#line 131 "parser.y"
                                                  { prod("comp_op -> !="); }
#line 1817 "parser.tab.c"
    break;

  case 53: /* comp_op: LT  */
#line 132 "parser.y"
                                                  { prod("comp_op -> <"); }
#line 1823 "parser.tab.c"
    break;

  case 54: /* comp_op: LE  */
#line 133 "parser.y"
                                                  { prod("comp_op -> <="); }
#line 1829 "parser.tab.c"
    break;

  case 55: /* comp_op: GT  */
#line 134 "parser.y"
                                                  { prod("comp_op -> >"); }
#line 1835 "parser.tab.c"
    break;

  case 56: /* comp_op: GE  */
#line 135 "parser.y"
                                                  { prod("comp_op -> >="); }
#line 1841 "parser.tab.c"
    break;

  case 57: /* arith: term  */
#line 138 "parser.y"
                                                  { prod("arith -> term"); }
#line 1847 "parser.tab.c"
    break;

  case 58: /* arith: arith PLUS term  */
#line 139 "parser.y"
                                                  { prod("arith -> arith + term"); }
#line 1853 "parser.tab.c"
    break;

  case 59: /* arith: arith MINUS term  */
#line 140 "parser.y"
                                                  { prod("arith -> arith - term"); }
#line 1859 "parser.tab.c"
    break;

  case 60: /* term: factor  */
#line 143 "parser.y"
                                                  { prod("term -> factor"); }
#line 1865 "parser.tab.c"
    break;

  case 61: /* term: term TIMES factor  */
#line 144 "parser.y"
                                                  { prod("term -> term * factor"); }
#line 1871 "parser.tab.c"
    break;

  case 62: /* term: term DIV factor  */
#line 145 "parser.y"
                                                  { prod("term -> term / factor"); }
#line 1877 "parser.tab.c"
    break;

  case 63: /* term: term MOD factor  */
#line 146 "parser.y"
                                                  { prod("term -> term % factor"); }
#line 1883 "parser.tab.c"
    break;

  case 64: /* factor: NUMBER  */
#line 149 "parser.y"
                                                  { prod("factor -> NUMBER"); }
#line 1889 "parser.tab.c"
    break;

  case 65: /* factor: ref  */
#line 150 "parser.y"
                                                  { prod("factor -> ref"); }
#line 1895 "parser.tab.c"
    break;

  case 66: /* factor: CHUNKY LPAREN ID RPAREN  */
#line 151 "parser.y"
                                                  { prod("factor -> chunky ( ID )"); }
#line 1901 "parser.tab.c"
    break;

  case 67: /* factor: LPAREN arith RPAREN  */
#line 152 "parser.y"
                                                  { prod("factor -> ( arith )"); }
#line 1907 "parser.tab.c"
    break;

  case 68: /* ref: ID  */
#line 155 "parser.y"
                                                  { prod("ref -> ID"); }
#line 1913 "parser.tab.c"
    break;

  case 69: /* ref: ID LBRACKET arith RBRACKET  */
#line 156 "parser.y"
                                                  { prod("ref -> ID [ arith ]"); }
#line 1919 "parser.tab.c"
    break;


#line 1923 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 159 "parser.y"


void yyerror(const char *msg) {
    report_syntax_error(msg);
}
