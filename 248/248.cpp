#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,c[3],v;
ll gcd(ll x,ll y,ll & a,ll & b)
{
  if(y==0)
    {
      a=1,b=0;
      return x;
    }
  ll tmp=gcd(y,x%y,b,a);
  b-=(x/y)*a;
  return tmp;
}
ll solv(ll c1,ll c2,ll v)
{
  ll x1,x2;
  ll d=gcd(c1,c2,x1,x2);
  if(v%d)
    return -1;
  if(c1>c2)
    x1^=x2,x2^=x1,x1^=x2,
      c1^=c2,c2^=c1,c1^=c2;
  x1*=(v/d),x2*=(v/d);
  ll l1=c1/d,l2=c2/d;
  if(x1<0)
    {
      ll t=(abs(x1)+l2-1)/l2;
      x1+=t*l2;
      x2-=t*l1;
    }
  if(x2<0)
    {
      ll t=(abs(x2)+l1-1)/l1;
      x1-=t*l2;
      x2+=t*l1;
    }
  if(x1<0 || x2<0)
    return -1;
  ll t=x1/l2;
  x1-=t*l2;
  x2+=t*l1;
  return (x1+x2);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",c+i);
  scanf("%d",&v);
  int ans=-1;
  if(n==3)
    {
      for(int i=0;i*c[2]<=v;++i)
	{
	  if(ans>0 && ans<=i)
	    break;
	  int tmp=solv(c[0],c[1],v-i*c[2]);
	  if(tmp>=0)
	    if(ans<0 || ans>tmp+i)
	      ans=tmp+i;
	}
    }
  else if(n==2)
    {
      int tmp=solv(c[0],c[1],v);
      if(tmp>=0)
	ans=tmp;
    }
  else
    {
      //n==1
      if((v%c[0])==0)
	ans=v/c[0];
    }
  printf("%d",ans);
  return 0;
}
