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
int dfs(int sta,int frm,int nn,int lim,vector< pair<int,int> > &ter,int nter[][N/32+2],int l,int vv[],int color)
{
  int r=cost[sta];
  vv[sta/32]|=(1<<(sta%32));
  if(l==1)
    color=sta;
  col[sta]=color;
  if(l==lim)
    {
      ter.push_back(make_pair(cost[sta],sta));
      /*int mm,mmi=-1;
      memset(nter[color],0,sizeof(int)*(N/32+2));
      for(int i=s[sta];i;i=p[i][1])
	if(p[i][0]!=frm && p[i][0]!=nn)
	  {
	    nter[color][0]+=cost[p[i][0]];
	    nter[color][p[i][0]/32+1]|=(1<<(p[i][0]%32));
	    }*/
    }
  else
    for(int i=s[sta];i;i=p[i][1])
      if(p[i][0]!=frm && p[i][0]!=nn)
	r+=dfs(p[i][0],sta,nn,lim,ter,nter,l+1,vv,color);
  return r;
}
int test(int sta,int frm,int d,int c,int n,int pattern[])
{
  bool vis[N]={0};
  int nter[N][N/32+2];
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
      int sum=dfs(v,v,frm,d/2,ter,nter,0,vv,v);
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
		      int mnum=c-1;
		      bool in[N]={0};
		      vector<int> cols;
		      int ncols[N][2]={0};
		      int dell[N]={0};
		      int nc(0),lc=-1;
		      for(int i=0;i<ter.size();++i)
			{
			  int cz=col[ter[i].second];
			  int nz=nter[cz][0];
			  if(lc!=cz)
			    lc=cz,++nc;
			  if(nz>0 && !in[cz])
			    {
			      in[cz]=true;
			      cols.push_back(cz);
			    }
			  dell[i]=(i>0?dell[i-1]:0)+ter[i].first;
			}
		      if(frm==6 && v==2 && d==3){
			for(int i=0;i<ter.size();++i)
			  cout<<(1+ter[i].second)<<' ';cout<<endl;}
		      int add[N]={0};
		      if(cols.size()>=1 && nc>1)
			{
			  for(int i=ter.size()-1;i>=0;--i)
			    {
			      int cz=col[ter[i].second];
			      ++ncols[cz][0];
			      if((int)ter.size()-i-ncols[cz][0]>=mnum)
				{
				  ncols[cz][1]=i+(int)ter.size()-i-ncols[cz][0]-mnum;
				  ncols[cz][0]=1e7;
				  add[cz]+=ter[i].first;
				}
			      else if(ncols[cz][0]>1000)
				add[cz]+=ter[i].first;
			    }
			  int kk=-1;
			  for(int j=0;j<cols.size();++j)
			    {
			      int tz=cols[j];
			      if((int)ter.size()-ncols[tz][0]>=mnum)
				ncols[tz][1]=(int)ter.size()-ncols[tz][0]-1-mnum;
			      else if(ncols[tz][0]<1000)
				ncols[tz][1]=-1;
			      int z=ncols[tz][1]>=0?dell[ncols[tz][1]]:0;
			      if(sum-z+nter[tz][0]+add[tz]>r)
				kk=tz,r=sum-z+nter[tz][0]+add[tz];
			    }
			  if(kk>=0)
			    {
			      memcpy(pattern,vv,sizeof(vv));
			      for(int j=0;j<=ncols[kk][1];++j)
				if(col[ter[j].second]!=kk )
				  pattern[ter[j].second/32]^=(1<<(ter[j].second%32));
			      for(int l=0;l<N/32+1;++l)
				pattern[l]|=nter[kk][l+1];
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
	    printf("%d ",i+1);
	    chk+=cost[i];
	  }
      if(all-ans!=chk)
	{cout<<"!"<<endl;
	  return 1;}
    }
  return 0;
}
