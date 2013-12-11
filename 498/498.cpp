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
#include <gmp.h>
#include <gmpxx.h>
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
const ll d12=1e12;
const ll base=1e9;
typedef vector<int> bn;
const int prec=9;
const ll PRE=(ll)(1e9);
const ll d9=PRE;
bn cc[N][M];
ll c[M][M];
ll det[N*2+1][M];
ll ss[N*2+1][M];
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
ll calLev3(ll d,int a,int b)
{      
  ll v=c[a][b]%d;
  v*=PRE;
  v/=d;
  if(b&1)
    return -v;//!!
  return v;
}
ll calLev2(int n1,int m1,int l,int n2,int m2)
{
  ll kk=0;
  for(int k=0;;++k)
    {
      ll v=calLev3(n1-m1+l+n2-m2+k+2,m2,k);
      if((v/100)==0)
      	break;
      kk+=v;

      int rk=m2-k;
      if(rk>k)
	{
	  v=calLev3(n1-m1+l+n2-m2+rk+2,m2,rk);
	  if(v/100)
	    {
	      kk+=v;
	    }
	}
      else break;
    }

  return kk;
}
void cal(int n1,int m1,int n2,int m2)
{
  bn nn;
  mul(nn,cc[n1][m1],cc[n2][m2]);
  mul(nn,(n1+1)*(n2+1));

  int len=calLen(nn);
  ll ans(0);

  ll v=n1-m1+0+1+n2-m2+1;
  ll kk=ss[v][m2];
  cout<<n1<<' '<<m1<<' '<<n2<<' '<<m2<<' '<<kk<<' '<<len<<endl;
  for(int l=0;l<=m1;++l)
    {
      cout<<l<<' '<<kk<<endl;
      ll d=n1-m1+l+1;
      ll li=1;
      ll kkk=(kk+500)/1000;
      int llen=len-1;
      for(ll i=1,j=10;i<=max(0,len-1-9);i<<=1,j=(j*j)%d)
	if(i&(len-1))
	  li=(li*j)%d;
      li=(li*(c[m1][l]%d))%d;
      cout<<"li"<<li<<' '<<c[m1][l]<<' '<<d<<endl;
      li*=d9;
      assert(li>=0);
      li/=d;
      li*=kkk;
      for(int i=0;i<min(9,len-1);++i)
	li/=10;
      if(l&1)
	ans+=1-li;
      else ans+=li;
      if(ans<0)
	ans+=d9;
      ans%=d9;
      ++v;
      assert(v<2003 && m2<51);
      if(det[v][m2]>50 )
	kk=max(kk-det[v][m2],0LL);
    }
  cout<<ans<<endl;
  // cout<<"!"<<ans<<endl;
  cout<<"!"<<endl;
  pt(nn);
  mul(nn,ans);
  prt(nn,len);
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
  FOR(i,2,N*2+1)
    FOR(j,0,M)
    {
      ll sum=0,sum2=0;
      FOR(k,0,j+1)
	{
	  ll d=(i+k)*(i+k-1);
	  ll v=c[j][k]%d;
	  v*=d12;
	  v/=d;
	  if(k&1)
	    sum+=1-v;
	  else sum+=v;
	  if(sum<0)
	    sum+=d12;
	  else sum%=d12;

	  d=i+k;
	  v=c[j][k]%d;
	  v*=d12;
	  v/=d;
	  if(k&1)
	    sum2+=1-v;
	  else sum2+=v;
	  if(sum2<0)
	    sum2+=d12;
	  else sum2%=d12;
	}
      det[i][j]=(sum+d12)%d12;
      ss[i][j]=(sum2+d12)%d12;
      // if(i>50 && j>2 && det[i][j]>100)
      // 	cout<<"!"<<i<<' '<<j<<' '<<det[i][j]<<endl;
    }
  // FOR(i,2,N*2+1)
  //   FOR(j,1,min(i+1,M))
  //   cout<<i<<' '<<j<<' '<<det[i][j]<<endl;

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
