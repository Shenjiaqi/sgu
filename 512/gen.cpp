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
typedef pair<int,int> pp;
int main()
{
  freopen("in","w",stdout);
  int n=10;
  cout<<n<<endl;
  map<pp,int> mapp;
  int mod=15;
  for(int i=0;i<n;)
    {
      int x=rand()%mod;
      int y=rand()%mod;
      if(mapp.find(pp(x,y))==mapp.end())
	{
	  mapp[pp(x,y)]=1;
	  cout<<x<<' '<<y<<endl;
	  ++i;
	}
    }
  return 0;
}
