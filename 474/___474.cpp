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
const int M = 1e5 + 7;
const int N = 25000 + 7;
const int mk = 30;
struct frag
{
  int x, y;
  int len, high;
};
// void pt(const frag & a )
// {
//   printf("%d %d %d %d\n", a.x, a.y, a.len, a.high );
// }
inline bool tri( const frag & a )
{
  return a.high < 0;
}
int areA( const frag & a )
{
  if( tri(a) )
    return a.len * a.len;
  return a.len * a.high * 2;
}
inline void mv( const frag & a, int mv[])
{
  mv[0] = mv[1] = a.x, mv[2] = mv[3] = a.y;
  mv[1] = a.x + a.len;
  if( tri(a) )
    mv[3] += a.len;
  else mv[3] += a.high;
}
inline void mvv( const frag & a, int mv[] )
{
  int minX, maxX, minY, maxY;
  minX = maxX = a.x - a.y;
  minY = maxY = a.x + a.y;
  if( tri( a ) )
    {
      maxX += a.len;
      minX -= a.len;
      maxY += a.len * 2;
      if( a.high == -1)
	maxY -= a.len;
      else if( a.high == -2 )
	minX += a.len;
      else if( a.high == -3 )
	minY += a.len;
      else
	maxX -= a.len;
    }
  else
    {
      minX -= a.high;
      maxX += a.len;
      maxY += a.len + a.high;
    }
  mv[0] = minX, mv[1] = maxX, mv[2] = minY, mv[3] = maxY;
}
inline bool apart_( int ma[], int mb[] )
{
  // 0 -> minX  1 -> maxX   2 -> minY  3 -> maxY
  return ( ma[0] >= mb[1] || ma[1] <= mb[0] ||
	   ma[2] >= mb[3] || ma[3] <= mb[2] );
}
inline bool apart( const frag &a, const frag &b)
{
  int ma[4], mb[4];
  mv( a, ma );
  mv( b, mb );
  if( apart_( ma, mb ) )
    return true;
  if( a.high >= 0 && b.high >= 0 )
    return false;
  mvv( a, ma );
  mvv( b, mb );
  return apart_( ma, mb );
}
bool allApart(const vector<frag> &s)
{
  for( int i = 0; i < s.size(); ++i )
    for( int j = i + 1; j < s.size(); ++j )
      if( !apart(s[i], s[j]) )
	return false;
  return true;
}
inline void conRec( frag & to, int x1, int y1, int len, int high )
{
  to.x = x1, to.y = y1, to.len = len, to.high = high;
}
inline void conTri( frag & to, int x1, int y1, int len, int type)
{
  to.x = x1, to.y = y1, to.len = len, to.high = type;
}
// split( big, x, y, small, areaBig, cnt );
void split( const frag & from, int x, int y, vector<frag> to[],
	    int area[], int cnt[])
{
  if( tri( from ) )
    {
      int mval[4];
      mv( from, mval );
      if( x < mval[1] && x > mval[0] && y < mval[3] && y > mval[2] )
	{
	  // assert( from.high == -1 );
	  int xx = from.x + from.y + from.len - y, 
	    yy = from.x + from.y + from.len - x;
	  frag tmp;
	  conTri( tmp, from.x, y, xx - from.x, from.high );
	  to[2].push_back(tmp);
	  area[2] += areA(tmp);
	  conTri( tmp, x, from.y, yy - from.y, from.high );
	  to[1].push_back(tmp);
	  area[1] += areA(tmp);
	  if( xx != x )
	    {
	      // assert( xx < x );
	      conTri( tmp, xx, yy, y - yy, from.high );
	      to[0].push_back(tmp);
	      area[0] += areA(tmp);
	      conRec( tmp, xx, from.y, x - xx, yy - from.y );
	      to[0].push_back(tmp);
	      area[0] += areA(tmp);
	    }
	  conRec( tmp, from.x, from.y, xx - from.x, y - from.y );
	  to[0].push_back(tmp);
	  area[0] += areA(tmp);
	  cnt[0] += ( xx - from.x ) * 2;
	  cnt[1] += ( yy - from.y ) * 2;
	  return ;
	}
      if( ( x <= mval[0] || x >= mval[1] ) &&
	  ( y <= mval[2] || y >= mval[3] ) )
	{
	  int pos;
	  // if( mval[1] <= x )
	  //   {
	  //     if( mval[3] <= y )
	  // 	pos = 0;
	  //     else pos = 2;
	  //   }
	  // else pos = 1;
	  if( x <= mval[0] )
	    pos = 1;
	  else if( y <= mval[2] )
	    pos = 2;
	  else pos = 0;
	  to[pos].push_back( from );
	  area[pos] += areA(from);
	  if( from.high == -1 )
	    {
	      if( y == mval[2] )
		cnt[0] += from.len;
	      if( x == mval[0] )
		cnt[1] += from.len;
	    }
	  else if( from.high == -2 )
	    {
	      if( y == mval[2] )
		cnt[0] += from.len;
	      if( x == mval[1] )
		cnt[1] += from.len;
	    }
	  else if( from.high == -3 )
	    {
	      if( y == mval[3] )
		cnt[0] += from.len;
	      if( x == mval[1] )
		cnt[1] += from.len;
	    }
	  else
	    {
	      if( y == mval[3] )
		cnt[0] += from.len;
	      if( x == mval[0] )
		cnt[1] += from.len;
	    }
	  return ;
	}
      bool ver = true;
      if( x < mval[1] && x > mval[0] )
	{
	  if( from.high == -1 || from.high == -3 )
	    y = from.x + from.y + from.len - x;
	  else
	    y = from.y - from.x + x;
	}
      else
	{
	  // assert( y < mval[3] && y > mval[2] );
	  ver = false;
	  if( from.high == -1 || from.high == -3 )
	    x = from.x + from.y + from.len - y;
	  else
	    x = from.x - from.y + y;
	}
      frag f[4];
      int l1 = x - from.x, h1 = y - from.y;
      int l2 = from.len - l1, h2 = from.len - h1;
      conRec( f[0], from.x, from.y, l1, h1);
      conRec( f[1], x, from.y, l2, h1);
      conRec( f[2], x, y, l2, h2 );
      conRec( f[3], from.x, y, l1, h2 );
      if( from.high == - 1 || from.high == -3 )
	{
	  f[3].high = f[1].high = from.high;
	  if( ver )
	    {
	      to[0].push_back( f[3] );
	      area[0] += areA(f[3]);
	      to[1].push_back( f[1] );
	      area[1] += areA(f[1]);
	      if( from.high == -1 )
		{
		  to[0].push_back( f[0] ), area[0] += areA(f[0]);
		  cnt[1] += h1 * 2;
		}
	      else
		{
		  to[1].push_back( f[2] ), area[1] += areA(f[2]);
		  cnt[1] += h2 * 2;
		}
	    }
	  else // horizontal
	    {
	      to[2].push_back(f[3]);
	      area[2] += areA(f[3]);
	      to[0].push_back(f[1]);
	      area[0] += areA(f[1]);
	      if( from.high == -1 )
		{
		  to[0].push_back(f[0]), area[0] += areA(f[0]);
		  cnt[0] += l1 * 2;
		}
	      else
		{
		  to[2].push_back(f[2]), area[2] += areA(f[2]);
		  cnt[0] += l2 * 2;
		}
	    }
	}
      else
	{
	  f[0].high = f[2].high = from.high;
	  if( ver )
	    {
	      to[0].push_back( f[0] );
	      area[0] += areA( f[0] );
	      to[1].push_back( f[2] );
	      area[1] += areA( f[2] );
	      if( from.high == -2 )
		{
		  to[1].push_back( f[1] );
		  area[1] += areA( f[1] );
		  cnt[1] += h1 * 2;
		}
	      else
		{
		  to[0].push_back( f[3] );
		  area[0] += areA( f[3] );
		  cnt[1] += h2 * 2;
		}
	    }
	  else// if( y < mval[3] && y > mval[2] )
	    {
	      to[0].push_back( f[0] );
	      area[0] += areA( f[0] );
	      to[2].push_back( f[2] );
	      area[2] += areA( f[2] );
	      if( from.high == -2 )
		{
		  to[0].push_back( f[1] );
		  area[0] += areA( f[1] );
		  cnt[0] += l2 * 2;
		}
	      else
		{
		  to[2].push_back( f[3] );
		  area[2] += areA( f[3] );
		  cnt[0] += l1 * 2;
		}
	    }
	}
    }
  else
    { // rectangle
      // assert( x <= from.x || x >= from.x + from.len ||
      // 	      y <= from.y || y >= from.y + from.high );
      frag tmp;
      if( ( x >= from.x + from.len || x <= from.x ) &&
	  ( y >= from.y + from.high || y <= from.y ) )
	{
	  // if( x >= from.x + from.len )
	  //   {
	  //     if( y >= from.y + from.high )
	  // 	{
	  // 	  to[0].push_back( from );
	  // 	  area[0] += areA( from );
	  // 	}
	  //     else
	  // 	{
	  // 	  to[2].push_back( from );
	  // 	  area[2] += areA( from );
	  // 	}
	  //   }
	  // else
	  //   {
	  //     to[1].push_back( from );
	  //     area[1] += areA( from );
	  //   }
	  int pos;
	  if( x <= from.x )
	    pos = 1;
	  else if( y <= from.y )
	    pos = 2;
	  else pos = 0;
	  to[pos].push_back( from );
	  area[pos] += areA( from );
	  if( x == from.x || x == from.x + from.len )
	    cnt[1] += from.high;
	  if( y == from.y || y == from.y + from.high )
	    cnt[0] += from.len;
	}
      else if( x < from.x + from.len && x > from.x )
	{
	  conRec( tmp, from.x, from.y, x - from.x, from.high );
	  to[0].push_back(tmp);
	  area[0] += areA(tmp);
	  conRec( tmp, x, from.y, from.len - ( x - from.x ), from.high );
	  to[1].push_back(tmp);
	  area[1] += areA(tmp);
	  cnt[1] += from.high * 2;
	}
      else
	{
	  // assert( from.y < y && y < from.y + from.high );
	  conRec( tmp, from.x, from.y, from.len, y - from.y );
	  to[0].push_back(tmp);
	  area[0] += areA(tmp);
	  conRec( tmp, from.x, y, from.len, from.high - ( y - from.y ) );
	  to[2].push_back(tmp);
	  area[2] += areA(tmp);
	  cnt[0] += from.len * 2;
	}
    }
}
bool dfsTri( const frag & big, vector<frag> & s)
{
  if( s.size() < mk )
    return allApart(s);
  // pt( big );
  int x, y;
  if( tri( big ) )
    {
      // big triangle is alway like the original one
      x = big.x + big.len / 2;
      y = big.x + big.y + big.len - x;
    }
  else
    {
      if( big.len > big.high )
	x = big.x + big.len / 2, y = N + 7;
      else
	x = N + 7, y = big.y + big.high / 2;
   }
  // cout << "split " << x << ' ' << y << endl;
  vector<frag> prt[3];
  int areaSum[3] = {0}, areaBig[3] = {0};
  int cnt[2] = {0}, cntB[2] = {0};
  vector<frag> small[3];
  split( big, x, y, small, areaBig, cntB );
  // {
  //   int tmp = areA(small[0][0]);
  //   if( small[1].size() )
  //     {
  // 	tmp += areA(small[1][0]);
  // 	assert(areA(small[1][0]));
  //     }
  //   if( small[2].size() )
  //     {
  // 	tmp += areA(small[2][0]);
  // 	assert(areA(small[2][0]));
  //     }
  //   assert( tmp == areA(big) );
  // }
  // for( int i = 0 ; i < 3; ++i )
  //   if( small[i].size() )
  //     {
  // 	cout << "big" << i << ':';
  // 	pt( small[i][0] );
  // 	cout << areaBig[i] << ' ' << cntB[i] << endl;
  //     }
  // if( tri(big) )
  //   assert( cntB[1] + cntB[0] == big.len * 2 );
  // else if( big.len > big.high )
  //   assert( cntB[1] == big.high * 2 && cntB[0] == 0);
  // else assert( cntB[0] == big.len * 2 && cntB[1] == 0);
    
  for( int i = s.size() - 1; !s.empty(); s.pop_back(), --i )
    {
      split( s[i], x, y, prt, areaSum, cnt );
      // cout << i << ' ' << areaSum[0] << ' ' << areaSum[1] << ' '
      // 	   << areaSum[2] << ' ' << cnt[0] << ' ' << cnt[1] << endl;
      for( int j = 0 ; j < 3; ++j )
      	if( areaBig[j] < areaSum[j] )
      	  return false;
      if( cnt[0] > cntB[0] || cnt[1] > cntB[1] )
      	return false;
    }
  if( cnt[0] != cntB[0] || cnt[1] != cntB[1] )
  // if( cnt[0] + cnt[1] != cntB[0] + cntB[1] )
    return false;
  for( int i = 0 ; i < 3 ; ++i )
    if( areaBig[i] != areaSum[i] )
      return false;
  for( int i = 0 ; i < 3; ++i )
    if( !prt[i].empty() && ! dfsTri( small[i][0], prt[i] ) )
      return false;
  return true;
}
int main()
{
  int t;
  scanf("%d", &t);
  for(; t; --t)
    {
      int n, m;
      scanf("%d%d", &n, &m);
      ll areaSum(0);
      bool ok = true;
      vector<frag> s;
      s.resize(m);
      frag big;
      conTri( big, 0, 0, n, -1 );
      for( int i = 0; i < m; ++i )
	{
	  int x1, y1, x2, y2, x3, y3;
	  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	  if( x1 + y1 > n || x2 + y2 > n || x3 + y3 > n )
	    ok = false;
	  // assert( x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 &&
	  // 	  x3 >= 0 && y3 >= 0 );
	  if( ok )
	    {
	      int type = 0;
	      int j = 0;
	      for( ; j < 3; ++j )
		{
		  if( ( x1 == x2 && y1 == y3 ) ||
		      ( x1 == x3 && y1 == y2 ) )
		    {
		      if( x1 == x2 )
			{
			  if( abs( y2 - y1 ) != abs( x3 - x1 ) )
			    ok = false;
			}
		      else if( abs( abs( x2 - x1 ) != abs( y3 - y1 ) ) )
			{
			  ok = false;
			}
		      if( x2 > x3 )
			swap( x2, x3 );
		      if( y2 > y3 )
			swap( y2, y3 );
		      if( x1 == x2)
			{
			  if( y1 == y2 )
			    type = -1;
			  else
			    type = -4;
			}
		      else if( y1 == y2 )
			type = -2;
		      else 
			type = -3;
		      conTri( s[i], x2, y2, x3 - x2, type );
		      // assert( y3 - y2 == x3 - x2 );
		      // assert( y3 - y2 > 0 );
		      break;
		    }
		  int tmpx = x1, tmpy = y1;
		  x1 = x2, y1 = y2;
		  x2 = x3, y2 = y3;
		  x3 = tmpx, y3 = tmpy;
		}
	      if( j >= 3 )
		ok = false;
	      areaSum += areA(s[i]);
	      if( areaSum > areA(big) )
		ok = false;
	    }
	}
      if( areaSum != areA(big) || !ok )
	{
	  printf("NO\n");
	}
      else
	{
	  // mk = 7;
	  // vector<frag> ss = s;
	  // bool a1 = dfsTri( big, s );
	  // mk = 30;
	  // bool a2 = dfsTri( big, ss);
	  // if( !a1 && a2 )
	  //   assert(0);
	  printf("%s\n", dfsTri( big, s ) ? "YES" : "NO" );
	}
    }
  return 0;
}
