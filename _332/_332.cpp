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
long double p[N][2];
long double q0[N][3];
long double q[N][3];
int dir[N];
const long double det=1e-11;
int n;
void get_line(long double a[],long double b[],long double c[])
{
  long double x=a[0],y=a[1];
  long double u=b[0],v=b[1];
  c[0]=y-v,c[1]=u-x;
  c[2]=-(c[0]*x+y*c[1]);
}
int sig(long double x,long double y,long double l[])
{
  long double r=x*l[0]+y*l[1]+l[2];
  if(fabs(r)<det)
    return 0;
  return r>0?1:-1;
}
void sh(long double t[],long double f[],long double r)
{
  FOR(i,0,3)
    t[i]=f[i];
  t[2]-=r*sqrt(t[0]*t[0]+t[1]*t[1]);
}
long double cr(long double a,long double b,long double c,long double d)
{
  return a*d-c*b;
}
bool get_poi(long double &x,long double &y,long double l1[],long double l2[])
{
  long double d=cr(l1[0],l1[1],l2[0],l2[1]);
  if(fabs(d)<det)
    return false;
  long double a=cr(-l1[2],l1[1],-l2[2],l2[1]);
  long double b=cr(l1[0],-l1[2],l2[0],-l2[2]);
  x=a/d,y=b/d;
  return true;
}
bool out(long double x,long double y,int d,long double *l)
{
  return (d && d!=sig(x,y,l));
}
int z[N],zf,zl;
void pl(long double l[])
{
	{
	  FOR(j,0,3)
	    cout<<l[j]<<' ';
	  cout<<endl;
	}
}
bool test(long double r)
{
  zf=0,zl=-1;
  FOR(i,0,n)
    {
      long double x,y;
      for(;zl-zf>=1;)
	{
	  if(!get_poi(x,y,q[z[zl]],q[z[zl-1]]))
	    return false;
	  if(out(x,y,dir[i],q[i]))
	    --zl;
	  else break;
	}
      for(;zl-zf>=1;)
	{
	  if(!get_poi(x,y,q[z[zf]],q[z[zf+1]]))
	    return false;
	  if(out(x,y,dir[i],q[i]))
	    ++zf;
	  else break;
	}
      z[++zl]=i;
    }
  for(;zl-zf>=2;)
    {
      long double x,y;
      int a=zl,b=zf;
      for(;zl-zf>=2;)
	{
	  if(!get_poi(x,y,q[z[zl]],q[z[zl-1]]))
	    return false;
	  if(out(x,y,dir[z[zf]],q[z[zf]]))
	    ++zf;
	  else break;
	}
      for(;zl-zf>=2;)
	{
	  if(!get_poi(x,y,q[z[zf]],q[z[zf+1]]))
	    return false;
	  if(out(x,y,dir[z[zl]],q[z[zl]]))
	    --zl;
	  else break;
	}
      if(a==zl && b==zf)
	break;
    }
  return zl-zf>=2;
}
int main()
{
  long double x,y;
  long double mx,my,mix,miy;
  mx=my=-1e9;
  mix=miy=1e9;
  x=y=0;
  scanf("%d",&n);
  FOR(i,0,n)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      p[i][0]=a,p[i][1]=b;
      x+=p[i][0],y+=p[i][1];
      mx=max(mx,p[i][0]);
      my=max(my,p[i][1]);
      mix=min(mix,p[i][0]);
      miy=min(miy,p[i][1]);
    }
  x/=n,y/=n;
  FOR(i,0,n)
    {
      get_line(p[i],p[(i+1)%n],q0[i]);
      dir[i]=sig(x,y,q0[i]);
    }
  long double ans=0.0;
  for(long double f=0,t=min(mx-mix,my-miy)/2.0+1;t-f>det;)
    {
      long double m=(f+t)/2.0;
      FOR(i,0,n)
	sh(q[i],q0[i],m*dir[i]);
      if(test(m))
	ans=f=m;
      else t=m;
    }
  printf("%lf",(double)ans);
  return 0;
}
