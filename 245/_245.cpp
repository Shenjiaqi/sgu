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
#define N 307
#define M 307
//pawn, rook, knight, bishop, queen, and king
int p[7];
char q[N][M];
int cnt[N][M];
bool cg[N][M];
int rx,ry;
int n,m;
int sc[400];
bool inr(int x,int y)
{
  return (x<n && x>=0 && y<m && y>=0);
}
void calp(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  if(inr(x-1,y-1))
    {
      c[x-1][y-1]+=num;
      if(c[x-1][y-1]==0)
	que.push(ppi(x-1,y-1));
    }
  if(inr(x-1,y+1))
    {
      c[x-1][y+1]+=num;
      if(c[x-1][y+1]==0)
	que.push(ppi(x-1,y+1));
    }
}
void calm(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,-1,2)
    FOR(j,-1,2)
    if(i!=0 || j!=0)
      {
	int xx=x+i,yy=y+j;
	if(inr(xx,yy))
	  {
	    c[xx][yy]+=num;
	    if(c[xx][yy]==0)
	      que.push(ppi(xx,yy));
	  }
      }
}
const static int dirq[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
void calq(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,8)
    for(int xx=x+dirq[i][0],yy=y+dirq[i][1];inr(xx,yy)&& q[xx][yy]!='#';xx+=dirq[i][0],yy+=dirq[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
const static int dirb[][2]={{1,1},{-1,-1},{1,-1},{-1,1}};
void calb(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,4)
    for(int xx=x+dirb[i][0],yy=y+dirb[i][1];inr(xx,yy)&& q[xx][yy]!='#';xx+=dirb[i][0],yy+=dirb[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
const static int dirk[][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
void calk(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,8)
    {
      int xx=x+dirk[i][0],yy=y+dirk[i][1];
      if(inr(xx,yy))
	{
	  c[xx][yy]+=num;
	  if(c[xx][yy]==0)
	    que.push(ppi(xx,yy));
	}
    }
}
const static int dirr[][2]={{1,0},{-1,0},{0,1},{0,-1}};
void calr(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,4)
    for(int xx=x+dirr[i][0],yy=y+dirr[i][1];inr(xx,yy) && q[xx][yy]!='#';xx+=dirr[i][0],yy+=dirr[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
int uncal(int x,int y,int c[N][M],queue<ppi> &que)
{
  switch(q[x][y])
    {
    case 'P':
      calp(x,y,c,-1,que);
      return p[0];
    case 'R':
      calr(x,y,c,-1,que);
      return p[1];
    case 'K':
      calk(x,y,c,-1,que);
      return p[2];
    case 'B':
      calb(x,y,c,-1,que);
      return p[3];
    case 'Q':
      calq(x,y,c,-1,que);
      return p[4];
    case 'M':
      calm(x,y,c,-1,que);
      return p[5];
    default:
      //assert(0);
      break;
    }
  return 0;
}
void cal(int x,int y,int c[N][M])
{
  queue<ppi> qq;
  switch(q[x][y])
    {
    case '@':
      rx=x,ry=y;
      break;
    case 'P':
      calp(x,y,c,1,qq);
      break;
    case 'R':
      calr(x,y,c,1,qq);
      break;
    case 'K':
      calk(x,y,c,1,qq);
      break;
    case 'B':
      calb(x,y,c,1,qq);
      break;
    case 'Q':
      calq(x,y,c,1,qq);
      break;
    case 'M':
      calm(x,y,c,1,qq);
      break;
    case '#':
    case '.':
      break;
    default:
      assert(0);
      break;
    }
}
int c[N][M];
int z[N][M];
int ans(int x,int y,int queen)
{
  memset(cg,0,sizeof(cg));
  memset(z,0,sizeof(z));
  memcpy(c,cnt,sizeof(c));
  queue<ppi> que;
  z[x][y]=1;
  que.push(ppi(x,y));
  cg[x][y]=1;
  int r(0);
  for(;!que.empty();que.pop())
    {
      ppi v=que.front();
      int xx=v.first,yy=v.second;
      if(queen)
	{
	  FOR(i,0,8)
	    {
	      for(int a=xx+dirq[i][0],b=yy+dirq[i][1];inr(a,b) && q[a][b]!='#' && z[a][b]==0;a+=dirq[i][0],b+=dirq[i][1])
		{
		  cg[a][b]=1;
		  if(c[a][b]==0)
		    que.push(ppi(a,b)),z[a][b]=1;
		  else if(q[a][b]!='.' && q[a][b]!='@')
		    {
		      break;
		    }
		}
	    }
	}
      else
	{
	  FOR(i,0,8)
	    {
	      int a=xx+dirk[i][0],b=yy+dirk[i][1];
	      if(inr(a,b) && q[a][b]!='#')
		{
		  cg[a][b]=1;
		  if(z[a][b]==0 && c[a][b]==0)
		    z[a][b]=1,que.push(ppi(a,b));
		}
	    }
	}
      if(q[xx][yy]!='.' && q[xx][yy]!='#' && q[xx][yy]!='@')
	{
	  // if(x==4&&y==2)
	  //   cout<<q[xx][yy]<<' '<<sc[q[xx][yy]]<<endl;
	  r+=sc[q[xx][yy]];
	  queue<ppi> lst;
	  uncal(xx,yy,c,lst);
	  for(;!lst.empty();lst.pop())
	    {
	      ppi vv=lst.front();
	      int vx=vv.first,vy=vv.second;
	      if(cg[vx][vy])
		que.push(ppi(vx,vy)),z[vx][vy]=1;
	    }
	}
    }
  int add(0);
  FOR(i,0,n)
    FOR(j,0,m)
    if(z[i][j]==0 && cg[i][j] && q[i][j]!='.' && q[i][j]!='#' && q[i][j]!='@' && add<sc[q[i][j]])
      add=sc[q[i][j]];
  if(add>p[6])
    r+=(add-p[6]);
  // if(r==125)
  //   {
  //     for(int i=0;i<n;++i)
  // 	{
  // 	  for(int j=0;j<m;++j)
  // 	    cout<<z[i][j];
  // 	  cout<<endl;
  // 	}
  //     cout<<x<<' '<<y<<endl;
  //   }
  // cout<<r<<endl<<endl<<endl;;
  return r;
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,7)
    scanf("%d",p+i);
  sc['P']=p[0],sc['R']=p[1],sc['K']=p[2],sc['B']=p[3],
    sc['Q']=p[4],sc['M']=p[5];
  FOR(i,0,n)
    scanf("\n%s",q+i);
  FOR(i,0,n)
    FOR(j,0,m)
    cal(i,j,cnt);
  // FOR(i,0,n)
  //   {
  //     FOR(j,0,m)
  // 	cout<<cnt[i][j]<<' ';
  //     cout<<endl;
  //   }
  if(cnt[rx][ry]==0)
    {
      printf("%d",max(ans(rx,ry,1),ans(rx,ry,0)));
    }
  else
    {
      int aa(0);
      FOR(i,0,8)
	for(int a=rx+dirq[i][0],b=ry+dirq[i][1];inr(a,b) && q[a][b]!='#';a+=dirq[i][0],b+=dirq[i][1])
	  {
	    if(cnt[a][b]==0)
	      {
		//cout<<a<<' '<<b<<endl;
		aa=max(aa,ans(a,b,1));
		break;
	      }
	    if(q[a][b]!='.' && q[a][b]!='@')
	      aa=max(aa,sc[q[a][b]]-p[6]);
	  }
      FOR(i,0,8)
      	{
      	  int x=rx+dirk[i][0],y=ry+dirk[i][1];
      	  if(inr(x,y) && q[x][y]!='#')
      	    {
      	      if(cnt[x][y]==0)
      		{
      		  // cout<<x<<' '<<y<<endl;
      		  aa=max(aa,ans(x,y,0));
      		}
      	      else if(q[x][y]!='.' && q[x][y]!='#')
      		aa=max(aa,sc[q[x][y]]-p[6]);
      	    }
	}
      printf("%d\n",aa);
    }
  return 0;
}
