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
const int N = 21;
const int NN = N + N * N + 7;
const int M = ( NN * NN ) * 2 + 7;
int w[N], r[N], sum[N];
int a[N][N];
int s[NN];
int ss[NN];
int edge[M][3], edgeI;
int lev[NN];
int S, T;
void add( int from, int to, int cap )
{
  ++edgeI, edge[edgeI][2] = s[from], s[from] = edgeI,
    edge[edgeI][1] = cap, edge[edgeI][0] = to;
  ++edgeI, edge[edgeI][2] = s[to], s[to] = edgeI,
    edge[edgeI][1] = 0, edge[edgeI][0] = from;
}
bool bfs()
{
  queue<int> que;
  memset( lev, 1 << 6, sizeof(lev) );
  int inf = lev[T];
  lev[S] = 0;
  que.push(S);
  for(; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      for( int i = s[v]; i; i = edge[i][2] )
	if( edge[i][1] > 0 )
	  {
	    int t = edge[i][0];
	    if( lev[t] > lev[v] + 1 )
	      {
		lev[t] = lev[v] + 1;
		if( T == t )
		  return true;
		que.push(t);
	      }
	  }
    }
  return false;
}
int dfs( int v, int f)
{
  if( v == T )
    return f;
  int k = s[v];
  int rf = f;
  for( ; f > 0 && k; k = edge[k][2] )
    if( edge[k][1] > 0 )
      {
	int t = edge[k][0];
	if( lev[t] == 1 + lev[v] )
	  {
	    int tmp = dfs( t, min(f, edge[k][1] ) );
	    edge[k][1] -= tmp;
	    edge[k + ( k & 1 ? 1 : -1 ) ][1] += tmp;
	    f -= tmp;
	  }
      }
  s[v] = k;
  return rf - f;
}
int mf()
{
  int r(0);
  memcpy( ss, s, sizeof(ss) );
  for(;bfs();)
    {
      for(;;)
	{
	  int tmp = dfs(S, 1e7);
	  if( tmp == 0 )
	    break;
	  r += tmp;
	}
      memcpy( s, ss, sizeof(s) );
    }
  return r;
}
int main()
{
  int n;
  scanf("%d", &n );
  for( int i = 0; i < n ; ++i )
    scanf("%d", w + i );
  for( int i = 0; i < n ; ++i )
    scanf("%d", r + i );
  for( int i = 0; i < n; ++i )
    for( int j = 0; j <n; ++j )
      {
	scanf("%d", &a[i][j] );
	sum[i] += a[i][j];
      }
  if( sum[0] < r[0] )
    {
      w[0] += r[0] - sum[0];
      r[0] = sum[0];
    }
  for( int i = 1; i < n ; ++i )
    if( sum[i] < r[i] )
      r[i] = sum[i];
  for( int i = 0; i < n; ++i )
    if( a[0][i] > 0 )
      w[0] += a[0][i],
	r[i] -= a[0][i];
  for( int i = 1; i < n; ++i )
    if( w[i] > w[0] )
      {
	printf("NO");
	return 0;
      }
  int poi = n;
  int mmf(0);
  S = n + n * n, T = S + 1;
  for( int i = 1; i < n; ++i )
    for( int j = i + 1; j < n; ++j )
      if( a[i][j] > 0 )
	{
	  add( S, poi, a[i][j] );
	  add( poi, i, a[i][j] );
	  add( poi, j, a[i][j] );
	  ++poi;
	  mmf += a[i][j];
	}
  assert( T < NN );
  for( int i = 1; i < n; ++i )
    {
      add( i, T, min( r[i], w[0] - w[i] ) );
    }
  int tmp = mf();
  if( mmf == tmp )
    printf("YES");
  else printf("NO");
  assert( tmp <= mmf );
  return 0;
}
