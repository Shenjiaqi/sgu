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
const double DET=(1e-13);
int pq[N][2];
double ang[N][N][2];
int nn[N];
bool forbid[N];
struct ele
{
  int len;
  int pre;
  double ang1;
  double ang2;
}zz[N][16];
bool in[N][16];
int s[N];
int p[N*2+1][4],poi;
int q[N+1],qoi;
double calang(int i,int j,int x,int y)
{
  int x1=pq[i][0]-x,y1=pq[i][1]-y;
  int x2=pq[j][0]-x,y2=pq[j][1]-y;
  double deg=(double)180.0*acos((double)(x1*x2+y1*y2)/(sqrt((double)(x1*x1+y1*y1))*(sqrt((double)(x2*x2+y2*y2)))))/acos(-1.0);
  if(x1*y2-x2*y1<0)
    return -deg;
  return deg;
}
void add(int f,int t,int v,int id)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=v,p[poi][3]=id,s[f]=poi;
}
void rec(int a,int b)
{
  if(zz[a][b].pre<0)
    return;
  q[qoi++]=(zz[a][b].pre)>>15;
  rec((zz[a][b].pre>>5)&((1<<10)-1),zz[a][b].pre&((1<<5)-1));
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  map<pair<int,int>,int> mapp;
  map<pair<int,int>,int>::iterator ite;
  int np(0);
  for(int i=0;i<n;++i)
    {
      int x1,y1,x2,y2,v,f,t;
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
      ite=mapp.find(make_pair(x1,y1));
      if(ite==mapp.end())
	f=mapp[make_pair(x1,y1)]=np,pq[np][0]=x1,pq[np][1]=y1,++np;
      else f=ite->second;
      ite=mapp.find(make_pair(x2,y2));
      if(ite==mapp.end())
	t=mapp[make_pair(x2,y2)]=np,pq[np][0]=x2,pq[np][1]=y2,++np;
      else t=ite->second;
      add(f,t,v,i);
      add(t,f,v,i);
    }
  int gx,gy,gx2,gy2;
  scanf("%d%d%d%d",&gx,&gy,&gx2,&gy2);
  for(int i=0;i<np;++i)
    {
      ang[i][i][0]=ang[i][i][1]=0.0;
      for(int j=i+1;j<np;++j)
	{
	  double deg=calang(i,j,gx,gy);
	  ang[i][j][0]=deg,ang[j][i][0]=-deg;
	  deg=calang(i,j,gx2,gy2);
	  ang[i][j][1]=deg,ang[j][i][1]=-deg;
	}
    }
  int ans=1e9;
  for(int i=0;i<np;++i)
    {
      memset(nn,0,sizeof(nn));
      memset(in,0,sizeof(in));
      in[i][0]=true;
      ++nn[i];
      zz[i][0].len=0,zz[i][0].pre=-1;
      zz[i][0].ang1=0,zz[i][0].ang2=0;
      queue<int> que;
      que.push(i<<5);
      for(;!que.empty();)
	{
	  int tmp=que.front();
	  que.pop();
	  int v=tmp>>5;
	  int j=tmp&((1<<5)-1);
	  in[v][j]=false;
	  for(int k=s[v];k;k=p[k][1])
	    {
	      int t=p[k][0];
	      if(forbid[t])
		continue;
	      double a1=zz[v][j].ang1+ang[v][t][0];
	      double a2=zz[v][j].ang2+ang[v][t][1];
	      if(fabs(a1)>(double)360.0+DET || fabs(a2)>(double)360.0+DET)
		continue;
	      int dis=zz[v][j].len+p[k][2];
	      int l=0;
	      for(;l<nn[t];++l)
		if(fabs(zz[t][l].ang1-a1)<DET && fabs(zz[t][l].ang2-a2)<DET)
		  break;
	      if(l>=nn[t] || dis<zz[t][l].len)
		{
		  if(l>16){
		    cout<<'!';return 1;}
		  if(l>=nn[t])
		    ++nn[t],zz[t][l].ang1=a1,zz[t][l].ang2=a2;
		  zz[t][l].len=dis;
		  zz[t][l].pre=tmp|(p[k][3]<<15);
		  if(!in[t][l])
		    {
		      que.push((t<<5)|l);
		      in[t][l]=true;
		    }
		}
	    }
	}
      for(int k=0;k<nn[i];++k)
	{
	  double tmp1,tmp2;
	  tmp1=max(fabs(zz[i][k].ang1),fabs(zz[i][k].ang2));
	  tmp2=min(fabs(zz[i][k].ang1),fabs(zz[i][k].ang2));
	  int kk=-1;
	  if(fabs(tmp1-(double)360.0)<DET && fabs(tmp2-(double)0.0)<DET)
	    if(ans>zz[i][k].len)
	      ans=zz[i][k].len,kk=k;
	  if(kk>=0)
	    qoi=0,rec(i,kk);
	}
      forbid[i]=true;
    }
  printf("%d\n%d\n",ans,qoi);
  for(int i=0;i<qoi;++i)
    printf("%d ",(1+q[i]));
  return 0;
}
