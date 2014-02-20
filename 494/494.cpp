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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 10007;
const int W = 1007;
int len[N];
int pos[N][2];
int dp[N][2];
int lenSum[N];
// int dpCol[N][10][2];
int dpCol[N][3];
int st[N];
stack<int> chgSt[W];
int cnt;
int lenN[N][W];
int calLen( int v, int length, int ed)
{
  // int nextV = v;
  // ++cnt;
  // for( int f = v + 1, t = min( ed , v + len / 2 + 1 ); f <= t ; )
  //   {
  //     int mid = ( f + t ) >> 1;
  //     if( lenSum[mid] - lenSum[v] + mid - v - 1 <= len )
  // 	nextV = mid, f = mid + 1;
  //     else t = mid - 1;
  //   }
  // return nextV;
  if( v == ed || length < len[v] )
    return v;
  return lenN[v][length];
}
// int calDpCol( int v, int lev, int c1, int c2, int tag, int ed)
// {
//   if( dpCol[v][lev][0] != tag )
//     {
//       dpCol[v][lev][0] = tag;
//       if( lev != 0 )
// 	{
// 	  int midV = calDpCol( v, lev - 1, c1, c2, tag, ed );
// 	  dpCol[v][lev][1] = calDpCol( midV, lev - 1, c1, c2, tag, ed );
// 	}
//       else
// 	{
// 	  int midV = calLen( v, c1, ed );
// 	  dpCol[v][lev][1] = calLen( midV, c2, ed );
// 	}
//     }
//   return dpCol[v][lev][1];
// }
int cal( int v, int c1, int c2, int line, 
	 int ed, int tag)
{
  // for( int i = 0 ; v != ed && line ; ++i, line >>= 1 )
  //   if( line & 1 )
  //     {
  // 	int lastV = v;
  // 	v = calDpCol( v, i, c1, c2, tag, ed );
  // 	if( v == lastV )
  // 	  break;
  //     }
  // printf(" %d %d %d %d %d %d\n", v, c1, c2, line, tag, ed);
  if( v == ed || line == 0 )
    return v;
  if( line < 0 )
    {
      cout << line << endl;
      assert( 0 );
    }
  if( dpCol[v][0] == tag )
    {
      // if( line < dpCol[v][2] )
      //   {
      //     cout << v << ' ' << ed << ' ' << dpCol[v][2] << ' ' << line << endl;
      //   }
      if( dpCol[v][1] != v )
	dpCol[v][1] = cal( dpCol[v][1], c1, c2, line - dpCol[v][2], ed, tag );
      dpCol[v][2] = line;
    }
  else
    {
      dpCol[v][0] = tag;
      int midV = calLen( v, c1, ed);
      int nextV = calLen( midV, c2, ed);
      if( nextV != v )
	dpCol[v][1] = cal( nextV, c1, c2, line - 1, ed, tag );
      else dpCol[v][1] = nextV;
      dpCol[v][2] = line;
    }
  return dpCol[v][1];
}
void update(int v, int row, int col,int limit, int array[][2] )
{
  if( col + len[v] > limit )
    col = 0, ++row;
  if( ( array[v][0] == 0 && array[v][1] == 0 ) ||
      array[v][0] > row || 
      ( array[v][0] == row && array[v][1] > col ) )
    {
      array[v][0] = row, array[v][1] = col;
    }
}
int main()
{
  int t;
  scanf("%d", &t);
  for( int i = 0 ; t-- ; )
    {
      int n, w, r, c;
      scanf("%d%d%d%d", &n, &w, &r, &c);
      int s = i;
      for( int j = 0 ; j < n ; ++i, ++j )
	scanf("%d", len + i );
      len[i] = 0;
      // lenSum[s] = 0;
      // for( int j = s + 1; j <= i ; ++j )
      // 	lenSum[j] = lenSum[ j - 1 ] + len[ j - 1 ];
      for( int j = s ; j <= i ; ++ j )
	{
	  int nextV = min( i, j +1 );
	  lenN[j][ len[j] ] = nextV;
	  for( int k = 1 + len[j], left = 0 ; k <= w - c ; ++k )
	    {
	      ++left;
	      if( nextV != i && left >= 1 + len[nextV] )
		++nextV, left = 0;
	      lenN[j][k] = nextV;
	    }
	}
      pos[s][0] = pos[s][1] = 0;
      dp[s][0] = dp[s][1] = 0;
      st[0] = s;
      for( int j = s + 1 ; j <= i ; ++j )
	{
	  pos[j][0] = pos[j][1] = 0;
	  dp[j][0] = dp[j][1] = 0;
	  update( j, pos[ j - 1 ][0], pos[ j - 1 ][1] + len[ j - 1 ] + 
		  (j == i ? 0 : 1),
		  w, pos);
	  if( pos[j][1] == 0 )
	    {
	      st[ pos[j][0] ] = j;
	      if( j != s )
	      	{
	      	  int col = pos[ j - 1 ][1] + len[ j - 1 ];
	      	  if( col + c <= w )
	      	    chgSt[ col ].push(j);
	      	}
	    }
	  else if( pos[j][1] - ( j == i ? 0 : 1 ) + c <= w )
	    chgSt[ pos[j][1] - ( j == i ? 0 : 1 ) ].push( j );
	}
      int line = pos[ i - 1 ][0];
      for( int col = 0 ; col + c <= w ; ++col )
	{
	  for( ; !chgSt[col].empty() ; chgSt[col].pop() )
	    {
	      int v = chgSt[col].top();
	      st[ pos[v][0] - ( pos[v][1] == 0 ? 1 : 0 ) ] = v;
	    }
	  for( int j = 0 ; j <= line ; ++j )
	    // if( j < line || col <= pos[i][1] )
	    {
	      int nextV = cal( st[j], w - ( col + c ), col, 
			       r - 1, i, col + c);
	      update( nextV, j + r - 1, col + c, w, dp );
	    }
	}
      for( int j = s ; j < i ; ++j )
	{
	  if( dp[j][0] || dp[j][1] )
	    update( j + 1, dp[j][0], dp[j][1] + len[j] + 
		    (j + 1 == i ? 0 : 1), w, dp );
	}
      int ans = min( line + r, dp[i][0] ) + 1;
      printf("%d\n", ans);
    }
  return 0;
}
