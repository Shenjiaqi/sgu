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
const int N = 107;
int p[ N * 2 ][4], poi;
bool left[ N * 2 ];
int q[2][ N * N ][2];
int s[ N * 2 ];
int c[ N * 2 ];
int d[ N * 2 ];
int n, m[2];
int ss, tt;
void add( int from, int to, int id )
{
  ++poi;
  p[poi][0] = to, p[poi][1] = 1, p[poi][2] = id, p[poi][3] = s[from],
    s[from] = poi;
  ++poi;
  p[poi][0] = from, p[poi][1] = 0, p[poi][2] = -1, p[poi][3] = s[to],
    s[to] = poi;
}
bool bfs()
{
  memcpy( c, s, sizeof(c) );
  memset( d, 0, sizeof(d) );
  queue<int> que;
  que.push(ss);
  d[ss] = 1;
  for( ; que.empty(); )
    {
      int v = que.front();
      que.pop();
      for( int i = c[v]; i; i = p[i][3] )
	if( p[i][1] )
	  {
	    int t = p[i][0];
	    if( d[t] == 0 )
	      {
		d[t] = d[v] + 1;
		que.push(t);
	      }
	  }
    }
  return d[tt];
}
int dfs( int v, int f )
{
  if( v == tt )
    return f;
  int i = c[v];
  int rf = f;
  for( ; i; i = p[i][3])
    if( p[i][1] )
      {
	int t = p[i][0];
	if( d[t] == 1 + d[v] )
	  {
	    int tmp = dfs( t, min( f, p[i][1] ) );
	    p[i][1] -= tmp;
	    f -= tmp;
	    int pir = i + ( i & 1 ? 1 : -1 );
	    p[pir][1] += tmp;
	  }
	if( f == 0 )
	  break;
      }
  c[v] = i;
  return rf - f;
}
int mf()
{
  int r(0);
  for( ; bfs(); )
    {
      for( ; ; )
	{
	  int tmp = dfs(ss, 1e9);
	  if( tmp == 0 )
	    break;
	  r += tmp;
	}
    }
  return r;
}
int main()
{
  scanf("%d%d%d", &n, &m[0], &m[1]);
  for( int i = 0; i < m[0]; ++i )
    {
      int f, t;
      scanf("%d%d", &f, &t);
      q[0][i][0] = f, q[0][i][1] = t;
      add( f, t * 2, i );
      left[f] = true;
    }
  for( int i = 0; i < m2; ++i )
    {
      int f, t;
      scanf("%d%d", &f, &t);
      q[1][i][0] = f, q[1][i][1] = t;
      add( f, t * 2, i );
    }
  ss = 2 * n + 1, tt = ss + 1;
  for( int i = 1; i<= n; ++i )
    if( left[i] )
      add( ss, i, -1 ), add( i * 2, tt, -1 );
    else add( 2 * i, i, -1);
  int ans = mf();
  printf("%d\n", ans);
  for( int i = 1; i <= n; ++i )
    {
      for( int j = s[v]; j; j = p[j][3] )
	if( p[j][2] >= 0 && p[j][1] == 0)
	  {
	    use[ left[i] ? 0 : 1 ][ p[j][2] ] = true;
	    break;
	  }
    }
  for( int i = 0; i < 2; ++i )
    for( int j = 0; j < m[i]; ++j )
      if( use[i][j] )
	printf("%d %d\n", q[i][j][0], q[i][j][1]);
  return 0;
}
