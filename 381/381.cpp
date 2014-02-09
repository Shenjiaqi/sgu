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
const int N = 100007;
const int M = 500007;
int n,m;
vector<ppi> p[N];
int tag[N][2],tagI;
const int inf = 1e9;
void add(int v1, int v2, int d1, int d2)
{
  int tmp = d1 == d2 ? 0 : 1;
  p[v1].push_back( ppi( v2, tmp ) );
  p[v2].push_back( ppi( v1, tmp ) );
}
int dfs(int v, int chg)
{
  if( tag[v][0] == tagI )
    {
      if( tag[v][1] != chg )
	return inf;
      return 0;
    }
  tag[v][0] = tagI;
  tag[v][1] = chg;
  int r = chg ? 1 : 0;
  for(int j = 0 ; j < p[v].size() ; ++j)
    {
      ppi i = p[v][j];
      int toV = i.first;
      int different = i.second;
      r += dfs( toV, different == chg ? 1 : 0);
      if( r >= inf )
	return inf;
    }
  return r;
}
int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < m ; ++i)
    {
      int va, vb, da, db;
      scanf("%d%d%d%d", &va, &vb, &da, &db);
      add(va, vb, da, db);
    }
  int ans(0);
  for(int i = 1 ; i <= n ; ++i)
    if( tag[i][0] == 0 )
      {
	++tagI;
	int v0 = dfs( i, 0);
	++tagI;
	int v1 = dfs( i, 1 );
	ans += min(v0, v1);
	if( ans >= inf)
	  {
	    printf("NO");
	    return 0;
	  }
	if( v0 < v1 )
	  {
	    ++tagI;
	    dfs(i, 0);
	  }
      }
  printf("YES\n%d", ans);
  for(int i = 1 ; i <= n ; ++i)
    if( tag[i][1] == 1 )
      printf("\n%d", i);
  return 0;
}
