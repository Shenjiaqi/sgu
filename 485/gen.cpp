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
  int t,n;
  t=1,n=25;
  cout<<t<<' '<<n<<endl;
  for(;t--;)
    {
      for(int i=0;i<3*n;++i)
	cout<<(rand()%1001)<<' ';
      cout<<endl;
    }
  return 0;
}
