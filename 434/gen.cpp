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
  int n;
  n=21;
  cout<<n<<endl;
  int s(0);
  FOR(i,0,n)
    {
      int t=rand()%1000;
      s+=t;
      cout<<t<<' ';
    }
  cout<<endl;
  FOR(i,0,n-1)
    {
      int t=(rand()%s);
      cout<<t<<' ';
      s-=t;
    }
  cout<<s<<endl;
  return 0;
}

