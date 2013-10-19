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
const ll base=1e9;
vector< vector<ll> > pp;
void mul(vector<ll> &a,vector<ll> &b)
{
  vector<ll> c=a;
  vector<ll> d=b;
  a.clear();
  for(int i=0;i<c.size();++i)
    for(int j=0;j<d.size();++j)
      {
	int k=i+j;
	if(k>=a.size())
	  a.resize(k+1);
	a[k]+=c[i]*d[j];
	if(a[k]>=base)
	  {
	    if(k+1>=a.size())
	      a.resize(k+2);
	    a[k+1]+=(a[k]/base);
	    a[k]%=base;
	  }
      }
}
void p2ow(vector<ll> &a,int n)
{
  for(int i=1,j=1;i<=n;i<<=1,++j)
    if(i&n)
      mul(a,pp[j]);
}
void sub(vector<ll> &a,vector<ll> &b)
{
  for(int i=0;i<b.size();++i)
    {
      a[i]-=b[i];
      if(a[i]<0)
	a[i]+=base,a[i+1]-=1;
    }
  int num=0;
  for(int i=a.size()-1;i>0 && a[i]==0;--i,++num)
    ;
  a.resize(a.size()-num);
}
void pt(vector<ll> &a)
{
  int i=a.size()-1;
  printf("%d",(int)a[i]);
  for(--i;i>=0;--i)
    printf("%09d",(int)a[i]);
}
void div(vector<ll> &a,ll b)
{
  for(int i=a.size()-1;i>=0;--i)
    {
      if(i>0)
	a[i-1]+=((a[i]%b)*base);
      a[i]/=b;
    }
  int num=0;
  for(int i=a.size()-1;i>0 && a[i]==0;--i,++num)
    ;
  a.resize(a.size()-num);
}
void add(vector<ll> &a,vector<ll> &b)
{
  for(int i=0;i<b.size();++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      a[i]+=b[i];
      if(a[i]>=base)
	{
	  if(a.size()<=i+1)
	    a.resize(i+2);
	  a[i+1]+=a[i]/base;
	  a[i]%=base;
	}
    }
}
int main()
{
  freopen("in","r",stdin);  freopen("out","w",stdout);
  int n;
  cin>>n;
  vector< pair< ll , vector<ll> > > num;
  pp.resize(2);
  pp[0].push_back(1);
  pp[1].push_back(2);
  for(int i=2,j=1;j<=n;++i,j<<=1)
    {
      pp.resize(pp.size()+1);
      pp[i]=pp[i-1];
      mul(pp[i],pp[i]);
    }
  for(int i=1;i<=n;++i)
    if((n%i)==0)
      {
	int j=num.size();
	num.resize(j+1);
	num[j].first=i;
	num[j].second.push_back(1);
	p2ow(num[j].second,i);
      }
  vector<ll> ans;
  for(int i=0;i<num.size();++i)
    for(int j=0;j<i;++j)
      if((num[i].first%num[j].first)==0)
	sub(num[i].second,num[j].second);
  for(int i=0;i<num.size();++i)
    {
      div(num[i].second,num[i].first);
      add(ans,num[i].second);
    }
  pt(ans);
  return 0;
}
