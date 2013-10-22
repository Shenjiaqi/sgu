#ifndef __DRT_H__
#define __DRT_H__
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
#endif
