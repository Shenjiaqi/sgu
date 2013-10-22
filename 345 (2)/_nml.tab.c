/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "_nml.y"

#include <gmpxx.h>
#include "front.h"
extern int yylineno;


/* Line 189 of yacc.c  */
#line 79 "_nml.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACTION = 258,
     ALIAS = 259,
     BYPASS = 260,
     CASE = 261,
     CHESS_PC_OFFSET = 262,
     CHESS_VIEW = 263,
     CST = 264,
     CYCLES = 265,
     DEFAULT = 266,
     DEF = 267,
     DELAY_SLOTS = 268,
     ELSE = 269,
     ENUM = 270,
     FU = 271,
     HW_INIT = 272,
     HW_STALL = 273,
     IF = 274,
     IMAGE = 275,
     INPORT = 276,
     MEM = 277,
     MODE = 278,
     OP = 279,
     OTHERS = 280,
     OUTPORT = 281,
     PIPE = 282,
     PROPERTIES = 283,
     PROPERTY = 284,
     READ_ACTION = 285,
     READ = 286,
     REG = 287,
     RSRC = 288,
     STAGE = 289,
     START = 290,
     SW_STALL = 291,
     SWITCH = 292,
     SYNTAX = 293,
     TRN = 294,
     VALUE = 295,
     WORDS = 296,
     WRITE_ACTION = 297,
     WRITE_VALUE = 298,
     WRITE = 299,
     ARBITARY_ORDER = 300,
     CLASS = 301,
     PRIMITIVE = 302,
     DOUBLEDOT = 303,
     DOLLAR = 304,
     DCOLON = 305,
     BITNEG = 306,
     IS_EXCLUSIVE = 307,
     MAKE_EXCLUSIVE = 308,
     OP_AND_RULE = 309,
     RULE_REF = 310,
     CHESS = 311,
     INT_CONST = 312,
     STRING_CONST = 313,
     BINARY_CONST = 314,
     HEX_CONST = 315,
     IDENTIFIER = 316,
     ASSIGN = 317,
     SEMI = 318,
     COLON = 319,
     COMMA = 320,
     LPAREN = 321,
     RPAREN = 322,
     LBRACE = 323,
     RBRACE = 324,
     LBRACK = 325,
     RBRACK = 326,
     AND = 327,
     OR = 328,
     EQU = 329,
     NEQU = 330,
     LESS = 331,
     LESSE = 332,
     GRT = 333,
     GRTE = 334,
     NOT = 335,
     POINT = 336,
     PLUS = 337,
     MINUS = 338,
     BITOR = 339,
     BITAND = 340,
     MUL = 341,
     DIV = 342,
     POW = 343,
     ALIGN = 344,
     DELAY = 345,
     ENUM_NAME = 346,
     MODE_AND_NAME = 347,
     MODE_RULE_NAME = 348,
     OP_RULE_NAME = 349,
     NUMBER_NAME = 350,
     TYPE_ID = 351,
     NEG = 352
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 111 "_nml.y"

char *charP;
int int;



