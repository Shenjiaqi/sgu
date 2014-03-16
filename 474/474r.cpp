#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
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
typedef pair<int,int> poi;
typedef struct
{
  poi r;
  poi a,b;
}tri;
const int N = 25007;
const int M = 1e5 + 7;
int n, m;
tri p[M];
//  |\     /| |--/ \--|
//  | \   / | | /   \ | 
//  |__\ /__| |/     \|  
//  0      1    2     3

//  |--/    /|   /\    ----   
//  | /   <  |  /  \   \  /
//  |/      \| /____\   \/   
//   7     4     6      5
void consTri(tri &t, int x1, int y1, int x2, int y2, int x3, int y3)
{
  for( int i = 0; i < 3; ++i )
    {
      if( ( x1 == x2 && y1 == y3 ) ||
	  ( x1 == y3 && y1 == x2 ) )
	{
	  t.first.first = x1, t.first.second = y1;
	  t.second.first = ( x1 == min( x2, x3 ) ? 0 : 1 ) |
	    ( y1 == min( y2, y3 ) ? 0 : 2 );
	  t.second.second = abs( x1 - max( x2, x3 ) );
	  return;
	}
      else if( x1 != x2 && x1 != x3 && y1 != y2 && y1 != y3 )
	{
	  t.first.first = x1, t.first.second = y1;
	  if( x1 < min( x2, x3 ) )
	    {
	      t.second.first = 4;
	      t.second.second = abs( y2 - y3 );
	    }
	  else if( x1 > max( x2, x3 ) )
	    {
	      t.second.first = 7;
	      t.second.second = abs( y2 - y3 );
	    }
	  else if( y1 < y2 )
	    {
	      t.second.first = 5;
	      t.second.second = abs( x2 - x3 );
	    }
	  else
	    {
	      t.second.first = 6;
	      t.second.second = abs( x2 - x3 );
	    }
	  return ;
	}
      swap( x1, x2 ), swap( y1, y2 );
      swap( x1, x3 ), swap( y1, y3 );
    }
}
const int nxt[][2] = { { 6, 7 }, { 4, 6 }, { 5, 7 }, { 4, 5 },
		       { 1, 3 }, { 2, 3 }, { 0, 1 }, { 0, 2 } };
