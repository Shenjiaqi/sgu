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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define M 10007
#define N 1007
#define R 1007
const ing inf=1e9+7;
// struct edge
// {
//   int to,cost,id;
//   edge(int t,int c,int i){to=t,cost=c,id=i;};
// };
int n,m,r,S,T;
vector<int> p[N],pp[N];
vector<int> q[R];
vector<int> u[M];
int ed[M][3];
vector<int> dis[M];
void add(int f,int t,int c,int id)
{
  ed[id][0]=f,ed[id][1]=t,ed[id][2]=c;
  p[f].PB(t);
  pp[t].PB(f);
}
int main()
{
  scanf("%d%d%d%d%d",&n,&m,&r,&s,&t);
  FOR(i,0,m)
    {
      int f,t,c;
      scanf("%d%d%d",&f,&t,&c);
      add(f,t,c,i+1);
    }
  add(0,s,0,m+1);
  FOR(i,0,r)
    {
      int k;
      scanf("%d",&k);
      FOR(j,0,k)
	{
	  int c;
	  scanf("%d",&c);
	  q[i].PB(c);
	  u[c].PB(i);
	}
    }
  FOR(i,1,m+1)
    {
      sort(u[c].begin(),u[c].end());
      dis[i].resize(1<<(u[c].size()));
      fill(dis[i].begin(),dis[i].end(),inf);
    }
  if(dfs(s,t))
    {
      dis[m+1][0]=0;
      queue<ppi> que;
      que.PB(ppi(m+1,0));
      for(;!que.empty();que.pop())
	{
	  int v=que.front().FIR;
	  int e=que.front().SEC;
	  
	}
    }
  else printf("-1");
  return 0;
}
