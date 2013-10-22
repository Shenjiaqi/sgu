%{
#include <gmpxx.h>
#include "front.h"
#include <cstring>
extern int yylineno;
%}

%token ta
%token tb

%union
{
string str;
}

%type <str> aaa

%%

aaa: ta tb{};
