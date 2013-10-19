#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
#define N 100007
vector<pp> p;
int n;
map<int,int> mapp;
map<int,int>::iterator ite,ii;
int val[N+1];
int s[N+1];
int q[N+1][2],qoi;
ll cal(int num)
{
  map<int,int> map1,mapbd;
  mapp.clear();
  memset(s,0,sizeof(s));
  memset(val,0,sizeof(val));
  qoi=0;
  for(int i=n-1;i>=0;--i)
    {
      int tmp=p[i].second;
      mapp[tmp]=tmp;
      ++qoi,q[qoi][0]=i,q[qoi][1]=s[tmp],s[tmp]=qoi;
    }
  ll r(0);
  for(int i=0;i<n;)
    {
      // cout<<"* "<<i<<' '<<val[i]<<endl;
      // cout<<"--------"<<endl;
      // for(ite=map1.begin();ite!=map1.end();++ite)
      // 	cout<<ite->first<<' '<<ite->second<<endl;
      // cout<<endl<<endl;
      int j=i;
      for(;p[j].first==p[i].first;++j)
	{
	  int tmp=p[j].second;
	  int v=val[q[s[tmp]][0]];
	  if(v)
	    {
	      for(;v>0;)
		{
		  ite=map1.lower_bound(tmp);
		  int tz=min(ite->second,v);
		  ite->second-=tz;
		  v-=tz;
		  //cout<<'!'<<j<<' '<<tz<<endl;
		  r+=tz;
		  if(ite->second<=0)
		    map1.erase(ite);
		}
	      mapbd.erase(tmp);
	    }
	  s[tmp]=q[s[tmp]][1];
	  if(s[tmp]==0)
	    mapp.erase(tmp);
	}
      // cout<<"--------------------"<<endl;
      // for(ite=map1.begin();ite!=map1.end();++ite)
      // 	cout<<ite->first<<' '<<ite->second<<endl;
      // cout<<endl<<endl;
      int k=i;
      for(;i<j;++i)
	{
	  int tmp=p[i].second;
	  ite=mapbd.upper_bound(tmp);
	  int c=(ite==mapbd.end()?num+1:ite->first);
	  ite=map1.upper_bound(tmp);
	  //cout<<"**"<<ite->first<<' '<<ite->second<<endl;
	  for(;ite!=map1.end() && ite->first<=c;)
	    {
	      map1[tmp]+=ite->second;
	      //cout<<"!!"<<i<<' '<<ite->first<<' '<<ite->second<<endl;
	      r+=ite->second;
	      ii=ite;
	      ++ite;
	      map1.erase(ii);
	    }
	}
      i=k;
      for(;i<j;++i)
	{
	  ite=mapp.lower_bound(p[i].second);
	  int c=(i==j-1?num:p[i+1].second);
	  if(ite!=mapp.end() && ite->first<c)
	    {
	      //cout<<"add "<<i<<' '<<ite->first<<' '<<c<<endl;
	      mapbd[ite->first]=1;
	      ++val[q[s[ite->first]][0]];
	      ++map1[c];
	      if(ite->first==p[i].second)
		--r;
	    }
	}
    }
  return r;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      p.push_back(pp(x,y));
      mapp[y]=0;
    }
  int num(0);
  for(ite=mapp.begin();ite!=mapp.end();++ite)
    ite->second=num++;
  for(int i=0;i<n;++i)
    p[i].second=mapp[p[i].second];
  sort(p.begin(),p.end());
  // for(int i=0;i<n;++i)
  //   cout<<p[i].first<<' '<<p[i].second<<endl;
  ll ans=cal(num);
  //cout<<ans<<endl;
  for(int i=0;i<n;++i)
    p[i].second=num-1-p[i].second;
  sort(p.begin(),p.end());
  ans+=cal(num);
  //cout<<ans<<endl;
  mapp.clear();
  for(int i=0,j;i<n;)
    for(--ans,j=p[i].first;p[i].first==j;++i,++ans)
      if(mapp.find(p[i].second)!=mapp.end())
	++ans;
      else mapp[p[i].second]=1;
  cout<<ans;
  return 0;
}
