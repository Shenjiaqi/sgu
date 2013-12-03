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
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 61
ll p[N][N];
int main()
{
  for(int i=1;i<=50;++i)
    {
      p[i][i]=1;
      for(int j=i-1;j>0;--j)
	p[i][j]=p[i][j+1]+p[i-j][j];
    }
  ll n;
  cin>>n;
  ll ans(1);
  for(ll i=2;i*i<=n;++i)
    if((n%i)==0)
      {
	ll num=0;
	for(;(n%i)==0;++num)
	  n/=i;
	ans*=p[num][1];
      }
  cout<<ans;
  return 0;
}
