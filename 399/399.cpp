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
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define M 17
#define N 17
char s[N][M];
char ss[N][M];
int p[N][M];
int c;
int n,m;
const int d[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dis[N*M][N*M];
int frm[N*M][N*M][2];
bool inr(int x,int y)
{
  return (x>=0 && y>=0 && x<n && y<m);
}
void dfs(int x,int y,int t)
{
  if(p[x][y]==0 && s[x][y]=='X')
    {
      p[x][y]=t;
      FOR(i,0,4)
	{
	  int xx=x+d[i][0],yy=y+d[i][1];
	  if(inr(xx,yy))
	    dfs(xx,yy,t);
	}
    }
}
void bt(int x,int y,int t,int l)
{
  ss[x][y]='*';
  FOR(k,0,4)
    {
      int xx=x+d[k][0],yy=y+d[k][1];
      if(inr(xx,yy) && s[xx][yy]=='.')
	{
	  int v=p[xx][yy];
	  if(dis[v][t]==l-1)
	    {
	      bt(xx,yy,t,l-1);
	      break;
	    }
	}
    }
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    scanf("%s",s[i]);
  vector<int> a,b;
  memset(dis,1<<5,sizeof(dis));
  int inf=dis[0][0];
  FOR(i,0,n)
    FOR(j,0,m)
    if(s[i][j]=='.')
      p[i][j]=++c,a.push_back(c);
    else dfs(i,j,++c),b.push_back(c);
  a.push_back(0);
  FOR(i,0,n)
    FOR(j,0,m)
    if(s[i][j]=='.')
      {
	int v1=p[i][j];
	FOR(k,0,4)
	  {
	    int x=i+d[k][0],y=j+d[k][1];
	    if(inr(x,y) && s[x][y]=='.')
	      {
		int v2=p[x][y];
		dis[v1][v2]=dis[v2][v1]=1;
	      }
	  }
      }
  FOR(i,0,n)
    {
      int v1=p[i][0],v2=p[i][m-1];
      dis[0][v1]=dis[v1][0]=
	dis[0][v2]=dis[v2][0]=1;
    }
  FOR(i,0,m)
    {
      int v1=p[0][i],v2=p[n-1][i];
      dis[0][v1]=dis[v1][0]=
	dis[0][v2]=dis[v2][0]=1;
    }
  FOR(i,0,a.size())
    dis[a[i]][a[i]]=0;
  FOR(k,0,a.size())
    {
      int kk=a[k];
      FOR(i,0,a.size())
	{
	  int ii=a[i];
	  if(ii!=kk && dis[ii][kk]<inf)
	    FOR(j,0,a.size())
	      {
		int jj=a[j];
		if(jj!=kk && jj!=ii && dis[kk][jj]<inf)
		  {
		    int tmp=dis[ii][kk]+dis[kk][jj];
		    if(tmp<dis[ii][jj])
		      dis[ii][jj]=tmp;
		  }
	      }
	}
    }
  FOR(i,0,n)
    FOR(j,0,m)
    {
      int v=p[i][j];
      if(s[i][j]=='X')
	FOR(k,0,4)
	  {
	    int x=i+d[k][0],y=j+d[k][1];
	    if(inr(x,y) && s[x][y]=='.')
	      {
		int v1=p[x][y];
		FOR(l,0,a.size())
		  {
		    int v2=a[l];
		    if(dis[v][v2]>dis[v1][v2])
		      dis[v][v2]=dis[v1][v2],
		      frm[v][v2][0]=x,frm[v][v2][1]=y;
		  }
	      }
	  }
    }
  int mind=1e9,ii,jj,kk;
  FOR(i,0,b.size())
    FOR(j,0,b.size())
    if(i!=j)
      {
	int v1=b[i],v2=b[j];
	FOR(k,0,a.size())
	  {
	    int t=a[k];
	    int tmp=dis[v1][t]+dis[v2][t]+dis[t][0];
	    if(tmp<mind)
	      mind=tmp,ii=v1,jj=v2,kk=t;
	  }
      }
  bt(frm[ii][kk][0],frm[ii][kk][1],kk,dis[ii][kk]);
  bt(frm[jj][kk][0],frm[jj][kk][1],kk,dis[jj][kk]);
  FOR(i,0,n)
    FOR(j,0,m)
    if(p[i][j]==kk)
      bt(i,j,0,dis[kk][0]);
  FOR(i,0,n)
    {
      FOR(j,0,m)
	printf("%c",ss[i][j]?ss[i][j]:s[i][j]);
      printf("\n");
    }
  return 0;
}
