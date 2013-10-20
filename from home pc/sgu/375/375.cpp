#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if(n&1)
    {
      int ans[33],ansi=0;
      for(;n>1;++ansi)
	{
	  int tmp=(n-1)/2;
	  ans[ansi]=1;
	  if(tmp&1)
	    n=tmp,ans[ansi]=2;
	  else n=(n+1)/2;
	}
      cout<<ansi<<endl;
      for(int i=ansi-1;i>=0;--i)
	cout<<ans[i]<<' ';
    }
  else
    cout<<"No solution";
  return 0;
}
