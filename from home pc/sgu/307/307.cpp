#include <cstdio>
#define N 300
int p[N][N];
int q[N][N];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;++i)
    for(int j=0;j<n-1;++j)
      scanf("%d",*(p+i)+j);
  for(int i=0;i<n-1;++i)
    for(int j=n-3;j>=0;--j)
      p[i][j]-=p[i][j+1];
  for(int i=0;i<n-1;++i)
    for(int j=n-3;j>=0;--j)
      p[j][i]-=p[j+1][i];
  for(int i=0;i<2;++i)
    {
      q[n-1][n-1]=i;
      for(int j=0;j<2;++j)
	{
	  q[n-2][n-1]=j;
	  for(int k=0;k<2;++k)
	    {
	      q[n-1][n-2]=k;
	      q[n-2][n-2]=p[n-2][n-2]-q[n-1][n-1]-q[n-2][n-1]-q[n-1][n-2];
	      if(q[n-2][n-2]<=1 && q[n-2][n-2]>=0)
		{
		  int l;
		  for(l=n-3;l>=0;--l)
		    {
		      q[l][n-1]=p[l][n-2]-q[l+1][n-2]-q[l+1][
}
