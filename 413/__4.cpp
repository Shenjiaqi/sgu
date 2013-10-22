#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h>
using namespace std;
#define N 100
#define M 1000
int p[N+1][N+1];
int fa[N+1];
int d[N+1];
int seq[N+1];
bool vis[N+1];
queue<int> que;
int dfs(int v)
{
  for(int i=1;i<=n;++i)
    {
      int tmp=dfs(i);
      if(tmp)
	return tmp;
    }
  return 0;
}
int query(int i)
{
  return fa[i]==i?i:fa[i]=query(fa[i]);
}
void joi(int a,int b)
{
  a=query(a);
  b=query(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in.txt","r",stdin);
  int tst;
  scanf("%d",&tst);
  for(;tst--;)
    {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(d,0,sizeof(d));
      memset(p,0,sizeof(p));
      for(int i=0,f,t;i<m;++i)
	{
	  scanf("%d%d",&f,&t);
	  ++d[f],++d[t];
	  p[f][t]=p[t][f]=1;
	}
      for(int i=1;i<=n;++i)
	{
	  fa[i]=i;
	  if(d[i]==1)
	    que.push(i);
	}
      for(;;)
	{
	  for(;!que.empty();)
	    {
	      int v=que.front();
	      que.pop();
	      if(d[v])
		{
		  int k=1;
		  for(;!p[v][k];++k)
		    ;
		  joi(v,k);
		  p[v][k]=p[k][v]=0;
		  --d[v],--d[k];
		  int num=2;
		  for(int i=1;i<=n;++i)
		    if(p[k][i] && d[i]==1)
		      {
			joi(k,i);
			++num;
			p[i][k]=p[k][i]=0;
			--d[k],--d[i];
		      }
		  if(num&1)
		    {
		      if(d[k]==1)
			que.push(k);
		    }
		  else
		    {
		      for(int i=1;i<=n;++i)
			if(p[k][i])
			  {
			    p[k][i]=p[i][k]=0;
			    --d[k],--d[i];
			    if(d[i]==1)
			      que.push(i);
			  }
		    }
		}
	    }
	  memset(vis,0,sizeof(vis));
	  int k=1;
	  for(;;++k)
	    if(d[k])
	      {
		k=dfs(k);
		break;
	      }
	  if(k<=0)
	    break;
	  for(int i=1;i<=n;++i)
	    if(p[k][i])
	      {
		int c1=k,c2=i;
		for(int j=i+1;j<=n;++j)
		  if(d[j]==2 && p[k][j] && p[i][j])
		    {
		      if(d[i]>2)
			c2=j;
		      else c1=j;
		      break;
		    }
		joi(c1,c2);
		for(int j=1;j<=n;++j)
		  if(p[c1][j])
		    {
		      --d[c1],--d[j];
		      p[c1][j]=p[j][c1]=0;
		      if(d[j]==1)
			que.push(j);
		      else if(d[j]==0)
			return 1;
		    }
		for(int j=1;j<=n;++j)
		  if(p[c2][j])
		    {
		      --d[c2],--d[j];
		      p[c2][j]=p[j][c2]=0;
		      if(d[j]==1)
			que.push(j);
		      else if(d[j]==0)
			return 1;
		    }
		break;
	      }
	}
      memset(seq,0,sizeof(seq));
      for(int i=1,j=1;i<=n;++i)
	{
	  int t=query(i);
	  if(seq[t]==0)
	    seq[t]=j++;
	  printf("%d ",seq[t]);
	}
      printf("\n");
      for(int i=1;i<=n;++i)
	{
	  if(d[i])
	    return 1;
	  for(int j=1;j<=n;++j)
	    if(p[i][j])
	      return 1;
	}
    }
  return 0;
}
