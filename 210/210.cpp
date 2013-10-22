#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N (400)
bool p[N+1][N+1];
int n;
int q[N+1][2];
int vis[N+1];
int an[N+1];
int ans[N+1];
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    if(*c==*d)
        return (*(c+1)<*(d+1)?1:-1);
    return (*c<*d?1:-1);
}
bool df(int v)
{
    for(int i=1;i<=n;++i)
        if(p[v][i] && !vis[i])
        {
            vis[i]=1;
            if(!an[i] || df(an[i]))
            {
                an[i]=v;
                return 1;
            }
        }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        q[i][0]=t,q[i][1]=i;
    }
    for(int i=1;i<=n;++i)
    {
        int j;
        scanf("%d",&j);
        for(int t;j>0;--j)
        {
            scanf("%d",&t);
            p[i][t]=1;
        }
    }
    qsort(q+1,n,sizeof(q[0]),cmp);
    for(int i=1;i<=n;++i)
    {
        memset(vis,0,sizeof(vis));
        df(q[i][1]);
    }
    for(int i=1;i<=n;++i)
        ans[an[i]]=i;
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}
