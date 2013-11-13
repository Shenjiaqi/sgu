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
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 10000
int p[N][2];
long double q0[N][3];
long double q[N][3];
int dir[N];
int n;
const long double det=1e-5;
void get_line(int l,long double d,long double &a,long double &b,long double &c)
{
  long double a0=q0[l][0],b0=q0[l][1],c0=q0[l][2];
  c=c0-dir[l]*d*sqrt(a0*a0+b0*b0);
  b=b0,a=a0;
}
bool get_poi(long double &x,long double &y,long double *l1,long double *l2)
{
  long double a,b,c,a_,b_,c_;
  a=l1[0],b=l1[1],c=l1[2];
  a_=l2[0],b_=l2[1],c_=l2[2];
  long double d=a*b_-a_*b;
  if(fabs(d)<det)
    return false;
  x=c_/d*b-c/d*b_;
  y=c/d*a_-c_/d*a;
  // x=(c_*b-c*b_)/d;
  // y=(c*a_-c_*a)/d;
  return true;
}
long double cross(long double x1,long double y1,long double x2,long double y2)
{
  return x1*y2-x2*y1;
}
long double dist(long double x,long double y,long double *l)
{
  long double a=l[0],b=l[1],c=l[2];
  return fabs(a*x+b*y+c)/sqrt(a*a+b*b);
}
int sig(long double x,long double y,long double *l)
{
  long double a=l[0],b=l[1],c=l[2];
  long double t=x*a+b*y+c;
  if(fabs(t)<1e-10)
    return 0;
  return t>0?1:-1;
}
bool out(long double x,long double y,int i,long double *l)
{
  return dir[i]!=sig(x,y,l);
}
bool test(long double r)
{
  int z[N+7],zf,zl;
  zf=zl=0;
  FOR(i,0,n)
    {
      for(;zl-zf>=2;)
	{
	  long double x,y;
	  if(!get_poi(x,y,q[z[zl-1]],q[z[zl-2]]))
	    ;//return false;
	  bool c=true;
	  if(out(x,y,i,q[i]))
	    --zl,c=false;
	  if(zl-zf>=2)
	    {
	      if(!get_poi(x,y,q[z[zf]],q[z[zf+1]]))
		;//return false;;
	      if(out(x,y,i,q[i]))
	  	++zf,c=false;
	    }
	  if(c)
	    break;
	}
      z[zl++]=i;
    }
  for(;zl-zf>2;)
    {
      bool c=true;
      long double x,y;
      for(;zl-zf>2;)
	{
	  if(get_poi(x,y,q[z[zf]],q[z[zf+1]]))
	    ;//return false;
	  if(out(x,y,z[zl-1],q[z[zl-1]]))
	    ++zf,c=false;
	  else break;
	}
      for(;zl-zf>2;)
	{
	  if(!get_poi(x,y,q[z[zl-1]],q[z[zl-2]]))
	    ;//return false;
	  if(out(x,y,z[zf],q[z[zf]]))
	    --zl,c=false;
	  else break;
	}
      if(c)
	break;
    }
  if(zl-zf<2)
    return false;
  //return zl-zf>2;
  long double xx(0.0),yy(0.0);
  get_poi(xx,yy,q[z[zf]],q[z[zl-1]]);
  FOR(i,0,n)
    if(sig(xx,yy,q0[i])!=dir[i] || (dist(xx,yy,q0[i])<r-det))
      return false;
  return true;
}
int main()
{
  scanf("%d",&n);
  long double xx,yy;
  xx=yy=0.0;
  int mx,my,mix,miy;
  my=mx=-1e9,mix=miy=1e9;
  FOR(i,0,n)
    {
      scanf("%d%d",*(p+i),*(p+i)+1);
      mx=max(mx,p[i][0]),my=max(my,p[i][1]);
      mix=min(mix,p[i][0]),miy=min(miy,p[i][1]);
      xx+=p[i][0];
      yy+=p[i][1];
    }
  xx/=(long double)n,yy/=(long double)n;
  FOR(i,0,n)
    {
      long double x0=p[i][0],y0=p[i][1];
      long double x1=p[(i+1)%n][0],y1=p[(i+1)%n][1];
      long double a=y1-y0,b=x0-x1;
      long double c=-a*x0-b*y0;
      q0[i][0]=a,q0[i][1]=b,q0[i][2]=c;
      dir[i]=sig(xx,yy,q0[i]);
    }
  long double ans=min(mx-mix,my-miy)/(long double)2.0+1;
  for(long double f=0.0,t=ans;t-f>det;)
    {
      long double m=(f+t)/(long double)2.0;
      FOR(i,0,n)
	get_line(i,m,q[i][0],q[i][1],q[i][2]);
      if(test(m))
	f=m,ans=m;
      else t=m;
    }
  printf("%lf\n",(double)ans);
  return 0;
}