/* Line 214 of yacc.c  */
#line 219 "_nml.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 231 "_nml.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNRULES -- Number of states.  */
#define YYNSTATES  370

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   352

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    19,
      29,    30,    33,    34,    36,    41,    45,    46,    49,    51,
      55,    56,    61,    68,    73,    78,    83,    90,    92,    94,
      96,   100,   104,   106,   115,   117,   121,   123,   134,   135,
     137,   142,   144,   152,   163,   165,   169,   171,   176,   178,
     182,   184,   187,   189,   191,   195,   196,   199,   200,   202,
     205,   208,   213,   215,   219,   221,   223,   226,   229,   231,
     232,   234,   237,   239,   241,   243,   247,   251,   255,   259,
     263,   267,   270,   274,   276,   282,   290,   291,   292,   294,
     299,   304,   306,   310,   312,   316,   318,   322,   324,   326,
     328,   330,   332,   334,   336,   338,   341,   343,   345,   347,
     349,   351,   352,   356,   357,   359,   361,   363,   369,   373,
     377,   381,   385,   388,   392,   396,   398,   400,   406,   408,
     412,   416,   417,   419,   420,   423,   431,   432,   435,   438,
     441,   443,   445,   447,   449,   451,   453,   466,   481,   489,
     497,   512,   521,   522,   524,   525,   530,   532,   536,   537,
     540,   542,   543,   545,   549,   553,   557,   558,   561,   562,
     564,   568,   571,   575,   576,   578,   583,   588,   589,   591,
     592,   594,   599,   604,   605,   608,   610
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      99,     0,    -1,   155,   100,    -1,   101,    -1,   100,   101,
      -1,   102,    -1,   111,    -1,   115,    -1,   103,    -1,    24,
     150,    66,   112,    67,    68,   104,   105,    69,    -1,    -1,
     104,   125,    -1,    -1,   106,    -1,    20,    64,   110,   107,
      -1,    20,    64,   108,    -1,    -1,    65,   108,    -1,   109,
      -1,   108,    65,   109,    -1,    -1,    10,    66,   161,    67,
      -1,    10,    66,   161,    84,   161,    67,    -1,    13,    66,
     161,    67,    -1,     7,    66,   161,    67,    -1,    46,    66,
     150,    67,    -1,   133,   143,   110,    50,   133,   143,    -1,
     122,    -1,   118,    -1,   113,    -1,   112,    65,   113,    -1,
     114,    64,    94,    -1,   150,    -1,    24,   150,    66,   116,
      67,    68,   117,    69,    -1,    94,    -1,   116,    84,    94,
      -1,   145,    -1,    23,   150,   119,    66,   112,    67,    68,
     104,   105,    69,    -1,    -1,   120,    -1,    46,    66,   121,
      67,    -1,   150,    -1,    23,   150,   119,    66,   123,    67,
     158,    -1,    23,   150,   119,    66,   123,    67,   158,    68,
     117,    69,    -1,   124,    -1,   123,    84,   124,    -1,    93,
      -1,    38,    64,   126,    63,    -1,   127,    -1,   126,    84,
     126,    -1,   128,    -1,   127,   128,    -1,   152,    -1,   129,
      -1,   135,   130,   131,    -1,    -1,    81,    38,    -1,    -1,
     132,    -1,    81,   151,    -1,   133,   143,    -1,   110,    50,
     133,   143,    -1,   152,    -1,    91,    81,   138,    -1,   134,
      -1,   139,    -1,   139,   141,    -1,   135,   136,    -1,   150,
      -1,    -1,   137,    -1,    81,   151,    -1,   150,    -1,   140,
      -1,   151,    -1,   139,    82,   139,    -1,   139,    83,   139,
      -1,   139,    86,   139,    -1,   139,    87,   139,    -1,   139,
      85,   139,    -1,   139,    84,   139,    -1,    51,   139,    -1,
      68,   139,    69,    -1,   150,    -1,    70,   142,   161,   142,
      71,    -1,    70,   142,   161,    48,   161,   142,    71,    -1,
      -1,    -1,   144,    -1,    76,     4,   133,    78,    -1,    20,
      65,   146,    64,    -1,   147,    -1,   146,    84,   147,    -1,
     148,    -1,   147,    50,   148,    -1,   149,    -1,    91,    81,
     138,    -1,   134,    -1,   152,    -1,    61,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,   156,    -1,   155,   156,
      -1,   160,    -1,   162,    -1,   167,    -1,   169,    -1,   157,
      -1,    -1,    35,    94,   158,    -1,    -1,   159,    -1,    52,
      -1,    53,    -1,    12,   150,    62,   161,    63,    -1,   161,
      82,   161,    -1,   161,    83,   161,    -1,   161,    86,   161,
      -1,   161,    87,   161,    -1,    83,   161,    -1,   161,    88,
     161,    -1,    66,   161,    67,    -1,   151,    -1,    95,    -1,
      15,   150,    68,   163,    69,    -1,   164,    -1,   163,    65,
     164,    -1,   150,   165,   166,    -1,    -1,    58,    -1,    -1,
      62,   161,    -1,     9,   150,    76,    96,    78,   168,    63,
      -1,    -1,    62,   151,    -1,    62,   153,    -1,    62,   154,
      -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,   174,
      -1,   175,    -1,    22,   150,   177,    76,    96,    65,   180,
      78,   181,   190,   191,    63,    -1,    32,   150,   176,    76,
      96,    65,   180,    78,   188,   181,   185,   190,   191,    63,
      -1,    39,   150,    76,    96,    78,   185,    63,    -1,    27,
     150,    76,    96,    78,   185,    63,    -1,    21,   150,    76,
      96,    78,   185,    63,    26,   150,    76,    96,    78,   185,
      63,    -1,    46,   150,   177,    76,    96,    78,   186,    63,
      -1,    -1,   177,    -1,    -1,    70,   178,   179,    71,    -1,
     161,    -1,   161,    48,   161,    -1,    -1,    65,   161,    -1,
      96,    -1,    -1,   182,    -1,     4,   150,   184,    -1,     4,
     150,   183,    -1,    70,   161,    71,    -1,    -1,    89,   161,
      -1,    -1,   186,    -1,    68,   187,    69,    -1,   150,    63,
      -1,   187,   150,    63,    -1,    -1,   189,    -1,    38,    66,
      91,    67,    -1,    38,    66,   152,    67,    -1,    -1,   192,
      -1,    -1,   193,    -1,    31,    66,   194,    67,    -1,    44,
      66,   194,    67,    -1,    -1,   194,   195,    -1,   196,    -1,
     150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   159,   160,   162,   163,   165,   166,   168,
     183,   184,   188,   189,   191,   194,   196,   197,   199,   200,
     202,   203,   204,   205,   206,   207,   210,   231,   232,   234,
     235,   237,   261,   279,   294,   311,   328,   331,   346,   347,
     349,   351,   353,   354,   370,   371,   373,   392,   396,   399,
     402,   404,   407,   410,   428,   449,   450,   455,   456,   458,
     470,   471,   473,   474,   487,   490,   491,   493,   517,   522,
     523,   525,   527,   529,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   541,   545,   546,   548,   553,   554,   556,
     558,   560,   561,   565,   566,   568,   571,   582,   586,   596,
     598,   600,   602,   604,   606,   607,   609,   610,   611,   612,
     617,   619,   620,   624,   625,   627,   627,   629,   641,   642,
     643,   644,   645,   646,   653,   654,   655,   666,   682,   683,
     685,   692,   693,   695,   696,   706,   725,   726,   727,   728,
     730,   731,   732,   733,   734,   735,   739,   769,   801,   803,
     805,   808,   810,   811,   813,   814,   816,   824,   839,   840,
     842,   844,   845,   847,   848,   850,   852,   853,   855,   856,
     858,   860,   861,   863,   864,   866,   867,   871,   872,   874,
     875,   877,   879,   881,   882,   886,   892
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACTION", "ALIAS", "BYPASS", "CASE",
  "CHESS_PC_OFFSET", "CHESS_VIEW", "CST", "CYCLES", "DEFAULT", "DEF",
  "DELAY_SLOTS", "ELSE", "ENUM", "FU", "HW_INIT", "HW_STALL", "IF",
  "IMAGE", "INPORT", "MEM", "MODE", "OP", "OTHERS", "OUTPORT", "PIPE",
  "PROPERTIES", "PROPERTY", "READ_ACTION", "READ", "REG", "RSRC", "STAGE",
  "START", "SW_STALL", "SWITCH", "SYNTAX", "TRN", "VALUE", "WORDS",
  "WRITE_ACTION", "WRITE_VALUE", "WRITE", "ARBITARY_ORDER", "CLASS",
  "PRIMITIVE", "DOUBLEDOT", "DOLLAR", "DCOLON", "BITNEG", "IS_EXCLUSIVE",
  "MAKE_EXCLUSIVE", "OP_AND_RULE", "RULE_REF", "CHESS", "INT_CONST",
  "STRING_CONST", "BINARY_CONST", "HEX_CONST", "IDENTIFIER", "ASSIGN",
  "SEMI", "COLON", "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "AND", "OR", "EQU", "NEQU", "LESS", "LESSE", "GRT",
  "GRTE", "NOT", "POINT", "PLUS", "MINUS", "BITOR", "BITAND", "MUL", "DIV",
  "POW", "ALIGN", "DELAY", "ENUM_NAME", "MODE_AND_NAME", "MODE_RULE_NAME",
  "OP_RULE_NAME", "NUMBER_NAME", "TYPE_ID", "NEG", "$accept",
  "nml_description", "Rule_list", "Rule", "Op_rule", "And_op_rule",
  "Syntax_attribute_list", "And_image_attribute_list",
  "And_image_attribute", "Instr_properties_opt", "Instr_properties",
  "Instr_property", "And_field_encoding_list", "Mode_rule",
  "Parameter_declaration_list", "Parameter_declaration",
  "Op_rule_instant_name", "Or_op_rule", "Op_rule_name_list",
  "Or_image_attribute_list", "And_mode_rule", "Class_access_opt",
  "Class_access", "Register_class_name", "Or_mode_rule",
  "Mode_rule_name_list", "N_mode_rule_name", "Syntax_attribute",
  "Syntax_encoding_list", "Syntax_encoding", "Syntax_encoding_element",
  "Rule_syntax_ref", "Poi_syn_opt", "Syntax_nr_opt", "Syntax_nr",
  "And_field_encoding", "Rule_image_ref", "Rule_instant_name",
  "Image_nr_opt", "Image_nr", "Enum_element_name", "Cst_expression",
  "Const_instant_name_Enum_instant_name", "Bit_selection", "Bit_kind_opt",
  "Enc_alias_opt", "Enc_alias", "Or_image_attribute", "Or_encoding_list",
  "Or_field_encoding_list", "Or_field_encoding", "Bit_string_literal",
  "Identifier", "Integer", "String", "Binary", "Hex", "Declaration_list",
  "Declaration", "Start_declaration", "Exclusive_command_opt",
  "Exclusive_command", "Number_declaration", "Integer_expression",
  "Enum_declaration", "Enum_list", "Enum_element", "Mnemonic_opt",
  "Init_opt", "Constant_declaration", "Constant_value_opt",
  "Storage_declaration", "Memory_declaration", "Register_declaration",
  "Transitory_declaration", "Pipe_declaration", "Port_declaration",
  "Class_declaration", "Valid_address_declaration_opt",
  "Valid_address_declaration", "Address_range", "Address_step_opt",
  "Address_type", "Alias_declaration_opt", "Alias_declaration",
  "Offset_declaration", "Align_opt", "Record_declaration_opt",
  "Record_declaration", "Storage_element_list", "Field_names_opt",
  "Field_names", "Read_access_transitory_list_opt",
  "Write_access_transitory_list_opt", "Read_access_transitory_list",
  "Write_access_transitory_list", "Access_transitory_list",
  "Access_transitory", "Transitory_name_Pipe_name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,   100,   100,   101,   101,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   110,   111,   111,   112,
     112,   113,   114,   115,   116,   116,   117,   118,   119,   119,
     120,   121,   122,   122,   123,   123,   124,   125,   126,   126,
     127,   127,   128,   128,   129,   130,   130,   131,   131,   132,
     110,   110,   133,   133,   133,   133,   133,   134,   135,   136,
     136,   137,   138,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   141,   141,   142,   143,   143,   144,
     145,   146,   146,   147,   147,   148,   148,   148,   149,   150,
     151,   152,   153,   154,   155,   155,   156,   156,   156,   156,
     156,   157,   157,   158,   158,   159,   159,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   163,   163,
     164,   165,   165,   166,   166,   167,   168,   168,   168,   168,
     169,   169,   169,   169,   169,   169,   170,   171,   172,   173,
     174,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   181,   181,   182,   182,   183,   184,   184,   185,   185,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   193,   194,   194,   195,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     9,
       0,     2,     0,     1,     4,     3,     0,     2,     1,     3,
       0,     4,     6,     4,     4,     4,     6,     1,     1,     1,
       3,     3,     1,     8,     1,     3,     1,    10,     0,     1,
       4,     1,     7,    10,     1,     3,     1,     4,     1,     3,
       1,     2,     1,     1,     3,     0,     2,     0,     1,     2,
       2,     4,     1,     3,     1,     1,     2,     2,     1,     0,
       1,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     5,     7,     0,     0,     1,     4,
       4,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     0,     3,     0,     1,     1,     1,     5,     3,     3,
       3,     3,     2,     3,     3,     1,     1,     5,     1,     3,
       3,     0,     1,     0,     2,     7,     0,     2,     2,     2,
       1,     1,     1,     1,     1,     1,    12,    14,     7,     7,
      14,     8,     0,     1,     0,     4,     1,     3,     0,     2,
       1,     0,     1,     3,     3,     3,     0,     2,     0,     1,
       3,     2,     3,     0,     1,     4,     4,     0,     1,     0,
       1,     4,     4,     0,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   110,   106,   107,   108,   109,   140,
     141,   142,   143,   144,   145,    99,     0,     0,     0,     0,
     154,     0,   152,   113,     0,   154,     1,     0,     0,     2,
       3,     5,     8,     6,     7,    28,    27,   105,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   115,   116,   112,
     114,     0,     0,    38,     0,     4,     0,   100,     0,     0,
     126,   125,     0,   131,     0,   128,     0,   156,   158,     0,
       0,     0,     0,     0,     0,     0,    39,     0,   136,     0,
     122,   117,     0,     0,     0,     0,     0,   132,   133,     0,
     127,   168,     0,     0,     0,     0,   168,     0,   168,     0,
       0,     0,    34,     0,    29,     0,     0,    32,     0,     0,
     124,   118,   119,   120,   121,   123,     0,   130,   129,     0,
       0,   169,   157,   159,   155,     0,     0,     0,     0,     0,
       0,    41,    46,     0,     0,    44,     0,     0,     0,     0,
       0,   102,   103,   137,   138,   139,   135,   134,     0,     0,
       0,   160,     0,   149,     0,   148,     0,    40,     0,   113,
       0,    30,    10,    31,     0,    35,   171,   170,     0,     0,
     161,   173,   151,    10,    42,    45,    12,     0,     0,    36,
     172,     0,     0,   177,   162,     0,   161,   174,    12,     0,
       0,     0,     0,    13,    11,     0,    33,     0,   166,     0,
     179,   178,     0,   168,     0,     0,    20,     0,     9,   101,
       0,    97,    69,     0,    91,    93,    95,    68,    98,     0,
       0,     0,   164,   163,   183,     0,     0,   180,     0,     0,
     177,    37,    43,     0,     0,     0,     0,     0,     0,     0,
      15,    18,    16,    87,    64,    65,    73,    68,    74,    62,
       0,    48,    50,    53,    55,    52,     0,     0,    67,    70,
      90,     0,     0,   168,     0,   167,     0,   183,   146,   175,
     176,   179,     0,     0,     0,     0,    81,    83,     0,     0,
      20,     0,    20,    14,     0,    60,    88,    86,     0,     0,
       0,     0,     0,     0,    66,    47,     0,    51,     0,    57,
      96,    72,    71,    92,    94,     0,   165,   181,   186,   184,
     185,     0,     0,     0,     0,     0,     0,    82,    63,    19,
      87,    17,     0,     0,     0,    75,    76,    80,    79,    77,
      78,    49,    56,     0,    54,    58,   150,   182,   147,    24,
      21,     0,    23,    25,    61,     0,     0,    86,    59,     0,
      89,    87,     0,     0,    22,    26,    86,    84,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    39,    40,    41,    42,   186,   202,   203,   293,
     250,   251,   252,    43,   113,   114,   115,    44,   116,   188,
      45,    85,    86,   140,    46,   144,   145,   204,   260,   261,
     262,   263,   309,   344,   345,   253,   254,   222,   268,   269,
     310,   255,   256,   304,   334,   295,   296,   189,   223,   224,
     225,   226,   287,    71,   259,   154,   155,    12,    13,    14,
      59,    60,    15,    72,    16,    74,    75,    98,   127,    17,
     119,    18,    19,    20,    21,    22,    23,    24,    55,    53,
      78,   104,   162,   193,   194,   232,   233,   130,   131,   159,
     196,   197,   210,   236,   211,   237,   276,   319,   320
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -315
static const yytype_int16 yypact[] =
{
     205,   -29,   -29,   -29,   -29,   -29,   -29,   -29,    12,   -29,
     -29,   101,   129,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,    49,    78,    89,    96,
       5,   105,     5,   140,   109,     5,  -315,   -29,   -29,   188,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,    63,   -35,
     -29,   117,   -35,   145,   149,   170,  -315,  -315,  -315,  -315,
    -315,   151,   179,   133,   159,  -315,   160,  -315,   -35,   -35,
    -315,  -315,    83,   198,    70,  -315,   180,   -18,   194,   165,
     184,   168,   189,   172,   200,   203,  -315,   -28,   212,   113,
     191,  -315,   -35,   -35,   -35,   -35,   -35,  -315,   218,   -29,
    -315,   215,   -35,   -35,   210,   221,   215,   222,   215,   207,
     -29,   -43,  -315,    46,  -315,   225,   -38,  -315,   103,   229,
    -315,    61,    61,   191,   191,   191,   -35,  -315,  -315,   -29,
     246,  -315,   148,   148,  -315,   208,   249,   208,   256,   215,
     255,  -315,  -315,    59,    28,  -315,   -29,   264,   242,   267,
     243,  -315,  -315,  -315,  -315,  -315,  -315,   148,   275,   -26,
     313,  -315,   262,  -315,   263,  -315,   279,  -315,   276,   140,
     250,  -315,  -315,  -315,   325,  -315,  -315,  -315,   283,   -29,
     343,   310,  -315,  -315,   281,  -315,    38,   285,   282,  -315,
    -315,   277,   -29,   321,  -315,   288,   343,  -315,    38,   325,
     292,   293,   289,  -315,  -315,   -19,  -315,   265,   -49,   294,
     315,  -315,   -24,   215,   295,   296,    31,   115,  -315,  -315,
     286,  -315,   287,     7,   312,  -315,  -315,  -315,  -315,   291,
     -35,   -35,  -315,  -315,  -315,   297,   303,  -315,   304,   305,
     321,  -315,  -315,   307,   308,   309,   311,    39,    39,   298,
     316,  -315,    53,   300,  -315,   231,  -315,   241,  -315,  -315,
     -39,   115,  -315,  -315,   299,  -315,   -29,   326,  -315,  -315,
    -315,   -19,   -19,   215,   220,   148,    75,  -315,  -315,  -315,
    -315,   315,   -35,   -35,   -35,   -29,  -315,  -315,   213,   -29,
      13,    36,    13,  -315,   366,    36,  -315,  -315,    39,    39,
      39,    39,    39,    39,  -315,  -315,   115,  -315,   340,   301,
    -315,  -315,  -315,   312,  -315,   322,  -315,  -315,  -315,  -315,
    -315,    76,   323,   136,   100,   166,   317,  -315,  -315,  -315,
     300,   316,    36,   337,   -35,   142,   142,   247,   247,  -315,
    -315,  -315,  -315,   326,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,   -35,  -315,  -315,  -315,   314,    36,    33,  -315,   190,
    -315,   300,   -35,   318,  -315,  -315,   148,  -315,   319,  -315
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -315,  -315,  -315,   349,  -315,  -315,   211,   193,  -315,  -315,
     104,   107,    98,  -315,   284,   252,  -315,  -315,  -315,   201,
    -315,  -315,  -315,  -315,  -315,  -315,   232,  -315,    93,  -315,
     143,  -315,  -315,  -315,  -315,  -276,  -188,  -204,  -315,  -315,
     112,  -169,  -315,  -315,  -252,  -314,  -315,  -315,  -315,   132,
     134,  -315,    -1,   -93,  -198,  -315,  -315,  -315,   393,  -315,
     238,  -315,  -315,   -41,  -315,  -315,   320,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,   162,
    -315,  -315,   271,   214,  -315,  -315,  -315,   -96,   270,  -315,
    -315,  -315,   171,   131,  -315,  -315,   137,  -315,  -315
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      26,    27,    28,    29,    30,    31,    32,   228,    34,    35,
     136,    77,   138,   264,   239,   330,   354,   221,    25,   265,
     243,   230,    67,   244,   305,   153,   245,    89,    90,   149,
     102,    68,    25,    25,   219,    25,    63,    64,   243,   219,
     231,   244,    25,   177,   245,   306,   150,   365,    69,    73,
     142,   121,   122,   123,   124,   125,   355,   264,   200,   246,
      70,   132,   133,   265,    92,    93,   112,   238,    94,    95,
      96,   270,   220,   228,   228,    52,   201,   246,   286,   288,
     361,   362,   247,   221,   221,   157,   117,   247,    67,   219,
     247,   271,    25,    67,   219,   169,    67,    25,    73,   248,
      25,    36,   264,   291,   248,   363,    33,   248,   265,   141,
     117,   146,   170,   147,   368,    92,    93,   240,   292,    94,
      95,    96,   249,   258,   146,    48,   168,   249,   158,   335,
     336,   337,   338,   339,   340,    99,    25,    25,     1,   100,
      49,     2,   317,   347,     3,   117,    91,    94,    95,    96,
       4,     5,    37,    38,   258,   258,     6,    50,   178,    66,
      67,     7,   151,   152,     8,    92,    93,   350,     9,    94,
      95,    96,    51,   219,   312,    10,    25,   315,   191,    84,
     120,    54,    92,    93,   351,    61,    94,    95,    96,   274,
     275,   208,    57,    58,    56,    92,    93,    62,   258,    94,
      95,    96,   258,   349,   227,   258,   258,   258,   258,   258,
     258,    37,    38,    76,     1,   257,   227,     2,    92,    93,
       3,    79,    94,    95,    96,    87,     4,     5,   302,   303,
      92,    93,     6,   352,    94,    95,    96,     7,    88,   258,
       8,   323,   324,   325,     9,    80,    81,    82,    92,    93,
     358,    10,    94,    95,    96,    83,    97,   364,   101,   103,
     227,   105,   106,   258,   107,   311,   110,   108,   109,   111,
     227,   227,    92,    93,   118,   318,    94,    95,    96,    96,
     126,   134,   327,   129,   326,   139,   135,   137,   311,   148,
     257,   316,   156,   357,   257,   298,   299,   300,   301,   302,
     303,   297,    92,    93,   161,   227,    94,    95,    96,   160,
     359,   -83,   163,   298,   299,   300,   301,   302,   303,   165,
     318,   366,   167,   -83,   -83,   -83,   -83,   -83,   -83,   298,
     299,   257,   172,   302,   303,   174,   173,   175,   176,   179,
     180,   181,   182,   142,   183,   187,   190,   192,   195,   199,
     205,   206,   209,   207,   212,   257,   216,   217,   218,   235,
     234,   229,   272,   277,   241,   242,   278,   266,   267,   273,
     332,   279,   280,   282,   283,   284,   294,   285,   342,   289,
     308,   290,   343,    67,   353,   346,   348,   356,    65,   367,
     369,   214,   360,   333,   198,   143,   331,   329,   171,   341,
     215,   328,   185,   313,   307,    47,   314,   184,   164,   166,
     213,   281,   322,     0,   321,     0,     0,     0,     0,   128
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,     5,     6,     7,   205,     9,    10,
     106,    52,   108,   217,   212,   291,   330,   205,    61,   217,
       7,    70,    57,    10,    63,   118,    13,    68,    69,    67,
      48,    66,    61,    61,    58,    61,    37,    38,     7,    58,
      89,    10,    61,    69,    13,    84,    84,   361,    83,    50,
      93,    92,    93,    94,    95,    96,   332,   261,    20,    46,
      95,   102,   103,   261,    82,    83,    94,    91,    86,    87,
      88,    64,    91,   271,   272,    70,    38,    46,   247,   248,
     356,    48,    51,   271,   272,   126,    87,    51,    57,    58,
      51,    84,    61,    57,    58,    67,    57,    61,    99,    68,
      61,     0,   306,    50,    68,   357,    94,    68,   306,   110,
     111,    65,    84,    67,   366,    82,    83,   213,    65,    86,
      87,    88,    91,   216,    65,    76,    67,    91,   129,   298,
     299,   300,   301,   302,   303,    65,    61,    61,     9,    69,
      62,    12,    67,    67,    15,   146,    63,    86,    87,    88,
      21,    22,    23,    24,   247,   248,    27,    68,   159,    96,
      57,    32,    59,    60,    35,    82,    83,    67,    39,    86,
      87,    88,    76,    58,   267,    46,    61,   273,   179,    46,
      67,    76,    82,    83,    84,    76,    86,    87,    88,   230,
     231,   192,    52,    53,    32,    82,    83,    35,   291,    86,
      87,    88,   295,    67,   205,   298,   299,   300,   301,   302,
     303,    23,    24,    96,     9,   216,   217,    12,    82,    83,
      15,    76,    86,    87,    88,    66,    21,    22,    86,    87,
      82,    83,    27,    67,    86,    87,    88,    32,    78,   332,
      35,   282,   283,   284,    39,    96,    76,    96,    82,    83,
     343,    46,    86,    87,    88,    76,    58,    67,    78,    65,
     261,    96,    78,   356,    96,   266,    66,    78,    96,    66,
     271,   272,    82,    83,    62,   276,    86,    87,    88,    88,
      62,    71,    69,    68,   285,    78,    65,    65,   289,    64,
     291,    71,    63,   334,   295,    82,    83,    84,    85,    86,
      87,    70,    82,    83,    96,   306,    86,    87,    88,    63,
     351,    70,    63,    82,    83,    84,    85,    86,    87,    63,
     321,   362,    67,    82,    83,    84,    85,    86,    87,    82,
      83,   332,    68,    86,    87,    68,    94,    94,    63,    26,
      78,    78,    63,    93,    68,    20,    63,     4,    38,    68,
      65,    69,    31,    76,    66,   356,    64,    64,    69,    44,
      66,    96,    50,    66,    69,    69,    63,    81,    81,    78,
       4,    67,    67,    66,    66,    66,    76,    66,    38,    81,
      81,    65,    81,    57,    67,    63,    63,    50,    39,    71,
      71,   198,    78,   295,   183,   111,   292,   290,   146,   306,
     199,   289,   170,   271,   261,    12,   272,   169,   137,   139,
     196,   240,   281,    -1,   277,    -1,    -1,    -1,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    12,    15,    21,    22,    27,    32,    35,    39,
      46,    99,   155,   156,   157,   160,   162,   167,   169,   170,
     171,   172,   173,   174,   175,    61,   150,   150,   150,   150,
     150,   150,   150,    94,   150,   150,     0,    23,    24,   100,
     101,   102,   103,   111,   115,   118,   122,   156,    76,    62,
      68,    76,    70,   177,    76,   176,   177,    52,    53,   158,
     159,    76,   177,   150,   150,   101,    96,    57,    66,    83,
      95,   151,   161,   150,   163,   164,    96,   161,   178,    76,
      96,    76,    96,    76,    46,   119,   120,    66,    78,   161,
     161,    63,    82,    83,    86,    87,    88,    58,   165,    65,
      69,    78,    48,    65,   179,    96,    78,    96,    78,    96,
      66,    66,    94,   112,   113,   114,   116,   150,    62,   168,
      67,   161,   161,   161,   161,   161,    62,   166,   164,    68,
     185,   186,   161,   161,    71,    65,   185,    65,   185,    78,
     121,   150,    93,   112,   123,   124,    65,    67,    64,    67,
      84,    59,    60,   151,   153,   154,    63,   161,   150,   187,
      63,    96,   180,    63,   180,    63,   186,    67,    67,    67,
      84,   113,    68,    94,    68,    94,    63,    69,   150,    26,
      78,    78,    63,    68,   158,   124,   104,    20,   117,   145,
      63,   150,     4,   181,   182,    38,   188,   189,   104,    68,
      20,    38,   105,   106,   125,    65,    69,    76,   150,    31,
     190,   192,    66,   181,   105,   117,    64,    64,    69,    58,
      91,   134,   135,   146,   147,   148,   149,   150,   152,    96,
      70,    89,   183,   184,    66,    44,   191,   193,    91,   152,
     185,    69,    69,     7,    10,    13,    46,    51,    68,    91,
     108,   109,   110,   133,   134,   139,   140,   150,   151,   152,
     126,   127,   128,   129,   135,   152,    81,    81,   136,   137,
      64,    84,    50,    78,   161,   161,   194,    66,    63,    67,
      67,   190,    66,    66,    66,    66,   139,   150,   139,    81,
      65,    50,    65,   107,    76,   143,   144,    70,    82,    83,
      84,    85,    86,    87,   141,    63,    84,   128,    81,   130,
     138,   150,   151,   147,   148,   185,    71,    67,   150,   195,
     196,   194,   191,   161,   161,   161,   150,    69,   138,   109,
     133,   108,     4,   110,   142,   139,   139,   139,   139,   139,
     139,   126,    38,    81,   131,   132,    63,    67,    63,    67,
      67,    84,    67,    67,   143,   133,    50,   161,   151,   161,
      78,   133,    48,   142,    67,   143,   161,    71,   142,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:

/* Line 1464 of yacc.c  */
#line 169 "_nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (9)].charP));
	if(!tmp)
	{	
		printf("L%d: %s already defined at %d\n",yylineno,(yyvsp[(2) - (9)].charP),vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add(strtab.addstr((yyvsp[(2) - (9)].charP)),OP_AND_RULE,opntab.add(partab.clear(),(yyvsp[(7) - (9)].int),(yyvsp[(8) - (9)].int)));
	}
	syntab.addtrm();
	;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 183 "_nml.y"
    {(yyval.int)=0;;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 184 "_nml.y"
    {
		(yyval.int)=min((yyvsp[(1) - (2)].int),(yyvsp[(2) - (2)].int));
		;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 188 "_nml.y"
    {(yyval.int)=0;;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 189 "_nml.y"
    {(yyval.int)=(yyvsp[(1) - (1)].int);;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 191 "_nml.y"
    {
		(yyval.int)=opimg.addent();
		;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 194 "_nml.y"
    {printf("TODO\n");(yyval.int)=0;;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 237 "_nml.y"
    {
		int tmp=partab.find((yyvsp[(1) - (3)].charP));
		if(tmp)
			printf("L%d: %s already declared before\n",yylineno,(yyvsp[(1) - (3)].charP));
		else
		{
			tmp=vartab.find((yyvsp[(3) - (3)].charP));
			if(!tmp)
				printf("L%d: %s not defined",yylineno,(yyvsp[(3) - (3)].charP));
			else
			{
				int type=vartab.gettype(tmp);
				if(type!=OP_AND_RULE && type!=MOD_AND_RULE &&
				type!=OP_OR_RULE && type!=MOD_OR_RULe &&
				type!=CST)
					printf("L%d: %s wrong type\n",yylineno,(yyvsp[(3) - (3)].charP));
				else partab.add(strtab.getstr(strtab.addstr((yyvsp[(1) - (3)].charP))),tmp);
			}
		}
	/*|	Mode_rule_instant_name COLON MODE_RULE_NAME
	|	Enum_instant_name COLON ENUM_NAME
	|	Const_instant_name COLON Const_name*/
		;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 261 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 280 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (8)].charP));
		if(tmp)
		{
			printf("L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (8)].charP),vartab.getdefline(tmp));
			partab.clear();/*TODO clear entries in list*/
		}
		else
		{
			vartab.add(strtab.addstr((yyvsp[(2) - (8)].charP)),OP_OR_RULE,oroptab.add(partab.clear(),(yyvsp[(7) - (8)].int)),yylineno);
			/*TODO now no check on paraments, just throw it*/
		}
		;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 294 "_nml.y"
    {
		/*TODO*/
		int tmp=vartab.find((yyvsp[(1) - (1)].charP));
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,(yyvsp[(1) - (1)].charP));
			else
			{
				partab.add(strtab.getstr(strtab.addstr((yyvsp[(1) - (1)].charP))),tmp);
			}
		}
		;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 311 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(3) - (3)].charP));
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,(yyvsp[(3) - (3)].charP));
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,(yyvsp[(3) - (3)].charP));
			else
			{
				partab.add(strtab.getstr(strtab.addstr((yyvsp[(3) - (3)].charP))),tmp);
			}
		}
		;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 328 "_nml.y"
    {(yyval.int)=(yyvsp[(1) - (1)].int);;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 332 "_nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (10)].charP));
	if(!tmp)
	{	
		printf("L%d: %s already defined at %d\n",yylineno,(yyvsp[(2) - (10)].charP),vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add(strtab.addstr((yyvsp[(2) - (10)].charP)),MODE_AND_RULE,opntab.add(partab.clear(),(yyvsp[(8) - (10)].int),(yyvsp[(9) - (10)].int)));
							/* ^^^^^^TODO*/
	}
	;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 355 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (10)].charP));
		if(tmp)
		{
			printf("L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (10)].charP),vartab.getdefline(tmp));
			partab.clear();/*TODO clear entries in list*/
		}
		else
		{
			vartab.add(strtab.addstr((yyvsp[(2) - (10)].charP)),MODE_OR_RULE,ormodetab.add(partab.clear(),(yyvsp[(9) - (10)].int)),yylineno);
									/*TODO^^^^^^
									now no check on paraments, just throw it*/
		}
		;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 373 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(1) - (1)].charP));
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,(yyvsp[(1) - (1)].charP));
			else
			{
				partab.add(strtab.getstr(strtab.addstr((yyvsp[(1) - (1)].charP))),tmp);
			}
		}
	;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 392 "_nml.y"
    {
		(yyval.int)=syntab.addtrm();
		;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 396 "_nml.y"
    {
		syntab.addalt();
		;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 399 "_nml.y"
    {
		;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 402 "_nml.y"
    {
		;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 404 "_nml.y"
    {
		;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 407 "_nml.y"
    {syntab.addele(syn_ref_c(STRING_CONST,strtab.addstr((yyvsp[(1) - (1)].charP)),0));;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 410 "_nml.y"
    {syntab.addele((yyvsp[(1) - (1)].int));;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 428 "_nml.y"
    {
		int tmp=partab.find((yyvsp[(1) - (3)].charP));
		if(!tmp)
		{
			printf("L%d:instant %s not defined\n",yylineno,(yyvsp[(1) - (3)].charP));
			(yyval.int)=syntax_ele_c(0,0,0);
		}
		else if(vartab.gettype(partab.getval(tmp))==ENUM && (yyvsp[(3) - (3)].mpz_class)==0)//TODO bug here
			(yyval.int)=syntax_ele_c(ENUM,tmp,0);
		else{
			int type=vartab.gettype(partab.getval(tmp));
			if(type!=OP_AND_RULE && type!=OP_OR_RULE
			&& type!=MOD_AND_RULE && type!=MOD_OR_RULE)
				printf("L%d: %s is not op or mod rule\n",yylineno,(yyvsp[(1) - (3)].charP));
			else (yyval.int)=syntax_ele_c(RULE_REF,tmp,(int)(yyvsp[(3) - (3)].mpz_class)/*check size*/);
		}
		;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 455 "_nml.y"
    {(yyval.mpz_class)=0;;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 456 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(1) - (1)].mpz_class);;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 458 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(2) - (2)].mpz_class);;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 473 "_nml.y"
    {opimg.addele(STRING,strtab.addstr((yyvsp[(1) - (1)].charP)),0);;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 474 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(1) - (3)].charP));
		int idx;
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,(yyvsp[(1) - (3)].charP));
		else if(vartab.gettype(tmp)!=ENUM)
			printf("L%d: %s wrong type\n",yylineno,(yyvsp[(1) - (3)].charP));
		else if(!(tmp=enumtab.findent(tmp,(yyvsp[(3) - (3)].charP))))
			printf("L%d: No such entry in %s",yyline,(yyvsp[(1) - (3)].charP));
		else opimg.addele(ENUM,tmp,idx);
		;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 487 "_nml.y"
    {
			opimg.addele(RULE_REF, ((yyvsp[(1) - (1)].charP)).val , ((yyvsp[(1) - (1)].charP)).ref );
			;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 493 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(1) - (2)].charP));
		if(!tmp)
		{
			printf("L%d:i %s not defined\n",yylineno,(yyvsp[(1) - (2)].charP));
			(yyval.charP)=rule_ref(0,0);
		}
		else
		{
			int type=vartab.gettype((yyvsp[(1) - (2)].charP));
			if(type!=OP_AND_RULE && type!=OP_OR_RULE &&
			type!=MODE_AND_RULE && type!=MODE_OR_RULE)
			{
				printf("L%d: %s wrong type",yylineno,(yyvsp[(1) - (2)].charP));
				(yyval.charP)=rule_ref(0,0);
			}
			else
			{
				(yyval.charP)=rule_ref(tmp,(int)(yyvsp[(2) - (2)].mpz_class));
				/*TODO check*/
			}
		}
		;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 517 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 522 "_nml.y"
    {(yyval.mpz_class)=(mpz_class)0;;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 523 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(1) - (1)].mpz_class);;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 525 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(2) - (2)].mpz_class);;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 527 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 541 "_nml.y"
    {
		
		;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 558 "_nml.y"
    {(yyval.int)=ortab.addent();;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 560 "_nml.y"
    {ortab.finele();;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 561 "_nml.y"
    {
		ortab.finele();
		;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 568 "_nml.y"
    {
			ortab.addele(STRING,strtab.addstr((yyvsp[(1) - (1)].charP)),0);
		;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 571 "_nml.y"
    {
			int tmp=vartab.find((yyvsp[(1) - (3)].charP));
			if(!tmp)
				printf("L%d: %s not defined\n",yylineno,(yyvsp[(1) - (3)].charP));
			else if(vartab.gettype(tmp)!=ENUM)
				printf("L%d: %s wrong");
			else
				ortab.addele(ENUM,tmp,enumtab.findent(vartab.getval(tmp),(yyvsp[(3) - (3)].charP)));
		;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 582 "_nml.y"
    {
		ortab.addele(RULE_REF,((yyvsp[(1) - (1)].charP)).val,((yyvsp[(1) - (1)].charP)).ref);
		;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 586 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 596 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 598 "_nml.y"
    {((yyval.mpz_class)).set_str((yyvsp[(1) - (1)].charP));;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 600 "_nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 602 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 604 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 629 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (5)].charP));
		if(tmp)
			printf("L%d: %s previous defined at line %d\n",yylineno,(yyvsp[(2) - (5)].charP),vartab.getdefline(tmp));
		else
		{
			int idx=strtab.addstr((yyvsp[(2) - (5)].charP));
			tmp=numtab.add((yyvsp[(4) - (5)].mpz_class));
			vartab.add(strtab.getstr(idx),DEF,tmp,yylineno);
		}
		;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 641 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(1) - (3)].mpz_class) + (yyvsp[(3) - (3)].mpz_class) ; ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 642 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(1) - (3)].mpz_class) - (yyvsp[(3) - (3)].mpz_class) ; ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 643 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(1) - (3)].mpz_class) * (yyvsp[(3) - (3)].mpz_class); ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 644 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(1) - (3)].mpz_class) / (yyvsp[(3) - (3)].mpz_class) ; ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 645 "_nml.y"
    { (yyval.mpz_class) = - ((yyvsp[(1) - (2)].charP)) ; ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 646 "_nml.y"
    {
		if(!((yyvsp[(3) - (3)].mpz_class)).fits_slong_p())//can fit into signed long
			printf("L%d:Exponent too large\n",yylineno);
		if((yyvsp[(3) - (3)].mpz_class)<(signed long int)0)//should be positive
			printf("L%d:Exponent cannot be negative\n",yylineno);
		unsigned long int exp=(unsigned long int)(yyvsp[(3) - (3)].mpz_class);
		mpz_pow_ui(((yyval.mpz_class)).get_mpz_t(),((yyvsp[(1) - (3)].mpz_class)).get_mpz_t(),exp);;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 653 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(2) - (3)].mpz_class) ; ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 654 "_nml.y"
    { (yyval.mpz_class) = (yyvsp[(1) - (1)].mpz_class) ; ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 655 "_nml.y"
    {
		int tmp=vartab.find(strtab.getstr((yyvsp[(1) - (1)].charP)));
		if(!tmp)
			printf("L%d:Cannot find Number_name %s\n",yylineno,strtab.getstr((yyvsp[(1) - (1)].charP)));
		else
			(yyval.mpz_class)=numtab.getval(vartab.getval(tmp));
		;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 666 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (5)].charP));
		if(/*$4 &&*/ !tmp)
			vartab.add(strtab.getstr(strtab.addstr((yyvsp[(2) - (5)].charP))),ENUM,enumtab.addentfin(),yylineno);
		else if(tmp)
			printf("L%d: %s already defined at %d",yylineno,(yyvsp[(2) - (5)].charP),vartab.getdefline(tmp));
		enumtab.clearent();
		;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 682 "_nml.y"
    {;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 683 "_nml.y"
    {;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 685 "_nml.y"
    {
		int tmp=strtab.addstr((yyvsp[(1) - (3)].charP));
		if(!enumtab.addent(strtab.getstr(tmp),(yyvsp[(2) - (3)].int),(yyvsp[(3) - (3)].mpz_class)))
			printf("L%d:Enum entry %s already defined\n",yylineno,(yyvsp[(1) - (3)].charP));
		;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 692 "_nml.y"
    {(yyval.int)=0;;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 693 "_nml.y"
    {(yyval.int)=strtab.add((yyvsp[(1) - (1)].charP));;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 695 "_nml.y"
    {(yyval.mpz_class)=(mpz_class)-1;;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 696 "_nml.y"
    {
		if((yyvsp[(2) - (2)].mpz_class)<0)
		{
			printf("L%d:Value set for enum cannot be negative\n",yylineno);
			(yyval.mpz_class)=-1;
		}
		else (yyval.mpz_class)=(yyvsp[(2) - (2)].mpz_class);
		;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 706 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (7)].charP));
		if(tmp)
			printf("L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (7)].charP),vartab.getdefline(tmp));
		else
		{
			tmp=vartab.find((yyvsp[(4) - (7)].charP));
			if(!tmp)
				printf("L%d: Can not find type %s\n",(yyvsp[(4) - (7)].charP));
			else if(vartab.gettype(tmp)!=TYPE)
				printf("L%d: %s is not defined as type",yylineno,(yyvsp[(4) - (7)].charP));
			else
			{
				tmp=csttab.add(tmp,(yyvsp[(6) - (7)].mpz_class));
				vartab.add(strtab.getstr(strtab.addstr((yyvsp[(2) - (7)].charP))),CST,tmp,yylineno);
			}
		}
		;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 725 "_nml.y"
    {(yyval.mpz_class)=mpz_class(0);;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 726 "_nml.y"
    {(yyval.mpz_class)=(yyvsp[(2) - (2)].mpz_class);;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 727 "_nml.y"
    {((yyval.mpz_class)).set_str((yyvsp[(2) - (2)].mpz_class),0);;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 728 "_nml.y"
    {((yyval.mpz_class)).set_str((yyvsp[(2) - (2)].mpz_class),0);;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 744 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (12)].charP));
		if(tmp)
			printf("L%d: %s already defined at %d\n",yylineno,(yyvsp[(2) - (12)].charP),vartab.getdefline(tmp));
		else
		{
			int typeid=vartab.find((yyvsp[(5) - (12)].charP));
			int addresstype=vartab.find((yyvsp[(7) - (12)].charP));
			if(!typeid)
				printf("L%d: type %s not defined\n",yylineno,(yyvsp[(5) - (12)].charP));
			else if(vartab.gettype(typeid)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,(yyvsp[(5) - (12)].charP));
			else if(!addresstype)
				printf("L%d: type %s not defined\n",yylineno,(yyvsp[(7) - (12)].charP));
			else if(vartab.gettype(addresstype)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,(yyvsp[(7) - (12)].charP));
			else
			{
				//tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12);
				tmp=memtab.add(3,typeid,addresstype,9,10,11,12);
				vartab.add(strtab.getstr(strtab.addstr((yyvsp[(2) - (12)].charP))),MEM,tmp,yylineno);
			}
		}
		;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 775 "_nml.y"
    {
		int tmp=vartab.find((yyvsp[(2) - (14)].charP));
		if(tmp)
			printf("L%d: %s already defined at %d\n",yylineno,(yyvsp[(2) - (14)].charP),vartab.getdefline(tmp));
		else
		{
			int typeid=vartab.find((yyvsp[(5) - (14)].charP));
			int addresstype=vartab.find((yyvsp[(7) - (14)].charP));
			if(!typeid)
				printf("L%d: %s not defined\n",yylineno,(yyvsp[(5) - (14)].charP));
			else if(vartab.gettype(typeid)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,(yyvsp[(5) - (14)].charP));
			else if(!addresstype)
				printf("L%d: %s not defined\n",yylineno,(yyvsp[(7) - (14)].charP));
			else if(vartab.gettype(addresstype)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,(yyvsp[(7) - (14)].charP));
			else
			{
				//tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12,$13);
				tmp=memtab.add(3,typeid,addresstype,9,10,11,12,13);
				vartab.add(strtab.getstr(strtab.addstr((yyvsp[(2) - (14)].charP))),REG,tmp,yylineno);
			}
		}
		;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 816 "_nml.y"
    {
		if((yyvsp[(1) - (1)].mpz_class)<=0)
		{
			printf("L%d: address range should be a positive integer\n",yylineno);
			(yyval.charP)=class(0,0);
		}
		else
			(yyval.charP)=address_range_c(0,((yyvsp[(1) - (1)].mpz_class))_1);;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 824 "_nml.y"
    {
		if((yyvsp[(1) - (3)].mpz_class)<0)
		{
			printf("L%d: address range should be nonnegative\n",yylineno);
			(yyvsp[(1) - (3)].mpz_class)=0;
		}
		if((yyvsp[(3) - (3)].mpz_class)<0)
		{
			printf("L%d: address range should be nonnegative\n",yylineno);
			(yyvsp[(3) - (3)].mpz_class)=0;
		}
		if((yyvsp[(1) - (3)].mpz_class)>(yyvsp[(3) - (3)].mpz_class))
			(yyval.charP)=address_range_c((yyvsp[(3) - (3)].mpz_class),(yyvsp[(1) - (3)].mpz_class));
		else (yyval.charP)=address_range_c((yyvsp[(1) - (3)].mpz_class),(yyvsp[(3) - (3)].mpz_class));;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 842 "_nml.y"
    { (yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;



/* Line 1464 of yacc.c  */
#line 2678 "_nml.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



