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
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int main()
{
  for(int i=0;i<(1<<10);++i)
    if(__builtin_popcount(i)==5)
      {
	vector<int> t;
	int s=0;
	for(int k=0,j=1;j<=i;j<<=1,++k)
	  if(i&j)
	    t.push_back(k),s+=k;
	if(
  return 0;
}
