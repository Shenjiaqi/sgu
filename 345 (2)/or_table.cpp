#include <vector>
#include "outputf.h"
#include <cstdio>
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_OR_TABLE
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
int or_table_ent::gettype(int i)
{
#ifdef DBG_OR_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].gettype();
}
int or_table_ent::getidx(int i)
{
#ifdef DBG_OR_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getidx();
}
int or_table_ent::getval(int i)
{
#ifdef DBG_OR_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getval();
}
int or_table_ent::getsize()
{
	return list.size();
}
void or_table_ent::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"oropn_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: type:%d  val:%d  idx:%d\n",i,list[i].gettype(),list[i].getval(),list[i].getidx());
	}
	delx(l);
	delid();
}
int or_table_ent::addele(int t,int v,int i)
{
	list.push_back(or_table_ele(t,v,i));
	return list.size()-1;
}

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
int or_table_entry::gettype(int t,int i)
{
#ifdef DBG_OR_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].gettype(i);
}
int or_table_entry::getidx(int t,int i)
{
#ifdef DBG_OR_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getidx(i);
}
int or_table_entry::getval(int t,int i)
{
#ifdef DBG_OR_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getval(i);
}
int or_table_entry::getsize()
{
	return list.size();
}
int or_table_entry::getentsize(int e)
{
#ifdef DBG_OR_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getsize();
}
void or_table_entry::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-1;
	mprint(-1,h,file,"or_table_entry size: %d\n",size-1);
	addid();
	for(int i=1;i<size;++i)
	{
		if(i==1)addx(l);
		mprint(l,h,file,"%d:\n",i);
		if(i==size-1) delx(l);
		list[i].output_h(file,1+l,h);
	}
	delid();
}
int or_table_entry::addele(int t,int v,int i)
{
	int tmp=list.size()-1;
	return list[tmp].addele(t,v,i);
}
int or_table_entry::finele()
{
	list.push_back(or_table_ent());
	return list.size()-2;
}

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
int or_table::gettype(int e,int t,int i)
{
#ifdef DBG_OR_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].gettype(t,i);
}
int or_table::getval(int e,int t,int i)
{
#ifdef DBG_OR_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getval(t,i);
}int or_table::getidx(int e,int t,int i)
{
#ifdef DBG_OR_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getidx(t,i);
}
int or_table::getentrysize(int t)
{
#ifdef DBG_OR_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getsize();
}
int or_table::getentsize(int t,int e)
{
#ifdef DBG_OR_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getentsize(e);
}
void or_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-2;
	mprint(-1,h,file,"or_table size: %d\n",size-1);
	addid();
	for(int i=1;i<size;++i)
	{
		if(i==1)addx(l);
		mprint(l,h,file,"%d:\n",i);
		if(i==size-1) delx(l);
		list[i].output_h(file,1+l,h);
	}
	delid();
}
int or_table::finele()
{
	int tmp=list.size()-1;
	return list[tmp].finele();
}
int or_table::addele(int t,int v,int i)
{
	int tmp=list.size()-1;
	return list[tmp].addele(t,v,i);
}
int or_table::addent()
{
	int tmp=list.size()-1;
	list.push_back(or_table_entry());
	list.push_back(or_table_entry());
	return tmp;
}
