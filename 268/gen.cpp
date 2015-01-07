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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
vector<ppi> p;
int main()
{
  int n=7;
  p.resize(n);
  srand(time(NULL));
  FOR(i,0,n)
    {
      p[i].FIR=rand();
      p[i].SEC=i;
    }
  sort(p.begin(),p.end());
  printf("%d\n",n);
  FOR(i,0,n)
    printf("%c",(char)(i+'A'));
  printf("\n");
  FR(i,p)
    printf("%c",(char)('A'+(i->SEC)));
  return 0;
}
