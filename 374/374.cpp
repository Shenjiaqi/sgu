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
ll p[42],q[42];
const ll base=(int)1e9;
void mul(int &la,ll a[],int &lb,ll b[])
{
  static ll tmp[42];
  memset(tmp,0,sizeof(tmp));
  for(int i=0;i<la;++i)
    for(int j=0;j<lb;++j)
      {
	tmp[i+j]+=((a[i]*b[j])%base);
	tmp[i+j+1]+=((a[i]*b[j])/base);
      }
  memcpy(b,tmp,sizeof(tmp));
  for(lb=41;lb>=0 && b[lb]==0;--lb)
    ;
  ++lb;
}
void pt(int l,ll a[])
{
  cout<<a[l-1];
  for(int i=l-2;i>=0;--i)
    printf("%09d",(int)a[i]);
}
int main()
{
  freopen("in","r",stdin);
  int a,b,k;
  cin>>a>>b>>k;
  p[0]=a+b;
  q[0]=1;
  int lp=1,lq=1;
  for(int i=0;i<k;++i)
    mul(lp,p,lq,q);
  pt(lq,q);
  return 0;
}
