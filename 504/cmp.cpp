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
using namespace std;
typedef long long ll;
#define N 700
char p[N][N+1];
int h,w;
ll q[N][N][10][4];
typedef pair<ll,ll> pp;
ll hash(ll a,ll b,ll c,ll d)
{
  if(a==0)
    a=1313131313131313131LL;
  if(b==0)
    b=1717171717171717171LL;
  if(c==0)
    c=3737373737373737373LL;
  if(d==0)
    d=7373737373737373737LL;
  const ll mod=2305843009213693951LL;
  a*=1711711171111711111LL;
  b*=3733733373333733333LL;
  c*=7377377737777377777LL;
  d*=1311311131111311111LL;
  ll r=(a<<1)^(b<<2)^(c<<3)^(d<<4);
  return r%mod;
}
bool check1(int x,int y,int a)
{
  int k=1,j=0;
  for(;2*k<=a;k<<=1,++j)
    ;
  if(q[x][y][j][0]==q[x][y][j][1] && 
     q[x][y][j][2]==q[x][y][j][3] && q[x][y][j][0]==q[x][y][j][2])
    {
      if(a>k)
	{
	  int d=a-k;
	  if(q[x-d][y][j][0]==q[x-d][y][j][1] && q[x+d][y][j][2]==q[x+d][y][j][3] &&
	     q[x-d][y][j][0]==q[x+d][y][j][2])
	    {
	      if(q[x][y-d][j][0]==q[x][y+d][j][1] && q[x][y+d][j][2]==q[x][y-d][j][3] && 
		 q[x][y-d][j][0]==q[x][y+d][j][2])
		{
		  if(q[x-d][y-d][j][0]==q[x-d][y+d][j][1] &&
		     q[x+d][y+d][j][2]==q[x+d][y-d][j][3] &&
		     q[x-d][y-d][j][0]==q[x+d][y+d][j][2])
		    return true;
		}
	    }
	}
      else return true;
    }
  return false;
}
bool check2(int xx,int yy,int a)
{
  int k=1,j=0;
  for(;2*k<=a;k<<=1,++j)
    ;
  int x[4],y[4];
  x[0]=xx-1,y[0]=yy-1;
  x[1]=xx-1,y[1]=yy;
  x[2]=xx,y[2]=yy;
  x[3]=xx,y[3]=yy-1;
  if(q[x[0]][y[0]][j][0]==q[x[1]][y[1]][j][1] && 
     q[x[2]][y[2]][j][2]==q[x[3]][y[3]][j][3] &&
     q[x[0]][y[0]][j][0]==q[x[2]][y[2]][j][2])
    {
      if(a>k)
	{
	  int d=a-k;
	  if(q[x[0]-d][y[0]][j][0]==q[x[1]-d][y[1]][j][1] && 
	     q[x[2]+d][y[2]][j][2]==q[x[3]+d][y[3]][j][3] &&
	     q[x[0]-d][y[0]][j][0]==q[x[2]+d][y[2]][j][2])
	    {
	      if(q[x[0]][y[0]-d][j][0]==q[x[1]][y[1]+d][j][1] &&
		 q[x[2]][y[2]+d][j][2]==q[x[3]][y[3]-d][j][3] && 
		 q[x[0]][y[0]-d][j][0]==q[x[2]][y[2]+d][j][2])
		{
		  if(q[x[0]-d][y[0]-d][j][0]==q[x[1]-d][y[1]+d][j][1] &&
		     q[x[2]+d][y[2]+d][j][2]==q[x[3]+d][y[3]-d][j][3] &&
		     q[x[0]-d][y[0]-d][j][0]==q[x[2]+d][y[2]+d][j][2])
		    return true;
		}
	    }
	}
      else return true;
    }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&h,&w);
  for(int i=0;i<h;++i)
    scanf("%s",*(p+i));
  for(int i=0;i<h;++i)
    for(int j=0;j<w;++j)
      for(int k=0;k<4;++k)
	q[i][j][0][k]=hash(0,0,0,p[i][j]);
  for(int i=0;;++i)
    {
      int tmp=1<<(1+i);
      if(tmp-1>h-tmp || tmp-1>w-tmp)
	break;
      int t=tmp>>1;
      for(int j=tmp-1;j<=h-tmp;++j)
	for(int k=tmp-1;k<=w-tmp;++k)
	  {
	    q[j][k][i+1][0]=hash(q[j-t][k-t][i][0],q[j-t][k][i][0],q[j][k][i][0],q[j][k-t][i][0]);
	    q[j][k][i+1][1]=hash(q[j-t][k+t][i][1],q[j-t][k][i][1],q[j][k][i][1],q[j][k+t][i][1]);
	    q[j][k][i+1][2]=hash(q[j+t][k+t][i][2],q[j+t][k][i][2],q[j][k][i][2],q[j][k+t][i][2]);
	    q[j][k][i+1][3]=hash(q[j+t][k-t][i][3],q[j+t][k][i][3],q[j][k][i][3],q[j][k-t][i][3]);
	  }
    }
  int ans[2]={0};
  ans[1]=0;
  int rc[2][2];
  for(int j=0;j<h;++j)
    for(int k=0;k<w;++k)
      {
	for(int f=ans[0]+1,l=min(min(j+1,h-j),min(k+1,w-k));f<=l;)
	  {
	    int mid=(f+l)/2;
	    if(check1(j,k,mid))
	      f=mid+1,ans[0]=mid,rc[0][0]=j,rc[0][1]=k;
	    else l=mid-1;
	  }
	for(int f=ans[1]+1,l=min(min(j,k),min(h-j,w-k));f<=l;)
	  {
	    int mid=(f+l)>>1;
	    if(check2(j,k,mid))
	      f=mid+1,ans[1]=mid,rc[1][0]=j,rc[1][1]=k;
	    else l=mid-1;
	  }
      }
  if(ans[0]>ans[1])
    {
      printf("%d %d %d %d",rc[0][0]-ans[0]+2,rc[0][1]-ans[0]+2,
	     rc[0][0]+ans[0],rc[0][1]+ans[0]);
    }
  else
    {
      printf("%d %d %d %d",rc[1][0]-ans[1]+1,rc[1][1]-ans[1]+1,
	     rc[1][0]+ans[1],rc[1][1]+ans[1]);
    }
  return 0;
}
