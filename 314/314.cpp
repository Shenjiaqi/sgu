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
#define N 10007
#define M 50007
int path[M][3];
int pp[M][2];
ll dist[N+1];
int p1[M][3],poi1,s1[N];
int p2[M][3],poi2,s2[N];
int cnt[N];
int frm[N];
const ll inf=1LL<<62;
void add1(int f,int t,int d)
{
  ++poi1,p1[poi1][0]=t,p1[poi1][1]=s1[f],s1[f]=poi1,p1[poi1][2]=d;
}
void add2(int f,int t,int d)
{
  ++poi2,p2[poi2][0]=t,p2[poi2][1]=s2[f],p2[poi2][2]=d,s2[f]=poi2;
}
bool in[N];
void dis(int s)
{
  dist[s]=0;
  queue<int> que;
  que.push(s);
  in[s]=true;
  for(;!que.empty();)
    {
      int v=que.front();
      in[v]=false;
      que.pop();
      for(int i=s2[v];i;i=p2[i][1])
	{
	  int t=p2[i][0];
	  int tmp=dist[v]+p2[i][2];
	  if(dist[t]>tmp)
	    {
	      dist[t]=tmp;
	      frm[t]=v;
	      if(!in[t])
		in[t]=true,que.push(t);
	    }
	}
    }
}
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  return *c-*d;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int s,t;
  scanf("%d%d",&s,&t);
  for(int i=0;i<m;++i)
    {
      int f,t,d;
      scanf("%d%d%d",&f,&t,&d);
      add1(f,t,d);
      add2(t,f,d);
      path[i][0]=f,path[i][1]=t,path[i][2]=d;
    }
  for(int i=1;i<=n;++i)
    dist[i]=inf;
  dis(t);
  int mm=0;
  for(int i=0;i<m;++i)
    if(dist[path[i][1]]<inf)
      pp[mm][0]=path[i][2]+dist[path[i][1]],
	pp[mm][1]=i,++mm;
  qsort(pp,mm,sizeof(pp[0]),cmp);
  poi1=0;
  memset(s1,0,sizeof(s1));
  for(int i=0;i<mm && i<k;++i)
    {
      int tmp=pp[i][1];
      add1(path[tmp][0],path[tmp][1],path[tmp][2]);
      //cout<<path[tmp][0]<<' '<<path[tmp][1]<<' '<<path[tmp][2]<<endl;
    }
  multimap<ll,int> mapp;
  multimap<ll,int>::iterator ite,ite2;
  int num=0;
  vector<ll> ans;
  if(dist[s]<inf)
    {
      /*ans.push_back(dist[s]);
      ++num;
      for(int i=s,l=0;;)
	{
	  for(int j=s1[i];j;j=p1[j][1])
	    {
	      int t=p1[j][0];
	      ll dis=l+(ll)p1[j][2]+dist[t];
	      if(t!=frm[i])
		{
		  if(mapp.size()==k-1)
		    {
		      ite=mapp.end();
		      --ite;
		      if(ite->first<dis)
			break;
		      mapp.erase(ite);
		    }
		  mapp.insert(make_pair(dis,t));
		  cout<<dis<<' '<<t<<endl;
		}
	    }
	  if(i==t)
	    break;
	  l+=dist[i]-dist[frm[i]];
	  i=frm[i];
	  }*/
      mapp.insert(make_pair(dist[s],s));
      ans.push_back(dist[s]);
      int left=n;
      int c=mapp.size();
      for(;num<k && mapp.size()>0;++num)
	{
	  ite=mapp.begin();
	  int v=ite->second;
	  ll dis=ite->first;
	  if(cnt[v])
	    ans.push_back(dis);
	  else --left;
	  ++cnt[v];
	  mapp.erase(ite),--c;
	  ll lim=inf;
	  for(;c>k-num-1;--c)
	    ite=mapp.end(),--ite,mapp.erase(ite);
	  if(c>=left+k-num-1 && c>0)
	    {
	      ite=mapp.end();
	      --ite;
	      lim=ite->first;
	    }
	  int tt=dis-dist[v];
	  for(int i=s1[v];i;i=p1[i][1])
	    {
	      int t=p1[i][0];
	      //if(t==frm[v] && cnt[v]==0)
	      //continue;
	      ll tmp=path[p1[i][2]][2]+tt;
	      tmp+=dist[t];
	      cout<<'!'<<tmp<<' '<<t<<' '<<v<<endl;
	      if(lim<tmp)
		break;
	      mapp.insert(make_pair(tmp,t));
	      ++c;
	      if(c>left+k-num-1)
		{
		  ite=mapp.end();
		  mapp.erase(--ite);
		  --c;
		  if(c>0)
		    {
		      ite=mapp.end();
		      --ite;
		      lim=ite->first;
		    }
		}
	    }
	  //cnt[v]=1;
	}
      for(int i=0;i<num;++i)
	cout<<ans[i]<<endl;
    }
  for(;num<k;++num)
    printf("NO\n");
  return 0;
}
