#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
#define N 100000
int n;
ll cal(int num)
{
  map<int,int> tr;
  map<int,int> bd;
  map<int,int> left;
  for(int i=0;i<n;++i)
    ++left[p[i].second];
  for(int i=0;i<n;++i)
    {
      int j=i;
      for(;j<n && p[j].first==p[i].first;++j)
	{
	  if(0==left[p[j].second])
	    left.erase(p[j].second);
	  map<int,int>::iterator ib=bd.upper_bound(p[j].second);
	  int u=(ib==bd.end()?num:ib->first);
	  map<int,ll>::iterator it=tr.lower_bound(p[j].second),iit;
	  for(;it!=tr.end() && it->first<u;)
	    {
	      tr[p[j].second]+=it->second;
	      r+=it->second;
	      iit=it++;
	      tr.erase(iit);
	    }
	  if(j!=i)
	    {
	      ++tr[p[j].second];
	      ++r;
	      ++bd[left.lower_bound(p[j].second)];
	    }
	  ib=bd.find(p[j].second);
	  if(ib!=bd.end())
	    {
	      int m=min(ib->second,tr[p[j].second));
	      if(ib->second==m)
		bd.erase(ib);
	      if(tr[p[j].second]==m)
		tr.erase(p[j].second);
	    }
	}
    }
  return r;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  typedef pair<int,int> pp;
  vector<pp> p;
  p.resize(n);
  map<int,int> mapp;
  for(int i=0;i<n;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      p[i].first=x,p[i].second=y;
      mapp[y]=0;
    }
  int num(0);
  map<int,int>::iterator ite;
  for(ite=mapp.begin();ite!=mapp.end();++ite)
    ite->second=num++;
  for(int i=0;i<n;++i)
    p[i].second=mapp[p[i].second];
  sort(p.begin(),p.end());
  ans+=cal();
  for(int i=0;i<n;++i)
    p[i].second=num-1-p[i].second;
  sort(p.begin(),p.end());
  cal();
  cout<<ans;
  return 0;
}
