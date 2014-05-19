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
const int N = 27;
int n;
char s[N][N];
bool vis[N][N];
int cnt;
bool pl[N][N];
char ch[N], bch[N];
int lm;
vector< vector<int> >p, bp;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1} };
char ppp[5][5];
int pppp, idt;
int cho[N];
int idp[N * N];
const int pri = 101999;
int hsh[pri + 7];
void dfs( int x, int y, char c )
{
  if( !vis[x][y] && s[x][y] == c )
    {
      // cout << c << ' ' << x << ' ' << y << ' ' << n << endl;
      lm = min( lm, y );
      vis[x][y] = true;
      pl[x][y] = true;
      for( int i = 1; i <= n; ++i )
	{
	  for( int j = 0; j < 4; ++j )
	    {
	      int xx = dir[j][0] * i + x;
	      int yy = dir[j][1] * i + y;
	      // cout << xx << ' ' << yy << endl;
	      if( xx >= 0 && xx < 20 && yy >= 0 && yy < 20 )
		dfs( xx, yy, c);
	    }
	}
    }
}
bool z[5][5];
int rotate( int c)
{
  memset( z, 0, sizeof(z));
  lm = 20;
  for( int i = n - 1; i >= 0; --i )
    for( int j = n - 1; j >= 0; --j )
      {
	if( c & 1 )
	  {
	    z[j][ n - 1 - i ] = true;
	    lm = min( lm, n - 1 - i );
	  }
	c >>= 1;
      }
  int r = 0;
  for( int i = 0; i < n; ++i )
    for( int j = lm; j < lm + n; ++j )
      {
	r <<= 1;
	if( j < n && z[i][j] )
	  r |= 1;
      }
  return r;
}
int right( int c)
{
  int t[5];
  for( int i = 0; i < n; ++i )
    {
      if( c & 1 )
	return 0;
      t[ n - i - 1 ] = c & ( ( 1 << n ) - 1 );
      c >>= n;
    }
  int r(0);
  for( int i = 0; i < n; ++i )
    r = ( r << n ) | ( t[i] >> 1 );
  return r;
}
int down( int c )
{
  if( c & ( ( 1 << n ) - 1 ) )
    return 0;
  return c >> n;
}
void add( int c, char cha)
{
  for( int i = n - 1; i >= 0; --i )
    for( int j = n - 1; j >= 0; --j )
      {
	if( c & 1 )
	  ppp[i][j] = cha;
	c >>= 1;
      }
}
bool dfs2(int i, int lj )
{
  if( i >= p.size() )
    return true;
  if( pppp )
    {
      int tmp = pppp % pri;
      ++tmp;
      if( hsh[tmp] == pppp )
	return false;
      hsh[tmp] = pppp;
    }
  for( int j = ( ( idt & ( 1 << i ) ) ? lj + 1 : 0 );
       j < p[i].size(); ++j )
    {
      if( ( pppp & p[i][j] ) == 0 )
	{
	  pppp |= p[i][j];
	  cho[i] = j;
	  if( dfs2( i + 1, j) ) 
	    return true;
	  pppp ^= p[i][j];
	}
    }
  return false;
}
bool cmp( int a, int b)
{
  int c = __builtin_popcount( p[a][0] );
  int d = __builtin_popcount( p[b][0] );
  if( c == d )
    return p[a][0] < p[b][0];
  return c > d;
}
int main()
{
  scanf("%d", &n);
  for( int i = 0; i < 20; ++i )
    scanf("%s", s[i]);
  for( int i = 0; i < 20; ++i )
    for( int j = 0; j < 20; ++j )
      if( s[i][j] != '.' && !vis[i][j] )
	{
	  ch[cnt] = s[i][j];
	  ++cnt;
	  memset( pl, 0, sizeof(pl) );
	  lm = 20;
	  dfs( i, j, s[i][j] );
	  int c(0);
	  for( int k = i; k < i + n; ++k )
	    for( int l = lm; l < lm + n; ++l )
	      {
		c <<= 1;
		if( pl[k][l] )
		  c |= 1;
	      }
	  vector<int> q;
	  q.push_back(c);
	  for( int k = 0; k < 3; ++k )
	    {
	      c = rotate(c);
	      q.push_back(c);
	    }
	  sort( q.begin(), q.end() );
	  q.resize( unique( q.begin(), q.end() ) - q.begin() );
	  p.push_back(q);
	  // for( auto k : q )
	  //   cout << ch[cnt-1] << ' ' << k << endl;
	  idp[ cnt - 1 ] = cnt - 1;
	}
  sort( idp, idp + cnt );
  bp = p;
  memcpy( bch, ch, sizeof(bch) );
  for( int i = 0; i < cnt; ++i )
    {
      p[i] = bp[ idp[i] ];
      ch[i] = bch[ idp[i] ];
    }
  for( int i = 0; i < p.size(); ++i )
    if( i > 0 && p[i][0] == p[i - 1][0] )
      idt |= ( 1 << i );
  for( int i = 0; i < p.size(); ++i )
    {
      for( int j = 0, jj = p[i].size(); j < jj; ++j )
	{
	  int c = p[i][j];
	  for( int count = 0; c; ++count)
	    {
	      int cc = c;
	      for( ; cc; ++count)
		{
		  if( count )
		  p[i].push_back(cc);
		  cc = right(cc);
		}
	      c = down(c);
	    }
	}
    }
  assert( dfs2(0, 0) );
  for( int i = 0; i< p.size(); ++i )
    add( p[i][cho[i]], ch[i] );
  for( int i = 0; i < n; ++i )
    {
      for( int j = 0; j < n; ++j )
	printf("%c", ppp[i][j]);
      printf("\n");
    }
  return 0;
}
