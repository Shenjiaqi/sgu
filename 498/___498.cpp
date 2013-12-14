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
// #include <gmp.h>
// #include <gmpxx.h>
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
#define N 1002
#define M 51
const ld eps=1e-13;
const ll base=1e9;
typedef vector<int> bn;
const int prec=9;
const ll PRE=(ll)(1e9);
ll c[M][M];
ld dd[N][M];
int ee[N][M];
double cal(int n1,int m1,int n2,int m2)
{
  ld a=dd[n1][m1]*dd[n2][m2];
  a*=(n1+1)*(n2+1);
  int len=ee[n1][m1]+ee[n2][m2]+1;
  for(;a>=10-eps;a/=10)
    ++len;
  ll ans(0);
  FOR(k,0,m2+1)
    {
      ll sum(0);
      FOR(l,0,m1+1)
	{
	  ll b=(n2-m2+k+1)*(n1-m1+l+n2-m2+k+2);
	  ll r=1;
	  for(ll i=1,j=10;i<=len-1;i<<=1,j=(j*j)%b)
	    if(i&(len-1))
	      r=(r*j)%b;
	  r*=(((c[m2][k]%b)*(c[m1][l]%b))%b);
	  r%=b;
	  r=(r*PRE)/b;
	  // ll r=1e9/b;
	  // r*=cc[m2][k][cc[m2][k].size()-1];
	  if((l+k)&1)
	    ans+=(1-r),sum+=(1-r);
	  else ans+=r,sum+=r;
	  for(;ans<0;)
	    ans+=PRE;
	  ans%=PRE;
	}
      // cout <<k<<' '<<sum<<endl;
      // cout<<ans<<endl;
    }

  // FOR(l,0,m1+1)
  //   {
  //     FOR(k,0,m2+1)
  // 	{
  // 	  ll b=(n2-m2+k+1)*(n1-m1+l+n2-m2+k+2);
  // 	  ll r=1;
  // 	  for(ll i=1,j=10;i<len-1;i<<=1,j=(j*j)%b)
  // 	    if(i&(len-1))
  // 	      r=(r*j)%b;
  // 	  r*=(((c[m2][k]%b)*(c[m1][l]%b))%b);
  // 	  r%=b;
  // 	  r=(r*PRE)/b;
  // 	  if((l+k)&1)
  // 	    ans+=(1-r);
  // 	  else ans+=r;
  // 	  for(;ans<0;)
  // 	    ans+=PRE;
  // 	  ans%=PRE;
  // 	}
  //     cout<<ans<<endl;
  //   }
  // cout<<a<<' '<<ans<<endl;
  ans=(ans+PRE)%PRE;
  a*=ans;
  a/=1e9;
  return a;
}
int main()
{
  FOR(i,0,N)
    {
      dd[i][0]=1;
      ee[i][0]=0;
      for(int j=1;j<min(i+1,M);++j)
  	{
	  dd[i][j]=dd[i-1][j-1]*(ld)i/(ld)j;
	  ee[i][j]=ee[i-1][j-1];
	  if(dd[i][j]>=10-eps)
	    dd[i][j]/=10,++ee[i][j];
  	}
    }
  // FOR(i,1,N)
  //   {
  //     FOR(j,1,N)
  // 	{
  // 	  ff[i][j][0]=1;
  // 	  FOR(k,1,177)
  // 	    ff[i][j][k]=(ff[i][j][k-1]*10)%(i*(i+j));
  // 	}
  //   }
  FOR(i,0,M)
    {
      c[i][0]=1;
      FOR(j,1,min(i+1,M))
	{
	  c[i][j]=c[i-1][j-1]*i;
	  c[i][j]/=j;
	}
    }
  int T;
  scanf("%d",&T);
  for(;T--;)
    {
      int n1,m1,n2,m2;
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      printf("%.4f\n",(float)cal(n1,m1,n2,m2));
    }
  return 0;
}
