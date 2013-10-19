#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","r",stdin);
  ll a,b,c;
  cin>>a>>b>>c;
  set<ll> sett;
  sett.insert(1);
  int n(1);
  for(ll i=1;n<=2000000;++n)
    {
      i=(a*i+(i%b))%c;
      if(sett.find(i)!=sett.end())
	{
	  cout<<n;
	  return 0;
	}
      sett.insert(i);
    }
  cout<<-1;
  return 0;
}
