#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 2005
int p[N][N];
int q[N];
int gen(int off,int l)
{
  if(l==1)
    {
      p[off][off]=0;
      return 0;
    }
  gen(off,max(l-l/2,l/2));
  int s=gen(off+l/2,l-l/2);
  int t=l-l/2;
  if(t==s)
    {
      for(int i=off+l/2;i<off+l/2+l/2;++i)
	{
	  memset(q,0,sizeof(int)*(s+1));
	  for(int j=off+l/2;j<off+l;++j)
	    q[(i<=j?p[i][j]:p[j][i])]=1;
	  int k;
	  for(k=1;q[k];++k)
	    ;
	  p[i-l/2][i]=k;
	}
      for(int i=off;i<off+l/2;++i)
	for(int j=off+l/2+i-off+1,k=s+1;;)
	  {
	    if(j>=off+l)
	      j-=(l-l/2);
	    p[i][j]=k;
	    ++k;
	    ++j;
	    if(j>=off+l)
	      j-=(l-l/2);
	    if(j==i+l/2)
	      break;
	  }
    }
  else for(int i=off;i<off+l/2;++i)
	 for(int j=off+l/2+i-off,k=s+1;;)
	   {
	     if(j>=off+l)
	       j-=(l-l/2);
	     p[i][j]=k;
	     ++k;
	     ++j;
	     if(j>=off+l)
	       j-=(l-l/2);
	     if(j==l/2+i)
	       break;
	   }
  return (t==s?s+t-1:s+t);
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  printf("%d\n",gen(0,n));
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<n;++j)
	printf("%d ",(i<=j?p[i][j]:p[j][i]));
      printf("\n");
    }
  return 0;
}
