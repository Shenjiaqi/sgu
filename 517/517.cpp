#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
#define N 1000
vector<int> dp[N+1][4];
const int base=1000000000;
void add(vector<int> &t,vector<int> &f)
{
  int c=0,i=0,l=f.size();
  for(;i<l && i<1000;++i)
    {
      if(t.size()<=i)
	t.resize(i+1);
      c+=t[i]+f[i];
      t[i]=c%base;
      c/=base;
    }
  for(;c && i<1000;++i)
    {
      if(t.size()<=i)
	t.resize(i+1);
      c+=t[i];
      t[i]=c%base;
      c/=base;
    }
}
void pt(vector<int> &v)
{
  if(v.size()==0)
    printf("0");
  else
    {
      int i=v.size()-1;
      for(;i>0 && v[i]==0;--i)
	;
      printf("%d",v[i]);
      for(--i;i>=0;--i)
	printf("%09d",v[i]);
    }
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  if(n>m)
    {
      int tmp=n;
      n=m,m=tmp;
    }
  if(n==1)
    printf("%c",(m&1?'0':'1'));
  else if(n==2)
    {
      for(int i=0;i<=N;++i)
	for(int j=0;j<2;++j)
	  dp[i][j].resize(1);
      dp[1][0][0]=dp[2][1][0]=1;
      for(int i=1;i<m;++i)
	if(i+1<=m)
	  {
	    add(dp[i+1][0],dp[i][0]);
	    add(dp[i+1][0],dp[i][1]);
	    if(i+2<=m)
	      add(dp[i+2][1],dp[i][0]);
	  }
      add(dp[m][0],dp[m][1]);
      pt(dp[m][0]);
    }
  else if(n==3)
    {
      for(int i=0;i<=N;++i)
	for(int j=0;j<4;++j)
	  dp[i][j].resize(1);
      dp[2][0][0]=dp[2][1][0]=1;
      dp[4][2][0]=dp[4][3][0]=1;
      for(int i=1;i<m;++i)
	{
	  if(i+2<=m)
	    {
	      add(dp[i+2][0],dp[i][1]);
	      add(dp[i+2][1],dp[i][0]);
	      add(dp[i+2][0],dp[i][3]);
	      add(dp[i+2][1],dp[i][2]);
	      if(i+4<=m)
		{
		  add(dp[i+4][2],dp[i][1]);
		  add(dp[i+4][3],dp[i][0]);
		  add(dp[i+4][2],dp[i][3]);
		  add(dp[i+4][3],dp[i][2]);
		}
	    }
	}
      for(int i=1;i<4;++i)
	add(dp[m][0],dp[m][i]);
      pt(dp[m][0]);
    }
  else
    {
      if(n&1)
	{
	  int c=n+1;
	  for(int i=0;i<=N;++i)
	    for(int j=0;j<4;++j)
	      dp[i][j].resize(1);
	  if(c<=m)
	    dp[c][0][0]=dp[c][2][0]=1;
	  if(c-2<=m)
	    dp[c-2][1][0]=dp[c-2][3][0]=1;
	  for(int i=1;i<m;++i)
	    {
	      if(i+c-2<=m)
		{
		  add(dp[i+c-2][1],dp[i][2]);
		  add(dp[i+c-2][1],dp[i][3]);
		  add(dp[i+c-2][3],dp[i][0]);
		  add(dp[i+c-2][3],dp[i][1]);
		  if(i+c<=m)
		    {
		      add(dp[i+c][0],dp[i][2]);
		      add(dp[i+c][0],dp[i][3]);
		      add(dp[i+c][2],dp[i][0]);
		      add(dp[i+c][2],dp[i][1]);
		    }
		}
	    }
	  for(int i=1;i<4;++i)
	    add(dp[m][0],dp[m][i]);
	  pt(dp[m][0]);
	}
      else
	{
	  for(int i=0;i<=N;++i)
	    for(int j=0;j<3;++j)
	      dp[i][j].resize(1);
	  dp[n][0][0]=dp[1][1][0]=dp[n-2][2][0]=1;
	  for(int i=1;i<m;++i)
	    {
	      if(i+1<=m)
		{
		  add(dp[i+1][1],dp[i][0]);
		  add(dp[i+1][1],dp[i][2]);
		  if(i+n-2<=m)
		    {
		      add(dp[i+n-2][2],dp[i][1]);
		      if(i+n<=m)
			{
			  add(dp[i+n][0],dp[i][1]);
			}
		    }
		}
	    }
	  add(dp[m][0],dp[m][1]);
	  add(dp[m][0],dp[m][2]);
	  pt(dp[m][0]);
	}
    }
  return 0;
}
