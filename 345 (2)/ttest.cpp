#include "l.h"
extern int yylex();
extern int yyparse();
#include <string>
#include "strstack.h"
strstack strsta;
using namespace std;
int main()
{
	char buf[4096];
	
	for(;;)
	{
		fgets(buf,sizeof(buf),stdin);
		printf("%s\n",buf);
		YY_BUFFER_STATE bs=yy_scan_string(buf);
		yyparse();
		yy_delete_buffer(bs);
		printf("!%s\n",strsta.getstr(strsta.getsize()).c_str());
		strsta.clear();
	}
	return 0;
}
