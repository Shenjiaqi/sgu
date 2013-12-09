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
typedef pair<ld,ld> ppld;
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 307
int n,m;
char p[N][N];
int q[N][N][2];
const int dir[]={-1,0,1};
queue<int> que;
bool inRng(int x,int y)
{
  return x>=0 && y>=0 && x<n && y<n;
}
void push(int x,int y,int s)
{
  q[x][y][s&1]=s;
  que.push((x<<11)|(y<<1)|(s&1));
}
void front(int &x,int &y,int &s)
{
  int v=que.front();
  x=v>>11;
  y=(v&((1<<11)-1))>>1;
  s=q[x][y][v&1];
}
void pop()
{
  que.pop();
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    scanf("%s",p+i);

  int x,y;
  FOR(i,0,n)
    FOR(j,0,n)
    if(p[i][j]=='Q')
      {
	x=i,y=j;
	p[i][j]=0;
      }
    else if(p[i][j]=='.')
      p[i][j]=0;
    else if(p[i][j]=='W')
      p[i][j]=1;
    else if(p[i][j]=='B')
      p[i][j]=2;
    else return 1;

  memset(q,1<<7,sizeof(q));
  push(x,y,m);
  for(;!que.empty();pop())
    {
      int stp;
      front(x,y,stp);
      --stp;
      // cout<<x<<' '<<y<<' '<<stp<<endl;
      if(stp>=0)
	FOR(i,0,3)
	  FOR(j,0,3)
	  {
	    int dx=dir[i],dy=dir[j];
	    if(dx!=0 || dy!=0)
	      {
		bool c1,c2;
		c1=c2=true;
		for(int xx=x+dx,yy=y+dy;(c1 || c2) && inRng(xx,yy);xx+=dx,yy+=dy)
		  if(p[xx][yy]==1)
		    break;
		  else
		    {
		      if(c1 && q[xx][yy][stp&1]<stp)
			  push(xx,yy,stp);
		      else if(xx!=dx+x && q[xx][yy][stp&1]>=stp+2)
			c1=false;
		      int st=stp-1;
		      if(c2 && st>=0 && q[xx][yy][st&1]<st)
			{
			  if(xx!=x+dx)
			    push(xx,yy,st);
			  else
			    {
			      int xxx=x-dx,yyy=y-dy;
			      if(inRng(xxx,yyy) && p[xxx][yyy]!=1)
				push(xx,yy,st);
			    }
			}
		      else if(0>st || (xx!=x+dx && q[xx][yy][st&1]>=st+2))
			c2=false;
		      if(p[xx][yy]==2)
			break;
		    }
	      }
	  }
    }
  int cnt=0,ans=0;
  FOR(i,0,n)//{
    FOR(j,0,n)
    {
      //cout<<q[i][j][0]<<' '<<q[i][j][1]<<"  ";
      if(q[i][j][0]>=0)
	++ans,++cnt;
      else if(q[i][j][1]>=0)
	++cnt;
    }//cout<<endl;}
  if(m>0 && cnt==1)
    printf("0");
  else printf("%d",ans);
  return 0;
}
