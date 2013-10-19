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
#define N 200007
int p[N][3],poi;
int s[N+1];
vector<int> ans;
int q[N*2],fq,lq;
void add(int f,int t,int v)
{
  ++poi,p[poi][0]=f,p[poi][1]=s[t],p[poi][2]=v,s[t]=poi;
}
int get()
{
  return q[fq++];
}
int pop()
{
  return q[--lq];
}
void push(int v)
{
  q[lq++]=v;
}
int dfs(int v,int len,int pro)
{
  if(len>(pro<<1))
    {
      int k=get();
      ans.push_back(k);
      p[k][2]=1;
      ++pro;
    }
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(p[i][2])
	pro=dfs(t,len+1,pro+1)-1;
      else
	{
	  push(i);
	  pro=dfs(t,len+1,pro)-p[i][2];
	  if(p[i][2]==0)
	    pop();
	}
    }
  return pro;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  char tmp[70];
  for(int i=1,a,b;i<n;++i)
    {
      scanf("\n%d %d %s",&a,&b,tmp);
      if(tmp[0]=='a')
	{
	  scanf("%s",tmp);
	  add(a,b,0);
	}
      else add(a,b,1);
    }
  dfs(1,0,0);
  printf("%d\n",(int)ans.size());
  for(int i=0;i<ans.size();++i)
    printf("%d ",ans[i]);
  return 0;
}
