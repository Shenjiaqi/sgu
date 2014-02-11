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
int gcd(int a,int b)
{
  return b == 0 ? a : gcd( b , a % b );
}
int main()
{
  for(int n, i = 1; EOF != scanf("%d", &n) ; ++i)
    {
      printf("Case #%d: ", i);
      int a, b;
      if( n == 1 )
	a = 1, b = 1;
      else if( n % 4 == 0 )
	{
	  int x = n / 2;
	  a = x - 2;
	  b = x;
	}
      else if( n % 4 == 1 )
	{
	  int t = ( n + 1 ) / 2;
	  // a = ( n - 1 ) * ( t - 2 ) + t - 4;
	  // b = n * t;
	  a = t - 2;
	  b = t;
	}
      else if( n % 4 == 2 )
	{
	  a = n - 2;
	  b = n + 2;
	}
      else
	{
	  a = n - 3;
	  b = n + 1;
	}
      if( a == 0 )
	b = 1;
      a = -a;
      int d = gcd( abs(a), abs(b) );
      a /= d, b /= d;
      printf("%d/%d", a, b);
      printf("\n");
    }
  return 0;
}
