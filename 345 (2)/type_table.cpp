#include <vector>
#include "hash.h"
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_TYPE_TABLE
class type_ent
{
public:
	bool sign;
	size_t width;
	type_ent(bool s,size_t w){sign=s,width=w;};
};

class type_table
{
private:
	vector<type_ent> list;
	class hash_control table;
public:
	int find(const char *n);
	int add(const char *n,bool s,size_t w);
	type_table(){list.push_back(type_ent(0,0));};
	int getwidth(int idx);
	void output_h(FILE *file,int l,bool h);
};
void type_table::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"type_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: signed: %d  width: %d\n",i,(int)list[i].sign,list[i].width);
	}
	delx(l);
	delid();
}
int type_table::getwidth(int idx)
{
#ifdef DBG_TYPE_TABLE
	if(idx<=0 || idx>list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[idx].width;
}
int type_table::find(const char *n)
{
	return table.find(n);
}
int type_table::add(const char *n,bool s,size_t w)
{
#ifdef DBG_TYPE_TABLE
	if(find(n))
		return 0;
#endif
	list.push_back( type_ent(s,w) );
	return (list.size()-1);
}
