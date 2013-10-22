#include <cstdio>
#include <cstring>
#define N (100)
int p[N+1][N+1];
int q[N+1][N+1];
int n,m;
bool can[N+1];
bool vis[N+1];
void ds(int v,int f)
{
    for(int i=1;i<=n;++i)
        if(!vis[i]&&p[v][i]&&!(f==i&&v==1))
        {
            --p[v][i],--p[i][v];
            vis[i]=1;
            ds(i,v);
        }
}
void df(int v,int f)
{
    for(int i=1;!vis[1] && i<=n;++i)
        if(!vis[i] && p[i][v] && !(i==1&&f==1))
        {
            --p[v][i],--p[i][v];
            vis[i]=1;
            df(i,v);
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ++p[a][b],++p[b][a];
    }
    memcpy(q,p,sizeof(q));
    for(int i=2;i<=n;++i)
        if(q[1][i])
        {
            memset(vis,0,sizeof(vis));
            memcpy(p,q,sizeof(p));
            --p[1][i],--p[i][1];
            ds(i,i);
            for(int i=2;i<=n;++i)
                if(vis[i])
                    can[i]=1;
        }
    for(int i=2;i<=n;++i)
        if(!can[i] && q[1][i] && (q[1][i]&1))
            can[i]=1;
    int d(0),md(0);
    for(int i=2;i<=n;++i)
        if(q[1][i])
        {
            ++d;
            if((q[1][i]&1)==0)
                can[1]=1;
            if(md<q[1][i])
                md=q[1][i];
        }
    if(!d || (d>1&&md>1))
        can[1]=1;
    for(int i=2;!can[1] && i<=n;++i)
        if(q[1][i])
        {
            memset(vis,0,sizeof(vis));
            memcpy(p,q,sizeof(p));
            --p[1][i],--p[i][1];
            df(i,1);
            if(vis[1])
                can[1]=1;
        }
    for(int i=1;i<=n;++i)
        if(can[i])
            printf("%d ",i);
    return 0;
}
