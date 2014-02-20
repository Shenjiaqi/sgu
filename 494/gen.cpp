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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int main()
{
  int t = 1;
  printf("%d\n", t);
  int n = 10000;
  int r = 900;
  int c = 2;
  int w = 1000;
  printf("%d %d %d %d\n", n, w, r, c);
  for( int i = 0 ; i < n ; ++i )
    printf("%d ", ( rand() % 150 ) + 1 );
  return 0;
}
