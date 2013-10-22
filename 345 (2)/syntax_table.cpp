#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_SYNTAX_TABLE
class syntax_ref_c
{
public:
	int type;
	int val;
	int idx;
	syntax_ref_c(int t=0,int v=0,int i=0){type=t,val=v,idx=i;};
	int gettype(){return type;};
	int getval(){return val;};
	int getidx(){return idx;};
};
class syntax_ent_c
{
public:
	vector<syntax_ref_c> list;
	int addele(syntax_ref_c src);
	syntax_ent_c(){list.push_back(syntax_ref_c(0,0,0));};
	void output_h(FILE *file,int l,bool h);
	int getsize();
	int geteleval(int i);
	int geteletype(int i);
};
int syntax_ent_c::geteletype(int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].gettype();
}
int syntax_ent_c::geteleval(int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getval();
}
int syntax_ent_c::getsize()
{
	return list.size();
}
void syntax_ent_c::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"syntax_ent_c size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: type:%d  val:%d  idx:%d\n",i,list[i].gettype(),list[i].getval(),list[i].getidx());
	}
	delx(l);
	delid();
}
int syntax_ent_c::addele(syntax_ref_c src)
{
	list.push_back(src);
	return list.size()-1;
}
class syntax_alt_c
{
public:
	vector<syntax_ent_c> list;
	int addele(syntax_ref_c src);
	int addalt();
	syntax_alt_c(){list.push_back(syntax_ent_c());list.push_back(syntax_ent_c());};
	void output_h(FILE *file,int l,bool h);
	int getelesize(int a);
	int geteleval(int a,int i);
	int geteletype(int a,int i);
};
int syntax_alt_c::geteletype(int a,int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].geteletype(i);
}
int syntax_alt_c::geteleval(int a,int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].geteleval(i);
}
int syntax_alt_c::getelesize(int a)
{
#ifdef DBG_SYNTAX_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].getsize();
}
void syntax_alt_c::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-1;
	mprint(-1,h,file,"syntax_trm_c size: %d\n",size-1);
	addid();
	for(int i=1;i<size;++i)
	{
		if(i==1) addx(l);
		mprint(l,h,file,"%d:\n",i);
		if(i==size-1) delx(l);
		list[i].output_h(file,1+l,h);
	}
	delid();
}
int syntax_alt_c::addele(syntax_ref_c src)
{
	int tmp=list.size()-1;
	return list[tmp].addele(src);
	
}
int syntax_alt_c::addalt()
{
	list.push_back(syntax_ent_c());
	return list.size()-2;
}
class syntax_trm_c
{
private:
	vector <syntax_alt_c> list;
public:
	syntax_trm_c(){list.push_back(syntax_alt_c());list.push_back(syntax_alt_c());};
	int addalt();
	int addele(syntax_ref_c src);
	int addtrm();
	void output_h(FILE *file,int l,bool h);
	int getelesize(int t,int a);
	int geteleval(int t,int a,int i);
	int geteletype(int t,int a,int i);
};
int syntax_trm_c::geteletype(int t,int a,int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].geteletype(a,i);
}
int syntax_trm_c::geteleval(int t,int a,int i)
{
#ifdef DBG_SYNTAX_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].geteleval(a,i);
}
int syntax_trm_c::getelesize(int t,int a)
{
#ifdef DBG_SYNTAX_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getelesize(a);
}
void syntax_trm_c::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-2;
	mprint(-1,h,file,"syntax_trm_c size: %d\n",size-1);
	addid();
	for(int i=1;i<size;++i)
	{
		if(i==1) addx(l);
		mprint(l,h,file,"%d:\n",i);
		if(i==size-1) delx(l);
		list[i].output_h(file,1+l,h);
	}
	delid();
}
int syntax_trm_c::addalt()
{
	int tmp=list.size()-1;
	return list[tmp].addalt();
}
int syntax_trm_c::addele(syntax_ref_c src)
{
	int tmp=list.size()-1;
	return list[tmp].addele(src);
}
int syntax_trm_c::addtrm()
{
	list.push_back(syntax_alt_c());
	list.push_back(syntax_alt_c());
	return list.size()-3;
}
