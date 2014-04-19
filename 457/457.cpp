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
const int N = 277;
const int M = 5777;
const int inf = M * 107;
vector<int> rd[N];
int n, m, a, b, ss, tt, ans, ni;
int p[ M * 4 + N * 4 ][3];
int q[ M * 4 + N * 3 ][3];
int poi, qoi;
int s[N], qs[N], c[N];
int z[M * 107][3], zi;
int sz[N];
bool g[N], gg[N];
int buf[ M * 107 * 2];
int bufi;
int d[N];
int du[N][2];
int bak[M][3], baki;
int opo[N];
void dfs1(int v )
{
  if( !gg[v] )
    {
      gg[v] = true;
      for( vector<int>::iterator i = rd[v].begin(); i != rd[v].end(); ++i )
	dfs1( *i );
    }
}
void add1( int f, int t, int w )
{
  // cout << f << ' ' << t << ' ' << w << endl;
  ++zi;
  z[zi][0] = t, z[zi][1] = w, z[zi][2] = sz[f], sz[f] = zi;
}
void add( int f, int t, int w, int arr[][3], int & ai, int si[] )
{
  ++ai;
  arr[ai][0] = t, arr[ai][1] = w, arr[ai][2] = si[f], si[f] = ai;
  ++ai;
  arr[ai][0] = f, arr[ai][1] = 0, arr[ai][2] = si[t], si[t] = ai;
}
bool bfs()
{
  // memcpy( c, qs, sizeof( qs[0] ) * ( n + 3 ) );
  // memset(d, 0, sizeof(d[0]) * ( n + 3 ) );
  memcpy( c, qs, sizeof(qs) );
  memset(d, 0, sizeof(d) );
  queue<int> que;
  que.push(ss);
  d[ss] = 1;
  for( ; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      for( int i = c[v]; i; i = q[i][2] )
	{
	  if( q[i][1] > 0 )
	    {
	      int t = q[i][0];
	      if( d[t] == 0 )
	      {
		d[t] = d[v] + 1;
		que.push(t);
	      }
	    }
	}
    }
  // cout << c[ss] << ' ' << d[tt] << endl;
  // for( int i = c[ss]; i; i = q[i][2] )
  //   cout << q[i][1] << ' ';cout << endl;
  return d[tt] > 0;
}
int dfs( int v, int f )
{
  if( v == tt )
    return f;
  int rf = f;
  int i = c[v];
  for( ; i && f > 0; i = q[i][2] )
    {
      int t = q[i][0];
      if( q[i][1] > 0 && d[t] == d[v] + 1 )
	{
	  int tmp = dfs( t, min( f, q[i][1] ) );
	  f -= tmp;
	  q[i][1] -= tmp;
	  q[ i + ( ( i & 1 ) ? 1 : -1 ) ][1] += tmp;
	}
      if( f <= 0 )
	break;
    }
  c[v] = i;
  return rf - f;
}
void mf()
{
  for( ; bfs(); )
    for( ; dfs( ss, inf); )
      ;//cout << tmp << endl;
}
bool chk( int v )
{
  // memcpy( q, p, sizeof( p[0] ) * ( poi + 1 ) );
  // memcpy( qs, s, sizeof( s[0] ) * ( n + 3 ) );
  memcpy( q, p, sizeof(p) );
  memcpy( qs, s, sizeof(s) );
  qoi = poi;
  add( b, tt, v, q, qoi, qs );
  add( ss, a, v, q, qoi, qs );
  add( b, a, inf, q, qoi, qs);
  mf();
  for( int i = qs[ss]; i; i = q[i][2] )
    if( q[i][1] > 0 )
      return false;
  return true;
}
void dfs( int v )
{
  for( int i = sz[v]; i; i = z[i][2] )
    {
      for( ;z[i][1] > 0; )
	{
	  --z[i][1];
	  dfs( z[i][0] );
	}
    }
  buf[bufi] = v;
  ++bufi;
}
void prt()
{
  if( ans == 0 )
    printf("0");
  else
    {
      chk(ans);
      // assert( q[qoi - 1][1] == m * 107 );
      for( int i = 1; i <= ni; ++i )
	if( i != ss && i != tt )
	  for( int j = qs[i]; j; j = q[j][2] )
	    if( j & 1 )
	      {
		int t = q[j][0];
		// if( ( i == opo[2] || i == 2 ) && ( t == 4 || t == opo[4] ) )
		//   cout << q[j + 1][1] << endl;
		if( t != ss && t != tt && q[ j + 1 ][1] )
		  {
		    int from, to;
		    from = min( opo[i], i );
		    to = min( opo[t], t );
		    // cout << "!" << i << ' ' << t << endl;
		    if( from != to )
		      add1( from, to, q[ j + 1 ][1] );
		  }
		// if( t != tt && t != ss && p[j][1] > 0 && p[j][1] > q[j][1] )
		//   add1( i, t, p[j][1] - q[j][1] );
	      }
      add1( b, a, ans );
      dfs(a);
      printf("%d", ans);
      int cnt(0);
      for( int i = bufi - 1; i > 0; --i)
	{
	  printf("\n");
	  // assert( buf[i] == a );
	  for(; i > 0; --i )
	    {
	      printf("%c ", (char)( buf[i] + '0' ) );
	      if( buf[i] == b )
		break;
	    }
	  // assert( buf[i] == b );
	  ++cnt;
	}
      assert( cnt == ans );
    }
}
int main()
{
  scanf("%d%d%d%d", &n, &m, &a, &b);
  ni = n;
  ss = ++ni, tt = ++ni;
  for( int i = 0; i < m ; ++i )
    {
      int f, t, w, type;
      scanf("%d%d%d%d", &f, &t, &w, &type);
      if( w > 0 )
	{
	  rd[f].push_back(t);
	  if( type )
	    {
	      g[t] = true;
	      g[f] = true;
	      du[f][0] += w, du[t][1] += w;
	      // ++du[f][0], ++du[t][1];
	      add( ss, t, w, p, poi, s );
	      add( f, tt, w, p, poi, s );
	      add1( f, t, w );
	    }
	  else
	    {
	      // add( f, t, w, p, poi, s );
	      bak[baki][0] = f, bak[baki][1] = t, bak[baki][2] = w;
	      ++baki;
	    }
	}
    }
  dfs1( a );
  for( int i = 1; i <= n; ++i )
    if( g[i] && !gg[i] )
      {
	printf("0");
	return 0;
      }
  for( int i = 1; i <= n; ++i )
    {
      if( du[i][1] > 0 && du[i][0] == du[i][1] )
	{
	  opo[i] = ++ni;
	  opo[ni] = i;
	  // cout << "!" << i << ' ' << ni << endl;
	  add( i, ni, inf, p, poi, s );
	  add( i, tt, 1, p, poi, s );
	  add( ss, ni, 1, p, poi, s );
	}
      else
	{
	  opo[i] = i;
	}
    }
  // cout << du[2][0] << ' ' << du[2][1] << endl;
  for( int i = 0; i < baki; ++i )
    {
      int f = bak[i][0], t = bak[i][1], w = bak[i][2];
      // if( f == 2 && t == 4 )
      // 	cout << w << ' ' << opo[2] << endl;
      add( opo[f], t, w, p, poi, s );
    }
  for( int f = 0, t = inf; f <= t; )
    {
      int mid = ( f + t ) / 2;
      if( chk( mid ) )
	ans = mid, f = mid + 1;
      else t = mid - 1;
    }
  prt();
  return 0;
}
