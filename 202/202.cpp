#include <stdlib.h>
#include <cstdio>
#define N 64
#define M 65
typedef long long ll;
const ll INF=(ll)(1e17);
ll step[N+1][M+1];
int choice[N+1][M+1];
int occupy[M+1][2];
bool cho[M+1];
int n,m;
int chosed()
{
  for(int i=1;i<=m;++i)
    if(!cho[i])
      return i;
  return 0;
}
void df(int mi,int ma,int nn,int mm,int locate,int dest)
{
  if(mi<ma)
    {
      //printf("!%d %d %d\n",mi,ma,choice[mm][nn]);
      int d=chosed();
      cho[d]=1;
      df(mi,mi+choice[mm][nn]-1,choice[mm][nn],mm,locate,d);
      df(mi+choice[mm][nn],ma,nn-choice[mm][nn],mm-1,locate,dest);
      df(mi,mi+choice[mm][nn]-1,choice[mm][nn],mm,d,dest);
    }
  else//mi==ma,nn==1;
    {
      //printf("!%d %d %d\n",mi,ma,choice[mm][nn]);
      printf("move %d from %d to %d",mi,locate,dest);
      if(occupy[dest][0])
	printf(" atop %d",occupy[dest][0]);
      printf("\n");
      cho[dest]=1;
      occupy[dest][0]=mi;
      if(occupy[dest][1]==0)
	occupy[dest][1]=mi;
      if(occupy[locate][1]>mi)
	occupy[locate][0]=mi+1;
      else occupy[locate][0]=occupy[locate][1]=0,cho[locate]=0;
    }
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=2;i<=m;++i)
    for(int j=1;j<=n;++j)
      step[i][j]=INF;
  for(int i=2;i<=m;++i)
    step[i][1]=1;
  for(int i=3;i<=m;++i)
    for(int j=2;j<=n;++j)
      for(int k=1;k<j;++k)
	{
	  ll tmp=step[i-1][j-k]+(ll)2*step[i][k];
	  if(step[i][j]>tmp)
	    step[i][j]=tmp,choice[i][j]=k;
	}
  printf("%lld\n",step[m][n]);
  occupy[1][0]=1,occupy[1][1]=n;
  cho[1]=1;
  df(1,n,n,m,1,m);
  return 0;
}
