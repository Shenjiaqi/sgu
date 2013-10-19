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
#include <functional>
using namespace std;
int cost[601][601];
int pre[601][601];
vector< vector< pair<int,int> > > p;
void bt(int k,int i)
{
  if(k>0)
    {
      bt(k-1,i-pre[k][i]);
      for(int j=1;j<=pre[k][i];++j)
	cout<<(p[k-1][j].second)<<' ';
    }
}
int main()
{
  freopen("in","r",stdin);
  int n,k,price;
  cin>>n>>k>>price;
  vector<int> gum;
  gum.resize(k);
  for(int i=0;i<k;++i)
    cin>>gum[i];
  p.resize(k);
  for(int i=0;i<n;++i)
    {
      int a,c;
      cin>>a>>c;
      p[c-1].push_back(make_pair(a,1+i));
    }
  for(int i=0;i<k;++i)
    {
      p[i].push_back(make_pair(0,0));
      if(p[i].size()>1)
	{
	  sort(p[i].begin(),p[i].end());
	  p[i][1].first+=gum[i];
	  for(int j=2;j<p[i].size();++j)
	    p[i][j].first+=p[i][j-1].first;
	}
    }
  const int inf=10000001;
  for(int i=0;i<=k;++i)
    for(int j=1;j<=n;++j)
      cost[i][j]=inf;
  for(int i=1;i<=k;++i)
    for(int j=0;j<n;++j)
      for(int kk=min((int)p[i-1].size()-1,n-j);kk>=0;--kk)
	if(cost[i][j+kk]>cost[i-1][j]+p[i-1][kk].first)
	  {
	    cost[i][j+kk]=cost[i-1][j]+p[i-1][kk].first;
	    pre[i][j+kk]=kk;
	  }
  for(int i=n;i>=0;--i)
    if(cost[k][i]<=price)
      {
	cout<<i<<endl;
	bt(k,i);
	break;
      }
  return 0;
}
