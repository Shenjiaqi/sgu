#ifndef __VAR_TABLE__
#define __VAR_TABLE__

#include "hash.h"
#include <cstdio>
#include <vector>
using namespace std;
class var_entry
{
private:
	const char * name;
	int type;
	int val;
	int defline;
public:
	var_entry(const char * n,int t,int v,int d){name=n,type=t,val=v,defline=d;};
	const char * getname(){return name;};
	int getlineno();
	int getval();
	int gettype();
	void setval(int v){val=v;};
};
class var_table
{
private:
	vector<var_entry> varlist;
	class hash_control nametable;
public:
	int add(const char * n,int t,int v,int d);
	int find(const char * str);
	var_table(){varlist.push_back( var_entry( NULL,0,0,0 ));};
	int getdefline(int i);
	int getval(int i);
	int chgval(int n,int v);
	int gettype(int i);
	void output_h(FILE *file,int l,bool h);
	const char * getname(int i);
};
#endif
