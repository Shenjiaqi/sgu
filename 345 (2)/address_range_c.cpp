#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
class address_range_c_ent
{
public:
	int beg;
	int end;
	address_range_c_ent(int b,int e){beg=b,end=e;};
	int getbeg(){return beg;};
	int getend(){return end;};
};
class address_range_c
{
private:
	vector<address_range_c_ent> list;
public:
	address_range_c(){list.push_back(address_range_c_ent(0,0));};
	int add(int b,int e);
	void output_h(FILE *file,int l,bool h);
};
void address_range_c::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"address_range_c size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: beg:%d  end:%d\n",i,list[i].getbeg(),list[i].getend());
	}
	delx(l);
	delid();
}
int address_range_c::add(int b,int e)
{
	list.push_back(address_range_c_ent(b,e));
	return (list.size()-1);
}
