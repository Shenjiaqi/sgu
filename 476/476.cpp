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
#define N 1000
#define K 20
const ll MOD=1000000000LL;
vector<ll> p[N+1];
vector<ll> ans;
int n,k;
void mul(vector<ll> &d,vector<ll> &s,ll v)
{
  ll c=0;
  d.resize(0);
  for(int i=0;i<s.size();++i)
    {
      c+=s[i]*v;
      d.push_back(c%MOD);
      c/=MOD;
    }
  if(c)
    d.push_back(c);
}
void pt(vector<ll> &a)
{
  if(a.size()==0)
    printf("0");
  else
    {
      int i=a.size()-1;
      printf("%d",(int)a[i]);
      for(--i;i>=0;--i)
	printf("%09d",(int)a[i]);
    }
}
void add(vector<ll> &d,vector<ll> &s)
{
  ll c(0);
  int i=0;
  for(;i<s.size();++i,c/=MOD)
    if(i>=d.size())
      {
	c+=s[i];
	d.push_back(c%MOD);
      }
    else
      {
	c+=(d[i]+s[i]);
	d[i]=c%MOD;
      }
  for(;c;c/=MOD,++i)
    if(i>=d.size())
      d.push_back(c);
    else
      {
	c+=d[i];
	d[i]=c%MOD;
      }
}
void sub(vector<ll> &d,vector<ll> &s)
{
  int i=0;
  ll c(0);
  for(i=0;i<s.size();++i)
    if(d[i]>=c+s[i])
      d[i]-=(c+s[i]),c=0;
    else d[i]=MOD+d[i]-(c+s[i]),c=1;
  for(;c;++i)
    if(d[i]>=c)
      d[i]-=c,c=0;
    else d[i]=MOD+d[i]-c,c=1;
  for(i=d.size()-1;i>0 && d[i]==0;--i)
    d.resize(i);
}
int triple[K][3];
int v[N*3+1];
bool chk(int i)
{
  for(int j=1,l=0;j<=i;j<<=1,++l)
    if(j&i)
      {
	for(int m=0;m<3;++m)
	  {
	    if(v[triple[l][m]]==i)
	      return false;
	    v[triple[l][m]]=i;
	  }
      }
  return true;
}
int as[K+1];
int main()
{
  freopen("in","r",stdin);
  p[0].push_back(1);
  p[1].push_back(1);
  for(int i=2;i<=N;++i)
    mul(p[i],p[i-1],(3*(i-1)+2)*(3*(i-1)+1)/2);
  scanf("%d%d",&n,&k);
  for(int i=0;i<k;++i)
    scanf("%d%d%d",*(triple+i),*(triple+i)+1,*(triple+i)+2);
  ans=p[n];
  for(int i=1;i<(1<<(k));++i)
    if(chk(i))
      {
	int tmp=__builtin_popcount(i);
	if(tmp&1)
	  --as[tmp];
	else ++as[tmp];
      }
  for(int j=1;j<=k;++j)
    if(as[j]>0)
      {
	vector<ll> tmp;
	mul(tmp,p[n-j],as[j]);
	add(ans,tmp);
      }
  for(int j=1;j<=k;++j)
    if(as[j]<0)
      {
	vector<ll> tmp;
	mul(tmp,p[n-j],-as[j]);
	sub(ans,tmp);
      }
  pt(ans);
  return 0;
}
