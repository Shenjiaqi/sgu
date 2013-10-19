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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 13
int p[N][N];
int dp[(1<<N)][2];
int t[13];
int n,m;
void pt(int k)
{
  if(dp[k][1]==k)
    {
      FOR(i,0,n)
	if((1<<i)&k)
	  printf("%c",(char)('a'+i));
      printf("\n");
    }
  else
    pt(dp[k][1]),pt(k^dp[k][1]);
}
bool test(int num)
{
  int cnt(0);
  FOR(i,0,num)
    FOR(j,0,num)
    if(p[t[i]][t[j]])
      if(cnt++)
	return false;
  return true;
}
int dfs(int k)
{
  if(dp[k][0]==0)
    {
      int num(0);
      for(int i=k;i;i^=(i&(-i)))
	t[num++]=__builtin_ctz(i);
      if(test(num))
	dp[k][0]=1,dp[k][1]=k;
      else
	{
	  dp[k][0]=1e9;
	  for(int i=k&(k-1);i>=(k^i);i=(i-1)&k)
	    {
	      int m=dfs(i)+dfs(k^i);
	      if(m<dp[k][0])
		dp[k][0]=m,dp[k][1]=i;
	    }
	}
    }
  return dp[k][0];
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  FOR(i,0,m)
    {
      char tmp[3];
      scanf("%s",tmp);
      p[tmp[0]-'a'][tmp[1]-'a']=1;
    }
  printf("%d\n",dfs((1<<n)-1));
  pt((1<<n)-1);
  return 0;
}
