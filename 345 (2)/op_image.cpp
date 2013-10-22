#include <vector>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_OPIMG_TABLE
class op_img_ele
{
	int type;
	int val;
	int idx;
public:
	op_img_ele(int t,int v,int i){type=t,val=v,idx=i;};
	int gettype(){return type;};
	int getval(){return val;};
	int getidx(){return idx;};
};
class op_img_ent
{
private:
	vector<op_img_ele> list;
public:
	op_img_ent(){list.push_back(op_img_ele(0,0,0));};
	int addele(int v,int t,int i);
	void output_h(FILE *file,int l,bool h);
	int getsize();
	int gettype(int i);
	int getval(int i);
	int getidx(int i);
};
int op_img_ent::gettype(int i)
{
#ifdef DBG_OPIMG_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].gettype();
}
int op_img_ent::getval(int i)
{
#ifdef DBG_OPIMG_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getval();
}
int op_img_ent::getidx(int i)
{
#ifdef DBG_OPIMG_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getidx();
}
int op_img_ent::getsize()
{
	return list.size();
}
void op_img_ent::output_h(FILE *file,int l,bool h)
{
	int size=list.size();
	mprint(-1,h,file,"op_img_ent size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: type:%d  val:%d  idx:%d\n",i,list[i].gettype(),list[i].getval(),list[i].getidx());
	}
	delx(l);
	delid();
}
int op_img_ent::addele(int v,int t,int i)
{
	list.push_back(op_img_ele(v,t,i));
	return list.size()-1;
}
class op_img_alt
{
private:
	vector<op_img_ent> list;
public:
	op_img_alt(){list.push_back(op_img_ent());list.push_back(op_img_ent());};
	int addele(int t,int v,int i);
	int addalt();
	void output_h(FILE *file,int l,bool h);
	int getentsize(int i);
	int getenttype(int a,int i);
	int getentval(int a,int i);
	int getentidx(int a,int i);
};
int op_img_alt::getenttype(int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].gettype(i);
}
int op_img_alt::getentval(int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].getval(i);
}
int op_img_alt::getentidx(int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].getidx(i);
}
int op_img_alt::getentsize(int i)
{
#ifdef DBG_OPIMG_TABLE
	if(i<=0 || i>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[i].getsize();
}
void op_img_alt::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-1;
	mprint(-1,h,file,"op_img_alt size: %d\n",size-1);
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
int op_img_alt::addele(int t,int v,int i)
{
	int tmp=list.size()-1;
	return list[tmp].addele(t,v,i);
}
int op_img_alt::addalt()
{
	list.push_back(op_img_ent());
	return list.size()-2;
}
class op_image
{
private:
	vector <op_img_alt> list;
public:
	op_image(){list.push_back(op_img_alt());list.push_back(op_img_alt());};
	int addele(int t,int v,int i);
	int addalt();
	int addtrm();
	void output_h(FILE *file,int l,bool h);
	int getaltsize(int a,int i);
	int getalttype(int t,int a,int i);
	int getaltval(int t,int a,int i);
	int getaltidx(int t,int a,int i);
};
int op_image::getalttype(int t,int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getenttype(a,i);
}
int op_image::getaltval(int t,int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(t<=0 || t>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getentval(a,i);
}
int op_image::getaltidx(int t,int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[t].getentidx(a,i);
}
int op_image::getaltsize(int a,int i)
{
#ifdef DBG_OPIMG_TABLE
	if(a<=0 || a>=list.size())
	{
		PE;
		return 0;
	}
#endif
	return list[a].getentsize(i);
}
void op_image::output_h(FILE *file,int l,bool h)
{
	int size=list.size()-2;
	mprint(-1,h,file,"op_image size: %d\n",size-1);
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
int op_image::addtrm()
{
	list.push_back(op_img_alt());
	list.push_back(op_img_alt());
	return list.size()-3;
}
int op_image::addalt()
{
	return list[list.size()-1].addalt();
}
int op_image::addele(int t,int v,int i)
{
	int tmp=list.size()-1;
	return list[tmp].addele(t,v,i);
}
