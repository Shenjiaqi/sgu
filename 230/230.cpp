#include <cstdio>
#include <cstring>
#define N (100)
#define M (10000)
int d[N+1];
int p[M+1][2],poi;
int s[N+1];
bool vis[N+1];
int q[N+1][N+1];
int n,m;
int main()
{
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    poi=1;
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[poi][0]=b,p[poi][1]=s[a],s[a]=poi,++poi;
        q[a][b]=1;
        ++d[b];
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(q[i][k]&&q[k][j])
                    q[i][j]=1;
    for(int i=1;i<=n;++i)
        if(q[i][i])
        {
            printf("No solution");
            return 0;
        }
    int que[N+1],qoi=0;
    for(int i=1;i<=n;++i)
        if(d[i]==0)
            que[qoi++]=i;
    int ans[N+1];
    for(int i=0,j=1;i<qoi;++i)
    {
        ans[que[i]]=j++;
        for(int k=s[que[i]];k;k=p[k][1])
        {
            --d[p[k][0]];
            if(d[p[k][0]]==0)
            {
                que[qoi++]=p[k][0];
            }
        }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    
    return 0;
}
