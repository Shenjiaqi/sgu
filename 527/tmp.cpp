#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int sumFlow;
const int MAXN = 1010;
const int MAXM = 1000200;
const int INF = 1000000000;
struct Edge
{
  int u, v, cap, cost;
  int next;
}edge[MAXM<<2];
int NE;
int head[MAXN], dist[MAXN], pp[MAXN];
bool vis[MAXN];
void init()
{
  NE = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost)
{
  edge[NE].u = u; edge[NE].v = v; edge[NE].cap = cap; edge[NE].cost = cost;
  edge[NE].next = head[u]; head[u] = NE++;
  edge[NE].u = v; edge[NE].v = u; edge[NE].cap = 0; edge[NE].cost = -cost;
  edge[NE].next = head[v]; head[v] = NE++;
}
bool SPFA(int s, int t, int n)
{
  int i, u, v;
  queue <int> qu;
  memset(vis,false,sizeof(vis));
  memset(pp,-1,sizeof(pp));
  for(i = 0; i <= n; i++) dist[i] = INF;
  vis[s] = true; dist[s] = 0;
  qu.push(s);
  while(!qu.empty())
    {
      u = qu.front(); qu.pop(); vis[u] = false;
      for(i = head[u]; i != -1; i = edge[i].next)
        {
	  v = edge[i].v;
	  if(edge[i].cap && dist[v] > dist[u] + edge[i].cost)
            {
	      dist[v] = dist[u] + edge[i].cost;
	      pp[v] = i;
	      if(!vis[v])
                {
		  qu.push(v);
		  vis[v] = true;
                }
            }
        }
    }
  if(dist[t] == INF) return false;
  return true;
}
int MCMF(int s, int t, int n) // minCostMaxFlow
{
  int flow = 0; // 总流量
  int i, minflow, mincost;
  mincost = 0;
  while(SPFA(s, t, n))
    {
      minflow = INF + 1;
      for(i = pp[t]; i != -1; i = pp[edge[i].u])
	if(edge[i].cap < minflow)
	  minflow = edge[i].cap;
      flow += minflow;
      for(i = pp[t]; i != -1; i = pp[edge[i].u])
        {
	  cout<<edge[i].u<<' ';
	  edge[i].cap -= minflow;
	  edge[i^1].cap += minflow;
        }
      cout<<endl;
      mincost += dist[t] * minflow;
    }
  sumFlow = flow; // 最大流
  return mincost;
}
int main()
{
  int n, m;
  int u, v, c;
  init();
  addedge(0,1,2,1e8/2);
  addedge(0,2,1,1e8);
  addedge(0,3,1,1e8);
  addedge(1,4,1,0);
  addedge(1,5,1,0);
  addedge(2,4,1,0);
  addedge(3,5,1,0);
  addedge(4,6,1,0);
  addedge(5,6,1,0);
  int ans=MCMF(0,6,7);
  printf("%d\n", ans);
  return 0;
}
