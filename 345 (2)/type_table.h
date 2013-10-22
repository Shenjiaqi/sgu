#ifndef __TYPE_TABLE__
#define __TYPE_TABLE__
#include <cstdio>
#include <vector>
using namespace std;
class type_ent
{
private:
	bool sign;
	size_t width;
public:
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
#endif
