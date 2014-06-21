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
typedef vector<int> bigNum;
const ll base = 1e9;
const int N = 25;
bigNum dp[N][N][N];
bigNum zero;
void pt( bigNum a )
{
  int i = a.size();
  if( i == 0 )
    printf("0");
  else
    {
      --i;
      printf("%d", a[i]);
      for( --i; i >= 0; --i )
	printf("%09d", a[i]);
    }
}
bigNum add( bigNum a, bigNum b )
{
  bigNum r;
  for( int i = 0; i < a.size() || i < b.size(); ++i )
    {
      if( r.size() <= i)
	r.resize( i + 1 );
      ll v = r[i];
      if( i < a.size() )
	v += a[i];
      if( i < b.size() )
	v += b[i];
      r[i] = v % base;
      v /= base;
      if( v > 0 )
	{
	  if( r.size() <= i + 1 )
	    r.resize( i + 2 );
	  r[ i + 1 ] += v;
	}
    }
  return r;
}
bigNum mul( bigNum a, bigNum b )
{
  bigNum r;
  for( int i = 0; i < a.size(); ++i )
    for( int j = 0; j < b.size(); ++j )
      {
	if( r.size() <= i + j )
	  r.resize( i + j + 1 );
	ll v = r[ i + j ];
	v += (ll)a[i] * (ll)b[j];
	r[ i + j ] = v % base;
	v /= base;
	if( v > 0 )
	  {
	    if( r.size() <= i + j + 1 )
	      r.resize( i + j + 2 );
	    r[ i + j + 1 ] += v;
	  }
      }
  return r;
}
bigNum que(int a, int b, int c)
{
  if( a > b )
    swap( a, b );
  if( a < c || b < c )
    return zero;
  if( dp[a][b][c].empty() )
    {
      if( c == 0 )
	dp[a][b][c].push_back(1);
      else
	{
	  bigNum tmp;
	  tmp.push_back(b);
	  dp[a][b][c] = add( que( a - 1, b,  c ),
				mul( tmp, que( a - 1, b - 1, c - 1 ) ) );
	}
    }
  return dp[a][b][c];
}
int main()
{
  int n, m, w, h, k;
  cin >> n >> m >> w >> h >> k;
  bigNum ans;
  // if( h >= n && w >= n )
  //   {
  //     for( int i = 0; i <= min( n, k ); ++i )
  // 	{
  // 	  int j = k - i;
  // 	  if( j <= m )
  // 	    ans = add( ans, mul( que( n, n, i ), que( m, m, j ) ) );
  // 	}
  //   }
  // else if ( h < n && w < n )
  //   {
  //     // if( ( m + h <= n && m + w <= n ) ||
  //     // 	  ( h == 0 && w == 0 && m >= n ) )
  //     // 	{
  //     // 	  ans = que( max( n, m ), max( n, m ), k );
  //     // 	}
  //     // else
  // 	{
  int a = max( 0, min( n - w, m ) );
  int b = max( 0, min( n - h, m ) );
  int x1 = m - a;
  int y1 = m - b;
  int x2 = n - a, y2 = n - b;
  // cout << a << ' ' << b << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  for( int i = 0; i <= min( k, min( a, b) ); ++i )
    {
      bigNum tmp = que( a, b, i );
      for( int c = 0; c <= min( k - i, min( a - i, y1) ); ++c )
	for( int d = 0; d <= min( k - i - c, min( a - i - c, y2 ) ); ++d )
	  {
	    bigNum tmp1 = mul( que( y1, a - i, c ),
			       que( y2, a - i - c, d ) );
	    tmp1 = mul( tmp1, tmp );
	    for( int e = 0; e <= min( k - i - c - d, min( x2, b - i) ); ++e )
	      for( int f = 0; f <= min( k - i - c - d - e, min( x1, b - i - e ) ); ++f )
		{
		  bigNum tmp2 = mul( que( x2, b - i, e ),
				     que( x1, b - i - e, f ) );
		  tmp2 = mul( tmp2, tmp1 );
		  for( int g = 0; g <= min( k - i - c - d - e - f, min( x2 - e, y2 - d ) ); ++g )
		    {
		      int h = k - i - c - d - e - f - g;
		      if( h <= min( x1 - f, y1 - c ) )
			{
			  bigNum tmp3 = mul( que( x2 - e, y2 - d, g ),
					     que( x1 - f, y1 - c, h ) );
			  tmp3 = mul( tmp3, tmp2 );
			  ans = add( ans, tmp3 );
			}
		    }
		}
	  }
    }
	// }
  //   }
  // else
  //   {
  //     assert( h < n || w < n );
  //     if( h < n )
  // 	swap( h, w );
  //     int c = min( n - w, m );
  //     for( int i =  0; i <= min( m, min( k, c ) ); ++i )
  // 	for( int j = 0; j <= min( n, min( k, c ) - i ); ++j )
  // 	  {
  // 	    bigNum tmp = mul( que( m, c, i ), que( n, c - i, j ) );
  // 	    bigNum sum;
  // 	    for( int a = 0; a <= min( k - i - j, n - c ); ++a )
  // 	      {
  // 		int b = k - i - j - a;
  // 		if( b < m - c )
  // 		  {
  // 		    bigNum tmp2 = mul( que( n - c, n - j, a),
  // 				       que( m - c, m - i, b ) );
  // 		    sum = add( sum , tmp2 );
  // 		  }
  // 	      }
  // 	    ans = add( ans, mul( tmp, sum ) );
  // 	  }
  //   }
  assert( n || m );
  pt( ans );
  // cout << endl; pt( que( 3, 3, 2 ) );
  return 0;
}
