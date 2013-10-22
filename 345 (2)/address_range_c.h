#ifndef __ADDRESS_RANGE_C__
#define __ADDRESS_RANGE_C__
#include <vector>
#include <cstdio>
using namespace std;
class address_range_c_ent
{
public:
	int beg;
	int end;
	address_range_c_ent(int b,int e){beg=b,end=e;};
	int getbeg(){return beg;};
	int getend(){return end;};
};
class address_range_c
{
private:
	vector<address_range_c_ent> list;
public:
	address_range_c(){list.push_back(address_range_c_ent(0,0));};
	int add(int b,int e);
	void output_h(FILE *file,int l,bool h);
};
#endif
