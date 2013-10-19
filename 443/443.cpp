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
int main()
{
  freopen("in","r",stdin);
  int a,b;
  cin>>a>>b;
  int aa,bb;
  aa=bb=0;
  int la,lb;
  for(int i=2;i<1000;++i)
    {
      if((a%i)==0)
	{
	  aa-=i;
	  for(;0==(a%i);)
	    a/=i;
	  la=i;
	}
      if((b%i)==0)
	{
	  bb-=i;
	  for(;0==(b%i);)
	    b/=i;
	  lb=i;
	}
    }
  if(a==1)
    aa=aa+la+la;
  else aa=a+aa;
  if(b==1)
    bb=bb+lb+lb;
  else bb=b+bb;
  cout<<(aa>bb?'a':'b');
  return 0;
}
