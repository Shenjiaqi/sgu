#include <cstdio>
#define N (19)
int n;
int p[N][2],poi;
int s[N];
bool d[N];
int df(int v)
{
  int r(1);
  for(int i=s[v];i;i=p[i][1])
    r+=df(p[i][0]);
  return r;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  poi=1;
  for(int i=1;i<=n;++i)
    {
      int j;
      scanf("%d",&j);
      for(;j;--j)
	{
	  int t;
	  scanf("%d",&t);
	  p[poi][0]=t,p[poi][1]=s[i],s[i]=poi++;
	  d[t]=1;
	}
    }
  for(int i=1;i<=n;++i)
    if(!d[i])
      p[poi][0]=i,p[poi][1]=s[0],s[0]=poi++;
  if(n==1)
    printf("1");
  else
  printf("%d",df(0));
  return 0;
}
