#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
#define N 100007
typedef long long ll;
const ll mod=1000000007LL;
char tmp[3][N];
ll q[3][N];
ll rr[N+1];
ll rev(ll v)
{
  ll r=1;
  for(int i=1;i<=mod-2;i<<=1,v=(v*v)%mod)
    if(i&(mod-2))
      r=(r*v)%mod;
  return r;
}
void cal(ll a[],int num)
{
  a[0]=1;
  for(int i=1;i<=num;++i)
    a[i]=(((a[i-1]*rr[i])%mod)*(num-i+1))%mod;
}
int main()
{
  freopen("in.txt","r",stdin);
  for(int i=0;i<3;++i)
    scanf("%s",tmp[i]);
  for(int i=1;i<=N;++i)
    if(rr[i]==0)
      rr[i]=rev(i);
  int l=strlen(tmp[0]);
  int x[4]={0};
  int m[]={0,1,2,3,3,2,1,0};
  for(int i=0;i<l;++i)
    ++x[m[(tmp[2][i]=='1'?4:0)|(tmp[1][i]=='1'?2:0)|(tmp[0][i]=='1'?1:0)]];
  for(int i=0;i<3;++i)
    cal(q[i],x[i+1]);
  ll ans(0);
  for(int i=0;i<=x[2];++i)
    {
      int a=2*i+x[1]-x[2];
      int c=2*i+x[3]-x[2];
      if(a>=0 && c>=0 && (a&1)==0 && (c&1)==0)
	{
	  a>>=1,c>>=1;
	  if( a<=x[1] && c<=x[3])
	    ans=(ans + (((q[0][a]*q[1][i])%mod) * q[2][c])%mod)%mod;
	}
    }
  for(int i=0;i<x[0];++i)
    ans=(ans<<1)%mod;
  cout<<ans;
  return 0;
}
