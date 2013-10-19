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
#define N 1001
#define M 10007
int p[N];
int d[N];
int q[M][2],qoi;
int s[N];
void add(int a,int b)
{
  ++d[b];
  ++qoi,q[qoi][0]=b,q[qoi][1]=s[a],s[a]=qoi;
}
int main()
{
  freopen("in","r",stdin);
  int n,t;
  scanf("%d%d",&n,&t);
  for(int i=1;i<=n;++i)
    scanf("%d",p+i);
  int m;
  scanf("%d",&m);
  for(int i,j;m--;)
    {
      scanf("%d%d",&i,&j);
      add(i,j);
    }
  multimap<int,int> mapp;
  multimap<int,int>::iterator ite;
  for(int i=1;i<=n;++i)
    if(d[i]==0)
      mapp.insert(make_pair(p[i],i));
  vector<int> ans;
  ll sum=0;
  for(int time=0;time<t && mapp.size()>0;)
    {
      ite=mapp.begin();
      int tmp=ite->first;
      if(tmp+time>t)
	break;
      time+=tmp;
      sum+=time;
      tmp=ite->second;
      ans.push_back(tmp);
      for(int i=s[tmp];i;i=q[i][1])
	if(0==(--d[q[i][0]]))
	  mapp.insert(make_pair(p[q[i][0]],q[i][0]));
      mapp.erase(ite);
    }
  printf("%d ",(int)ans.size());
  cout<<sum<<endl;
  for(int i=0;i<ans.size();++i)
    printf("%d ",ans[i]);
  return 0;
}

