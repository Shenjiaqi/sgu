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
int m2[N+1],m1[N+1];
map<int,int> ma;
void add(int * v,int pos,int val,int num)
{
  ++pos;
  if(pos)
    for(;pos<=num+1;pos+=(pos&(-pos)))
      v[pos]+=val;
}
int que(int *v,int pos)
{
  int r(0);
  ++pos;
  if(pos)
    for(;pos;pos^=(pos&(-pos)))
      r+=v[pos];
  return r;
}
void sub(int *m1,int nu,int pos,int num)
{
  for(;nu>0;)
    {
      ite=ma.lower_bound(pos);
      //      if(ite==ma.end())
      //{cout<<"!!"<<nu<<" "<<pos<<endl;return ;}
      int nn=min(nu,ite->second);
      nu-=nn;
      ite->second-=nn;
      if(ite->second==0)
	ma.erase(ite);
      add(m1,ite->first,-nn,num);
    }
}
ll cal(int num)
{
  mapp.clear();
  memset(s,0,sizeof(s));
  memset(val,0,sizeof(val));
  memset(m2,0,sizeof(m2));
  memset(m1,0,sizeof(m1));
  ma.clear();
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
      int j=i;
      for(;p[j].first==p[i].first;++j)
	{
	  int tmp=p[j].second;
	  int v=val[q[s[tmp]][0]];
	  if(v)
	    {
	      add(m2,tmp,-v,num);
	      //cout<<j<<' '<<v<<endl;
	      sub(m1,v,tmp,num);
	      //cout<<"^ "<<j<<' '<<v<<endl;
	      r+=v;
	    }
	  s[tmp]=q[s[tmp]][1];
	  if(s[tmp]==0)
	    mapp.erase(tmp);
	}
      for(int k=i;k<j;++k)
	{
	  int zz=que(m2,p[k].second)-que(m1,p[k].second);
	  //	  if(k==5)
	    {
	      //cout<<que(m2,p[k].second)<<' '<<que(m1,p[k].second)<<endl;
	     //  for(ite=ma.begin();ite!=ma.end();++ite)
	    // 	cout<<ite->first<<' '<<ite->second<<"   ";
	    //   cout<<'!'<<k<<endl;
	    // }
	  if(zz)
	    {
	      sub(m1,zz,p[k].second,num);
	      //if(p[k].second==0)
	      //cout<<"!!!"<<endl;
	      ma[p[k].second-1]+=zz,add(m1,p[k].second-1,zz,num);
	      //cout<<"^^ "<<k<<' '<<zz<<endl;
	      r+=zz;
	    }
	    }
	}
      for(;i<j;++i)
	{
	  int tmp=p[i].second;
	  ite=mapp.lower_bound(tmp);
	  if(ite!=mapp.end())
	    {
	      int c=(i==j-1?num:p[i+1].second);
	      //if(ite->first<c)
		{
		  //cout<<"add "<<c-1<<endl;
		  if(c-1>=ite->second)
		    {
		      add(m2,ite->first,1,num);
		      ++val[q[s[ite->first]][0]];
		      ++ma[c-1];
		      add(m1,c-1,1,num);
		      if(ite->second==tmp)
			--r;
		      else if(ite->second<c && c!=num)
			++r;
		    }
		}
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
  ll ans=cal(num);
  //cout<<ans<<endl;
  for(int i=0;i<n;++i)
    p[i].second=num-1-p[i].second;
  sort(p.begin(),p.end());
  ans+=cal(num);
  //cout<<ans<<endl;
  memset(s,0,sizeof(s));
  for(int i=0,j;i<n;)
    for(--ans,j=p[i].first;p[i].first==j;++i,++ans)
      ans+=s[p[i].second],s[p[i].second]=1;
  cout<<ans;
  return 0;
}
