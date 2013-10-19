#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 1507
#define M 300007
int lev[N+1];
ll p[M+1][5],poi;
int s[N+1];
int c[N+1];
ll cap[N+1];
int source,target;
bool in[N+1];
queue<int> que[N+1];
void dfs(int l)
{
  if(l==lev[target])
    {
      in[target]=false;
      que[l].pop();
      cap[target]=0;
      return ;
    }
  que[l].push(0);
  for(;que[l].size()>1;)
    {
      for(;;)
	{
	  int v=que[l].front();
	  que[l].pop();
	  que[l].push(v);
	  if(v==0)
	    break;
	  c[v]=s[v];
	  int i;
	  for(i=s[v];cap[v] && i;i=p[i][2])
	    {
	      int t=p[i][0];
	      ll tmp=min(p[i][1],cap[v]);
	      cap[v]-=tmp;
	      cap[t]+=tmp;
	      p[i][3]+=tmp;
	      p[i][1]-=tmp;
	      p[i][4]=tmp;
	      if(!in[t])
		que[l+1].push(t),in[t]=true;
	      if(cap[v]<=0)
		break;
	    }
	  s[v]=i;
	}
      dfs(l+1);
      for(;;)
	{
	  int v=que[l].front();
	  que[l].pop();
	  if(v==0)
	    {
	      que[l].push(0);
	      break;
	    }
	  for(int i=c[v];i;i=p[i][2])
	    {
	      int t=p[i][0];
	      ll tmp=min(p[i][4],cap[t]);
	      if(tmp>0)
		{
		  p[i][3]-=tmp;
		  p[i][1]+=tmp;
		  cap[v]+=tmp;
		  cap[t]-=tmp;
		}
	      if(i==s[v])
		{
		  if((tmp>0 || p[i][1]==0) && s[v])
		    s[v]=p[i][2];
		  break;
		}
	    }
	  if(cap[v]>0 && s[v]>0)
	    que[l].push(v);
	  else in[v]=false;
	}
    }
  que[l].pop();
}
int main()
{
  freopen("in","r",stdin);
  int n,m,l;
  scanf("%d%d%d",&n,&m,&l);
  for(int i=1;i<=n;++i)
    scanf("%d",lev+i);
  for(int i=0,f,t,c;i<m;++i)
    {
      scanf("%d%d%d",&f,&t,&c);
      ++poi,p[poi][0]=t,p[poi][1]=c,p[poi][2]=s[f],s[f]=poi;
    }
  for(int i=1;i<=n;++i)
    if(lev[i]==1)
      source=i;
    else if(lev[i]==l)
      target=i;
  cap[source]=1e17;
  in[source]=true;
  que[1].push(source);
  dfs(1);
  for(int i=1;i<=poi;++i)
    printf("%d\n",(int)p[i][3]);
  return 0;
}
