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
#line 1 "nml.y"

#include <gmpxx.h>
#include "front.h"
#include <iostream>
extern int yylineno;
extern var_table vartab;
extern string_table strtab;
extern num_table numtab;
void yyerror(const char *s);
extern int yylex(void);


/* Line 189 of yacc.c  */
#line 85 "nml.tab.c"

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
     ASSIGN = 258,
     DEF = 259,
     SEMI = 260,
     IDENTIFIER = 261,
     PLUS = 262,
     MINUS = 263,
     DIV = 264,
     POW = 265,
     LPAREN = 266,
     RPAREN = 267,
     LBRACE = 268,
     RBRACE = 269,
     ENUM = 270,
     STRING_CONST = 271,
     COMMA = 272,
     CST = 273,
     LESS = 274,
     GRT = 275,
     TYPE = 276,
     INT_CONST = 277,
     BIN_CONST = 278,
     HEX_CONST = 279,
     VAL_TYPE = 280,
     SYNTAX = 281,
     MEM = 282,
     LBRACK = 283,
     RBRACK = 284,
     DOUBLEDOT = 285,
     REG = 286,
     START = 287,
     OP = 288,
     RULE_REF = 289,
     DCOLON = 290,
     IMAGE = 291,
     POINT = 292,
     COLON = 293,
     BITOR = 294,
     OP_OR_RULE = 295,
     OP_AND_RULE = 296,
     MODE_AND_RULE = 297,
     MODE_OR_RULE = 298,
     CYCLES = 299,
     ALIAS = 300,
     CHESS_PC_OFFSET = 301,
     CLASS = 302,
     DELAY_SLOTS = 303,
     MODE = 304,
     ENUM_NAME = 305,
     MUL = 306,
     NEG = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 62 "nml.y"

const char* charP;
int index;



