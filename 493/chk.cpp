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
const int N = 1007;
int building[N][3];
int light[N][2];
int preBuilding[N], preCnt;
int cov[N][2];
inline int cross(int x1, int y1, int x2, int y2)
{
  return x1 * y2 - y1 * x2;
}
int cmp( const void * a, const void *b)
{
  return *(int*)a - *(int*)b;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T-- ; )
    {
      int n;
      scanf("%d", &n);
      if( n > 20 )
	return 1;
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d%d%d", &building[i][0],
		&building[i][1], &building[i][2]);
	  light[i][0] = light[i][1] = 0;
	}
      qsort(building, n, sizeof(building[0]), cmp);
      assert( n < 11 );
      for( int i = 0 ; i < n ; ++i )
	{
	  cov[i][0] = 1 << ( i * 2 );
	  for( int j = i - 1, c = cov[i][0] >> 1, vx = 0, vy = 0; j >= 0 ; --j,
		 c >>= 2)
	    {
	      int vx_ = building[j][1] - building[i][0];
	      int vy_ = 0 - building[i][2];
	      if( cross( vx, vy, vx_, vy_ ) <= 0 )
		{
		  cov[i][0] |= c;
		}
	      vx_ = building[j][0] - building[i][0];
	      vy_ = building[j][2] - building[i][2];
	      if( cross( vx, vy, vx_, vy_ ) <= 0 )
		vx = vx_, vy = vy_;
	    }
	  cov[i][1] = 1 << ( i * 2 + 1 ) ;
	  for( int j = i + 1, c = cov[i][1] << 1, vx = 0, vy = 0; j < n ; ++j,
		 c <<= 2)
	    {
	      int vx_ = building[j][0] - building[i][1];
	      int vy_ = 0 - building[i][2];
	      if( cross( vx, vy, vx_, vy_ ) >= 0 )
		cov[i][1] |= c;
	      vx_ = building[j][1] - building[i][1];
	      vy_ = building[j][2] - building[i][2];
	      if( cross( vx, vy, vx_, vy_ ) >= 0 )
		vx = vx_, vy = vy_;
	    }
	}
      int ans = n * 2, ansi;
      for( int i = 0 ; i < ( 1 << ( n * 2 ) ) ; ++i )
	if( ans > __builtin_popcount(i) )
	  {
	    int cover = 0;
	    for( int j = 0, v = i ; j < n ; ++j )
	      {
		if( v & 1 )
		  cover |= cov[j][0];
		v >>= 1;
		if( v & 1 )
		  cover |= cov[j][1];
		v >>= 1; 
	      }
	    if( cover == ( 1 << ( n * 2 ) ) -1 )
	      ans = __builtin_popcount(i), ansi = i;
	  }
      cout << ans << endl;
      for( int i = 0 ; i < n ; ++i )
	{
	  if( ansi & 1 )
	    cout << i << " 0" << endl;
	  ansi >>= 1;
	  if( ansi & 1 )
	    cout << i << " 1" << endl;
	  ansi >>= 1;
	}
    }
  return 0;
}
