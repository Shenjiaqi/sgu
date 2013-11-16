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
#define N 17
#define M 17
char s[N][M];
int c;
int d[N][M][N][M];
int dist[N][M][N*M];
int mi[N*M][N][M];
int n,m;
bool inr(int x,int y)
{
  return (x>=0 && y>=0 && x<n && y<m);
}
void bt(int blk,int x,int y)
{
  int di=mi[blk][x][y];
  FOR(i,0,n)
    FOR(j,0,m)
    if(p[i][j]==blk && p[i][j][x][y]==di)
      {
	tra(
}
void dfs(int x,int y,int tag)
{
  if(p[x][y]==0 && s[x][y]=='X')
    {
      p[x][y]=tag;
      FOR(i,0,4)
	{
	  int xx=x+dir[k][0],yy=y+dir[k][1];
	  if(inr(xx,yy))
	    r=min(r,dfs(xx,yy,tag));
	}
    }
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    scanf("%s",s[n]);
  memset(d,1<<5,sizeof(d));
  int inf=d[0][0][0][0];
  FOR(i,0,n)
    FOR(j,0,m)
    {
      d[i][j][i][j]=0;
      FOR(k,0,4)
	{
	  int x=i+dir[k][0],y=j+dir[k][1];
	  if(inr(x,y))
	    {
	      if(s[i][j]=='X' && s[x][y]=='X')
		d[i][j][x][y]=0;
	      else d[i][j][x][y]=1;
	    }
	}
    }
  int zx=n,zy=m;
  d[zx][zy][zx][zy]=0;
  FOR(i,0,n)
    d[zx][zy][i][0]=d[zx][zy][i][m-1]=
    d[i][0][zx][zy]=d[i][m-1][zx][zy]=1;
  FOR(i,0,m)
    d[zx][zy][0][i]=d[zx][zy][n-1][i]=
    d[0][i][zx][zy]=d[n-1][i][zx][zy]=1;
  FOR(ki,0,n+1)
    FOR(kj,0,m+1)
    {
      FOR(ii,0,n+1)
	FOR(ij,0,m+1)
	{
	  int d1=d[ii][ij][ki][kj];
	  if(d1<inf)
	    FOR(ji,0,n+1)
	      FOR(jj,0,m+1)
	      {
		int d2=d[ki][kj][ji][jj];
		if(d2<inf)
		  p[ii][ij][ji][jj]=min(d1+d2,p[ii][ij][ji][jj]);
	      }
	}
    }
  c=1;
  FOR(i,0,n)
    FOR(j,0,m)
    if(s[i][j]=='X' && p[i][j]==0)
      dfs(i,j,c),++c;
  memset(mi,1<<5,sizeof(mi));
  FOR(i,0,n)
    FOR(j,0,m)
    if(s[i][j]=='X')
      FOR(a,0,n+1)
	FOR(b,0,m+1)
	if(s[a][b]=='.')
	  mi[p[i][j]][a][b]=min(mi[p[i][j]][a][b],p[i][j][a][b]);
  int ans(1e9),aa,bb,ii,jj;
  FOR(a,1,c)
    FOR(b,1,c)
    {
      FOR(i,0,n+1)
	FOR(j,0,m+1)
	if(s[i][j]=='.')
	  {
	    int tmp=mi[a][i][j] + mi[b][i][j] + p[zx][zy][i][j];
	    if( tmp < ans )
	      ans = tmp , aa = a , bb = b , ii = i , jj = j;
	  }
    }
  bt(aa,ii,jj);
  bt(bb,ii,jj);
  return 0;
}
