#ifndef __NUM_TABLE__
#define __NUM_TABLE__
#include <gmpxx.h>
#include <vector>
#include <cstdio>
using namespace std;
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
#endif
