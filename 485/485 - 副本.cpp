#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 27
int p[N*3];
int dp[N][N][N][N];
int t,n;
int cal(int l,int r,int ll,int rr,int left)
{
  if(ll>0)
    {
      
    }
}
int dfs(int l,int r,int ll,int rr)
{
  if(l>n && r>n)
    return 0;
  if(l>n)
    return dfs(l-1,r+1,0,rr+1);
  if(r>n)
    return dfs(l+1,r-1,ll+1,0);
  if(dp[l][r][ll][rr])
    return dp[l][r][ll][rr];
  int tmp=dfs(l+1,r,ll+1,0)+cal(l,r,ll,rr,true);
  tmp=max(dfs(l,r+1,0,rr+1)+cal(l,r,ll,rr,false),tmp);
  return dp[l][r][ll][rr]=tmp;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&t,&n);
  if(n>25)
    return 1;
  for(;t--;)
    {
      for(int i=0;i<n*3;++i)
	scanf("%d",p+i);
      sort(p,p+n*3);
      memset(dp,0,sizeof(dp));
      printf("%d\n",dfs(0,0,0,0));
    }
  return 0;
}
