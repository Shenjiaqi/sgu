#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 10007
#define M 50007
int p[M][3],poi;
int q[M][3],qoi,qs[N];
int s[N];
int cnt[N];
ll dis[N];
vector<vector<ll> > vv;
void add(int f,int t,int d)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi,p[poi][2]=d;
}
void adds(int f,int t,int d)
{
  ++qoi,q[qoi][0]=t,q[qoi][1]=qs[f],qs[f]=qoi,q[qoi][2]=d;
}
bool in[N];
int dis[N];
ll inf;
void dis(int v)
{
  queue<int> que;
  que.push(v);
  memset(dis,1<<6,sizeof(dis));
  inf=dis[0];
  for(;!que.empty();)
    {
      v=que.front();
      que.pop();
      in[v]=false;
      for(int i=qs[v];i;i=q[i][1])
	{
	  int t=q[i][0];
	  if(dis[t]>dis[v]+q[i][2])
	    {
	      dis[t]=dis[v]+q[i][2];
	      if(!in[t])
		in[t]=true,que.push(t);
	    }
	}
    }
}
multimap<ll,int> ans;
void dis(int v,bool k)
{
  if(dis[v]<inf);
  for(int i=1;i<vv[v].size();++i)
    {
      if(adda(vv[0]+
    }
}
int main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int s,t;
  scanf("%d%d",&s,&t);
  for(int i=0;i<m;++i)
    {
      scanf("%d%d%d",f,t,d);
      add(f,t,d);
      addr(t,f,d);
    }
  multimap<ll,int> mapp;
  multimap<ll,int>::iterator ite;
  mapp.insert(make_pair(0,s));
  vv.resize(n+1);
  for(;mapp.size()>0;)
    {
      ite=mapp.begin();
      ll dis=ite->first;
      int v=ite->second;
      vv[v].push_back(dis);
      if(!cnt[v])
	for(int j=s[v];j;j=p[j][1])
	  mapp.insert(make_pair(dis+p[j][2],p[j][0]));
      cnt[v]=true;
    }
  dis(t);
  dfs(s,true);
  return 0;
}
