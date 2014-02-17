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
  int n = 11;
  cout << n << endl;
  vector<pair<int, int> > tmp;
  srand(13);
  for(int i = 0; i < n; ++i)
    {
      tmp.push_back(make_pair(rand(), i + 1));
    }
  sort(tmp.begin(), tmp.end());
  vector<int> a;
  for(int i = 0, j = 0; j < n;)
    {
      if(i < n)
	{
	  if( (rand()&1) == 1 || i <= j)
	    {
	      a.push_back(tmp[i].second);
	      ++i;
	    }
	  else
	    {
	      a.push_back(-tmp[j].second);
	      ++j;
	    }
	}
      else
	{
	  a.push_back(-tmp[j].second);
	  ++j;
	}
    }
  reverse(a.begin(), a.end());
  vector<int> ai;
  ai.resize(n);
  for(int i = 0; i < a.size(); ++i)
    {
      int v = a[i];
      if( v > 0 )
	{
	  int cnt(0);
	  for(int j = i + 1; j < a.size(); ++j)
	    {
	      int tmp = a[j];
	      if((tmp < 0 && -tmp < v) || tmp > v)
		++cnt;
	    }
	  ai[v - 1] = cnt;
	}
    }
  for(int i = 0; i < ai.size(); ++i)
    cout << ai[i] << ' ';
  cout << endl;
  for(int i = 0; i < a.size(); ++i)
    cout << a[i] << ' ';
  cout << endl;
  return 0;
}
