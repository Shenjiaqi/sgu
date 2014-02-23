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
const ld eps = 1e-11;
ld vaX, vaY, vbX, vbY;
ld ra, rb;
ld ma, mb;
ld paX, paY, pbX, pbY;
ld t;
inline ld dis(ld xA, ld yA, ld xB, ld yB)
{
  xA -= xB, yA -= yB;
  return sqrtl( xA * xA + yA * yA );
}
inline ld distance(ld time)
{
  return dis( paX + vaX * time, paY + vaY * time, 
	      pbX + vbX * time, pbY + vbY * time );
}
inline ld mul(ld a, ld b, ld c, ld d)
{
  return a * c + b * d;
}
int main()
{
  cin >> paX >> paY >> vaX >> vaY >> ra >> ma;
  cin >> pbX >> pbY >> vbX >> vbY >> rb >> mb;
  cin >> t;
  ld timeOfMeet = 0;
  for(ld a = 0, b = t; fabsl( a - b ) > eps / 2.0 ; )
    {
      timeOfMeet = ( a + b ) / 2.0;
      ld c = ( a + timeOfMeet ) / 2.0;
      if( distance( c ) < distance( timeOfMeet ) + eps )
	b = timeOfMeet;
      else a = c;
    }
  if( distance( timeOfMeet ) < ra + rb - eps )
    {
      for( ld a = 0, b = timeOfMeet; fabsl( a - b ) > eps / 2.0; )
	{
	  timeOfMeet = ( a + b ) / 2.0;
	  if( distance( timeOfMeet ) < ra + rb )
	    b = timeOfMeet;
	  else a = timeOfMeet;
	}
      paX += vaX * timeOfMeet, paY += vaY * timeOfMeet;
      pbX += vbX * timeOfMeet, pbY += vbY * timeOfMeet;
      t -= timeOfMeet;
      ld vecABx = pbX - paX, vecABy = pbY - paY;
      ld lenVecAB = dis(vecABx, vecABy, 0, 0);
      vecABx /= lenVecAB, vecABy /= lenVecAB;
      ld va = mul(vecABx, vecABy, vaX, vaY);
      ld vb = mul(vecABx, vecABy, vbX, vbY);
      if(!( fabsl(va) < eps && fabsl(vb) < eps ))// && 
      // ( va >= 0 && vb <= 0 ) )
	{
	  ld va_, vb_;
	  ld e = ma * va * va + mb * vb * vb;
	  ld p = ma * va + mb * vb;
	  if( fabsl( p ) < eps )
	    {
	      vb_ = sqrtl( e * ma / ( mb * mb + mb * ma ) );
	      va_ = - mb * vb_ / ma ;
	      assert( isfinite( va_ ) && isfinite( vb_ )) ;
	    }
	  else
	    {
	      ld a = ( ma + mb ) / p;
	      ld b = - 2.0 ;
	      ld c = ( p - ( ma * e ) / p ) / mb;
	      ld d = b * b - 4.0 * a * c;
	      d = sqrtl( d );
	      ld ansVb1 = ( -b + d ) / ( 2.0 * a );
	      ld ansVb2 = ( -b - d ) / ( 2.0 * a );
	      ld ansVa1 = ( p - mb * ansVb1 ) / ma;
	      ld ansVa2 = ( p - mb * ansVb2 ) / ma;
	      if( ! ( fabsl(ansVa1) < eps && fabsl(ansVb1) < eps) )
		{
		  if( ( ansVa1 >= 0 && ansVb1 <= 0 ) || 
		      ( ansVa1 <= 0 && ansVb1 <= 0 && ansVa1 > ansVb1) ||
		      ( ansVa1 >= 0 && ansVb1 >= 0 && ansVa1 > ansVb1 ) )
		    {
		      ansVa1 = ansVa2,  ansVb1 = ansVb2;
		    }
		}
	      va_ = ansVa1, vb_ = ansVb1;
	    }
	  assert( isfinite( va_ ) && isfinite( vb_ )) ;
	  ld tmp = mul(-vecABy, vecABx, vaX, vaY);
	  vaX = tmp * ( - vecABy ) + va_ * vecABx;
	  vaY = tmp * vecABx + va_ * vecABy;
	  tmp = mul(-vecABy, vecABx, vbX, vbY);
	  vbX = tmp * ( -vecABy) + vb_ * vecABx;
	  vbY = tmp * vecABx + vb_ * vecABy;
	}
    }
  paX += vaX * t, paY += vaY * t;
  pbX += vbX * t, pbY += vbY * t;
  // assert( isfinite(vaX) && isfinite(vaY) && isfinite(vbX) && isfinite(vbY) );
  printf("%.7lf %.7lf %.7lf %.7lf\n", (double)paX, (double)paY, 
	 (double)vaX, (double)vaY);
  printf("%.7lf %.7lf %.7lf %.7lf\n", (double)pbX, (double)pbY, 
	 (double)vbX, (double)vbY);
  return 0;
}
