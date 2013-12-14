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
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#include <gmp.h>
#include <gmpxx.h>
const int N=2007;
const int M=57;
const int prec=10000;
mpf_class c[N][M];
int main()
{
  FOR(i,0,N)
    {
      c[i][0].set_prec(prec);
      c[i][0]=1;
      FOR(j,1,min(M,i+1))
	{
	  c[i][j].set_prec(prec);
	  c[i][j]=c[i-1][j-1]*i;
	  c[i][j]/=j;
	}
    }

  int t,n1,m1,n2,m2;
  freopen("in","r",stdin);
  scanf("%d",&t);
  for(;t--;)
    {
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      mpf_class ans(0,prec);
      mpf_class tmp(0,prec);
      tmp=c[m2][0]/c[n2+n1-m2+0+1][m1];
      tmp*=c[n1][m1]*c[n2][m2]*((n1+1)*(n2+1));
      // cout<<tmp*c[n1][m1]*c[n2][m2]*((n1+1)*(n2+1))<<endl;
      tmp/=((n2-m2+0+1)*(n2-m2+0+1+n1+1));
      // mpf_class ta(0,prec);
      // cout<<tmp<<endl;
      mpf_class t(0,prec),rtmp(0,prec);
      rtmp=t=tmp;
      t/=1e70;
      // cout<<t<<endl;
      
      FOR(k,0,m2+1)
	{
	  // cout<<tmp<<endl;
	  mpf_class f(0,prec);
	  if(k)
	    {
	      f=1;
	      f*=(n2-m2+k);
	      f*=(m2-k+1);
	      f*=(n1+n2+k+1-m1-m2);
	      // cout<<(n2-m2+k)*(m2-k+1)*(n1+n2+k+1-m1-m2)<<' ';
	      // cout<<((n2-m2+k+1)*(n2-m2+k+2+n1)*k)<<endl;
	      f/=((n2-m2+k+1)*(n2-m2+k+2+n1));
	      f/=k;
	      tmp*=f;
	    }
	  // cout<<tmp<<endl;
	  // mpf_class t(0,prec);
	  // cout<<'!'<<c[m2+1][k+1]/c[n1+n2+k+2][m1+1]<<endl;
	  // t=c[m2][k]/c[n2+n1-m2+k+1][m1];
	  // t*=c[n1][m1]*c[n2][m2]*((n1+1)*(n2+1));
	  // cout<<tmp*c[n1][m1]*c[n2][m2]*((n1+1)*(n2+1))<<endl;
	  // t/=((n2-m2+k+1)*(n2-m2+k+1+n1+1));
	  // cout<<tmp<<' '<<t<<endl;
	  mpf_class tt(0,1000);
	  tt=tmp/rtmp;
	  // cout<<k<<' '<<tt<<endl;
	  mpz_class ttt;
	  ttt=tt;
	  // cout<<"!"<<(tt-ttt)<<endl;
	  tt=((n2-m2+1)*(n1+n2+1+1-m1-m2));
	  tt*=c[m2][k];
	  tt/=(n2-m2+k+1)*(n2-m2+k+2+n1);
	  // cout<<k<<' '<<tt<<' '<<tmp/rtmp<<' '<<f<<endl;
	  ttt=tt;
	  // cout<<(tt-ttt)<<' '<<(n2-m2+k+1)*(n2-m2+k+2+n1)<<endl;

	  if(k&1)
	    ans-=tmp// ,ta-=t
	      ;
	  else ans+=tmp// ,ta+=t;
	  ;
	}

      // cout.setf(ios::fixed);   
      cout.precision(4);
      cout<<ans<<endl;

      // FOR(k,0,m2)
      // 	{
      // 	  mpf_sum(0,prec);
      // 	  FOR(j,0,
      // 	}
    }
  // printf("%.4f\n",(float)ans);
  return 0;
}
