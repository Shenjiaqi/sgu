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
inline int cross(int x1, int y1, int x2, int y2)
{
  return x1 * y2 - y1 * x2;
}
void addBuilding(int v, int side, int x1, int y1)
{
  for( ; preCnt > 1 ; --preCnt )
    {
      int a = preBuilding[ preCnt - 1 ];
      int b = preBuilding[ preCnt - 2 ];
      int x2 = building[a][side], y2 = building[a][2];
      int x3 = building[b][side], y3 = building[b][2];
      int c = cross( x2 - x1, y2 - y1, x3 - x1, y3 - y1 ) ;
      if( ( side == 0 && c < 0 ) || ( side == 1 && c > 0 ) )
	break;
    }
  if( preCnt > 0 )
    {
      int a = preBuilding[ preCnt - 1 ];
      if( building[a][2] <= y1 )
	--preCnt;
    }
  preBuilding[preCnt] = v;
  ++preCnt;
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
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d%d%d", &building[i][0],
		&building[i][1], &building[i][2]);
	  light[i][0] = light[i][1] = 0;
	}
      qsort(building, n, sizeof(building[0]), cmp);
      int ans = 2;
      preCnt = 0;
      for( int i = 0 ; i < n - 1 ; ++i )
	{
	  addBuilding( i, 1 , building[i][1], building[i][2]);
	  addBuilding( i + 1, 1, building[ i + 1 ][0], 0 );
	  --preCnt;
	  if( preCnt > 0 )
	    {
	      int a = preBuilding[ preCnt - 1 ];
	      if( light[a][1] == 0 )
		{
		  ++ans;
		  if( building[a][2] <= building[ i + 1 ][2] )
		    light[ i + 1 ][0] = 1;
		  else
		    light[a][1] = 1;
		}
	    }
	  else
	    {
	      assert(0);
	      // ++ans;
	      // light[ i + 1 ][0] = 1;
	    }
	}
      preCnt = 0;
      for( int i = n - 1 ; i > 0 ; --i )
	if( light[ i - 1 ][1] == 0 )
	  {
	    addBuilding( i, 0, building[i][0], building[i][2] );
	    addBuilding( i - 1, 0, building[ i - 1 ][1], 0 );
	    --preCnt;
	    if( preCnt == 0 )
	      {
		assert(0);
		// ++ans;
		// light[ i - 1 ][1] = 1;
	      }
	    int a = preBuilding[ preCnt - 1 ];
	    if( light[a][0] == 0 )
	      {
		++ans;
		light[a][0] = 1;
	      }
	  }
      // for( int i = 0 ; i < n ; ++i )
      // 	{
      // 	  if( light[i][0] )
      // 	    cout << i << " 0" << endl;
      // 	  if( light[i][1] )
      // 	    cout << i << " 1" << endl;
      // 	}
      printf("%d\n", ans);
    }
  return 0;
}

