#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 20
char p[N][N+1];
int q[N][N];
int n;
void rotate(int i,int &x,int &y)
{
  for(;i;--i)
    {
      int tmp=y;
      y=n-x-1;
      x=tmp;
    }
}
int z[N*N][3]={0};
int pir[N*N];
bool dfs(int v)
{
  if(pir[v])
    return true;
  if(z[v][0]==0)
    return false;
  if(pir[z[v][1]]==0)
    {
      pir[z[v][1]]=v+1;
      pir[v]=z[v][1]+1;
      if(z[z[v][1]][0]==2)
	if(!dfs(z[z[v][1]][2]==v?z[z[v][1]][1]:z[z[v][1]][2]))
	  return false;
    }
  else if(z[v][0]==2 && pir[z[v][2]]==0)
    {
      pir[z[v][2]]=v+1;
      pir[v]=z[v][2]+1;
      if(z[z[v][2]][0]==2)
	if(!dfs(z[z[v][2]][2]==v?z[z[v][2]][1]:z[z[v][2]][2]))
	  return false;
    }
  else return false;
  return true;
}
bool chk(int r,int x,int y)
{
  int cnt(0);
  memset(z,0,sizeof(z));
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(q[i][j])
	{
	  int ix=i+x,jy=j+y;
	  if(ix<n && jy<n && ix>=0 && jy>=0)
	    {
	      rotate(r,ix,jy);
	      if((ix!=i || jy!=j) && q[ix][jy])
		{
		  int f=i*n+j;
		  int t=ix*n+jy;
		  if(f!=t && (z[f][0]==0 || (z[f][0]==1 && z[f][1]!=t)))
		    {
		      ++z[f][0],z[f][z[f][0]]=t;
		      ++z[t][0],z[t][z[t][0]]=f;
		    }
		}
	    }
	}
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(q[i][j] && z[i*n+j][0]==0)
	return false;
  memset(pir,0,sizeof(pir));
  for(int i=0;i<n*n;++i)
    if(z[i][0]==1)
      if(!dfs(i))
	return false;
  for(int i=0;i<n*n;++i)
    if(z[i][0]>0)
      if(!dfs(i))
	return false;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(q[i][j]==1 && pir[i*n+j]==0)
	return false;
  return true;
}
void pt(int r,int x,int y)
{
  memset(q,0,sizeof(q));
  for(int i=0;i<n*n;++i)
    if(pir[i])
      {
	int a=i;
	int b=pir[i]-1;
	int xa=a/n,ya=a%n;
	int xb=b/n,yb=b%n;
	xa+=x,ya+=y;
	if(xa<n && n>ya && xa>=0 && ya>=0)
	  {
	    rotate(r,xa,ya);
	    if(xa==xb && ya==yb)
	      {
		q[i/n][i%n]=1;
		pir[b]=0;
	      }
	  }
	/*int tmp=pir[i]-1;
	q[tmp/n][tmp%n]=1;
	pir[pir[i]-1]=0;*/
      }
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<n;++j)
	printf("%c",q[i][j]?'1':'0');
      printf("\n");
    }
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  int cnt(0);
  for(int i=0;i<n;++i)
    {
      scanf("%s",p[i]);
      for(int j=0;j<n;++j)
	if(p[i][j]=='1')
	  q[i][j]=1,++cnt;
    }
  if((cnt&1)==0)
    {
      for(int i=0;i<4;++i)
	{
	  for(int x=1-n;x<n;++x)
	    for(int y=1-n;y<n;++y)
	      {
		if(chk(i,x,y))
		  {
		    printf("YES\n");
		    pt(i,x,y);
		    return 0;
		  }
	      }
	}
    }
  printf("NO");
  return 0;
}
