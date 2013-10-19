#include <cstdio>
#include <cstring>
#define N (1000)
int p[2][2];
int q[2][2];
int ai[N+1+1];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",ai+i);
  int (*a)[2],(*b)[2];
  a=p,b=q;
  if(ai[0]<=2)
    {
      if(ai[0]==0)
	a[0][0]=1;
      else if(ai[0]==1)
	a[0][1]=1,a[1][0]=1;
      else //ai[0]==2
	a[1][1]=1;
      for(int i=1;i<n;++i)
	{
	  memset(b,0,sizeof(p));
	  for(int j=0;j<2;++j)
	    for(int k=0;k<2;++k)
	      {
		int tmp=ai[i]-j-k;
		if(tmp<2 && tmp>=0)
		  b[tmp][j]+=a[j][k];
	      }
	  int (*tmp)[2];
	  tmp=a,a=b,b=tmp;
	}
    }
  printf("%d",a[0][0]+a[0][1]);
  return 0;
}
