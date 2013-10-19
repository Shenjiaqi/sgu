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
#define N 100
int p[N][2];
int main()
{
  freopen("in","r",stdin);
  int a,b,n;
  scanf("%d%d%d",&a,&b,&n);
  for(int i=0,j=b,num;n>i && a>=0 && b>=0;++i)
    {
      scanf("%d",&num);
      if(num>j)
	p[i][1]=num-j,a-=p[i][1];
      else if(num<j)
	p[i][0]=j-num,b-=p[i][0];
      j=num;
    }
  if(a<0 || b<0)
    cout<<"ERROR";
  else
    for(int i=0;i<n;++i)
      cout<<p[i][1]<<' '<<p[i][0]<<endl;
  return 0;
}
