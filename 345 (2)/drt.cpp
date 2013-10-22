#include "syntax_table.h"
#include "par_table.h"
#include "opn_table.h"
#include "ormode_table.h"
#include "oropn_table.h"
#include "var_table.h"
#include "nml.tab.h"
#include "op_image.h"
#include "or_table.h"
#include "enum_table.h"
#include "string_table.h"
#include "hash.h"
#include <string>
#include <cstring>
#include <cstdlib>
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
using namespace std;
class rule
{
private:
	opn_table * ar;
	par_table * pr;
	syntax_trm_c * sync;
	ormode_table *orm;
	oropn_table *oro;
	var_table * var;
	op_image * oi;
	or_table * ot;
	enum_table * et;
	string_table * st;
	const char * startrule;
	hash_control tokengen;
	FILE * tokenfile;
	FILE * rulefile;
	FILE * lexfile;
	FILE * typefile;
#define DONE(a) ((a)==3)
#define ING(a) ((a)==2)
#define NOTYET ((a)==0)
#define SETDONE(a) (a=3)
#define SETING(a) (a=2)
#define SETNOTYET(a) (a=0)
	int *v;
public:
	rule(opn_table * ont,var_table * vt,par_table *pt,syntax_trm_c * stc,const char * sr,op_image * oit,or_table *otable,enum_table * et,string_table *st,oropn_table *ortable);
	~rule();
	int spr(int k);
	int gen_enum(int v);
	int gen_str(const char *v);
	int gen_ruleref(const char * str);
	void gen_andrule_img_beg(int num);
	void gen_andrule_img_end();
	int gen_str_r(const char *c);
	int gen_ruleref_r(int v);
	int gen_ot_ref(const char * name);
	void gen_rule_beg(const char *type,const char * n);
	void gen_rule_end();
	void gen();
	void gen_and_rule(int k);
	void gen_or_rule(int k);
	void end();
};
void rule::gen()
{
	spr(var->find(startrule));
}
void rule::gen_rule_end()
{
	fprintf(rulefile,"\n;");
}
void rule::gen_rule_beg(const char *type,const char *n)
{
	fprintf(rulefile,"\nrule_%s:",n);
	fprintf(typefile,"\n%%type <%s> rule_%s",type,n);
}
int rule::gen_ot_ref(const char * name)
{
}
int rule::gen_str_r(const char *c){
}
int rule::gen_ruleref_r(int v){}
void rule::gen_andrule_img_beg(int num)
{
	fprintf(rulefile,"\n{ $$ = strsta.newstr(");
}
void rule::gen_andrule_img_end()
{
	fprintf(rulefile,");}");
}
rule::rule(opn_table * ont,var_table * vt,par_table * pt,syntax_trm_c * stc,const char * sr,op_image * oit,or_table * otable,enum_table * etable,string_table * stable,oropn_table *ortable)
{
	ar=ont;
	int size=ar->getsize();
	v=new int[size+1];
	for(int i=0;i<size;++i)
		SETNOTYET(v[i]);

	oro=ortable;

	st=stable;

	et=etable;
	
	var=vt;

	sync=stc;

	pr=pt;

	startrule=sr;

	oi=oit;

	ot=otable;

	tokenfile=fopen("tokenfile","w+");
	rulefile=fopen("rulefile.y","w+");
	lexfile=fopen("lexfile.l","w+");
	fprintf(lexfile,"%%{\n#include \"y.h\"\n%%}\n\n%%%%\n");
	typefile=fopen("typefile","w+");
}
void rule::end()
{
	FILE * yfile=fopen("y.y","w");
	fprintf(yfile,"%%{\n#include <cstdio>\n\
#include \"strstack.h\"\n\
extern int yylineno;\n\
extern void yyerror(const char *s);\n\
extern strstack strsta;\n\
extern int yylex(void);\n%%}\n\
%%union{\n\
int idx;\n\
}\n");
	fprintf(yfile,"\n%%token\n");
	fseek(tokenfile,0,SEEK_SET);
	char buf[4096];
	for(;NULL!=fgets(buf,sizeof(buf),tokenfile);)
		fputs(buf,yfile);
	fseek(typefile,0,SEEK_SET);
	fprintf(yfile,"\n");
	for(;NULL!=fgets(buf,sizeof(buf),typefile);)
		fputs(buf,yfile);
	fprintf(yfile,"\n\n%%start rule_%s\n",startrule);
	fprintf(yfile,"\n%%%%\n");
	fseek(rulefile,0,SEEK_SET);
	for(;NULL!=fgets(buf,sizeof(buf),rulefile);)
		fputs(buf,yfile);
	fprintf(yfile,"\n%%%%\n\
void yyerror(const char *s)\n\
{\n\
	fprintf (stderr, \"L%%d: %%s\\n\",yylineno,s);\n\
}\n");
	fprintf(lexfile,"\n[ \\t]\t{}\n");
	fprintf(lexfile,"\n%%%%\n\
int yywrap()\n\
{\n\
	return 1;\n\
}");
}
rule::~rule()
{
	delete []v;
}
int rule::gen_enum(int v)
{
	gen_rule_beg("idx",var->getname(v));
	int k=var->getval(v);
	int enumsize=et->getentsize(k);
	int width=et->getwidth(k);
	for(int i=1;i<enumsize;++i)
	{
		int r;
		const char * c;
		et->getinfo(k,i,&r,NULL,&c);
		gen_str(c);
		fprintf(rulefile,"\t{ $$ = strsta.newstr((string)\"");
		for(int j=1<<(width-1);j;j>>=1)
			if(j&r)
				fprintf(rulefile,"1");
			else fprintf(rulefile,"0");
		fprintf(rulefile,"\");}");
		if(i!=enumsize-1)
			fprintf(rulefile,"|\n");
	}
	gen_rule_end();
}
int rule::gen_str(const char *v)
{
	int u=st->addstr(v);
	if(!tokengen.find(v))
	{
		tokengen.insert(v,1);
		fprintf(tokenfile,"\ntok_%d/*%s*/",u,v);
		fprintf(lexfile,"\n\"%s\"\t{return tok_%d/*%s*/;}",v,u,v);
	}
	fprintf(rulefile," tok_%d /*%s*/",u,v);
}
int rule::gen_ruleref(const char * name)
{
	fprintf(rulefile," rule_%s",name);
}
void rule::gen_or_rule(int k)
{
			int opor=var->getval(k);
			int para=oro->getpara(opor);
			int parasize=0;
			for(int i=para;;++i,++parasize)
			{
				const char * name=pr->getval(i);
				if(name==NULL)
					break;
	//			printf("%d %s\n",i,name);
				int id=var->find(name);
				int type=var->gettype(id);
				if(type==OP_OR_RULE || type==OP_AND_RULE ||
				type==MODE_OR_RULE || type==MODE_AND_RULE)
					spr(id);
			}
			gen_rule_beg("idx",var->getname(k));
			bool * orruleimg=(bool*)calloc(sizeof(bool),parasize+1);
			int img=oro->getval(opor);
			int imgentrysize=ot->getentrysize(img)-1;
			string action;
			for(int i=1;i<imgentrysize;++i)
			{
				int entsize=ot->getentsize(img,i);
				int pri=0;
				action.clear();
				for(int j=1;j<entsize;++j)
				{
					int type=ot->gettype(img,i,j);
					switch(type)
					{
						case STRING_CONST: //gen_str_r(st->getstr(ot->getval(img,i,j)));break;
							action+=" (string)";
							action+=(string)st->getstr(ot->getval(img,i,j));
							break;
						//case ENUM:
						case RULE_REF:
							if(pri)/*TODO check at front end*/
								PE
							else
							{
								pri=ot->getval(img,i,j);
								//printf("pri %d %d\n",pri,para);
								if(orruleimg[pri-para])
									PE/*TODO check at front end*/
								else
								{
									orruleimg[pri]=1;
									//gen_ot_ref(pr->getname(para+pri));
									fprintf(rulefile," rule_%s",pr->getval(pri));
									action+=" strsta.getstr($1)";
								}
							}
							break;
						default: PE;break;
					}
					if(j!=entsize-1)
						action+=(string)"+";
				}
				fprintf(rulefile,"{$$=strsta.newstr(%s);}",action.c_str());
				if(i!=imgentrysize-1)
					fprintf(rulefile,"|\n");
			}
			gen_rule_end();
}
void rule::gen_and_rule(int k)
{
			int opn=var->getval(k);
			int par=ar->getpara(opn);
			int nvar=0;
			for(int i=par;;++i,++nvar)
			{
				const char * parname=pr->getval(i);
				if(parname==NULL)
					break;
				//printf("!%s\n",parname);
				int rl=var->find(parname);
				int type=var->gettype(rl);
				if(type==OP_AND_RULE || type==OP_OR_RULE||
					type==MODE_AND_RULE || type==MODE_OR_RULE || type==ENUM)
				spr(rl);
			}
			gen_rule_beg("idx",var->getname(k));
			int *varinsyn=(int*)calloc((nvar+1),sizeof(int));
			int syn=ar->getsyn(opn);
			int synsize=sync->getelesize(syn,1/*TODO no other alternatives*/);
			for(int i=1;i<synsize;++i)
			{
				int type=sync->geteletype(syn,1,i);
				int varnum;
				switch(type)
				{
					case STRING_CONST: gen_str(st->getstr(sync->geteleval(syn,1,i)));break;
					case RULE_REF: 
						varnum=sync->geteleval(syn,1,i);
						if(varinsyn[varnum-par+1])
							PE;//check should be done at front end
						gen_ruleref(pr->getval(varnum));
						varinsyn[varnum-par+1]=i;
						break;
					default: PE;break;
				}
			}
			
			int img=ar->getimg(opn);
			int imgsize=oi->getaltsize(img,1);
			gen_andrule_img_beg(imgsize);
			for(int i=1;i<imgsize;++i)
			{
				int type=oi->getalttype(img,1,i);
				switch(type)
				{
					case STRING_CONST: //gen_str_r(st->getstr(oi->getaltval(img,1,i)));break;
					fprintf(rulefile," (string)\"%s\"",st->getstr(oi->getaltval(img,1,i)));
					break;
					case ENUM:
					case RULE_REF: //gen_ruleref_r(varinsyn[oi->getaltval(img,1,i)-par]);break;
					printf("varinsyn %d %d\n",par,oi->getaltval(img,1,i));
					fprintf(rulefile," strsta.getstr($%d)",varinsyn[oi->getaltval(img,1,i)-par+1]);
					break;
					default: PE;break;
				}
				if(i!=imgsize-1)
					fprintf(rulefile,"+");
			}
			gen_andrule_img_end();
			free(varinsyn);
			gen_rule_end();
}
int rule::spr(int k)
{
	if(DONE(v[k]))
		return 0;

	printf("%d %s\n",k,var->getname(k));

	if(ING(v[k]))
	{
		fprintf(stderr,"loop encountered\n");
		return 1;
	}
	SETING(v[k]);

	int type=var->gettype(k);
	if(type==ENUM)
	{
		gen_enum(k);
	}
	else
	{
	
		if(type==OP_AND_RULE || type==MODE_AND_RULE)
		{
			gen_and_rule(k);
		}
		else if(type==OP_OR_RULE)
		{
			gen_or_rule(k);
		}
		else PE
	}
	SETDONE(v[k]);
}
