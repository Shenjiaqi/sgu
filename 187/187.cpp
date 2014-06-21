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
const int M = 2000 + 7;
const int N = 130000 + 7;
int p[M * 3][3], poi;
int split( int v, int num )
{
  assert( num > 0 && num < abs( p[v][0] - p[v][1] ) + 1 );
  ++poi;
  p[poi][1] = p[v][1];
  p[poi][2] = p[v][2];
  p[v][2] = poi;
  if( p[v][0] < p[v][1] )
    p[v][1] = p[v][0] + num - 1, p[poi][0] = p[v][1] + 1;
  else p[v][1] = p[v][0] - num + 1, p[poi][0] = p[v][1] - 1;
  return poi;
}
ppi dfs( int f, int t, int v, int pre, int preNum )
{
  // if( f == 1 && t == 5 )
  //   cout << "!" << f << ' ' << t << ' ' << v << ' ' << preNum << endl;
  if( v == 0 )
    {
      ppi tmp;
      tmp.first = tmp.second = 0;
      return tmp;
    }
  int firstNum = preNum + 1;
  int lastNum = preNum + abs( p[v][0] - p[v][1] ) + 1;
  if( lastNum < f )
    {
      ppi tmp = dfs( f, t, p[v][2], v, lastNum );
      p[v][2] = tmp.second;
      tmp.second = v;
      return tmp;
    }
  else if( firstNum > t )
    {
      ppi tmp;
      tmp.first = v;
      tmp.second = 0;
      return tmp;
    }
  else if( lastNum <= t && firstNum >= f )
    {
      ppi tmp = dfs( f, t, p[v][2], v, lastNum );
      if( firstNum == f )
	p[v][2] = tmp.first;
      else p[v][2] = pre;
      if( lastNum == t )
	{
	  tmp.second = v;
	}
      swap( p[v][0], p[v][1] );
      return tmp;
    }
  else if( f > firstNum )
    split( v, f - firstNum );
  else 
    split( v, t + 1 - firstNum );
  return dfs( f, t, v, pre, preNum );
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m );
  int s = 1;
  p[1][0] = 1, p[1][1] = n;
  p[1][2] = 0;
  poi = 1;
  for( int i = 0; i < m; ++i )
    {
      int f, t;
      scanf("%d%d", &f, &t);
      ppi tmp = dfs( f, t, s, 0, 0 );
      s = tmp.second;
      // cout << endl;
    }
  // return 0;
  for( int i = s; i; i = p[i][2] )
    // {
    //   cout << p[i][0] << ' ' << p[i][1] << endl;
    // }
    for( int j = p[i][0], k = 0 ; k < abs( p[i][0] - p[i][1] ) + 1; ++k)
      {
    	printf("%d ", j);
    	if( p[i][0] < p[i][1] )
    	  ++j;
    	else --j;
      }
  return 0;
}
