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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 27
int p[N*3];
bool vis[N*3];
int e[N*3];
int est2[N*3][N];
int a[N],c[N];
int n,lim;
ll cnt;
int ans;
// int est(int s,int lev)
// {
//   int r(0);
//   for(int i=0,j=lev*2;i<lev;++i)
//     {
//       for(;vis[s];--s)
// 	;
//       int a=p[s--];
//       --j;
//       for(;vis[s];--s)
// 	;
//       r+=a*p[s];
//       --j;
//       if(j<=lev)
// 	r-=p[n-j+1]*p[s];
//       --s;
//     }
//   return r;
// }
void dfs(int lev,int l,int r,int num)
{
  if(lev==0)
    ans=max(ans,num);
  else
    {
      for(;vis[l];--l)
	;
      if((p[l]-p[n-lev+1])*p[l-1]*lev+num>ans)
	{
	  vis[l]=true;
	  a[lev]=p[l];
	  r=min(min(3*n-((n-lev)*2+1),r),l-1);
	  for(int pre=-1;r>=n+lev;--r)
	    if(!vis[r] && p[r]!=pre)
	      {
		pre=c[lev]=p[r];
		int t1=(a[lev+1]-p[n-lev-1+1]-c[lev]),t2=(c[lev+1]-a[lev]);
		int tmp=t1*t2;
		vis[r]=true;
		if(lev==n || tmp>=0)
		  dfs(lev-1,l-1,r-1,num+(a[lev]-p[n-lev+1])*c[lev]);
		vis[r]=false;
		if(lev<n && t1>0 && t2<0)
		  break;
	      }
	  vis[l]=false;
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d%d",&t,&n);
  for(;t--;)
    {
      for(int i=1;i<=3*n;++i)
      	scanf("%d",p+i);
      sort(p,p+3*n);
      ans=0;
      dfs(n,3*n,3*n-1,0);
      cout<<ans<<endl;
    }
  return 0;
}
