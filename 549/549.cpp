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
#define N 4000
#define K 4000
vector<int> p[N+1];
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    {
      int m,c;
      scanf("%d%d",&m,&c);
      p[m].push_back(c);
    }
  vector<ppi> q;
  FOR(i,0,N+1)
    if(p[i].size())
      q.push_back(ppi((int)p[i].size(),i));
  if(q.size()>=k)
    {
      sort(q.begin(),q.end(),greater<ppi>());
      int ti;
      for(int i=0;;)
	{
	  for(int j=q[i].first;i<q.size() && q[i].first==j;++i)
	    ;
	  if(i>=k)
	    {
	      ti=i;
	      break;
	    }
	}
      int t=q[ti-1].first;
      vector<ppi>qq;
      FOR(i,0,ti)
	{
	  int k=q[i].second;
	  sort(p[k].begin(),p[k].end(),greater<int>());
	  int val(0);
	  FOR(j,0,t)
	    val+=p[k][j];
	  qq.push_back(ppi(val,k));
	}
      sort(qq.begin(),qq.end(),greater<ppi>());
      int s(0);
      FOR(i,0,k)
	s+=qq[i].first;
      printf("%d %d",t,s);
    }
  else printf("0 0");
  return 0;
}
