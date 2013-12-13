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
  v.set_prec(100000);
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
      mpf_class ans(0,100000);
      mpf_class aa(0);
      FOR(l,0,m1+1)
	{
	  mpf_class vt,vt2;
	  cc(vt,n1+1,m1-l);
	  cc(vt2,n1+l-m1,l);
	  vt*=vt2;
	  int lt=0;
	  for(;vt>=10-1e-7;vt/=10)
	    ++lt;
	  // cout<<lt<<' '<<vt<<endl;
	  mpf_class sum(0,100000);
	  FOR(k,0,m2+1)
	    {
	      mpf_class kt,t2,t3,t4,tmp;
	      cc(kt,n2+1,m2-k);
	      cc(t2,n2-m2+k,k);
	      kt*=t2;
	      int kl=lt;
	      for(;kt>=10-1e-7;kt/=10)
		++kl;
	      // cout<<kt<<' '<<kl<<' '<<vt<<endl;
	      int v1=n1-m1+l+1;
	      int v2=n2-m2+k+1;
	      v2+=v1;
	      mpf_class t(1,100000);
	      t=v1;
	      for(int i=0;i<kl;++i)
		t*=10;
	      t/=v2;
	      // for(ll i=1,j=10;i<=kl-1;i<<=1,j=(j*j)%v2)
	      // 	if(i&(kl-1))
	      // 	  tt=(tt*j)%v2;
	      // t=(int)tt;
	      // for(int i=0;i<min(kl,0);++i)
	      // 	t*=10;
	      // cout<<t<<endl;
	      kt*=t;
	      // cout<<"kt "<<kt<<' '<<sum<<endl;
	      if(k&1)
		sum-=kt;
	      else sum+=kt;
	      // cout<<sum<<endl;
	  // cc(t1,m2+1,k+1);
	  // cc(t2,m1+1,l+1);
	  // t1*=(k+1),t2*=(l+1);
	  // t1/=(n2-m2+1+k);
	  // t2/=(n1-m1+1+l+n2-m2+1+k);
	  // tmp.set_prec(1000);
	  // tmp=t1*t2;

	  // cc(t3,n2+1,m2+1);
	  // cc(t4,n1+1,m1+1);
	  // tmp*=t3,tmp*=t4;

	  // cc(t1,n2+1,m2+1);
	  // cc(t2,m2+1,k+1);
	  // cc(t3,n1+1,m1+1);
	  // cc(t4,m1+1,l+1);
	  // tmp.set_prec(1000);
	  // tmp=(l+1);
	  // tmp/=(n1+1-m1+l+n2+k-m2+1);
	  // tmp*=(k+1);
	  // tmp/=(n2+1-m2+k);
	  // tmp*=(t1*t2*t3*t4);

	  // cc(t1,n2+1,m2-k);
	  // cc(t2,n2+1-m2+k,k+1);
	  // cc(t3,n1+1,m1-l);
	  // cc(t4,n1+1-m1+l,l+1);
	  // tmp.set_prec(1000);
	  // tmp=(l+1);
	  // tmp/=(n1+1-m1+l+n2+k-m2+1);
	  // tmp*=(k+1);
	  // tmp/=(n2+1-m2+k);
	  // // tmp*=(t1*t2*t3*t4);

	  // cc(t1,n2+1,m2-k);
	  // // cout<<t1<<endl;
	  // cc(t2,n2-m2+k,k);
	  // cc(t3,n1+1,m1-l);
	  // cc(t4,n1-m1+l,l);
	  // // if(l==3 && k==5)
	  // //   cout<<t1*t2*t3*t4<<endl;
	  // tmp.set_prec(1000);
	  // tmp=(n1+1-m1+l);
	  // tmp/=(n1+1-m1+l+n2+k-m2+1);
	  // // cout<<tmp<<endl;
	  // tmp*=(t1*t2*t3*t4);
	  // mpz_class tt;
	  // tt=tmp;
	  // mpf_class ttt(0,100000);
	  // tt/=10;
	  // tt*=10;
	  // ttt=tt;
	  // // cc(t1,n2+1,m2-k);
	  // ttt=tmp-ttt;
	  // if(ttt>10-1e-4 )
	  //   ttt=0;
	  // // cout<<l<<' '<<k<<' '<<ttt<<endl;
	  // // cout<<(tmp*1e6-tt)<<endl;

	  // // cc(t2,n2-m2+k,k);
	  // // cc(t3,n1+1,n1-l);
	  // // cc(t4,n1-m1+l,l);
	  // // tmp.set_prec(1000);
	  // // tmp=n1+1-m1+l;
	  // // tmp/=(n1+1-m1+l+n2+k-m2+1);
	  // // tmp*=(t1*t2*t3*t4);
	  // // cout<<tmp<<endl;
	  // if((l+k)&1)
	  //   {
	  //     ans-=tmp,aa-=(ttt);
	  //     if(aa<0)
	  // 	aa+=10;
	  //   }
	  // else
	  //   {
	  //     ans+=tmp,aa+=(ttt);
	  //     if(aa>10)
	  // 	aa-=10;
	  //   }
	    }
	  cout<<sum<<endl;
      // mpf_class t1,t2;
      // cc(t1,n1,m1);
      // cc(t2,n2,m2);
      // t1*=(n1+1);
      // t2*=(n2+1);
      // cout<<(t1*t2*ans)<<endl;
      // cout<<((n1+1)*(n2+1)*ans)<<endl;
	  sum*=vt;
	  if(l&1)
	    ans-=sum;
	  else ans+=sum;
	}

      cout<<ans<<' '<<aa<<endl;
    }
  return 0;
}
