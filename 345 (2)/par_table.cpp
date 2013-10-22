#include "hash.h"
#include <cstdio>
#include <vector>
#include "outputf.h"
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_PAR_TABLE
class param_entry
{
private:
	const char *name;
	const char * val;
public:
	param_entry(const char *n,const char * v){name=n,val=v;};
	const char * getname(){return name;};
	const char * getval(){return val;};
};
class par_table
{
private:
	hash_control table;
	vector <param_entry>list;
	int count;
public:
	par_table(){count=0;list.push_back(param_entry(0,0));};
	int add(const char * n,const char *v);
	int find(const char *n);
	int clear();
	const char * getval(int idx);
	const char * getname(int idx);
	void output_h(FILE *file,int l,bool h);
};
void par_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"par_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: name:%s  val:%s\n",i,list[i].getname(),list[i].getval());
	}
	delx(l);
	delid();
}
const char * par_table::getname(int idx)
{
#ifdef DBG_PAR_TABLE
	if(idx<=0 || idx>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[idx].getname();
}
const char * par_table::getval(int idx)
{
#ifdef DBG_PAR_TABLE
	if(idx<=0 || idx>=list.size())
	{
		PE
		return 0;
	}
#endif
	return list[idx].getval();
}
int par_table::find(const char *n)
{
	return table.find(n);
}
int par_table::add(const char *n,const char *v)
{
#ifdef DBG_PAR_TABLE
	if(find(n))
	{
		PE
		return 0;
	}
#endif
	++count;
	list.push_back(param_entry(n,v));
	int tmp=list.size()-1;
	table.insert(n,tmp);
}
int par_table::clear()
{
	for(int i=list.size()-count;i<list.size();++i)
		table.erase(list[i].getname());
	int tmp=list.size()-count;
	count=0;
	list.push_back(param_entry(0,0));
	return tmp;
}
