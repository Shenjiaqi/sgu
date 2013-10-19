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
#define N 300
struct ele
{
  int len,pre;
  double ang0,ang1;
}zz[N][N];
int seg[N][3];
int pos[N][2];
double ang[N][2];
int q[N],qoi;
int con[N][N];
const int inf=1e8;
const double det=1e-10;
double calang(int a,int b,int x,int y)
{
  int x1=pos[a][0]-x,y1=pos[a][1]-y;
  int x2=pos[b][0]-x,y2=pos[b][1]-y;
  double tmp=(double)180.0*acos((double)(x1*x2+y1*y2)/(sqrt((double)(x1*x1+y1*y1))*sqrt((double)(x2*x2+y2*y2))))/acos(-1.0);
  return (x1*y2-x2*y1<0?-tmp:tmp);
}
map<pair<int,int>,int> mappp;
void bt(int f,int t)
{
  if(zz[f][t].pre>=0)
    {
      bt(f,zz[f][t].pre);
      bt(zz[f][t].pre,t);
    }
  else q[qoi++]=mappp[make_pair(f,t)];
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  map<pair<int,int>,int> mapp;
  map<pair<int,int>,int>::iterator ite;
  int np=0;
  for(int i=0;i<n;++i)
    {
      int x1,y1,x2,y2,v;
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
      int f,t;
      ite=mapp.find(make_pair(x1,y1));
      if(ite==mapp.end())
	{
	  f=mapp[make_pair(x1,y1)]=np;
	  pos[f][0]=x1,pos[f][1]=y1;
	  ++np;
	}
      else f=ite->second;
      ite=mapp.find(make_pair(x2,y2));
      if(ite==mapp.end())
	{
	  t=mapp[make_pair(x2,y2)]=np;
	  pos[t][0]=x2,pos[t][1]=y2;
	  ++np;
	}
      else t=ite->second;
      seg[i][0]=f,seg[i][1]=t,seg[i][2]=v;
      mappp[make_pair(f,t)]=i;
      mappp[make_pair(t,f)]=i;
    }
  for(int i=0;i<np;++i)
    for(int j=0;j<np;++j)
      zz[i][j].len=inf;
  int gx0,gy0,gx1,gy1;
  scanf("%d%d%d%d",&gx0,&gy0,&gx1,&gy1);
  for(int i=0;i<n;++i)
    {
      int f=seg[i][0],t=seg[i][1];
      zz[f][t].len=zz[t][f].len=seg[i][2];
      ang[i][0]=zz[f][t].ang0=calang(f,t,gx0,gy0);
      ang[i][1]=zz[f][t].ang1=calang(f,t,gx1,gy1);
      zz[t][f].ang0=-zz[f][t].ang0;
      zz[t][f].ang1=-zz[f][t].ang1;
      zz[f][t].pre=zz[t][f].pre=-1;
      //cout<<ang[i][0]<<' '<<ang[i][1]<<endl;
    }
  for(int i=0;i<np;++i)
    for(int j=0;j<np;++j)
      if(i!=j && zz[j][i].len<inf)
	for(int k=0;k<np;++k)
	  if(i!=k && j!=k && zz[j][i].len+zz[i][k].len<zz[j][k].len)
	    {
	      zz[j][k].len=zz[j][i].len+zz[i][k].len;
	      //cout<<j<<' '<<k<<' '<<zz[j][k].len<<endl;
	      zz[j][k].pre=i;
	      zz[j][k].ang0=zz[j][i].ang0+zz[i][k].ang0;
	      zz[j][k].ang1=zz[j][i].ang1+zz[i][k].ang1;
	    }
  int ans=inf,ansi,ansj;
  for(int i=0;i<n;++i)
    {
	int f=seg[i][0],t=seg[i][1];
	for(int j=0;j<np;++j)
	  if(j!=f && j!=t)
	    {
	      int dif=seg[i][2]+zz[j][f].len+zz[j][t].len;
	      if(dif<ans)
		{
		  double ang0=fabs(zz[j][f].ang0+ang[i][0]-zz[j][t].ang0);
		  double ang1=fabs(zz[j][f].ang1+ang[i][1]-zz[j][t].ang1);
		  if(ang0<ang1)
		    swap(ang0,ang1);
		  //cout<<ang0<<' '<<ang1<<endl;
		  if(fabs(ang0-(double)360.0)<1.0 && ang1<1.0)
		    ans=dif,ansi=i,ansj=j;
	      }
	  }
    }
  printf("%d\n",ans);
  bt(ansj,seg[ansi][0]);
  bt(ansj,seg[ansi][1]);
  printf("%d\n",(1+qoi));
  for(int i=0;i<qoi;++i)
    printf("%d ",(1+q[i]));
  printf("%d",(ansi+1));
  return 0;
}
