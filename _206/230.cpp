#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N (60)
#define M (400)
#define INF (10001)
int p[M+1][5];
int q[N];
int fa[N+1];
int n,m;
int cmp2(const void *a,const void *b)
{
    return *((int*)a+3)-*((int*)b+3);
}
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    if(*(c+2)==*(d+2))
        return *(c+3)-*(d+3);
    return *(c+2)-*(d+2);
}
int gfa(int v)
{
    return (v==fa[v]?v:(fa[v]=gfa(fa[v])));
}
void merge(int a,int b)
{
    a=gfa(a);
    b=gfa(b);
    if(a!=b)
        fa[a]=b;
}
int main()
{
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    int ma(0);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p[i][0]=a,p[i][1]=b,p[i][2]=c,p[i][3]=i+1,p[i][4]=c;
        if(i<n)
            ma=max(ma,c);
        else p[i][2]=ma;
    }
    for(;;)
      {
       for(int i=1;i<=n;++i)
            fa[i]=i;
        qsort(p,n-1,sizeof(p[0]),cmp);
	bool con=0;
	for(int i=1;i<n;++i)
	  {
	    merge(p[i][0],p[i][1]);
	    int num(0),mi=min(p[i][2]-1,p[i][2]-p[i-1][2]+1);
	    for(int j=n;j<=m;++j)
	      if(gfa(p[j][0])==gfa(p[j][1]) && p[j][2]>p[j][4])
                ++num,mi=min(mi,p[j][2]-p[j][4]);
	    if(num>0)
	      {
		con=1;
		p[i][2]-=mi;
		for(int j=n;j<=m;++j)
		  if(gfa(p[j][0])==gfa(p[j][1]) && p[j][2]>p[j][4])
                    p[j][2]=max(p[i][2],p[j][4]);
	      }
	  }
	if(!con) break;
      }
    qsort(p,m,sizeof(p[0]),cmp2);
    for(int i=1;i<=m;++i)
        printf("%d\n",p[i][2]);
    return 0;
}
