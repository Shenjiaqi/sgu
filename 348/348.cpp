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
ll getminshift(ll v,int &s,const ll high,const ll mask,int w)
{
  int j=0;
  int mi=0;
  ll minv=mask;
  for(ll i=1;i&mask;i<<=1,++j)
    {
      if(high&v)
	{
	  if(v<minv)
	    minv=v,mi=j;
	  v=(v<<1)|1;
	}
      else v<<=1;
      v&=mask;
    }
  s=(s+mi)%w;
  return minv;
}
int main()
{
  freopen("in","r",stdin);
  ll n;
  cin>>n;
  ll c=1;
  int w=63;
  for(c<<=(w-1);(c&n)==0;c>>=1)
    --w;
  ll msk(0);
  for(ll i=c;i;i>>=1)
    msk|=i;
  ll ans=0;
  for(int shift=0;;)
    {
      n=getminshift(n,shift,c,msk,w);
      ans=max(ans,n);
      if(shift==0)
	break;
      n=n-((((n^c)>>shift)+1)<<shift);
    }
  cout<<ans;
  return 0;
}
