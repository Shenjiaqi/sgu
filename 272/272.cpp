#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define N 10000
#define M 100000
int s[N+1];
int p[M*2+1][2],poi;
bool seta[N+1];
bool setb[N+1];
bool in[N+1];
int dis[N+1];
bool usd[N+1];
int pre[N+1];
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi;
}
int findpath(int v)
{
  int l=dis[v];
  usd[v]=true;
  if(l==0)
    {
      pre[v]=0;
      return true;
    }
  for(int i=s[v];i;i=p[i][1])
    if(dis[p[i][0]]==l-1)
      {
	int t=p[i][0];
	if(!usd[t] && findpath(t))
	  {
	    pre[v]=t;
	    return true;
	  }
      }
  return false;
}
void pt(int v)
{
  for(;v;v=pre[v])
    printf("%d ",v);
  printf("\n");
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      add(f,t);
      add(t,f);
    }
  int n1,n2;
  scanf("%d",&n1);
  for(int i=0;i<n1;++i)
    {
      int t;
      scanf("%d",&t);
      seta[t]=true;
    }
  scanf("%d",&n2);
  queue<int> que;
  for(int i=0;i<n2;++i)
    {
      int t;
      scanf("%d",&t);
      setb[t]=true;
      que.push(t);
      in[t]=true;
    }
  for(int i=1;i<=n;++i)
    dis[i]=1e9;
  que.push(0);
  for(int i=0;que.size()>1;)
    {
      int v=que.front();
      que.pop();
      if(v==0)
	{
	  ++i;
	  que.push(0);
	}
      else
	{
	  dis[v]=i;
	  for(int j=s[v];j;j=p[j][1])
	    if(!in[p[j][0]])
	      {
		que.push(p[j][0]);
		in[p[j][0]]=true;
	      }
	}
    }
  int md=1e9;
  for(int i=1;i<=n;++i)
    if(seta[i])
      md=min(md,dis[i]);
  queue<int> ans;
  for(int i=1;i<=n;++i)
    if(seta[i] && dis[i]==md && findpath(i))
      ans.push(i);
  cout<<ans.size()<<' '<<md<<endl;
  for(;!ans.empty();ans.pop())
    pt(ans.front());
  return 0;
}
