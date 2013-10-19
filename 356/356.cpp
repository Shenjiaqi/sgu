#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
using namespace std;
typedef long long ll;
const ll mod=1e9;
vector<int> p[3];
int gcd(int a,int b)
{
  return (b==0?a:gcd(b,a%b));
}
void pt(vector<int> &v)
{
  if(v.size()==0)
    printf("0");
  else
    {
      int i=v.size()-1;
      printf("%d",v[i]);
      for(--i;i>=0;--i)
	printf("%09d",v[i]);
    }
}
void add(vector<int> &t,vector<int> &a,vector<int> &b)
{
  t.resize(0);
  int c=0;
  for(int i=0;i<a.size() || i<b.size();++i)
    {
      if(i<a.size())
	c+=a[i];
      if(i<b.size())
	c+=b[i];
      t.push_back(c%mod);
      c/=mod;
    }
  if(c>0)
    t.push_back(c);
}
void mul(vector<int> &t,ll v)
{
  vector<int> tmp=t;
  t.resize(0);
  ll c=0;
  for(int i=0;i<tmp.size();++i)
    {
      c+=(ll)tmp[i]*v;
      t.push_back(c%mod);
      c/=mod;
    }
  if(c>0)
    t.push_back(c);
}
bool divi(vector<int> & a,ll d)
{
  if(a.size()==0 || (a.size()==1 && a[0]==0))
    return true;
  ll v=0;
  for(int i=a.size()-1;i>=0;--i)
    v=((v*mod)%d+(ll)a[i])%d;
  return (v==0);
}
void div(vector<int> &a,ll d)
{
  if(a.size()==0 || (a.size()==1 && a[0]==0))
    return ;
  ll v=0;
  for(int i=a.size()-1;i>=0;--i)
    {
      ll tmp=(ll)a[i]+v*mod;
      a[i]=tmp/d;
      v=tmp%d;
    }
  for(int i=a.size()-1;i>0 && a[i]==0;--i)
    a.resize(i);
}
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&k,&n);
  int t=n-k;
  p[0].push_back(1);
  p[1].push_back(0);
  for(int i=2;i<=t;++i)
    {
      add(p[i%3],p[(i-1)%3],p[(i-2)%3]);
      mul(p[i%3],i-1);
    }
  if((p[t%3].size()==1 && p[t%3][0]==0) || p[t%3].size()==0)
    printf("0");
  else
    {
      vector<int> v1=p[t%3];
      p[0].resize(1);
      p[0][0]=1;
      for(int i=2;i<=n;++i)
	mul(p[0],i);
      vector<int> v2=p[0];
      p[0].resize(k);
      for(int i=0;i<k;++i)
	p[0][i]=n-i;
      for(int i=2;i<=k;++i)
	for(int j=i,l=0;l<k && j>1;++l)
	  {
	    int d=gcd(j,p[0][l]);
	    j/=d;
	    p[0][l]/=d;
	  }
      for(int i=0;i<k;++i)
	mul(v1,p[0][i]);
      for(int i=2;i<100;++i)
	for(;divi(v1,i) && divi(v2,i);)
	  div(v1,i),div(v2,i);
      pt(v1);
      printf("/");
      pt(v2);
    }
  return 0;
}
