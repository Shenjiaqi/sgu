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
#define N 31
vector<int> s;
vector<int> p[N];
vector<int> q[N];
vector<int> first[N],last[N];
bool vis[N];
const int mod=10000000;
void pt(vector<int> &a)
{
  if(a.size()==0)
    printf("0");
  else
    {
      int i=a.size()-1;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%07d",a[i]);
    }
}
bool cmp(vector<int> &a,int off)
{
  if(off+s.size()-1>=a.size())
    return false;
  for(int j=0;j<s.size();++j)
    if(a[off+j]!=s[j])
      return false;
  return true;
}
void add(vector<int> &t,int v)
{
  for(int i=0;i<t.size() && v;)
    {
      v+=t[i];
      t[i]=v%mod;
      v/=mod;
    }
  if(v)
    t.push_back(v);
}
void add(vector<int> &t,vector<int> &f)
{
  int i=0;
  int c=0;
  for(;i<f.size();++i,c/=mod)
    {
      if(i>=t.size())
	{
	  c+=f[i];
	  t.push_back(c%mod);
	}
      else
	{
	  c=f[i]+t[i]+c;
	  t[i]=c%mod;
	}
    }
  for(;c;++i,c/=mod)
    if(i>=t.size())
      t.push_back(c%mod);
    else
      {
	c+=t[i];
	t[i]=c%mod;
      }
}
void dfs(int lev)
{
  if(vis[lev])
    return;
  vis[lev]=true;
  for(int i=0;i<p[lev].size();++i)
    if(p[lev][i]>=0)
      {
	dfs(p[lev][i]);
	add(q[lev],q[p[lev][i]]);
      }
    else
      if(s.size()==1 && s[0]==p[lev][i])
	add(q[lev],1);
  if(s.size()>1)
    for(int i=0;i<p[lev].size();++i)
      {
	vector<int> ss;
	if(p[lev][i]>=0)
	  ss=last[p[lev][i]];
	else ss.push_back(p[lev][i]);
	for(int j=0,k=i+1;k<p[lev].size() && j<s.size()-1;++k)
	  if(p[lev][k]<0)
	    ss.push_back(p[lev][k]),++j;
	  else
	    for(int l=0;l<first[p[lev][k]].size() && j<s.size()-1;++l)
	      ss.push_back(first[p[lev][k]][l]),++j;
	for(int j=0;j+s.size()-1<ss.size();++j)
	  if(cmp(ss,j))
	    add(q[lev],1);
      }
  for(int i=0;first[lev].size()<s.size()-1 && i<p[lev].size();++i)
    if(p[lev][i]<0)
      first[lev].push_back(p[lev][i]);
    else
      for(int j=0;j<first[p[lev][i]].size() && first[lev].size()<s.size()-1;++j)
	first[lev].push_back(first[p[lev][i]][j]);
  for(int i=p[lev].size()-1;i>=0 && last[lev].size()<s.size()-1;--i)
    if(p[lev][i]<0)
      last[lev].push_back(p[lev][i]);
    else
      for(int j=last[p[lev][i]].size()-1;j>=0 && last[lev].size()<s.size()-1;--j)
	last[lev].push_back(last[p[lev][i]][j]);
  for(int a=0,b=last[lev].size()-1;a<b;++a,--b)
    swap(last[lev][a],last[lev][b]);
}
int main()
{
  freopen("in","r",stdin);
  int n;
  char tmp[107];
  scanf("%d\n%s\n",&n,tmp);
  for(int i=0;tmp[i]!='\0';++i)
    s.push_back(tmp[i]=='a'?-1:-2);
  for(int i=0;i<n;++i)
    {
      int j;
      scanf("%d",&j);
      for(;j;)
	{
	  char tmp;
	  scanf("%c",&tmp);
	  if(tmp!='a' && tmp!='b' && (tmp<'0' || tmp>'9'))
	    continue;
	  --j;
	  if(tmp=='a' || tmp=='b')
	    p[i].push_back(tmp=='a'?-1:-2);
	  else
	    {
	      int k=tmp-'0';
	      if(EOF!=scanf("%c",&tmp))
		if(tmp<='9' && tmp>='0')
		  k=k*10+tmp-'0';
	      p[i].push_back(k-1);
	    }
	}
    }
  dfs(n-1);
  pt(q[n-1]);
  /*for(int i=0;i<n;++i)
    {
      cout<<endl;
      pt(q[i]);
      cout<<endl;
      }*/
  return 0;
}
