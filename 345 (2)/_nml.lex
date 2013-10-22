%{
#include "nml.tab.h"
extern int lineno;
%}
	//%option noyywrap
letter					[a-zA-Z_]
digit					[0-9]
bin						[01]
hex						[0-9a-fA-F]
alpha					[0-9a-zA-Z_]
identifier				{letter}{alpha}*
int_constant			"-"?{digit}+
fixed_constant			{digit}+"."{digit}+
binary_constant			0b{bin}+
hex_constant			0x{hex}+
blank					[ \t]
string_constant			\"([^\"]|(\\.))*\"
%x IN_COMMENT
%option	yylineno
%%

"primitive"				{return PRIMITIVE;}
"class"					{return CLASS;}
"int"					{return INT;}
"cst"					{return CST;}
"enum"					{return ENUM;}
"mem"					{return MEM;}
"reg"					{return REG;}
"trn"					{return TRN;}
"inport"				{return INPORT;}
"outport"				{return OUTPORT;}
"alias"					{return ALIAS;}
"align"					{return ALIGN;}
"syntax"				{return SYNTAX;}
"read"					{return READ;}
"write"					{return WRITE;}
"op"					{return OP;}
"mode"					{return MODE;}
"arbitary_order"		{return ARBITARY_ORDER;}
"image"					{return IMAGE;}
"is_exclusive"			{return IS_EXCLUSIVE;}
"make_exclusive"		{return MAKE_EXCLUSIVE;}
"align"				{return ALIGN;}
"delay_slots"			{return DELAY_SLOTS;}
"chess_pc_offset"		{return CHESS_PC_OFFSET;}
"="				{return ASSIGN;}
";"				{return SEMI;}
":"				{return COLON;}
","				{return COMMA;}
"("				{return LPAREN;}
")"				{return RPAREN;}
"{"				{return LBRACE;}
"}"				{return RBRACE;}
"["				{return LBRACK;}
"]"				{return RBRACK;}
"&&"				{return AND;}
"||"				{return OR;}
"!="				{return NEQU;}
"=="				{return EQU;}
"<"				{return LESS;}
"<="				{return LESSE;}
">"				{return GRT;}
">="				{return GRTE;}
"!"				{return NOT;}
"."				{return POINT;}
"+"				{return PLUS;}
"-"				{return MINUS;}
"|"				{return BITOR;}
"&"				{return BITAND;}
"*"				{return MUL;}
"/"				{return DIV;}
"**"			{return POW;}
"$"				{return DOLLAR;}
"::"			{return DCOLON;}
"~"				{return BITNEG;}
".."				{return DOUBLEDOT;}

{blank}
{identifier}			{yylval.charP=yytext;return IDENTIFIER;}
{int_constant}			{yylval.charP=yytext;return INT_CONST;}
{fixed_constant}		{return FIXED_CONST;}
{binary_constant}		{return BINARY_CONST;}
{hex_constant}			{return HEX_CONST;}
{string_constant}		{yy.lval.charP=yytext;return STRING_CONST;}


\n				{}

"//"[^\n]*			{}
<INITIAL>{
"/*"              BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"      BEGIN(INITIAL);
[^*\n]+   // eat comment in chunks
"*"       // eat the lone star
\n        yylineno++;
}
.				{fprintf(strerr,"INVALID TOKEN\n");}

%%
int yywrap()
{
	return 1;
}
