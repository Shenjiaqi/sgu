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
const int N = 2e5 + 7;
int n, m, k;
int weightSum[N];
int costSum[N];
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for( int i = 0 ; i < n ; ++i )
    {
      int weight, cost;
      scanf("%d%d", &weight, &cost);
      weightSum[i] = ( i > 0 ? weightSum[ i - 1 ] : 0 ) + weight;
      costSum[i] = cost + ( i > 0 ? costSum[i - 1] : 0 );
    }
  int ans = 0, lft = -1, rht = n, num = 0;
  for( int i = n ; i > m ; --i )
    {
      int lim = weightSum[ i - 1 ] - weightSum[ i - m - 1 ];
      if( k * weightSum[ i - m - 1 ] <  lim )
	break;
      int j = -1;
      for( int f = 0, t = i - m - 1; f <= t ; )
	{
	  int mid = ( f + t ) >> 1;
	  if( k * ( weightSum[ i - m - 1 ] - weightSum[mid] ) >= lim )
	    j = mid, f = mid + 1;
	  else t = mid - 1;
	}
      int cand = costSum[ n - 1 ] - costSum[ i - 1 ] + 
	( j >= 0 ? costSum[j] : 0 );
      if( ans < cand )
	{
	  ans = cand;
	  lft = j, rht = i;
	  num = j + 1 + n - i;
	}
    }
  printf("%d %d\n", num, ans);
  for( int i = n ; i > rht ; --i )
    printf("H");
  for( int i = 0 ; i <= lft ; ++i )
    printf("T");
  return 0;
}
