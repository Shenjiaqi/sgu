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
// #include <unordered_set>
// #include <unordered_map>
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
const int N = 2e4 + 7;
int p[N][4];
bool conf[N];
int gcd( int a, int b)
{
  return b == 0 ? a : gcd( b, a % b );
}
struct e
{
  int dis, tim;
  bool on;
  int id;
  e(int d, int t, bool o, int i)
  {
    // int tmp = gcd( d, t);
    // dis = d / tmp, tim = t / tmp, on = o, id = i;
    dis = d, tim = t, on = o, id = i;
  };
};
bool cmp( const e &a, const e &b )
{
  // if( (ld)a.dis / (ld)a.tim >= (ld)b.dis / (ld)b.tim )
  //   return true;
  int t1 = a.dis * b.tim;
  int t2 = b.dis * a.tim;
  if( t1 != t2 )
    return t1 > t2;
  if( a.on != b.on )
    return a.on;
  return a.id < b.id;
}
bool chk( int dis, int tim, int tR, int tG, int vDis, int vTim )
{
  if( dis * vTim <= vDis * tim )
    {
      if( tim <= tG )
	return true;
      tim -= tG;
      return dis * vTim >= vDis * tim;
    }
  int tmp = ( dis * vTim - vDis * tim ) % ( ( tR + tG ) * vDis );
  return ( tmp == 0 || ( tmp >= tR * vDis ) );
}
int main()
{
  int n, s, vMin, vMax;
  scanf("%d%d%d%d", &n, &s, &vMin, &vMax);
  vector<e> v;
  for( int i = 0; i < n; ++i )
    {
      scanf("%d%d%d%d", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);
      int dis = p[i][0];
      int tim = p[i][3];
      int tR = p[i][1];
      int tG = p[i][2];
      if( chk( dis, tim, tR, tG, vMax, 1) )
	conf[i] = false;
      else conf[i] = true;
      if( tim > tG )
	{
	  int tt = tim - tG;
	  int tmp = gcd( dis, tt);
	  if( dis <= vMax * tt && dis >= vMin * tt )
	    v.push_back( e( dis / tmp, tt / tmp, true, i) );
	}
      for( ; dis >= vMin * tim ; )
	{
	  int tmp = gcd( dis, tim );
	  if( dis <= vMax * tim )
	    v.push_back( e( dis / tmp, tim / tmp, false, i) );
	  tim += tR;
	  tmp = gcd( dis, tim );
	  if( dis <= vMax * tim && dis >= vMin * tim )
	    v.push_back( e( dis / tmp, tim / tmp, true, i ) ) ;
	  tim += tG;
	}
    }
  sort( v.begin(), v.end(), cmp );
  int ansC(0), ansD = vMax, ansT = 1;
  for( int i = 0; i < n; ++i )
    if( conf[i] )
      ansC += 1;
  for( int i = 0, cnt = ansC; i < v.size(); )
    {
      int j = i;
      for( ; j < v.size() && v[i].dis == v[j].dis &&
	     v[i].tim == v[j].tim && v[j].on; ++j )
	if( conf[ v[j].id ] )
	  conf[ v[j].id ] = false, --cnt;
      // cout << (ld) v[i].dis / (ld) v[i].tim << ' ' << cnt << endl;
      if( cnt < ansC )
	ansC = cnt, ansD = v[i].dis, ansT = v[i].tim;
      for( ; j < v.size() && v[i].dis == v[j].dis &&
	     v[i].tim == v[j].tim ; ++j )
	if( !conf[ v[j].id ] )
	  conf[ v[j].id ] = true, ++cnt;
      i = j;
    }
  printf("%.10lf\n%d\n", (double)( (ld)ansD / (ld)ansT), ansC);
  for( int i = 0; i < n; ++i )
    if( !chk( p[i][0], p[i][3], p[i][1], p[i][2], ansD, ansT ) )
      printf("%d ", i + 1);
  return 0;
}
