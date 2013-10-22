#ifndef __OR_TABLE__
#define __OR_TABLE__

#include <vector>
#include "outputf.h"
#include <cstdio>
using namespace std;

class or_table_ele
{
private:
	int type;
	int val;
	int idx;
public:
	or_table_ele(int t,int v,int i){type=t,val=v,idx=i;};
	int gettype(){return type;};
	int getval(){return val;};
	int getidx(){return idx;};
};
class or_table_ent
{
private:
	vector<or_table_ele> list;
public:
	or_table_ent(){list.push_back(or_table_ele(0,0,0));};
	int addele(int t,int v,int i);
	void output_h(FILE *file,int l,bool h);
	int getsize();
	int gettype(int i);
	int getval(int i);
	int getidx(int i);
};
class or_table_entry
{
private:
	vector<or_table_ent> list;
public:
	or_table_entry(){list.push_back(or_table_ent());list.push_back(or_table_ent());};
	int addele(int t,int v,int i);
	int finele();
	void output_h(FILE *file,int l,bool h);
	int getentsize(int e);
	int getsize();
	int gettype(int t,int i);
	int getval(int t,int i);
	int getidx(int t,int i);
};
class or_table
{
private:
	vector<or_table_entry> list;
public:
	or_table(){list.push_back(or_table_entry());list.push_back(or_table_entry());};
	int addele(int t,int v,int i);
	int addent();
	int finele();
	void output_h(FILE *file,int l,bool h);
	int getentsize(int t,int e);
	int getentrysize(int t);
	int gettype(int e,int t,int i);
	int getval(int e,int t,int i);
	int getidx(int e,int t,int i);
};
#endif
