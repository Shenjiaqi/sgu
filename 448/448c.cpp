#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 16
int p[N][N];
vector<int> q[N+1][5];
bool vis[1<<N][5];
ll dp[1<<N][N][5];
bool r[N+1][N+1];
int mr[N+1];
int n,m;
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
ll dfs(int msk,int v,int r)
{
  if(!vis[msk][r])
    {
      vector<int> pos;
      gpos(msk,pos);
      int num=pos.size();
      for(int i=0;i<q[num][r].size();++i)
	{
	  int t=q[num][r][i];
	  int c=0;
	  vector<int> p1,p2;
	  for(int j=0,k=1;k<=t;++j,k<<=1)
	    if(t&k)
	      c|=(1<<pos[j]),p1.push_back(pos[j]);
	  int cc=msk^c;
	  gpos(cc,p2);
	  for(int j=0;j<p1.size();++j)
	    for(int jj=mr[p1.size()];jj<min(r,(int)p1.size());++jj)
	      {
		ll v1=dfs(c,p1[j],jj);
		if(v1)
		  for(int k=0;k<p2.size();++k)
		    for(int kk=mr[p2.size()];kk<min(r,(int)p2.size());++kk)
		      if(jj==r-1 || kk==r-1)
			{
			  ll tmp=v1*dfs(cc,p2[k],kk);
			  dp[msk][cmp(p1[j],p2[k])][r]+=tmp;
			}
	      }
	}
      vis[msk][r]=true;
    }
  return dp[msk][v][r];
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
  mr[1]=0;
  for(int i=2;i<=n;++i)
    {
      mr[i]=mr[i-1];
      int tmp=i-1;
      if(tmp==(tmp&(-tmp)))
	++mr[i];
    }
  for(int i=1;i<(1<<n);++i)
    {
      int c=__builtin_popcount(i);
      for(int j=2;j<=n;++j)
	if(i<(1<<j))
	{
	  int cm=((1<<j)-1)^i;
	  if(i<cm)
	    {
	      int a=c,b=j-c;
	      if(a>b)
		swap(a,b);
	      int lb=mr[b]+1,llb=b-1+1;
	      for(int k=mr[j];k<min(5,j);++k)
		{
		  if(lb<=k && llb>=k)
		    {
		      q[j][k].push_back(i);
		    }
		}
	    }
	}
    }
  for(int i=0;i<n;++i)
    dp[1<<i][i][0]=1,vis[1<<i][0]=true;
  cout<<dfs((1<<n)-1,m-1,mr[n]);
   // cout<<endl<<dfs(3840,8,2)<<endl;
  return 0;
}
