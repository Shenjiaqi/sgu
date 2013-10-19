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
#define N 9
#define M 3
char p[N][N+1];
char q[N][N+1];
int pos[N][2];
int qos[N][2];
int fa[N];
int head[N];
int cc[N];
int bel[N];
int bellist[N][N];
int h,w;
int g[M][M];
int kp[N][N],ki,visk[N][N];
void gpos()
{
  int cnt(0);
  for(int x=0;x<h;++x)
    for(int y=0;y<w;++y)
      if(p[x][y]=='X')
	pos[cnt][0]=x,pos[cnt][1]=y,++cnt;
}
const int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool dfsf(int v,int num)
{
  if(v>=num)
    {
      return true;
    }
  FOR(i,0,M)
    FOR(j,0,M)
    if(g[i][j]==0)
      {
	int flg=true;
	FOR(k,0,cc[v])
	  {
	    int z=bellist[v][k];
	    int x=pos[z][0]-pos[head[v]][0]+i,y=pos[z][1]-pos[head[v]][1]+j;
	    if(x<0 || x>=M || y<0 || y>=M || g[x][y])
	      {
		flg=false;
		break;
	      }
	    g[x][y]=v+'A';
	  }
	if(flg && dfsf(v+1,num))
	  return true;
	FOR(k,0,cc[v])
	  {
	    int z=bellist[v][k];
	    int x=pos[z][0]-pos[head[v]][0]+i,y=pos[z][1]-pos[head[v]][1]+j;
	    if(x>=0 && x<M && y<M && y>=0 && g[x][y]==v+'A')
	      g[x][y]=0;
	  }
      }
  return false;
}
bool shift(int num)
{
  memset(g,0,sizeof(g));
  return dfsf(0,num);
}
// int fillk(int x,int y,int id)
// {
//   kp[x][y]=id;
//   int r(1);
//   FOR(i,0,4)
//     {
//       int xx=x+dir[i][0],yy=y+dir[i][1];
//       if(xx>=0 && yy>=0 && xx<h && yy<w && kp[xx][yy]!=id)
// 	r+=fillk(xx,yy,id);
//     }
//   return r;
// }
int findki(int x,int y,int id)
{
  visk[x][y]=id;
  int r(1);
  FOR(k,0,4)
    {
      int xx=dir[k][0]+x,yy=dir[k][1]+y;
      if(xx>=0 && yy>=0 && xx<h && yy<w && kp[xx][yy]==id &&
	 visk[xx][yy]!=id)
	r+=findki(xx,yy,id);
    }
  return r;
}
bool ok(int num)
{
  FOR(i,0,num)
    {
      ++ki;
      FOR(j,0,cc[i])
	{
	  int v=bellist[i][j];
	  int x=pos[v][0],y=pos[v][1];
	  kp[x][y]=ki;
	}
      int tmp=findki(pos[bellist[i][0]][0],pos[bellist[i][0]][1],ki);
      if(tmp!=cc[i])
	return false;
      // int z=0;
      // FOR(j,0,h)
      // 	{
      // 	  if(kp[j][0]!=ki)
      // 	    z+=fillk(j,0,ki);
      // 	  if(kp[j][w-1]!=ki)
      // 	    z+=fillk(j,w-1,ki);
      // 	}
      // FOR(j,0,w)
      // 	{
      // 	  if(kp[0][j]!=ki)
      // 	    z+=fillk(0,j,ki);
      // 	  if(kp[h-1][j]!=ki)
      // 	    z+=fillk(h-1,j,ki);
      // 	}
      // if(z+cc[i]!=h*w)
      // 	return false;
    }
  return true;
}
bool dfs(int num,int v)
{
  if(v<N)
    {
      if(num<N-v)
	{
	  int f(0);
	  FOR(i,0,v)
	    if((f&(1<<fa[i]))==0)
	      {
		f|=(1<<fa[i]);
		fa[v]=fa[i];
		if(dfs(num,v+1))
		  return true;
	      }
	}
      if(num>0)
	{
	  fa[v]=v;
	  if(dfs(num-1,v+1))
	    return true;
	}
    }
  else
    {
      int cnt(0);
      FOR(i,0,N)
      	if(fa[i]==i)
	  head[cnt]=i,bel[i]=cnt,++cnt;
      // FOR(i,0,h)
      // 	FOR(j,0,w)
      // 	q[i][j]=p[i][j];
      FOR(i,0,cnt)
	cc[i]=0;
      FOR(i,0,N)
      	{
      	  int t=bel[fa[i]];
      	  bel[i]=t;
      	  //q[pos[i][0]][pos[i][1]]=bel[i];
      	  bellist[t][cc[t]++]=i;
      	}
      // FOR(i,0,cnt)
      // 	if(cc[i]!=fill(pos[head[i]][0],pos[head[i]][1],bel[head[i]]))
      // 	  return false;
      // return move(cnt);
      return (ok(cnt) && shift(cnt));
    }
  return false;
}
bool test(int num)
{
  fa[0]=0;
  return dfs(num-1,1);
}
int main()
{
  scanf("%d %d",&h,&w);
  FOR(i,0,h)
    scanf("%s",*(p+i));
  gpos();
  int ans(9);
  for(int f=1,t=9;f<=t;)
    {
      int m=(f+t)>>1;
      if(test(m))
  	t=m-1,ans=m;
      else f=m+1;
    }
  printf("%d\n",ans);
  test(ans);
  FOR(i,0,h)
    FOR(j,0,w)
    q[i][j]=p[i][j];
  FOR(i,0,N)
    q[pos[i][0]][pos[i][1]]=bel[i]+'A';
  FOR(i,0,h)
    {
      FOR(j,0,w)
	printf("%c",q[i][j]);
      printf("\n");
    }
  printf("\n");
  FOR(i,0,M)
    {
      FOR(j,0,M)
	printf("%c",g[i][j]);
      printf("\n");
    }
  return 0;
}
