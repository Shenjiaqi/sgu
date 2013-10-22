#include <vector>
#include "outputf.h"
#include <cstdio>
using namespace std;
class address_ent
{
public:
	int range;
	int step;
	address_ent(int r,int s){range=r,step=s;};
	int getrange(){return range;};
	int getstep(){return step;};
};
class address_table
{
private:
	vector<address_ent> list;
public:
	address_table(){list.push_back(address_ent(0,0));};
	int add(int addrange,int step);
	void output_h(FILE *file,int l,bool h);
};
void address_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"address_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: range: %d  step: %d\n",i,list[i].getrange(),list[i].getstep());
	}
	delx(l);
	delid();
}
int address_table::add(int addrange,int step)
{
	list.push_back(address_ent(addrange,step));
	return (list.size()-1);
}
