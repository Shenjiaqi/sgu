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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100000
int p[N][6];
int num[N];
int q[N*3+7];
int qoi;
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    ++c,++d;
  return *c-*d;
}
void add(int pos,int m)
{
  for(;pos<=qoi;pos+=(pos&(-pos)))
    q[pos]+=m;
}
int que(int pos)
{
  int r(0);
  for(;pos;pos^=(pos&(-pos)))
    r+=q[pos];
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  map<ll,int> mapy;
  FOR(i,0,n)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      p[i][0]=a-b;
      p[i][1]=a+b;
      mapy[a+b]=mapy[(ll)a+b-c]=mapy[(ll)a+b+c]=0;
      p[i][3]=c;
      p[i][5]=i;
    }
  qoi=0;
  FR(i,mapy)
    i->second=++qoi;
  ++qoi;
  FOR(i,0,n)
    {
      p[i][4]=mapy[(ll)p[i][1]+(ll)p[i][3]];
      p[i][2]=mapy[(ll)p[i][1]-(ll)p[i][3]];
      p[i][1]=mapy[p[i][1]];
    }
  qsort(p,n,sizeof(p[0]),cmp);
  multimap<int,int> mapp;
  for(int i=0;i<n;)
    {
      for(;!mapp.empty() && mapp.begin()->first<p[i][0];)
	{
	  int tmp=mapp.begin()->second;
	  add(p[tmp][4]+1,1);
	  add(p[tmp][2],-1);
	  mapp.erase(mapp.begin());
	}
      int ri=i;
      for(;i<n && p[i][0]==p[ri][0];++i)
	{
	  add(p[i][2],1);
	  add(p[i][4]+1,-1);
	  mapp.insert(ppi(p[i][0]+p[i][3],i));
	}
      for(;ri<i;++ri)
	num[ri]=que(p[ri][1])-1;
    }
  multimap<int,int,greater<int> > maa;
  memset(q,0,sizeof(q));
  for(int i=n-1;i>=0;)
    {
      for(;!maa.empty() && maa.begin()->first>p[i][0];)
	{
	  int tmp=maa.begin()->second;
	  add(p[tmp][4]+1,1);
	  add(p[tmp][2],-1);
	  maa.erase(maa.begin());
	}
      int ri=i;
      for(;i>=0 && p[i][0]==p[ri][0];--i)
	num[i]+=que(p[i][1]);
      for(;ri>i;--ri)
	{
	  add(p[ri][2],1);
	  add(p[ri][4]+1,-1);
	  maa.insert(ppi(p[ri][0]-p[ri][3],ri));
	}
    }
  vector<int> ans;
  FOR(i,0,n)
    if(num[i]>=k)
      ans.push_back(p[i][5]+1);
  sort(ans.begin(),ans.end());
  printf("%d\n",(int)ans.size());
  FOR(i,0,ans.size())
    printf("%d ",ans[i]);
  return 0;
}
