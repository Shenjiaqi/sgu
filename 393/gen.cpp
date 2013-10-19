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
#define N 13
#define M 50
int main()
{
  freopen("in","r",stdin);
  int n=N,m=M;
  cout<<n<<' '<<m<<endl;
  srand(14);
  map<ppi,int> mapp;
  FOR(i,0,m)
    {
      char a=((rand()%n)+'a');
      char b=((rand()%n)+'a');
      if(mapp.find(ppi(a,b))==mapp.end())
	{
	  mapp[ppi(a,b)]=1;
	  cout<<a<<b<<endl;
	}
      else --i;
    }
  return 0;
}
