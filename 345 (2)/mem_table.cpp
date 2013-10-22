#include <gmpxx.h>
#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
class mem_ent
{
private:
	int addrng;
	int type;
	int addrtype;
public:
	mem_ent(int a,int t,int at){addrng=a,type=t,addrtype=at;};
	int getaddrng(){return addrng;};
	int gettype(){return type;};
	int getaddrtype(){return addrtype;};
};

class mem_table
{
private:
	vector<mem_ent> list;
public:
	mem_table(){list.push_back(mem_ent(0,0,0));}
	int add(int a,int t,int at,int t9,int t10,int t11,int t12);
	void output_h(FILE *file,int l,bool h);
};
void mem_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"mem_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: addrng: %d  type: %d  addrtype: %d\n",i,list[i].getaddrng(),list[i].gettype(),list[i].getaddrtype());
	}
	delx(l);
	delid();
}
int mem_table::add(int a,int t,int at,int t9,int t10,int t11,int t12)
{
	list.push_back(mem_ent(a,t,at));
	return (list.size()-1);
}
