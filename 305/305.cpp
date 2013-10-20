#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
vector<vector<int> > p;
vector<vector<int> > pp;
vector<int> q;
vector<pair<int,int> > r;
vector<int> opo;
vector<bool> vis;
vector<int> cover;
bool dfs(int v)
{
  for(int i=p[v].size()-1;i>=0;--i)
    if(!vis[p[v][i]])
      {
	vis[p[v][i]]=true;
	if(cover[p[v][i]]<0 || dfs(cover[p[v][i]]))
	  {
	    opo[v]=p[v][i];
	    cover[p[v][i]]=v;
	    return true;
	  }
      }
  return false;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  cin>>n>>m;
  r.resize(n);
  for(int i=0;i<n;++i)
    {
      cin>>r[i].first>>r[i].second;
      if(r[i].first)
	{
	  int j=-1;
	  if(r[i].first>0)
	    {
	      if(r[i].second>0)
		j=r[i].second;
	      else
		{
		  j=(-r[i].second/r[i].first)*r[i].first+r[i].second;
		  if(j<=0)
		    j+=r[i].first;
		  if(j-r[i].first>0)
		    j-=r[i].first;
		}
	    }
	  else if(r[i].second>0)
	    {
	      j=((m-r[i].second)/r[i].first)*r[i].first+r[i].second;
	      if(j>m)
		j+=r[i].first;
	      if(j-r[i].first<=m)
		j-=r[i].first;
	    }
	  for(int k=0;k<n && j>0 && j<=m;++k,j+=r[i].first)
	    q.push_back(j);
	}
      else if(r[i].second>0 && r[i].second<=m)
	q.push_back(r[i].second);
    }
  sort(q.begin(),q.end());
  q.resize(unique(q.begin(),q.end())-q.begin());
  p.resize(n);
  pp.resize(q.size());
  for(int i=0;i<n;++i)
    for(int j=q.size()-1;j>=0;--j)
      {
	int tmp=q[j]-r[i].second;
	if(((r[i].first==tmp) ||
	    (r[i].first && (tmp%r[i].first)==0 ) && tmp/r[i].first>=0))
	  {
	    p[i].push_back(j);
	    pp[j].push_back(i);
	  }
      }
  opo.resize(n);
  fill(opo.begin(),opo.end(),-1);
  cover.resize(q.size());
  fill(cover.begin(),cover.end(),-1);
  vis.resize(q.size());
  for(int i=0;i<n;++i)
    {
      fill(vis.begin(),vis.end(),false);
      dfs(i);
    }
  vector< bool > ocp;
  ocp.resize(n+1);
  fill(ocp.begin(),ocp.end(),false);
  for(int i=0;i<n;++i)
    if(opo[i]>=0 && q[opo[i]]<=n)
      ocp[q[opo[i]]]=true;
  for(int i=0,j=0;i<n;++i)
    if(opo[i]<0)
      {
	for(++j;ocp[j];++j)
	  ;
	cout<<j<<' ';
      }
    else cout<<q[opo[i]]<<' ';
  return 0;
}
