#include <cstdio>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1007
#define M 20007
int p[M+1][3],poi;
int s[N];
int d[N];
int id;
bool in[N];
int low[N];
int sta[N],sti;
int grp;
int bel[N];
int num[N];
int q[M+1][2],qoi;
int sq[N];
int du[N];
int q1[N];
int dis[N][N];
int ans[M],ani;
void dfs(int v)
{
  in[v]=true;
  d[v]=low[v]=++id;
  sta[sti++]=v;
  for(int i=s[v];i;i=p[i][1])
    if(d[p[i][0]]==0)
      {
	dfs(p[i][0]);
	low[v]=min(low[v],low[p[i][0]]);
      }
    else if(in[p[i][0]])
      low[v]=min(low[v],d[p[i][0]]);
  if(d[v]==low[v])
    {
      for(;;)
	{
	  --sti;
	  in[sta[sti]]=false;
	  bel[sta[sti]]=grp;
	  ++num[grp];
	  if(sta[sti]==v)
	    break;
	}
      ++grp;
    }
}
int cc[N];
bool chk(int v,int l)
{
  cc[v]=l;
  for(int i=sq[v];i;i=q[i][1])
    if(cc[q[i][0]]==l || (0==cc[q[i][0]] && chk(q[i][0],l)))
      return true;
  return false;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      --f,--t;
      ++poi,p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=i+1,s[f]=poi;
    }
  for(int i=0;i<n;++i)
    if(d[i]==0)
      dfs(i);
  for(int i=0;i<grp;++i)
    if(cc[i]==0 && chk(i,i+1))
      return 1;
  typedef pair<int,int> pp;
  map<pp,int> mapp;
  for(int i=0;i<n;++i)
    {
      int a=bel[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int b=bel[p[j][0]];
	  if(a!=b && mapp.find(pp(a,b))==mapp.end())
	    {
	      mapp[pp(a,b)]=1;
	      ++qoi,q[qoi][0]=b,q[qoi][1]=sq[a],sq[a]=qoi;
	      ++du[b];
	    }
	}
    }
  int f1,l1;
  f1=l1=0;
  for(int i=0;i<grp;++i)
    {
      if(du[i]==0)
	q1[l1++]=i;
      dis[i][i]=num[i];
    }
  for(;f1<l1;++f1)
    {
      int v=q1[f1];
      for(int i=sq[v];i;i=q[i][1])
	{
	  int t=q[i][0];
	  if(v==t)
	    return 1;
	  for(int j=0;j<=f1;++j)
	    {
	      int k=q1[j];
	      //for(int j=0;j<grp;++j)
	      if(dis[v][k]>0)
		dis[t][k]=max(dis[t][k],dis[v][k]+num[t]);
	    }
	  if(0==--du[t])
	    q1[l1++]=t;
	}
    }
  int w(0);
  for(int i=0;i<n;++i)
    {
      int a=bel[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int b=bel[p[j][0]];
	  int tmp=dis[b][a];
	  if(tmp>=w)
	    {
	      if(tmp>w)
		ani=0,w=tmp;
	      ans[ani++]=p[j][2];
	    }
	}
    }
  for(int i=0;i<grp;++i)
    if(du[i]>0)
      return 1;
  printf("%d\n%d\n",w,ani);
  for(int i=0;i<ani;++i)
    printf("%d ",ans[i]);
  return 0;
}
