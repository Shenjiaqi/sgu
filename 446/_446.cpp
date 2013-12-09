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
#define pb push_back
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 1007
const double mag=1e8;
const double eps=1e-7;
int n;
ll p1[N][2],p2[N][2];
void rd(ll p[][2])
{
  ll x,y;
  x=y=0;
  FOR(i,0,n)
    {
      double a,b;
      scanf("%lf%lf",&a,&b);
      x+=(p[i][0]=(ll)(a*mag));
      y+=(p[i][1]=(ll)(b*mag));
    }
  x/=n,y/=n;
  FOR(i,0,n)
    p[i][0]-=x,
    p[i][1]-=y;
}
ll dis(ld x,ld y)
{
  return (ll)sqrt(x*x+y*y);
}
ld ang(ll x,ll y)
{
  // if(x==0)
  //   {
  //     if(y==0)
  // 	return 0;
  //     ld r= acosl((ld)-1.0)/(ld)2.0;
  //     if(y<0)
  // 	return -r;
  //     return r;
  //   }
  return atan2l((ld)y,(ld)x);
}
int cmp(const void *a,const void *b)
{
  ll *c=(ll*)a,*d=(ll*)b;
  ll x1=*c,x2=*d;
  ++c,++d;
  ll y1=*c,y2=*d;
  ld a1=ang(x1,y1);
  ld a2=ang(x2,y2);
  if(fabsl(a1-a2)<eps)
    {
      ll d1=dis(x1,y1);
      ll d2=dis(x2,y2);
      return d1-d2;
    }
  return a1<a2?-1:1;
}
int main()
{
  scanf("%d",&n);
  rd(p1);
  qsort(p1,n,sizeof(p1[0]),cmp);
  rd(p2);
  qsort(p2,n,sizeof(p2[0]),cmp);
  for(int i=0;i<n;++i)
    cout<<p1[i][0]<<' '<<p1[i][1]<<' '<<ang(p1[i][0],p1[i][1])<<endl;
  for(int i=0;i<n;++i)
    cout<<p2[i][0]<<' '<<p2[i][1]<<' '<<ang(p2[i][0],p2[i][1])<<endl;
  double ans=1e100;
  for(int i=0;i<n;++i)
    {
      ll d1=dis(p1[i][0],p1[i][1]);
      if(d1>0)
	{
	  for(int j=0;j<n;++j)
	    {
	      ll d2=dis(p2[j][0],p2[j][1]);
	      ld dang=ang(p1[i][0],p1[i][1])-ang(p2[j][0],p2[j][1]);
	      // if(i==0 && j==2)
	      // 	cout<<d1<<' '<<d2<<endl;
	      if(d2==d1 && fabsl(dang)<ans)
		{
		  int k=1;
		  for(;k<n;++k)
		    {
		      int ii=(i+k)%n;
		      int jj=(j+k)%n;
		      ld dang2=ang(p1[ii][0],p1[ii][1])-
			ang(p2[jj][0],p2[jj][1]);
		      if(fabsl(dang-dang2)>eps)
			break;
		    }

		  if(i==0 && j==2)
		    cout<<k<<endl;
		  if(k>=n)
		    ans=fabsl(dang);
		}
	    }
	  break;
	}
    }
  if(ans>10)
    printf("0");
  else printf("%.7lf",min((double)ans,acos(-1)-1e-7));
  return 0;
}
