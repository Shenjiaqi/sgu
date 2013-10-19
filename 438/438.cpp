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
int p[N+2][3];
int s[N+2];
int pp[N+2];
int qq[(N+2)*(N+2)*2+1][2],qoi;
int q[(N+2)*(N+2)*2+1][2];
int sp,tp;
void add(int f,int t)
{
  ++qoi,qq[qoi][0]=t,qq[qoi][1]=s[f],s[f]=qoi;
}
int bfs(int limit)
{
  queue<int> que;
  bool vis[N+2]={0};
  int frm[N+2][2];
  que.push(sp);
  vis[sp]=true;
  frm[sp][0]=-1;
  frm[sp][1]=pp[sp];
  int l(1);
  que.push(-1);
  for(;!que.empty() && !vis[tp] && l<=limit;)
    {
      int v=que.front();
      que.pop();
      if(v<0)
	{
	  ++l;
	  que.push(-1);
	}
      else
	for(int i=s[v];i;i=q[i][1])
	  {
	    int tmp=q[i][0];
	    if(!vis[tmp] && pp[tmp]>0)
	      {
		vis[tmp]=true;
		frm[tmp][0]=v;
		frm[tmp][1]=min(pp[tmp],frm[v][1]);
		que.push(tmp);
	      }
	  }
    }
  if(!vis[tp])
    return 0;
  for(int i=tp;i>=0;)
    {
      int pre=frm[i][0];
      pp[i]-=frm[tp][1];
      i=pre;
    }
  return frm[tp][1]*(limit-l+1);
}
bool test(int v)
{
  memcpy(q,qq,sizeof(qq[0])*(qoi+1));
  for(int i=0;i<n;++i)
    pp[i]=p[i][2];
  pp[sp]=m;
  pp[tp]=m;
  for(int left=m;left>0;)
    {
      int flow=bfs(v);
      if(flow<=0)
	return false;
      left-=flow;
    }
  return true;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d%d",&n,&m,&d,&w);
  for(int i=0;i<n;++i)
    scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);
  sp=n+1,tp=sp+1;
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      if(((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]))<=d*d)
	add(i,j),add(j,i);
  for(int i=0;i<n;++i)
    {
      if(p[i][1]<=d)
	add(sp,i);
      if(w-p[i][1]<=d)
	add(i,tp);
    }
  if(w<=d)
    add(sp,tp);
  int ans=-1;
  for(int f=0,l=N+1+(M-1);f<=l;)
    {
      int m=(f+l)>>1;
      if(test(m))
	l=m-1,ans=m;
      else f=m+1;
    }
  if(ans<0)
    cout<<"IMPOSSIBLE";
  else cout<<ans;
  return 0;
}
