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
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 1007
const ld eps=(1e-7);
const ld det=1e-5;
ld p1[N][2],p2[N][2];
int n;
void rd(ld p[][2])
{
  ld x1,y1;
  x1=y1=0.0;
  FOR(i,0,n)
    {
      double x,y;
      scanf("%lf%lf",&x,&y);
      x1+=x;
      y1+=y;
      p[i][0]=x,p[i][1]=y;
    }
  x1/=(ld)n;
  y1/=(ld)n;
  FOR(i,0,n)
    p[i][0]-=x1,p[i][1]-=y1;
}
ld dis(ld x1,ld y1,ld x2,ld y2)
{
  x1-=x2;
  y1-=y2;
  return sqrt(x1*x1+y1*y1);
}
int cmp(const void * a,const void *b)
{
  ld *c=(ld*)a,*d=(ld*)b;
  ld x1=*c,x2=*d;
  ++c,++d;
  ld y1=*c,y2=*d;
  ld da=dis(x1,y1,0,0);
  ld db=dis(x2,y2,0,0);
  if(da<det || db<det)
    {
      if(fabsl(da-db)<det)
  	return 0;
      return da<db?-1:1;
    }
  if(fabsl(y1)<det)
    y1=0;
  if(fabsl(y2)<det)
    y2=0;
  ld aga=atan2l(y1,x1);
  ld agb=atan2l(y2,x2);
  if(fabsl(aga-agb)>eps)
    return aga<agb?-1:1;
  if(fabsl(da-db)<det)
    return 0;
  return da<db?-1:1;
}
ld angle(ld a[2],ld b[2])
{
  ld r=a[0]*b[0]+a[1]*b[1];
  ld dd=(dis(a[0],a[1],0,0)*dis(b[0],b[1],0,0));
  r/=dd;
  r=acosl(r);
  ld c=(a[0]*b[1]-a[1]*b[0])/dd;
  if(c<=det)
    r=-r;
  return r;
}
bool check(int i,int j,int k,ld cs)
{
  int ii=(i+k+n)%n;
  int jj=(j+k+n)%n;
  ld dd1=dis(p1[ii][0],p1[ii][1],0,0);
  ld dd2=dis(p2[jj][0],p2[jj][1],0,0);
  // if(i==0 && j==2)
  //   cout<<dd1<<' '<<dd2<<' '<<fabsl(dd1-dd2)<<' '<<k<<endl;
  if(fabsl(dd1-dd2)>det)
    return false;
  ld ccs=angle(p1[ii],p2[jj]);
      // if(i==0 && j==2)
      // 	{
      // 	  cout<<cs<<' '<<ccs<<endl;
      // 	  cout<<ang(p1[i][0],p1[i][1])<<' '<<ang(p2[j][0],p2[j][1])<<endl;
      // 	  cout<<ang(p1[ii][0],p1[ii][1])<<' '<<ang(p2[jj][0],p2[jj][1])<<endl;
      // 	}
  if(fabsl(cs-ccs)>eps)
    return false;
  return true;
}
int main()
{
  scanf("%d",&n);
  rd(p1);
  qsort(p1,n,sizeof(p1[0]),cmp);
  rd(p2);
  qsort(p2,n,sizeof(p2[0]),cmp);
  // FOR(i,0,n)
  //   cout<<p1[i][0]<<' '<<p1[i][1]<<endl;
  // FOR(i,0,n)
  //   cout<<p2[i][0]<<' '<<p2[i][1]<<endl;
  ld ans=1e10;
  FOR(i,0,n)
    {
      ld d1=dis(p1[i][0],p1[i][1],0,0);
      if(d1>det)
	{
	  FOR(j,0,n)
	    {
	      ld d2=dis(p2[j][0],p2[j][1],0,0);
	      if(d2>det)
		{
		  ld cs=angle(p1[i],p2[j]);
		  if(fabsl(cs)>=ans)
		    break;
		  int k=1;
		  for(;k<n;++k)
		    {
		      if(!check(i,j,k,cs))
			break;
		    }
		  if(k>=n)
		    ans=min(ans,fabsl(cs));

		}
	    }
	  break;
	}
    }
  if(ans>100)
    printf("0");
  else printf("%.7lf",min((double)ans,(double)acosl(-1.0)-1e-7));
  return 0;
}
