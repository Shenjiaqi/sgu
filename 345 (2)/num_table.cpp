#include <gmpxx.h>
#include <vector>
#include <cstdio>
#include "outputf.h"
#include <cstdio>
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_NUM_TABLE
class num_table
{
private:
#define NUM_TABLE_SIZE (10000)
	vector<mpz_class> numlist;
public:
	int add(mpz_class num);
	int getwidth(int idx);
	mpz_class getval(int idx);
	num_table(){numlist.push_back(mpz_class(0));};
	const char * getstr(int idx);
	void output_h(FILE *file,int l,bool h);
};
void num_table::output_h(FILE *file,int l,bool h)
{
	int size=numlist.size();
	mprint(-1,h,file,"num_table size: %d\n",size-1);
	addid();
	addx(l);
	for(int i=1;i<size;++i)
	{
		mprint(l,h,file,"%d: num: %s\n",i,numlist[i].get_str().c_str());
	}
	delx(l);
	delid();
}
const char * num_table::getstr(int idx)
{
#ifdef DBG_NUM_TABLE
	if(idx<=0 || idx>numlist.size())
	{
		PE
		return 0;
	}
#endif
	return numlist[idx].get_str().c_str();
}
int num_table::getwidth(int idx)
{
#ifdef DBG_NUM_TABLE
	if(idx<=0 || idx>numlist.size())
	{
		PE
		return 0;
	}
#endif				//不能保证正确，还要测试
	return mpz_sizeinbase(numlist[idx].get_mpz_t(),2);
}
int num_table::add(mpz_class num)
{
	numlist.push_back(num);
	return (numlist.size()-1);
}

mpz_class num_table::getval(int idx)
{
#ifdef DBG_NUM_TABLE
	if(idx>=numlist.size() || idx<0)
	{
		PE
		return 0;
	}
#endif
	return numlist[idx];
}

