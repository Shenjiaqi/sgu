#include <string>
#include <cstdio>
#include <vector>
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_STRSTACK
class strstack
{
private:
	vector<string> sta;
	int n;
public:
	void clear();
	strstack();
	int newstr(string s);
	string getstr(int k);
	int getsize();
};
strstack::strstack()
{
	n=0;
}
void strstack::clear()
{
	n=0;
}
int strstack::newstr(string s)
{
	++n;
	if(n>=sta.size())
		sta.resize(n+1);
	sta[n]=s;
	return n;
}
string strstack::getstr(int k)
{
#ifdef DBG_STRSTACK
	if(k<=0 || k>n)
	{
		PE
		return sta[0];
	}
#endif
	return sta[k];
}
int strstack::getsize()
{
	return n;
}