const int dir[][2] = { { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 },
		       { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };
void split( const tri & big, tri &a, tri &b)
{
  int type = big.second.first;
  a.second.first = nxt[type][0];
  b.second.first = nxt[type][1];
  int len = big.second.second;
  int x = big.first.first, y = big.first.seocnd;
  b.first.first = a.first.first = x + dir[type][0][0] * ( len >> 1 );
  b.first.second = a.first.second = y + dir[type][0][1] * ( len >> 1 );
  if( type > 3 )
    len >>= 1;
  a.seocond.second = b.second.second = len;
}
inline bool minTri( const tri & t)
{
  return t.second.second == 1;
}
ll cross(poi a, poi b)
{
  return (ll)a.first * (ll)b.second - (ll)a.second * (ll) b.first;
}
inline poi sub( const poi & a, const poi & b)
{
  return poi( a.first - b.first, a.second - b.second );
}
// relation between point and triangle
// 0 -> point in triangle
// 1 -> point on triangle
// 2 -> point out of triangle
int poiInTri( const poi &a, const tri & b)
{
  poi p1 = b.first;
  poi p2 = p1, p3 = p1;
  bool zero = false;
  for( int i = 0 ; i < 3; ++i )
    {
      poi tmp = sub( p2, p1 );
      ll val = cross( tmp , sub( a, p1 ) ) * cross( tmp , sub( p3, p1 ) );
      if( val < 0 )
	return 2;
      if( val == 0 )
	zero = true;
      swap( p1, p2 );
      swap( p2, p3 );
    }
  return zero ? 1 : 0;
}
void decompose( const tri &a, int &x1, int &y1, int &x2, 
		int &y2, int &x3, int &y3)
{
  x2 = x3 = x1 = a.first.first;
  y2 = y3 = y1 = a.first.second;
  int type = a.second.first;
  int len = a.second.second;
  if( type == 0 )
    x2 += len, y3 += len;
  else if( type == 1 )
    x2 -= len, y3 += len;
  else if( type == 2 )
    x2 += len, y3 -= len;
  else if( type == 3 )
    x2 -= len, y3 += len;
  else
    {
      assert( len > 1 );
      len >>= 1;
      if( type == 4 )
	x2 += len, x3 += len, y2 -= len, y3 += len;
      else if( type == 5 )
	y3 += len, y2 += len, x2 += len, x3 -= len;
      else if( type == 6 )
	y3 -= len, y2 -= len, x2 += len, x3 -= len;
      else
	x2 -= len, x3 -=len, y2 += len, y3 -= len;
    }
}
bool apart( const tri & a, const tri & b)
{
  int x1, y1, x2, y2, x3, y3;
  int xx1, yy1, xx2, yy2, xx3, yy3;
  decompose( a, x1, y1, x2, y2, x3, y3);
  decompose( b, xx1, yy1, xx2, yy2, xx3, yy3 );
  for( int i = 0; i < 3; ++i )
    {
      
    }
}
// const int pt[][4] = { { 1, 6, 2, 7 }, { 3, 4, 0, 6 }, 
// 		      { 3, 5, 0, 7 }, { 1, 4, 2, 5 },
// 		      { 1, 6, 3, 5 }, { 2, 7, 3, 4 },
// 		      { 0, 7, 1, 4 }, { 0, 6, 2, 5 } };
inline bool canMerge( const tri & to, const tri & p1, const tri & p2)
{
  // int tt = to.second.first;
  // int t1 = p1.second.first;
  // int t2 = p2.second.first;
  return apart( p1, p2 );
}
bool dfs( const tri &big, stack<int> &stk )
{
  if( minTri(big) )
    {
      if( stk.size() == 1 )
	{
	  return triIntri( big, p[stk.top()] );
	}
      else if( stk.size() == 2 )
	{
	  int t1 = stk.top();
	  stk.pop();
	  int t2 = stk.top();
	  return ( canMerge( big, p[t1], p[t2] ) == 3 );
	}
      return false;
    }
  if( stk.empty() )
    return false;
  if( stk.size() == 1 )
    {
      int t = stk.top();
      return triIntri( big, p[t] );
    }
  if( stk.size() > area( big ) * 2 )
    return false;
  tri part1, part2;
  splitTri( big, part1, part2 );
  stack<int> stk1, stk2;
  for(; stk.empty(); stk.pop() )
    {
      int t = stk.top();
      if( !apart( p[t], part1 ) )
	{
	  stk1.push(t);
	  if( !apart( p[t], part2 ) )
	    stk2.push(t);
	}
      else stk2.push(t);
    }
  return dfs( part1, stk1 ) && dfs( part2, stk2 );
}
int main()
{
  scanf("%d", &t);
  for(; t--;)
    {
      scanf("%d%d", &n, &m);
      poi xy[3];
      tri big;
      xy[0].first = xy[0].second = xy[1].first = xy[2].second;
      xy[1].second = xy[2].first = n;
      consTri(big, xy);
      ll areaSum(0);
      bool allInBig = true;
      for( int i = 0; i < n; ++i )
	{
	  for( int j = 0 ; j < 3; ++j )
	    {
	      scanf("%d%d", &xy[j].first, &xy[j].second);
	      if( 2 == poiInTri( xy[j], big ) )
		allInBig = false;
	    }
	  consTri( p[i], xy);
	  areaSum += area( p[i] );
	}
      if( areaSum > area( big ) || allInBig )
	{
	  printf("NO");
	}
      else
	{
	  stack<int> stk;
	  for( int i = 0; i < n; ++i )
	    stk.push(i);
	  if( stk.size() == n )
	    {
	      if( dfs( big, stk ) )
		printf("YES");
	      else printf("NO");
	    }
	}
      printf("\n");
    }
  return 0;
}
