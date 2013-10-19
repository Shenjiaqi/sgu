#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100000
#define M 200000
int n,m;
int p[M*2+1][2],poi;
int s[N];
int q[N][3];
int dis[N];
bool in[N];
bool cnt[N];
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi;
}
void spfa(int st)
{
  memset(dis,1<<6,sizeof(dis));
  dis[st]=0;
  queue<int> que;
  in[st]=true;
  que.push(st);
  for(;!que.empty();)
    {
      int k=que.front();
      que.pop();
      in[k]=false;
      for(int i=s[k];i;i=p[i][1])
	{
	  int to=p[i][0];
	  if(dis[to]>dis[k]+1)
	    {
	      dis[to]=dis[k]+1;
	      if(!in[to])
		in[to]=true,que.push(to);
	    }
	}
    }
  FOR(i,0,n)
    q[i][st]=dis[i];
}
int z[N],zz[3];
bool cmp(int a,int b)
{
  FOR(i,0,3)
    if(q[a][zz[i]]!=q[b][zz[i]])
      return q[a][zz[i]]<q[b][zz[i]];
  return a<b;
}
void pass()
{
  sort(z,z+n,cmp);
  // cout<<"!";
  // FOR(i,0,n)
  //   cout<<z[i]<<' ';cout<<endl;
  int ma=1e9,mb=1e9,mc=1e9;
  int a=zz[0],b=zz[1],c=zz[2];
  map<ppi,int> mapp;
  for(int i=0;i<n;)
    {
      int k=i;
      ma=q[z[i]][a];
      for(;i<n && q[z[i]][a]==ma;++i)
	{
	  int j=z[i];
	  if(q[j][c]>mc || q[j][b]>mb || mapp.find(ppi(q[j][b],q[j][c]))!=mapp.end())
	    cnt[j]=true;
	}
      for(;k<i;++k)
	{
	  int j=z[k];
	  mapp[ppi(q[j][b],q[j][c])]=1;
	  mb=min(q[j][b],mb);
	  mc=min(q[j][c],mc);
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  FOR(i,0,m)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      --a,--b;
      add(a,b);
      add(b,a);
    }
  FOR(i,0,3)
    spfa(i);
  FOR(i,0,n)
    z[i]=i;
  FOR(i,0,3)
    zz[i]=i;
  // FOR(i,0,n){cout<<i<<' ';
  //   FOR(j,0,3)
  //     cout<<q[i][j]<<' ';cout<<endl;}
  for(;;)
    {
      // FOR(i,0,3)
      // 	cout<<zz[i]<<' ';cout<<endl;
      pass();
      // FOR(i,0,n)
      // 	cout<<cnt[i]<<' ';cout<<endl;
      if(!next_permutation(zz,zz+3))
	break;
    }
  FOR(i,0,n)
    if(!cnt[i])
      {
	printf("1");
	return 0;
      }
  printf("2");
  return 0;
}
