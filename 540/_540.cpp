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
const int N = 20000 + 7;
const ld eps = 1e-10;
int x[N], r[N], g[N], d[N];
vector<pair<pair<int,int>, int> > lst;
set< pair<pair<int,int>, int > > chk;
int n, s, vMin, vMax;
int gcd( int a, int b )
{
  return b == 0 ? a : gcd( b, a % b );
}
void ins( int dis, int tim, int val )
{
  assert( dis > 0 && tim > 0 );
  int tmp = gcd( dis, tim );
  dis /= tmp, tim /= tmp;
  lst.push_back( make_pair( make_pair( dis, tim ), val ) );
  if( chk.find( make_pair( make_pair( dis, tim ), val ) ) != chk.end() )
    assert(0);
  assert( dis <= vMax * tim && dis >= vMin * tim );
  chk.insert( make_pair( make_pair( dis, tim ), val ) );
}
bool insert( int dis1, int tim1, int dis2, int tim2 )
{
  if( dis1 * tim2 < dis2 * tim1 )
    return true;
  if( dis1 < vMin * tim1 )
    return false;
  if( dis2 > vMax * tim2 )
    return true;
  if( dis1 < vMax * tim1 )
    ins( dis1, tim1, 1);
  else ins( vMax, 1, 1 );
  if( dis2 > vMin * tim2 )
    ins( dis2, tim2, -1 );
  else ins( vMin, 1, -1 );
  return true;
}
bool cmp( const pair< pair<int,int>, int> & a,
	  const pair< pair<int,int>, int> & b )
{
  return a.first.first * b.first.second > b.first.first * a.first.second;
}
int main()
{
  scanf("%d%d%d%d", &n, &s, &vMin, &vMax);
  for( int i = 0; i < n; ++i )
    {
      scanf("%d%d%d%d", x + i, r + i, g + i, d + i );
      chk.clear();
      if( d[i] )
	insert( vMax, 1, x[i], d[i] );
      for( int t = d[i] + r[i]; ; t += g[i] + r[i])
      	{
      	  if( !insert( x[i], t, x[i], t + g[i] ) )
      	    break;
      	}
    }
  sort( lst.begin(), lst.end(), cmp );
  int ans(0), pre(0);
  pair<int,int> ansV;
  ansV.first = vMax, ansV.second = 1;
  for( int i = 0; i < lst.size(); )
    {
      pair<int,int> v = lst[i].first;
      if( v.first < vMin * v.second )
	break;
      int sub(0);
      for( ; i < lst.size() && lst[i].first == v; ++i )
	if( lst[i].second == 1 )
	  ++pre;
	else if( lst[i].second == -1 )
	  ++sub;
	else assert(0);
      if( ans < pre )
	{
	  ans = pre;
	  ansV = v;
	}
      pre -= sub;
    }
  printf("%.10lf\n%d\n", (double)ansV.first / (double)ansV.second, n - ans );
  int cnt(0);
  for( int i = 0; i < n; ++i )
    {
      if( ansV.first * d[i] < x[i] * ansV.second )
	{
	  int tmp = ( x[i] * ansV.second - d[i] * ansV.first ) % ( ( r[i] + g[i] ) * ansV.first );
	  if( tmp != 0 && tmp < r[i] * ansV.first )
	    {
	      if( cnt )
		printf(" ");
	      printf("%d", i + 1 );
	      ++cnt;
	    }
	}
    }
  assert( cnt == n - ans );
  return 0;
}
