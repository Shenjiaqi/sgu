#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_OROPN_TABLE
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
int oropn_table::getpara(int i)
{
#ifdef DBG_OROPN_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getparam();
}
int oropn_table::getval(int i)
{
#ifdef DBG_OROPN_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getval();
}
void oropn_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"oropn_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: param:%d  val:%d\n",i,list[i].getparam(),list[i].getval());
	}
	delx(l);
	delid();
}
int oropn_table::add(int p,int v)
{
	list.push_back(oropn_table_ent(p,v));
	return list.size()-1;
}
