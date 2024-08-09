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
#include <stdlib.h>
#include "ast.h"
#include "symtab.h"

extern FILE *yyin;
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int yylex(void);

#line 85 "parser.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CADENA = 4,                     /* CADENA  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_ALFABETO = 7,                   /* ALFABETO  */
  YYSYMBOL_A = 8,                          /* A  */
  YYSYMBOL_B = 9,                          /* B  */
  YYSYMBOL_N = 10,                         /* N  */
  YYSYMBOL_M = 11,                         /* M  */
  YYSYMBOL_MATRIZ = 12,                    /* MATRIZ  */
  YYSYMBOL_TAU = 13,                       /* TAU  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_TYPE_INT = 15,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 16,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_CADENA = 17,               /* TYPE_CADENA  */
  YYSYMBOL_TYPE_MODELO = 18,               /* TYPE_MODELO  */
  YYSYMBOL_TYPE_CAD_MULT = 19,             /* TYPE_CAD_MULT  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_LB = 24,                        /* LB  */
  YYSYMBOL_RB = 25,                        /* RB  */
  YYSYMBOL_LP = 26,                        /* LP  */
  YYSYMBOL_RP = 27,                        /* RP  */
  YYSYMBOL_LS = 28,                        /* LS  */
  YYSYMBOL_RS = 29,                        /* RS  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_MUL = 38,                       /* MUL  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_MOD = 40,                       /* MOD  */
  YYSYMBOL_SIZE = 41,                      /* SIZE  */
  YYSYMBOL_CAT = 42,                       /* CAT  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_PRINT = 45,                     /* PRINT  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_stmt = 49,                      /* stmt  */
  YYSYMBOL_expr = 50,                      /* expr  */
  YYSYMBOL_condicion = 51,                 /* condicion  */
  YYSYMBOL_array = 52,                     /* array  */
  YYSYMBOL_reassign = 53,                  /* reassign  */
  YYSYMBOL_declaracion = 54,               /* declaracion  */
  YYSYMBOL_print = 55                      /* print  */
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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

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
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    60,    61,    65,    66,    67,    68,    69,
      70,    71,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    99,   100,   101,   102,   103,   104,   105,
     109,   150,   175,   176,   180,   181,   182,   183,   184,   185,
     187,   188,   191,   195
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "CADENA",
  "INT", "FLOAT", "ALFABETO", "A", "B", "N", "M", "MATRIZ", "TAU",
  "ASSIGN", "TYPE_INT", "TYPE_FLOAT", "TYPE_CADENA", "TYPE_MODELO",
  "TYPE_CAD_MULT", "WHILE", "IF", "ELSE", "THEN", "LB", "RB", "LP", "RP",
  "LS", "RS", "EQ", "NE", "LE", "GE", "LT", "GT", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "SIZE", "CAT", "COMMA", "SEMICOLON", "PRINT", "$accept",
  "program", "block", "stmt", "expr", "condicion", "array", "reassign",
  "declaracion", "print", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    -5,   -16,   -16,   -16,    12,     7,    11,    25,    33,
      35,    28,    28,    89,    89,   -15,    48,   -16,     1,   124,
       6,    16,    17,    89,    89,    38,    54,    56,    21,    57,
      58,    59,   -16,   -16,    28,   327,    51,    52,   362,   490,
       8,    89,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
      89,    89,    89,    89,    89,    89,   -16,   -16,   -16,   -16,
     -16,   -16,   490,   490,    89,    63,    89,    66,    78,    89,
      60,    62,   292,    55,    89,    89,    89,    89,    89,    89,
      89,     1,     1,   -16,   -16,    89,   369,   404,   490,   490,
      90,    90,    90,   490,    89,   490,    89,    73,   490,    89,
      89,   -16,   426,   490,   490,   490,   490,   490,   490,    37,
      65,   490,   -16,    77,   490,   490,    89,   145,   166,   -16,
     -16,    75,    89,   490,    89,    89,    80,   490,   187,   208,
       1,    89,    89,    81,   229,   448,   -16,    89,   -16,   250,
      89,   271,    89,   469,   -16
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    13,    12,    15,    14,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    16,     0,     0,     0,     0,     0,    41,
       0,     0,     1,     3,    30,    31,    28,    29,    27,    32,
       0,     0,     0,     0,     0,     0,    25,    26,     8,    10,
       9,    11,    42,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     4,    17,    18,     0,     0,     0,    20,    21,
      22,    23,    24,    44,     0,    45,     0,     0,    46,     0,
       0,    33,     0,    34,    35,    36,    37,    38,    39,     0,
       0,    40,    53,    19,    47,    48,     0,     0,     0,    19,
       5,     6,     0,    50,     0,     0,     0,    43,     0,     0,
       4,     0,     0,     0,     0,     0,     7,     0,    49,     0,
       0,     0,     0,     0,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,    -3,   -16,   -11,    13,   -16,   -16,   -16,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    36,    40,    20,    21,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    35,    38,    39,     1,     2,     3,     4,     5,    23,
      25,    41,    62,    63,    27,    43,     6,     7,     8,     9,
      10,    11,    12,    72,    67,    37,    24,    13,    29,    14,
      86,    32,     2,     3,     4,    33,    30,    84,    31,    87,
      88,    89,    90,    91,    92,    26,    15,    73,    42,    28,
      59,    85,    64,    93,    34,    95,    14,    65,    98,    68,
      60,    61,   120,   102,   103,   104,   105,   106,   107,   108,
      66,    69,    70,    71,   111,    81,    82,    94,   109,   110,
      96,    97,   101,   114,    99,   115,   100,   116,   117,   118,
     121,   122,    32,     2,     3,     4,    33,   126,    44,    45,
      46,    47,    48,    49,   130,   123,   136,     0,     0,     0,
       0,   127,     0,   128,   129,    13,     0,    14,    74,     0,
     134,   135,     0,     0,     0,     0,   139,   133,     0,   141,
       0,   143,    44,    45,    46,    47,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    44,    45,    46,    47,    48,    49,     0,
      51,    52,    53,    54,    55,    56,    57,     0,    58,     0,
       0,     0,     0,    74,    44,    45,    46,    47,    48,    49,
       0,    51,    52,    53,    54,    55,    56,    57,   124,     0,
       0,     0,     0,     0,    74,    44,    45,    46,    47,    48,
      49,     0,    51,    52,    53,    54,    55,    56,    57,   125,
       0,     0,     0,     0,     0,    74,    44,    45,    46,    47,
      48,    49,     0,    51,    52,    53,    54,    55,    56,    57,
     131,     0,     0,     0,     0,     0,    74,    44,    45,    46,
      47,    48,    49,     0,    51,    52,    53,    54,    55,    56,
      57,   132,     0,     0,     0,     0,     0,    74,    44,    45,
      46,    47,    48,    49,     0,    51,    52,    53,    54,    55,
      56,    57,   137,     0,     0,     0,     0,     0,    74,    44,
      45,    46,    47,    48,    49,     0,    51,    52,    53,    54,
      55,    56,    57,   140,     0,     0,     0,     0,     0,    74,
      44,    45,    46,    47,    48,    49,     0,    51,    52,    53,
      54,    55,    56,    57,   142,     0,     0,     0,     0,    83,
      74,     0,    75,    76,    77,    78,    79,    80,    51,    52,
      53,    54,    55,    56,    57,    44,    45,    46,    47,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,    51,    52,    53,    54,    55,    56,    57,
      44,    45,    46,    47,    48,    49,     0,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,     0,    83,
      74,     0,     0,     0,     0,     0,   112,    74,    51,    52,
      53,    54,    55,    56,    57,    51,    52,    53,    54,    55,
      56,    57,    44,    45,    46,    47,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,   113,    44,    45,    46,    47,    48,    49,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,    74,   119,    44,    45,    46,    47,
      48,    49,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,   138,     0,     0,    74,    44,    45,    46,
      47,    48,    49,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,   144,     0,     0,    74,    44,    45,
      46,    47,    48,    49,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57
};

