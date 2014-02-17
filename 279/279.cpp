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
int vis[N],visCnt;
int main()
{
  int n;
  scanf("%d", &n);
  vector<int> a;
  for( int i = 0; i < n; ++i )
    {
      int ai;
      scanf("%d", &ai);
      if( ai < 0 )
	{
	  printf("NO");
	  return 0;
	}
      a.push_back( ai );
    }
  list<int> ans;
  for( int i = n; i > 0 ; --i )
    {
      int ai = a[ i - 1 ];
      typeof( ans.begin() ) j = ans.begin();
      ++visCnt;
      for(; j != ans.end() && ai > 0 ; ++j )
	{
	  if( *j > i )
	    --ai;
	  else if( *j < 0 )
	    {
	      --ai;
	      *j = -i;
	    }
	  if( *j > 0 )
	    vis[ *j ] = visCnt;
	}
      for(; ai > 0 ; --ai)
	ans.insert( j, -i );
      ans.insert( j, i );
      for( j = ans.begin() ; j != ans.end() ; ++j )
	cout << *j << ' '; cout << endl;
    }
  list<int> neg;
  for( typeof( ans.begin() ) i = ans.begin() ; i != ans.end() ; 
       ++i)
    if( *i > 0 )
      neg.insert( neg.end(), *i );
  for( typeof( ans.begin() ) i = ans.begin() ; 
	 i != ans.end() ; ++i )
    if( *i < 0 )
      {
	bool ok = false;
	for(; !neg.empty() ;)
	  {
	    int val = - *neg.begin();
	    neg.erase( neg.begin() );
	    if( val > *i )
	      {
		*i = val ;
		ok = true;
		break;
	      }
	    else ans.insert( i, val );
	  }
	if( !ok )
	  {
	    printf("NO");
	    return 0;
	  }
      }
  for( ; !neg.empty() ; neg.erase( neg.begin() ) )
    ans.insert( ans.end(), - *neg.begin() );
  reverse( ans.begin(), ans.end() );
  printf("YES\n");
  for( typeof( ans.begin() ) i = ans.begin(); i != ans.end(); 
       ++i)
    printf("%d ", *i);
  return 0;
}
