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
int vis[1<<25];
int cost[2][1<<25];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  queue<int> que;
  que.push(0);
  que.push(-1);
  for(int i=0;i<n;++i)
    {
      string tmp;
      cin>>tmp;
      int v(0);
      for(int j=0;j<m;++j)
	v=(v<<1)|(tmp[j]=='*'?1:0);
      //cout<<que.size()<<endl;
      for(int ff=i&1,tt=1-(i&1);;)
	{
	  int f=que.front();
	  que.pop();
	  if(f<0)
	    {
	      que.push(-1);
	      break;
	    }
	  int t=f|v;
	  if(i>=vis[t])
	    {
	      vis[t]=i+1;
	      que.push(t);
	      cost[tt][t]=cost[ff][f];
	    }
	  else 
	    cost[tt][t]=min(cost[tt][t],cost[ff][f]);
	  t=f;
	  if(i>=vis[t])
	    {
	      vis[t]=i+1;
	      que.push(t);
	      cost[tt][t]=cost[ff][f]+1;
	    }
	  else cost[tt][f]=min(cost[tt][t],cost[ff][f]+1);
	}
    }
  int ans=1e9;
  for(int ff=n&1;;)
    {
      int v=que.front();
      que.pop();
      if(v<0)
	break;
      ans=min(max(__builtin_popcount(v),cost[ff][v]),ans);
    }
  cout<<ans;
  return 0;
}
