#ifndef __PAR_TABLE__
#define __PAR_TABLE__
#include "hash.h"
#include <cstdio>
#include <vector>
using namespace std;
class param_entry
{
private:
	const char *name;
	const char * val;
public:
	param_entry(const char *n,const char * v){name=n,val=v;};
	const char * getname(){return name;};
	const char * getval(){return val;};
};
class par_table
{
private:
	hash_control table;
	vector <param_entry>list;
	int count;
public:
	par_table(){count=0;list.push_back(param_entry(0,0));};
	int add(const char * n,const char *v);
	int find(const char *n);
	int clear();
	const char * getval(int idx);
	const char * getname(int idx);
	void output_h(FILE *file,int l,bool h);
};
#endif
