#include <cstdio>
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  int sum(0);
  for(int i=0;i<m;++i)
    {
      int t;
      scanf("%d",&t);
      sum+=t;
    }
  //  printf("%d\n",sum);
  printf("%d",(n-(((sum+n-1)/n)*n)+sum)%n);
  return 0;
}
