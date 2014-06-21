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
const int N = 1e5 + 7;
const int M = 1e5 + 7;
int edge[ M * 2 + 7][3], edgei;
int s[N];
int n, m;
int belong[N];
int du[N];
bool vis[N];
vector<ppi> ee[N];
vector<int> dd[N];
vector<int> gg[N];
void add( int f, int t )
{
  ++edgei;
  edge[edgei][0] = t, edge[edgei][1] = s[f], s[f] = edgei;
  ++du[f];
}
int dfs( int v, int from )
{
  if( vis[v] )
    return 0;
  vis[v] = true;
  int r = 1;
  for( int i = s[v]; i; i = edge[i][1] )
    {
      int t = edge[i][0];
      if( t != from )
	r += dfs( t, v );
    }
  return r;
}
int couple( int v )
{
  return v + ( v & 1 ? 1 : -1 );
}
void dfsss( int v, int from, vector<int> &lst )
{
  lst.push_back( v );
  if( vis[v] )
    return ;
  vis[v] = true;
  int c = 0;
  if( ee[v][0].first == from )
    c = 1;
  if( ee[v][c].second & 1 )
    {
      dfsss( ee[v][c].first, v, lst);
    }
}
pair<int,int> dfss( int v, int from )
{
  if( du[v] == 4 )
    return make_pair( v, 0 );
  int t = edge[s[v]][0];
  if( t == from )
    t = edge[ edge[s[v]][1] ][0];
  pair<int,int> r = dfss( t, v );
  ++r.second;
  return r;
}
void dfssss( int v, int from, int be )
{
  if( belong[v] == -1 )
    return;
  if( !vis[v] )
    {
      vis[v] = true;
      belong[v] = be;
      for( int i = s[v]; i; i = edge[i][1] )
	{
	  int t = edge[i][0];
	  dfssss( t, v, be == 1 ? 2 : 1 );
	}
    }
  else 
    {
      // assert( belong[v] == be );
    }
}
int main()
{
  scanf("%d%d", &n, &m);
  for( int i = 0; i < m; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      add( a, b );
      add( b, a );
    }
  assert( n == dfs( 1, 0 ) );
  memset( vis, 0, sizeof( vis ) );
  int fdu(0);
  for( int i = 1; i <= n; ++i )
    if( du[i] == 4 )
      {
	fdu = i;
	vector<pair<int,int> > c;
	for( int j = s[i]; j; j = edge[j][1] )
	  {
	    int t = edge[j][0];
	    c.push_back( dfss( t, i ) );
	  }
	sort( c.begin(), c.end() );
	ee[i].push_back( make_pair( c[0].first, c[0].second + c[1].second + 2) );
	ee[i].push_back( make_pair( c[2].first, c[2].second + c[3].second + 2) );
	dd[i].push_back( ee[i][0].second & 1 );
	dd[i].push_back( ee[i][1].second & 1 );
	gg[i].push_back( c[0].second );
	gg[i].push_back( c[2].second );
      }
  assert( fdu > 0 );
  for(int ff = 1 ; ff <= n ; ++ff )
    {
      if( !vis[ff] && du[ff] == 4 )
	{
	  vis[ff] = true;
	  vector<int> lst[2];
	  for( int j = 0; j < 2; ++j )
	    if( dd[ff][j] == 1 )
	      dfsss( ee[ff][j].first, ff, lst[j] );
	  if( !lst[0].empty() && lst[0][ lst[0].size() - 1 ] == ff )
	    {
	      for( int j = 1; j < lst[0].size(); j += 2 )
		{
		  belong[ lst[0][j] ] = -1;
		}
	      if( lst[0].size() & 1  )
		belong[ff] = -1;
	    }
	  else
	    {
	      int i = lst[0].size() - 2;
	      for( ; i >= 0; i -= 2 )
		belong[ lst[0][i] ] = -1;
	      if( i == -1 )
		belong[ff] = -1, i = 1;
	      else i = 0;
	      for( ; i < lst[1].size(); i += 2 )
		belong[ lst[1][i] ] = -1;
	    }
	}
      // if( pre != ee[ff][0].first )
      // 	pre = ff, ff = ee[ff][0].first;
      // else
      // 	pre = ff, ff = ee[ff][1].first;
      // if( ff == fdu )
      // 	break;
    }
  int cnt(0);
  for( int i = 1; i <= n; ++i )
    if( belong[i] == -1 )
      ++cnt;
  if( cnt == 0 )
    {
      int sum(0);
      for(int pre = 0, ff = fdu ; ; )
  	{
  	  int c = 0;
  	  if( ee[ff][0].first == pre )
  	    c = 1;
  	  sum += gg[ff][c] + 1;
  	  pre = ff, ff = ee[ff][c].first;
	  if( ff == fdu )
	    break;
  	}
      if( sum & 1 )
  	{
  	  belong[fdu] = -1;
  	}
    }
  memset( vis, 0, sizeof( vis ) );
  for( int i = 1; i <= n; ++i )
    if( !vis[i] && belong[i] != -1 )
      dfssss( i, 0, 1 );
  vector<int> ans[2];
  for( int i = 1; i <= n; ++i )
    if( belong[i] > 0 )
      {
	ans[ belong[i] - 1 ].push_back(i);
      }
  for( int i = 0; i < 2; ++i )
    {
      printf("%d", (int)ans[i].size() );
      for( int j = 0; j < ans[i].size(); ++j )
	printf(" %d", ans[i][j]);
      printf("\n");
    }
  return 0;
}
