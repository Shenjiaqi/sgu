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
#define M 100
int p[M];
int main()
{
  freopen("in","r",stdin);
  int m;
  scanf("%d",&m);
  map<int,int> mappp;
  for(int i=0;i<m;++i)
    {
      scanf("%d",p+i);
      mappp[p[i]]=1;
    }
  int n=(1+sqrt(1+8*m))/2;
  map<int,int>mapp;
  mapp[0]=1;
  vector<int> que;
  vector<int> ans;
  que.push_back(0);
  ans.push_back(0);
  for(int i=0;i<m && ans.size()<m;++i)
    if(mapp.find(p[i])==mapp.end())
      {
	bool flag=true;
	for(int j=0;flag && j<ans.size();++j)
	  if(mappp.find(ans[j]^p[i])==mappp.end())
	    flag=false;
	if(flag)
	  {
	    for(int j=0,k=que.size();j<k;++j)
	      if(mapp.find(p[i]^que[j])==mapp.end())
		mapp[p[i]^que[j]]=1,que.push_back(p[i]^que[j]);
	    ans.push_back(p[i]);
	  }
      }
  for(int i=0;i<ans.size();++i)
    printf("%d ",ans[i]);
  return 0;
}
