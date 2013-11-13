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
#define M 200
#define N 200
int p[M][N];
int vis[M][N],vi;
int m,n;
const int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int x,int y,int t,int z)
{
  vis[x][y]=t;
  int r=(((x+y)&1)==z)?1:0;
  FOR(i,0,4)
    {
      int xx=x+dir[i][0],yy=y+dir[i][1];
      if(xx>=0 && yy>=0 && xx<m && yy<n && p[xx][yy]!=0 && vis[xx][yy]!=t)
	r+=dfs(xx,yy,t,z);
    }
  return r;
}
int main()
{
  scanf("%d%d",&m,&n);
  FOR(i,0,m)
    FOR(j,0,n)
    scanf("%d",*(p+i)+j);
  int ans(0);
  FOR(i,0,m)
    FOR(j,0,n)
    if(p[i][j]==1 && vis[i][j]==0)
      {
	++vi;
	int tmp1=dfs(i,j,vi,vi&1);
	++vi;
	int tmp2=dfs(i,j,vi,vi&1);
	if(tmp1>tmp2)
	  {
	    ++vi;
	    ans+=dfs(i,j,vi,vi&1);
	  }
	else ans+=tmp2;
      }
  printf("%d\n",ans);
  FOR(i,0,m)
    {
      FOR(j,0,n)
	{
	  if(p[i][j]==0)
	    printf("#");
	  else
	    {
	      if(((i+j)&1)==(vis[i][j]&1))
		printf("G");
	      else printf(".");
	    }
	}
      printf("\n");
    }
  return 0;
}
