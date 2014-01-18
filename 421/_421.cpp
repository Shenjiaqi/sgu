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
int n,m,k;
int a[N];
int ntag;
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
inline bool cmpabs(int a,int b)
{
  a=abs(a),b=abs(b);
  if(a==b)
    return false;
  return ((abs(a)<abs(b))^ntag);
}
const ld eps=1e-13;
typedef pair<ld,int> pli;
struct cmpp
{
  bool operator()(const pli &v1,const pli &v2) const
  {
    if(fabsl(v1.first-v2.first)<eps)
      return v1.second>v2.second;
    return ((v1.first>v2.first)^ntag);
  };
};
struct el
{
  ld val;
  ld preval;
  int lev;
  vector<int> lst;
  int precol;
  map<pli,int,cmpp>::iterator ite1;
};
struct cmpel
{
  bool operator()(const el &e1,const el &e2) const
  {
    if(fabsl(e1.val-e2.val)<eps)
      {
	if(e1.lev==e2.lev)
	  {
	    if(e1.precol==e2.precol)
	      return e1.ite1->first.second>e2.ite1->first.second;
	    return e1.precol>e2.precol;
	  }
	return e1.lev>e2.lev;
      }
    return ((e1.val>e2.val)^ntag);
  };
};
typedef long long ll;
ll base=1e9;
typedef vector<int> bn;
void prt(bn &v)
{
  int i=v.size()-1;
  if(i<0)
    printf("0");
  printf("%d",v[i]);
  for(--i;i>=0;--i)
    printf("%09d",v[i]);
}
void mul(bn &v,ll a)
{
  for(;v.size()>0 && v[v.size()-1]==0;)
    v.pop_back();
  ll carry=0;
  for(int i=0,j=v.size();i<j;++i)
    {
      carry+=(ll)v[i]*a;
      v[i]=carry%base;
      carry/=base;
    }
  if(carry>0)
    v.push_back(carry);
}
map<pli,int,cmpp> mapp[M][2];
map<pli,int,cmpp>::iterator itee[M][N][2],ite;
void pt(const el & z)
{
  bn val;
  val.push_back(1);
  for(int i=0;i<z.lst.size();++i)
    mul(val,z.lst[i]);
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
}
void calpos()
{
  sort(a,a+n,cmpabs);
  for(int i=0;i<n;++i)
    {
      int t=a[i]>=0?0:1;
      mapp[0][t][pli(fabsl(a[i]),i)]=t;
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
	    if(ite!=mapp[i-1][h].end())
	      {
		mapp[i][t^h][pli(ite->first.first*fabsl(a[j]),j)]=t^h;
	      }
	  }
	for(int h=0;h<2;++h)
	  itee[i][j][h]=mapp[i][h].begin();
      }
  for(typeof(mapp[0][1].begin()) i=mapp[0][1].begin();i!=mapp[0][1].end();++i)
    cout<<i->second<<' '<<i->first.first<<endl;
  map<el,int,cmpel> que;
  el tmp;
  tmp.ite1=mapp[m-1][ntag].begin();
  tmp.val=tmp.ite1->first.first;
  tmp.preval=1;
  tmp.lev=m-1;
  int col=tmp.ite1->first.second;
  tmp.precol=n;
  // cout<<tmp.val<<endl;
  que[tmp]=1;
  for(;--k;)
    {
      tmp=que.begin()->first;
      cout<<k<<' '<<tmp.val<<endl;
      for(;;)
	{
	  typeof(ite) ii=tmp.ite1;
	  for(++ii;ii!=mapp[tmp.lev][tmp.ite1->second].end() && 
		ii->first.second>=tmp.precol;)
	    {
	      typeof(ii) iii=ii++;
	      mapp[tmp.lev][tmp.ite1->second].erase(iii);
	    }
	  if(ii!=mapp[tmp.lev][tmp.ite1->second].end())
	    {
	      el z=tmp;
	      z.val=z.preval*ii->first.first;
	      cout<<"!"<<tmp.lev<<' '<<z.val<<' '<<z.precol<<' '<<ii->first.first<<' '<<
	      	ii->first.second<<' '<<ii->second<<' '<<a[ii->first.second]<<endl;
	      z.ite1=ii;
	      que[z]=1;
	    }
	  if(tmp.lev>0)
	    {
	      tmp.precol=tmp.ite1->first.second;
	      tmp.preval*=fabsl(a[tmp.precol]);
	      tmp.lst.push_back(abs(a[tmp.precol]));
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
  pt(que.begin()->first);
}
void calneg()
{
  int i=0;
  for(int j=0;j<n;++j)
    if(a[j]!=0)
      a[i]=a[j],++i;
  n=i;
  ntag=1;
  printf("-");
  calpos();
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d",&n,&m,&k);
  assert(m<=n);
  int nneg=0;
  for(int i=0;i<n;++i)
    {
      scanf("%d",a+i);
      if(a[i]<0)
	++nneg;
    }
  if(cntp(n-nneg,nneg))
    calpos();
  else calneg();
  return 0;
}