/* Line 214 of yacc.c  */
#line 180 "nml.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "nml.tab.c"

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    19,
      29,    38,    40,    43,    45,    47,    49,    59,    60,    63,
      69,    70,    73,    75,    79,    80,    85,    92,    97,   102,
     107,   110,   115,   116,   118,   122,   124,   128,   131,   133,
     134,   137,   142,   144,   146,   149,   151,   154,   155,   157,
     160,   161,   163,   167,   171,   173,   175,   184,   186,   191,
     193,   197,   199,   203,   205,   207,   211,   214,   215,   217,
     220,   222,   224,   226,   230,   232,   235,   237,   239,   241,
     243,   245,   247,   251,   253,   255,   265,   275,   277,   278,
     283,   284,   287,   296,   298,   302,   304,   312,   313,   316,
     319,   322,   324,   331,   333,   337,   341,   342,   344,   345,
     348,   354,   358,   362,   366,   370,   373,   377,   381,   383,
     385,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    96,    55,    -1,    56,    -1,    55,    56,
      -1,    62,    -1,    57,    -1,    59,    -1,    58,    -1,    49,
       6,    11,    81,    12,    13,    74,    64,    14,    -1,    49,
       6,    11,    60,    12,    13,    85,    14,    -1,    61,    -1,
      60,    61,    -1,     6,    -1,    63,    -1,    84,    -1,    33,
       6,    11,    81,    12,    13,    74,    64,    14,    -1,    -1,
      64,    65,    -1,    36,    38,    69,    66,     5,    -1,    -1,
      17,    67,    -1,    68,    -1,    67,    17,    68,    -1,    -1,
      44,    11,   117,    12,    -1,    44,    11,   117,    39,   117,
      12,    -1,    48,    11,   117,    12,    -1,    46,    11,   117,
      12,    -1,    47,    11,     6,    12,    -1,    72,    70,    -1,
      69,    35,    72,    70,    -1,    -1,    71,    -1,    19,    45,
      20,    -1,    16,    -1,    50,    37,    89,    -1,    73,    91,
      -1,     6,    -1,    -1,    74,    75,    -1,    26,    38,    76,
       5,    -1,    77,    -1,    78,    -1,    77,    78,    -1,    16,
      -1,    73,    79,    -1,    -1,    80,    -1,    37,   119,    -1,
      -1,    82,    -1,    81,    17,    82,    -1,     6,    38,    83,
      -1,     6,    -1,    50,    -1,    33,     6,    11,    95,    12,
      13,    85,    14,    -1,    86,    -1,    36,    38,    87,     5,
      -1,    88,    -1,    87,    39,    88,    -1,    90,    -1,    88,
      35,    90,    -1,     6,    -1,    93,    -1,    50,    37,    89,
      -1,    73,    91,    -1,    -1,    92,    -1,    37,   119,    -1,
      16,    -1,     6,    -1,    94,    -1,    95,    39,    94,    -1,
      97,    -1,    96,    97,    -1,   116,    -1,   111,    -1,   108,
      -1,   105,    -1,    99,    -1,    98,    -1,    32,     6,     5,
      -1,   101,    -1,   100,    -1,    31,     6,   103,    19,   110,
      17,   102,    20,     5,    -1,    27,     6,   103,    19,   110,
      17,   102,    20,     5,    -1,   110,    -1,    -1,    28,   106,
     104,    29,    -1,    -1,    17,   117,    -1,    21,     6,    19,
     119,    17,   107,    20,     5,    -1,   117,    -1,   117,    30,
     117,    -1,    25,    -1,    18,     6,    19,   110,    20,   109,
       5,    -1,    -1,     3,    22,    -1,     3,    23,    -1,     3,
      24,    -1,     6,    -1,    15,     6,    13,   112,    14,     5,
      -1,   113,    -1,   112,    17,   113,    -1,     6,   114,   115,
      -1,    -1,    16,    -1,    -1,     3,   117,    -1,     4,     6,
       3,   117,     5,    -1,   117,     7,   117,    -1,   117,     8,
     117,    -1,   117,    51,   117,    -1,   117,     9,   117,    -1,
       8,   117,    -1,   117,    10,   117,    -1,    11,   117,    12,
      -1,   119,    -1,   118,    -1,     6,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    99,   100,   103,   104,   107,   108,   111,
     123,   134,   135,   137,   150,   151,   154,   165,   166,   169,
     173,   174,   176,   177,   180,   181,   182,   183,   184,   185,
     188,   189,   192,   193,   196,   198,   199,   207,   214,   222,
     223,   226,   230,   234,   235,   237,   238,   243,   244,   246,
     259,   260,   261,   263,   274,   289,   293,   307,   309,   313,
     314,   316,   317,   319,   323,   326,   335,   340,   341,   344,
     354,   356,   373,   377,   383,   384,   387,   388,   389,   390,
     391,   392,   395,   402,   403,   405,   422,   441,   443,   444,
     448,   449,   454,   471,   481,   500,   503,   517,   518,   519,
     520,   523,   533,   542,   543,   546,   551,   552,   555,   556,
     567,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     593,   601
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "DEF", "SEMI", "IDENTIFIER",
  "PLUS", "MINUS", "DIV", "POW", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "ENUM", "STRING_CONST", "COMMA", "CST", "LESS", "GRT", "TYPE",
  "INT_CONST", "BIN_CONST", "HEX_CONST", "VAL_TYPE", "SYNTAX", "MEM",
  "LBRACK", "RBRACK", "DOUBLEDOT", "REG", "START", "OP", "RULE_REF",
  "DCOLON", "IMAGE", "POINT", "COLON", "BITOR", "OP_OR_RULE",
  "OP_AND_RULE", "MODE_AND_RULE", "MODE_OR_RULE", "CYCLES", "ALIAS",
  "CHESS_PC_OFFSET", "CLASS", "DELAY_SLOTS", "MODE", "ENUM_NAME", "MUL",
  "NEG", "$accept", "nml_description", "rule_list", "rule", "mode_rule",
  "and_mode_rule", "or_mode_rule", "mode_rule_name_list", "mode_rule_name",
  "op_rule", "and_op_rule", "and_image_attribute_list",
  "and_image_attribute", "instr_properties_opt", "instr_properties",
  "instr_property", "and_field_encoding_list", "enc_alias_opt",
  "enc_alias", "and_field_encoding", "rule_instant_name",
  "syntax_attribute_list", "syntax_attribute", "syntax_encoding_list",
  "syntax_encoding", "syntax_encoding_element", "syntax_nr_opt",
  "syntax_nr", "parameter_declaration_list", "parameter_declaration",
  "r_name", "or_op_rule", "or_image_attribute_list", "or_image_attribute",
  "or_encoding_list", "or_field_encoding_list", "enum_element_name",
  "or_field_encoding", "image_nr_opt", "image_nr", "bit_string_literal",
  "op_rule_name", "op_rule_name_list", "declaration_list", "declaration",
  "start_declaration", "storage_declaration", "register_declaration",
  "memory_declaration", "address_type", "valid_address_declaration",
  "address_step_opt", "type_declaration", "address_range", "val_type",
  "cst_declaration", "cst_value_opt", "type_id", "enum_declaration",
  "enum_list", "enum_element", "mnemonic_opt", "init_opt",
  "number_declaration", "integer_expression", "number_name", "integer", 0
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
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      59,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    72,    72,    72,    73,    74,
      74,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    81,    82,    83,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    90,    90,    90,    91,    91,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    99,    99,   100,   101,   102,   103,   103,
     104,   104,   105,   106,   106,   107,   108,   109,   109,   109,
     109,   110,   111,   112,   112,   113,   114,   114,   115,   115,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     9,
       8,     1,     2,     1,     1,     1,     9,     0,     2,     5,
       0,     2,     1,     3,     0,     4,     6,     4,     4,     4,
       2,     4,     0,     1,     3,     1,     3,     2,     1,     0,
       2,     4,     1,     1,     2,     1,     2,     0,     1,     2,
       0,     1,     3,     3,     1,     1,     8,     1,     4,     1,
       3,     1,     3,     1,     1,     3,     2,     0,     1,     2,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     9,     9,     1,     0,     4,
       0,     2,     8,     1,     3,     1,     7,     0,     2,     2,
       2,     1,     6,     1,     3,     3,     0,     1,     0,     2,
       5,     3,     3,     3,     3,     2,     3,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    81,    80,    84,    83,    79,    78,    77,    76,     0,
       0,     0,     0,    88,    88,     0,     1,     0,     0,     2,
       3,     6,     8,     7,     5,    14,    15,    75,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     4,   120,
       0,     0,   121,     0,   119,   118,   106,     0,   103,   101,
       0,     0,    90,    93,     0,     0,    50,    50,   115,     0,
     110,     0,     0,     0,     0,     0,   107,   108,     0,     0,
      97,     0,     0,     0,     0,     0,     0,    71,     0,    51,
      72,     0,    13,     0,    11,     0,   117,   111,   112,   114,
     116,   113,     0,   105,   102,   104,     0,     0,    95,     0,
      91,    89,    94,     0,     0,     0,     0,     0,     0,     0,
      13,     0,    12,     0,   109,    98,    99,   100,    96,     0,
       0,    87,     0,    54,    55,    53,    39,     0,    52,     0,
      71,    73,     0,    39,    92,     0,     0,    17,     0,     0,
      57,     0,    17,    86,    85,     0,     0,    40,     0,    56,
      10,     0,     0,    16,     0,    18,    38,    70,     0,    67,
       0,    59,    61,    64,     9,    45,    47,     0,    42,    43,
       0,     0,     0,    66,    68,    58,     0,     0,     0,    46,
      48,    41,    44,    35,     0,    20,    32,    67,    63,    65,
      69,    60,    62,    49,     0,    24,     0,     0,     0,    30,
      33,    37,    36,     0,     0,     0,     0,    21,    22,    32,
      19,     0,     0,     0,     0,     0,    24,    31,    34,     0,
       0,     0,     0,    23,    25,     0,    28,    29,    27,     0,
      26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,    29,    30,    31,    32,    33,    93,    94,    34,
      35,   156,   165,   207,   217,   218,   195,   209,   210,   196,
     169,   147,   157,   177,   178,   179,   189,   190,    88,    89,
     135,    36,   149,   150,   170,   171,   199,   172,   183,   184,
     173,    90,    91,     9,    10,    11,    12,    13,    14,   130,
      43,    83,    15,    62,   109,    16,   107,   131,    17,    57,
      58,    77,   103,    18,    53,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
      80,    15,    30,    62,    68,    71,    88,    90,   105,    20,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   119,
     118,   113,   120,   110,   110,   135,  -153,   137,   138,    66,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   115,   139,
     140,   125,   115,   122,   130,  -153,   141,   142,  -153,  -153,
     115,   115,  -153,    -3,  -153,  -153,   134,    99,  -153,  -153,
     131,   143,   144,    49,   140,   140,   148,   149,   146,    10,
    -153,   115,   115,   115,   115,   115,  -153,   154,   153,   139,
     156,   145,   115,   133,   115,   147,   150,   127,    91,  -153,
    -153,    11,   127,    33,  -153,    92,  -153,    82,    82,   146,
     146,   146,   115,  -153,  -153,  -153,   112,   158,  -153,   151,
      79,  -153,    79,   140,   140,    40,   155,   160,   159,   163,
    -153,   161,  -153,   162,    79,  -153,  -153,  -153,  -153,   168,
     157,  -153,   164,  -153,  -153,  -153,  -153,   127,  -153,   152,
    -153,  -153,   152,  -153,  -153,   171,   173,   165,   166,   172,
    -153,   175,   165,  -153,  -153,   167,    13,  -153,    28,  -153,
    -153,    83,     9,  -153,   169,  -153,  -153,  -153,   174,   176,
      -2,   177,  -153,  -153,  -153,  -153,   178,   180,     9,  -153,
      60,   181,   125,  -153,  -153,  -153,    28,    28,   125,  -153,
    -153,  -153,  -153,  -153,   179,    85,   182,   176,  -153,  -153,
    -153,   177,  -153,  -153,   181,    81,    60,   185,   183,  -153,
    -153,  -153,  -153,   184,   186,   187,   188,   189,  -153,   182,
    -153,   190,   115,   115,   194,   115,    81,  -153,  -153,     4,
      55,   170,    63,  -153,  -153,   115,  -153,  -153,  -153,    73,
    -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,   191,  -153,  -153,  -153,  -153,    86,  -153,
    -153,    42,  -153,  -153,  -153,   -34,  -153,   -23,  -153,    -4,
    -152,    65,  -153,  -153,  -153,    25,  -153,  -153,   192,    97,
    -153,  -153,    67,  -153,  -153,    31,    14,    32,    24,  -153,
    -153,   103,  -153,  -153,   214,  -153,  -153,  -153,  -153,   111,
     200,  -153,  -153,  -153,  -153,  -153,  -153,    53,  -153,  -153,
     193,  -153,  -153,  -153,   -42,  -153,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      63,    61,    70,   185,    71,    72,    73,    74,    68,    69,
     176,    71,    72,    73,    74,   166,   234,    71,    72,    73,
      74,    19,    96,   118,     1,   175,   176,   163,   197,    97,
      98,    99,   100,   101,   166,     2,    20,   186,     3,   120,
     110,     4,   112,   235,   167,   121,   133,     5,    75,   164,
     119,     6,     7,    27,   197,    75,    71,    72,    73,    74,
     124,    75,    71,    72,    73,    74,   166,   236,    21,    28,
      71,    72,    73,    74,    22,   238,   193,    23,   168,    84,
      71,    72,    73,    74,     1,   240,    71,    72,    73,    74,
     134,    73,    74,    60,    24,     2,    25,   174,     3,    27,
      75,     4,   205,   116,   123,    26,    75,     5,   117,   117,
     194,     6,     7,    78,    75,    28,    79,    85,    86,   164,
     206,    49,    38,    50,    75,   213,    51,   214,   215,   216,
      75,    39,    40,    75,   125,   126,   127,    52,    42,    41,
      45,    64,   200,    46,    47,    56,    59,    52,   203,    65,
      76,    80,    66,    67,    87,    92,    74,   102,   104,   106,
      81,    82,   111,   128,   113,   115,   137,   114,   136,   140,
     108,   129,   139,   144,   142,   143,   153,   145,   154,   122,
     229,   230,   237,   232,   146,   191,   159,   198,   148,   160,
     220,   155,   233,   239,   161,   222,   227,   223,   224,   225,
     231,   208,   219,   192,   158,   162,   226,   180,   152,   151,
     228,   181,   187,   182,   138,   188,   204,   201,   212,   202,
      48,   211,   141,    37,    44,   132,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      42,    41,     5,     5,     7,     8,     9,    10,    50,    51,
     162,     7,     8,     9,    10,     6,    12,     7,     8,     9,
      10,     6,    12,    12,     4,    16,   178,    14,   180,    71,
      72,    73,    74,    75,     6,    15,     6,    39,    18,     6,
      82,    21,    84,    39,    16,    12,     6,    27,    51,    36,
      39,    31,    32,    33,   206,    51,     7,     8,     9,    10,
     102,    51,     7,     8,     9,    10,     6,    12,     6,    49,
       7,     8,     9,    10,     6,    12,    16,     6,    50,    30,
       7,     8,     9,    10,     4,    12,     7,     8,     9,    10,
      50,     9,    10,    40,     6,    15,     6,    14,    18,    33,
      51,    21,    17,    12,    12,     0,    51,    27,    17,    17,
      50,    31,    32,    14,    51,    49,    17,    64,    65,    36,
      35,     6,     3,     8,    51,    44,    11,    46,    47,    48,
      51,    13,    19,    51,    22,    23,    24,    22,    28,    19,
       5,    19,   182,     6,     6,     6,     6,    22,   188,    19,
      16,    20,    11,    11,     6,     6,    10,     3,     5,     3,
      17,    17,    29,     5,    17,    38,     6,    17,    13,     6,
      25,    20,    13,     5,    13,    13,     5,    20,     5,    93,
     222,   223,    12,   225,    20,     5,    14,     6,    36,    14,
       5,    26,   226,   235,   152,    11,   219,    11,    11,    11,
       6,    19,   206,   178,    38,    38,    17,    38,   143,   142,
      20,    37,    35,    37,   117,    37,    37,   186,   204,   187,
      29,   197,   119,     9,    24,   114,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    15,    18,    21,    27,    31,    32,    54,    96,
      97,    98,    99,   100,   101,   105,   108,   111,   116,     6,
       6,     6,     6,     6,     6,     6,     0,    33,    49,    55,
      56,    57,    58,    59,    62,    63,    84,    97,     3,    13,
      19,    19,    28,   103,   103,     5,     6,     6,    56,     6,
       8,    11,    22,   117,   118,   119,     6,   112,   113,     6,
     110,   119,   106,   117,    19,    19,    11,    11,   117,   117,
       5,     7,     8,     9,    10,    51,    16,   114,    14,    17,
      20,    17,    17,   104,    30,   110,   110,     6,    81,    82,
      94,    95,     6,    60,    61,    81,    12,   117,   117,   117,
     117,   117,     3,   115,     5,   113,     3,   109,    25,   107,
     117,    29,   117,    17,    17,    38,    12,    17,    12,    39,
       6,    12,    61,    12,   117,    22,    23,    24,     5,    20,
     102,   110,   102,     6,    50,    83,    13,     6,    82,    13,
       6,    94,    13,    13,     5,    20,    20,    74,    36,    85,
      86,    85,    74,     5,     5,    26,    64,    75,    38,    14,
      14,    64,    38,    14,    36,    65,     6,    16,    50,    73,
      87,    88,    90,    93,    14,    16,    73,    76,    77,    78,
      38,    37,    37,    91,    92,     5,    39,    35,    37,    79,
      80,     5,    78,    16,    50,    69,    72,    73,     6,    89,
     119,    88,    90,   119,    37,    17,    35,    66,    19,    70,
      71,    91,    89,    44,    46,    47,    48,    67,    68,    72,
       5,    45,    11,    11,    11,    11,    17,    70,    20,   117,
     117,     6,   117,    68,    12,    39,    12,    12,    12,   117,
      12
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
#line 112 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (9)].charP));
	int z=partab.clear();
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (9)].charP),vartab.getdefline(tmp));
	else
	{
		vartab.add((yyvsp[(2) - (9)].charP),MODE_AND_RULE,opntab.add(z,syntab.addtrm(),opimg.addtrm()),yylineno);
	}
