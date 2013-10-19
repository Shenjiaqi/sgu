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
#define N 1000
#define K 1000
int p[N][3];
int a[K],b[N];
ll tim[N];
int t[N];
bool cmp(int a,int b)
{
  if(tim[a]==tim[b])
    return p[b][2]<p[a][2];
  return tim[a]<tim[b];
}
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    scanf("%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2);
  FOR(i,0,k)
    scanf("%d",a+i);
  FOR(i,0,n)
    scanf("%d",b+i);
  FOR(i,0,n)
    tim[i]=2*1e7-p[i][0],t[i]=i;
  FOR(i,0,k)
    {
      int q[1000];
      FOR(j,0,n)
	q[j]=3*a[i]*a[i]+5*a[i]*b[j]+2*b[j]*b[j];
      sort(q,q+n,greater<int>());
      sort(t,t+n,cmp);
      FOR(j,0,n)
	tim[t[j]]+=2*1e7-q[j]-p[t[j]][1];
    }
  sort(t,t+n,cmp);
  FOR(i,0,n)
    printf("%d ",t[i]+1);
  return 0;
}
