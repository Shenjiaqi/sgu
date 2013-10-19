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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 10000000
#define Z 20
const int pri[Z]={2,3,5,7,11,13,17,19,23,29,
		 31,37,41,43,47,53,59,61,67,71};
int p[Z][2];
vector<int> ans;
vector<int> q[Z][2];
ll const mod=1e9;
void pt(vector<int> &a)
{
  if(a.size()==0)
    printf("0");
  else
    {
      int i=a.size()-1;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%09d",a[i]);
    }
}
void mul(vector<int> &r,vector<int> &b,vector<int> &c)
{
  vector<int> a;
  for(int i=0;i<b.size() && a.size()<60;++i)
    for(int j=0;j<c.size() &&a.size()<60;++j)
      {
	if(i+j>=a.size())
	  a.resize(i+j+1);
	ll tmp=(ll)a[i+j]+(ll)b[i]*(ll)c[j];
	a[i+j]=tmp%mod;
	tmp/=mod;
	if(tmp)
	  {
	    if(a.size()<=i+j+1)
	      a.resize(i+j+2);
	    a[i+j+1]+=tmp;
	  }
      }
  r=a;
}
void powder(vector<int> &r,int b,int k)
{
  vector<int> tmp;
  tmp.push_back(b);
  r.resize(0);
  r.push_back(1);
  for(int i=1;i<=k;i<<=1,mul(tmp,tmp,tmp))
    if(i&k)
      mul(r,r,tmp);
}
int cmp(vector<int> &a,vector<int> &b)
{
  if(a.size()!=b.size())
    return a.size()-b.size();
  for(int i=a.size()-1;i>=0;--i)
    if(a[i]!=b[i])
      return a[i]-b[i];
  return 0;
}
void dfs(int lev,vector<int> &val,int a)
{
  if(ans.size()>0 && cmp(ans,val)<0)
    return;
  if(a==1)
    {
      ans=val;
      return;
    }
  if(lev>=Z)
    return;
  vector<int> tmp;
  if((a%p[lev][0])==0)
    {
      mul(tmp,val,q[lev][0]);
      dfs(lev+1,tmp,a/p[lev][0]);
    }
  if(p[lev][1] && (a%p[lev][1])==0)
    {
      mul(tmp,val,q[lev][1]);
      dfs(lev+1,tmp,a/p[lev][1]);
    }
}
int main()
{
  freopen("in","r",stdin);
  int k;
  scanf("%d",&k);
  for(int i=0;i<Z;++i)
    {
      int tmp=(double)k/max((double)1.0,log(pri[i]));
      tmp=max(tmp-1,1);
      for(int j=tmp;j>=1;--j)
	if((k%j)==0)
	  {
	    p[i][0]=j;
	    break;
	  }
      for(int j=tmp+1;j<=k;++j)
	if((k%j)==0)
	  {
	    p[i][1]=j;
	    break;
	  }
    }
  for(int i=0;i<4;++i)
    cout<<pri[i]<<' '<<p[i][0]<<' '<<p[i][1]<<endl;
  for(int i=0;i<Z;++i)
    {
      powder(q[i][0],pri[i],p[i][0]-1);
      if(p[i][1]>0)
	powder(q[i][1],pri[i],p[i][1]-1);
    }
  vector<int> tmp;
  tmp.push_back(1);
  dfs(0,tmp,k);
  pt(ans);
  return 0;
}
