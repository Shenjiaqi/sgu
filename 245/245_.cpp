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
int q[N][M];
int cnt[N][M];
int rx,ry;
int n,m;
bool inr(int x,int y)
{
  return (x<n && x>=0 && y<m && y>=0);
}
const static dirq[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
const static dirk[][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
const static dirb[][2]={{1,1},{-1,-1},{1,-1},{-1,1}};
const static dirr[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int score[255];
void calP(int x,int y,int c[N][M],int num)
{
  if(inr(x-1,y-1))
    c[x-1][y-1]+=num;
  if(inr(x-1,y+1))
    c[x-1][y+1]+=num;
}
void calm(int x,int y,int c[N][M],int num)
{
  FOR(i,-1,2)
    FOR(j,-1,2)
    if(i!=0 || j!=0)
      {
	int xx=x+i,yy=y+j;
	if(inr(xx,yy))
	  c[xx][yy]+=num;
      }
}
void calq(int x,int y,int c[N][M],int num)
{
  FOR(i,0,8)
    for(int xx=x+dirq[i][0],yy=y+diq[i][1];inr(xx,yy);xx+=dirq[i][0],yy+=dirq[i][1])
      {
	c[xx][yy]+=num;
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
void calB(int x,int y,int c[N][M],int num)
{
  FOR(i,0,4)
    for(int xx=x+dirb[i][0],yy=y+dir[i][1];inr(xx,yy);xx+=dirb[i][0],yy+=dirb[i][1])
      {
	c[xx][yy]+=num;
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
void calK(int x,int y,int c[N][M],int num)
{
  FOR(i,0,8)
    {
      int xx=x+dirk[i][0],yy=y+dirk[i][1];
      if(inr(xx,yy))
	c[xx][yy]+=num;
    }
}
void calR(int x,int y,int c[N][M],int num)
{
  FOR(i,0,4)
    for(int xx=x+dirr[i][0],yy=y+dirr[i][1];inr(xx,yy);xx+=dirr[i][0],yy+=dirr[i][1])
      {
	c[xx][yy]+=num;
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
int uncal(int x,int y,int c[N][M])
{
  switch(q[x][y])
    {
    case 'P':
      calP(x,y,c,-1);
      return p[0];
    case 'R':
      calR(x,y,c,-1);
      return p[1];
    case 'K':
      calK(x,y,c,-1);
      return p[2];
    case 'B':
      calB(x,y,c,-1);
      return p[3];
    case 'Q':
      calC(x,y,c,-1);
      return p[4];
    case 'M':
      calM(x,y,c,-1);
      return p[5];
    default:
      break;
    }
  return 0;
}
void cal(int x,int y,int c[N][M])
{
  switch(q[i][j])
    {
    case '@':
      rx=x,ry=y;
      break;
    case 'P':
      calP(x,y,c,1);
      break;
    case 'R':
      calR(x,y,c,1);
      break;
    case 'K':
      calK(x,y,c,1);
      break;
    case 'B':
      calB(x,y,c,1);
      break;
    case 'Q':
      calC(x,y,c,1);
      break;
    case 'M':
      calM(x,y,c,1);
      break;
    default:
      break;
    }
}
bool ok(int x,int y,int z[N][M],int count[N][M])
{
  return (z[x][y]==0 && count[x][y]==0);
}
bool add(int x,int y,int z[N][M],int count[N][M],queue<ppi> &que)
{
  if(ok(x,y,z,count))
    {
      que.push(ppi(x,y)),z[x][y]=1;
      return (q[x][y]=='.' || q[x][y]=='@');
    }
  return false;
}
void fill(int x,int y,int z[N][M],int count[N][M],queue<ppi> &que,int queen)
{
  if(queen)
    {
      for(int k=0;k<8;++k)
	for(int i=x+dirq[k][0],j=y+dirq[k][1];inr(i,j) && add(i,j,z,count,q);i+=dirq[k][0],j+=dirq[k][1])
	  ;
    }
  else
    {
      FOR(i,0,8)
	{
	  int xx=x+dirk[i][0],yy=y+dirk[j][1];
	  if(inr(xx,yy))
	    add(xx,yy,z,count,q);
	}
    }
}
int att(int z[N][M],int queen,int mi)
{
  int r(0);
  FOR(i,0,n)
    FOR(j,0,m)
    if(q[i][j]!='.' && q[i][j]!='@' && z[i][j]==0 && r<score[q[i][j]] && mi<score[q[i][j]])
      {
	if(queen)
	  {
	    FOR(k,0,8)
	      for(int x=i+dirq[k][0],y=j+dirq[k][1];inr(x,y) && (q[x][y]=='.' || q[x][y]=='@');x+=dirq[k][0],y+=dirq[k][1])
		if(z[x][y])
		  {
		    r=score[q[i][j]];
		    break;
		  }
	  }
	else
	  FOR(k,0,8)
	    {
	      int xx=x+dirk[k][0],yy=y+dirk[k][1];
	      if(inr(xx,yy) && z[xx][yy])
		{
		  r=score[q[i][j]];
		  break;
		}
	    }
      }
  return r;
}
int an(int x,int y,int queen)
{
  int ans(0);
  queue<ppi> que;
  int z[N][M]={0};
  int ccnt[N][M];
  memcpy(ccnt,cnt,sizeof(cnt));
  fill(x,y,z,ccnt,que,queen);
  for(;!que.empty();)
    {
      ppi v=que.front();
      que.pop();
      int xx=v->first,yy=v->second;
      if(q[xx][yy]!='@' && q[xx][yy]!='.' && z[xx][yy]==0)
	{
	  ans+=uncal(xx,yy,ccnt);
	}
      fill(xx,yy,z,ccnt,que,queen);
    }
  int ma=att(z,queen,p[6]);
  if(ma>p[6])
    ans+=ma-p[6];
  return ans;
}
//"P" - pawn, "R" - rook, "K" - knight, "B" - bishop, "Q" - queen, "M" - king, "@" - your starting point 
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,7)
    scanf("%d",p+i);
  score['P']=p[0],score['R']=p[1],score['K']=p[2],
    score['B']=p[3],score['Q']=p[4],score['M']=p[5];
  FOR(i,0,n)
    {
      char _n;
      scanf("%c",&_n);
      FOR(j,0,m)
	scanf("%c",&q[i][j]);
    }
  FOR(i,0,n)
    FOR(j,0,m)
    cal(i,j,cnt);
  if(cnt[x][y]==0)
    {
      printf("%d",max(an(x,y,0),an(x,y,1)));
    }
  else
    {
      int ans(0);
      FOR(i,0,8)
	for(int xx=x+dirq[i][0],yy=y+dir[i][1];inr(xx,yy);xx+=dirq[i][0],yy+=dirq[i][1])
	  if(cnt[xx][yy]==0)
	    {
	      ans=max(ans,an(xx,yy,1));
	      break;
	    }
      FOR(i,0,8)
	{
	  int xx=x+dirk[i][0],yy=y+dirk[i][1];
	  if(inr(xx,yy))
	    ans=max(ans,an(xx,yy,0));
	}
      printf("%d",ans);
    }
  return 0;
}
