#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
#define N 1007
#define M 20007
int p[M+1][3],poi;
int s[N];
int q[M+1][3],qoi;
int sq[N];
int n,m;
bool vis[N];
int fa[N],fai;
int sta[N],sti;
int du[N];
int qdu[N];
int ans[M],ani;
int num[N];
bool in[N];
int dis[N];
int quee[N+1];
int qq[N];
int ta[N];
bool ins[N];
int low[N];
void add(int f,int t,int z[][3],int y[],int &oi,int id)
{
  ++oi,z[oi][0]=t,z[oi][1]=y[f],z[oi][2]=id,y[f]=oi;
}
void dfs(int v,int l)
{
  //vis[v]=true;
  ta[v]=low[v]=l;
  sta[sti++]=v;
  in[v]=true;
  for(int i=s[v];i;i=p[i][1])
    {
      if(ta[p[i][0]]==0)
	{
	  dfs(p[i][0],l+1);
	  low[v]=min(low[v],low[p[i][0]]);
	}
      else if(in[p[i][0]])
	low[v]=min(low[v],ta[p[i][0]]);
    }
  if(ta[v]==low[v])
    {
      ++fai;
      for(;;)
      {
	fa[sta[--sti]]=fai;
	//cout<<sta[sti]<<' ';
	++num[fai];
	in[sta[sti]]=false;
	if(sta[sti]==v)
	  break;
      }
      //cout<<endl;
    }
  /*
  if(fa[v]==0)
    {
      sta[sti++]=v;
      fa[v]=l;
      int low=l;
      for(int i=s[v];i;i=p[i][1])
	if(!vis[p[i][0]])
	  {
	    if(fa[p[i][0]]==0)
	      low=min(low,dfs(p[i][0],l+1));
	    else
	      low=min(low,fa[p[i][0]]);
	  }
      if(fa[v]==low)
	{
	  for(;;)
	    {
	      --sti;
	      ++num[fai];
	      fa[sta[sti]]=fai;
	      vis[sta[sti]]=true;
	      if(sta[sti]==v)
		break;
	    }
	  ++fai;
	  return l;
	}
      return low;
    }
    return fa[v];*/
}
int cccc[N];
bool chk(int v,int cc)
{
  cccc[v]=cc;
  for(int i=sq[v];i;i=q[i][1])
    if(cccc[q[i][0]]==cc || (cccc[q[i][0]]==0 && chk(q[i][0],cc)))
      return true;
  return false;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      --f,--t;
      add(f,t,p,s,poi,i+1);
    }
  for(int i=0;i<n;++i)
    if(ta[i]==0)
      dfs(i,1);
  typedef pair<int,int> pp;
  map<pp,int> mapp;
  for(int i=0;i<n;++i)
    {
      int a=fa[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int b=fa[p[j][0]];
	  if(a!=b && mapp.find(pp(a,b))==mapp.end())
	    {
	      //cout<<fa[i]<<' '<<fa[p[j][0]]<<endl;
	      mapp[pp(a,b)]=1;
	      add(a,b,q,sq,qoi,p[j][2]);
	      ++du[b];
	    }
	}
    }
  for(int i=1;i<=fai;++i)
    if(cccc[i]==0 && chk(i,i))
      return 1;
  int fquee,lquee,fqq,lqq;
  fquee=lquee=0;
  for(int i=1;i<=fai;++i)
    if(du[i]==0)
      quee[lquee++]=i;
  int w=0;
  for(;fquee!=lquee;)
    {
      int ll=lquee;
      for(int i=fquee;i<ll;++i)
	for(int j=sq[quee[i]];j;j=q[j][1])
	  if(0==--du[q[j][0]])
	    quee[lquee++]=q[j][0];
      for(;fquee<ll;++fquee)
	{
	  int vv=quee[fquee];
	  memset(dis,0,sizeof(dis));
	  memcpy(qdu,du,sizeof(qdu));
	  fqq=lqq=0;
	  for(int i=sq[vv];i;i=q[i][1])
	    if(0==qdu[q[i][0]])
	      {
		qq[lqq++]=q[i][0];
		dis[q[i][0]]=num[q[i][0]]+num[vv];
	      }
	  for(;fqq!=lqq;++fqq)
	    {
	      int v=qq[fqq];
	      for(int i=sq[v];i;i=q[i][1])
		{
		  dis[q[i][0]]=max(dis[q[i][0]],dis[v]+num[q[i][0]]);
		  if(--qdu[q[i][0]]==0)
		    qq[lqq++]=q[i][0];
		}
	    }
	  for(int i=sq[vv];i;i=q[i][1])
	    {
	      if(w<=dis[q[i][0]])
		{
		  if(w<dis[q[i][0]])
		    ani=0,w=dis[q[i][0]];
		  ans[ani++]=q[i][2];
		}
	    }
	}
    }
  //  for(int i=0;i<fai;++i)
  //if(du[i]>0)
  //  return 1;
  if(w>0)
    {
      printf("%d\n%d\n",w,ani);
      for(int i=0;i<ani;++i)
	printf("%d ",ans[i]);
    }
  else
    {
      for(int i=1;i<=fai;++i)
	w=max(w,num[i]);
      printf("%d\n%d\n",w,m);
      for(int i=1;i<=m;++i)
	printf("%d ",i);
    }
  return 0;
}
