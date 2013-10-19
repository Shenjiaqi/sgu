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
#define N 60
#define M 400
int p[M][2];
int q[N*2+1][3],qoi;
int s[M+1];
int cost[M];
int a[N];
int b[M];
bool vis[M];
int slk;
int pp[M][M];
int opo[M];
int n,m;
void add(int f,int t,int v)
{
  ++qoi,q[qoi][0]=t,q[qoi][1]=s[f],q[qoi][2]=v,s[f]=qoi;
}
bool df(int f,int t,int v)
{
  if(vis[f])
    return false;
  vis[f]=true;
  for(int i=s[f];i;i=q[i][1])
    if(q[i][0]==t || df(q[i][0],t,v))
      {
	pp[q[i][2]][v]=pp[v][q[i][2]]=max(cost[q[i][2]]-cost[v],0);
	return true;
      }
  return false;
}
bool dfs(int v)
{
  vis[v]=true;
  for(int i=n;i<m;++i)
    if(!vis[i])
      {
	if(a[v]+b[i]==pp[v][i])
	  {
	    vis[i]=true;
	    if(opo[i]<0 || dfs(opo[i]))
	      {
		opo[i]=v;
		return true;
	      }
	  }
	else
	  slk=min(slk,a[v]+b[i]-pp[v][i]);
      }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  cin>>n>>m;
  for(int i=0;i<m;++i)
    {
      cin>>p[i][0]>>p[i][1];
      cin>>cost[i];
    }
  for(int i=0;i<n-1;++i)
    add(p[i][0],p[i][1],i),add(p[i][1],p[i][0],i);
  for(int i=n-1;i<m;++i)
    {
      memset(vis,0,sizeof(vis));
      df(p[i][0],p[i][1],i);
    }
  for(int i=0;i<n-1;++i)
    for(int j=n-1;j<m;++j)
      a[i]=max(a[i],pp[i][j]);
  memset(opo,-1,sizeof(opo));
  for(int i=0;i<n-1;++i)
    {
      for(;;)
	{ 
	  slk=1e9;
	  memset(vis,0,sizeof(vis));
	  if(dfs(i))
	    break;
	  cout<<i<<' '<<slk<<endl;
	  for(int j=0;j<n-1;++j)
	    cout<<a[j]<<' ';
	  for(int j=n-1;j<m;++j)
	    cout<<b[j]<<' ';cout<<endl;
	  if(slk==1e9)
	    break;
	  for(int j=0;j<n-1;++j)
	    if(vis[j])
	      a[j]-=slk;
	  for(int j=n;j<m;++j)
	    if(vis[j])
	      b[j]+=slk;
	}
    }
  for(int i=0;i<n-1;++i)
    cout<<(cost[i]-a[i])<<endl;
  for(int i=n-1;i<m;++i)
    cout<<(cost[i]+b[i])<<endl;
  return 0;
}
