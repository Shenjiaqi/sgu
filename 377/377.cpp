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
ll a[51],b[51];
const ll base=(ll)1e9;
void pt(ll c[])
{
  int i=49;
  for(;i && c[i]==0;--i)
    ;
  cout<<c[i];
  for(--i;i>=0;--i)
    printf("%09d",(int)c[i]);
}
void po(ll c[],int p)
{
  memset(c,0,sizeof(a));
  c[0]=1;
  for(int i=0;i<p;++i)
    {
      for(int j=0;j<50;++j)
	c[j]<<=1;
      for(int j=0;j<50;++j)
	{
	  c[j+1]+=(c[j]/base);
	  c[j]%=base;
	}
    }
  //pt(c);cout<<endl;
}
void sub1(ll c[])
{
  for(int i=0;;++i)
    if(c[i])
      {
	--c[i];
	break;
      }
    else
      c[i]=base-1;
}
void add(ll c[],ll d[])
{
  for(int i=0;i<50;++i)
    {
      c[i]+=d[i];
      c[i+1]+=(c[i]/base);
      c[i]%=base;
    }
}

int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  po(a,n);
  po(b,m);
  sub1(a);
  sub1(b);
  add(a,b);
  pt(a);
  return 0;
}
