/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 111 "_nml.y"

char *charP;
int int;



/* Line 1685 of yacc.c  */
#line 155 "_nml.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


