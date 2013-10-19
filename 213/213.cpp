#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define N (401)
int path[N*N*2+1][3],pathi;
int s[N+1];
bool block[N+1][N+1];
int n,m,S,T;
int color[N*N+1][2];
int scolor[N+1];
int que[N*2+10];
int road[N*N+1][2];
int can[N*N+1];
int vis[N+1];
bool test()
{
  int qf,ql;
  qf=0,ql=1;
  que[qf]=S;
  memset(vis,0,sizeof(vis));
  vis[S]=1;
  for(;qf<ql;++qf)
    {
      int v=que[qf];
      for(int j=s[v];j;j=path[j][1])
	if(!vis[path[j][0]] && !block[v][path[j][0]])
	  que[ql++]=path[j][0],vis[path[j][0]]=1;
      if(vis[T])
	break;
    }
  return vis[T];
}
inline void add(int a,int b,int v)
{
  ++pathi,path[pathi][0]=b,path[pathi][1]=s[a],s[a]=pathi,path[pathi][2]=v;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d%d",&n,&m,&S,&T);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      add(f,t,i);
      add(t,f,i);
      road[i][0]=t,road[i][1]=f;
    }
  int qf,ql;
  qf=0,ql=2;
  que[qf]=S;
  que[qf+1]=-1;
  vis[S]=1;
  int ncol(0);
  for(int i=1;qf<ql;++i)
    {
      int k=que[qf++];
      for(int j=s[k];j;j=path[j][1])
	if(!vis[path[j][0]])
	  {
	    vis[path[j][0]]=1+vis[k];
	    que[ql++]=path[j][0];
	  }
    }
  int coli(0);
  for(int i=1;i<=n;++i)
    for(int j=s[i];j;j=path[j][1])
      if(vis[i]==1+vis[path[j][0]])
	{
	++coli,color[coli][0]=path[j][2],color[coli][1]=scolor[vis[i]],scolor[vis[i]]=coli;
	ncol=max(ncol,vis[i]);
	}
  int ncan(0);
  for(int i=1;i<=ncol;++i)
    {
      memset(block,0,sizeof(block));
      int r(0);
      for(int j=scolor[i];j;j=color[j][1])
	{
	  ++r;
	  int f=road[color[j][0]][0],t=road[color[j][0]][1];
	  block[f][t]=block[t][f]=1;
	}
      if(!test())
	can[i]=r,++ncan;
    }
  printf("%d\n",ncan);
  for(int i=1;i<=ncol;++i)
    if(can[i])
      {
	printf("%d",can[i]);
	for(int j=scolor[i];j;j=color[j][1])
	  printf(" %d",color[j][0]+1);
	printf("\n");
      }
  return 0;
}
