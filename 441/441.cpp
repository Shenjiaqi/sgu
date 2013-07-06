#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod=2007*81;
ll _(ll v)
{
  ll r(1);
  for(;v>1;--v)
    r*=v;
  return r;
}
void gcd(ll a,ll b,ll &c,ll &d)
{
  if((a%b)==0)
    d=1,c=0;
  else
    {
      gcd(b,a%b,d,c);
      d-=(a/b*c);
    }
}
ll ___(ll b,ll v)
{
  ll x,y;
  gcd(b,v,x,y);
  return ((x%v)+v)%v;
}
ll __(ll a,ll b)
{
  return (_(a)/((_(b)*_(a-b)))%mod);
}
ll ____(ll a,ll b)
{
  b%=1332;
  ll r(1);
  for(ll i=1;i<=b;i<<=1,a=(a*a)%mod)
    if(i&b)
      r=(r*a)%mod;
  return r;
}
int main()
{
  freopen("in.txt","r",stdin);
  ll n,k;
  cin>>n>>k;
  ll ans(0);
  for(ll i=1;i<=k;++i)
    {
      ll tmp=((__(k,i)*____(i,n))%mod);
      if((k-i)&1)
	ans+=(mod-tmp);
      else ans+=tmp;
      ans%=mod;
    }
  ll div;
  if(k>=9)
    div=81;
  else if(k>=6)
    div=9;
  else if(k>=3)
    div=3;
  else div=1;
  ans/=div;
  ll zz=(_(k)/div)%2007;
  cout<<((___(zz,2007)*ans)%2007);
  return 0;
}
