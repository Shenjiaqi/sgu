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
#define N 10000
int p[N];
int main()
{
  int n,m,k;
  n=k=20;
  m=7;
  cout<<n<<' '<<m<<' '<<k<<endl;
  FOR(i,0,n)
    {
      p[i]=rand()%13;
      // if(i&1)
      // 	p[i]=-1;
      cout<<p[i]<<' ';
    }
  // vector<ll> q;
  // for(int i=0;i<(1<<n);++i)
  //   {
  //     if(__builtin_popcount(i)==m)
  // 	{
  // 	  ll t=1;
  // 	  for(int j=1,k=0;j<=i;j<<=1,++k)
  // 	    if(j&i)
  // 	      t*=p[k];
  // 	  q.PB(t);
  // 	}
  //   }
  // sort(q.begin(),q.end(),greater<ll>());
  // for(int i=0;i<q.size();++i)
  //   cout<<i<<' '<<q[i]<<endl;
  
  return 0;
}
