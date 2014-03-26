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
const int M = 1e6 + 7;
ll q;
int c;
ll dp[M];
int addMod( int a, int b)
{
  return ( a + b ) % M;
}
int subMod( int a, int b)
{
  return addMod( (a - b) % M, M );
}
int main()
{
  cin >> q >> c;
  for( int i = c; ; ++i )
    {
      if( dp[ addMod( i, 0 ) ] >= q )
	{
	  cout << i;
	  break;
	}
      dp[ addMod( i, 1 ) ] = 
	dp[ subMod( i, c) ] + 1 + dp[ addMod( i, 0 ) ];
    }
  return 0;
}
