#ifndef __ENUM_TABLE__
#define __ENUM_TABLE__
//-------------------------------------------------------
class enum_table_ent
{
private:
	const char * mnemonic;
	const char * name;
	int val;
public:
	enum_table_ent(const char * n,const char * m,int v){name=n,mnemonic=m,val=v;};
	const char * getname();
	const char * getmne();
	size_t get_width();
	void setval(int v){val=v;};
	int getval(){return val;};
	void setname(const char * n){name=n;};
	void setmne(const char *n){mnemonic=n;};
	void getinfo(int *v,const char **n,const char **m);
};
//-------------------------------------------------------
class enum_table_term
{
public:
	vector< enum_table_ent > list;
	size_t width;
	
	enum_table_term(){width=1;list.push_back(enum_table_ent(NULL,NULL,0));};
	int addent(const char * n,const char * m,int v);
	int findent(const char * n);
	void clearent();
	void fin();
	void output_h(FILE *file,int l,bool h);
	int getval(int i);
	const char * getname(int i);
	const char * getmne(int i);
	void getinfo(int i,int *v,const char **n,const char **m);
	int getentsize();
	int getwidth();
};
//-------------------------------------------------------
class enum_table
{
private:
	vector < enum_table_term > list;
	//class hash_control table;
public:
	enum_table();
	void clear();
	int addent(const char * n,const char * m,int v);
	int findent(int i,const char *n);
	int addentfin();
	void clearent();
	void output_h(FILE *file,int l,bool h);
	int getval(int e,int i);
	const char * getname(int e,int i);
	const char * getmne(int e,int i);
	void getinfo(int e,int i,int *v,const char **n,const char **m);
	int getentsize(int i);
	int getwidth(int i);
};
#endif
