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
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int det = m - n;
  bool ok = true;
  if( det >= 0 )
    {
      int c = det + 1;
      if( n < 3 * c - c + 1 )
	;
      else if( n > 10 * c - c + 1 + ( 10 * c - c + 1 - c + 1 ) )
	;
      else
	{
	  printf("%d\n", c);
	  int left = n;
	  int seq = 1;
	  queue<int> lst;
	  int num = min( 10, left - 2 * ( c - 1 ) );
	  printf("%d", num);
	  for( ; seq <= num; ++seq, --left)
	    printf(" %d", seq);
	  for( int i = 1; i < c; ++i )
	    {
	      printf("\n");
	      num = min( 10, left - (c - i - 1 ) * 2 + 1);
	      printf("%d %d", num, seq - 1);
	      lst.push( seq - 1 );
	      for( int j = 1; j < num; ++j, ++seq, --left)
		printf(" %d", seq);
	    }
	  printf("\n%d", left);
	  for( int i = 1; left > 0 ; ++i )
	    {
	      if( !lst.empty() && lst.front() == i )
		{
		  lst.pop();
		  ++i;
		}
	      --left;
	      printf("\n%d %d", i, seq);
	      ++seq;
	    }
	  return 0;
	}
    }
  printf("No solution");
  return 0;
}
