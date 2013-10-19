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
#define N 200
#define M 200
int p[N][M];
int q[N][M];
int emp[N][M];
bool in[N][M];
int main()
{
  //freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    FOR(j,0,m)
    scanf("%d",*(p+i)+j);
  queue<ppi> a;
  FOR(i,0,n)
    FOR(j,0,m)
    {
      emp[i][j]=(i>0?1:0)+(i<n-1?1:0)+(j>0?1:0)+(j<m-1?1:0);
      if(emp[i][j]+1==p[i][j])
	a.push(ppi(i,j)),in[i][j]=true,++q[i][j];
    }
  queue<ppi> b;
  const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
  for(;!a.empty();)
    {
      b.push(a.front());
      int x=a.front().first,y=a.front().second;
      a.pop();
      FOR(i,0,4)
	{
	  int xx=x+dir[i][0];
	  int yy=y+dir[i][1];
	  if(xx>=0 && yy>=0 && xx<n && yy<m)
	    {
	      if(q[xx][yy])
		++q[xx][yy];
	      --emp[xx][yy];
	      if(emp[xx][yy]+1==p[xx][yy] && !in[xx][yy])
		a.push(ppi(xx,yy)),in[xx][yy]=true,++q[xx][yy];
	    }
	}
    }
  FOR(i,0,n)
    FOR(j,0,m)
    if(p[i][j]!=q[i][j])
      {
	printf("No solution");
	return 0;
      }
  for(;!b.empty();b.pop())
    printf("%d %d\n",b.front().first+1,b.front().second+1);
  return 0;
}
