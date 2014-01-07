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
#define N 1007
int n,vw,vc;
int p[N][2];
vector<pair<ld,ld> > cut[N];
const ld eps=1e-7;
map<int,int> mapp;
bool eq(const ld &a,const ld &b)
{
  return fabsl(a-b)<eps;
}
struct line
{
  ld x1,y1,x2,y2;
  int type;
  line(ld xx1,ld yy1,ld xx2,ld yy2,int t)
  {
    if(xx1>xx2)
      swap(xx1,xx2),swap(yy1,yy2);
    x1=xx1,x2=xx2;
    y1=yy1,y2=yy2;
    type=t;
  };
};
bool cmprd(const line &a,const line &b)
{
  if(!eq(a.x1,b.x1))
    return a.x1<b.x1;
  return a.x2<b.x2;
}
vector<line> rd;
ld calx(ld x1,ld y1,ld x2,ld y2,ld y)
{
  assert(y<max(y1,y2)+eps && y>min(y1,y2)-eps);
  if(eq(x1,x2))
    return x1;
  assert(!eq(y1,y2));
  return (y-y1)*(x2-x1)/(y2-y1)+x1;
}
void cal(int a,int b)
{
  if(p[a][1]<p[b][1])
    mapp[p[a][1]]=a;
  else
    {
      typeof(mapp.begin()) ite=mapp.lower_bound(p[b][1]),tmp;
      for(;ite!=mapp.end() && ite->first<=p[a][1];)
	{
	  tmp=ite++;
	  int k=tmp->second;
	  ld x,y;
	  x=calx(p[a][0],p[a][1],p[b][0],p[b][1],p[k][1]);
	  y=p[k][1];
	  rd.PB(line(p[k][0],p[k][1],x,y,1));
	  cut[min(a,b)].PB(MP(x,y));
	  mapp.erase(tmp);
	}
    }
}
struct cmp
{
  bool operator()(const ld &a,const ld&b) const
  {
    return (!eq(a,b) && a<b);
  }
};
ld dis(const ld &x1,const ld&y1,const ld&x2,const ld&y2)
{
  ld dx=x1-x2;
  ld dy=y1-y2;
  return sqrtl(dx*dx+dy*dy);
}
int main()
{
  scanf("%d%d%d",&n,&vw,&vc);
  FOR(i,0,n)
    scanf("%d%d",&p[i][0],&p[i][1]);
  for(int i=0;i<n-1;++i)
    cal(i,i+1);
  for(int i=n-1;i>0;--i)
    cal(i,i-1);
  for(int i=0;i<n-1;++i)
    {
      ld prex=p[i][0],prey=p[i][1];
      sort(cut[i].begin(),cut[i].end());
      for(int j=0;j<cut[i].size();++j)
	{
	  ld x=cut[i][j].FIR;
	  ld y=cut[i][j].SEC;
	  rd.PB(line(x,y,prex,prey,0));
	  prex=x,prey=y;
	}
      rd.PB(line(prex,prey,p[i+1][0],p[i+1][1],0));
    }
  sort(rd.begin(),rd.end(),cmprd);
  map<ld,ld,cmp> mappp;
  mappp[p[0][0]]=0;
  for(int i=0;i<rd.size();++i)
    {
      ld x1=rd[i].x1,x2=rd[i].x2;
      ld y1=rd[i].y1,y2=rd[i].y2;
      typeof(mappp.begin()) ite=mappp.find(x1);
      assert(ite!=mappp.end());
      ld time=ite->second;
      if(rd[i].type==1)
	time+=fabsl(x2-x1)/(ld)vc;
      else
	time+=dis(x1,y1,x2,y2)/(ld)vw;
      typeof(ite) tmp=mappp.find(x2);
      // cout<<"!"<<x2<<' '<<time<<' '<<x1<<' '<<ite->second<<' '<<rd[i].type<<endl;
      if(tmp==mappp.end())
	mappp[x2]=time;
      else tmp->second=min(tmp->second,time);
    }
  typeof(mappp.begin()) ani=mappp.find(p[n-1][0]);
  assert(ani!=mappp.end());
  printf("%.9lf",(double)ani->SEC);
  return 0;
}
