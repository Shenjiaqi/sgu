#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define M (200000)
#define N (2000)
int p[M*2+1][3],poi;
int s[N+1];
int path[M][3];
void add(int x,int y,int l)
{
  ++poi,p[poi][0]=y,p[poi][1]=l,p[poi][2]=s[x],s[x]=poi;
}
bool in[N+1];
int p1[N+1],p2[N+1],p3[N+1];
void sr(int st,int a[])
{
  queue<int> que;
  que.push(st);
  memset(a,-1,sizeof(p1));
  a[st]=0;
  in[st]=true;
  for(;!que.empty();)
    {
      int v=que.front();
      for(int c=s[v];c;c=p[c][2])
	{
	  int pp=p[c][0];
	  if(a[pp]<0 || a[pp]>a[v]+p[c][1])
	    {
	      a[pp]=a[v]+p[c][1];
	      if(!in[pp])
		{
		  que.push(pp);
		  in[pp]=true;
		}
	    }
	}
      que.pop();
      in[v]=false;
    }
}
int a1[N*2+1];//,a2[N*2+1];
void ad(int v,int m,int val)
{
  for(int i=v;i<=m;i+=(i&(-i)))
    a1[i]+=val;
}
int que(int v)
{
  int r=0;
  for(;v;v-=(v&(-v)))
    r+=a1[v];
  return r;
}
int ans[N*2+1];
bool added[N*2+1];
int main()
{
  freopen("in.txt","r",stdin);
  int n,x,y;
  cin>>n>>x>>y;
  int m;
  cin>>m;
  for(int i=0;i<m;++i)
    {
      int xi,yi,li;
      scanf("%d%d%d",&xi,&yi,&li);
      add(xi,yi,li);
      add(yi,xi,li);
      path[i][0]=xi,path[i][1]=yi,path[i][2]=li;
    }
  sr(x,p1);
  sr(y,p2);
  for(int i=1;i<=n;++i)
    p3[i]=p1[i]+p2[i];
  int smin=p1[y];
  map<int,int> mapp;
  map<int,int>::iterator ite;
  for(int i=1;i<=n;++i)
    {
      mapp[p1[i]]=0;
      mapp[p3[i]]=0;
    }
  ite=mapp.begin();
  for(int i=0;ite!=mapp.end();++ite)
    ite->second=++i;
  int mn=mapp.size();
  for(int i=0;i<m;++i)
    {
      int xi=path[i][0],yi=path[i][1],li=path[i][2];
      if(p3[xi]==smin && p3[yi]==smin)
	{
	  if(p1[xi]+li==p1[yi])
	    {
	      ad(1+mapp[p1[xi]],mn,1);
	      ad(mapp[p1[yi]],mn,-1);
	    }
	  else if(p1[yi]+li==p1[xi])
	    {
	      ad(1+mapp[p1[yi]],mn,1);
	      ad(mapp[p1[xi]],mn,-1);
	    }
	}
    }
  for(int i=1;i<=n;++i)
    {
      if(p3[i]==smin)
	{
	  int tmp=mapp[p1[i]];
	  ++ans[tmp];
	  if(!added[tmp])
	    {
	      ans[tmp]+=(que(tmp));//-que(tmp,a2));
	      added[tmp]=true;
	    }
	}
    }
  for(int i=1;i<=n;++i)
    if(p3[i]==smin)
      {
	int tmp=mapp[p1[i]];
	//cout<<'!'<<ans[tmp]<<' '<<add[tmp]<<endl;
	cout<<(ans[tmp])<<' ';
      }
    else cout<<0<<' ';
  return 0;
}
