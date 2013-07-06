#include <cstdio>
#define N 20
char p[N*N+1];
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    for(int a=0;a<n;++a)
      {
	for(int j=0;j<n;++j)
	  for(int b=0;b<n;++b)
	    p[j*n+b]=(((j+a)%n)*n+((i+b)%n))>=k?'.':'*';
	printf("%s\n",p);
      }
  return 0;
}
