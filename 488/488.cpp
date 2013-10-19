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
#define N 1000000
int p[N];
int a[N][2],b[N][2];
void val(int c[][2],int n)
{
  c[0][0]=c[0][1]=0;
  for(int i=1;i<n;++i)
    {
      c[i][0]=p[i]>p[i-1]?c[i-1][0]+1:0;
      c[i][1]=p[i]<p[i-1]?c[i-1][1]+1:0;
    }
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d",&t);
  for(;t--;)
    {
      int n;
      scanf("%d",&n);
      for(int i=0;i<n;++i)
	scanf("%d",p+i);
      val(a,n);
      for(int i=0,j=n-1;i<j;++i,--j)
	swap(p[i],p[j]);
      val(b,n);
      int ans[2]={0};
      for(int i=0;i<n;++i)
	ans[0]=max(ans[0],min(a[i][0],b[n-1-i][0])),
	  ans[1]=max(ans[1],min(a[i][1],b[n-1-i][1]));
      printf("%d %d\n",ans[0],ans[1]);
    }
  return 0;
}
