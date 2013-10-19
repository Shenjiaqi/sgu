#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 200000
typedef pair<int,int> pp;
const ll mod=99990001;
int s[N];
int p[N*2+1][3],poi;
int weight[N];
int vis[N];
int fa[N][2];
int idx[N];
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f];
  if(s[f])
    p[s[f]][2]=poi;
  s[f]=poi;
}
void del(int l)
{
  int v=(l&1)?p[l+1][0]:p[l-1][0];
  if(s[v]==l)
    s[v]=p[l][1];
  else
    {
      p[p[l][1]][2]=p[l][2];
      p[p[l][2]][1]=p[l][1];
    }
}
bool nxt(stack<int> &sta,queue<int> &que,int tag,int &m)
{
  for(;;)
    {
      if(sta.empty())
	return false; 
      int l=sta.top();
      sta.pop();
      for(;l &&  vis[p[l][0]]==tag;)
	l=p[l][1];
      if(l)
	{
	  if(p[l][1])
	    sta.push(p[l][1]);
	  int b=p[l][0];
	  sta.push(s[b]);
	  que.push(b);
	  vis[b]=tag;
	  m=min(b,m);
	  break;
	}
    }
  return true;
}
void re(queue<int> &que,int m)
{
  for(;!que.empty();)
    {
      int a=que.front();
      que.pop();
      idx[a]=m;
    }
}
int cal(ll w,ll a,ll b)
{
  return (int)((((w*a)%mod)+b)%mod);
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;++i)
    {
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      --x,--y;
      weight[i]=w;
      add(x,y);
      add(y,x);
    }
  fa[0][0]=1;
  setbuf(stdout,NULL);
  for(int i=1;i<n;++i)
    {
      int q;
      scanf("%d",&q);
      int a,b;
      a=p[(q<<1)-1][0],b=p[q<<1][0];
      del((q<<1)-1);
      del(q<<1);
      int v=idx[a];
      int w=cal(weight[q-1],fa[v][0],fa[v][1]);
      printf("%d\n",w);
      queue<int> que1,que2;
      que1.push(a),que2.push(b);
      vis[a]=vis[b]=i;
      int min1=a,min2=b;
      stack<int> stack1,stack2;
      stack1.push(s[a]);
      stack2.push(s[b]);
      for(;;)
	{
	  bool f1=nxt(stack1,que1,i,min1);
	  bool f2=nxt(stack2,que2,i,min2);
	  if(f1 && f2)
	    continue;
	  if((!f1 && !f2 && min1<min2) || (!f1&&f2))
	    re(que1,i);
	  else
	    re(que2,i);
	  break;
	}
      fa[i][0]=((ll)fa[v][0]*(ll)w)%mod;
      fa[i][1]=((ll)fa[v][1]*(ll)w)%mod;
      fa[v][1]=((ll)fa[v][1]+(ll)w)%mod;
    }
  return 0;
}
