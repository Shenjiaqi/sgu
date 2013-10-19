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
#define N 20
int con[N][N];
bool zz[1<<N];
int mm[1<<N];
int cc[1<<N];
int val[1<<N];
int cost[N];
bool ccon[N][N];
int n;
int dfs(int v,int f,int pat)
{
  int r=1<<v;
  for(int i=0;i<n;++i)
    if(i!=f && con[v][i] && ((1<<i)&pat))
      r|=dfs(i,v,pat);
  return r;
}
bool chk(int i,int j)
{
  for(int a=0;a<n;++a)
    if((1<<a)&i)
      for(int b=0;b<n;++b)
	if((1<<b)&j)
	  if(ccon[a][b])
	    return true;
  return false;
}
int main()
{
  freopen("in","r",stdin);
  int d1,c1,d2,c2;
  scanf("%d%d%d%d%d",&n,&d1,&c1,&d2,&c2);
  int all(0);
  for(int i=0;i<n;++i)
    {
      scanf("%d",cost+i);
      all+=cost[i];
    }
  for(int i=0;i<n-1;++i)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      --a,--b;
      con[a][b]=con[b][a]=1;
      ccon[a][b]=ccon[b][a]=1;
    }
  for(int i=1;i<(1<<n);++i)
    if(i==dfs(__builtin_ctz(i),-1,i))
      zz[i]=true;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(con[j][i])
	for(int k=0;k<n;++k)
	  if(con[i][k] && (con[j][k]==0 || con[j][i]+con[i][k]<con[j][k]))
	    con[j][k]=con[j][i]+con[i][k];
  for(int i=0;i<(1<<n);++i)
    if(zz[i])
      {
	int m=0;
	for(int a=0;a<n;++a)
	  if((1<<a)&i)
	    for(int b=a+1;b<n;++b)
	      if(((1<<b)&i) && con[a][b] && m<con[a][b])
		m=con[a][b];
	int c=0;
	for(int a=0;a<n;++a)
	  if((1<<a)&i)
	    for(int b=0;b<n;++b)
	      if(((1<<b)&i) && a!=b && con[a][b]==m)
		{
		  ++c;
		  break;
		}
	mm[i]=m,cc[i]=c;
	for(int a=0;a<n;++a)
	  if((1<<a)&i)
	    val[i]+=cost[a];
      }
  int ans=-1,ans1;
  for(int i=1;i<(1<<n);++i)
    if(zz[i] && mm[i]==d1 && cc[i]<=c1)
      for(int j=(~i)&((1<<n)-1);j;j=(j-1)&(~i))
	{
	  if(zz[j] && mm[j]==d2 && cc[j]<=c2 && !chk(i,j))
	    if(ans<val[i]+val[j])
	      ans=val[i]+val[j],ans1=i|j;
	}
  cout<<endl;
  if(ans>=0)
    {
      printf("%d\n",(all-ans));
      for(int i=0;i<n;++i)
	if((ans1&(1<<i))==0)
	  printf("%d ",(i+1));
    }
  else printf("-1");
  /*cout<<endl;
  cout<<zz[1<<8]<<' '<<mm[1<<8]<<' '<<cc[1<<8]<<endl;
  cout<<zz[245]<<' '<<mm[245]<<' '<<cc[245]<<endl;*/
  return 0;
}
