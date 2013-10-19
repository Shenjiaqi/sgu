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
#define N 200000
const ll mod=99990001;
int fa[N];
bool vis[N];
int gfa(int v)
{
  return (v==fa[v]?v:fa[v]=gfa(fa[v]));
}
void join(int a,int b)
{
  a=gfa(a);
  b=gfa(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in","w",stdout);
  int n=200000;
  printf("%d\n",n);
  for(int i=0;i<n;++i)
    fa[i]=i;
  for(int i=1;i<n;)
    {
      int a=rand()%n;
      int b=rand()%n;
      if(gfa(a)!=gfa(b))
	{
	  printf("%d %d %d\n",(1+a),(1+b),(int)(rand()%mod));
	  ++i;
	  join(a,b);
	}
    }
  for(int i=1;i<n;)
    {
      int tmp=rand()%n;
      if(!vis[tmp])
	{
	  printf("%d ",(1+tmp));
	  vis[tmp]=true;
	  ++i;
	}
    }
  return 0;
}
