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
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  char tmp[100];
  for(int i=0;i<n;++i)
    {
      scanf("%s",tmp);
      int l=strlen(tmp);
      if((tmp[l-2]=='c'&&tmp[l-1]=='h') || tmp[l-1]=='x' || tmp[l-1]=='s' || tmp[l-1]=='o')
	tmp[l]='e',tmp[l+1]='s',tmp[l+2]='\0';
      else if(tmp[l-1]=='f')
	tmp[l-1]='v',tmp[l]='e',tmp[l+1]='s',tmp[l+2]='\0';
      else if(tmp[l-2]=='f'&&tmp[l-1]=='e')
	tmp[l-2]='v',tmp[l-1]='e',tmp[l]='s',tmp[l+1]='\0';
      else if(tmp[l-1]=='y')
	tmp[l-1]='i',tmp[l]='e',tmp[l+1]='s',tmp[l+2]='\0';
      else tmp[l]='s',tmp[l+1]='\0';
      printf("%s\n",tmp);
    }
  return 0;
}
