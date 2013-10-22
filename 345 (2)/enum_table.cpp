#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_ENUM_TABLE
//-------------------------------------------------------
class enum_table_ent
{
private:
	const char * mnemonic;
	const char * name;
	int val;
public:
	enum_table_ent(const char * n,const char * m,int v){name=n,mnemonic=m,val=v;};
	const char * getname();
	const char * getmne();
	size_t get_width();
	void setval(int v){val=v;};
	int getval(){return val;};
	void setname(const char * n){name=n;};
	void setmne(const char *n){mnemonic=n;};
	void getinfo(int *v,const char **n,const char **m);
};
void enum_table_ent::getinfo(int *v,const char **n,const char **m)
{
	if(v)	*v=val;
	if(n)	*n=name;
	if(m)	*m=mnemonic;
}
const char * enum_table_ent::getmne()
{
	return mnemonic;
}
size_t enum_table_ent::get_width()
{
	return (8*sizeof(int)-(__builtin_clz(val)));
}
const char * enum_table_ent::getname()
{
	return name;
}
/*enum_table_ent::enum_table_ent(const char * n,const char * m,int v)
{
	name=n;
	mnemonic=m;
	val=v;
}*/
//-------------------------------------------------------
class enum_table_term
{
public:
	vector< enum_table_ent > list;
	size_t width;
	
	enum_table_term(){width=1;list.push_back(enum_table_ent(NULL,NULL,0));};
	int addent(const char * n,const char * m,int v);
	int findent(const char * n);
	void clearent();
	void fin();
	void output_h(FILE *file,int l,bool h);
	int getval(int i);
	const char * getname(int i);
	const char * getmne(int i);
	void getinfo(int i,int *v,const char **n,const char **m);
	int getentsize();
	int getwidth();
};
int enum_table_term::getwidth()
{
	return width;
}
int enum_table_term::getentsize()
{
	return list.size();
}
void enum_table_term::getinfo(int i,int *v,const char **n,const char **m)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
	}
#endif
	list[i].getinfo(v,n,m);
}
int enum_table_term::getval(int i)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getval();
}
const char * enum_table_term::getname(int i)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getname();
}
const char * enum_table_term::getmne(int i)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getmne();
}
void enum_table_term::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"enum_table_term size: %d  width: %d\n",size-1,width);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: mnemonic: %s  name: %s  val: %d\n",i,list[i].getmne(),list[i].getname(),list[i].getval());
	}
	delx(l);
	delid();
}
void enum_table_term::fin()
{
	width=1;
	for(int i=1;i<list.size();++i)
	{
		if(list[i].getmne()==NULL)
			list[i].setmne(list[i].getname());
		if(list[i].getval()<0)
		{
			if(i==1)
				list[i].setval(0);
			else
				list[i].setval((list[i-1].getval()+1));
		}
		width=max(width,list[i].get_width());
	}
}
void enum_table_term::clearent()
{
	list.clear();
	list.push_back(enum_table_ent(NULL,NULL,0));
	width=1;
}
int enum_table_term::findent(const char *n)
{
	for(int i=1;i<list.size();++i)
		if(!strcmp(n,list[i].getname()))
			return i;
	return 0;
}
int enum_table_term::addent(const char * n,const char * m,int v)
{
	list.push_back(enum_table_ent(n,m,v));
	return (list.size()-1);
}
//-------------------------------------------------------
class enum_table
{
private:
	vector < enum_table_term > list;
	//class hash_control table;
public:
	enum_table();
	void clear();
	int addent(const char * n,const char * m,int v);
	int findent(int i,const char *n);
	int addentfin();
	void clearent();
	void output_h(FILE *file,int l,bool h);
	void getinfo(int e,int i,int *v,const char **n,const char **m);
	int getval(int e,int i);
	const char * getname(int e,int i);
	const char * getmne(int e,int i);
	int getentsize(int i);
	int getwidth(int i);
};
int enum_table::getwidth(int i)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getwidth();
}
int enum_table::getentsize(int i)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getentsize();
}
const char * enum_table::getmne(int e,int i)
{
#ifdef DBG_ENUM_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getmne(i);
}
const char * enum_table::getname(int e,int i)
{
#ifdef DBG_ENUM_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getname(i);
}
int enum_table::getval(int e,int i)
{
#ifdef DBG_ENUM_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[e].getval(i);
}
void enum_table::getinfo(int e,int i,int *v,const char **n,const char **m)
{
#ifdef DBG_ENUM_TABLE
	if(e<=0 || e>=list.size())
	{
		PE;
	}
#endif
	return list[e].getinfo(i,v,n,m);
}
void enum_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-1;
	mprint(-1,h,file,"enum_table size: %d\n",size-1);
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
int enum_table::findent(int i,const char * n)
{
#ifdef DBG_ENUM_TABLE
	if(i<=0 || i>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[i].findent(n);
}
int enum_table::addent(const char * n,const char * m,int v)
{
	int tmp=list.size()-1;
	if(list[tmp].findent(n))
		return 0;
	return list[tmp].addent(n,m,v);
}
enum_table::enum_table()
{
	list.push_back(enum_table_term());
	list.push_back(enum_table_term());
}

int enum_table::addentfin()
{
	int tmp=list.size()-1;
	list[tmp].fin();
	list.push_back(enum_table_term());
	return tmp;
}
void enum_table::clearent()
{
	int tmp=list.size()-1;
	if(tmp>0)
		list[tmp].clearent();
}
