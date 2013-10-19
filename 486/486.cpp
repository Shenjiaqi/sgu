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
  char p[4],q[4];
  for(int i=0;i<4;++i)
    cin>>p[i];
  for(int i=0;i<4;++i)
    cin>>q[i];
  int bull(0),cow(0);
  for(int i=0;i<4;++i)
    if(p[i]==q[i])
      ++bull,p[i]=q[i]=0;
  for(int i=0;i<4;++i)
    if(q[i])
      for(int j=0;j<4;++j)
	if(q[i]==p[j])
	  {
	    ++cow,p[j]=0;
	    break;
	  }
  cout<<bull<<' '<<cow;
  return 0;
}
