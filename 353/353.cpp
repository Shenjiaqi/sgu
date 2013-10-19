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
int cal(int &mo,int len,int pri)
{
  int tmp=min(mo/pri,len);
  mo-=pri*tmp;
  return tmp;
}
int main()
{
  freopen("in","r",stdin);
  int n,k1,k2,p1,p2,p3;
  scanf("%d%d%d%d%d%d",&n,&k1,&k2,&p1,&p2,&p3);
  int ans=0;
  if(n>=p1)
    {
      ans=k1;
      n-=p1;
      if(n>0)
	{
	  int t=min((n+p2-1)/p2,k2);
	  ans+=t;
	  n-=t*p2;
	  if(n>0)
	    ans+=(n+p3-1)/p3;
	}
    }
  printf("%d",ans);
  return 0;
}
