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
#include <functional>
using namespace std;
typedef long long ll;
ll mind(ll v)
{
  ll tmp=(sqrt(v)+0.5);
  for(int i=3;i<=tmp;i+=2)
    if((v%i)==0)
      return i;
  return v;
}
bool canee(ll a,ll b,bool prt)
{
  if(a>b || a<=2)
    return 0;
  if(!prt)
    return 1;
  /*ll i=2;
    for(;;)
    {
    ll c=(i<<1);
    if((c>=a) || (a%c) || a+c>b)
    break;
    i=c;
    }*/
  for(ll i=2;a<b;)
    {
      cout<<a<<endl;
      a+=i;
      i<<=1;
      for(;i>2 && (a<=i || (a%i) || a+i>b);)
	i>>=1;
    }
  cout<<a<<endl;
  return 1;
}
bool canoe(ll a,ll b,bool prt)
{
  if(b<a || !(a&1) || (b&1))
    return 0;
  /*if(b==a)
    return 1;*/
  if((b-a)<a && (b-a)>1 && (a%(b-a))==0)
    {
      if(prt)
	cout<<a<<endl<<b<<endl;
      return 1;
    }
  ll tmpa=mind(a);
  if(tmpa==a)
    return 0;
  tmpa+=a;
  bool tprt=canee(tmpa,b,0);
  if(tprt && prt)
    {
      cout<<a<<endl;
      canee(tmpa,b,1);
    }
  return tprt;
}
bool caneo(ll a,ll b,bool prt)
{
  if(b<a || (a&1) || !(b&1))
    return 0;
  /*if(a==b)
    return 1;*/
  if((b-a)<a && (b-a)>1 && (a%(b-a))==0)
    {
      if(prt)
	cout<<a<<endl<<b<<endl;
      return 1;
    }
  ll tmpb=mind(b);
  if(tmpb==b)
    return 0;
  tmpb=b-tmpb;
  bool tprt=canee(a,tmpb,prt);
  if(tprt && prt)
    cout<<b<<endl;
  return tprt;
}
int main()
{
  freopen("in","r",stdin);
  ll a,b;
  cin>>a>>b;
  if((a&1))
    {
      ll t;
      if(b&1)
	t=mind(b);
      else t=0;
      if(t!=b && canoe(a,b-t,0))
	{
	  canoe(a,b-t,1);
	  if(t)
	    cout<<b<<endl;
	  return 0;
	}
      if(b&1)
	{
	  t=mind(a);
	  if(t!=a && caneo(a+t,b,0))
	    {
	      cout<<a<<endl;
	      caneo(a+t,b,1);
	      return 0;
	    }
	}
    }
  else if((b&1))
    {
      if(caneo(a,b,0))
	{
	  caneo(a,b,1);
	  return 0;
	}
    }
  else if(canee(a,b,0))
    {
      canee(a,b,1);
      return 0;
    }
  cout<<"Impossible";
  return 0;
}
