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
//#include <unordered_set>
//#include <unordered_map>
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
int tag[1 << 21], tagi;
ll num[2][1 << 21];
queue<int> que[2];
int qf, qt;
int p[4], n;
void add( int to, int c1, int c2, int c3, int c4, int left, int under, int pos, int val, ll cnt)
{
  // int v = ( c1 << 15 ) | ( c2 << 10 ) | ( c3 << 5 ) | ( left << 4 );
  int v = ( c1 << 16 ) | ( c2 << 11 ) | ( c3 << 6 ) | ( left << 5 );
  if( pos == 0 )
    v |= ( ( under << 1 ) | val );
  else
    {
      v |= under;
      if( ( ( under >> pos ) & 1 ) != val )
	v ^= ( 1 << pos );
    }
  if( tag[v] != tagi )
    {
      tag[v] = tagi;
      num[to][v] = cnt;
      que[to].push(v);
    }
  else
    {
      num[to][v] += cnt;
    }
}
void decompo( int used, int v, int *c, int &left, int &under )
{
  // c[0] = v >> 15;
  // c[1] = ( v >> 10 ) & 31;
  // c[2] = ( v >> 5 ) & 31;
  // left = ( v >> 4 ) & 1;
  // c[3] = p[3] - ( used - ( p[0] + p[1] + p[2] - c[0] - c[1] - c[2] ) );
  // under = v & 15;
  c[0] = v >> 16;
  c[1] = ( v >> 11 ) & 31;
  c[2] = ( v >> 6 ) & 31;
  left = ( v >> 5 ) & 1;
  c[3] = n * n - used - c[0] - c[1] - c[2];
  under = v & 31;
}
int main()
{
  scanf("%d%d%d%d%d", &n, p, p + 1, p + 2, p + 3);
  ++tagi;
  qf = 0, qt = 1;
  add( qf, p[0], p[1], p[2], p[3], 0, 0, 0, 0, 1);
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < 2 * i + 1; ++j )
      {
	++tagi;
	for( ; !que[qf].empty(); que[qf].pop() )
	  {
	    int conf = que[qf].front();
	    int c[4];
	    int left, under;
	    ll m = num[qf][conf];
	    decompo( i * i + j, conf, c, left, under);
	    if( j == 0 )
	      {
		if( c[0] > 0 )
		  add( qt, c[0] - 1, c[1], c[2], c[3], 0, under, j, 0, m);
		if( c[1] > 0 )
		  {
		    add( qt, c[0], c[1] - 1, c[2], c[3], 0, under, j, 0, m);
		    add( qt, c[0], c[1] - 1, c[2], c[3], 0, under, j, 1, m);
		    add( qt, c[0], c[1] - 1, c[2], c[3], 1, under, j, 0, m);
		  }
		if( c[2] > 0 )
		  {
		    add( qt, c[0], c[1], c[2] - 1, c[3], 1, under, j, 1, m);
		    add( qt, c[0], c[1], c[2] - 1, c[3], 0, under, j, 1, m);
		    add( qt, c[0], c[1], c[2] - 1, c[3], 1, under, j, 0, m);
		  }
		if( c[3] > 0 )
		  add( qt, c[0], c[1], c[2], c[3] - 1, 1, under, j, 1, m);
	      }
	    else if( ( j & 1 ) == 0 )
	      {
		if( left == 0 )
		  {
		    if( c[0] > 0 )
		      add( qt, c[0] - 1, c[1], c[2], c[3], 0, under, j / 2, 0, m);
		    if( c[1] > 0 )
		      {
			add( qt, c[0], c[1] - 1, c[2], c[3], 0, under, j / 2, 1, m);
			add( qt, c[0], c[1] - 1, c[2], c[3], 1, under, j / 2, 0, m);
		      }
		    if( c[2] > 0 )
		      add( qt, c[0], c[1], c[2] - 1, c[3], 1, under, j / 2, 1, m);
		  }
		else
		  {
		    if( c[1] > 0 )
		      add( qt, c[0], c[1] - 1, c[2], c[3], 0, under, j / 2, 0, m);
		    if( c[2] > 0 )
		      {
			add( qt, c[0], c[1], c[2] - 1, c[3], 0, under, j / 2, 1, m);
			add( qt, c[0], c[1], c[2] - 1, c[3], 1, under, j / 2, 0, m);
		      }
		    if( c[3] > 0 )
		      add( qt, c[0], c[1], c[2], c[3] - 1, 1, under, j / 2, 1, m);
		  }
	      }
	    else
	      {
		int pos = ( j + 1 ) / 2;
		int u = ( under >> pos ) & 1;
		if( left == 0 && u == 0 )
		  {
		    if( c[0] > 0 )
		      add( qt, c[0] - 1, c[1], c[2], c[3], 0, under, pos, u, m);
		    if( c[1] > 0 )
		      add( qt, c[0], c[1] - 1, c[2], c[3], 1, under, pos, u, m);
		  }
		else if( ( left == 0 && u == 1 ) || 
			 ( left == 1 && u == 0 ) )
		  {
		    if( c[1] > 0 )
		      add( qt, c[0], c[1] - 1, c[2], c[3], 0, under, pos, u, m);
		    if( c[2] > 0 )
		      add( qt, c[0], c[1], c[2] - 1, c[3], 1, under, pos, u, m);
		  }
		else // left == 1 && u == 1
		  {
		    if( c[2] > 0 )
		      add( qt, c[0], c[1], c[2] - 1, c[3], 0, under, pos, u, m);
		    if( c[3] > 0 )
		      add( qt, c[0], c[1], c[2], c[3] - 1, 1, under, pos, u, m);
		  }
	      }
	  }
	swap( qf, qt);
      }
  ll ans(0);
  for( ; !que[qf].empty(); que[qf].pop() )
    ans += num[qf][ que[qf].front() ];
  cout << ans;
  return 0;
}
