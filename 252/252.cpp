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
const int N = 107;
const int M = 1007;
const int NN = N * 4 + 7;
const int MM = M * 2 + ( N * 6 + 7 ) * 2 + 7;
int n, m;
int rRail[MM][4];
int rail[MM][4], railI;
int sRail[NN];
bool in[NN];
int from[NN];
int dis[NN];
int to[NN];
int S, T, SS, TT;
void add( int from, int to, int cap, int c)
{
  ++railI;
  rail[railI][0] = to, rail[railI][1] = cap, rail[railI][2] = c, 
    rail[railI][3] = sRail[from], sRail[from] = railI;
  ++railI;
  rail[railI][0] = from, rail[railI][1] = 0, rail[railI][2] = -c,
    rail[railI][3] = sRail[to], sRail[to] = railI;
}
int mf()
{
  memcpy( rail, rRail, sizeof(rail) );
  int cnt(0);
  for(;;++cnt)
    {
      memset( dis, 1 << 6, sizeof(dis) );
      int inf = dis[SS];
      queue<int> que;
      dis[SS] = 0;
      in[SS] = true;
      que.push(SS);
      for(; !que.empty(); )
	{
	  int v = que.front();
	  in[v] =false;
	  que.pop();
	  for( int i = sRail[v]; i; i = rail[i][3])
	    {
	      int t = rail[i][0];
	      int capacity = rail[i][1];
	      int cost = rail[i][2];
	      if( capacity > 0 && dis[t] > dis[v] + cost )
		{
		  dis[t] = dis[v] + cost;
		  from[t] = v;
		  to[t] = i;
		  if( !in[t] )
		    {
		      in[t] = true;
		      que.push(t);
		    }
		}
	    }
	}
      if( dis[TT] < inf )
	{
	  for( int i = from[TT]; i ; i = from[i] )
	    {
	      int idx = to[i];
	      --rail[idx][1];
	      if(idx & 1)
		++idx;
	      else --idx;
	      ++rail[idx][1];
	    }
	}
      else break;
    }
  return cnt;
}
int vS( int v )
{
  return v << 2;
}
int vT( int v )
{
  return vS(v) +1;
}
int vSS(int v)
{
  return vT(v) + 1;
}
int vTT(int v)
{
  return vSS(v) + 1;
}
int main()
{
  scanf("%d%d", &n, &m);
  S = vTT(n) + 1, T = S + 1, SS = T + 1, TT = SS + 1;
  for( int i = 0 ; i < m ; ++i )
    {
      int f, t, c;
      scanf("%d%d%d", &f, &t, &c);
      add( vS(f), vT(t), 1, c);
    }
  add( T, S, 0, 0 );
  int modIdx = railI;
  for( int i = 1; i <= n ; ++i )
    {
      add( S, vSS(i), 1, 0 );
      add( vSS(i), TT, 1, 0);
      add( vT(i), vSS(i), 1, 0);
      add( vTT(i), vS(i), 1, 0);
      add( vTT(i), T, 1, 0);
      add( SS, vTT(i), 1, 0);
    }
  int ansVal = n;
  memcpy( rRail, rail, sizeof( rRail ) );
  for( int f = 1, t = n; f <= t; )
    {
      int mid = (f + t) >> 1;
      rRail[modIdx - 1][1] = mid;
      if( mf() == n )
	ansVal = mid, t = mid - 1;
      else f = mid + 1;
    }
  rRail[modIdx - 1][1] = ansVal;
  memset( from, 0, sizeof(from) );
  memset( to, 0, sizeof(to) );
  int costSum(0);
  for( int i = 1 ; i <= n ; ++i )
    {
      int fV = vS(i);
      for( int j = sRail[fV]; j; j = rail[j][3] )
	{
	  int tV = rail[j][0];
	  if( tV % 4 == 1 && tV / 4 <= n && rail[j][1] == 0 && rRail[j][1] == 1)
	    {
	      // tV == vS( some point )
	      from[tV / 4] = i;
	      to[i] = tV / 4;
	      costSum += rRail[j][2];
	    }
	}
    }
  vector<queue<int> > ans;
  for( int i = 1; i <= n ; ++i )
    if( from[i] == 0 )
      {
	ans.resize( ans.size() + 1 );
	for( int j = i; j; j = to[j] )
	  ans[ans.size() - 1].push(j);
      }
  printf("%d %d\n", (int)ans.size(), costSum);
  for( int i = 0 ; i < ans.size() ; ++i )
    {
      printf("%d", (int)ans[i].size());
      for( ; !ans[i].empty(); ans[i].pop() )
	printf(" %d", ans[i].front() );
      printf("\n");
    }
  return 0;
}
