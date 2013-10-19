#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100007
#define M 200007
char a[N*2+2*M];
char *p[N],*q[M][2];
int seq[N];
int tree[N][5],tri;
int z[N][2],zoi;
int y[M][2],yoi;
int ans[M];
int range[M][2];
int num[N];
int que(int v)
{
  if(v<=0)
    return 0;
  int r(0);
  for(;v;v^=(v&(-v)))
    r+=num[v];
  return r;
}
void addd(int k)
{
  if(k>0)
    for(;k<N+1;k+=(k&(-k)))
      ++num[k];
}
void rev(char *c)
{
  int l=strlen(c);
  for(int i=0,j=l-1;i<j;++i,--j)
    swap(c[i],c[j]);
}
int newnode(char c)
{
  ++tri;
  memset(tree[tri],0,sizeof(tree[tri]));
  tree[tri][0]=c;
  return tri;
}
void mark(int v,char *c,int id)
{
  if(*c)
    {
      if(tree[v][0]==*c)
	{
	  if(*(1+c)==0)
	    {
	      ++yoi,y[yoi][0]=id,y[yoi][1]=tree[v][4],tree[v][4]=yoi;
	      return;
	    }
	  if(tree[v][1])
	    mark(tree[v][1],c+1,id);
	}
      else if(tree[v][2])
	mark(tree[v][2],c,id);
    }
}
void add(int v,char *c,int id)
{
  if(*c)
    {
      if(tree[v][0]==*c)
	{
	  if(*(1+c)==0)
	    {
	      ++zoi,z[zoi][0]=id,z[zoi][1]=tree[v][3],tree[v][3]=zoi;
	      return;
	    }
	  if(tree[v][1]==0)
	    tree[v][1]=newnode(*(1+c));
	  add(tree[v][1],c+1,id);
	}
      else
	{
	  if(tree[v][2]==0)
	    tree[v][2]=newnode(*c);
	  add(tree[v][2],c,id);
	}
    }
}
void dfs2(int v)
{
  for(int i=tree[v][4];i;i=y[i][1])
    {
      int k=y[i][0];
      int f=range[k][0],t=range[k][1];
      ans[k]=-(que(t)-que(f-1));
    }
  if(tree[v][1])
    dfs2(tree[v][1]);
  for(int i=tree[v][3];i;i=z[i][1])
    addd(seq[z[i][0]]);
  for(int i=tree[v][4];i;i=y[i][1])
    {
      int k=y[i][0];
      int f=range[k][0],t=range[k][1];
      ans[k]+=(que(t)-que(f-1));
    }
  if(tree[v][2])
    dfs2(tree[v][2]);
}
int dfs1(int v,int f)
{
  for(int i=tree[v][3];i;i=z[i][1])
    seq[z[i][0]]=f;
  int t=f;
  if(tree[v][1])
    t=dfs1(tree[v][1],f+1);//child
  for(int i=tree[v][4];i;i=y[i][1])
    {
      int k=y[i][0];
      range[k][0]=f,range[k][1]=t;
    }
  if(tree[v][2])
     t=dfs1(tree[v][2],t+1);//brother
  return t;
}
int main()
{
  int n;
  scanf("%d",&n);
  int t=0;
  FOR(i,0,n)
    {
      scanf("%s",a+t);
      p[i]=a+t;
      t+=(strlen(a+t)+1);
    }
  int m;
  scanf("%d",&m);
  FOR(i,0,m)
    FOR(j,0,2)
    {
      scanf("%s",a+t);
      q[i][j]=a+t;
      t+=(strlen(a+t)+1);
    }
  FOR(i,0,n)
    add(0,p[i],i);
  FOR(i,0,m)
    mark(0,q[i][0],i);
  dfs1(0,0);

  tri=zoi=yoi=0;
  FOR(i,0,5)
    tree[0][i]=0;

  FOR(i,0,n)
    {
      rev(p[i]);
      add(0,p[i],i);
    }
  FOR(i,0,m)
    {
      rev(q[i][1]);
      mark(0,q[i][1],i);
    }
  dfs2(0);
  FOR(i,0,m)
    printf("%d\n",ans[i]);
  return 0;
}
