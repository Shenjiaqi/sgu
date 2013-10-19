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
#define N 25
int S,T;
int p[(N*N*2+N*N*2*N+2)*2+1][4],poi;
int s[N*N*2+2];
int out[N*N];
bool in[N*N*2+2];
int dist[N*N*2+2];
int pre[N*N*2+2][2];
void add(int f,int t,int flow,int cost)
{
  //cout<<f<<' '<<t<<' '<<flow<<' '<<cost<<endl;
  ++poi,p[poi][0]=t,p[poi][1]=flow,p[poi][2]=cost,p[poi][3]=s[f],s[f]=poi;
  ++poi,p[poi][0]=f,p[poi][1]=0,p[poi][2]=-cost,p[poi][3]=s[t],s[t]=poi;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  S=N*N*2,T=S+1;
  for(int i=0;i<n;++i)
    {
      string tmp;
      cin>>tmp;
      for(int j=0;j<m;++j)
	if(tmp[j]=='*')
	  {
	    //cout<<(i*m+j)<<endl;
	    add((i*m+j)+N*N,T,1,0);
	    for(int k=0;k<n;++k)
	      {
		++out[k*m+j];
		add(k*m+j,i*m+j+N*N,1,0);
	      }
	    for(int k=0;k<m;++k)
	      if(k!=j)
		{
		  ++out[i*m+k];
		  add(i*m+k,i*m+j+N*N,1,0);
		}
	  }
    }
  for(int i=0;i<n*m;++i)
    if(out[i])
      add(S,i,out[i],(1e9)/(50*out[i]));
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	cout<<out[i*m+j]<<' ';
      cout<<endl;
    }
  queue<int> que;
  for(;;)
    {
      memset(dist,1<<6,sizeof(dist));
      in[S]=true;
      dist[S]=0;
      que.push(S);
      pre[T][0]=-1;
      for(;!que.empty();)
	{
	  int f=que.front();
	  for(int i=s[f];i;i=p[i][3])
	    {
	      int t=p[i][0];
	      if(p[i][1] && (dist[t]>dist[f]+p[i][2]))
		{
		  dist[t]=dist[f]+p[i][2];
		  pre[t][0]=f;
		  pre[t][1]=i;
		  if(!in[t])
		    {
		      que.push(t);
		      in[t]=true;
		    }
		}
	    }
	  que.pop();
	  in[f]=false;
	}
      if(pre[T][0]==-1)
	break;
      for(int i=T;;i=pre[i][0])
	{
	  --p[pre[i][1]][1];
	  ++p[((pre[i][1]&1)?1:-1) + pre[i][1]][1];
	  if(i==S)
	    break;
	}
      //cout<<endl;
    }
  int ans(0);
  int sum(0);
  for(int i=s[S];i;i=p[i][3])
    if(p[i+1][1]>0)
      {
	++ans;
	sum+=p[i+1][1]*p[i][2];
      }
  cout<<(sum/(1e9/50))<<endl;
  cout<<ans;
  return 0;
}
