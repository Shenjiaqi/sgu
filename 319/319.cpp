#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define N 60000
int p[N+1][4];
int pre[N+1];
ll area[N+1];
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  int w,h;
  scanf("%d%d%d",&n,&w,&h);
  for(int i=1;i<=n;++i)
    {
      scanf("%d%d%d%d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
      if(p[i][0]>p[i][2])
	swap(p[i][0],p[i][2]);
      if(p[i][1]>p[i][3])
	swap(p[i][1],p[i][3]);
    }
  vector< pair<int,pair<int,int> > > q;
  for(int i=1;i<=n;++i)
    {
      q.push_back(make_pair(p[i][0],make_pair(p[i][1],i)));
      q.push_back(make_pair(p[i][0],make_pair(p[i][3],i)));
      q.push_back(make_pair(p[i][2],make_pair(0,i)));
    }
  sort(q.begin(),q.end());
  map<int,int> mapp;
  map<int,int>::iterator ite;
  mapp[0]=0;
  mapp[h]=0;
  p[0][0]=p[0][1]=0,p[0][2]=w,p[0][3]=h;
  for(int i=0;i<3*n;++i)
    {
      int v=q[i].second.second;
      int s=q[i].first;
      int l=q[i].second.first;
      if(s==p[v][0])
	{
	  if(l==p[v][1])
	    {
	      ite=mapp.lower_bound(l);
	      --ite;
	      int tmp=ite->second;
	      if(p[tmp][3]==ite->first)
		pre[v]=pre[tmp];
	      else pre[v]=tmp;
	    }
	  mapp[l]=v;
	}
      else
	{
	  mapp.erase(p[v][1]);
	  mapp.erase(p[v][3]);
	}
    }
  area[0]=(ll)h*(ll)w;
  for(int i=1;i<=n;++i)
    {
      int v=pre[i];
      ll tmp=(ll)(p[i][2]-p[i][0])*(ll)(p[i][3]-p[i][1]);
      area[v]-=tmp;
      area[i]+=tmp;
    }
  sort(area,area+n+1);
  for(int i=0;i<n+1;++i)
    printf("%I64d ",area[i]);
  return 0;
}
