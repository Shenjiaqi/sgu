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
  for( ; t-- ; )
    {
      int n = 8;
      srand(16);
      cout << n << endl;
      for( int i = 0,r = 0; i < n ; ++i )
	{
	  int l = ( rand() % 10 ) + r + 1;
	  r = l + ( rand() % 10 ) + 1;
	  int h = ( rand() % 30 ) + 1;
	  cout << l << ' ' << r << ' ' << h << endl;
	}
    }
  return 0;
}
