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
int p[4];
int q[255];
int tr[4][4];
int dp[200][200];
char tmp[207];
int main()
{
  freopen("in","r",stdin);
  for(int i=0;i<4;++i)
    scanf("%d",p+i);
  q['b']=0,q['r']=1,q['y']=2,q['w']=3;
  for(int i=0;i<4;++i)
    for(int j=0;j<p[i];++j)
      {
	char a,b;
	scanf("\n%c%c",&a,&b);
	tr[q[a]][q[b]]|=1<<i;
      }
  scanf("\n%s",tmp);
  int l=strlen(tmp);
  for(int i=0;i<l;++i)
    dp[i][i]=1<<q[tmp[i]];
  for(int i=1;i<=l;++i)
    for(int j=0;j+i-1<l;++j)
      for(int k=j;k+1<=j+i-1;++k)
	if(dp[j][k] && dp[k+1][j+i-1])
	  for(int a=0;a<4;++a)
	    if(dp[j][k]&(1<<a))
	      for(int b=0;b<4;++b)
		if(dp[k+1][j+i-1]&(1<<b))
		  dp[j][j+i-1]|=tr[a][b];
  if(dp[0][l-1]==0)
    printf("Nobody");
  else
    {
      if(dp[0][l-1]&1)
	printf("b");
      if(dp[0][l-1]&2)
	printf("r");
      if(dp[0][l-1]&4)
	printf("y");
      if(dp[0][l-1]&8)
	printf("w");
    }
  return 0;
}
