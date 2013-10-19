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
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 1000
#define M 1000
int p[N][M];
int col[N*M];
int s[N*M];
int q[N*2+1][2],qoi;
map<int,int> mapp;
void cal(int tmp)
{
  if(s[tmp]==0)
    return;
  bool v[51]={0};
  for(int i=s[tmp];i;i=q[i][1])
    if(col[q[i][0]])
      v[col[q[i][0]]]=true;
  for(int i=1;i<51;++i)
    if(!v[i])
      {
	col[tmp]=i;
	break;
      }
}
void add(int f,int t)
{
  ++qoi,q[qoi][0]=t,q[qoi][1]=s[f],s[f]=qoi;
}
void dfs(int v,int f)
{
  if(col[v])
    return;
  ll fb(0);
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f)
      fb|=col[p[i][0]];
  col[v]=2;
  for(;col[v]&fb;col[v]<<=1)
    ;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  int num(0);
  for(int i=0,j;i<m;++i)
    {
      scanf("%d",&j);
      if(mapp.find(j)==mapp.end())
	{
	  mapp[j]=num;
	  ++num;
	}
      p[0][i]=mapp[j];
    }
  for(int i=1;i<n;++i)
    {
      for(int j=0,k=0,t;j<m;++j)
	{
	  scanf("%d",&t);
	  if(mapp.find(t)==mapp.end())
	    {
	      mapp[t]=num;
	      ++num;
	    }
	  p[i][j]=mapp[t];
	  if(k==0 && p[i][j]!=p[0][j])
	    {
	      add(p[i][j],p[0][j]);
	      add(p[0][j],p[i][j]);
	      k=1;
	    }
	}
    }
  printf("Yes\n");
  for(map<int,int>::iterator ite=mapp.begin();ite!=mapp.end();++ite)
    {
      cal(ite->second);
      printf("%d -> %d\n",ite->first,col[ite->second]);
    }
  return 0;
}
