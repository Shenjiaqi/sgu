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
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 1000000
int q[N+1][2];
int gcd(int a,int b)
{
  return (b==0?a:gcd(b,a%b));
}
int po(ll a,ll b,ll p)
{
  ll r(1);
  for(ll i=1;i<=b && a!=1;i<<=1,a=(a*a)%p)
    if(i&b)
      r=(r*a)%p;
  return (int)r;
}
bool cal(int n,int p,int i)
{
  n%=(p-1);
  for(int j=1,k=(p-1)/gcd(p-1,n);p>j && k>0;++j)
    {
      int l=po(j,n,p);
      //cout<<i<<' '<<k<<' '<<j<<' '<<n<<' '<<l<<endl;
      if(q[l][0]!=i)
	{
	  --k;
	  q[l][0]=i;
	  q[l][1]=j;
	  if(l>1 && q[l-1][0]==i)
	    {
	      printf("1 %d %d",q[l-1][1],j);
	      return true;
	    }
	  if(l<p-1 && q[l+1][0]==i)
	    {
	      printf("1 %d %d",j,q[l+1][1]);
	      return true;
	    }
	}
    }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
    {
      int n,p;
      scanf("%d%d",&n,&p);
      if(!cal(n,p,i+1))
	printf("-1");
      printf("\n");
    }
  return 0;
}
