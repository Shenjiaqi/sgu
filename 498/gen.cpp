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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)

int main()
{
  int n=10000;
  cout<<n<<endl;

  for(int i=0;i<n;++i)
    //cout<<"1000 50 1000 50\n";
    {
      // int a=rand()%1000,b=rand()%1000;
      // ++a,++b;
      // int c=min(50,rand()%a);
      // int d=min(50,rand()%b);
      int a=1000,c=50;
      int b=1000;
      cout<<a<<' '<<c<<' '<<b<<' '<<c<<endl;
    }

  return 0;
}
