#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll po(ll a,ll b,ll c)
{
  ll r=1;
  for(ll i=1;i<=b;i<<=1,a=(a*a)%c)
    if(i&b)
      r=(r*a)%c;
  return r;
}
ll gcd(ll a,ll b,ll &x,ll &y)
{
  if(a%b==0)
    {
      x=0,y=1;
      return b;
    }
  ll tmp=gcd(b,a%b,y,x);
  y=y-(a/b*x);
  return tmp;
}
int main()
{
  freopen("in.txt","r",stdin);
  ll p,k,a;
  cin>>p>>k>>a;
  if(a==0)
    {
      cout<<1<<endl<<0;
      return 0;
    }
  ll t=p-1;
  vector<ll> fact;
  for(ll i=2;i<sqrt(p-1) && i<=t;++i)
    if(t%i==0)
      for(fact.push_back(i);t%i==0;t/=i)
	;
  if(t>1)
    fact.push_back(t);
  ll g=2;
  for(int i;;++g)
    {
      i=0;
      for(;i<fact.size();++i)
	if(po(g,(p-1)/fact[i],p)==1)
	  break;
      if(i>=fact.size())
	break;
    }
  ll m=sqrt(p)+1;
  map<ll,ll> mapp;
  for(ll i=0,c=1;i<m;++i,c=(c*g)%p)
    mapp[c]=i;
  map<ll,ll> ans;
  ll tmp=po(g,(p-1-m),p);
  for(ll i=0,c=a;i<=m;++i,c=(c*tmp)%p)
    {
      ll t=c;
      if(mapp.find(t)!=mapp.end())
	{
	  ll c=mapp[t]+m*i;
	  if(((p-1)%k)==0)
	    {
	      if((c%k)==0)
		for(ll j=0;j<k;++j)
		  ans[po(g,(c/k+j*((p-1)/k))%(p-1),p)]=1;
	    }
	  else
	    {
	      ll x,y;
	      gcd(k,p-1,x,y);
	      x=((x%(p-1))+(p-1))%(p-1);
	      ans[(po(g,(x*c)%(p-1),p))]=1;
	    }
	  break;
	}
    }
  cout<<ans.size()<<endl;
  for(map<ll,ll>::iterator ite=ans.begin();ite!=ans.end();++ite)
    cout<<(ite->first)<<' ';
  return 0;
}
