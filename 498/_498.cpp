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
#define N 1001
#define M 51
const ll base=1e9;
typedef vector<int> bn;
const int prec=9;
const ll PRE=(ll)(1e9);
bn cc[N][M];
ll c[M][M];
void mul(bn &t, bn &f, int v)
{
  t.resize(0);
  for(int i=0;i<f.size();++i)
    {
      if(t.size()<=i)
	t.resize(i+1);
      ll ca=t[i];
      ca+=(ll)f[i]*(ll)v;
      t[i]=ca%base;
      ca/=base;
      if(ca>0)
	{
	  if(t.size()<=i+1)
	    t.resize(i+2);
	  t[i+1]+=ca;
	}
    }
}
void mul(bn &t,int v)
{
  ll c=0;
  for(int i=0,j=t.size();i<j;++i)
    {
      c+=(ll)t[i]*(ll)v;
      t[i]=c%base;
      c/=base;
    }
  if(c)
    t.PB(c);
}
void mul(bn &t, const bn &a,const bn &b)
{
  t.resize(0);
  FOR(i,0,a.size())
    FOR(j,0,b.size())
    {
      if(t.size()<=i+j)
	t.resize(i+j+1);
      ll v=t[i+j];
      v+=(ll)a[i]*(ll)b[j];
      t[i+j]=v%base;
      v/=base;
      if(v>0)
	{
	  if(t.size()<=i+j+1)
	    t.resize(i+j+2);
	  t[i+j+1]+=v;
	}
    }
}
void div(bn &a,int b)
{
  ll re=0;
  for(int i=a.size()-1;i>=0;--i)
    {
      re=re*base+a[i];
      a[i]=re/b;
      re%=b;
    }
  for(;a.size() && a[a.size()-1]==0;)
     a.resize(a.size()-1);
  assert(re==0);
}
int calLen(bn&a)
{
  int i=a.size()-1;
  int r=i*9;
  for(int j=a[i];j;j/=10)
    ++r;
  return r;
}
void pt(bn&a)
{
  if(a.size())
    {
      int i=a.size()-1;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%09d",a[i]);
    }
  else printf("0");
  printf("\n");
}
void prt(bn&v,int l)
{
  int i=(l-1)/9;
  double v1=v[i];
  for(int j=(l-1)%9;j;--j)
    v1/=10;
  if(v.size()>i+1)
    {
      double c=v[i+1];
      for(int j=9-((l-1)%9);j;--j)
	c*=10;

      v1+=c;
    }
  v1/=PRE;
  printf("%.5lf\n",v1);
}
void cal(int n1,int m1,int n2,int m2)
{
  bn a;
  int len(0);
  mul(a,cc[n1][m1],cc[n2][m2]);
  mul(a,(n1+1)*(n2+1));
  
  len=calLen(a);
  ll ans(0);
  // ld kk=0;
  // FOR(k,0,m2+1)
  //   {
  //     ld tmp=(ld)c[m2][k]/(ld)(n1-m1+0+1+n2-m2+k+1);
  //     if(k&1)
  // 	kk+=1e-13-tmp;
  //     else kk+=tmp;
  //   }
  // cout<<kk<<endl;
  FOR(l,0,m1+1)
    {
      FOR(k,0,m2+1)
	{
	  ll b=(n2-m2+k+1)*(n1-m1+l+n2-m2+k+2);
	  ll r=1;
	  for(ll i=1,j=10;i<=len-1;i<<=1,j=(j*j)%b)
	    if(i&(len-1))
	      r=(r*j)%b;
	  r*=(((c[m2][k]%b)*(c[m1][l]%b))%b);
	  r%=b;
	  r=(r*PRE)/b;
	  if((l+k)&1)
	    ans+=(1-r);
	  else ans+=r;
	  for(;ans<0;)
	    ans+=PRE;
	  ans%=PRE;
	}
    }
  ans=(ans+PRE)%PRE;
  cout<<ans<<endl;
  cout<<"!"<<endl;
  pt(a);
  mul(a,ans);
  prt(a,len);
}
int main()
{
  FOR(i,0,N)
    {
      cc[i][0].PB(1);
      for(int j=1;j<min(i+1,M);++j)
  	{
  	  mul(cc[i][j],cc[i-1][j-1],i);
  	  div(cc[i][j],j);
  	}
    }
  FOR(i,0,M)
    FOR(j,0,min(i+1,M))
    {
      c[i][j]=cc[i][j][0];
      if(cc[i][j].size()>1)
	c[i][j]+=(ll)base*cc[i][j][1];
    }
  int T;
  scanf("%d",&T);
  for(;T--;)
    {
      int n1,m1,n2,m2;
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      cal(n1,m1,n2,m2);
    }
  return 0;
}
