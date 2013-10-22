#ifndef __OP_IMAGE__
#define __OP_IMAGE__
#include <vector>
#include <cstdio>
using namespace std;
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
	void output_h(FILE *file,int l);
	int getsize();
	int gettype(int i);
	int getval(int i);
	int getidx(int i);
};
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
class op_image
{
private:
	vector <op_img_alt> list;
public:
	op_image(){list.push_back(op_img_alt());list.push_back(op_img_alt());};
	int addele(int t,int v,int i);
	int addalt();
	int addtrm();
	int output_h();
	void output_h(FILE *file,int l,bool h);
	int getaltsize(int a,int i);
	int getalttype(int t,int a,int i);
	int getaltval(int t,int a,int i);
	int getaltidx(int t,int a,int i);
};
#endif
