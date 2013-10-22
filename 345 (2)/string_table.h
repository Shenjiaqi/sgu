#ifndef __STRING_TABLE__
#define __STRING_TABLE__

#include "hash.h"
#include <cstdio>
#include "outputf.h"
#include <cstring>
using namespace std;
class string_table
{
private:
	class hash_control table;
	char * str;
	int poi;
public:	
	string_table();
	~string_table();
	int addstr(const char *);
	const char * getstr(int idx);
	void output_h(FILE *file,int l,bool h);
};
#endif
