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
#define MPF
#ifdef MPF
#include <gmp.h>
#include <gmpxx.h>
#endif
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
#ifdef MPF
mpf_class t[N][M];
#endif
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
  ll kk=0;
#ifdef MPF
  mpf_class mkk(0,1000);
#endif
  const ll ppre=1e11;
  for(int k=0;k<=m2;++k)
    {
      ll d=(n1-m1+0+1+n2-m2+k+1);
      ll v=c[m2][k]%d;
      v*=ppre;
      v/=d;
      if(k&1)
	kk+=1-v;
      else kk+=v;
      if(kk<0)
	kk+=ppre;
      else kk%=ppre;
#ifdef MPF
      mpf_class mt1(1,1000),mt2(1,1000);
      mt1*=t[m2][k];
      mt1/=(n1-m1+0+1+n2-m2+k+1);
      // mt2*=t[m2][k];
      // mt2/=(n1-m1+0+1+n2-m2+k+1);
      // mt1-=mt2;
      if(k&1)
	mkk-=mt1;
      else mkk+=mt1;
#endif
    }
  assert(ppre/PRE==100);
  kk/=100;
  bn nn;
  mul(nn,cc[n1][m1],cc[n2][m2]);
  mul(nn,(n1+1)*(n2+1));
  int len=calLen(nn);
  ll ans(0);
  for(int l=0;l<=m1;++l)
    {
      ll d=n1-m1+l+1;
      ll li=1;
      for(ll i=1,j=10;i<=len-1;i<<=1,j=(j*j)%d)
	if(i&(len-1))
	  li=(li*j)%d;
      li=(li*c[m1][l])%d;
      li*=ppre;
      li*=1000;
      li/=d;
      li/=1000;
      li/=100;
      li*=kk;
      if(l&1)
	ans+=1-li;
      else ans+=li;
      if(ans<0)
	ans+=PRE;
      else ans%=PRE;

      
    }
#ifdef MPF
  if(mkk>1e-9)
    {
      cout<<kk<<endl;
      cout<<mkk<<' '<<n2<<' '<<m2<<endl;
    }
  // int ca=0;
  // if(fabsl(kk)>(ld)1e-19)
  //   for(;fabsl(kk)<1;kk*=10)
  //     ++ca;
  // cout<<ca<<endl;
#endif
  FOR(l,0,m2+1)
    {
      
    }
  // FOR(l,0,m1+1)
  //   {
  //     FOR(k,0,m2+1)
  // 	{
  // 	  ll b=(n2-m2+k+1)*(n1-m1+l+n2-m2+k+2);
  // 	  ll r=1;
  // 	  for(ll i=1,j=10;i<=len-1;i<<=1,j=(j*j)%b)
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
  //   }
  // ans=(ans+PRE)%PRE;
  // mul(a,ans);
  //  prt(a,len);
}
int main()
{
  FOR(i,0,N)
    {
      cc[i][0].PB(1);
#ifdef MPF
      t[i][0].set_prec(1000);
      t[i][0]=1;
#endif
      for(int j=1;j<min(i+1,M);++j)
  	{
  	  mul(cc[i][j],cc[i-1][j-1],i);
  	  div(cc[i][j],j);
#ifdef MPF
	  t[i][j].set_prec(1000);
	  t[i][j]=t[i-1][j-1]*i;
	  t[i][j]/=j;
#endif
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
  if(T>5000)
    return 1;
  scanf("%d",&T);
  for(;T--;)
    {
      int n1,m1,n2,m2;
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      cal(n1,m1,n2,m2);
    }
  return 0;
}
