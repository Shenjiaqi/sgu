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
#define N 2000000
int p[N];
int main()
{
  freopen("in","r",stdin);
  int n,q;
  scanf("%d%d",&n,&q);
  for(int i=0;i<n;++i)
    p[i]=((i+1)%n)<<1;
  int pos=0;
  for(int i=0,dir=0;i<n-1;++i)
    {
      if(dir==0)
	for(int j=1;j<q;++j)
	  pos=p[pos]>>1;
      else for(int j=1;j<q;++j)
	     pos=p[pos]&1?p[(pos-1+n)%n]:(pos-1+n)%n;
      int pre=p[pos]&1?p[(pos-1+n)%n]:(pos-1+n)%n;
      int nxt=p[pos]>>1;
      p[pre]=(p[pre]&1)|(nxt<<1);
      if((p[nxt]&1)==0)
	p[nxt]|=1;
      p[(nxt-1+n)%n]=pre;
      pos=nxt;
      dir=pos&1;
    }
  printf("%d",(pos+1));
  return 0;
}
