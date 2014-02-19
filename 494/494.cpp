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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 10007;
const int W = 1007;
int len[N];
int dp[W][W][2];
int main()
{
  int t;
  scanf("%d", &t);
  for(;t--;)
    {
      int n, w, r, c;
      scanf("%d%d%d%d", &n, &w, &r, &c);
      for( int i = 0 ; i < n ; ++i )
	scanf("%d", len + i );
      dp[0][n] = 1;
      addIllus( 0, 0, 0 );
      for( int i = 0 ; i < n ; ++i )
	{
	  for( int j = 0 ; j < w - len[i] ; ++j )
	    {
	      if( dp[i][j][0] == i + 1 )
		{
		  dp[i][j][0] = 0;
		  
		}
	    }
	}
    }
}
