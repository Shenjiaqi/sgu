#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define M (12)
double t1[1<<(1+M)][7],t2[1<<(1+M)][7];
double possi[M+1];
#define ANS (6)
double answ[ANS];
double ansl[ANS];
double possibility[M+1];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<M;++i)
    scanf("%lf",possi+i);
  for(int i=0;i<n;++i)
    {
      double tmp;
      scanf("%lf",&tmp);
      possi[M]+=tmp;
    }
  possi[M]/=(double)n;
  double (*a)[7],(*b)[7];
  a=t1,b=t2;
  a[0][0]=1.0;
  for(int i=0;i<1+M;++i)
    possibility[i]=(double)(1+i)/(double)(M+1);
  for(int i=1;i<12;++i)
    {
      memset(b,0,sizeof(t1));
      for(int j=0;j<(1<<(1+M));++j)
	{
	  for(int l=max(0,i-6);l<min(6,i+1);++l)
	    {
	      int numz=0;
	      for(int z=1<<M;z>1 && (z&j);z>>=1)
		++numz;
	      for(int z=1,y=0;y<M+1;++y,z<<=1)
		{
		  if((z&j)==0)
		    {
		      double tmp=possibility[numz];
		      b[z|j][l+1]+=a[j][l]*possi[y]*tmp;
		      b[z|j][l]+=a[j][l]*((double)1.0-possi[y])*tmp;
		      numz=0;
		    }
		  else ++numz;
		}
	    }
	}
      if(i>=6)
	for(int j=0;j<(1<<(1+M));++j)
	  {
	    answ[i-6]+=b[j][6];
	    ansl[i-6]+=b[j][i-6];
	  }
      double (*t)[7];
      t=a,a=b,b=t;
    }
  for(int i=0;i<ANS;++i)
    printf("%.3lf\n",answ[i]);
  for(int i=ANS-1;i>=0;--i)
    printf("%.3lf\n",ansl[i]);
  return 0;
}
