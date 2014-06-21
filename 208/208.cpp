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
const int N = 20, M = 20;
const ll base = 1e9;
typedef vector<int> bigNum;
void pt( bigNum & a )
{
  int i = a.size();
  if( i == 0 )
    printf("0");
  else
    {
      --i;
      printf("%d", a[i] );
      for( --i; i >= 0; --i )
	printf("%09d", a[i] );
    }
}
void mul( bigNum & a, bigNum & b )
{
  bigNum t1 = a, t2 = b;
  a.resize(0);
  for( int i = 0; i < t1.size(); ++i )
    for( int j = 0; j < t2.size(); ++j )
      {
	if( a.size() <= i + j )
	  a.resize( i + j + 1 );
	ll t = a[ i + j ];
	t += (ll) t1[i] * (ll) t2[j] ;
	a[ i + j ] = t % base;
	t /= base;
	if( t > 0 )
	  {
	    if( a.size() <= i + j + 1 )
	      a.resize( i + j + 2 );
	    a[ i + j + 1 ] += t;
	  }
      }
}
void addB( bigNum & a, bigNum & b )
{
  ll carry(0);
  int i = 0;
  for( ; i < b.size(); ++i )
    {
      if( i >= a.size() )
	a.resize( i + 1 );
      else
	carry += a[i];
      carry += b[i];
      a[i] = carry % base;
      carry /= base;
    }
  for( ; carry > 0; ++i)
    {
      if( i >= a.size() )
	a.resize( i + 1 );
      else
	carry += a[i];
      a[i] = carry % base;
      carry /= base;
    }
}
void re( bigNum & a )
{
  int i = a.size() - 1;
  for( ; i > 0 && a[i] == 0; --i )
    a.pop_back();
}
void subB( bigNum & a, int v )
{
  for( int i = 0 ; v > 0; ++i )
    {
      a[i] -= v;
      if( a[i] < 0 )
	{
	  a[i] += base;
	  v = 1;
	}
      else break;
    }
  re(a);
}
void divB( bigNum & a, int v )
{
  ll r(0);
  for( int i = a.size() - 1; i >= 0; --i )
    {
      r *= base;
      r += a[i];
      a[i] = r / v;
      r %= v;
    }
  assert( r == 0 );
  re(a);
}
void pow2( bigNum & a, int v )
{
  a.resize(0);
  a.push_back(1);
  bigNum tmp;
  tmp.push_back(2);
  for( ; v; v >>= 1,  mul( tmp, tmp) )
    if( v & 1 )
      mul( a, tmp );
}
bool vis[N][M];
int main()
{
  int n, m;
  cin >> n >> m;
  bigNum ans;
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < m; ++j)
      for( int k = 0; k < 2; ++k )
	for( int q = 0; q < ( m == n ? 4 : 1 ); ++q )
	  {
	    int t = 0;
	    memset( vis, 0 , sizeof(vis) );
	    for( int ii = 0; ii < n; ++ii )
	      for( int jj = 0; jj < m; ++jj )
		if( !vis[ii][jj] )
		  {
		    ++t;
		    for( int a = ii, b = jj; !vis[a][b]; )
		      {
			vis[a][b] = true;
			a = ( a + i ) % n;
			b = ( b + j ) % m;
			if( k )
			  a = n - 1 - a, b = m - 1 - b;
			for( int l = 0; l < q; ++l )
			  swap( a, b ), b = m - 1 - b;
		      }
		  }
	    bigNum tmp;
	    pow2( tmp, t);
	    addB( ans, tmp );
	  }
  divB( ans, n * m * 2 * ( m == n ? 4 : 1 ) );
  // subB( ans, 1 );
  pt( ans );
  return 0;
}
