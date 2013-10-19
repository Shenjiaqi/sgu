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
ll p[200000+7];
int main()
{
  freopen("in","r",stdin);
  ll n,h;
  cin>>n>>h;
  ll *a=p+100000;
  a[0]=(h+1)*(h+1);
  ll j=h+1,pre=a[0];
  for(int i=1;i<=100000;++i,++j)
    pre=a[0-i]=pre+j,pre=a[0+i]=pre+j;
  int cnt=0;
  for(int i=0-100000;i<=100000;++i)
    if(a[i]<=n && a[i]>0)
      printf("%d ",(int)a[i]);
  return 0;
}
