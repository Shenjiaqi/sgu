#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 1000000
int p[N+1];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0,j;i<n;++i)
    {
      scanf("%d",&j);
      p[j]=1;
    }
  for(int i=N;i>0;--i)
    {
      int num(0);
      for(int j=i;j<=N && num<2;j+=i)
	if(p[j])
	  ++num;
      if(num>=2)
	{
	  cout<<i;
	  break;
	}
    }
  return 0;
}
