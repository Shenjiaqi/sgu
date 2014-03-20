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
  cout << t << endl;
  int n, m;
  n = 316, m = n * n;
  cout << n << ' ' << m << endl;
  for( int i = 0 ; i < n; ++i )
    for( int j = 0; j < n - i; ++j )
      if( j != n - i - 1 )
      {
	cout << i << ' ' << j << ' ' << i + 1 << ' ' << j << ' ' 
	     << i + 1 << ' ' << j + 1 << endl;
	cout << i << ' ' << j << ' ' << i + 1 << ' ' << j + 1 << ' '
	     << i << ' ' << j + 1 << endl;
      }
      else
	cout << i << ' ' << j << ' ' << i + 1 << ' ' << j << ' '
	     << i << ' ' << j + 1 << endl;
  return 0;
}
