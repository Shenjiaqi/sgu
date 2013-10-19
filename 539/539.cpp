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
#define N 1000
int p[N],q[N];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",p[i]);
  memcpy(q,p,sizeof(q));
  sort(q,q+n);
  for(;;)
    {
      vector<int> s[N];
      vector<int> tmp;
      for(int i=0;i<n;++i)
	if(q[i]!=p[i])
	  {
	    s[q[i]].push_bacK(i);
	    tmp.push_back(i);
	    ++nn;
	  }
      if(tmp.size()==0)
	break;
      for(int i=0;i<tmp.size();++i)
	{
	  for(int j=i+1;j<tmp.size();++j)
	    if(p[i]==q[j] && p[j]==q[i])
	      
	}
      
    }
}
