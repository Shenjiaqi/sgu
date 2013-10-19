#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 100000
const double det=1e-13;
double xx0,yy0;
int p[N+3][2];
struct cmp
{
  bool operator()(const double &a,const double & b)
  {
    if(fabs(a-b)<det)
      return 0;
    return a<b;
  }
};
double calang(int v)
{
  double x=p[v][0],y=p[v][1];
  x-=xx0,y-=yy0;
  double tmp=atan2(y,x)*(double)180.0/acos(-1.0);
  /*double ttmp=acos(x/sqrt(x*x+y*y))*(double)180.0/acos(-1.0);
  if(y<0)
  ttmp=360.0-ttmp;*/
  if(tmp<0)
    tmp=360.0+tmp;
  //cout<<x<<' '<<y<<' '<<ttmp<<' '<<tmp<<endl;
  return tmp;
}
double len(int a,int b)
{
  double x=p[a][0]-p[b][0],y=p[a][1]-p[b][1];
  return sqrt(x*x+y*y);
}
ll calarea(int a,int b,int c)
{
  ll x1=p[a][0],x2=p[b][0],x3=p[c][0];
  ll y1=p[a][1],y2=p[b][1],y3=p[c][1];
  return llabs(x1*(y2-y3)+x3*(y1-y2)+x2*(y3-y1));
}
ll cross(ll x0,ll y0,ll x1,ll y1)
{
  return (x0*y1-x1*y0);
}
bool side(int v,int a,int b)
{
  double x1=p[a][0],y1=p[a][1];
  double x2=p[b][0],y2=p[b][1];
  double x=p[v][0],y=p[v][1];
  double tmp=((y2-y1)*(x-x1)-(x2-x1)*(y-y1));
  double tmp2=((y2-y1)*(xx0-x1)-(x2-x1)*(yy0-y1));
  return ((tmp>0 && tmp2<0) || (tmp<0 && tmp2>0));
}
int main()
{
  freopen("in","r",stdin);
  for(int i=0;i<3;++i)
    {
      scanf("%d%d",&p[i][0],&p[i][1]);
      xx0+=p[i][0],yy0+=p[i][1];
    }
  ll area=calarea(0,1,2);
  xx0/=3.0,yy0/=3.0;
  map<double,int,cmp> mapp;
  map<double,int,cmp>::iterator ite,ite1,ite2;
  for(int i=0;i<3;++i)
    mapp[calang(i)]=i;
  int n;
  scanf("%d",&n);
  for(int i=3;i<n+3;++i)
    {
      scanf("%d%d",&p[i][0],&p[i][1]);
      if(fabs((double)p[i][0]-xx0)<det && fabs((double)p[i][1]-yy0)<det)
	continue;
      double tmp=calang(i);
      ite1=ite2=ite=mapp.lower_bound(tmp);
      if(ite1==mapp.begin())
	ite1=mapp.end();
      --ite1;
      if(ite2==mapp.end())
	ite=ite2=mapp.begin();
      if(side(i,ite1->second,ite2->second))
	{
	  //cout<<'!'<<i<<' '<<p[i][0]<<' '<<p[i][1]<<' '<<ite1->second<<' '<<ite2->second<<endl;
	  area+=calarea(ite1->second,ite2->second,i);
	  for(;;)
	    {
	      int j=ite1->second;
	      ite2=ite1;
	      if(ite2==mapp.begin())
		ite2=mapp.end();
	      --ite2;
	      int k=ite2->second;
	      if(cross(p[k][0]-p[j][0],p[k][1]-p[j][1],p[i][0]-p[j][0],p[i][1]-p[j][1])>=0)
		{
		  area+=calarea(j,k,i);
		  mapp.erase(ite1);
		  ite1=ite2;
		}
	      else break;
	    }
	  for(;;)
	    {
	      int j=ite->second;
	      ite2=ite;
	      ++ite2;
	      if(ite2==mapp.end())
		ite2=mapp.begin();
	      int k=ite2->second;
	      if(cross(p[i][0]-p[j][0],p[i][1]-p[j][1],p[k][0]-p[j][0],p[k][1]-p[j][1])>=0)
		{
		  area+=calarea(i,j,k);
		  mapp.erase(ite);
		  ite=ite2;
		}
	      else break;
	    }
	  //cout<<'!'<<i<<' '<<tmp<<endl;
	  mapp[tmp]=i;
	}
      cout<<area<<'\n';
    }
  return 0;
}
