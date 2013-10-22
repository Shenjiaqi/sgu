#include "hash.h"
#include <cstdio>
#include "outputf.h"
#include <vector>
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_VAR_TABLE
class var_entry
{
private:
	const char * name;
	int type;
	int val;
	int defline;
public:
	var_entry(const char * n,int t,int v,int d){name=n,type=t,val=v,defline=d;};
	const char * getname(){return name;};
	int getlineno();
	int getval();
	int gettype();
	void setval(int v){val=v;};
};
int var_entry::gettype()
{
	return type;
}
int var_entry::getlineno()
{
	return defline;
}
int var_entry::getval()
{
	return val;
}
class var_table
{
private:
	vector<var_entry> varlist;
	class hash_control nametable;
public:
	int add(const char * n,int t,int v,int d);
	int find(const char * str);
	var_table(){varlist.push_back( var_entry( NULL,0,0,0 ));};
	int getdefline(int i);
	int getval(int i);
	int chgval(int n,int v);
	int gettype(int i);
	void output_h(FILE *file,int l,bool h);
	const char * getname(int i);
};
void var_table::output_h(FILE *file,int l,bool h)
{
	int size=varlist.size();
	mprint(-1,h,file,"var_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: name: %s  type: %d  val: %d  defineline: %d\n",i,
		varlist[i].getname(),varlist[i].gettype(),varlist[i].getval(),varlist[i].getlineno());
	}
	delx(l);
	delid();
}
int var_table::getval(int i)
{
#ifdef DBG_VAT_TABLE
	if(i<=0 || i>=varlist.size())
	{
		PE
		return 0;
	}
#endif
	return varlist[i].getval();
}
int var_table::add(const char * n,int t,int v,int d)
{
#ifdef DBG_VAR_TABLE
	if(nametable.find(n))
	{
		PE
		return 0;
	}
#endif
	varlist.push_back( var_entry(n,t,v,d) );
	int tmp=varlist.size()-1;
	nametable.insert(n,tmp);
	return tmp;
}
int var_table::chgval(int n,int v)
{
#ifdef DBG_VAR_TABLE
	if(!n || n>=varlist.size())
	{
		PE
		return 0;
	}
#endif
	int tmp=varlist[n].getval();
	varlist[n].setval(v);
	return tmp;
}
int var_table::find(const char *str)
{
	return nametable.find(str);
}

int var_table::getdefline(int i)
{
#ifdef DBG_VAR_TABLE
	if(i<=0 || i>=varlist.size())
	{
		PE
		return 0;
	}
#endif
	return varlist[i].getlineno();
}
int var_table::gettype(int i)
{
#ifdef DBG_VAR_TABLE
	if(i<=0 || i>=varlist.size())
	{
		PE
		return 0;
	}
#endif
	return varlist[i].gettype();
}
const char * var_table::getname(int i)
{
#ifdef DBG_VAR_TABLE
	if(i<=0 || i>=varlist.size())
	{
		PE
		return 0;
	}
#endif
	return varlist[i].getname();
}
