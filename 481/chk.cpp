#include <iostream>
#include <gmpxx.h>
using namespace std;
int main()
{
  int n;
  freopen("in","r",stdin);
  freopen("o1","w",stdout);
  scanf("%d",&n);
  mpz_class ans(0);
  for(int i=3;i<n;++i)
    {
      mpz_class a=n;
      for(int j=n-1;j>n-i;--j)
	a*=j;
      mpz_class b=1;
      for(int j=0;j<n-i-1;++j)
	b*=n;
      ans+=a*b;
    }
  mpz_class b=1;
  for(int i=1;i<n;++i)
    b*=i;
  ans+=b;
  cout<<(ans/2);
  return 0;
}
