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
#define N 2000
int p[2][N*4+1][2];
int s[2][N];
int poi[2];
int q[N][2];
int t[N+1],ti;
int an[N][4],ani;
int vis[N],visi;
void add(int i,int f,int t)
{
  ++poi[i],p[i][poi[i]][0]=t,p[i][poi[i]][1]=s[i][f],s[i][f]=poi[i];
}
bool check_con(int i,int f,int t)
{
  for(int j=s[i][f];j;j=p[i][j][1])
    if(p[i][j][0]==t)
      return true;
  return false;
}
bool find_circle(int i,int v,int l,int f)
{
  t[l]=v;
  ti=l;
  if(vis[v]==visi)
    return true;
  vis[v]=visi;
  for(int j=s[i][v];j;j=p[i][j][1])
    if(p[i][j][0]>=0 && p[i][j][0]!=f && find_circle(i,p[i][j][0],l+1,v))
      return true;
  return false;
}
void bk(int i,int f,int t)
{
  for(int j=s[i][f];j;j=p[i][j][1])
    if(p[i][j][0]==t)
      {
	p[i][j][0]=-1;
	p[i][j+((j&1)?1:-1)][0]=-1;
	break;
      }
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  FOR(i,0,2)
    {
      FOR(j,0,n-1)
	{
	  int f,t;
	  scanf("%d%d",&f,&t);
	  --f,--t;
	  add(i,f,t);
	  add(i,t,f);
	  if(i==0)
	    q[j][0]=f,q[j][1]=t;
	}
    }
  FOR(i,0,n-1)
    {
      if(!check_con(1,q[i][0],q[i][1]))
	{
	  an[ani][0]=q[i][0],an[ani][1]=q[i][1];
	  add(1,q[i][0],q[i][1]);
	  ti=0;
	  ++visi;
	  find_circle(1,q[i][0],0,-1);
	  FOR(j,0,ti)
	    if(!check_con(0,t[j],t[j+1]))
	      {
		bk(1,t[j],t[j+1]);
		an[ani][2]=t[j],an[ani][3]=t[j+1];
		break;
	      }
	  ++ani;
	}
    }
  printf("%d\n",ani);
  FOR(i,0,ani)
    printf("2 %d %d %d %d\n",an[i][0]+1,an[i][1]+1,an[i][2]+1,an[i][3]+1);
  return 0;
}
