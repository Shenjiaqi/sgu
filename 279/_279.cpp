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
int vis[N], visCnt;
int main()
{
  int n;
  scanf("%d", &n);
  set < pair< int, int > > a;
  for( int i = 0 ; i < n ; ++i )
    {
      int ai;
      scanf("%d", &ai);
      if( ai < 0 )
	{
	  printf("NO");
	  return 0;
	}
      a.insert( make_pair( ai, i + 1 ) );
    }
  list <int> ans, neg;
  for(; !a.empty() ; a.erase( a.begin() ) )
    {
      int ai = a.begin()->first;
      int i = a.begin()->second;
      typeof( ans.begin() ) j = ans.begin();
      ++visCnt;
      for(; ai > 0 && j != ans.end() ; ++j )
	{
	  if( *j > 0 )
	    {
	      vis[ *j ] = visCnt;
	      if( *j > i )
		--ai;
	    }
	  else if( *j < 0 )
	    {
	      if( abs( *j ) < i )
		--ai;
	    }
	}
      for(; ai > 0 && !neg.empty(); neg.erase( neg.begin() ) )
	{
	  int val = *neg.begin();
	  if( val < i )
	    --ai;
	  ans.insert( j, -val );
	}
      if( ai > 0 )
	{
	  printf("NO");
	  return 0;
	}
      for(; j != ans.end(); ++j)
	{
	  if( *j < 0 )
	    {
	      if( abs( *j ) < i )
		{
		  for( typeof(j) k = j; k != ans.end() ; ++k)
		    {
		      if( *k > 0 && *k < i )
			{
			  printf("NO");
			  return 0;
			}
		    }
		  break;
		}
	    }
	  else
	    {
	      if( *j > i )
		{
		  for( typeof(j) k = j; k != ans.end(); ++k)
		    if( *k > 0 && *k < i )
		      {
			printf("NO");
			return 0;
		      }
		  break;
		}
	      vis[ *j ] = visCnt;
	    }
	}
      ans.insert( j, i );
      typeof( neg.begin() ) k = neg.begin();
      for(; k != neg.end(); ++k )
	if( vis[ *k ] != visCnt )
	  break;
      neg.insert( k, i );
      // for( typeof( ans.begin() ) i = ans.begin(); 
      // 	   i != ans.end(); ++i )
      // 	cout << *i << ' '; cout << endl;
      // for( typeof( neg.begin() ) i = neg.begin(); 
      // 	   i != neg.end(); ++i )
      // 	cout << *i << ' '; cout << endl << endl;
    }
  for(; !neg.empty(); neg.erase( neg.begin() ) )
    ans.insert( ans.end(), - *neg.begin() );
  reverse( ans.begin(), ans.end() );
  printf("YES\n");
  for( typeof( ans.begin() ) i = ans.begin();
       i != ans.end(); ++i )
    printf("%d ", *i);
  return 0;
}
