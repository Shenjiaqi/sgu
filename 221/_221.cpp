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
const int N = 51;
const ll base = 1e9;
typedef vector<int> bigNum;
int n, k;
bigNum dp[ N + 1 ][ N + 1 ];
bigNum c[ N + 1 ][ N + 1 ];
void pt( bigNum & v)
{
  if( v.empty() )
    printf("0");
  else
    {
      int i = v.size() - 1;
      printf("%d", v[i] );
      for( --i; i >= 0; --i )
	printf("%09d", v[i]);
    }
}
void mul(bigNum &t, bigNum &a, bigNum &b )
{
  t.resize(0);
  for( int i = 0; i < a.size(); ++i )
    for( int j = 0; j < b.size(); ++j )
      {
	if( t.size() <= i + j )
	  t.resize( i + j + 1 );
	ll carry = (ll)a[i] * (ll)b[j] + (ll)t[ i + j ];
	t[i + j] = carry % base;
	carry /= base;
	if( carry )
	  {
	    if( t.size() <= i + j + 1 )
	      t.resize( i + j + 2 );
	    t[i + j + 1 ] += carry;
	  }
      }
  for( ; t.size() > 1 && t[ t.size() - 1 ] == 0; )
    t.pop_back();
}
void mul( bigNum & t, bigNum &a, int b )
{
  vector<int> tmp;
  tmp.push_back(b);
  mul(t, a, tmp);
}
void divide( bigNum &a, int b )
{
  ll r(0);
  for( int i = a.size() - 1; i >= 0; --i )
    {
      r = r * base + a[i];
      a[i] = r / b;
      r %= b;
    }
  assert( r == 0 );
  for( ; a.size() > 1 && a[ a.size() - 1 ] == 0; )
    a.pop_back();
}
void addV( bigNum &a, bigNum &b )
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
  for( ; carry; ++i)
    {
      if( i >= a.size() )
	a.resize( i + 1 );
      carry += a[i];
      a[i] = carry % base;
      carry /= base;
    }
}
int main()
{
  cin >> n >> k;
  if( k > n * 2 )
    printf("0");
  else
    {
      vector<int> one;
      one.push_back(1);
      for( int i = 0; i <= N; ++i )
	{
	  c[i][0] = one;
	  for( int j = 1; j <= i; ++j )
	    {
	      mul( c[i][j], c[i][ j - 1 ], i - j + 1 );
	      divide( c[i][j], j);
	    }
	}
      for( int j = 0; j <= n; ++j )
	for( int l = 0; l <= j; ++l )
	  {
	    if( j > 2 )
	      dp[j][l] = dp[ j - 2 ][l];
	    else if( l == 0 )
	      dp[j][l] = one;
	    if( l > 0 )
	      {
		vector<int> tmp1, tmp2;
		if( j > 2 )
		  tmp1  = dp[ j - 2 ][ l - 1];
		else if( l == 1 )
		  tmp1 = one;
		mul( tmp2, tmp1, c[ j - ( l - 1 ) ][1] );
		mul( tmp1, tmp2, j == n ? 1 : 2 );
		addV( dp[j][l], tmp1 );
	      }
	    if( l > 1 )
	      {
		vector<int> tmp1, tmp2;
		if( j > 2 )
		  tmp1 = dp[ j - 2 ][ l - 2 ];
		else if( l == 2 )
		  tmp1 = one;
		mul( tmp2, tmp1, c[ j - ( l - 2 ) ][2]);
		mul( tmp1, tmp2, j == n ? 0 : 2 );
		addV( dp[j][l], tmp1 );
	      }
	  }
      bigNum ans;
      int a, b;
      if( n & 1 )
	a = n - 1, b = n;
      else
	a = n, b = n - 1;
      for( int i = 0; i <= min( k, a); ++i )
	if( k - i <= b )
	  {
	    vector<int> tmp;
	    mul( tmp, dp[a][i], dp[b][ k - i ]);
	    addV( ans, tmp);
	  }
      pt(ans);
    }
  return 0;
}
