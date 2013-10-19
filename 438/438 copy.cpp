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
#define N 50
#define M 50
int n,m,d,w;
int p[N][3];
int sp,tp;
int q[((2*N+2)*(2*N+2))*2+1][4],qoi;
int s[N*2+2];
void add(int f,int t,int cap,int dis)
{
  ++qoi,q[qoi][0]=t,q[qoi][1]=cap,q[qoi][2]=dis,q[qoi][3]=s[f],s[f]=qoi;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d%d",&n,&m,&d,&w);
  for(int i=0;i<n;++i)
    scanf("%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2);
  sp=n*2;
  tp=sp+1;
  for(int i=0;i<n;++i)
    {
      if(p[i][1]<=d)
	add(sp,i*2,m,0),add(i*2,sp,0,0);
      if(w-p[i][1]<=d)
	add(i*2+1,tp,m,0),add(tp,2*i+1,0,0);
      add(i*2,i*2+1,p[i][2],1);
      add(2*i+1,2*i,0,-1);
      for(int j=i+1;j<n;++j)
	if(((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]))<=d*d)
	  add(i*2+1,j*2,m,0),add(2*j,2*i+1,0,0),
	    add(j*2+1,i*2,m,0),add(2*i,2*j+1,0,0);
    }
  if(w<=d)
    add(sp,tp,m,0),add(tp,sp,0,0);
  int ans=-1;
  int in[2*N+2];
  int distance[N*2+2];
  int from[N*2+2];
  int idx[N*2+2];
  int val[N*2+2];
  //queue<int> que;
  for(int sum=0,num=0,c=0;;++c)
    {
      //if(c>m)
      //break;
      //que.push(sp);
      memset(in,0,sizeof(in));
      memset(distance,1<<6,sizeof(distance));
      distance[sp]=0;//,in[sp]=true;
      val[sp]=m;
      /*  for(;!que.empty() && cc<(n*2+2)*(n*2+2);++cc)
	{
	  int v=que.front();
	  que.pop();
	  in[v]=false;
	  for(int i=s[v];i;i=q[i][3])
	    {
	      if(q[i][1]>0)
		{
		  int d=distance[v]+q[i][2];
		  int tmp=q[i][0];
		  if(d<distance[tmp])
		    {
		      distance[tmp]=d;
		      if(!in[tmp])
			que.push(tmp),in[tmp]=true,from[tmp]=v,idx[tmp]=i,val[tmp]=min(q[i][1],val[v]);
		    }
		}
	    }
	    }*/
      for(;!in[tp];)
	{
	  int minv,minp;
	  minv=n+1;
	  for(int i=tp;i>=0;--i)
	    if(!in[i] && minv>distance[i])
	      minv=distance[i],minp=i;
	  if(minv==1+n)
	    break;
	  in[minp]=1;
	  for(int i=s[minp];i;i=q[i][3])
	    if(q[i][1]>0)
	      {
		int t=q[i][0];
		if(!in[t])
		  {
		    int l=distance[minp]+q[i][2];
		    int c=min(q[i][1],val[minp]);
		    if(distance[t]>l || (distance[t]==l && c>val[t]))
		      distance[t]=l,val[t]=c,from[t]=minp,idx[t]=i;
		  }
	      }
	}
      if(distance[tp]>n+1)
	break;
      int l=0;
      for(int i=tp;i!=sp;i=from[i])
	{
	  q[idx[i]][1]-=val[tp];
	  q[(idx[i]&1)?idx[i]+1:idx[i]-1][1]+=val[tp];
	  l+=q[idx[i]][2];
	}
      //cout<<l<<' '<<val[tp]<<endl;
      sum+=l*val[tp];
      num+=val[tp];
      int z=(sum+m+num-1)/num;
      if(ans<0 || ans>z)
	ans=z;
    }
  if(ans<0)
    cout<<"IMPOSSIBLE";
  else cout<<ans;
  return 0;
}
