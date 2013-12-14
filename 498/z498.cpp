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
const ll base=1e9;
const ll bb=base*base;
const int prec=3;
class fn
{
public:
  vector<int> v;
  bool sig;
  fn(){sig=0;v.resize(0);};
  void set(int n);
  void div(int n);
  void mul(int n);
  void re();
  // void pt();
  void pf(int c);
  // void add(fn &n);
  // void sub(fn &n);
};
#define N 1001
#define M 51
// fn c[N][M];
int ci[N][M][17];
// ld a[N*2+7][M];
// int cmp(const vector<int> &a,const vector<int> &b)
// {
//   if(a.size()!=b.size())
//     return a.size()-b.size();
//   int i=a.size()-1;
//   for(;i>=0;--i)
//     if(a[i]!=b[i])
//       return a[i]-b[i];
//   return 0;
// }
void fn::pf(int c)
{
  int i=v.size()-1;
  if(sig)
    printf("-");
  if(i>=prec)
    {
      printf("%d",v[i]);
      for(--i;i>=prec;--i)
	printf("%09d",v[i]);
    }
  printf(".");
  int j=prec-1;
  for(;j>0 && j>i && j>=prec-c;--j)
    printf("%09d",0);
  for(;i>=0 && i>=prec-c;--i)
    printf("%09d",v[i]);
  printf("\n");
}
void fn::set(int n)
{
  v.resize(1);
  if(n<0)
    {
      sig=1;
      v[0]=-n;
    }
  else sig=0,v[0]=n;
}
inline void seti(int *a,int v)
{
  a[0]=1;
  a[1]=v;
}
// void fn::pt()
// {
//   int i=v.size()-1;
//   if(i<0)
//     printf("0");
//   else
//     {
//       if(sig)
// 	printf("-");
//       printf("%d",v[i]);
//       for(--i;i>=0;--i)
// 	printf("%09d",v[i]);
//     }
//   printf("\n");
// }
void fn::re()
{
  int i=v.size()-1;
  for(;i>=0 && v[i]==0;--i)
    ;
  v.resize(i+1);
  if(v.size()==0)
    sig=0;
}
// void rei(int *a)
// {
//   int i=a[0];
//   for(;i>0 && a[i]==0;--i)
//     ;
//   a[0]=i+1;
// }
void fn::div(int n)
{
  ll c=0;
  // if((n<0 && !sig) || (n>0 && sig))
  //   sig=1;
  // else sig=0;
  // if(n<0)
  //   n=-n;
  for(int i=v.size()-1;i>=0;--i)
    {
      c=c*base+v[i];
      v[i]=c/n;
      c%=n;
    }
  re();
}
inline void divi(int *a,int v)
{
  ll c=0;
  int n0=0;
  for(int i=a[0];i>0;--i)
    {
      c=(c*base+a[i]);
      a[i]=c/v;
      if(a[i] && !n0)
	n0=i;
      c%=v;
    }
  a[0]=n0;
  // rei(a);
}
inline void divii(int *a,int v,int d)
{
  int i=a[0];
  int j=i+d;
  ll r=0;
  int n0=0;
  for(;i>0;--i,--j)
    {
      r=r*base+a[i];
      a[j]=r/v;
      if(!n0 && a[j])
	n0=j;
      r%=v;
    }
  for(;j>0;--j)
    {
      r*=base;
      a[j]=r/v;
      if(!n0 && a[j])
	n0=j;
      r%=v;
    }
  a[0]=n0;
}
void fn::mul(int n)
{
  ll c=0;
  int i=0;
  // if((n<0 && !sig) || (n>0 && sig))
  //   sig=1;
  // else sig=0;
  // if(n<0)
  //   n=-n;
  for(int j=v.size();i<j;++i)
    {
      c=c+(ll)v[i]*n;
      v[i]=c%base;
      c/=base;
    }
  if(c)
    v.PB(c);
}
inline void mulii(int *a,int *b,int v)
{
  int i=1;
  ll c=0;
  for(int j=b[0];i<=j;++i)
    {
      c+=(ll)b[i]*v;
      a[i]=c%base;
      c/=base;
    }
  if(c)
    {
      a[i]=c;
      a[0]=i;
    }
  else a[0]=i-1;
}
inline void muli(int *a,int v)
{
  ll c=0;
  int i=1;
  for(int j=a[0];i<=j;++i)
    {
      c=c+(ll)a[i]*v;
      a[i]=c%base;
      c/=base;
    }
  if(c)
    a[++a[0]]=c;
}
inline void cpy(int *a,int *b)
{
  memcpy(a,b,(1+b[0])*sizeof(int));
}
// void addd(vector<int> &a,const vector<int> &b)
// {
//   int i=0;
//   ll c=0;
//   for(int j=b.size();i<j;++i)
//     {
//       if(i>=a.size())
// 	a.resize(i+1);
//       c+=a[i]+b[i];
//       if(c>=base)
// 	{
// 	  a[i]=c%base;
// 	  c-=base;
// 	}
//       else
// 	{
// 	  a[i]=c;
// 	  c=0;
// 	}
//     }
//   for(;c;++i)
//     {
//       if(i>=a.size())
// 	a.resize(i+1);
//       c+=a[i];
//       if(c>=base)
// 	{
// 	  a[i]=c%base;
// 	  c-=base;
// 	}
//       else
// 	{
// 	  a[i]=c;
// 	  c=0;
// 	}
//     }
// }
// void subb(vector<int> &a,const vector<int> &b)
// {
//   int carry=0;
//   int i=0;
//   for(int j=b.size();i<j;++i)
//     {
//       a[i]-=(b[i]+carry);
//       if(a[i]<0)
// 	a[i]+=base,carry=1;
//       else carry=0;
//     }
//   for(;carry;++i)
//     {
//       --a[i];
//       if(a[i]<0)
// 	a[i]+=base;
//       else break;
//     }
// }
// void fn::add(fn &n)
// {
//   assert(!n.sig);
//   if(sig)
//     {
//       if(cmp(v,n.v)>0)
// 	subb(v,n.v);
//       else
// 	{
// 	  vector<int> tmp=v;
// 	  v=n.v;
// 	  subb(v,tmp);
// 	  sig=0;
// 	}
//       re();
//     }
//   else
//     {
//       addd(v,n.v);
//     }
// }
// void fn::sub(fn &n)
// {
//   assert(!n.sig);
//   if(sig)
//     {
//       addd(v,n.v);
//     }
//   else
//     {
//       if(cmp(v,n.v)>=0)
// 	{
// 	  subb(v,n.v);
// 	}
//       else
// 	{
// 	  vector<int> tmp=v;
// 	  v=n.v;
// 	  subb(v,tmp);
// 	  sig=1;
// 	}
//       re();
//     }
// }
void mull(vector<int> &a,const vector<int> &b,const vector<int> &c)
{
  for(int i=0;i<b.size();++i)
    for(int j=0;j<c.size();++j)
      {
	if(a.size()<=i+j)
	  a.resize(i+j+1);
	ll d=a[i+j];
	d+=(ll)b[i]*(ll)c[j];
	a[i+j]=d%base;
	d/=base;
	if(d>0)
	  {
	    if(a.size()<=i+j+1)
	      a.resize(i+j+2);
	    a[i+j+1]+=d;
	  }
      }
}
void pt(int *a)
{
  {
    int i=a[0];
    if(i>0)
      printf("%d",a[i]);
    for(--i;i>prec;--i)
      printf("%09d",a[i]);
  }
  printf(".");
  for(int i=min(a[0],prec);i>0;--i)
    printf("%09d",a[i]);
}
float cal(int n1,int m1,int n2,int m2)
{
  // fn vv;
  // vv.v.resize(c[n2][m2].v.size()+prec);
  // FOR(i,0,c[n2][m2].v.size())
  //   vv.v[i+prec]=c[n2][m2].v[i];
  // vv.mul((n1+1)*(n2+1));
  // vv.div((n2-m2+0+1)*(n2-m2+0+n1+2));
  // vv.pf(prec);
  // for(int i=0;i<m1;++i)
  //   {
  //     int m=n1-i;
  //     int d=(n2+n1-m2+1-i);
  //     if(i+1<m1)
  // 	{
  // 	  ++i;
  // 	  m*=n1-i;
  // 	  d*=(n2+n1-m2+1-i);
  // 	}
  //     vv.mul(m);
  //     vv.div(d);
  //   }

  int v[17];
  mulii(v,ci[n2][m2],(n1+1)*(n2+1));
  divii(v,(n2-m2+1)*(n2-m2+n1+2),prec);
  // pt(v);
  for(int i=0;i<m1;)
    {
      ll m=1;
      ll d=1;
      int j=i;
      for(;i<m1 && m*(n1-i)<base && d*(n2+n1-m2+1-i)<base;++i)
	m*=(n1-i),d*=(n2+n1-m2+1-i);
      muli(v,m);
      divi(v,d);
    }
  // mull(v.v,c[n1][m1].v,c[n2][m2].v);
  // v.mul((n1+1)*(n2+1));
  // int l=v.v.size();
  // v.v.resize(v.v.size()+prec);
  // for(int i=l-1;i>=0;--i)
  //   {
  //     v.v[i+prec]=v.v[i];
  //     v.v[i]=0;
  //   }
  // for(int i=m1;i>0;--i)
  //   {
  //     v.mul(i);
  //     v.div(n2+n1-m2+0+1-i+1);
  //   }
  // v.div((n2-m2+0+1)*(n2-m2+0+n1+2));
  // v.pf(1);
  ll ans=0;
  FOR(k,0,m2+1)
    {
      if(k)
	{
	  int a=(n2-m2+k)*(m2-k+1)*(n1+n2+k+1-m1-m2);
	  int b=((n2-m2+k+1)*(n2-m2+k+2+n1)*k);
	  muli(v,a);
	  divi(v,b);
	//   v.mul((n2-m2+k)*(m2-k+1)*(n1+n2+k+1-m1-m2));
	//   v.div((n2-m2+k+1)*(n2-m2+k+2+n1)*k);
	}
      // cout<<v.v.size()<<endl;
      int s=v[0];
      ll tmp=0;
      if(s>=prec)
	{
	  // tmp=v.v[prec-1];
	  tmp=v[prec];
	  if(s>=prec+1)
	    tmp+=(ll)v[prec+1]*base;
	}
      if(k&1)
      	{
      	  ans+=1-tmp;
      	  if(ans<0)
      	    ans+=bb;
      	}
      else
      	{
      	  // ans.add(v);
      	  ans+=tmp;
      	  if(ans>bb)
      	    ans-=bb;
      	}
      // if(k)
      // 	{
      // 	  ld t=(n2-m2+1)*(a[m2][k])*(n1+n2+1+1-m1-m2);
      // 	  // for(int i=0;i<len;++i)
      // 	  //   t*=10;
      // 	  t/=(n2-m2+k+1)*(n2-m2+k+2+n1);
      // 	  cout<<k<<' '<<t<<endl;
      // 	  // ll d=(n2-m2+k+1)*(n2-m2+k+2+n1);
      // 	  // ll j=(10)%d;
      // 	  // ll t=((n2-m2+1)*((ll)a[m2][k]%d)*(n1+n2+1+1-m1-m2))%d;
      // 	  // for(int i=1;i<=len;i<<=1,j=(j*j)%d)
      // 	  //   if(i&(len))
      // 	  //     t=(t*j)%d;
      // 	  // t%=d;
      // 	  // t*=base;
      // 	  // t/=d;
      // 	  // cout<<t<<' '<<d<<endl;
      // 	  // if(k&1)
      // 	  //   {
      // 	  //     sum-=t;
      // 	  //     if(sum<base)
      // 	  // 	sum+=base;
      // 	  //   }
      // 	  // else
      // 	  //   {
      // 	  //     sum+=t;
      // 	  //     sum%=base;
      // 	  //   }
      // 	}
      // else sum+=base;
    }
  // cout<<"!"<<(sum*vv/1e8)<<endl;
  double r=ans%(base*10);
  return r/1e9;
}
int main()
{
  // FOR(i,0,N*2+2)
  //   {
  //     a[i][0]=1;
  //     FOR(j,1,min(M,i+1))
  // 	a[i][j]=a[i-1][j-1]*(ld)i/(ld)j;
  //   }
  FOR(i,0,N)
    {
      seti(ci[i][0],1);
      // c[i][0].set(1);
      FOR(j,1,min(M,i+1))
	{
	  cpy(ci[i][j],ci[i-1][j-1]);
	  muli(ci[i][j],i);
	  divi(ci[i][j],j);
	  // c[i][j].v=c[i-1][j-1].v;
	  // c[i][j].mul(i);
	  // c[i][j].div(j);
	}
    }
  int t;
  scanf("%d",&t);
  for(;t--;)
    {
      int n1,m1,n2,m2;
      scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
      if(n1==n2 && m1==m2)
      	printf("0.5\n");
      else
	{
	  float r;
	  if(m1>m2 || (m1==m2 && n1>n2))
	    r=1-cal(n2,m2,n1,m1);
	  else
	    r=cal(n1,m1,n2,m2);
	  if((double)m1/n1<(double)m2/n2 && r<1e-4)
	    r=1;
	  printf("%.5f\n",r);
	  // for(int a=0;a<50;++a)
	  //   for(int b=0;b<50;++b)
	  //     if((int)(10000*cal(n1,a,n2,b))==9984)
	  // 	cout<<a<<' '<<b<<endl;
	}
    }
  return 0;
}
