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
typedef sturct
{
  int x, y;
}poi;
typedef struct
{
  poi r;
  poi a,b;
  int size;
}tri;
const int N = 25007;
const int M = 1e5 + 7;
int n, m;
tri p[M];
void split( const tri & big, tri &a, tri &b)
{
  assert( abs( big.a.x - big.b.x ) > 1 || abs( big.a.y - bif.a.x ) > 1 );
  a.r.x = b.r.x = ( big.a.x + big.b.x ) >> 1;
  a.r.y = b.r.y = ( big.a.y + big.b.y ) >> 1;
  b.a = a.a = big.r;
  a.b = big.a;
  b.b = big.b;
  a.size = b.size = big.size >> 1;
}
inline bool minTri( const tri & t)
{
  return t.size == 1;
  // if( t.r.x == t.a.x )
  //   return abs( t.r.y - t.a.y ) == 1;
  // else if ( t.r.x == t.b.x )
  //   return abs( t.r.y - t.b.y ) == 1;
  // if( t.a.x == t.b.x )
  //   return abs( t.a.y - t.b.y ) == 1;
  // return abs( t.a.x - t.b.x ) == 1;
}
inline ll cross(const poi &a, const poi &b)
{
  return (ll)a.x * (ll)b.y - (ll)a.y * (ll) b.x;
}
inline void sub( poi & r, const poi & a, const poi & b)
{
  r.x = a.x - b.x;
  r.y = a.y - b.y;
}
inline int minX( const tri & a)
{
  return min( a.r.x, min( a.a.x, a.b.x ) );
}
inline int maxX( const tri & a )
{
  return max( a.r.x, max( a.a.x, a.b.x ) );
}
inline int minY( const tri & a )
{
  return min( a.r.y, min( a.a.y, a.b.y ) );
}
inline int maxY( const tri & a)
{
  return max( a.r.y, max( a.a.y, a.b.y ) );
}
// relation between point and triangle
// 0 -> point in triangle
// 1 -> point on triangle
// 2 -> point out of triangle
int poiTri( const poi &a, const tri & b)
{
  // fast test
  if( a.x < minX(b) || a.x > maxX(b) ||
      a.y < minY(b) || a.y > maxY(b) )
    return false;
  poi p1 = b.r, p2 = b.a, p3 = b.b;
  bool on = false;
  for( int i = 0 ; i < 3; ++i )
    {
      poi tmp, t1, t2;;
      sub(tmp, p2, p1 );
      sub(t1, a, p1);
      sub(t2, p3, p1);
      ll val = cross( tmp , t1 ) * cross( tmp , t2 );
      if( val < 0 )
	return 2;
      if( val == 0 )
	{
	  if( a.x <= max( p1.x, p2.x ) && a.x >= min( p1.x, p2.x ) &&
	      a.y <= max( p1.y, p2.y ) && a.y >= min( p1.y, p2.y ) )
	    on = true
	      break;;
	}
      poi tmp = p1;
      p1 = p2, p2 = p3, p3 = tmp;
    }
  return on ? 1 : 0;
}
bool test( const poi & p1[], const poi & p2[] )
{
  for( int i = 0; i < 3; ++i )
    {
      poi line;
      sub( line, p1[i], p1[ ( i + 1 ) % 3 ] );
      poi t1;
      sub( t1, p1[ ( i + 2 ) % 3 ], p1[ ( i + 1) % 3 ] );
      bool tag = cross( t1, line) > 0 ? true : false;
      int j = 0;
      for( ; j < 3; ++j )
	{
	  sub( t1, p2[j], p1[ ( i + 1 ) % 3 ] );
	  ll tmp = cross( t1, line );
	  if( tmp != 0 )
	    {
	      bool ttag = tmp > 0 ? true : false;
	      if( tag == ttag )
		break;
	    }
	}
      if( j >= 3 )
	return true;
    }
  return false;
}
bool apart( const tri & a, const tri & b)
{
  // poi p1[3], p2[3];
  // p1[0] = a.r, p1[1] = a.a, p1[2] = a.b;
  // p2[0] = b.r, pt[2] = b.a, p2[2] = b.b;
  // // fast test
  // if( maxX(a) < minX(b) || minX(a) > maxX(b) ||
  //     maxY(a) < minY(b) || minY(a) > maxY(b) )
  //   return true;
  // //
  // return test( p1, p2 ) || test( p2, p1 );
}
inline bool canMerge( const tri & to, const tri & p1, const tri & p2)
{
  return apart( p1, p2 );
}
// a in b ?
inline bool triInTri( const tri &a, const tri &b )
{
  return a.size <= b.size && 
    poiTri( a.r, b ) < 2 && poiTri( a.a, b) && poiTri( a.b, b );
}
inline ll area( const tri & a )
{
  poi line1, line2;
  sub( line1, a.x, a.r );
  sub( line2, a.y, a.r );
  return llabs( cross( line1, line2 ) );
}
void consTri(tri &t, poi a, poi b, poi c)
{
  for( int i = 0; i < 3; ++i )
    {
      if( ( ( a.x == b.x && a.y == c.y ) ||
	    ( a.x == c.x && a.y == c.x ) ) ||
	  ( a.x != b.x && a.x != c.x && a.y != b.y && a.y != c.y ) )
	{
	  t.r = a;
	  t.a = b, t.b = c;
	  t.size = area(t);
	  return;
	}
      poi tmp = a;
      a = b, b = c, c = a;
    }
}
bool dfs( const tri &big, stack<int> &stk )
{
  if( minTri(big) )
    {
      if( stk.size() == 1 )
	return triInTri( big, p[stk.top()] );
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
      return triInTri( big, p[stk.top()] );
    }
  if( stk.size() > area( big ) * 2LL )
    return false;
  tri part1, part2;
  splitTri( big, part1, part2 );
  stack<int> stk1, stk2;
  ll area1(0), area2(0);
  int inCnt1(0), inCnt2(0);
  for(; stk.empty() && inCnt1 < 1 && inCnt < 1; stk.pop() )
    {
      int t = stk.top();
      if( !apart( p[t], part1 ) )
	{
	  stk1.push(t);
	  area1 += p[t].size;
	  if( p[t].size > triInTri( part1, p[t] ) )
	    ++inCnt1;
	  if( !apart( p[t], part2 ) )
	    {
	      stk2.push(t);
	      area2 += p[t].size;
	      if( triInTri( part2, p[t] ) )
		++inCnt2;
	    }
	}
      else
	{
	  stk2.push(t);
	  area2 += p[t].size;
	  if( part2.size && triInTri( part2, p[t] ) )
	    ++inCnt2;
	}
    }
  if( inCnt1 > 1 || inCnt2 > 1 || 
      ( inCnt1 == 1 && stk1.size() > 1 ) ||
      ( inCnt2 == 1 && skt2.size() > 1 ) )
    return false;
  if( area1 < area( part1 ) || area2 < area( part2 ) )
    return false;
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
      xy[0].x = xy[0].y = xy[1].x = xy[2].y = 0;
      xy[1].y = xy[2].x = n;
      consTri(big, xy);
      ll areaSum(0);
      bool allInBig = true;
      for( int i = 0; i < n; ++i )
	{
	  for( int j = 0 ; j < 3; ++j )
	    {
	      scanf("%d%d", &xy[j].x, &xy[j].y);
	      if( 2 == poiTri( xy[j], big ) )
		allInBig = false;
	    }
	  consTri( p[i], xy);
	  areaSum += p[i].size;
	}
      if( areaSum != big.size || !allInBig )
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
