#include <cstdio>
#define N 200
bool p[N+1][N+1];
int c[N+1];
int n,m,ans;
bool df(int v,int col)
{
    if(!c[v])
    {
        c[v]=col;
        if(col==1)
            ++ans;
        for(int i=1;i<=n;++i)
            if(p[v][i] && !df(i,(col==1?2:1)))
                return 0;
    }
    else if(c[v]!=col)
        return 0;
    return 1;
}
bool can()
{
    for(int i=1;i<=n;++i)
        if(!c[i] && !df(i,1))
            return 0;
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        p[a][b]=p[b][a]=1;
    }
    if(!can())
        printf("no");
    else
    {
        printf("yes\n%d\n",ans);
        for(int i=1;i<=n;++i)
            if(c[i]==1)
                printf("%d ",i);
    }
    return 0;
}
