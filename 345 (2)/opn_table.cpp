#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_OPN_TABLE
class opn_tab_entry
{
private:
	int para;
	int syn;
	int img;
public:
	opn_tab_entry(int p,int s,int i){para=p,syn=s,img=i;};
	int getpara(){return para;};
	int getsyn(){return syn;};
	int getimg(){return img;};
};
class opn_table
{
private:
	vector<opn_tab_entry> list;
public:
	opn_table(){list.push_back(opn_tab_entry(0,0,0));};
	int add(int p,int s,int i);
	void output_h(FILE *file,int l,bool h);
	int getsize();
	int getpara(int i);
	int getsyn(int i);
	int getimg(int i);
};
int opn_table::getpara(int i)
{
#ifdef DBG_OPN_TABLE
	if(i<=0 || i>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[i].getpara();
}
int opn_table::getsyn(int i)
{
#ifdef DBG_OPN_TABLE
	if(i<=0 || i>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[i].getsyn();
}
int opn_table::getimg(int i)
{
#ifdef DBG_OPN_TABLE
	if(i<=0 || i>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[i].getimg();
}
int opn_table::getsize()
{
	return list.size();
}
void opn_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"opn_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: para: %d  syn: %d  img: %d\n",i,list[i].getpara(),list[i].getsyn(),list[i].getimg());
	}
	delx(l);
	delid();
}
int opn_table::add(int p,int s,int i)
{
	list.push_back(opn_tab_entry(p,s,i));
	int j=list.size()-1;
	return list.size()-1;
}
