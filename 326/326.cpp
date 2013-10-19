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
#define N 20
ll w[N];
ll r[N];
ll a[N][N];
ll d[N];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    cin>>w[i];
  for(int i=0;i<n;++i)
    cin>>r[i];
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      {
	cin>>a[i][j];
	d[i]+=a[i][j];
      }
  w[0]+=r[0]-d[0];
  for(int i=1;i<n;++i)
    w[i]-=(r[i]-d[i]);
  for(int i=1;i<n;++i)
    w[0]+=a[0][i];
  for(int i=1;i<n;++i)
    for(int j=1;j<n && w[i]<w[0];++j)
      if(a[i][j])
	{
	  int tmp=min(w[0]-w[i],a[i][j]);
	  a[i][j]-=tmp,a[j][i]-=tmp;
	  w[i]+=tmp;
	}
  for(int i=1;i<n;++i)
    for(int j=1;j<n;++j)
      if(a[i][j])
	{
	  printf("NO");
	  return 0;
	}
  printf("YES");
  return 0;
}
