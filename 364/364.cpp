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
#define M 107
int n,s;
int x,h,a,b,cnt;
int p[M][3];
bool vis[M][2];
int dp[M][2][2];
int ans[2];
int cmp(const void *a, const void *b)
{
  return *((int*)b+2)-*((int*)a+2);
}
void dfs(int lev, int dir, int x, int y,int costn, int costt)
{
  // if(lev>=0)
  //   cout<<lev<<' '<<dp[lev][1][0]<<' '<<dp[lev][1][1]<<endl;
  int nxt=-1;
  for(int i=lev+1;i<cnt;++i)
    if(p[i][2]<y && p[i][0]<x && x<p[i][1])
      {
	nxt=i;
	break;
      }
  if(x==a)
    {
      if(y>=b && (nxt==-1 || p[nxt][2]<=b))
	{
	  if(ans[0]>costn || 
	     (ans[0]==costn &&
	      ans[1]>costt+b-y))
	    {
	      ans[0]=costn,
		ans[1]=costt+y-b;
	      // cout<<lev<<endl;
	    }
	}
    }
  if(nxt>=0)
    {
      costt+=y-p[nxt][2];
      if(vis[nxt][dir]==false || 
	 dp[nxt][dir][0]>costn ||
	 (dp[nxt][dir][0]==costn && 
	  dp[nxt][dir][1]>costt+abs(p[nxt][dir]-x)))
	dp[nxt][dir][0]=costn,
	  dp[nxt][dir][1]=costt+abs(p[nxt][dir]-x),
	  vis[nxt][dir]=true;;
      dir^=1;
      costn+=1;
      if(vis[nxt][dir]==false ||
	 dp[nxt][dir][0]>costn ||
	 (dp[nxt][dir][0]==costn &&
	  dp[nxt][dir][1]>costt+abs(p[nxt][dir]-x)))
	dp[nxt][dir][0]=costn,
	  dp[nxt][dir][1]=costt+abs(p[nxt][dir]-x),
	  vis[nxt][dir]=true;
      // if(nxt==3)
      // 	cout<<lev<<' '<<dir<<endl;
    }
}
int main()
{
  int m;
  scanf("%d%d%d%d%d%d%d",&n,&s,&x,&h,&a,&b,&m);
  FOR(i,0,m)
    {
      scanf("%d%d%d",&p[cnt][0],&p[cnt][1],&p[cnt][2]);
      if(p[i][2]==b && p[i][0]<a && p[i][1]>a)
	{
	  ++cnt;
	  p[cnt][2]=p[cnt-1][2];
	  p[cnt][0]=a;
	  p[cnt][1]=p[cnt-1][1];
	  p[cnt-1][1]=a;
	}
      ++cnt;
    }
  qsort(p,cnt,sizeof(p[0]),cmp);
  ans[0]=n;
  dfs(-1,1,x,h,0,0);
  for(int i=0;i<cnt;++i)
    for(int j=0;j<2;++j)
      if(vis[i][j])
	dfs(i,j,p[i][j],p[i][2],dp[i][j][0],dp[i][j][1]);
  int num=n-ans[0];
  int time=(n-1)*s+ans[1];
  if(num==0)
    time=0;
  printf("%d %d",num,time);
  return 0;
}
