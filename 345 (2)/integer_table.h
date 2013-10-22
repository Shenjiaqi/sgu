#ifndef __INTEGER_TABLE__
#define __INTEGER_TABLE__

#include <gmpxx.h>
#include <vector>
using namespace std;

class integer_table
{
private:
	vector<mpz_class> list;
public:
	void clear();
	int add(const char *v);
	int add(mpz_class v);
	void vadd();
	void vsub();
	void vmul();
	void vdiv();
	void vneg();
	void vpow();
	mpz_class getans();
};

#endif
