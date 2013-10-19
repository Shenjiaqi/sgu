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
#define N 1000
#define M 1000
int n,m;
int q[M*2+1][2],qoi;
int s[N+1];
int dis[N+1];
int re[N+1];
void add(int f,int t)
{
  ++qoi,q[qoi][0]=t,q[qoi][1]=s[f],s[f]=qoi;
}
bool dfs(int v)
{
  if(re[v]==0)
    {
      for(int i=s[v];i;i=q[i][1])
	if(dis[q[i][0]]==dis[v]+1 && !dfs(q[i][0]))
	  {
	    re[v]=1;
	    break;
	  }
      if(re[v]==0)
	re[v]=2;
    }
  return (re[v]==1);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      add(f,t),add(t,f);
    }
  queue<int> que;
  que.push(1);
  dis[1]=1;
  for(;!que.empty();)
    {
      int v=que.front();
      que.pop();
      for(int i=s[v];i;i=q[i][1])
	{
	  int tmp=q[i][0];
	  if(dis[tmp]==0)
	    {
	      dis[tmp]=dis[v]+1;
	      que.push(tmp);
	    }
	}
    }
  cout<<(dfs(1)?"Vladimir":"Nikolay");
  return 0;
}
