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
#define N 19
int p[N+1][1<<N];
void gen()
{
  p[1][0]=0;
  p[1][1]=1;
  for(int i=2;i<=N;++i)
    {
      memcpy(p[i],p[i-1],sizeof(int)*(1<<(i-1)));
      for(int j=1<<(i-1);j<(1<<i);++j)
	p[i][j]=(1<<(i-1))|p[i-1][(1<<i)-j-1];
    }
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  gen();
  //for(int i=0;i<(1<<n);++i)cout<<p[n][i]<<endl;
  for(int i=0;i<(1<<n);++i)
    for(int j=0;j<(1<<m);++j)
      {
	printf("%d",((p[n][i]<<m)|p[m][j]));
	printf("%c",(j==(1<<m)-1?'\n':' '));
      }
  return 0;
}
