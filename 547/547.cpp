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
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 205
int cost[N];
int p[N*2+1][2],poi;
int s[N];
int col[N];
int dfs(int sta,int frm,int nn,int lim,vector< pair<int,int> > &ter,int l,int vv[],int color)
{
  int r=cost[sta];
  vv[sta/32]|=(1<<(sta%32));
  if(l==1)
    color=sta;
  col[sta]=color;
  if(l==lim)
    ter.push_back(make_pair(cost[sta],sta));
  else
    for(int i=s[sta];i;i=p[i][1])
      if(p[i][0]!=frm && p[i][0]!=nn)
	r+=dfs(p[i][0],sta,nn,lim,ter,l+1,vv,color);
  return r;
}
int test(int sta,int frm,int d,int c,int n,int pattern[])
{
  bool vis[N]={0};
  vis[sta]=true;
  queue<int> que;
  que.push(sta);
  int r(0);
  int vv[N/32+1];
  for(;!que.empty();)
    {
      int v=que.front();
      que.pop();
      vector<pair<int,int> > ter;
      memset(vv,0,sizeof(vv));
      int sum=dfs(v,v,frm,d/2,ter,0,vv,v);
      if(((d&1) || sum>r) && ter.size()>0)
	{
	  sort(ter.begin(),ter.end());
	  if(d&1)
	    {
	      if(c>1)
		{
		  if(d==1)
		    {
		      int zzz=-1;
		      for(int j=s[v];j;j=p[j][1])
			if(p[j][0]!=frm && (zzz=-1 || cost[p[j][0]]>cost[zzz]))
			  zzz=p[j][0];
		      if(zzz>=0 && (sum+cost[zzz])>r)
			{
			  r=sum+cost[zzz];
			  memcpy(pattern,vv,sizeof(vv));
			  pattern[zzz/32]|=(1<<zzz);
			}
		    }
		  else
		    {
		      int mnum=c-2;
		      vector<int> cols;
		      int nc(0),lc=-1;
		      vector< pair<int,int> > ext;
		      bool in[N]={0};
		      for(int i=0;i<ter.size();++i)
			{
			  int cc=col[ter[i].second];
			  if(lc!=cc)
			    lc=cc,++nc;
			  for(int j=s[ter[i].second];j;j=p[j][1])
			    if(p[j][0]!=frm && (vv[p[j][0]/32]&(1<<(p[j][0]%32)))==0)
			      {
				ext.push_back(make_pair(cost[p[j][0]],p[j][0]));
				sum+=cost[p[j][0]];
				col[p[j][0]]=cc;
				if(!in[cc])
				  in[cc]=true,cols.push_back(cc);
			      }
			}
		      sort(ext.begin(),ext.end());
		      if(cols.size()>=1 && nc>1)
			{
			  int kk=-1;
			  for(int i=0;i<cols.size();++i)
			    {
			      int cc=cols[i];
			      int a=ext.size()-1;
			      int del=0;
			      for(;a>=0 && col[ext[a].second]!=cc;--a)
				del+=ext[a].first;
			      --a;
			      int b=ter.size()-1;
			      for(;b>=0 && col[ter[b].second]==cc;--b)
				;
			      --b;
			      for(int left=mnum;(a>=0 || b>=0) && sum-del>r;)
				if(a>=0 && cc!=col[ext[a].second])
				  del+=ext[a].first,--a;
				else if(b>=0 && cc==col[ter[b].second])
				  --b;
				else if(left<=0)
				  {
				    if(a>=0)
				      {
					del+=ext[a].first;
					--a;
				      }
				    if(b>=0)
				      {
					del+=ter[b].first;
					--b;
				      }
				  }
				else
				  {
				    if(a>=0 && b>=0)
				      {
					if(ext[a].first>ter[b].first)
					  --a;
					else --b;
				      }
				    else if(a>=0)
				      --a;
				    else --b;
				    --left;
				  }
			      if(sum-del>r)
				kk=cc,r=sum-del;
			    }
			  if(kk>=0)
			    {
			      memcpy(pattern,vv,sizeof(vv));
			      int a=ext.size()-1,b=ter.size()-1;
			      for(;a>=0 && col[ext[a].second]!=kk;--a)
				;
			      if(a>=0)
				{
				  pattern[ext[a].second/32]|=(1<<(ext[a].second%32));
				  --a;
				}
			      for(;b>=0 && col[ter[b].second]==kk;--b)
				;
			      if(b>=0)
				{
				  pattern[ter[b].second/32]|=(1<<(ter[b].second%32));
				  --b;
				}
			      for(int left=mnum;a>=0 || b>=0;)
				if(a>=0 && col[ext[a].second]!=kk)
				  --a;
				else if(b>=0 && col[ter[b].second]==kk)
				  --b;
				else if(left>0)
				  {
				    int zzz;
				    if(a>=0 && b>=0)
				      {
					if(ext[a].first>ter[b].first)
					  zzz=ext[a].second,--a;
					else zzz=ter[b].second,--b;
				      }
				    else if(a>=0)
				      zzz=ext[a].second,--a;
				    else zzz=ter[b].second,--b;
				    --left;
				    pattern[zzz/32]|=(1<<(zzz%32));
				  }
				else
				  {
				    --a;
				    if(b>=0)
				      pattern[ter[b].second/32]^=(1<<(ter[b].second%32)),--b;
				  }
			    }
			}
		    }
		}
	    }
	  else
	    {
	      int mnum=c;
	      int del(0);
	      if(d>0)
		{
		  bool tmp[N]={0};
		  if(mnum>1)
		    {
		      int k=0;
		      for(int i=ter.size()-1,j=-1;i>=0 && sum-del>r;--i)
			if(mnum<=0)
			  del+=ter[i].first,tmp[ter[i].second]=true;
			else if(k==0)
			  j=col[ter[i].second],++k,--mnum;
			else if(k==1)
			  {
			    if(mnum==1)
			      {
				if(j==col[ter[i].second])
				  del+=ter[i].first,tmp[ter[i].second]=true;
				else ++k,--mnum;
			      }
			    else
			      {
				--mnum;
				if(j!=col[ter[i].second])
				  ++k;
			      }
			  }
			else
			  --mnum;
		      if(k<2)
			del=sum+1;
		      else
			for(int i=0;i<n;++i)
			  if(tmp[i])
			    vv[i/32]^=(1<<(i%32));
		    }
		  else del=sum+1;
		}
	      else if(c<1)
		del=sum+1;
	      if(sum-del>r)
		{
		  r=sum-del;
		  memcpy(pattern,vv,sizeof(vv));
		}
	    }
	}
      for(int i=s[v];i;i=p[i][1])
	if(p[i][0]!=frm && vis[p[i][0]]==false)
	  que.push(p[i][0]),vis[p[i][0]]=true;
    }
  return r;
}
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi;
}
int main()
{
  freopen("in","r",stdin);
  int n,d1,c1,d2,c2;
  scanf("%d%d%d%d%d",&n,&d1,&c1,&d2,&c2);
  int all(0);
  for(int i=0;i<n;++i)
    {
      scanf("%d",cost+i);
      all+=cost[i];
    }
  for(int i=1,f,t;i<n;++i)
    {
      scanf("%d%d",&f,&t);
      --f,--t;
      add(f,t);
      add(t,f);
    }
  int ans=-1,ans1[N/32+1];
  int tt[2][N];
  int pattern[2][N][N/32+1];
  for(int i=0;i<n;++i)
    {
      for(int j=s[i];j;j=p[j][1])
	{
	  tt[0][p[j][0]]=test(p[j][0],i,d1,c1,n,pattern[0][p[j][0]]);
	  tt[1][p[j][0]]=test(p[j][0],i,d2,c2,n,pattern[1][p[j][0]]);
	}
      for(int j=s[i];j;j=p[j][1])
	if(tt[0][p[j][0]])
	  for(int k=s[i];k;k=p[k][1])
	    if(tt[1][p[k][0]] && p[j][0]!=p[k][0])
	      {
		int tmp=tt[0][p[j][0]]+tt[1][p[k][0]];
		if(tmp>ans)
		  {
		    ans=tmp;
		    memcpy(ans1,pattern[0][p[j][0]],sizeof(ans1));
		    for(int l=0;l<N/32+1;++l)
		      ans1[l]|=pattern[1][p[k][0]][l];
		  }
	      }
    }
  if(ans==-1)
    printf("-1");
  else
    {
      printf("%d\n",(all-ans));
      int chk=0;
      for(int i=0;i<n;++i)
	if(0==(ans1[i/32]&(1<<(i%32))))
	  {
	    printf("%d ",(i+1));
	    chk+=cost[i];
	  }
      if(all-ans!=chk)
	{cout<<"!"<<chk<<endl;
	  return 1;}
    }
  return 0;
}
