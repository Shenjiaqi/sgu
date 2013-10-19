#include <cstdio>
#include <cstring>
#define N (1000)
#define M (50000)
int s[N+1];
bool deter[N+1];
bool vis[N+1];
bool active[N+1];
int path[M+1][3],poi;
void add(int f,int t,int w)
{
  ++poi,path[poi][0]=f,path[poi][1]=s[t],path[poi][2]=w,s[t]=poi;
}
int lev[N+1];
bool df(int v,int w,int l)
{
  if(deter[v])
    return (active[v]);
  if(vis[v])
    return w;
  vis[v]=true;
  for(int i=s[v];i;i=path[i][1])
    if(!df(path[i][0],path[i][2]|w,l+1))
      return false;
  return true;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t,w;
      scanf("%d%d%d",&f,&t,&w);
      add(f,t,w);
    }
  for(int i=1;i<=n;++i)
    {
      memset(vis,0,sizeof(vis));
      active[i]=df(i,0),deter[i]=1;
      printf("%d\n",(int)active[i]);
      deter[i]=true;
    }
  return 0;
}
