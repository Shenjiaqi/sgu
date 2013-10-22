#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 251
typedef long long ll;
const ll base=1000000000;
int p[N];
vector<int> dp[2][N];
void add(vector<int> &t,vector<int> &f)
{
  int lf=f.size();
  int c(0);
  int i(0);
  for(;i<lf;++i)
    {
      if(i>=t.size())
	t.resize(i+1);
      c+=(t[i]+f[i]);
      t[i]=c%base;
      c/=base;
    }
  for(;c;++i)
    {
      if(i>=t.size())
	t.resize(i+1);
      c+=t[i];
      t[i]=c%base;
      c/=base;
    }
}
void mul(vector<int> &t,int v)
{
  ll c(0);
  for(int i=0;i<t.size();++i)
    {
      c+=(ll)t[i]*(ll)v;
      t[i]=c%base;
      c/=base;
    }
  if(c)
    {
      t.resize(t.size()+1);
      t[t.size()-1]=c;
    }
}
void pt(vector<int> &v)
{
  int i=v.size()-1;
  printf("%d",v[i]);
  for(--i;i>=0;--i)
    printf("%09d",v[i]);
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  sort(p,p+n);
  for(int i=0;i<2;++i)
    for(int j=0;j<=k;++j)
      dp[i][j].resize(1);
  for(int i=1;i<=n;++i)
    {
      int f=(i-1)&1;
      int t=i&1;
      dp[f][0][0]=1;
      for(int j=1;j<=min(k,i);++j)
	{
	  if(p[i-1]>j-1)
	    {
	      add(dp[t][j],dp[f][j-1]);
	      mul(dp[t][j],p[i-1]-j+1);
	      add(dp[t][j],dp[f][j]);
	    }
	}
      for(int j=0;j<=k;++j)
	{
	  dp[f][j].resize(1);
	  dp[f][j][0]=0;
	}
    }
  pt(dp[n&1][k]);
  return 0;
}
