#include <cstdio>
#include <cstring>
#define N (1005)
#define M (50005)
int s[N+1];
bool deter[N+1];
int vis[N+1];
int value[N+1];
int lev[N+1];
bool active[N+1];
int path[M+1][3],poi;
void add(int f,int t,int w)
{
  ++poi,path[poi][0]=f,path[poi][1]=s[t];
  if(w)
    path[poi][2]=1;
  s[t]=poi;
}
bool df(int v,int w,int l)
{
  if(deter[v])
    return (active[v]);
  if(vis[v]>=2)
    return true;
  lev[l]=lev[l-1]+w;
  if(vis[v])
    {
      ++vis[v];
      return lev[l]-lev[value[v]];
    }
  value[v]=l;
  vis[v]=1;
  for(int i=s[v];i;i=path[i][1])
    if(!df(path[i][0],path[i][2],l+1))
      {
	active[v]=false;
	deter[v]=true;
	return false;
      }
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
      memset(value,0,sizeof(value));
      active[i]=df(i,0,1);
      deter[i]=1;
      printf("%d\n",(int)active[i]);
    }
  return 0;
}
