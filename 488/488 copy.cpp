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
int a[N],b[N];
int tmp[N];
int gpos(int f,int t,int c[],int v)
{
  for(;f<=t;)
    {
      int m=(f+t)>>1;
      if(c[m]==v)
	return m;
      if(c[m]<v)
	f=m+1;
      else t=m-1;
    }
  return f;
}
void val(int c[],int n)
{
  for(int i=0,j=-1;i<n;++i)
    {
      int pos=gpos(0,j,tmp,p[i]);
      tmp[pos]=p[i];
      c[i]=pos;
      j=max(j,pos);
    }
}
int cal(int n)
{
  val(a,n);
  for(int i=0,j=n-1;i<j;++i,--j)
    swap(p[i],p[j]);
  val(b,n);
  int ans(0);
  for(int i=0;i<n;++i)
    ans=max(ans,min(a[i],b[n-1-i]));
  return ans;
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
    {
      int n;
      scanf("%d",&n);
      for(int j=0;j<n;++j)
	scanf("%d",p+j);
      printf("%d ",cal(n));
      for(int j=0;j<n;++j)
	p[j]=-p[j];
      printf("%d\n",cal(n));
    }
  return 0;
}
