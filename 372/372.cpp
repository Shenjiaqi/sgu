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
typedef pair<int,int> pp;
#define N 1000
#define K 1000
vector<pp> p[2];
ll dp[K+1][N+1][2][2];
int frm[K+1][N+1][2][2];
int main()
{
  freopen("in","r",stdin);
  int k,n;
  scanf("%d%d",&k,&n);
  for(int i=0,c,s;i<n;++i)
    {
      scanf("%d%d",&c,&s);
      p[s].push_back(pp(c,i+1));
    }
  memset(dp,1<<5,sizeof(dp));
  sort(p[0].begin(),p[0].end());
  sort(p[1].begin(),p[1].end());
  ll inf=dp[0][0][0][0];
  if(p[0].size())
    dp[1][1][0][0]=(ll)k*p[0][0].first,frm[1][1][0][0]=0;
  if(p[1].size())
    dp[1][0][1][0]=(ll)k*p[1][0].first,frm[1][0][1][0]=4;
  for(int i=2;i<=k;++i)
    for(int j=(i-1)/3;j<i-(i-1)/3;++j)
      {
	int l=i-1-j;
	ll num=k-i+1;
	ll t;
	ll tmp=dp[i-1][j][0][0];
	if(tmp<inf)
	  {
	    if(j<p[0].size() && dp[i][j+1][0][1]>tmp+num*(ll)p[0][j].first)
	      dp[i][j+1][0][1]=tmp+num*(ll)p[0][j].first,frm[i][j+1][0][1]=0;
	    if(l<p[1].size() && dp[i][j][1][0]>tmp+num*(ll)p[1][l].first)
	      dp[i][j][1][0]=tmp+num*(ll)p[1][l].first,frm[i][j][1][0]=4;
	  }
	tmp=dp[i-1][j][1][0];
	if(tmp<inf)
	  {
	    if(j<p[0].size() && dp[i][j+1][0][0]>tmp+num*(ll)p[0][j].first)
	      dp[i][j+1][0][0]=tmp+num*(ll)p[0][j].first,frm[i][j+1][0][0]=2;
	    if(l<p[1].size() && dp[i][j][1][1]>tmp+num*(ll)p[1][l].first)
	      dp[i][j][1][1]=tmp+num*(ll)p[1][l].first,frm[i][j][1][1]=6;
	  }
	tmp=dp[i-1][j][0][1];
	if(tmp<inf && l<p[1].size() && dp[i][j][1][0]>tmp+num*(ll)p[1][l].first)
	  dp[i][j][1][0]=tmp+num*(ll)p[1][l].first,frm[i][j][1][0]=5;
	tmp=dp[i-1][j][1][1];
	if(tmp<inf && j<p[0].size() && dp[i][j+1][0][0]>tmp+num*(ll)p[0][j].first)
	  dp[i][j+1][0][0]=tmp+num*(ll)p[0][j].first,frm[i][j+1][0][0]=3;
      }
  ll a=inf;
  int ii,jj,ll;
  for(int i=0;i<=k;++i)
    for(int j=0;j<2;++j)
      for(int l=0;l<2;++l)
	if(dp[k][i][j][l]<a)
	  a=dp[k][i][j][l],ii=i,jj=j,ll=l;
  if(a>=inf)
    printf("Impossible");
  else
    {
      vector<int> ans;
      for(;k;--k)
	{
	  int tmp=frm[k][ii][jj][ll];
	  ll=((tmp&1)?1:0);
	  jj=((tmp&2)?1:0);
	  if(tmp&4)
	    ans.push_back(p[1][k-ii-1].second);
	  else
	    ans.push_back(p[0][ii-1].second),--ii;
	}
      for(int i=ans.size()-1;i>=0;--i)
	printf("%d ",ans[i]);
    }
  return 0;
}
