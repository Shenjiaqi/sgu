%{
#include <gmpxx.h>
#include "nml.tab.h"
#include "front.h"
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
%}
	//%option noyywrap
letter				[a-zA-Z_]
digit				[0-9]
bin				[01]
hex				[0-9a-fA-F]
alpha				[0-9a-zA-Z_]
identifier			{letter}{alpha}*
int_constant			{digit}+
fixed_constant			{digit}+"."{digit}+
binary_constant			0b{bin}+
hex_constant			0x{hex}+
blank				[ \t]
string_constant			\"([^\"]|(\\.))*\"
%x IN_COMMENT
%option	yylineno
%%

{string_constant}		{
	//strip off quotes
	*(yytext+yyleng-1)='\0';
	yylval.charP=strtab.getstr(strtab.addstr(yytext+1));
	return STRING_CONST;}
\"[^\"\n]*$	{
	*(yytext+yyleng-1)='\0';
	yylval.charP=strtab.getstr(strtab.addstr(yytext));
	fprintf(stderr,"L%d: Unterminated string",yylineno);
	return STRING_CONST;
	}
{int_constant}			{yylval.charP=strtab.getstr(strtab.addstr(yytext));return INT_CONST;}
"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MUL;}
"/"				{return DIV;}
"::"				{return DCOLON;}
"image"				{return IMAGE;}
"cycles"			{return CYCLES;}
"alias"				{return ALIAS;}
"chess_pc_offset"		{return CHESS_PC_OFFSET;}
"class"				{return CLASS;}
"delay"				{return DELAY_SLOTS;}
"syntax" 			{return SYNTAX;}
"mode" 				{return MODE;}
"."				{return POINT;}
":"				{return COLON;}
"|"				{return BITOR;}
"**"				{return POW;}
"def"				{return DEF;}
"enum"				{return ENUM;}
"{"				{return LBRACE;}
"}"				{return RBRACE;}
";"				{return SEMI;}
"="				{return ASSIGN;}
"("				{return LPAREN;}
")"				{return RPAREN;}
","				{return COMMA;}
"cst"				{return CST;}
"<"				{return LESS;}
">"				{return GRT;}
"["				{return LBRACK;}
"]"				{return RBRACK;}
".."				{return DOUBLEDOT;}
"type"				{return TYPE;}
"mem"				{return MEM;}
"op"				{return OP;}
"reg"				{return REG;}
"start"				{return START;}
"unsigned"			{yylval.index=0;return VAL_TYPE;}
"signed"			{yylval.index=1;return VAL_TYPE;}
{binary_constant}		{yylval.charP=strtab.getstr(strtab.addstr(yytext));return BIN_CONST;}
{hex_constant}			{yylval.charP=strtab.getstr(strtab.addstr(yytext));return HEX_CONST;}


{blank}				{}


{identifier}			{yylval.charP=strtab.getstr(strtab.addstr(yytext));
				int tmp=vartab.find(yylval.charP);
				if(tmp)
				{
					switch(vartab.gettype(tmp))
					{
						case ENUM : return ENUM_NAME;
						default: /*PE;*/break;
					}
				}
				return IDENTIFIER;}

\n				{}

"//"[^\n]*			{}
<INITIAL>{
"/*"              BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"      BEGIN(INITIAL);
[^*\n]+   // eat comment in chunks
"*"       // eat the lone star
\n        //yylineno++;
}
.				{fprintf(stderr,"L%d: INVALID TOKEN \"%s\"\n",yylineno,yytext);}

%%
int yywrap()
{
	return 1;
}
