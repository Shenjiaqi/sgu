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
#define N 21
int s[2][N];
int w[1<<N];
int ww[1<<N];
int c[2];
int sum[2];
int dp[1<<N][N];
int dfs(int v)
{
  if(w[v]==0)
    {
      int t=v&(-v);
      w[v]=w[t]+dfs(v^t);
      ww[v]=max(w[t],ww[v^t]);
    }
  return w[v];
}
int cal(int a,int b,int d,int dd)
{
  if(a==0 || b==0)
    {
      if(b)
	a=b;
      return (a==(a&(-a))?0:N);
    }
  int c=a|b;
  if(dp[c][dd]==0)
    {
      if(b&d)
	swap(a,b);
      int t=a^d;
      int r(N);
      if(!(w[a]>w[b] && w[t]>w[b]) && !(w[b]-ww[b]>w[t]))
	for(int i=b|t,j=0;i;++j,i^=(i&(-i)))
	  r=min(r,cal(t,b,i&(-i),j)+(w[t]==w[b]?0:1));
      dp[c][dd]=r;
    }
  return dp[c][dd];
}
int main()
{
  int n;
  scanf("%d",&n);
  FOR(i,0,2)
    FOR(j,0,n)
    scanf("%d",&s[i][j]);
  FOR(i,0,n)
    if(s[0][i]<s[1][i])
      sum[1]+=(ww[1<<c[1]]=w[1<<c[1]]=s[1][i]-s[0][i]),++c[1];
  FOR(i,0,n)
    if(s[0][i]>s[1][i])
      sum[0]+=(ww[1<<(c[0]+c[1])]=w[1<<(c[0]+c[1])]=s[0][i]-s[1][i]),++c[0];
  if(sum[0]==sum[1])
    {
      if(c[0])
	{
	  FOR(i,1,(1<<c[1]))
	    dfs(i);
	  FOR(i,1,(1<<c[0]))
	    dfs(i<<c[1]);
	  int a=((1<<c[0])-1)<<c[1];
	  int b=(1<<c[1])-1;
	  int ans(N);
	  for(int i=a|b,j=0;i;i^=(i&(-i)),++j)
	    ans=min(ans,cal(a,b,i&(-i),j));
	  printf("%d",ans);
	}
      else printf("0");
    }
  else printf("-1");
  return 0;
}
