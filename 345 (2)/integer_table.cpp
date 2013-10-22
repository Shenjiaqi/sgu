#include <gmpxx.h>
#include <vector>
using namespace std;
#define PE {printf("INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_INTEGER_TABLE
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
void integer_table::clear()
{
	list.clear();
}
int integer_table::add(const char *v)
{
	list.push_back(mpz_class(v));
}
int integer_table::add(mpz_class v)
{
	list.push_back(v);
}
void integer_table::vadd()
{
	int tmp=list.size()-1;
	if(tmp<1)
	{
		PE
		return ;
	}
	list[tmp-1]+=list[tmp];
	list.pop_back();
}
void integer_table::vsub()
{
	int tmp=list.size()-1;
	if(tmp<1)
	{
		PE;
		return ;
	}
	list[tmp-1]-=list[tmp];
	list.pop_back();
}
void integer_table::vmul()
{
	int tmp=list.size()-1;
	if(tmp<1)
	{
		PE
		return ;
	}
	list[tmp-1]*=list[tmp];
	list.pop_back();
}
void integer_table::vdiv()
{
	int tmp=list.size()-1;
	if(tmp<1)
	{
		PE
		return ;
	}
	list[tmp-1]/=list[tmp];
	list.pop_back();
}
void integer_table::vneg()
{
	int tmp=list.size()-1;
	if(tmp<0)
	{
		PE
		return ;
	}
	list[tmp]=-list[tmp];
}
void integer_table::vpow()
{
	int tmp=list.size()-1;
	if(tmp<1)
	{
		PE
		return ;
	}
	if(!(list[tmp].fits_ulong_p()))
	{
		fprintf(stderr,"exponent too big\n");
		PE
		return;
	}
	mpz_pow_ui(list[tmp-1].get_mpz_t(),list[tmp-1].get_mpz_t(),(unsigned long int)list[tmp].get_ui());
	list.pop_back();
}
mpz_class integer_table::getans()
{
	if(list.size()<=0)
	{
		PE;
		return 0;
	}
	mpz_class tmp=list[list.size()-1];
	list.pop_back();
	return tmp;
}
