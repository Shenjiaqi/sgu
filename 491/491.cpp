#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define N 100000
typedef long long ll;
vector<int> p[N+1];
int q[N+1];
int main()
{
  int n;
  scanf("%d",&n);
  if(n==1)
    printf("0");
  else
    {
      for(int i=2;i+i<=n;++i)
	for(int j=i+i;j<=n;j+=i)
	  p[j].push_back(i);
      ll ans=n-2;
      for(int i=2;i<=n;++i)
	for(int k=n-i;k>i;k-=i)
	  if(q[k]!=i)
	    {
	      q[k]=i,++ans;
	      for(int j=p[k].size()-1;j>=0 && p[k][j]>i;--j)
		if(q[p[k][j]]!=i)
		  ++ans,q[p[k][j]]=i;
	    }
      cout<<ans;
    }
  return 0;
}
