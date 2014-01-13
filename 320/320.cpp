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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 507
#define M 507
int n,m,k;
int cnt;
char cs[N][M];
int s[N][M],si;
bool inque[N][M];
bool vis[N][M];
bool col[N][M];
queue<ppi> que;
const int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int corner[][2]={{-1,-1},{1,-1},{-1,1},{1,1}};
int sx,sy;
bool inrng(int xx,int yy)
{
  return (xx>=0 && yy>=0 && xx<=n+1 && yy<=m+1);
}
void dfs1(int x,int y,int t)
{
  if(!col[x][y] && t==cs[x][y])
    {
      s[x][y]=si;
      col[x][y]=true;
      FOR(i,0,4)
	dfs1(x+dir[i][0],y+dir[i][1],t);
    }
}
int dfs(int x,int y,int t)
{
  int r=0;
  if(!vis[x][y])
    {
      vis[x][y]=true;
      ++r;
      FOR(i,0,4)
	{
	  int xx=x+dir[i][0],yy=y+dir[i][1];
	  if(s[xx][yy]==t)
	    r+=dfs(xx,yy,t);
	  else if(!inque[xx][yy])
	    {
	      inque[xx][yy]=true;
	      que.push(MP(xx,yy));
	      if(sx<xx || (sx==xx && sy<yy))
		sx=xx,sy=yy;
	    }
	}
      FOR(i,0,4)
	{
	  int xx=corner[i][0]+x,yy=corner[i][1]+y;
	  if(s[xx][yy]!=t && !inque[xx][yy])
	    {
	      inque[xx][yy]=true;
	      que.push(MP(xx,yy));
	      if(sx<xx || (sx==xx && sy<yy))
		sx=xx,sy=yy;
	    }
	}
    }
  return r;
}
void dfs2(int x,int y)
{
  if(inque[x][y])
    {
      inque[x][y]=false;
      FOR(i,0,4)
	{
	  int xx=x+dir[i][0],yy=dir[i][1]+y;
	  if(inrng(xx,yy))
	    dfs2(xx,yy);
	}
    }
}
int dfs3(int x,int y)
{
  int r=0;
  if(!vis[x][y])
    {
      if(inque[x][y])
	inque[x][y]=false;
      vis[x][y]=true;
      ++r;
      FOR(i,0,4)
	{
	  int xx=x+dir[i][0],yy=dir[i][1]+y;
	  if(!vis[xx][yy])
	    r+=dfs3(xx,yy);
	}
    }
  return r;
}
int main()
{
  scanf("%d%d%d",&n,&m,&k);
  FOR(i,1,n+1)
    scanf("%s",cs[i]+1);
  FOR(i,1,n+1)
    FOR(j,1,m+1)
    if(!col[i][j])
      {
	++si;
	dfs1(i,j,cs[i][j]);
      }
  int ans=0;
  FOR(i,1,1+n)
    FOR(j,1,1+m)
    if(!vis[i][j])
      {
	sx=sy=-1;
	int num=dfs(i,j,s[i][j]);
	if(num>=k)
	  {
	    ans+=num;
	    dfs2(sx,sy);
	    for(;!que.empty();que.pop())
	      {
		int x=que.front().FIR,y=que.front().SEC;
		if(inque[x][y])
		  {
		    int tmp=dfs3(x,y);
		    ans+=tmp;
		  }
	      }
	  }
	else
	  for(;!que.empty();que.pop())
	    inque[que.front().FIR][que.front().SEC]=false;
      }
  printf("%d",ans);
  return 0;
}
