#ifndef __ADDRESS_TABLE__
#define __ADDRESS_TABLE__
#include <cstdio>
#include "outputf.h"
class address_ent
{
public:
	int range;
	int step;
	address_ent(int r,int s){range=r,step=s;};
	int getrange(){return range;};
	int getstep(){return step;};
};
class address_table
{
private:
	vector<address_ent> list;
public:
	address_table(){list.push_back(address_ent(0,0));};
	int add(int addrange,int step);
	void output_h(FILE *file,int l,bool h);
};
#endif
