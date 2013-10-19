#include <cstdio>
#include <stdlib.h>
#include <vector>
using namespace std;
#define N 64
#define M 65
typedef long long ll;
const ll INF=(ll)(1e17);
ll step[N+1][M+1];
int choice[N+1][M+1];
vector <int> sta[N+1];
int n,m;
int chosed(int vv,int vo,int ma)
{
  for(int i=1;i<=m;++i)
    if(i!=vo && i!=vv)
      {
	int tmp=sta[i].size();
	if(tmp==0 || sta[i][tmp-1]>ma)
	  return i;
      }
  //printf("! %d %d %d %d",vo,vv,ma,sta[1][0]);
  exit(1);
  return 0;
}
void add(int v,int c)
{
  sta[c].push_back(v);
}
void df(int mi,int ma,int mm,int nn,int locate,int dest)
{
  if(mi<ma)
    {
      int d=chosed(locate,dest,ma);
      df(mi,mi+choice[mm][nn]-1,mm,choice[mm][nn],locate,d);
      df(mi+choice[mm][nn],ma,mm-1,nn-choice[mm][nn],locate,dest);
      df(mi,mi+choice[mm][nn]-1,mm,choice[mm][nn],d,dest);
    }
  else
    {
      printf("move %d from %d to %d",mi,locate,dest);
      int tmp=sta[dest].size();
      if(tmp>0)
	printf(" atop %d",sta[dest][tmp-1]);
      printf("\n");
      sta[dest].push_back(mi);
      sta[locate].pop_back();
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
  for(int i=n;i>0;--i)
    sta[1].push_back(i);
  df(1,n,m,n,1,m);
  return 0;
}
