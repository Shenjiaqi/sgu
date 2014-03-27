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
const ld det = 1e-16;
ld square( ld v )
{
  return v * v;
}
int main()
{
  int h, d, m;
  cin >> h >> d >> m;
  if( h > d || d > m )
    printf("NO");
  else if( d == h )
    {
      if( m == h )
	printf("YES\n0 %d\n-1 0\n1 0", h);
      else printf("NO");
    }
  // else if( m == h )
  //   {
  //     printf("NO");
    // }
  else
    {
      ld alpha = acosl( (ld)h / (ld)d );
      ld mx = acosl(0);
      ld ans = 0;
      for( ld f = 0.0, t = mx - alpha; t - f > det;)
	{
	  ld theta = ( f + t ) / (ld)2.0;
	  ans = theta;
	  ld x1 = h * tanl( - theta - alpha );
	  ld x2 = h * tanl( theta - alpha );
	  // ld a = h / cosl( theta + alpha );
	  // ld b = h / cosl( theta - alpha ); 
	  // if( theta < alpha )
	  //   {
	  //   }
	  ld tmp = x1 + x2;
	  tmp = square( tmp ) + (ld) 4.0 * square(h);
	  if( (ld)4.0 * square( m ) >= tmp - det )
	    f = theta;
	  else t = theta;
	  // cout << tmp  << ' ' << theta << ' ' << 4.0 * square(m) << endl;
	}
      ld x1 = h * tanl( - ans - alpha );
      ld x2 = h * tanl( ans - alpha );
      if( fabsl( x2 - x1 ) < 1e-8 )
	printf("NO");
      else
	{
	  printf("YES\n");
	  printf("0 %d\n", h);
	  printf("%.8lf 0\n", (double)x1);
	  printf("%.8lf 0\n", (double)x2);
	}
      // if( 4.0 * square(m) - ( square( x1 - x2 ) + (ld)4.0 * square(h) ) > 1e-7 )
      // 	assert(0);
      // assert( fabs( x1 - x2 ) > 1e-3 && fabs(x1) < 1e8 &&
      // 	      fabs(x2) < 1e8 );
      // ld a2 = square( x1 ) + square(h);
      // ld c2 = square( x2 ) + square(h);
      // ld th = acosl( ( a2 + square( x1 - x2 ) - c2 ) / ( 2.0 * sqrtl(a2) * fabsl( x1 - x2 ) ) );
      // ld xx = sinl( ans * 2.0 ) * sqrtl(c2) / sinl( th );
      // // cout << xx << ' ' << ( x1 - x2 ) << ' ' << endl;
      // assert( fabs( xx + x1 - x2 ) < 1e-7 );
      // ld mmx = ( x1 + x2 ) / 2.0;
      // ld mm = sqrtl( square( mmx ) + square( h ) );
      // cout << mm << ' ' << m << endl;
      // assert( mm - m < 1e-7 );
    }
  return 0;
}