;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 124 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (8)].charP));
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at %d\n",yylineno,(yyvsp[(2) - (8)].charP),vartab.getdefline(tmp));
		partab.clear();
	}
	else vartab.add((yyvsp[(2) - (8)].charP),MODE_OR_RULE,ormodetab.add(partab.clear(),(yyvsp[(7) - (8)].index)),yylineno);
;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 137 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(1) - (1)].charP));
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=MODE_OR_RULE && type!=MODE_AND_RULE)
			fprintf(stderr,"L%d: %s is not a mode rule\n",yylineno,(yyvsp[(1) - (1)].charP));
		else partab.add((yyvsp[(1) - (1)].charP),(yyvsp[(1) - (1)].charP));
	}
;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 155 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (9)].charP));
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (9)].charP),vartab.getdefline(tmp));
		partab.clear();
	}
	else vartab.add((yyvsp[(2) - (9)].charP),OP_AND_RULE,opntab.add(partab.clear(),syntab.addtrm(),opimg.addtrm()),yylineno);
;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 165 "nml.y"
    {;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 166 "nml.y"
    {;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 169 "nml.y"
    {
	opimg.addalt();
;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 198 "nml.y"
    {opimg.addele(STRING_CONST,strtab.addstr((yyvsp[(1) - (1)].charP)),0);;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 199 "nml.y"
    {
		int tmp=vartab.find((yyvsp[(1) - (3)].charP));
		tmp=vartab.getval(tmp);
		int idx=enumtab.findent(tmp,(yyvsp[(3) - (3)].charP));
		if(!idx)
			fprintf(stderr,"L%d: no entry %s in %s\n",yylineno,(yyvsp[(3) - (3)].charP),(yyvsp[(1) - (3)].charP));
		else opimg.addele(ENUM,tmp,idx);
	;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 207 "nml.y"
    {
		opimg.addele(RULE_REF,partab.find((yyvsp[(1) - (2)].charP)),(yyvsp[(2) - (2)].index));
	;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 214 "nml.y"
    {
	int tmp=partab.find((yyvsp[(1) - (1)].charP));
	(yyval.charP)=NULL;
	if(!tmp)
		fprintf(stderr,"L%d: %s not declared\n",yylineno,(yyvsp[(1) - (1)].charP));
	else (yyval.charP)=(yyvsp[(1) - (1)].charP);
;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 223 "nml.y"
    {
;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 226 "nml.y"
    {
	syntab.addalt();
;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 230 "nml.y"
    {
//	| syntax_encoding_list BITOR syntax_encoding{
;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 234 "nml.y"
    {;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 235 "nml.y"
    {;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 237 "nml.y"
    {syntab.addele(syntax_ref_c(STRING_CONST,strtab.addstr((yyvsp[(1) - (1)].charP)),0));;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 238 "nml.y"
    {
	/*TODO no check on rule_instant_name(such as enum cannot follow by syntax_nr*/
	syntab.addele(syntax_ref_c(RULE_REF,partab.find((yyvsp[(1) - (2)].charP)),(yyvsp[(2) - (2)].index)/*TODO check size*/));
;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 243 "nml.y"
    {(yyval.index)=0;;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 244 "nml.y"
    {(yyval.index)=(yyvsp[(1) - (1)].index);;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 246 "nml.y"
    {
	(yyval.index)=0;
	mpz_class t=(mpz_class)(yyvsp[(2) - (2)].charP);
	if(!t.fits_sint_p())
		fprintf(stderr,"L%d: %s too large\n",yylineno,(yyvsp[(2) - (2)].charP));
	else if(t<0)
		fprintf(stderr,"L%d: %s should not be negative\n",yylineno,(yyvsp[(2) - (2)].charP));
	else (yyval.index)=t.get_si();
;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 263 "nml.y"
    {
	int tmp=partab.find((yyvsp[(1) - (3)].charP));
	if(tmp)
		fprintf(stderr,"L%d: %s already declared\n",yylineno,(yyvsp[(1) - (3)].charP));
	else
	{
		tmp=vartab.find((yyvsp[(3) - (3)].charP));
		partab.add((yyvsp[(1) - (3)].charP),(yyvsp[(3) - (3)].charP));
	}
;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 274 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(1) - (1)].charP));
	(yyval.charP)=NULL;
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=OP_OR_RULE && type!=OP_AND_RULE
		&& type!=MODE_OR_RULE && type!=MODE_AND_RULE
		&& type!=CST)
			fprintf(stderr,"L%d: %s wrong type\n",yylineno,(yyvsp[(1) - (1)].charP));
		else (yyval.charP)=(yyvsp[(1) - (1)].charP);
	}
;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 289 "nml.y"
    {
	(yyval.charP)=(yyvsp[(1) - (1)].charP);
;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 294 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (8)].charP));
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (8)].charP),vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add((yyvsp[(2) - (8)].charP),OP_OR_RULE,oroptab.add(partab.clear(),(yyvsp[(7) - (8)].index)),yylineno);
	}
;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 307 "nml.y"
    {(yyval.index)=(yyvsp[(1) - (1)].index);;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 309 "nml.y"
    {
	(yyval.index)=ortab.addent();
;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 313 "nml.y"
    {ortab.finele();;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 314 "nml.y"
    {ortab.finele();;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 319 "nml.y"
    {
	(yyval.charP)=(yyvsp[(1) - (1)].charP);
;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 323 "nml.y"
    {
		ortab.addele(STRING_CONST,strtab.addstr((yyvsp[(1) - (1)].charP)),0);
	;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 326 "nml.y"
    {
		int ename=vartab.find((yyvsp[(1) - (3)].charP));
		int tmp=0;
		if(ename)
			tmp=enumtab.findent(vartab.getval(ename),(yyvsp[(3) - (3)].charP));
		if(!tmp)
			fprintf(stderr,"L%d: enum %s has not entry %s\n",yylineno,(yyvsp[(1) - (3)].charP),(yyvsp[(3) - (3)].charP));
		ortab.addele(ENUM,ename,tmp);
	;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 335 "nml.y"
    {
		//ortab.addele(RULE_REF,vartab.getval(vartab.find(partab.getval(partab.find($1)))),$2);
		ortab.addele(RULE_REF,partab.find((yyvsp[(1) - (2)].charP)),(yyvsp[(2) - (2)].index));
;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 340 "nml.y"
    {(yyval.index)=0;;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 341 "nml.y"
    {(yyval.index)=(yyvsp[(1) - (1)].index);;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 344 "nml.y"
    {
	mpz_class t=(mpz_class)(yyvsp[(2) - (2)].charP);
	(yyval.index)=0;
	if(!t.fits_sint_p())
		fprintf(stderr,"L%d: number %s too large\n",yylineno,(yyvsp[(2) - (2)].charP));
	else if(t<0)
		fprintf(stderr,"L%d: expect a positive number at %s\n",yylineno,(yyvsp[(2) - (2)].charP));
	else (yyval.index)=t.get_si();
;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 354 "nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 356 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(1) - (1)].charP));
	(yyval.charP)=NULL;
	if(!tmp)
	{
		fprintf(stderr,"L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
	}
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=OP_AND_RULE && type!=OP_OR_RULE && type!=MODE_AND_RULE && type!=MODE_OR_RULE)
			fprintf(stderr,"L%d %s wrong type\n",yylineno,(yyvsp[(1) - (1)].charP));
		else
			(yyval.charP)=(yyvsp[(1) - (1)].charP);
	}
;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 373 "nml.y"
    {
	if(partab.find((yyvsp[(1) - (1)].charP)))
		fprintf(stderr,"L%d: %s already declared\n",yylineno,(yyvsp[(1) - (1)].charP));
	partab.add((yyvsp[(1) - (1)].charP),vartab.getname(vartab.find((yyvsp[(1) - (1)].charP))));;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 377 "nml.y"
    {
	if(partab.find((yyvsp[(3) - (3)].charP)))
		fprintf(stderr,"L%d: %s already declared\n",yylineno,(yyvsp[(3) - (3)].charP));
	partab.add((yyvsp[(3) - (3)].charP),vartab.getname(vartab.find((yyvsp[(3) - (3)].charP))));
;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 395 "nml.y"
    {
	/*int tmp=vartab.find($2);
	if(setstart(tmp))
		fprintf(stderr,"L%d: %s alreay declared as start rule\n",yylineno,vartab.getname(tmp));*/
	setstart((yyvsp[(2) - (3)].charP));
;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 411 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (9)].charP));
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (9)].charP),vartab.getdefline(tmp));
	else
	{
		tmp=memtab.add((yyvsp[(3) - (9)].index),(yyvsp[(5) - (9)].index),(yyvsp[(7) - (9)].index),9,10,11,12);/*TODO*/
		vartab.add((yyvsp[(2) - (9)].charP),REG,tmp,yylineno);
	}
;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 427 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (9)].charP));
        if(tmp)
                fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (9)].charP),vartab.getdefline(tmp));
        else
        {
                int tid=(yyvsp[(5) - (9)].index);
                int addresstype=(yyvsp[(7) - (9)].index);
                //tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12);
                tmp=memtab.add((yyvsp[(3) - (9)].index),tid,addresstype,9,10,11,12);
                vartab.add((yyvsp[(2) - (9)].charP),MEM,tmp,yylineno);
        }
;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 441 "nml.y"
    {(yyval.index)=(yyvsp[(1) - (1)].index);;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 443 "nml.y"
    {(yyval.index)=0;;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 444 "nml.y"
    {
	(yyval.index)=addrtab.add((yyvsp[(2) - (4)].index),(yyvsp[(3) - (4)].index));
;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 448 "nml.y"
    {(yyval.index)=numtab.add(1);;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 449 "nml.y"
    {
	(yyval.index)=numtab.add(inttab.getans());
	inttab.clear();
;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 454 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (8)].charP));
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (8)].charP),vartab.getdefline(tmp));
	else
	{
		mpz_class width;
		width=(mpz_class)(yyvsp[(4) - (8)].charP);
		if(width<=0)
		{
			fprintf(stderr,"L%d: %s width of type should be positive",yylineno,(yyvsp[(2) - (8)].charP));
			width=1;/*TODO*/
		}
		vartab.add((yyvsp[(2) - (8)].charP),TYPE,typetab.add((yyvsp[(2) - (8)].charP),(yyvsp[(6) - (8)].index),width.get_ui()),yylineno);
	}
;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 471 "nml.y"
    {
		mpz_class tmp=inttab.getans();
		inttab.clear();
                if(tmp<=0)
                {
                        fprintf(stderr,"L%d: address range should be a positive integer\n",yylineno);
                        (yyval.index)=0;
                }
                else
                        (yyval.index)=addrangetab.add(numtab.add(0),numtab.add(tmp-1));;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 481 "nml.y"
    {
		mpz_class e=inttab.getans();
		mpz_class b=inttab.getans();
		inttab.clear();
                if(e<0)
                {
                        fprintf(stderr,"L%d: address range should be nonnegative\n",yylineno);
                        e=0;
                }
                if(b<0)
                {
                        fprintf(stderr,"L%d: address range should be nonnegative\n",yylineno);
                        b=0;
                }
                if(e>=b)
                        (yyval.index)=addrangetab.add(numtab.add(b),numtab.add(e));
                else (yyval.index)=addrangetab.add(numtab.add(e),numtab.add(b));
;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 500 "nml.y"
    {
	(yyval.index)=(yyvsp[(1) - (1)].index);
;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 503 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (7)].charP));
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (7)].charP),vartab.getdefline(tmp));
	else
	{
		if(numtab.getwidth((yyvsp[(6) - (7)].index))>typetab.getwidth((yyvsp[(4) - (7)].index)))
			fprintf(stderr,"L%d: %s is too large for type of width %d\n",
			yylineno,numtab.getstr((yyvsp[(6) - (7)].index)),typetab.getwidth((yyvsp[(4) - (7)].index)));
      		tmp=csttab.add((yyvsp[(4) - (7)].index),(yyvsp[(6) - (7)].index));
		vartab.add((yyvsp[(2) - (7)].charP),CST,tmp,yylineno);
	}
;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 517 "nml.y"
    {(yyval.index)=numtab.add(0);;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 518 "nml.y"
    {mpz_class tmp;tmp=(yyvsp[(2) - (2)].charP);(yyval.index)=numtab.add(tmp);;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 519 "nml.y"
    {mpz_class tmp;tmp.set_str((yyvsp[(2) - (2)].charP),0);(yyval.index)=numtab.add(tmp);;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 520 "nml.y"
    {mpz_class tmp;tmp.set_str((yyvsp[(2) - (2)].charP),0);(yyval.index)=numtab.add(tmp);;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 523 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(1) - (1)].charP));
	(yyval.index)=0;
	if(!tmp)
		fprintf(stderr,"L%d: Can not find type %s\n",yylineno,(yyvsp[(1) - (1)].charP));
	else if(vartab.gettype(tmp)!=TYPE)
		fprintf(stderr,"L%d: %s is not defined as type\n",yylineno,(yyvsp[(1) - (1)].charP));
	else (yyval.index)=vartab.getval(tmp);
;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 533 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (6)].charP));
	int t=enumtab.addentfin();
	if(!tmp)
		vartab.add((yyvsp[(2) - (6)].charP),ENUM,t,yylineno);
	else fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,(yyvsp[(2) - (6)].charP),vartab.getdefline(tmp));
	enumtab.clearent();
;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 546 "nml.y"
    {
	if(!enumtab.addent((yyvsp[(1) - (3)].charP),(yyvsp[(2) - (3)].charP),(yyvsp[(3) - (3)].index)))
		fprintf(stderr,"L%d:Enum entry %s already defined\n",yylineno,(yyvsp[(1) - (3)].charP));
;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 551 "nml.y"
    {(yyval.charP)=NULL;;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 552 "nml.y"
    {(yyval.charP)=(yyvsp[(1) - (1)].charP);;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 555 "nml.y"
    {(yyval.index)=-1;;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 556 "nml.y"
    {
	mpz_class tmp=inttab.getans();
	if(tmp<0)
	{
		fprintf(stderr,"L%d:Value set for enum cannot be negative\n",yylineno);
		(yyval.index)=-1;
	}
	else (yyval.index)=tmp.get_si();
	inttab.clear();
;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 567 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(2) - (5)].charP));
	if(tmp)
		fprintf(stderr,"L%d: %s previous defined at line %d\n",yylineno,(yyvsp[(2) - (5)].charP),vartab.getdefline(tmp));
	else
	{
		mpz_class tmp=inttab.getans();
		int t=numtab.add(tmp);
		inttab.clear();
		vartab.add((yyvsp[(2) - (5)].charP),DEF,t,yylineno);
	}
;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 580 "nml.y"
    { inttab.vadd(); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 581 "nml.y"
    { inttab.vsub(); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 582 "nml.y"
    { inttab.vmul(); ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 583 "nml.y"
    { inttab.vdiv(); ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 584 "nml.y"
    { inttab.vneg() ; ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 585 "nml.y"
    {inttab.vpow();;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 586 "nml.y"
    { ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 587 "nml.y"
    { inttab.add((yyvsp[(1) - (1)].charP)) ; ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 588 "nml.y"
    {
		inttab.add(numtab.getval(vartab.getval(vartab.find((yyvsp[(1) - (1)].charP)))));
		;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 593 "nml.y"
    {
	int tmp=vartab.find((yyvsp[(1) - (1)].charP));
	(yyval.charP)=0;
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,(yyvsp[(1) - (1)].charP));
	else (yyval.charP)=(yyvsp[(1) - (1)].charP);
;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 601 "nml.y"
    {
	(yyval.charP)=(yyvsp[(1) - (1)].charP);
;}
    break;



/* Line 1464 of yacc.c  */
#line 2455 "nml.tab.c"
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



/* Line 1684 of yacc.c  */
#line 604 "nml.y"

void yyerror(const char *s)
{
	fprintf (stderr, "L%d: %s\n",yylineno,s);
}

