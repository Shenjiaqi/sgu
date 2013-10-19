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
int e[N*3][N];
int a[N],c[N];
int n,lim;
int dfs(int l,int r,int s,int sum,int num)
{
  if(s<n || num>=lim)
    return num>=lim?num:0;
  //cout<<l<<' '<<r<<' '<<num<<' '<<sum*p[s]<<' '<<lim<<' '<<s<<endl;
  if((ll)num+(ll)sum*(ll)p[s]+(ll)(l>=0?e[s][l]:0)<lim)
    return 0;
  if(l<r)
    {
      int t1=(a[r+1]-p[n-1-(r+1)]-p[s]);
      int t2=(c[r+1]-a[r]);
      if(r==n-1 || (t1>=0 && t2>=0) || (t1<=0 && t2<=0) )
      {
	  c[r]=p[s];
	  int tmp=dfs(l,r-1,s-1,sum-a[r]+p[n-1-r],
		      num+(a[r]-p[n-1-r])*c[r]);
	  if(tmp>0)
	    return tmp;
      }
      if(r<n-1 && t2<0 && t1>0)
	return 0;
    }
  if(l>=0)
    {
      a[l]=p[s];
      return dfs(l-1,r,s-1,sum+a[l]-p[n-1-l],num);
    }
  return 0;
}
int cal(int s,int l)
{
  int f=max(s>0?e[s-1][l]:0,(s>1 && l>0)?e[s-2][l-1]:0);
  int t=f+(s>0?(p[s]-p[n-1-l])*p[s-1]:0);
  cout<<f<<' '<<t<<endl;
  int r=0;
  for(;f<=t;)
    {
      lim=(f+t)>>1;
      int tmp=dfs(l,l,s,0,0);
      if(tmp>=lim)
	f=tmp+1,r=tmp;
      else t=lim-1;
    }
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d%d",&t,&n);
  for(;t--;)
    {
      FOR(i,0,3*n)
	scanf("%d",p+i);
      sort(p,p+3*n);
      // memset(e,0,sizeof(e));
      // e[n][0]=(p[n]-p[0])*p[n-1];
      // for(int i=n;i<3*n;++i)
      // 	for(int j=0;j<(i-n+2)/2;++j)
      // 	  {
      // 	    if(i!=n || j)
      // 	      e[i][j]=cal(i,j);
      // 	    cout<<e[i][j]<<endl;
      // 	  }
      for(int i=0;i<3*n;++i)
	for(int j=0;j<n;++j)
	  {
	    e[i][j]=0;
	    for(int k=i,l=j;k>=n && l>=0;--k,--l)
	      e[i][j]+=(p[k]-p[n-1-l])*p[k-1];
	  }
      //cout<<e[3*n-1][n-1]<<endl;
      int ans=0;
      for(int f=0,l=e[3*n-1][n-1];f<=l;)
	{
	  lim=(f+l)>>1;
	  int tmp=dfs(n-1,n-1,3*n-1,0,0);
	  cout<<lim<<' '<<tmp<<endl;
	  if(tmp>=lim)
	    f=tmp+1,ans=tmp;
	  else l=lim-1;
	  }
      printf("%d\n",e[3*n-1][n-1]);
    }
  return 0;
}
