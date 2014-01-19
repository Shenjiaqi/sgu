#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
#define N 10000
#define M 13
typedef long double ld;
typedef long long ll;
const ll base=1e9;
const ld eps=2e-17;
int n,m,k;
int a[N];
int ntag;
struct bn
{
  ld lv;
  // vector<int> v;
};
void mul(vector<int> &a,ll b)
{
  assert(b>0);
  ll carry=0;
  for(int i=0,j=a.size();i<j;++i)
    {
      carry+=(ll)a[i]*b;
      a[i]=carry%base;
      carry/=base;
    }
  if(carry>0)
    a.push_back(carry);
}
void mul(bn &a,const ll b)
{
  // ll carry=0;
  // for(int i=0,j=a.v.size();i<j;++i)
  //   {
  //     carry+=(ll)a.v[i]*b;
  //     a.v[i]=carry%base;
  //     carry/=base;
  //   }
  // if(carry>0)
  //   a.v.push_back(carry);
  // else
  //   for(;a.v.size()>0 && a.v[a.v.size()-1]==0;)
  //     a.v.pop_back();
  assert(b>0);
  a.lv+=logl((ld)b);
  // a.lv*=(ld)b;
}
void mul(bn &to,const bn &a,const bn &b)
{
  // to.v.resize(0);
  // for(int i=0;i<a.v.size();++i)
  //   for(int j=0;j<b.v.size();++j)
  //     {
  // 	if(to.v.size()<=i+j)
  // 	  to.v.resize(i+j+1);
  // 	ll carry=(ll)a.v[i]*(ll)b.v[j]+(ll)to.v[i+j];
  // 	to.v[i+j]=carry%base;
  // 	carry/=base;
  // 	if(carry>0)
  // 	  {
  // 	    if(to.v.size()<=i+j+1)
  // 	      to.v.resize(i+j+2);
  // 	    to.v[i+j+1]+=carry;
  // 	  }
  //     }
  // for(;to.v.size()>0 && to.v[to.v.size()-1]==0;)
  //   to.v.pop_back();
  to.lv=a.lv+b.lv;
}
int cmpbn(const bn &a,const bn&b)
{
  if(fabsl(a.lv-b.lv)<eps)
    {
      // int sa=a.v.size(),sb=b.v.size();
      // if(sa!=sb)
      // 	return sa>sb?1:-1;
      // for(int i=0;i<sa;++i)
      // 	if(a.v[i]!=b.v[i])
      // 	  return a.v[i]>b.v[i]?1:-1;
      return 0;
    }
  return a.lv>b.lv?1:-1;
}
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
inline bool cmpabs(int a,int b)
{
  a=abs(a),b=abs(b);
  if(a==b)
    return false;
  return ((abs(a)<abs(b))^ntag);
}
typedef pair<bn,int> pli;
struct cmpp
{
  bool operator()(const pli &v1,const pli &v2) const
  {
    int c=cmpbn(v1.first,v2.first);
    if(c==0)
      return v1.second>v2.second;
    return ((c>0?1:0)^ntag);
  };
};
struct el
{
  bn val;
  bn preval;
  int lev;
  int precol;
  vector<int>lst;
  map<pli,int,cmpp>::iterator ite1;
};
struct cmpel
{
  bool operator()(const el &e1,const el &e2) const
  {
    int c=cmpbn(e1.val,e2.val);
    if(c!=0)
      return ((c>0?1:0)^ntag);
    if(e1.lev!=e2.lev)
      return e1.lev>e2.lev;
    if(e1.precol!=e2.precol)
      return e1.precol>e2.precol;
    if(e1.ite1->first.second!=e2.ite1->first.second)
      return e1.ite1->first.second>e2.ite1->first.second;
    assert(e1.lst.size()==e2.lst.size());
    for(int i=0;i<e1.lst.size();++i)
      if(e1.lst[i]!=e2.lst[i])
	return e1.lst[i]>e2.lst[i];
    c=cmpbn(e1.ite1->first.first,e2.ite1->first.first);
    if(c)
      return c>0?1:0;
    return cmpbn(e1.preval,e2.preval)>=0;
  };
};
void prt(const vector<int> & val)
{
  int i=val.size()-1;
  if(i<0)
    printf("0");
  else
    {
      printf("%d",val[i]);
      for(--i;i>=0;--i)
	printf("%09d",val[i]);
    }
}
map<pli,int,cmpp> mapp[M][2];
map<pli,int,cmpp>::iterator itee[M][N][2],ite;
void pt(const el & z,const vector<int> &lst)
{
  vector<int> val;
  val.push_back(1);
  for(int i=0;i<lst.size();++i)
    mul(val,abs(a[lst[i]]));
  int lev=z.lev;
  if(lev>=0)
    {
      int col=z.ite1->first.second;
      int posi=z.ite1->second;
      for(int i=lev;i>=0;--i)
  	{
  	  mul(val,abs(a[col]));
  	  if(i>0)
  	    {
  	      posi^=(a[col]>=0?0:1);
  	      col=itee[i-1][col-1][posi]->first.second;
  	    }
  	}
    }
  prt(val);
  // prt(z.val);
}
void calpos()
{
  sort(a,a+n,cmpabs);
  for(int i=0;i<n;++i)
    {
      int t=a[i]>=0?0:1;
      pli c;
      // c.first.v.push_back(abs(a[i]));
      c.first.lv=logl((ld)abs(a[i]));
      c.second=i;
      mapp[0][t][c]=t;
      for(int j=0;j<2;++j)
	itee[0][i][j]=mapp[0][j].begin();
    }
  for(int i=1;i<m;++i)
    for(int j=i;j<n;++j)
      {
	int t=a[j]>=0?0:1;
	for(int h=0;h<2;++h)
	  {
	    ite=itee[i-1][j-1][h];
	    // assert(ite->second==h);
	    if(ite!=mapp[i-1][h].end())
	      {
		pli c=ite->first;
		mul(c.first,abs(a[j]));
		c.second=j;
		mapp[i][t^h][c]=t^h;
	      }
	  }
	for(int h=0;h<2;++h)
	  itee[i][j][h]=mapp[i][h].begin();
      }
  // for(typeof(mapp[0][1].begin()) i=mapp[0][1].begin();i!=mapp[0][1].end();++i)
  //   cout<<i->second<<' '<<i->first.first<<endl;
  // multimap<el,vector<int>,cmpel> que;
  map<el,int,cmpel> que;
  el tmp;
  tmp.ite1=mapp[m-1][ntag].begin();
  tmp.val=tmp.ite1->first.first;
  tmp.lev=m-1;
  tmp.preval.lv=0;
  tmp.precol=n;
  // cout<<tmp.val<<endl;
  // bn one;
  // one.v.push_back(1);
  // one.lv=0;
  vector<int> emp;
  // que.insert(make_pair(tmp,emp));
  que[tmp]=1;
  for(;--k;)
    {
      // cout<<k<<' '<<que.size()<<endl;
      tmp=que.begin()->first;
      // vector<int> lst=que.begin()->second;
      // cout<<k<<' '<<tmp.val<<endl;
      for(;;)
	{
	  typeof(ite) ii=tmp.ite1;
	  for(++ii;ii!=mapp[tmp.lev][tmp.ite1->second].end() && 
		ii->first.second>=tmp.precol;)
	    {
	      typeof(ii) iii=ii++;
	      // mapp[tmp.lev][tmp.ite1->second].erase(iii);
	    }
	  if(ii!=mapp[tmp.lev][tmp.ite1->second].end())
	    {
	      el z=tmp;
	      mul(z.val,tmp.preval,ii->first.first);
	      // mul(z.val,preval,ii->first.first);
	      z.ite1=ii;
	      que[z]=1;
	      // que.insert(make_pair(z,lst));
	    }
	  if(tmp.lev>0)
	    {
	      tmp.precol=tmp.ite1->first.second;
	      // lst.push_back(tmp.precol);
	      tmp.lst.push_back(tmp.precol);
	      mul(tmp.preval,abs(a[tmp.precol]));
	      // mul(preval,abs(a[tmp.precol]));
	      --tmp.lev;
	      int posi=tmp.ite1->second^(a[tmp.precol]>=0?0:1);
	      tmp.ite1=itee[tmp.lev][tmp.precol-1][posi];
	    }
	  else break;
	}
      // for(++ite;ite!=mapp[lev][posi].end() && 
      // 	    ite->first.second>=col;)
      // 	{
      // 	  typeof(ite) ii=ite++;
      // 	  mapp[lev][posi].erase(ii);
      // 	}
      // if(ite!=mapp[lev][posi].end())
      // 	{
      // 	  col=ite->first.second;
      // 	  el t;
      // 	  t.lev=lev;
      // 	  t.val=tmp.preval*ite->first.first;
      // 	  t.ite1=ite;
      // 	  if(lev>0)
      // 	    {
      // 	      t.ite2=itee[lev-1][col-1][posi^(a[col]>=0?0:1)];
      // 	    }
      // 	  t.preval=tmp.preval;
      // 	  t.lst=tmp.lst; 
      // 	  cout<<"!"<<t.val<<' '<<ite->first.first<<endl;
      // 	  que[t]=1;
      // 	}
      // if(lev>0)
      // 	{
      // 	  posi=tmp.ite2->second;
      // 	  ite=tmp.ite2;
      // 	  col=tmp.ite1->first.second;
      // 	  lev=tmp.lev;
      // 	  for(++ite;ite!=mapp[lev-1][posi].end() && ite->second>=col;)
      // 	    {
      // 	      typeof(ite) ii=ite++;
      // 	      mapp[lev-1][posi].erase(ii);
      // 	    }
      // 	  if(ite!=mapp[lev-1][posi].end())
      // 	    {
      // 	      el t;
      // 	      t.lev=lev-1;
      // 	      t.preval=tmp.preval*fabsl(a[col]);
      // 	      t.val=t.preval*ite->first.first;
      // 	      t.ite1=ite;
      // 	      if(lev>1)
      // 		t.ite2=itee[lev-2][ite->first.second-1][posi^(a[col]>=0?0:1)];
      // 	      t.lst=tmp.lst;
      // 	      t.lst.push_back(abs(a[col]));
      // 	      que[t]=1;
      // 	      cout<<"!!"<<t.val<<' '<<ite->first.first<<' '<<a[col]<<' '
      // 		  <<t.val<<' '<<t.ite1->first.second<<endl;
      // 	    }
      // 	}
      que.erase(que.begin());
      for(;que.size()>k;)
	{
	  typeof(que.end()) ii=que.end();
	  --ii;
	  que.erase(ii);
	}
    }
  pt(que.begin()->first,que.begin()->first.lst);
}
void calneg()
{
  ntag=1;
  printf("-");
  calpos();
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d",&n,&m,&k);
  assert(m<=n);
  int nneg=0,npos=0,nzero=0;
  for(int i=0;i<n;++i)
    {
      scanf("%d",a+i);
      if(a[i]<0)
	++nneg;
      else if(a[i]>0)
	++npos;
      else ++nzero;
    }
  int i=0;
  for(int j=0;j<n;++j)
    if(a[j]!=0)
      a[i]=a[j],++i;
  n=i;
  if(npos+nneg>0 && cntp(npos,nneg))
    calpos();
  else if(nzero>0 && cntz(nzero,nneg+npos))
    printf("0");
  else calneg();
  return 0;
}
