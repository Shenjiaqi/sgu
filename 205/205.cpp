#include <cstdio>
#include <cstdlib>
#define INF (2000000000)
#define N (128)
#define M (1000)
int p[N][N];
int q[N][N];
int r[M];
int u[N][N];
int (*t1)[N],(*t2)[N];
int re[M][N][2];
void df(int lev,int x,int y)
{
  if(lev<=0)
    return;
  //  printf("\n!%d %d %d\n",lev,x,y);
  df(lev-1,re[lev-1][x][0],re[lev-1][x][1]);
  printf("%d ",y);
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",r+i);
  int m,s;
  scanf("%d%d",&m,&s);
  for(int i=0;i<m;++i)
    for(int j=0;j<s;++j)
      {
	scanf("%d",*(u+i)+j);
	q[i][j]=p[i][j]=INF;
      }
  t1=q,t2=p;
  for(int i=0;i<s;++i)
      q[0][i]=abs(r[0]-u[0][i]);
  int tmpv[N];
  for(int i=1;i<n;++i)
    {
      for(int j=0;j<m;++j)
	tmpv[j]=INF;
      for(int j=0;j<m;++j)
	for(int k=0;k<s;++k)
	  {
	    if(tmpv[k%m]>t1[j][k])
	      tmpv[k%m]=t1[j][k],re[i][k%m][0]=j,re[i][k%m][1]=k;
	    t2[j][k]=INF;
	  }
      for(int j=0;j<m;++j)
	if(tmpv[j]<INF)
	  for(int k=0;k<s;++k)
	    t2[j][k]=tmpv[j]+abs(u[j][k]-r[i]);
      int (*tt)[N];
      tt=t1,t1=t2,t2=tt;
    }
  int ans=INF,x,y;
  for(int i=0;i<m;++i)
    for(int j=0;j<s;++j)
      if(ans>t1[i][j])
	x=i,y=j,ans=t1[i][j];
  printf("%d\n",ans);
  df(n,x,y);
  return 0;
}
