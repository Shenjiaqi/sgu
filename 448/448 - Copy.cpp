#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;
#define N 16
int p[N][N];
vector<int> q[N+1];
bool vis[1<<N];
vector<int> dp[1<<N][N];
bool r[N+1][N+1];
int n,m;
const ll base=1e9;
void pt(vector<int> &a)
{
  assert(a.size()<2);
  if(a.size())
    {
      int i=a.size()-1;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%09d",a[i]);
    }
  else printf("0");
  printf("\n");
}
void mul(vector<int> &to,vector<int> &a,vector<int> &b)
{
  to.resize(0);
  for(int i=0;i<a.size();++i)
    for(int j=0;j<b.size();++j)
      {
	ll v=a[i];
	v*=b[j];
	if(i+j>=to.size())
	  to.resize(i+j+1);
	v+=to[i+j];
	to[i+j]=v%base;
	v/=base;
	if(v)
	  {
	    if(i+j+1>=to.size())
	      to.resize(i+j+2);
	    to[i+j+1]+=v;
	  }
      }
//   for(int i=0;i<to.size();++i)
//     if(to[i]>=base)
//       {
// 	if(to.size()<=i+1)
// 	  to.reisze(i+2);
// 	to[i+1]+=to[i]/base;
// 	to[i]%=base;
//       }
}
void add(vector<int> &to,vector<int> &from)
{
  for(int i=0;i<max(to.size(),from.size());++i)
    {
      if(i>=to.size())
	to.resize(i+1);
      ll v=to[i];
      if(i<from.size())
	v+=from[i];
      to[i]=v%base;
      v/=base;
      if(v>0)
	{
	  if(i+1>=to.size())
	    to.resize(i+2);
	  to[i+1]+=v;
	}
    }
}
int cmp(int a,int b)
{
  return p[a][b]?a:b;
}
void gpos(int v,vector<int> & pp)
{
  for(int i=0,j=1;j<=v;++i,j<<=1)
    if(j&v)
      pp.push_back(i);
}
vector<int>* dfs(int msk,int v)
{
  if(!vis[msk])
    {
      vector<int> pos;
      gpos(msk,pos);
      int num=pos.size();
      for(int i=0;i<q[num].size();++i)
	{
	  int t=q[num][i];
	  int c=0;
	  vector<int> p1,p2;
	  for(int j=0,k=1;k<=t;++j,k<<=1)
	    if(t&k)
	      c|=(1<<pos[j]),p1.push_back(pos[j]);
	  vector< vector<int>* > z1,z2;
	  for(int j=0;j<p1.size();++j)
	    z1.push_back(dfs(c,p1[j]));
	  int cc=msk^c;
	  gpos(cc,p2);
	  for(int j=0;j<p2.size();++j)
	    z2.push_back(dfs(cc,p2[j]));
	  for(int j=0;j<p1.size();++j)
	    for(int k=0;k<p2.size();++k)
	      {
		vector<int> tmp;
		mul(tmp,*z1[j],*z2[k]);
		if(msk==((1<<n)-1) && cmp(p1[j],p2[k])==0 && (cc==1 || c==1))
		  {
		    cout<<c<<' '<<p1[j]<<' '<<cc<<' '<<p2[k]<<endl;
		    pt(*z1[j]);
		    pt(*z2[k]);
		  }
		add(dp[msk][cmp(p1[j],p2[k])],tmp);
	      }
	}
      vis[msk]=true;
    }
  return &dp[msk][v];
}
int main()
{
//   freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      scanf("%d",&p[i][j]);
  for(int i=1;i<=n;++i)
    {
      for(int j=i/2;j>0;--j)
	{
	  r[i][j]=true;
	  int jj=i-j;
	  if(jj==(jj&(-jj)))
	    break;
	}
    }
  for(int i=1;i<(1<<n);++i)
    {
      int c=__builtin_popcount(i);
      for(int j=2;j<=n;++j)
	if(r[j][c])
	  {
	    if((2*c<j && i<(1<<j)) || (2*c==j && i<(1<<(j-1))))
	      q[j].push_back(i);
	  }
    }
  for(int i=0;i<n;++i)
    dp[1<<i][i].push_back(1),vis[1<<i]=true;
  pt(*dfs((1<<n)-1,m-1));
  pt(*dfs(240,4));
  return 0;
}
