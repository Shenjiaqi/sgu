#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  double ans=0.0;
  double c=n;
  c=(c-1)/c;
  for(int i=m;i>0;--i)
    ans=ans*c+(double)1.0;
  printf("%.9lf\n",ans);
  return 0;
}
