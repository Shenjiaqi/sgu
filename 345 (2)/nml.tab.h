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

/* Line 1685 of yacc.c  */
#line 62 "nml.y"

const char* charP;
int index;



/* Line 1685 of yacc.c  */
#line 110 "nml.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


