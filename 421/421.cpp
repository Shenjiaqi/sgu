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
#define N 10007
#define K 13
const ld inf=1e200;
int n,k,m;
int a[N];
map<pair<ld,int>,int> mapp[K][2];
int main()
{
  scanf("%d%d%d",&n,&k,&m);
  FOR(i,0,n)
    scanf("%d",a+i);
  FOR(i,0,n)
    if(a[i]>=0)
      {
	mapp[MP((ld)a[i],n-i)][0]=i;
	mapp[MP(-inf,n-i)][1]=i;
      }
    else
      {
	mapp[MP(-inf,n-i)][0]=i;
	mapp[MP((ld)-a[i],n-i)]=i;
      }
  typeof(mapp[0][0].begin()) ite;
  FOR(i,1,m)
    for(int j=i;j<n;++j)
    {
      ld amax=-inf,bmax=-inf;
      ite=mapp[i-1][0].upper_bound(MP(amax,n-j));
      if(ite!=mapp[i-1][0].end())
	amax=a[i]*ite->FIR.FIR;
      ite=mapp[i][0].upper_bound(MP(amax,n-(j-1)));
      if(ite!=mapp[i][0].end())
	amax=ite->FIR.FIR;
      ite=mapp[i-1][1].upper_bound(MP(bmax,n-j));
      if(ite!=mapp[i-1][1].end())
	bmax=ite->FIR.FIR*a[i];
      ite=mapp[i][1].upper_bound(MP(bmax,n-(j-1)));
      if(ite!=mapp[i][1].end())
	bmax=ite->FIR.FIR;
      mapp[i][a[i]>=0?0:1][MP(amax,n-i)]=i;
      mapp[i][a[i]>=0?1:0][MP(bmax,n-i)]=i;
    }
}
