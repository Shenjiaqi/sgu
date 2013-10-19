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
#include <functional>
using namespace std;
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  /*
    int c=(n*m)%3;//0 1 2 3 4
    for(int i=0;i<n;++i)
    {
    for(int j=0;j<m;++j)
    printf("%c",((((i+j)%3)==c)?'#':'0'));
    printf("\n");
    }*/
  int v[3]={0};
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      ++v[(i+j)%3];
  int c=0;
  for(int i=1;i<3;++i)
    if(v[c]>v[i])
      c=i;
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	if((i+j)%3==c)
	  cout<<'#';
	else cout<<'0';
      cout<<endl;
    }
  return 0;
}
