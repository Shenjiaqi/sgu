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
ll p[51];
ll cc(int a,int b)
{
  if(a<b)
    return 0;
  ll r=1;
  for(int i=0;i<b;++i)
    r=(r*(ll)(a-i))/(ll)(i+1);
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n,l1,l2;
  ll posi;
  cin>>n>>l1>>l2>>posi;
  for(int i=l1;i<=n-l2;++i)
    {
      p[i]=cc(i,l1)*cc(n-i,l2);
      if(i)
	p[i]+=p[i-1];
    }
  posi*=p[n-l2];
  for(int i=1;;++i)
    for(int j=0;j+i-1<=n;++j)
      if((p[i+j-1]-(j?p[j-1]:0))*(ll)100>=posi)
	{
	  cout<<j<<' '<<(i+j-1);
	  return 0;
	}
  return 0;
}