static const yytype_int16 yycheck[] =
{
      11,    12,    13,    14,     3,     4,     5,     6,     7,    14,
       3,    26,    23,    24,     3,    18,    15,    16,    17,    18,
      19,    20,    21,    34,     3,    12,    14,    26,     3,    28,
      41,     3,     4,     5,     6,     7,     3,    29,     3,    50,
      51,    52,    53,    54,    55,    38,    45,    34,     0,    38,
      44,    43,    14,    64,    26,    66,    28,     3,    69,    38,
      44,    44,    25,    74,    75,    76,    77,    78,    79,    80,
      14,    14,    14,    14,    85,    24,    24,    14,    81,    82,
      14,     3,    27,    94,    24,    96,    24,    14,    99,   100,
      25,    14,     3,     4,     5,     6,     7,    22,     8,     9,
      10,    11,    12,    13,    24,   116,    25,    -1,    -1,    -1,
      -1,   122,    -1,   124,   125,    26,    -1,    28,    28,    -1,
     131,   132,    -1,    -1,    -1,    -1,   137,   130,    -1,   140,
      -1,   142,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,     8,     9,    10,    11,    12,    13,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    -1,
      -1,    -1,    -1,    28,     8,     9,    10,    11,    12,    13,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    28,     8,     9,    10,    11,    12,
      13,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    28,     8,     9,    10,    11,
      12,    13,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    28,     8,     9,    10,
      11,    12,    13,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    28,     8,     9,
      10,    11,    12,    13,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    28,     8,
       9,    10,    11,    12,    13,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    28,
       8,     9,    10,    11,    12,    13,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       8,     9,    10,    11,    12,    13,    -1,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    27,    28,    36,    37,
      38,    39,    40,    41,    42,    36,    37,    38,    39,    40,
      41,    42,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,     8,     9,    10,    11,    12,    13,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,     8,     9,    10,    11,
      12,    13,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    28,     8,     9,    10,
      11,    12,    13,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    25,    -1,    -1,    28,     8,     9,
      10,    11,    12,    13,    -1,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    15,    16,    17,    18,
      19,    20,    21,    26,    28,    45,    47,    48,    49,    50,
      53,    54,    55,    14,    14,     3,    38,     3,    38,     3,
       3,     3,     3,     7,    26,    50,    51,    51,    50,    50,
      52,    26,     0,    48,     8,     9,    10,    11,    12,    13,
      28,    36,    37,    38,    39,    40,    41,    42,    44,    44,
      44,    44,    50,    50,    14,     3,    14,     3,    38,    14,
      14,    14,    50,    51,    28,    30,    31,    32,    33,    34,
      35,    24,    24,    27,    29,    43,    50,    50,    50,    50,
      50,    50,    50,    50,    14,    50,    14,     3,    50,    24,
      24,    27,    50,    50,    50,    50,    50,    50,    50,    48,
      48,    50,    27,    29,    50,    50,    14,    50,    50,    29,
      25,    25,    14,    50,    43,    43,    22,    50,    50,    50,
      24,    43,    43,    48,    50,    50,    25,    43,    25,    50,
      43,    50,    43,    50,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     5,     9,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     4,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     6,     4,     4,     4,     5,     5,    10,
       6,    16,     3,     4
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
  case 2: /* program: block  */
#line 51 "parser.y"
          { 
        printf("ARBOL:\n");
        printAST((yyvsp[0].ast), 0); 
        printf("RESULTADOS:\n");
        executeAST((yyvsp[0].ast));
    }
#line 1292 "parser.tab.c"
    break;

  case 3: /* block: stmt block  */
#line 60 "parser.y"
               { (yyval.ast) = createNode(_BLOCK, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1298 "parser.tab.c"
    break;

  case 4: /* block: %empty  */
#line 61 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1304 "parser.tab.c"
    break;

  case 5: /* stmt: WHILE condicion LB block RB  */
#line 65 "parser.y"
                                { (yyval.ast) = createNode(_WHILE, (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1310 "parser.tab.c"
    break;

  case 6: /* stmt: IF condicion LB block RB  */
#line 66 "parser.y"
                               { (yyval.ast) = createNode(_IF, (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1316 "parser.tab.c"
    break;

  case 7: /* stmt: IF condicion LB block RB ELSE LB block RB  */
#line 67 "parser.y"
                                                { (yyval.ast) = createNode(_ELSE, createNode(_IF, (yyvsp[-7].ast), (yyvsp[-5].ast)), (yyvsp[-1].ast)); }
#line 1322 "parser.tab.c"
    break;

  case 12: /* expr: CADENA  */
#line 75 "parser.y"
           { (yyval.ast) = createStringNode((yyvsp[0].sval)); }
#line 1328 "parser.tab.c"
    break;

  case 13: /* expr: IDENTIFIER  */
#line 76 "parser.y"
                 { (yyval.ast) = createIdentifierNode((yyvsp[0].sval)); }
#line 1334 "parser.tab.c"
    break;

  case 14: /* expr: FLOAT  */
#line 77 "parser.y"
            { (yyval.ast) = createFloatNode((yyvsp[0].fval)); }
#line 1340 "parser.tab.c"
    break;

  case 15: /* expr: INT  */
#line 78 "parser.y"
          { (yyval.ast) = createIntNode((yyvsp[0].ival)); }
#line 1346 "parser.tab.c"
    break;

  case 16: /* expr: ALFABETO  */
#line 79 "parser.y"
               { (yyval.ast) = createIdentifierNode((yyvsp[0].cval)); }
#line 1352 "parser.tab.c"
    break;

  case 17: /* expr: LP expr RP  */
#line 80 "parser.y"
                 { (yyval.ast) = (yyvsp[-1].ast); }
#line 1358 "parser.tab.c"
    break;

  case 18: /* expr: LS array RS  */
#line 81 "parser.y"
                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 1364 "parser.tab.c"
    break;

  case 19: /* expr: expr LS expr RS  */
#line 82 "parser.y"
                      { (yyval.ast) = createNode(_SVARR, (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1370 "parser.tab.c"
    break;

  case 20: /* expr: expr PLUS expr  */
#line 83 "parser.y"
                     { (yyval.ast) = createNode(_PLUS, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1376 "parser.tab.c"
    break;

  case 21: /* expr: expr MINUS expr  */
#line 84 "parser.y"
                      { (yyval.ast) = createNode(_MINUS, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1382 "parser.tab.c"
    break;

  case 22: /* expr: expr MUL expr  */
#line 85 "parser.y"
                    { (yyval.ast) = createNode(_MUL, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1388 "parser.tab.c"
    break;

  case 23: /* expr: expr DIV expr  */
#line 86 "parser.y"
                    { (yyval.ast) = createNode(_DIV, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1394 "parser.tab.c"
    break;

  case 24: /* expr: expr MOD expr  */
#line 87 "parser.y"
                    { (yyval.ast) = createNode(_MOD, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1400 "parser.tab.c"
    break;

  case 25: /* expr: expr SIZE  */
#line 88 "parser.y"
                { (yyval.ast) = createNode(_SIZE, (yyvsp[-1].ast), NULL); }
#line 1406 "parser.tab.c"
    break;

  case 26: /* expr: expr CAT  */
#line 89 "parser.y"
               { (yyval.ast) = createNode(_CAT, (yyvsp[-1].ast), NULL); }
#line 1412 "parser.tab.c"
    break;

  case 27: /* expr: expr MATRIZ  */
#line 90 "parser.y"
                  { (yyval.ast) = createNode(_MATRIZ, (yyvsp[-1].ast), NULL); }
#line 1418 "parser.tab.c"
    break;

  case 28: /* expr: expr N  */
#line 91 "parser.y"
             { (yyval.ast) = createNode(_N, (yyvsp[-1].ast), NULL); }
#line 1424 "parser.tab.c"
    break;

  case 29: /* expr: expr M  */
#line 92 "parser.y"
             { (yyval.ast) = createNode(_M, (yyvsp[-1].ast), NULL); }
#line 1430 "parser.tab.c"
    break;

  case 30: /* expr: expr A  */
#line 93 "parser.y"
             { (yyval.ast) = createNode(_A, (yyvsp[-1].ast), NULL); }
#line 1436 "parser.tab.c"
    break;

  case 31: /* expr: expr B  */
#line 94 "parser.y"
             { (yyval.ast) = createNode(_B, (yyvsp[-1].ast), NULL); }
#line 1442 "parser.tab.c"
    break;

  case 32: /* expr: expr TAU  */
#line 95 "parser.y"
               { (yyval.ast) = createNode(_TAU, (yyvsp[-1].ast), NULL); }
#line 1448 "parser.tab.c"
    break;

  case 33: /* condicion: LP condicion RP  */
#line 99 "parser.y"
                    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1454 "parser.tab.c"
    break;

  case 34: /* condicion: expr EQ expr  */
#line 100 "parser.y"
                   { (yyval.ast) = createNode(_EQ, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1460 "parser.tab.c"
    break;

  case 35: /* condicion: expr NE expr  */
#line 101 "parser.y"
                   { (yyval.ast) = createNode(_NE, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1466 "parser.tab.c"
    break;

  case 36: /* condicion: expr LE expr  */
#line 102 "parser.y"
                   { (yyval.ast) = createNode(_LE, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1472 "parser.tab.c"
    break;

  case 37: /* condicion: expr GE expr  */
#line 103 "parser.y"
                   { (yyval.ast) = createNode(_GE, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1478 "parser.tab.c"
    break;

  case 38: /* condicion: expr LT expr  */
#line 104 "parser.y"
                   { (yyval.ast) = createNode(_LT, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1484 "parser.tab.c"
    break;

  case 39: /* condicion: expr GT expr  */
#line 105 "parser.y"
                   { (yyval.ast) = createNode(_GT, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1490 "parser.tab.c"
    break;

  case 40: /* array: array COMMA expr  */
#line 110 "parser.y"
    {
        if((yyvsp[-2].ast)->type == _INT_ARR && (yyvsp[0].ast)->type == _INT){
            ASTNode *val = (yyvsp[-2].ast);
            void *result = realloc(val->value.iarr.array, (++val->value.iarr.size)* sizeof(int));
            if (result == NULL){
                printf("Espacio lleno");
                exit(EXIT_FAILURE);
            }
            val->value.iarr.array[val->value.iarr.size - 1] = (yyvsp[0].ast)->value.ival;
            (yyval.ast) = val;
        }
        else if((yyvsp[-2].ast)->type == _FLOAT_ARR && (yyvsp[0].ast)->type == _FLOAT){
            ASTNode *val = (yyvsp[-2].ast);
            void *result = realloc(val->value.farr.array, (++val->value.farr.size)* sizeof(float));
            if (result == NULL){
                printf("Espacio lleno");
                exit(EXIT_FAILURE);
            }
            val->value.farr.array = result;
            val->value.farr.array[val->value.farr.size - 1] = (yyvsp[0].ast)->value.fval;
            (yyval.ast) = val;
        }
        else if((yyvsp[-2].ast)->type == _FLOAT_MAT && (yyvsp[0].ast)->type == _FLOAT_ARR){
            ASTNode *val = (yyvsp[-2].ast);
            void *result = realloc(val->value.fmat.array, (++val->value.fmat.n) * sizeof(farray*));
            if (result == NULL){
                printf("Espacio lleno");
                exit(EXIT_FAILURE);
            }
            val->value.fmat.array = result;
            farray * inside = malloc(sizeof (farray));
            inside->array =  (yyvsp[0].ast)->value.farr.array;
            inside->size =  (yyvsp[0].ast)->value.farr.size;
            val->value.fmat.array[val->value.fmat.n - 1] = inside;
            (yyval.ast) = val;
        }else{
            printf("Los arreglos deben ser del mismo tipo %s, %s\n", (yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
            exit(EXIT_FAILURE);
        }
    }
#line 1535 "parser.tab.c"
    break;

  case 41: /* array: expr  */
#line 151 "parser.y"
    {
        if ((yyvsp[0].ast)->type == _INT){
            int *var = malloc(sizeof(int));
            *var = (yyvsp[0].ast)->value.ival;
            (yyval.ast) = createIntArrNode(var,1);
        }else if ((yyvsp[0].ast)->type == _FLOAT){
            float *var = malloc(sizeof(float));
            *var = (yyvsp[0].ast)->value.fval;
            (yyval.ast) = createFloatArrNode(var,1);
        }else if ((yyvsp[0].ast)->type == _FLOAT_ARR){
            farray **var = malloc(sizeof(farray*));
            farray *inside = malloc(sizeof(farray));
            inside->array =  (yyvsp[0].ast)->value.farr.array;
            inside->size =  (yyvsp[0].ast)->value.farr.size;
            *var = inside;
            (yyval.ast) = createFloatMatNode(var,1,1);
        }else{
            printf("No se permiten arreglos del tipo %s", get_enum_name((yyvsp[0].ast)->type));
            exit(EXIT_FAILURE);
        }
    }
#line 1561 "parser.tab.c"
    break;

  case 42: /* reassign: IDENTIFIER ASSIGN expr  */
#line 175 "parser.y"
                           { (yyval.ast) = createNode(_RELOC, createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1567 "parser.tab.c"
    break;

  case 43: /* reassign: expr LS expr RS ASSIGN expr  */
#line 176 "parser.y"
                                  { (yyval.ast) = createNode(_RELOC_ARR, (yyvsp[-5].ast), createNode(_RELOC_ARR_AUX, (yyvsp[-3].ast), (yyvsp[0].ast))); }
#line 1573 "parser.tab.c"
    break;

  case 44: /* declaracion: TYPE_INT IDENTIFIER ASSIGN expr  */
#line 180 "parser.y"
                                    { (yyval.ast) = createNode(_aINT, createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1579 "parser.tab.c"
    break;

  case 45: /* declaracion: TYPE_FLOAT IDENTIFIER ASSIGN expr  */
#line 181 "parser.y"
                                        { (yyval.ast) = createNode(_aFLOAT, createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1585 "parser.tab.c"
    break;

  case 46: /* declaracion: TYPE_CADENA IDENTIFIER ASSIGN expr  */
#line 182 "parser.y"
                                         { (yyval.ast) = createNode(_aCADENA, createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1591 "parser.tab.c"
    break;

  case 47: /* declaracion: TYPE_INT MUL IDENTIFIER ASSIGN expr  */
#line 183 "parser.y"
                                          { (yyval.ast) = createNode(_aINT_ARR, createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1597 "parser.tab.c"
    break;

  case 48: /* declaracion: TYPE_FLOAT MUL IDENTIFIER ASSIGN expr  */
#line 184 "parser.y"
                                            { (yyval.ast) = createNode(_aFLOAT_ARR,createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1603 "parser.tab.c"
    break;

  case 49: /* declaracion: TYPE_CAD_MULT IDENTIFIER ASSIGN LB expr COMMA expr COMMA expr RB  */
#line 186 "parser.y"
    { (yyval.ast) = createNode(_aCADE_MULTI,createIdentifierNode((yyvsp[-8].sval)), createNode(_aCADE_MULTI, (yyvsp[-5].ast), createNode(_aCADE_MULTI, (yyvsp[-3].ast), (yyvsp[-1].ast)))); }
#line 1609 "parser.tab.c"
    break;

  case 50: /* declaracion: TYPE_FLOAT MUL MUL IDENTIFIER ASSIGN expr  */
#line 187 "parser.y"
                                                { (yyval.ast) = createNode(_aFLOAT_MAT,createIdentifierNode((yyvsp[-2].sval)), (yyvsp[0].ast)); }
#line 1615 "parser.tab.c"
    break;

  case 51: /* declaracion: TYPE_MODELO IDENTIFIER ASSIGN LB expr COMMA expr COMMA expr COMMA expr COMMA expr COMMA expr RB  */
#line 189 "parser.y"
    { (yyval.ast) = createNode(_aMODELO,createIdentifierNode((yyvsp[-14].sval)), createNode(_aMODELO, (yyvsp[-11].ast), createNode(_aMODELO, (yyvsp[-9].ast), createNode(_aMODELO, (yyvsp[-7].ast), createNode(_aMODELO, (yyvsp[-5].ast), 
        createNode(_aMODELO, (yyvsp[-3].ast), (yyvsp[-1].ast))))))); }
#line 1622 "parser.tab.c"
    break;

  case 52: /* declaracion: ALFABETO ASSIGN expr  */
#line 191 "parser.y"
                           { (yyval.ast) = createNode(_aALFABETO, createIdentifierNode((yyvsp[-2].cval)), (yyvsp[0].ast)); }
#line 1628 "parser.tab.c"
    break;

  case 53: /* print: PRINT LP expr RP  */
#line 195 "parser.y"
                     {
        (yyval.ast) = createNode(_PRINT, (yyvsp[-1].ast), NULL); 
    }
#line 1636 "parser.tab.c"
    break;


#line 1640 "parser.tab.c"

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

#line 198 "parser.y"


int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
