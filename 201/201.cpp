#include <cstdio>
#include <cstring>
using namespace std;
#define K (1007)
#define L ('z'-'a'+1)
#define CARRY (100000000)
#define WID (17)
int tra[K][L];
int ans[2][K][WID];
char str[1+L];
int acc[K];
int got[K][L];
int nabs[K][L];
int nstr,nstat,nacc,sta,n;
bool vis[K][L];
void df(int i,int j)
{
  if(vis[i][j])
    return ;
  vis[i][j]=1;
  if(!nabs[i][j])
    tra[i][j]=got[i][j];
  else
    {
      df(got[i][j],j);
      tra[i][j]=tra[got[i][j]][j];
    }
}
void add(int *a,int *b)
{
  for(int i=0;i<WID;++i)
    {
      a[i]+=b[i];
      while(a[i]>=CARRY)
	a[i]-=CARRY,++a[i+1];
    }
}
void pr(int *a)
{
  int i=WID-1;
  for(;i>0 && a[i]==0;--i)
    ;
  printf("%d",a[i]);
  for(--i;i>=0;--i)
    printf("%08d",a[i]);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%s",str);
  nstr=strlen(str);
  scanf("%d%d%d",&nstat,&sta,&nacc);
  for(int i=0;i<nacc;++i)
    scanf("%d",acc+i);
  for(int i=1;i<=nstat;++i)
    for(int j=0;j<nstr;++j)
      scanf("%d",*(got+i)+j);
  for(int i=1;i<=nstat;++i)
    for(int j=0;j<nstr;++j)
      scanf("%d",*(nabs+i)+j);
  scanf("%d",&n);
  for(int i=1;i<=nstat;++i)
    for(int j=0;j<nstr;++j)
      df(i,j);
  for(int i=0;i<nacc;++i)
    ans[0][acc[i]][0]=1;
  for(int i=1;i<=n;++i)
    {
      int frm,to;
      to=i&1;
      frm=1-to;
      memset(ans[to],0,sizeof(ans[0]));
      for(int j=1;j<=nstat;++j)
	for(int k=0;k<nstr;++k)
	  if(tra[j][k])
	    add(ans[to][j],ans[frm][tra[j][k]]);
    }
  pr(ans[n&1][sta]);
  return 0;
}
