#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> pp;
#define N 4007
#define M 100007
int s[N];
int p[M*2+1][4],pi;
int q[N][3],qi;
int idx[N];
vector<pp> z[N];
int ans[N];
int lst[N],li[N];
void add(int f,int t,int len,int v)
{
  ++pi,p[pi][0]=t,p[pi][1]=s[f],s[f]=pi,p[pi][2]=len,p[pi][3]=v;
}
void dfs(int v,int frm,int d)
{
  q[v][0]=d;
  q[v][1]=qi;
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(t!=frm && p[i][3]==1)
	dfs(t,v,d+p[i][2]);
    }
  q[v][2]=qi++;
}
void dfs2(int v,int frm)
{
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(t!=frm && p[i][3]==1)
	dfs2(t,v);
    }
  int a=q[v][1],b=q[v][2];
  li[v]=v;
  int last=v;
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(t!=frm && p[i][3]==1)
	{
	  int k=li[t];
	  for(;k;k=lst[k])
	    {
	      for(;idx[k]<z[k].size();++idx[k])
		{
		  int id=q[z[k][idx[k]].second][2];
		  if(id<a || id>b)
		    {
		      ans[v]=min(ans[v],z[k][idx[k]].first+q[k][0]-q[v][0]);
		      lst[last]=k;
		      last=k;
		      break;
		    }
		}
	    }
	}
    }
  lst[last]=0;
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      int id1=q[t][2];
      if(id1<a || id1>b)
	{
	  if(!(t==frm && p[i][3]==1))
	    {
	      ans[v]=min(ans[v],q[t][0]+p[i][2]);
	    }
	}
    }
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t,l,v;
      scanf("%d%d%d%d",&f,&t,&l,&v);
      add(f,t,l,v);
      add(t,f,l,v);
    }
  dfs(1,0,0);
  for(int i=1;i<=n;++i)
    {
      for(int j=s[i];j;j=p[j][1])
	{
	  int t=p[j][0];
	  z[i].push_back(pp(q[t][0]+p[j][2],t));
	}
      sort(z[i].begin(),z[i].end());
    }
  memset(ans,1<<6,sizeof(ans));
  int inf=ans[0];
  dfs2(1,0);
  for(int i=2;i<=n;++i)
    printf("%d ",inf<=ans[i]?-1:ans[i]);
  return 0;
}
