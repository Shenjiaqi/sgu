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
int p[N];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  stack<int> ans;
  for( int i = 0 ; i < m ; ++i )
    {
      int pos;
      scanf("%d", &pos);
      ++p[pos];
      ans.push( pos );
      if( p[pos] == 1 )
	{
	  int j = pos + 1;
	  for( ; j < n ; ++j )
	    if( p[j] == 2 )
	      {
		p[ j ] = 0;
		ans.push(j);
		++p[ j + 1 ];
		ans.push( j + 1 );
		break;
	      }
	}
      else if( p[pos] == 2 )
	{
	  p[pos] = 0;
	  ++p[ pos + 1 ];
	  ans.push( pos + 1 );
	  for( int j = pos + 1; j < n; ++j )
	    if( p[j] == 2 )
	      {
		p[j] = 0;
		if( j != pos + 1 )
		  ans.push( j ) ;
		++p[ j + 1 ];
		ans.push( j + 1 );
		break;
	      }
	}
      else
	{
	  p[pos] = 1;
	  ++p[pos + 1];
	  ans.push( pos + 1 );
	  for( int j = pos + 1; j < n; ++j )
	    if( p[j] == 2 )
	      {
		p[j] = 0;
		if( j != pos + 1 )
		  ans.push( j );
		++p[ j + 1 ];
		ans.push( j + 1 );
		break;
	      }
	}
      if( ans.size() <= 2 )
      	for( int j = pos - 2 ; j >=0 ; --j )
      	  if( p[j] == 2 )
      	    {
      	      p[ j ] = 0;
      	      ans.push( j );
      	      ++p[ j + 1 ];
      	      ans.push( j + 1 );
      	      break;
      	    }
      printf("%d", (int)ans.size() );
      for( ; !ans.empty(); ans.pop() )
	{
	  printf(" %d %d", ans.top(), p[ ans.top() ] );
	  assert( p[ ans.top() ] < 3 );
	}
      // assert( ans.size() < 4 );
      printf("\n");
    }
  return 0;
}
