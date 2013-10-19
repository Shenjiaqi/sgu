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
#define Z 17
const int pri[Z]={2,3,5,7,11,13,17,19,23,29,
		  31,37,41,43,47,53,59};//,61,67,71};
long double r[Z];
long double dp[100001][Z];
int idx[100001][Z];
vector<int> di[100001];
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
  for(int i=0;i<b.size() ;++i)
    for(int j=0;j<c.size();++j)
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
long double cal(int k,int s)
{
  if(s==0)
    {
      idx[k][0]=k;
      return (long double)(k-1)*r[0];
    }
  if(k==1 && s>0)
    return -1;
  if(dp[k][s]==0)
    {
      for(int i=di[k].size()-1;i>=0;--i)
	{
	  long double tmp=cal(k/di[k][i],s-1);
	  if(tmp>0)
	    {
	      if(dp[k][s]==0 || dp[k][s]>tmp+r[s]*(di[k][i]-1))
		dp[k][s]=tmp+r[s]*(di[k][i]-1),idx[k][s]=di[k][i];
	    }
	}
      if(dp[k][s]==0)
	dp[k][s]=-1;
    }
  return dp[k][s];
}
void pp(int c,int k)
{
  vector<int>ans;
  ans.push_back(1);
  for(int j=c;j>=0;--j)
    {
      vector<int>tmp;
      tmp.push_back(pri[j]);
      powder(tmp,pri[j],idx[k][j]-1);
      k/=idx[k][j];
      mul(ans,ans,tmp);
    }
  pt(ans);
}
int main()
{
  freopen("in","r",stdin);
  int k;
  scanf("%d",&k);
  for(int i=0;i<Z;++i)
    r[i]=log2l((long double)pri[i]);
  for(int i=1;i<=k;++i)
    for(int j=i;j<=k;j+=i)
      di[j].push_back(i);
  long double mm=0;
  int c;
  for(int i=0;i<Z;++i)
    {
      long double tmp=cal(k,i);
      if(tmp>0 && (mm==0 || mm>tmp))
	mm=tmp,c=i;
    }
  pp(c,k);
  return 0;
}
