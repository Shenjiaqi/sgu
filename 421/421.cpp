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
#define N 1000
#define M 13
int n,m,k;
int ai[N];
bool cmpabs(int a,int b)
{
  return abs(a)<abs(b);
}
bool cntp(int np,int nn)
{
  int a=max(0,k-nn);
  int b=min(np,k);
  ld v1=1,v2=1;
  ld sum=0;
  for(int i=0;i<a;++i)
    v1*=(ld)(np-i)/(ld)(i+1);
  for(int i=0;i<k-a;++i)
    v2*=(ld)(nn-i)/(ld)(i+1);
  for(int i=a;i<=b && sum<=k;++i)
    {
      sum+=v1*v2;
      if(i!=b)
	{
	  v1*=(ld)(np-i)/(i+1);
	  v2*=(ld)(k-i)/(ld)(nn-(k-i)+1);
	}
    }
  return sum+.1>=k;
}
const ld eps=1e-13;
inline bool eq(const ld &a,const ld &b)
{
  return fabsl(a-b)<eps;
}
struct z
{
  ld v;
  int c;
  z(const ld &vv,const int &cc){v=vv,c=cc};
};
struct cmp1
{
  bool operator()(const struct &a,const struct &b)const
  {
    if(eq(a.v,b.v))
      return a.c>b.c;
    return a.v>b.v;
  }
};
struct y
{
  ld val;
  ld preval;
  map<z,int,cmp1>::iterator ite1,ite2;
  bool vite2;
  vector<int> pre;
  bool pos;
  bool operator()(const struct y &a,const struct y&b)const
  {
    if(eq(a.val,b.val))
      {
	if(a.pre.size()==b.pre.size())
	  {
	    if(a.ite1->SEC==b.ite1->SEC)
	      {
		if(a.vite2 && b.vite2)
		  return a.ite2->SEC>b.ite2.SEC;
		return a.vite2;
	      }
	    return a.ite1->SEC>b.ite1->SEC;
	  }
	return a.pre.size()<b.pre.size();
      }
    return a.val>b.val;
  };
};
void calp()
{
  sort(ai,ai+n,cmpabs);
  map<z,int,cmp1> mapp[K][2];
  map<z,int,cmp1>::iterator ite[K][N][2];
  for(int i=0;i<n;++i)
    {
      int t=0;
      if(ai[i]<0)
	t=1;
      mapp[0][t].insert(z(fabsl(ai[i]),i));
      FOR(j,0,2)
	ite[0][i][j]=mapp[0][j].begin();
    }
  for(int i=1;i<k;++i)
    {
      for(int j=i;j<n;++j)
	{
	  int t=0;
	  if(a[j]<0)
	    t=1;
	  FOR(d,0,2)
	    if(ite[i-1][j-1][d]!=mapp[i-1][d].end())
	      {
		ld val=ite[i-1][j-1][d]->FIR;
		mapp[t^d][i].insert(z(val*fabsl(a[j]),j));
	      }
	  FOR(d,0,2)
	    ite[i][j][d]=mapp[i][d].begin();
	}
    }
  map<y,int> q;
  struct y tmp;
  tmp.val=ite[k-1][n-1][0]->FIR;
  tmp.ite1=ite[k-1][n-1][0];
  tmp.pos=true;
  if(k>1)
    {
      tmp.vite2=true;
      int col=ite[k-1][n-1][0].SEC;
      if(ai[col]>=0)
	tmp.ite2=ite[k-2][col-1][0];
      else tmp.ite2=ite[k-2][col-1][1];
    }
  else tmp.vite2=false;
  tmp.preval=1;
  q[y]=k-1;
  for(;--k;)
    {
      map<y,int>::iterator ite=q.begin();
      struct y1,y2;
      map<z,int,cmp1>::iterator ite1=ite->FIR.ite1;
      int lev=ite->SEC;
      int c=ite->FIR.pos?1:0;
      ++ite1;
      if(ite1!=mapp[lev][c].end())
	{
	  y1.ite1=ite1;
	  if(lev>0)
	    {
	      y1.vite2=true;
	      int col=ite1->SEC;
	      if((ai[col]>=0?1:0) == c)
		{
		  y1.ite2=ite[lev-1][col-1][0];
		  y1.pos=true;
		}
	      else
		{
		  y1.ite2=ite[lev-1][col-1][1];
		  y1.pos.false;
		}
	    }
	  else y1.vite2=false;
	  y1.val=ite1->FIR*(ld)ai[col]*ite->preval;
	  q[y1]=lev;
	}
      if(ite->vite2)
	{
	  int c=ite->pos?1:0;
	  int col=ite->ite1->SEC;
	  map<ld,int,cmp1>::iterator ite2=ite->ite2;
	  ++ite2;
	  if(ite2!=mapp[lev-1][c].end())
	    {
	      y2.val=ite->FIR.pre*(ld)ai[col]*ite2->FIR;
	      y2.pos=(ite->pos?1:0)^c;
	      y2.pre.PB(col);
	      y2.preval*=(ld)ai[col];
	      y2.ite1=ite->ite2;
	      if(lev>1)
		{
		  y2.ite2=ite[
	    }
	}
    }
}
int main()
{
  scanf("%d%d%d",&n,&m,&k);
  int np,nn;
  np=nn=0;
  FOR(i,0,n)
    {
      scnaf("%d",ai+i);
      if(ai[i]>=0)
	++np;
      else ++nn;
    }
  if(cntp(np,nn))
    calp();
  else caln();
  return 0;
}
