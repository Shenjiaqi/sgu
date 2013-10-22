#ifndef __CST_TABLE__
#define __CST_TABLE__
class cst_table_ent
{
private:
	int type;
	int val;
public:
	cst_table_ent(int t,int v){type=t,val=v;};/*TODO check*/
	int gettype(){return type;};
	int getval(){return val;};
};
class cst_table
{
private:
	vector<cst_table_ent> list;
public:
	cst_table(){list.push_back(cst_table_ent(0,0));};
	int add(int t,int v);
	void output_h(FILE *file,int l,bool h);
};
#endif
