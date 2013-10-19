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
#define N 100000
int p[N];
int pre[N];
int q[3][3];
void dfs(int v)
{
  if(v>=0)
    {
      dfs(pre[v]);
      printf("%d ",p[v]);
    }
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  FOR(i,0,n)
    scanf("%d",p+i);
  q[0][2]=-1;
  q[0][1]=-2;
  q[1][0]=q[2][0]=-1;
  for(int i=0;i<n;++i)
    {
      int j=0,k=-1;
      for(;j<3;++j)
	if(q[j][0]>=0 && abs(q[j][1]-p[i])!=1 && (k<0 || q[k][0]<q[j][0]))
	  k=j;
      pre[i]=q[k][2];
      j=0;
      for(;j<3;++j)
	if(q[j][1]==p[i])
	  break;
      int len=q[k][0];
      if(j<3)
	{
	  q[j][0]=len+1;
	  q[j][1]=p[i];
	  q[j][2]=i;
	}
      else
	{
	  k=0;
	  for(j=1;j<3;++j)
	    if(q[j][0]<q[k][0])
	      k=j;
	  q[k][0]=len+1;
	  q[k][1]=p[i];
	  q[k][2]=i;
	}
    }
  int i,j=0;
  for(i=1;i<3;++i)
    if(q[i][0]>q[j][0])
      j=i;
  printf("%d\n",(n-q[j][0]));
  dfs(q[j][2]);
  return 0;
}

