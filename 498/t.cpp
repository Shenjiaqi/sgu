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

int main()
{
  FOR(i,0,n+1)
    {
      c[i][0].set_prec(1000);
      c[i][0]=1;
      FOR(j,1,min(i+1,m+1))
	{
	  c[i][j].set_prec(1000);
	  c[i][j]=c[i-1][j-1]*i;
	  c[i][j]/=j;
	}
    }

  // FOR(i,1,n*2+1)
  //   FOR(j,0,min(i+1,m+1))
  //   {
  //     mpf_class v(0,1000);
  //     FOR(k,0,min(j+1,m+1))
  // 	{
  // 	  mpf_class tmp(0,1000);
  // 	  tmp=c[j][k];
  // 	  tmp/=(i-j+k+1);
  // 	  if(k&1)
  // 	    v-=tmp;
  // 	  else v+=tmp;
  // 	}
  //     if(j==1 && i<10)
  // 	cout<<v<<endl;
  //     if(v<0 || v>=1)
  // 	cout<<v<<' '<<i<<' '<<j<<endl;
  //   }

  // FOR(i,2,2003)
  //   FOR(j,1,min(i+1,m+1))
  
  FOR(i,2,2003)
    FOR(j,0,min(i+1,51))
    {
      mpf_class a(0,1000);
      FOR(k,0,j+1)
  	{
  	  mpf_class v;
  	  v.set_prec(1000);
  	  v=c[j][k];
  	  v/=((i+k)*(i+k-1));
  	  if(k&1)
  	    a-=v;
  	  else a+=v;
  	}
      if(j==0)
	cout<<' '<<i<<' '<<j<<' '<<(a*1e12)<<endl;
    }

  return 0;
}
