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
#define M 52
const ld eps=1e-13;
const ll d12=1e12;
const ll base=1e9;
typedef vector<int> bn;
const int prec=9;
const ll PRE=(ll)(1e9);
const ll d9=PRE;
const ll d10=1e10;
ll mmd[N*2+7][301];
int ff[100];
ld dd[N*2+7][M];
bn cc[N][M];
int ee[N*2+7][M];
ll c[M][M];
bn ft[N*2+1][M];
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
void mul(bn &a,bn &b)
{
  bn tmp;
  mul(tmp,a,b);
  a=tmp;
}
void add(bn &a,bn &b)
{
  ll c=0;
  int i=0;
  for(int j=b.size();i<j;++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      c+=a[i]+b[i];
      a[i]=c%base;
      c/=base;
    }
  for(;c;++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      c+=a[i];
      a[i]=c%base;
      c/=base;
    }
}
void d0(bn &a)
{
  int i=a.size()-1;
  for(;i>=0 && a[i]==0;--i)
    ;
  a.resize(i+1);
}
void sub(bn &a,bn &b)
{
  if(a.size()<b.size())
    {
      a.resize(0);
      return ;
    }
  int i=0,c=0;
  for(int j=b.size();i<j;++i)
    {
      a[i]-=(c+b[i]);
      if(a[i]>=0)
	c=0;
      else a[i]+=base,c=1;
    }
  for(;c && i<a.size();++i)
    {
      a[i]-=c;
      if(a[i]>=0)
	break;
      else a[i]+=base;
    }
  if(i>=a.size())
    a.resize(0);
  else
    d0(a);
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
  d0(a);
}
int calLen(bn&a)
{
  int i=a.size()-1;
  int r=i*9;
  for(int j=a[i];j;j/=10)
    ++r;
  return r;
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
  bn v;
  mul(v,cc[n1][m1],cc[n2][m2]);
  mul(v,(n1+1)*(n2+1));
  int l=v.size();
  FOR(i,0,l)
    v.PB(0);
  for(int i=0;i<m1;++i)
    mul(v,n2+n1-m2+0+1+i);
  for(int i=0;i<m1;++i)
    div(v,i+1);
  div(v,(n2-m2+0+1)*(n2-m2+0+n1+2));
  bool sig=0;
  for(int i
}
int main()
{
  // freopen("in","r",stdin);
  // ff[0]=1;
  // FOR(i,1,100)
  //   ff[i]=10*ff[i-1];

  // FOR(i,0,N+N+3)
  //   {
  //     cc[i][0].PB(1);
  //     dd[i][0]=1;
  //     ee[i][0]=0;
  //     for(int j=1;j<min(i+1,M);++j)
  // 	{
  // 	  dd[i][j]=dd[i-1][j-1]*(ld)i/(ld)j;
  // 	  ee[i][j]=ee[i-1][j-1];
  // 	  for(;dd[i][j]>=10.0;++ee[i][j])
  // 	    dd[i][j]/=10.0;
  // 	  mul(cc[i][j],cc[i-1][j-1],i);
  // 	  div(cc[i][j],j);
  // 	}
  //   }
  // FOR(i,0,M)
  //   {
  //     c[i][0]=1;
  //     FOR(j,1,min(i+1,M))
  // 	{
  // 	  c[i][j]=(c[i-1][j-1]*(ll)i)/(ll)j;
  // 	}
  //   }
  // FOR(i,1,2003)
  //   {
  //     mmd[i][0]=1;
  //     FOR(j,1,301)
  // 	{
  // 	  mmd[i][j]=(mmd[i][j-1]*10)%i;
  // 	}
  //   }
  // for(int i=2;i<=2002;++i)
  //   for(int j=1;j<=min(i,51);++j)
  //     {
  // 	FOR(k,0,30)
  // 	  ft[i][j].PB(0);
  // 	ft[i][j].PB(j);
  // 	div(ft[i][j],i);
  //     }

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
