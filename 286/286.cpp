#include <cstdio>
#include <iostream>
using namespace std;
#define N 2007
#define M (N*N*2)
int p[M][2],poi;
int s[N];
bool vis[N];
int lev[N],cnt;
bool usd[M];
int from[N];
void add(int f,int t,int num)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=num,s[f]=poi;
}
int dfs(int v,int frm)
{
  lev[v]=++cnt;
  from[v]=frm;
  int minl=1e9,k;
  for(;s[v];s[v]=p[s[v]][1])
    {
      int t=p[s[v]][0];
      if(t==frm)
	continue;
      if(lev[t]==0)
	{
	  usd[p[s[v]][2]]=true;
	  int tmp=dfs(t,v);
	  if(tmp==t)
	    usd[p[s[v]][2]]=false;
	  else break;
	}
      else if(minl>lev[t])
	minl=lev[t],k=s[v];
    }
  for(int i=from[v];;i=from[i])
    {
      for(;s[i];s[i]=p[s[i]][1])
	{
	  int t=p[s[i]][0];
	  if(lev[t]==0)
	    {
	      
	    }
	}
      if(i==1)
	break;
    }
  usd[p[k][2]]=true;
  return p[k][0];
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<(n*k)/2;++i)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      add(a,b,i+1);
      add(b,a,i+1);
    }
  for(int i=1;i<=n;++i)
    if(lev[i]==0)
      dfs(i,0);
  printf("YES");
  for(int i=0;i<ansi;++i)
    printf("%d",ans[i]);
  return 0;
}
