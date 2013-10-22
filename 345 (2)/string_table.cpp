#include "hash.h"
#include <cstring>
#include <cstdio>
#include "outputf.h"
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG__STRING_TABLE
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
void string_table::output_h(FILE *file,int l,bool h)
{
	const char * p=str+1;
	mprint(-1,h,file,"string_table size: %d(chars&\\0)\n",poi);
	addid();
	addx(l);
	for(;p<str+poi;++p)
	{
		mprint(l,h,file,"%d: %s\n",(int)(p-str),p);
		for(;p<str+poi && *p;++p)
			;
	}
	delx(l);
	delid();
}
string_table::string_table()
{
#define STRING_TABLE_SIZE (100000<<1)
	str=new char[STRING_TABLE_SIZE+1];
	memset(str,0,(STRING_TABLE_SIZE+1)*sizeof(str[0]));
	poi=0;
}
string_table::~string_table()
{
	delete []str;
}

int string_table::addstr(const char * string)
{
	int idx=table.find(string);
	if(idx)
		return idx;
	idx=++poi;
	int len=strlen(string);
	poi+=len;
#ifdef DBG_SRRING_TABLE
	if(!poi || poi>STRING_TABLE_SIZE)
		PE
#endif
	strncpy(str+idx,string,len);
	table.insert(getstr(idx),idx);
	return idx;
}

const char * string_table::getstr(int idx)
{

#ifdef DBG_STRING_TABLE
	//if(idx>poi || idx<=0 || *(str+idx-1)!='\0') enum_table mneonic=NULL
	  if(idx>poi || idx<0 || (id>0 && *(str+idx-1)!='\0'))
		PE
#endif
	return (str+idx);
}

