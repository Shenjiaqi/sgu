#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
#define N (80)
#define DET (1e-13)
#define PI (3.1415927)
#define MINA (1e-8)
typedef pair<double,double> pp;
typedef pair<pp,pp> ele;
void pr(ele x)
{
  pp a=x.first;
  pp b=x.second;
  printf("%lf %lf %lf %lf\n",a.first,a.second,b.first,b.second);
}
bool equ(const pp &a,const pp &b)
{
#define ER (1e-5)
  if(fabs(a.first-b.first)>ER)
    return 0;
  return fabs(a.second-b.second)<ER;
}
double angle(const pp &a,const pp &b)
{
  if(equ(a,b))
    return 0;
  double x=b.first-a.first,y=b.second-a.second;
  double tmp=acos(x/sqrt(x*x+y*y));
  if(y<0)
    tmp=(double)2.0*PI-tmp;
  return tmp;
}
struct cmp
{
  bool operator()(const ele &a,const ele &b)
  {
    if(!equ(a.first,b.first))
      return a.first<b.first;
    double a1=angle(a.first,a.second);
    double a2=angle(b.first,b.second);
    //if(fabs(a1-a2)<DET)return a.second<b.second;
    return a1+DET<a2;
  }
};
map<ele,int,cmp> mapp;
int n;
int line[N][4];
bool cross(int a,int b,double &x,double &y)
{
  double x1=line[a][3]-line[a][1],x2=line[a][0]-line[a][2];
  double x3=line[a][0]*x1+line[a][1]*x2;
  double y1=line[b][3]-line[b][1],y2=line[b][0]-line[b][2];
  double y3=line[b][0]*y1+line[b][1]*y2;
  double tmp=x1*y2-x2*y1;
  x=x3*y2-y3*x2;
  y=x1*y3-x3*y1;
  if(fabs(tmp)<DET)
    return 0;
  x=x/tmp;
  y=y/tmp;
  return 1;
}
bool check(pp a,pp b,pp c)
{
  double x1=b.first-a.first,y1=b.second-a.second;
  double x2=c.first-a.first,y2=c.second-a.second;
  return x1*y2-x2*y1>0;
}
bool getnele(const ele &in,ele & out)
{
  map<ele,int,cmp>::iterator ite;
  ite=mapp.upper_bound(ele(in.second,in.first));
  if(ite==mapp.end() || !equ((*ite).first.first,in.second))
    ite=mapp.lower_bound(ele(in.second,in.second));
  if(ite==mapp.end() || !equ((*ite).first.first,in.second))
    return 0;
  out=(*ite).first;
  if(!check(in.second,in.first,out.second))
    return 0;
  return 1;
}
double calarea(const pp &a,const pp &b,const pp &c)
{
  double x1=b.first-a.first,y1=b.second-a.second;
  double x2=c.first-a.first,y2=c.second-a.second;
  return ((double)0.5*fabs(x1*y2-y1*x2));
}
double cal(ele t)
{
  pp r=t.first;
  double area(0.0);
  mapp.erase(t);
  for(int i=0;;++i)
    {
      ele tmp;
      if(!getnele(t,tmp))
	return 0;
      if(equ(tmp.second,r))
	{
	  if(i>0)
	    mapp.erase(tmp);
	  break;
	}
      t=tmp;
      mapp.erase(t);
      area+=calarea(r,t.first,t.second);
    }
  return area;
}
int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d%d%d%d",*(line+i),*(line+i)+1,*(line+i)+2,*(line+i)+3);
  /*for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      {
	double x,y;
	if(i!=j && !cross(i,j,x,y))
	  {
	    if(fabs(x)<DET && fabs(y)<DET)
	      ;//return 1;
	  }
	  }*/
  for(int i=0;i<n;++i)
    {
      vector<pp> point;
      double x,y;
      for(int j=0;j<n;++j)
	if(i!=j && cross(i,j,x,y))
	  point.push_back(pp(x,y));
      sort(point.begin(),point.end());
      vector<pp>::iterator ite=unique(point.begin(),point.end(),equ);
      point.resize(ite-point.begin());
      int size=point.size();
      for(int j=0;j<size-1;++j)
	mapp[ele(point[j],point[j+1])]=1,mapp[ele(point[j+1],point[j])]=1;
    }
  vector<double>area;
  for(;!mapp.empty();)
    {
      ele t=(*mapp.begin()).first;
      double tmp=cal(t);
      //printf("\n");
      if(tmp>MINA)
	area.push_back(tmp);
    }
  sort(area.begin(),area.end());
  int size=area.size();
  printf("%d\n",size);
  for(int i=0;i<size;++i)
    printf("%.4lf\n",area[i]);
  return 0;
}
