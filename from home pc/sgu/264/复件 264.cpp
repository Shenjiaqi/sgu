#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
#define N 800
typedef pair<int,int> ppi;
char name[N*2][11];
char q[N*2][N][11];
int p[N*2][N*2];
int pp[N*2][N*2];
int in[N*2];
bool usd[N*2];
int s[N*2];
int path[N*N*2+1][2],pi;
bool vis[N*2];
int op[N*2];
void add(int f,int t)
{
  ++pi,path[pi][0]=t,path[pi][1]=s[f],s[f]=pi;
}
bool dfs(int v)
{
  for(int i=s[v];i;i=path[i][1])
    {
      int t=path[i][0];
      if(!vis[t])
	{
	  vis[t]=true;
	  if(op[t]<0 || dfs(op[t]))
	    {
	      op[op[t]=v]=t;
	      return true;
	    }
	}
    }
  return false;
}
int main()
{
  int n;
  scanf("%d",&n);
  map<string,int> mapm,mapf;
  for(int i=0;i<n*2;++i)
    {
      scanf("%s",name+i);
      string tmp(name[i]);
      if(i<n)
	mapm[tmp]=i;
      else mapf[tmp]=i;
      for(int j=0;j<n;++j)
	scanf("%s",*(q+i)+j);
    }
  for(int i=0;i<2*n;++i)
    for(int j=0;j<n;++j)
      {
	string tmp(q[i][j]);
	pp[i][p[i][j]=(i<n?mapf[tmp]:mapm[tmp])]=j;
      }
  vector<ppi> qq[2*N];
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      {
	int k=min(j,pp[p[i][j]][i]);
	qq[k].push_back(ppi(i,p[i][j]));
      }
  memset(op,1<<7,sizeof(op));
  for(int i=0,cnt=1;i<n;++i,++cnt)
    {
      memset(s,0,sizeof(s));
      pi=0;
      int na,nb;
      na=nb=0;
      for(int j=0;j<qq[i].size();++j)
	{
	  int a=qq[i][j].first,b=qq[i][j].second;
	  if(!usd[a] && !usd[b])
	    {
	      add(a,b);
	      add(b,a);
	      if(in[a]!=cnt)
		in[a]=cnt,++na;
	      if(in[b]!=cnt)
		in[b]=cnt,++nb;
	    }
	}
      if(na!=nb)
	{
	  printf("NO");
	  return 0;
	}
      for(int j=0;j<n;++j)
	if(in[j]==cnt)
	  {
	    memset(vis,0,sizeof(vis));
	    if(!dfs(j))
	      {
		printf("NO");
		return 0;
	      }
	  }
      for(int j=0;j<2*n;++j)
	if(in[j]==cnt)
	  usd[j]=true;
    }
  printf("YES");
  for(int i=0;i<n;++i)
    printf("\n%s %s",name[i],name[op[i]]);
  return 0;
}
