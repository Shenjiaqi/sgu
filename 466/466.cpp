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
const int N = 1e5 + 7;
const int Q = 1e5 + 7;
char s[N];
int bw[N], ew[N];
vector<ppi> que[Q];
int rng( const ppi &t )
{
  return t.second - t.first + 1;
}
struct cmp
{
  bool operator()( const ppi &p1, const ppi &p2 ) const
  {
    int r1 = rng(p1), r2 = rng(p2);
    if( r1 == r2 )
      return p1.first < p2.first;
    return r1 < r2;
  }
};
set<ppi,cmp> st;
void add( const ppi & a )
{
  assert( bw[a.first] == 0 && 0 == ew[a.second] );
  bw[a.first] = a.second;
  ew[a.second] = a.first;
  st.insert(a);
}
void del( const ppi & a )
{
  assert( bw[a.first] == a.second &&
	  ew[a.second] == a.first );
  bw[a.first] = 0;
  ew[a.second] = 0;
  assert( st.find( a ) != st.end() );
  st.erase(a);
}
void pt( int seq, int f, int t )
{
  if( f > t )
    cout << "#" << f << ' ' << t << endl;
  assert( f <= t );
  que[seq].push_back( ppi( f, t ) );
  printf("%d", f );
  if( t != f )
    printf("-%d", t);
}
int main()
{
  int n, q;
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  for( int i = 0; s[i]; )
    if( s[i] == '.' )
      {
	ppi tmp;
	tmp.first = i + 1;
	for( ; s[i] && s[i] == '.'; ++i )
	  ;
	tmp.second = i;
	add( tmp );
      }
    else
      {
	assert( s[i] == 'X' );
	++i;
      }
  for( int i = 0; i < q; ++i )
    {
      int num;
      scanf("%s%d", s, &num);
      if( s[0] == 'P' )
	{
	  ppi tmp;
	  tmp.first = 1, tmp.second = num;
	  typeof( st.begin() ) c1;
	  if( bw[1] > 0 && bw[1] != n && ew[n] > 0 )
	    {
	      ppi tt1, tt2;
	      tt1.first = 1, tt1.second = bw[1];
	      del( tt1 );
	      tt2.first = ew[n], tt2.second = n;
	      del( tt2 );
	      c1 = st.lower_bound(tmp);
	      add(tt1);
	      add(tt2);
	    }
	  else
	    {
	      c1 = st.lower_bound(tmp);
	    }
	  if( ew[n] > 0 && ew[n] != 1 &&
	      bw[1] > 0 &&
	      bw[1] + n - ew[n] + 1 >= num &&
	      ( c1 == st.end() ||
		bw[1] + n - ew[n] + 1 < rng( *c1 ) ) )
	    {
	      // if( c1 != st.end() && rng( *c1 ) ==
	      // 	  bw[1] + n - ew[n] + 1 )
	      // 	assert(0);
	      ppi t1, t2;
	      t1.first = ew[n];
	      t1.second = n;
	      del(t1);
	      if( num <= rng( t1 ) )
		{
		  pt( i + 1, t1.first, t1.first + num - 1 );
		  if( num < rng( t1 ) )
		    {
		      t1.first += num;
		      add(t1);
		    }
		}
	      else
		{
		  t2.first = 1;
		  t2.second = bw[1];
		  del(t2);
		  int num2 = num - rng(t1);
		  pt( i + 1, 1, num2 );
		  printf(",");
		  pt( i + 1, t1.first, t1.second);
		  if( num2 < rng( t2 ) )
		    {
		      t2.first = num2 + 1;
		      add(t2);
		    }
		}
	    }
	  else if( c1 != st.end() )
	    {
	      ppi t = *c1;
	      del(t);
	      pt( i + 1, t.first, t.first + num - 1 );
	      if( num < rng( t ) )
		{
		  t.first += num;
		  add(t);
		}
	    }
	  else 
	    printf("NO ROOM");
	  printf("\n");
	}
      else
	{
	  for(; !que[num].empty(); que[num].pop_back() )
	    {
	      ppi tmp = que[num][que[num].size() - 1];
	      int f = tmp.first, t = tmp.second;
	      if( f > 1 && ew[ f - 1 ] > 0 )
		{
		  ppi tt;
		  tt.first = ew[ f - 1 ], tt.second = f - 1;
		  del( tt );
		  f = tt.first;
		}
	      if( t != n && bw[ t + 1] > 0 )
		{
		  ppi tt;
		  tt.first = t + 1, tt.second = bw[ t + 1 ];
		  del( tt );
		  t = tt.second;
		}
	      tmp.first = f, tmp.second = t;
	      add(tmp);
	    }
	}
      // for( typeof( st.begin() ) j = st.begin();
      // 	   j != st.end(); ++j )
      // 	cout << j->first << ' ' << j->second << endl;
    }
  return 0;
}
