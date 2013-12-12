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
#include <gmp.h>
#include <gmpxx.h>
const int n=2000;
const int m=50;
mpf_class c[n+1][m+1];
void cc(mpf_class &v,int a,int b)
{
  v.set_prec(1000000);
  v=1;
  for(int i=0;i<b;++i)
    {
      v*=(a-i);
      v/=(b-i);
    }
}
int main()
{
  int T;
  scanf("%d",&T);
  for(;T--;)
    {
      int n1,m1,n2,m2;
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      mpf_class ans(0,1000000);
      FOR(k,0,m2+1)
	FOR(l,0,m1+1)
	{
	  mpf_class t1,t2,t3,t4,tmp;

	  // cc(t1,m2+1,k+1);
	  // cc(t2,m1+1,l+1);
	  // t1*=(k+1),t2*=(l+1);
	  // t1/=(n2-m2+1+k);
	  // t2/=(n1-m1+1+l+n2-m2+1+k);
	  // tmp.set_prec(1000000);
	  // tmp=t1*t2;

	  // cc(t3,n2+1,m2+1);
	  // cc(t4,n1+1,m1+1);
	  // tmp*=t3,tmp*=t4;

	  cc(t1,n2+1,m2+1);
	  cc(t2,m2+1,k+1);
	  cc(t3,n1+1,m1+1);
	  cc(t4,m1+1,l+1);
	  tmp.set_prec(1000000);
	  tmp=(l+1);
	  tmp/=(n1+1-m1+l+n2+k-m2+1);
	  tmp*=(k+1);
	  tmp/=(n2+1-m2+k);
	  tmp*=(t1*t2*t3*t4);

	  // cc(t1,n2+1,m2-k);
	  // cc(t2,n2-m2+k,k);
	  // cc(t3,m1+1,m1-l);
	  // cc(t4,n1-m1+l,l);
	  // tmp.set_prec(1000000);
	  // tmp=n1+1-m1+l;
	  // tmp/=(n1+1-m1+l+n2+k-m2+1);
	  // tmp*=(t1*t2*t3*t4);
	  if((l+k)&1)
	    ans-=tmp;
	  else ans+=tmp;
	}
      cout<<ans<<endl;;
      // mpf_class t1,t2;
      // cc(t1,n1,m1);
      // cc(t2,n2,m2);
      // t1*=(n1+1);
      // t2*=(n2+1);
      // cout<<(t1*t2*ans)<<endl;
      // cout<<((n1+1)*(n2+1)*ans)<<endl;
    }
  return 0;
}
