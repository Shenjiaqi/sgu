#include <cstdio>
#define N 10
bool p[N][101];
int pp[N][N+1];
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i)
    {
      int k;
      scanf("%d",&k);
      for(int j=0;j<k;++j)
	{
	  int t;
	  scanf("%d",&t);
	  p[i][t]=true;
	  pp[i][++pp[i][0]]=t;
	}
    }
  for(int i=0;i<m;++i)
    {
      int k;
      scanf("%d",&k);
      bool q[N];
      for(int j=0;j<n;++j)
	q[j]=true;
      for(int j=0;j<k;++j)
	{
	  int t;
	  scanf("%d",&t);
	  if(t>0)
	    {
	      for(int l=0;l<n;++l)
		if(q[l] && !p[l][t])
		  q[l]=false;
	    }
	  else
	    for(int l=0;l<n;++l)
	      if(q[l] && p[l][-t])
		q[l]=false;
	}
      int cnt(0);
      for(int j=0;j<n;++j)
	if(q[j])
	  ++cnt;
      printf("%d\n",cnt);
      for(int j=0;j<n;++j)
	if(q[j])
	  {
	    for(int l=0;l<=pp[j][0];++l)
	      printf("%d ",pp[j][l]);
	    printf("\n");
	  }
    }
  return 0;
}
