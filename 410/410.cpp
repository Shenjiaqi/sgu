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
#define N 100000
int p[N];
vector<int> qq[1001];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  int m=0;
  for(int i=0;i<n;++i)
    {
      scanf("%d",p+i);
      m=max(m,p[i]);
    }
  int q[1001],qoi=0;
  ll step=m;
  for(int i=0;i<n;++i)
    {
      for(;p[i]<m;++step)
	{
	  p[i]<<=1;
	  if(step<1000 && p[i]<=m)
	    q[qoi]=i+1,++qoi;
	}
      if(m<p[i])
	{
	  if(step<=1000 && p[i]-m<=1000)
	    qq[p[i]-m].push_back(i+1);
	}
    }
  cout<<step<<'\n';
  if(step<=1000)
    {
      for(int i=0;i<qoi;++i)
	printf("science mission to the planet %d\n",q[i]);
      for(int i=1;i<=m;++i)
	{
	  printf("flying mission\n");
	  for(int j=0;j<qq[i].size();++j)
	    printf("science mission to the planet %d\n",qq[i][j]);
	}
    }
  return 0;
}
