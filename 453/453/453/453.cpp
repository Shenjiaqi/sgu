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
ll gcd( ll a, ll b )
{
  return b == 0 ? a : gcd( b, a % b );
}
int main()
{
  ios::sync_with_stdio(false);
  ll l, v1, v2, t;
  cin >> l >> v1 >> v2 >> t;
  if( v1 < v2 )
    swap( v1, v2 );
  ll num = v1 * t / l;
  ll ans = num;
  ll gc = gcd( v1, v2 );
  if( ( ( v1 / gc ) & 1 ) == 0 ||
      ( ( v2 / gc ) & 1 ) == 0 )
    {
      ans -= ( ( t * gc ) / l + 1 ) / 2;
      if( ( t * v1 ) % l == 0 && ( t * v2 ) % l == 0 &&
	  ( ( ( t * v1 ) / l ) & 1 ) != ( ( ( t * v2 ) / l ) & 1 ) )
	++ans;
    }
  ll tv = l * num; // / v1;
  if( ( tv * v2 ) % ( v1 * l ) != 0 || 
      ( num & 1 ) == ( ( tv * v2 / ( v1 * l ) ) & 1 ) )
    {
      ll pos2 = ( ( t * v2 ) % ( 2LL * l ) );
      if( pos2 >= l )
	pos2 = 2LL * l - pos2;
      ll pos1 = ( ( t * v1 ) % ( 2LL * l ) );
      if( pos1 >= l )
	pos1 = 2LL * l - pos1;
      pos1 = l - pos1;
      // cout << num << ' ' << pos1 << ' ' << pos2 << endl;
      if( ( ( num & 1 ) && pos2 <= pos1 ) ||
      	  ( ( num & 1 ) == 0 && pos2 >= pos1 ) )
      	++ans;
    }
  cout << ans;
  return 0;
}
