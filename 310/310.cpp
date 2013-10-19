#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  cin>>n>>m>>k;
  typedef long long ll;
  ll p[1<<15]={0},q[1<<15];
  ll *pa,*pb;
  pa=p,pb=q;
  for(int i=0;i<(1<<m);++i)
    if(__builtin_popcount(i)>=k)
      pa[i]=1;
  for(int i=m;i<n;++i)
    {
      memset(pb,0,sizeof(p));
      for(int j=0;j<(1<<m);++j)
	{
	  pb[(j>>1)|(1<<(m-1))]+=pa[j];
	  if(__builtin_popcount((j>>1))>=k)
	    pb[j>>1]+=pa[j];
	}
      ll *tmp;
      tmp=pb,pb=pa,pa=tmp;
    }
  ll ans(0);
  for(int i=0;i<(1<<m);++i)
    ans+=pa[i];
  cout<<ans;
  return 0;
}
