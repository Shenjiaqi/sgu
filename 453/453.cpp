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
  freopen("in","r",stdin);
  ll l,v1,v2,t;
  cin>>l>>v1>>v2>>t;
  cout<<( (t*(v1+v2)+l)/(l<<1) );
  return 0;
}
