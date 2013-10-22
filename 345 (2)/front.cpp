#include <cstdio>
#include "string_table.h"
#include "num_table.h"
#include "var_table.h"
#include "integer_table.h"
#include "enum_table.h"
#include "cst_table.h"
#include "type_table.h"
#include "mem_table.h"
#include "address_table.h"
#include "address_range_c.h"
#include "or_table.h"
#include "oropn_table.h"
#include "par_table.h"
#include "syntax_table.h"
#include "opn_table.h"
#include "op_image.h"
#include "ormode_table.h"

#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}

ormode_table ormodetab;
op_image opimg;
opn_table opntab;
syntax_trm_c syntab;
par_table partab;
oropn_table oroptab;
or_table ortab;
address_range_c addrangetab;
address_table addrtab;
mem_table memtab;
string_table strtab;
num_table numtab;
var_table vartab;
integer_table inttab;
enum_table enumtab;
cst_table csttab;
type_table typetab;

static const char * startrule;
void setstart(const char * v)
{
	startrule=v;//TODO: no check now
}

const char * getstart()
{
	return startrule;
}

void fgx(FILE *file)
{
	fprintf(file,"\n");
	for(int i=0;i<5;++i)
		fprintf(file,"-----");
	fprintf(file,"***");
	for(int i=0;i<5;++i)
		fprintf(file,"-----");
	fprintf(file,"\n\n");
}
int output_h(const char * filename,bool h=true)
{
	if(filename==NULL)
	{
		PE;
		return 1;
	}
	FILE * file;
	if(NULL==(file=fopen(filename,"w")))
	{
		perror("");
		return 1;
	}
	
	ormodetab.output_h(file,0,h);
	
	fgx(file);

	opimg.output_h(file,0,h);
	
	fgx(file);
	
	opntab.output_h(file,0,h);
	
	fgx(file);
	
	syntab.output_h(file,0,h);
	
	fgx(file);
	
	partab.output_h(file,0,h);
	
	fgx(file);
	
	oroptab.output_h(file,0,h);
	
	fgx(file);
	
	ortab.output_h(file,0,h);
	
	fgx(file);
	
	addrangetab.output_h(file,0,h);
	
	fgx(file);
	
	memtab.output_h(file,0,h);
	
	fgx(file);
	
	addrtab.output_h(file,0,h);
	
	fgx(file);
	
	strtab.output_h(file,0,h);
	
	fgx(file);
	
	numtab.output_h(file,0,h);
	
	fgx(file);
	
	vartab.output_h(file,0,h);
	
	fgx(file);
	
//	inttab.output_h(file,0);
	enumtab.output_h(file,0,h);
	
	fgx(file);
	
	csttab.output_h(file,0,h);

	fgx(file);
	
	typetab.output_h(file,0,h);
	
}
