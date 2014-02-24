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
int cross( int x1, int y1, int x2, int y2 )
{
  return x1 * y2 - y1 * x2;
}
int mul( int x1, int y1, int x2, int y2 )
{
  return x1 * x2 + y1 * y2;
}
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  vector< pair<int, int> > cake;
  for( int i = 0 ; i < n ; ++i )
    {
      int posCor[4][2];
      int posCan[2][2];
      int xSum = 0, ySum = 0;
      for( int j = 0 ; j < 4 ; ++j )
	{
	  scanf("%d%d", &posCor[j][0], &posCor[j][1]);
	  xSum += posCor[j][0], ySum += posCor[j][1];
	}
      for( int j = 0 ; j < 2 ; ++j )
	scanf("%d%d", &posCan[j][0], &posCan[j][1]);
      xSum /= 2, ySum /= 2;
      int canCut = ( ( cross( posCan[0][0] * 2 - xSum, 
			      posCan[0][1] * 2 - ySum,
			      posCan[1][0] * 2 - xSum,
			      posCan[1][1] * 2 - ySum) != 0 ) ||
		     mul( posCan[0][0] * 2 - xSum, posCan[0][1] * 2- ySum,
			  posCan[1][0] * 2 - xSum, posCan[1][1] * 2- ySum ) < 0 ) 
	? 1 : 0;
      cake.push_back( make_pair( abs( cross( posCor[1][0] - posCor[0][0],
					     posCor[1][1] - posCor[0][1],
					     posCor[2][0] - posCor[0][0],
					     posCor[2][1] - posCor[0][1]) ),
				 canCut ) );
    }
  sort( cake.begin(), cake.end(), greater< typeof( cake[0] ) >() );
  int maxArea = 0;
  for( int i = 0 ; i < k ; ++i )
    if( cake[i].second > 0 )
      maxArea += cake[i].first;
  int minArea = 0;
  int i = 0;
  for( ; cake[i].first != cake[ k - 1 ].first ; ++i )
    if( cake[i].second > 0 )
      minArea += cake[i].first;
  int j = k;
  for( ; j < cake.size() && cake[j].first == cake[ k - 1 ].first ; ++j )
    ;
  for( --j ; i < k ; ++i, --j )
    if( cake[j].second > 0 )
      minArea += cake[j].first;
  printf("%f %f", minArea / 2.0, maxArea / 2.0);
  // for( auto i : cake )
  //   cout << i.first << ' ' << i.second << endl;
  return 0;
}
