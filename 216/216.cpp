#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000
int n,b;
int p[N*2+1][2],poi;
int s[N+1];
int fa[N+1][3];
int ans[N+1];
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi;
}
int gf(int v)
{
  return (v==fa[v][0]?v:(fa[v][0]=gf(fa[v][0])));
}
void join(int a,int b,int c)
{
  a=gf(a);
  b=gf(b);
  if(a!=b)
    {
      fa[b][0]=a;
      fa[a][1]+=fa[b][1];
      fa[a][2]=c;
    }
}
void dfs(int v,int f)
{
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f)
      dfs(p[i][0],v);
  int j=0;
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f)
      {
	if(fa[gf(p[i][0])][1]<b)
	  {
	    if(j)
	      join(j,p[i][0],v);
	    if(fa[gf(p[i][0])][1]<b)
	      j=p[i][0];
	    else j=0;
	  }
      }
  if(j && fa[gf(j)][1]<b)
    join(v,j,v);
}
int fill(int v,int f)
{
  if(fa[gf(v)][1]>=b)
    return v;
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f)
      {
	int tmp=fill(p[i][0],v);
	if(tmp)
	  return tmp;
      }
  return 0;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&b);
  if(b>n)
    {
      printf("0");
      return 0;
    }
  for(int i=0,f,t;i<n-1;++i)
    {
      scanf("%d%d",&f,&t);
      add(f,t),add(t,f);
    }
  for(int i=1;i<=n;++i)
    fa[i][0]=i,fa[i][1]=1,fa[i][2]=i;
  dfs(1,0);
  if(fa[gf(1)][1]<b)
    {
      int tmp=fill(1,0);
      join(tmp,1,fa[gf(tmp)][2]);
    }
  for(int i=1;i<=n;++i)
    if(fa[gf(i)][1]>3*b || fa[gf(i)][1]<b || fa[gf(i)][2]==0)
      return 1;
  int num(0);
  for(int i=1;i<=n;++i)
    if(fa[i][0]==i)
      ans[num]=i,++num,fa[i][1]=num;
  printf("%d\n",num);
  for(int i=1;i<=n;++i)
    printf("%d ",fa[gf(i)][1]);
  printf("\n");
  for(int i=0;i<num;++i)
    printf("%d ",fa[ans[i]][2]);
  return 0;
}
