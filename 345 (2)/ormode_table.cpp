#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_ORMODE_TABLE
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
int ormode_table::add(int p,int v)
{
	list.push_back(ormode_table_ent(p,v));
	return list.size()-1;
}
void ormode_table::output_h(FILE *file,int l,bool h)
{
#ifdef DBG_ORMODE_TABLE
	if(file==NULL)
	{
		PE;
		return ;
	}
#endif
	int size=list.size();
	mprint(l-1,h,file,"ormode_table size:%d\n",size-1);
	addid();
	for(int i=1;i<size;++i)
	{
		if(i==1) addx(l);
		mprint(l,h,file,"%d: param: %d  val: %d\n",i,list[i].getparam(),list[i].getval());
		if(i==size-1) delx(l);
	}
	delid();
}
