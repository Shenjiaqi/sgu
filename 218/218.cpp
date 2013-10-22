#include <cstdio>
#include <cstring>
#define N (500)
#define INF (1e6)
int p[N+1][N+1];
int n,mt;
int pre[N+1];
int vis[N+1];
int test(int v)
{
    for(int i=1;i<=n;++i)
        if(p[v][i]<=mt && !vis[i])
        {
            vis[i]=1;
            if(pre[i]==0 || test(pre[i]))
            {
                pre[i]=v;
                return 1;
            }
        }
    return 0;
}
int mf()
{
    for(int i=1;i<=n;++i)
    {
        memset(vis,0,sizeof(vis));
        if(!test(i))
            return 0;
    }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int f,l;
    f=INF,l=-INF;
    //printf("%d %d\n",f,l);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%d",*(p+i)+j);
            if(f>p[i][j]) f=p[i][j];
            if(l<p[i][j]) l=p[i][j];
        }
    int ans=l;
    for(;f<=l;)
    {
        mt=(f+l)>>1;
        memset(pre,0,sizeof(pre));
        if(mf())
            ans=mt,l=mt-1;
        else f=mt+1;
    }
    mt=ans;
    memset(pre,0,sizeof(pre));
    mf();
    printf("%d",mt);
    for(int i=1;i<=n;++i)
        printf("\n%d %d",pre[i],i);
    return 0;
}
