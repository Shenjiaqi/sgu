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
const int N = 10;
int n, k;
ll dp[ N + 1 ][ N + 1 ];
ll c[ N + 1 ][ N + 1 ];
int main()
{
  cin >> n >> k;
  if( k > N * 2 )
    printf("0");
  else
    {
      for( int i = 0; i <= N; ++i )
	{
	  c[i][0] = 1;
	  for( int j = 1; j <= i; ++j )
	    c[i][j] = c[i][ j - 1 ] * ( i - j + 1 ) / j;
	}
      for( int j = 0; j <= n; ++j )
	for( int l = 0; l <= j; ++l )
	  {
	    dp[j][l] = j > 2 ? dp[ j - 2 ][l] : ( l == 0 ? 1 : 0 );
	    if( l > 0 )
	      dp[j][l] += ( j > 2 ? 
			    dp[ j - 2 ][ l - 1 ] : l == 1 ? 1 : 0 ) * 
		c[ j - ( l - 1 ) ][1] * ( j == n ? 1LL : 2LL );
	    if( l > 1 )
	      dp[j][l] += ( j > 2 ? 
			    dp[ j - 2 ][ l - 2 ] : l == 2 ? 1 : 0 ) * 
		c[ j - ( l - 2 ) ][2] * ( j == n ? 0LL : 2LL );
	  }
      ll ans(0);
      int a, b;
      if( n & 1 )
	a = n - 1, b = n;
      else
	a = n, b = n - 1;
      for( int i = 0; i <= min( k, a); ++i )
	if( k - i <= b )
	  ans += dp[a][i] * dp[b][ k - i ];
      cout << ans;
    }
  return 0;
}
