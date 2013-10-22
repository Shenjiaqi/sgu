#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  int l=40,r=218,k=57;
  int ans(0);
  for(int i=l;i<=r;)
    {
      int t=0;
      for(;i<=r && t<k;++i)
	{
	  int j=i;
	  for(;j>0;j/=10)
	    t+=(j%10);
	}
      if(t>=k)
	++ans;
    }
  cout<<ans;
  return 0;
}
