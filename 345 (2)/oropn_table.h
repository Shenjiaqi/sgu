#ifndef __OROPN_TABLE__
#define __OROPN_TABLE__
#include <vector>
#include <cstdio>
using namespace std;
class oropn_table_ent
{
private:
	int param;
	int val;
public:
	oropn_table_ent(int p,int v){param=p,val=v;};
	int getparam(){return param;};
	int getval(){return val;};
};
class oropn_table
{
private:
	vector<oropn_table_ent> list;
public:
	oropn_table(){list.push_back(oropn_table_ent(0,0));};
	int add(int p,int v);
	void output_h(FILE *file,int l,bool h);
	int getpara(int i);
	int getval(int i);
};
#endif
