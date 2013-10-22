#include <cstdio>
#include <iostream>
#include "front.h"
#include "drt.h"
using namespace std;
extern int yylex();
extern int yyparse();
int main()
{
	freopen("in","r",stdin);
	yyparse();
	int tmp=vartab.find("bbb");
	output_h("output",true);
	rule rulea(&opntab,&vartab,&partab,&syntab,getstart(),&opimg,&ortab,&enumtab,&strtab,&oroptab);
	rulea.gen();
	rulea.end();
	/*
	for(int i=1;i<30;++i)
	{
		const char * c;
		enumtab.getinfo(vartab.getval(40),i,NULL,NULL,&c);
		printf("%s\n",c);
	}*/
	return 0;
}
