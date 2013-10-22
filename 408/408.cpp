#include <cstdio>
int main()
{
  int n;
  scanf("%d",&n);
  int ans(0);
  for(int i=1;i<=n;++i)
    if(i==1)
      ans+=1;
    else
      {
	int tmp=i/2+1;
	ans+=tmp*(i-tmp+2);
      }
  printf("%d",ans);
  return 0;
}
