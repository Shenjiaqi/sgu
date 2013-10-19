#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N (401)
int path[N*N*2+1][3],pathi;
int s[N+1];
bool block[N+1][N+1];
int n,m,S,T;
int color[N*N+1];
int scolor[N+1];
int que[N*2+10];
int road[N+1][2];
bool can[N*N+1];
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
  for(int i=1;qf<ql-1;++i)
    {
      scolor[i]=scolor[i-1];
      ++ncol;
      for(;;)
	{
	  int k=que[qf++];
	  if(k<0)
	    {
	      que[ql++]=-1;
	      break;
	    }
	  for(int j=s[k];j;j=path[j][1])
	    if(vis[path[j][0]]>vis[k] || !vis[path[j][0]])
	    {
	      color[scolor[i]++]=path[j][2];
	      if(!vis[path[j][0]])
		{
		  vis[path[j][0]]=i+1;
		  que[ql++]=path[j][0];
		}
	    }
	}
    }
  int ncan(0);
  for(int i=1;i<ncol;++i)
    {
      memset(block,0,sizeof(block));
      for(int j=scolor[i-1];j<scolor[i];++j)
	{
	  int f=road[color[j]][0],t=road[color[j]][1];
	  block[f][t]=block[t][f]=1;
	}
      if(!test())
	can[i]=1,++ncan;
    }
  printf("%d\n",ncan);
  for(int i=1;i<=ncol;++i)
    if(can[i])
      {
	printf("%d",scolor[i]-scolor[i-1]);
	for(int j=scolor[i-1];j<scolor[i];++j)
	  printf(" %d",color[j]+1);
	printf("\n");
      }
  return 0;
}
