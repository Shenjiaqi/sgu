#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 16
int p[N][N];
bool r[N+1][N+1];
vector<int> q[N+1];
int n,m;
bool vis[1<<N];
vector<int> dp[1<<N][N];
const ll base=1e9;
int cmp(int a,int b)
{
  return p[a][b]?a:b;
}
void gpos(int v,vector<int> &a)
{
  for(int i=0,j=1;j<=v;++i,j<<=1)
    if(j&v)
      a.push_back(i);
}
void pt(vector<int> &a)
{
  int i=a.size();
  if(i)
    {
      --i;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%09d",a[i]);
    }
  else printf("0");
}
void mul(vector<int> &a,vector<int> &b,vector<int> &c)
{
  a.resize(0);
  for(int i=0;i<b.size();++i)
    for(int j=0;j<c.size();++j)
      {
	if(i+j>=a.size())
	  a.resize(i+j+1);
	ll v=a[i+j];
	v+=(ll)b[i]*(ll)c[j];
	a[i+j]=v%base;
	v/=base;
	if(v>0)
	  {
	    if(i+j+1>=a.size())
	      a.resize(i+j+2);
	    a[i+j+1]+=v;
	  }
      }
}
void add(vector<int> &a,vector<int> &b)
{
  for(int i=0;i<max(a.size(),b.size());++i)
    {
      if(i>=a.size())
	a.resize(i+1);
      ll v=a[i];
      if(i<b.size())
	v+=b[i];
      a[i]=v%base;
      v/=base;
      if(v>0)
	{
	  if(i+1>=a.size())
	    a.resize(i+2);
	  a[i+1]+=v;
	}
    }
  for(int i=0;i<a.size();++i)
    {
      if(a[i]>=base)
	{
	  if(a.size()<=i+1)
	    a.resize(i+2);
	  a[i+1]+=a[i]/base;
	  a[i]%=base;
	}
    }
}
vector<int> *dfs(int msk,int v)
{
  if(!vis[msk])
    {
      int c=__builtin_popcount(msk);
      vector<int> p0;
      gpos(msk,p0);
      for(int i=0;i<q[c].size();++i)
	{
	  int t=q[c][i];
	  vector<int> p1;
	  int c1(0);
	  for(int j=0,k=1;k<=t;++j,k<<=1)
	    if(t&k)
	      c1|=(1<<p0[j]),
		p1.push_back(p0[j]);
	  int c2=msk^c1;
	  vector<int> p2;
	  gpos(c2,p2);
	  vector<vector<int> * >z1,z2;
	  for(int j=0;j<p1.size();++j)
	    z1.push_back(dfs(c1,p1[j]));
	  for(int j=0;j<p2.size();++j)
	    z2.push_back(dfs(c2,p2[j]));
	  for(int j=0;j<p1.size();++j)
	    for(int k=0;k<p2.size();++k)
	      {
		vector<int> tmp;
		mul(tmp,*z1[j],*z2[k]);
		add(dp[msk][cmp(p1[j],p2[k])],tmp);
	      }
	}
      vis[msk]=true;
    }
  return &dp[msk][v];
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      scanf("%d",&p[i][j]);
  if(n==16)
    {
      int i=0;
      for(i=0;i<n;++i)
	if(i!=m-1 && p[m-1][i]==0)
	  break;
      if(i>=n)
	return 1;
    }
  for(int i=2;i<=n;++i)
    for(int j=i/2;;--j)
      {
	r[i][j]=true;
	int t=i-j;
	if(t==(t&(-t)))
	  break;
      }
  for(int i=1;i<(1<<n);++i)
    {
      int c=__builtin_popcount(i);
      for(int j=2;j<=n;++j)
	if(r[j][c])
	  if((2*c<j && i<(1<<j)) || (2*c==j && i<(1<<(j-1))))
	    q[j].push_back(i);
    }
  for(int i=0;i<n;++i)
    dp[1<<i][i].push_back(1),
      vis[1<<i]=true;
  pt(*dfs((1<<n)-1,m-1));
  return 0;
}
