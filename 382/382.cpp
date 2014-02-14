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
#include <gmp.h>
#include <gmpxx.h>
//g++ 382.cpp -lgmp -lgmpxx -I /usr/local/include/ -L/usr/local/lib
int main()
{
  mpz_class cc[51][51];
  for(int i = 0 ; i <= 50 ; ++i)
    {
      cc[i][0] = 1;
      for(int j = 1 ; j <= i ; ++j)
	cc[i][j] = ( cc[i-1][j-1] * i ) / j;
    }
  mpz_class ans[51][2];
  ans[0][0] = 1, ans[0][1] = 1;
  for( int i = 1; i <= 50 ; ++i)
    {
      ans[i][0] = 1, ans[i][1] = 1;
      for( int j = 0 ; j < i ; ++j )
	{
	  mpz_class tmp = ans[j][0];
	  for( int k = 0 ; k < i - j ; ++k )
	    tmp *= 2;
	  tmp *= cc[i][j];
	  ans[i][0] *= ans[j][1];
	  tmp *= ans[i][1];
	  if( j & 1 )
	    tmp = -tmp;
	  ans[i][0] += tmp;
	  ans[i][1] *= ans[j][1];
	  mpz_gcd(tmp.get_mpz_t(), ans[i][0].get_mpz_t(), ans[i][1].get_mpz_t() );
	  ans[i][0] /= tmp;
	  ans[i][1] /= tmp;
	}
      mpz_class tmp = 3;
      for( int j = 0 ; j < i ; ++j )
	tmp *= 2;
      tmp -= 1;
      if( i & 1 )
	tmp += 1;
      else tmp -= 1;
      ans[i][1] *= tmp;
      mpz_gcd(tmp.get_mpz_t(), ans[i][0].get_mpz_t(), ans[i][1].get_mpz_t() );
      ans[i][0] /= tmp;
      ans[i][1] /= tmp;
      cout<< '"' << ans[i][0] << '/' << ans[i][1] << '"' << ",\n";
    }
  return 0;
}
