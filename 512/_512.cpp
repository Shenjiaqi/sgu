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
vector<pp> p;
ll q[N*5][5];
map<int,int> mapp;
map<int,int>::iterator ite;
void init(int f,int t,int l)
{
  q[l][0]=f,q[l][1]=t,q[l][2]=q[l][3]=q[l][4]=0;
  if(l==1)
    q[l][4]=1;
  if(f<t)
    {
      init(f,(f+t)>>1,l<<1);
      init(((f+t)>>1)+1,t,(l<<1)+1);
    }
}
void push(int l)
{
  if(q[l][4])
    q[l][2]+=q[l][3],q[l][3]=0;
  else if(q[l][3])
    q[l<<1][3]+=q[l][3],q[(l<<1)+1][3]+=q[l][3],q[l][3]=0;
}
ll que(int k,int l)
{
  push(l);
  if(q[l][4])
    return q[l][2];
  if((k<=(q[l][0]+q[l][1])>>1))
    return que(k,l<<1);
  return que(k,(l<<1)+1);
}
void pushd(int l)
{
  push(l);
  int lc=l<<1;
  int rc=lc+1;
  if(q[l][4])
    q[lc][2]=q[rc][2]=q[l][2],
      q[lc][3]=q[rc][3]=0,
      q[lc][4]=q[rc][4]=1,
      q[l][4]=0;
}
void mg(int l)
{
  push(l);
  int lc=l<<1;
  int rc=lc+1;
  if(q[l][4]==0 && q[lc][4] && q[rc][4])
    {
      push(lc);
      push(rc);
      if(q[lc][2]==q[rc][2])
	q[l][2]=q[lc][2],q[l][3]=0,q[l][4]=1;
    }
}
void add(int f,int t,int l,int v)
{
  //cout<<l<<' '<<q[l][1]<<' '<<t<<' '<<q[l][0]<<' '<<f<<endl;
  if(q[l][0]>t || q[l][1]<f)
    return ;
  push(l);
  if(q[l][1]<=t && q[l][0]>=f)
    q[l][3]+=v;
  else
    { 
      pushd(l);
      add(f,t,l<<1,v);
      add(f,t,(l<<1)+1,v);
      mg(l);
    }
}
ll val[N+1];
ll cal(int f,int t)
{
  init(f,t,1);
  ll r(0);
  mapp.clear();
  //cout<<f<<' '<<t<<endl;
  for(int i=0;i<n;i)
    {
      int j=i;
      for(;j<n && p[j].first==p[i].first;++j)
	{
	  r+=(val[j]=que(p[j].second,1));
	  cout<<j<<' '<<val[j]<<endl;
	  mapp[p[j].second]=p[j].second;
	}
      r+=j-i-1;
      add(p[i].second,t,1,1);
      //cout<<p[i].second<<' '<<t<<"que3 "<<que(3,1)<<endl;
      for(;i<j;++i)
	if(val[i])
	  {
	    ite=mapp.upper_bound(p[i].second);
	    int c=(ite==mapp.end()?t:ite->first-1);
	    if(p[i].second<=c)
	      add(p[i].second,c,1,-val[i]);
	  }
      /*ll tmp=que(p[i].second,1);
      r+=tmp;
      cout<<"i "<<i<<' '<<tmp<<endl;
      ite=mapp.upper_bound(p[i].second);
      if(ite==mapp.end())
	add(p[i].second,t,1,1-tmp);
      else
	{
	  add(p[i].second,ite->first-1,1,1-tmp);
	  add(ite->first,t,1,1);
	}
	mapp[p[i].second]=p[i].second;*/
    }
  return r;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  p.resize(n);
  for(int i=0;i<n;++i)
    {
      scanf("%d%d",&p[i].first,&p[i].second);
      mapp[p[i].second]=1;
    }
  int num(0);
  for(ite=mapp.begin();ite!=mapp.end();++ite)
    ite->second=num++;
  for(int i=0;i<n;++i)
    p[i].second=mapp[p[i].second];
  sort(p.begin(),p.end());
  ll ans=cal(0,num-1);
  for(int i=0;i<n;++i)
    p[i].second=num-1-p[i].second;
  sort(p.begin(),p.end());
  cout<<ans<<endl;
  ans+=cal(0,num-1);
  cout<<ans<<endl;
  mapp.clear();
  for(int i=0;i<n;)
    {
      ++ans;
      for(int j=p[i].first;p[i].first==j;++i,--ans)
	if(mapp.find(p[i].second)!=mapp.end())
	  --ans;
	else
	  mapp[p[i].second]=1;
    }
  cout<<ans;
  return 0;
}
