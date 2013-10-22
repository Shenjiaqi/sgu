#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <list>
using namespace std;
#define N 107
#define M 1007
int p[M*2+1][4],poi;
int s[N+1];
int id[N+1];
int vis[N+1];
int q[M][2];
int seq[N+1];
int n,m;
int gid;
queue<int> que;
int fa[N+1];
int d[N+1];
bool fb[N+1];
int quer(int v)
{
  return fa[v]==v?v:fa[v]=quer(fa[v]);
}
void joi(int a,int b)
{
  a=quer(a),b=quer(b);
  if(a!=b)
    fa[a]=b;
}
bool circle(int v,int f)
{
  if(vis[v]==gid)
    return true;
  vis[v]=gid;
  for(int i=s[v],pre=0;i;i=p[i][1])
    {
      int t=p[i][0];
      if(t!=f && circle(t,v))
	return true;
      pre=i;
    }
  return false;
}
int dfs(int v)
{
  int r=1;
  vis[v]=gid;
  for(int i=s[v];i;i=p[i][1])
    if(vis[p[i][0]]!=gid && !fb[p[i][0]])
      r+=dfs(p[i][0]);
  return r;
}
void add(int f,int t)
{
  ++d[f];
  ++poi,p[poi][0]=t;
  p[poi][1]=s[f];
  p[s[f]][2]=poi;
  s[f]=poi;
  p[poi][3]=f;
  p[poi][2]=0;
}
void dele(int i)
{
  --d[p[i][3]];
  if(p[i][2]==0)
    s[p[i][3]]=p[i][1];
  else
    p[p[i][2]][1]=p[i][1];
  if(p[i][1])
    p[p[i][1]][2]=p[i][2];
}
void del(int i)
{
  dele(i);
  dele(i+((i&1)?1:-1));
}
int main()
{
  freopen("in.txt","r",stdin);
  int tst;
  scanf("%d",&tst);
  for(;tst--;)
    {
      scanf("%d%d",&n,&m);
      memset(s,0,sizeof(s));
      memset(id,0,sizeof(id));
      memset(d,0,sizeof(d));
      poi=0;
      int cnt=0;
      list<int> road;
      for(int i=0,f,t;i<m;++i)
	{
	  scanf("%d%d",&f,&t);
	  add(f,t);
	  add(t,f);
	  q[i][0]=f,q[i][1]=t;
	  road.push_back(i);
	}
      for(int i=1;i<=n;++i)
	{
	  if(d[i]==1)
	    que.push(i);
	  fa[i]=i;
	}
      int left=n;
      for(list<int>::iterator ite,ite2;left>0 && road.size()>0;)
	{
	  left=0;
	  for(int i=1;i<=n;++i)
	    if(d[i])
	      ++left;
	  for(;!que.empty();)
	    {
	      int v=que.front();
	      que.pop();
	      if(d[v])
		{
		  int t=p[s[v]][0];
		  del(s[v]);
		  joi(v,t);
		  int num=2;
		  for(int i=s[t];i;i=p[i][1])
		    {
		      int to=p[i][0];
		      if(d[to]==1)
			{
			  del(i);
			  joi(t,to);
			  ++num;
			}
		    }
		  if(num&1 && d[t])
		    {
		      if(d[t]==1)
			que.push(t);
		      left-=(num-1);
		    }
		  else
		    {
		      for(int i=s[t];i;i=p[i][1])
			{
			  int to=p[i][0];
			  del(i);
			  if(d[to]==1)
			    que.push(to);
			}
		      left-=num;
		    }
		}
	    }
	  int ll=0;
	  for(int i=1;i<=n;++i)
	    if(d[i])
	      ++ll;
	  if(left<ll)
	    return 1;
	  else if(left>ll)
	  return 0;
	  ite=road.begin();
	  for(;left>0 && ite!=road.end();)
	    {
	      int a=q[*ite][0];
	      int b=q[*ite][1];
	      if(d[a] && d[b])
		{
		  fb[a]=fb[b]=true;
		  ++gid;
		  int k=s[a];
		  for(;k;k=p[k][1])
		    {
		      int t=p[k][0];
		      if(!fb[t] && vis[t]!=gid && (dfs(t)&1))
			break;
		    }
		  if(k==0)
		    for(k=s[b];k;k=p[k][1])
		      {
			int t=p[k][0];
			if(!fb[t] && vis[t]!=gid && (dfs(t)&1))
			  break;
		      }
		  fb[a]=fb[b]=false;
		  if(k==0)
		    {
		      for(int k=s[a];k;k=p[k][1])
			{
			  int t=p[k][0];
			  del(k);
			  if(d[t]==1)
			    que.push(t);
			}
		      for(int k=s[b];k;k=p[k][1])
			{
			  int t=p[k][0];
			  del(k);
			  if(d[t]==1)
			    que.push(t);
			}
		      joi(a,b);
		      ite2=ite++;
		      road.erase(ite2);
		      left-=2;
		    }
		  else ++ite;
		}
	      else
		{
		  ite2=ite++;
		  road.erase(ite2);
		}
	    }
	  ll=0;
	  for(int ii=1;ii<=n;++ii)
	    if(d[ii])
	      ++ll;
	  //if(ll!=left)
	  //return 1;
	  //if(left==cpy)
	  //break;
	}
      memset(seq,0,sizeof(seq));
      for(int i=1,j=1;i<=n;++i)
	{
	  int t=quer(i);
	  if(seq[t]==0)
	    seq[t]=j++;
	  printf("%d ",seq[t]);
	}
      for(;!que.empty();)
	que.pop();
      printf("\n");
    }
  return 0;
}
