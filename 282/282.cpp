#include <cstdio>
typedef long long ll;
int nump(int a,int p)
{
  int r(0);
  if(a)
    for(;a;a/=p)
      r+=a/p;
  return r;
}
ll dep(ll a,ll p)
{
  if(a)
    for(;a%p==0;a/=p)
      ;
  return a;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,p;
  scanf("%d%d%d",&n,&m,&p);
  int a=nump(n+m-1,p)-nump(m-1,p);
  int b=nump(n,p);
  if(a>b)
    printf("0");
  else
    {
      ll ansa=1;
      for(int i=m;i<n+m;++i)
	ansa=(ansa*dep((ll)i,(ll)p))%((ll)p);
      ll ansb=1;
      for(int i=1;i<=n;++i)
	ansb=(ansb*dep((ll)i,(ll)p))%((ll)p);
      ll ansc=1;
      for(;((ansc*ansb)%(ll)p)!=1;++ansc)
	;
      ansa=(ansa*ansc)%(ll)p;
      //printf("%lld %lld\n",ansc,ansb);
      printf("%lld",ansa);
    }
  return 0;
}
