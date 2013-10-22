#include <gmpxx.h>
#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
class cst_table_ent
{
private:
	int type;
	int val;//->numtab
public:
	cst_table_ent(int t,int v){type=t,val=v;};/*TODO check*/
	int gettype(){return type;};
	int getval(){return val;};
};

class cst_table
{
private:
	vector<cst_table_ent> list;
public:
	cst_table(){list.push_back(cst_table_ent(0,0));};
	int add(int t,int v);
	void output_h(FILE *file,int l,bool h);
};
void cst_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"cst_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: type: %d  val: %d\n",i,list[i].gettype(),list[i].getval());
	}
	delx(l);
	delid();
}
int cst_table::add(int t,int v)
{
	list.push_back(cst_table_ent(t,v));
	return list.size()-1;
}
