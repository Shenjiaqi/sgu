#ifndef __ORMODE_TABLE__
#define __ORMODE_TABLE__
#include <vector>
using namespace std;
class ormode_table_ent
{
private:
	int param;
	int val;
public:
	int getparam(){return param;};
	int getval(){return val;};
	ormode_table_ent(int p,int v){param=p,val=v;};
};
class ormode_table
{
private:
	vector<ormode_table_ent> list;
public:
	ormode_table(){list.push_back(ormode_table_ent(0,0));};
	int add(int p,int v);
	void output_h(FILE * file,int l,bool h);
};
#endif
