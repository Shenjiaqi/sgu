#ifndef __MEM_TABLE__
#define __MEM_TABLE__
#include <vector>
using namespace std;
class mem_ent
{
private:
	int addrng;
	int type;
	int addrtype;
public:
	mem_ent(int a,int t,int at){addrng=a,type=t,addrtype=at;};
};
class mem_table
{
private:
	vector<mem_ent> list;
public:
	mem_table(){list.push_back(mem_ent(0,0,0));}
	int add(int a,int t,int at,int t9,int t10,int t11,int t12);
};
#endif
