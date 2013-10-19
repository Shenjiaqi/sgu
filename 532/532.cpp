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
using namespace std;
typedef long long ll;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 600
int p[N][4],q[N][4];
int c[N*2+1];
typedef pair<int,int> point;
typedef pair<int,point> seg;
void add(int pos,int v)
{
  for(;pos<=N*2;pos+=(pos&(-pos)))
    c[pos]+=v;
}
int que(int pos)
{
  int r=0;
  for(;pos;pos^=(pos&(-pos)))
    r+=c[pos];
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  map<int,int> mapx,mapy;
  map<int,int>::iterator ite;
  FOR(i,0,n)
    {
      scanf("%d%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3);
      mapx[p[i][0]]=mapx[p[i][2]]=0;
      mapy[p[i][1]]=mapy[p[i][3]]=0;
    }
  int cnt=1;
  for(ite=mapx.begin();ite!=mapx.end();++ite)
    ite->second=cnt++;
  cnt=1;
  for(ite=mapy.begin();ite!=mapy.end();++ite)
    ite->second=cnt++;
  for(int i=0;i<n;++i)
    p[i][0]=mapx[p[i][0]],p[i][2]=mapx[p[i][2]],
      p[i][1]=mapy[p[i][1]],p[i][3]=mapy[p[i][3]];
  vector<seg> x,y;
  for(int i=0;i<n;++i)
    if(p[i][0]==p[i][2])
      x.push_back(seg(p[i][0],point(min(p[i][1],p[i][3]),max(p[i][1],p[i][3]))));
    else
      y.push_back(seg(max(p[i][0],p[i][2]),point(min(p[i][0],p[i][2]),p[i][1])));
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ll ans=0;
  for(int i=0,s=0;i<x.size() && s<y.size();++i)
    {
      int h=x[i].second.second,l=x[i].second.first,k=x[i].first;
      for(;s<y.size() && y[s].first<=k;++s)
	;
      if(s>=y.size())
	break;
      vector<point> tmp;
      for(int u=s;u<y.size();++u)
	{
	  int a=y[u].second.second,b=y[u].second.first,c=y[u].first;
	  if(b<=k && a<=h && a>=l)
	    {
	      add(a,1);
	      tmp.push_back(point(c,a));
	    }
	}
      int o=0;
      for(int j=i+1;j<x.size() && o<tmp.size();++j)
	{
	  for(;o<tmp.size() && tmp[o].first<x[j].first;++o)
	    add(tmp[o].second,-1);
	  if(o>=tmp.size())
	    break;
	  int aa=x[j].second.first,bb=x[j].second.second;
	  if(!(aa>=h || bb<=l))
	    {
	      int z=que(bb)-que(aa-1);
	      ans+=(z*(z-1))/2;
	    }
	}
      for(;o<tmp.size();++o)
	add(tmp[o].second,-1);
    }
  cout<<ans;
  return 0;
}
