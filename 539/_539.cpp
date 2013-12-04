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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 1007
int p[N],q[N];
bool vis[N];
vector<ppi> ans[2];
map<int,int> mapp;
int main()
{
  int n;
  scanf("%d",&n);
  FOR(i,0,n)
    scanf("%d",p+i);
  memcpy(q,p,sizeof(q));
  // memcpy(r,p,sizeof(p));
  sort(q,q+n);
  FOR(i,0,n)
    mapp[p[i]]=0;
  int cnt=0;
  FR(i,mapp)
    i->second=cnt++;
  FOR(i,0,n)
    p[i]=mapp[p[i]];
  FOR(i,0,n)
    q[i]=mapp[q[i]];
  mapp.clear();
  bool fg=true;
  for(int i=0;fg && i<n;++i)
    if(p[i]!=q[i] && !vis[i])
      {
	int j=i+1;
	for(;j<n;++j)
	  if(!vis[j] && p[j]==q[i] && q[j]==p[i])
	    {
	      vis[j]=true;
	      //swap(p[j],p[i]);
	      ans[0].push_back(ppi(i,j));
	      break;
	    }
	if(j>=n)
	  fg=false;
      }
  if(fg)
    {
      if(ans[0].size())
	{
	  printf("1\n%d",(int)ans[0].size());
	  FR(i,ans[0])
	    printf(" %d %d",(1+i->first),(1+i->second));
	}
      else printf("0");
    }
  else
    {
      // cout<<"!"<<endl;
      ans[0].resize(0);
      memset(vis,0,sizeof(vis));
      int num[N]={0};
      FOR(i,0,n)
	++num[q[i]+1];
      FOR(i,1,cnt)
	num[i]+=num[i-1];
      FOR(i,1,n)
	q[i]=q[i-1]+1;
      FOR(i,0,n)
	p[i]=num[p[i]]++;
      int pos[N];
      FOR(i,0,n)
	pos[p[i]]=i;
      // FOR(i,0,n)
      // 	cout<<p[i]<<' '<<q[i]<<endl;
      FOR(i,0,N)
	if(!vis[i])
	  if(p[i]!=q[i])
	    {
	      vector<int> l;
	      l.push_back(i);
	      vis[i]=true;
	      for(int j=p[i];j!=i;j=p[j])
		vis[j]=true,l.push_back(j);
	      reverse(l.begin(),l.end());
	      // FR(j,l)
	      // 	cout<<*j<<' ';cout<<"!"<<endl;
	      if(l.size()==2)
		ans[0].push_back(ppi(l[0],l[1]));
	      else
		{
		  int a=1,b=l.size()-1;
		  for(;a<b;++a,--b)
		    {
		      ans[0].push_back(ppi(l[a],l[b]));
		      ans[1].push_back(ppi(l[b],l[a-1]));
		    }
		  if(b>a-1)
		    ans[1].push_back(ppi(l[b],l[a-1]));
		}
	    }
      // if(ans[1].size())// ???? got PE, This need not to be checked and should always be true.
	printf("2\n");
      // else
      // 	{
      // 	  //printf("1\n");
      // 	  //return 1;
      // 	}
      FOR(i,0,2)
	if(ans[i].size())
	  {
	    printf("%d",(int)ans[i].size());
	    FR(j,ans[i])
	      printf(" %d %d",(1+j->first),(1+j->second));
	    printf("\n");
	  }
    }
  // FOR(i,0,2)
  //   FR(j,ans[i])
  //   swap(r[j->first],r[j->second]);
  // // cout<<endl;
  // FOR(i,0,n)
  //   {
  //     if(i && r[i]<r[i-1])
  // 	return 1;
  //   }
  // cout<<endl;
  return 0;
}
