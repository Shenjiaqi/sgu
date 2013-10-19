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
#define N 1500
#define M 300000
int main()
{
  freopen("in","r",stdin);
  int n=N;
  int m=M;
  int l=N/3;
  int c=1000000;
  int lev[N+1];
  lev[1]=1,lev[2]=l;
  for(int i=3;i<=n;++i)
    {
      int t;
      for(;;)
	{
	  t=rand()%l;
	  ++t;
	  if(t!=1 && t!=l)
	    break;
	}
      lev[i]=t;
    }
  bool con[N+1][N+1]={0};
  for(int i=0;i<m;)
    {
      int a,b,c;
      a=rand()%n;
      b=rand()%n;
      c=rand()%c;
      ++a,++b,++c;
      if(!con[a][b] && lev[a]==lev[b]-1)
	{
	  printf("%d %d %d\n",a,b,c);
	  ++i;
	  con[a][b]=true;
	}
    }
  return 0;
}
