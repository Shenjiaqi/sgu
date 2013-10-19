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
int main()
{
  freopen("in","w",stdout);
  int n,m;
  n=10,m=100;
  cout<<n<<' '<<m<<endl;
  for(int i=0;i<n;++i)
    for(int j=0;j<3;++j)
      cout<<((rand()%10000)+1)<<' ';
  cout<<endl;
  for(int i=0;i<m;++i)
    for(int j=0;j<3;++j)
      cout<<((rand()%10000)+1)<<' ';
  cout<<endl;
  return 0;
}
