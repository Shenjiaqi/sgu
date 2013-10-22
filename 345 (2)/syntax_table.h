#ifndef __SYNTAX_TABLE__
#define __SYNTAX_TABLE__
#include <vector>
#include <cstdio>
using namespace std;
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
#endif
