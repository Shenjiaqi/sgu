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
// bn ft[N*2+1][M];
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
  ld nn=dd[n1][m1]*dd[n2][m2];
  nn*=(n1+1)*(n2+1);
  int len=ee[n1][m1]+ee[n2][m2];
  for(;nn>=10-1e-7;)
    nn/=10,++len;
  // cout<<nn<<endl;
  ld ans(0);
  FOR(k,0,m2+1)
    {
      ld d=dd[n1+n2-m2+k+1][m1];
      int lend=ee[n1+n2-m2+k+1][m1];
      // cout<<d<<endl;
      d*=(n2-m2+k+1)*(n2+n1-m2+k+2);
      for(;d>=10-1e-7;d/=10)
	++lend;
      lend=len-lend;
      ld t=c[m2][k];
      t=fmod(t,d);
      ld j=10;
      for(int i=1;i<=lend;i<<=1,j=fmod(j*j,d))
	if(i&(lend))
	  t=fmod(t*j,d);
      t/=d;
      if(k&1)
	ans-=t;
      else ans+=t;
      ans=fmod(ans,10.0);
      if(ans<0)
	ans+=10;
      ans=fmod(ans,10.0);
      // ld t1=dd[n1][m1]*dd[n2][m2];
      // t1/=dd[n2+n1-m2+k+1][m1];
      // // cout<<t1<<endl;
      // ld t2=(n1+1)*(n2+1);
      // t2/=((n2-m2+k+1)*(n2-m2+k+1+n1+1));
      // t2*=dd[m2][k];
      // t1*=t2;
      // cout<<t1<<"!"<<endl;
      // if(k&1)
      // 	ans-=t1;
      // else ans+=t1;
    }
  ans*=nn;
  printf("%.4f\n",(float)ans);
}
//   bn a=cc[n1][m1];;
//   int cl=calLen(a);

//   ld ans(0);
//   FOR(l,0,m1+1)
//     {
//       ld vl=dd[m1][l];
//       int llen=ee[m1][l];
//       ld sum=0.0;
//       FOR(k,0,m2+1)
// 	{
// 	  ld vk=dd[n2-m2+k][k]*dd[n2+1][m2-k];
// 	  int lk=ee[n2-m2+k][k]+ee[n2+1][m2-k]+llen+cl;
// 	  if(vk>=10)
// 	    ++lk,vk/=10;
// 	  int v2=n2-m2+k+1+n1-m1+l+1;
// 	  ld tmp=mmd[v2][max(0,lk-9)];
// 	  tmp/=v2;
// 	  tmp*=ff[min(lk,9)];
// 	  vk*=tmp;
// 	  if(k&1)
// 	    sum-=vk;
// 	  else sum+=vk;
// 	}
//       vl*=sum;
//       vl-=(ld)((ll)vl/10LL)*10.0;
//       if(l&1)
// 	ans-=vl;
//       else ans+=vl;
//     }
//   ll z=ans*d9;
//   mul(a,z%d9);
//   prt(a,cl);
// }  

//   FOR(l,0,m1+1)
//     {
//       ld vt=dd[n1+1][m1-l]*dd[n1+l-m1][l];
//       int lt=ee[n1+1][m1-l]+ee[n1+l-m1][l];
//       if(vt>=10)
// 	vt/=10.0,++lt;
//       // cout<<lt<<' '<<vt<<endl;
//       ld sum=0;
//       FOR(k,0,m2+1)
// 	{
// 	  ld kt=dd[n2+1][m2-k]*dd[n2-m2+k][k];
// 	  int kl=ee[n2+1][m2-k]+ee[n2-m2+k][k]+lt;
// 	  if(kt>=10)
// 	    kt/=10,++kl;
// 	  // cout<<kt<<' '<<kl<<' '<<vt<<endl;
// 	  int v1=n1-m1+l+1;
// 	  int v2=n2-m2+k+1;
// 	  v2+=v1;
// 	  ld t=((ll)v1*mmd[v2][max(0,kl-0)])%(v2);
// 	  t*=ff[min(kl,0)];
// 	  t/=v2;
// 	  cout<<t<<endl;
// 	  kt*=t;
// 	  if(kt>10-1e-8)
// 	    kt-=((ll)kt/10)*(ld)10;
// 	  // cout<<"kt "<<kt<<' '<<sum<<' '<<sum-kt<<endl;
// 	  if(k&1)
// 	    {
// 	      sum=sum-kt;
// 	      if(sum<0)
// 	      	sum+=10;
// 	    }
// 	  else
// 	    {
// 	      sum+=kt;
// 	      // if(sum>=1)
// 	      // 	sum-=(ll)sum;
// 	      if(sum>=10)
// 	      	{
// 	      	  sum-=((ll)sum/10)*(ld)10;
// 	      	}
// 	    }
// 	  // cout<<sum<<endl;
// 	}
//       // cout<<sum<<endl;
//       sum*=vt;
//       // if(sum>10)
//       // 	sum-=(ld)((ll)sum/10)*10;
//       if(sum>=10-1e-8)
// 	sum-=((ll)sum/10)*10;
//       if(sum>1e-8)
// 	{
// 	  if((l)&1)
// 	    {
// 	      ans-=sum;
// 	      if(ans<0)
// 		ans+=10.0;
// 	    }
// 	  else
// 	    {
// 	      ans+=sum;
// 	      if(ans>=10-1e-8)
// 		ans-=((ll)ans/10)*10;
// 	    }
// 	}
//     }
//   // cout<<"!"<<ans<<endl;
//   ans-=((ll)ans/10)*(ld)10;
//   // if(ans<1e-5 && (ld)m1/n1>(ld)m2/n2)
//   //   printf("1\n");
//   // else
//   printf("%.7f\n",(float)ans);
// }
int main()
{
  freopen("in","r",stdin);
  // ff[0]=1;
  // FOR(i,1,100)
  //   ff[i]=10*ff[i-1];

  FOR(i,0,N+N+3)
    {
      // cc[i][0].PB(1);
      dd[i][0]=1;
      ee[i][0]=0;
      for(int j=1;j<min(i+1,M);++j)
  	{
	  dd[i][j]=dd[i-1][j-1]*(ld)i/(ld)j;
	  ee[i][j]=ee[i-1][j-1];
	  for(;dd[i][j]>=10.0;++ee[i][j])
	    dd[i][j]/=10.0;
  	  // mul(cc[i][j],cc[i-1][j-1],i);
  	  // div(cc[i][j],j);
	}
    }
  FOR(i,0,M)
    {
      c[i][0]=1;
      FOR(j,1,min(i+1,M))
  	{
  	  c[i][j]=(c[i-1][j-1]*(ll)i)/(ll)j;
  	}
    }
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
