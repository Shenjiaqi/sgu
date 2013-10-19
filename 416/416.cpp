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
#define N 100
int p[N][2];
int main()
{
  //  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  p[0][0]=n,p[0][1]=1;
  for(int i=1,j=n/2-1,k=1,l=n-1,m=2;i<=j;++i,--j)
    {
      p[i][0]=m,p[i][1]=l;
      ++m,--l;
      if(i!=j)
	p[j][0]=m,p[j][1]=l;
      ++m,--l;
      if(k==0)
      	{
      	  swap(p[i][0],p[i][1]);
	  if(i!=j)
	    swap(p[j][0],p[j][1]);
      	}
      k^=1;
    }
  for(int i=0;i<n/2;++i)
    {
      printf("%d %d ",p[i][0],p[i][1]);
    }
  return 0;
}
