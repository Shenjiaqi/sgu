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
int main()
{
  int n;
  scanf("%d", &n);
  list< pair<int, int> > a;
  for( int i = 0 ; i < n ; ++i )
    {
      int ai;
      scanf("%d", &ai);
      if( ai < 0 )
	{
	  printf("NO");
	  return 0;
	}
      a.insert( a.end(), make_pair( i + 1, ai ) );
    }
  list<int> neg, ans;
  for(; !a.empty() ;)
    {
      typeof( a.begin() ) i = a.begin();
      for(; i != a.end() && i->second > 0 ; ++i)
	;
      if( i != a.end() )
	{
	  int num = i->first;
	  ans.insert( ans.begin(), num );
	  neg.insert( neg.end(), num );
	  a.erase(i);
	  for( i = a.begin() ; i != a.end() ; ++i )
	    if( i->first < num )
	      i->second -= 1;
	    // else break;
	}
      else
	{
	  if( neg.empty() )
	    {
	      printf("NO");
	      return 0;
	    }
	  int num = *neg.begin();
	  ans.insert( ans.begin(), - num );
	  neg.erase( neg.begin() );
	  for( i = a.begin(); i != a.end() ; ++i )
	    if( i->first > num )
	      i->second -= 1;
	}
    }
  for(; !neg.empty() ; neg.erase( neg.begin() ) )
    ans.insert( ans.begin(), -( *neg.begin() ) );
  printf("YES\n");
  for( typeof( ans.begin() ) i = ans.begin() ; 
       i != ans.end() ; ++i )
    printf("%d ", *i);
  return 0;
}
