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
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 10000
#define M 13
const ld eps=2e-15;
const ll base=1e9;
bool ntag;
int n,m,k;
int a[N];
bool cntp(int pos,int neg)
{
  int f=max(0,m-neg);
  int t=min(pos,m);
  assert(f<=t);
  ld sum=0;
  ld vp=1;
  for(int i=0;i<f;++i)
    vp=vp*(ld)(pos-i)/(ld)(i+1);
  ld vn=1;
  for(int i=0;i<m-f;++i)
    vn=vn*(ld)(neg-i)/(ld)(i+1);
  for(int i=f;;++i)
    {
      if(((m-i)&1)==0)
	sum+=vn*vp;
      if(sum+0.1>k)
	return true;
      if(i>=t)
	break;
      vp=(vp*(ld)(pos-i))/(ld)(i+1);
      vn=(vn*(ld)(m-i))/(ld)(neg-(m-i)+1);
    }
  k-=(int)(sum+0.1);
  return false;
}
bool cntz(int zero,int nzero)
{
  int f=max(0,m-nzero);
  int t=min(zero,m);
  assert(f<=t);
  ld sum=0;
  ld vp=1;
  for(int i=0;i<f;++i)
    vp=vp*(ld)(zero-i)/(ld)(i+1);
  ld vn=1;
  for(int i=0;i<m-f;++i)
    vn=vn*(ld)(nzero-i)/(ld)(i+1);
  for(int i=f;;++i)
    {
      if(i>0)
	sum+=vn*vp;
      if(sum+0.1>k)
	return true;
      if(i>=t)
	break;
      vp=(vp*(ld)(zero-i))/(ld)(i+1);
      vn=(vn*(ld)(m-i))/(ld)(nzero-(m-i)+1);
    }
  // cout<<"!"<<sum<<endl;
  k-=(int)(sum+0.1);
  return false;
}
inline bool cmpabs(const int &a,const int &b)
{
  return ((abs(a)<abs(b))!=ntag);
}
struct bn
{
  ld v;
  vector<int> vec;
  bn(int vv){v=logl(vv);vec.PB(vv);};
  bn(){v=0;vec.PB(1);};
};
int cmpbn(const bn& a,const bn& b)
{
  if(fabsl(a.v-b.v)>eps)
    return a.v>b.v?1:-1;
  int sa=a.vec.size();
  int sb=b.vec.size();
  if(sa!=sb)
    return sa>sb?1:-1;
  for(--sa;sa>=0;--sa)
    if(a.vec[sa]!=b.vec[sa])
      return a.vec[sa]>b.vec[sa]?1:-1;
  return 0;
}
typedef pair<bn,int> pbi;
struct cmppbi
{
  bool operator()(const pbi &a,const pbi &b) const 
  {
    int c=cmpbn(a.FIR,b.FIR);
    if(c!=0)
      return (c>0)!=ntag;
    return a.SEC>b.SEC;
  };
};
map<pbi,int,cmppbi> mapp[M][2];
typeof(mapp[0][0].begin()) itee[M][N][2],ite;
inline void mul(bn &to,const bn &from,const bn v)
{
  to.v=from.v+v.v;
  to.vec.resize(0);
  FOR(i,0,from.vec.size())
    FOR(j,0,v.vec.size())
    {
      if(to.vec.size()<i+j+1)
	to.vec.resize(i+j+1);
      ll carry=(ll)from.vec[i]*(ll)v.vec[j]+(ll)to.vec[i+j];
      to.vec[i+j]=carry%base;
      carry/=base;
      if(carry>0)
	{
	  if(to.vec.size()<i+j+2)
	    to.vec.resize(i+j+2);
	  to.vec[i+j+1]+=carry;
	}
    }
}
inline void mul(bn &to,const bn v)
{
  bn tmp=to;
  mul(to,tmp,v);
}
struct el
{
  bn val;
  typeof(ite) ii;
  vector<int> lst;
};
struct cmpel
{
  bool operator()(const el &a,const el &b) const 
  {
    int c=cmpbn(a.val,b.val);
    if(c!=0)
      return (c>0)!=ntag;
    int sa=a.lst.size();
    if(sa!=b.lst.size())
      return sa<b.lst.size();
    for(--sa;sa>=0;--sa)
      if(a.lst[sa]!=b.lst[sa])
	return a.lst[sa]>b.lst[sa];
    return a.ii->FIR.SEC>b.ii->FIR.SEC;
  };
};
void mul(vector<int> &to,ll v)
{
  ll carry=0;
  for(int i=0,j=to.size();i<j;++i)
    {
      carry+=(to[i]*v);
      to[i]=carry%base;
      carry/=base;
    }
  if(carry>0)
    to.PB(carry);
}
void pt(const vector<int> v)
{
  int i=v.size();
  assert(i>0);
  if(ntag)
    printf("-");
  printf("%d",v[i-1]);
  for(i-=2;i>=0;--i)
    printf("%09d",v[i]);
}
void prt(const el &v)
{
  vector<int> ans;
  ans.PB(1);
  FR(i,v.lst)
    mul(ans,abs(a[*i]));
  int lev=m-1-v.lst.size();
  typeof (mapp[0][0].begin()) i=v.ii;
  for(;lev>=0;--lev)
    {
      int col=i->FIR.SEC;
      mul(ans,abs(a[col]));
      if(lev>0)
	i=itee[lev-1][col-1][i->SEC^(a[col]>0?0:1)];
    }
  pt(ans);
}
void cal()
{
  sort(a,a+n,cmpabs);
  FOR(i,0,n)
    {
      int c=a[i]>0?0:1;
      mapp[0][c].insert(MP(pbi(bn(abs(a[i])),i),c));
      FOR(j,0,2)
	itee[0][i][j]=mapp[0][j].begin();
    }
  FOR(i,1,m)
    FOR(j,i,n)
    {
      int h=a[j]>0?0:1;
      FOR(c,0,2)
	{
	  ite=itee[i-1][j-1][c];
	  if(ite!=mapp[i-1][c].end())
	    {
	      bn tmp(1);
	      mul(tmp,ite->FIR.FIR,bn(abs(a[j])));
	      mapp[i][c^h][pbi(tmp,j)]=c^h;
	    }
	}
      FOR(c,0,2)
	itee[i][j][c]=mapp[i][c].begin();
    }
  map<el,bn,cmpel> que;
  el tmp;
  tmp.ii=itee[m-1][n-1][ntag?1:0];
  tmp.val=tmp.ii->FIR.FIR;
  que[tmp]=bn(1);
  for(;--k;)
    {
      tmp=que.begin()->FIR;
      // cout<<k<<' '<<expl(tmp.val)<<' '<<tmp.ii->FIR.SEC<<endl;
      bn preval=que.begin()->SEC;
      que.erase(que.begin());
      int lev=m-1-tmp.lst.size();
      for(;lev>=0;--lev)
	{
	  ite=tmp.ii;
	  int precol=tmp.lst.size()>0?tmp.lst[tmp.lst.size()-1]:n;
	  for(++ite;
	      ite!=mapp[lev][tmp.ii->SEC].end() &&
		ite->FIR.SEC>=precol;)
	    {
	      typeof(ite) i=ite++;
	      // mapp[lev][tmp.ii->SEC].erase(i);
	    }
	  if(ite!=mapp[lev][tmp.ii->SEC].end())
	    {
	      mul(tmp.val,preval,ite->FIR.FIR);
	      swap(ite,tmp.ii);
	      // cout<<"!"<<lev<<' '<<expl(tmp.val)<<' '<<expl(ite->FIR.FIR)<<' '<<tmp.ii->FIR.SEC<<endl;;
	      que[tmp]=preval;
	      // cout<<"@@"<<que.find(tmp)->FIR.ii->FIR.SEC<<' '<<tmp.ii->FIR.SEC<<endl;
	      swap(ite,tmp.ii);
	    }
	  int col=tmp.ii->FIR.SEC;
	  if(lev>0)
	    {
	      mul(preval,bn(abs(a[col])));
	      int sig=tmp.ii->SEC^(a[col]>0?0:1);
	      // cout<<sig<<endl;
	      tmp.ii=itee[lev-1][col-1][sig];
	      if(tmp.ii==mapp[lev-1][sig].end())
		break;
	      assert(tmp.ii->SEC==sig);
	      tmp.lst.PB(col);
	    }
	}
      for(;que.size()>k;)
	{
	  typeof(que.end()) i=que.end();
	  --i;
	  que.erase(i);
	}
    }
  // cout<<expl(que.begin()->FIR.val)<<endl;
  prt(que.begin()->FIR);
}
int main()
{
  // freopen("inn","r",stdin);
  scanf("%d%d%d",&n,&m,&k);
  int npos,nneg,nzeo;
  npos=nneg=nzeo=0;
  FOR(i,0,n)
    {
      scanf("%d",a+i);
      if(a[i]==0)
	++nzeo;
      else if(a[i]>0)
	++npos;
      else ++nneg;
    }
  int nn=n;
  n=0;
  for(int i=0;i<nn;++i)
    if(a[i]!=0)
      a[n++]=a[i];
  if(npos+nneg>0 && cntp(npos,nneg))
    cal();
  else if(nzeo>0 && cntz(nzeo,npos+nneg))
    printf("0");
  else
    {
      ntag=true;
      cal();
    }
  return 0;
}

