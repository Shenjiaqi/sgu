#include <cstdio>
#include <cstring>
using namespace std;
#define N 40
int p[1+N*N*4/2*2][2],poi;
int s[N*N+1];
int q[N+1][N+1];
void add(int a,int b)
{
    p[++poi][0]=b,p[poi][1]=s[a],s[a]=poi;
    p[++poi][0]=a,p[poi][1]=s[b],s[b]=poi;
}
int pre[N*N+1];
bool vis[N*N+1];
bool df(int v)
{
    if(vis[v]==1)
        return 0;
    vis[v]=1;
    for(int i=s[v];i;i=p[i][1])
        if(!pre[p[i][0]] || df(pre[p[i][0]]))
        {
            pre[p[i][0]]=v;
            //pre[v]=p[i][0];
            return 1;
        }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    int r(0);
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        q[x][y]=1;
        ++r;
    }
    if((r&1)==0)
    {
        const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
        for(int i=1;i<=n;++i)
            for(int j=1+(i&1);j<=n;j+=2)
                if(!q[i][j])
                    for(int k=0;k<4;++k)
                    {
                        int x=i+dir[k][0];
                        int y=j+dir[k][1];
                        if(x<1 || y<1 || x>n || y>n)
                            continue;
                        if(!q[x][y])
                            add((i-1)*n+j,(x-1)*n+y);
                    }
        int ans(0);
        for(int i=1;i<=n;++i)
            for(int j=1+(i&1);j<=n;j+=2)
                if(!q[i][j])
                {
                    memset(vis,0,sizeof(vis));
                    if(df((i-1)*n+j))
                        ++ans;
                }
        if(ans*2+r==n*n)
        {
            printf("Yes\n");
            int cnt=2;
            int hv(0),vv(0);
            for(int i=1;i<=n;++i)
                for(int j=1+((i^1)&1);j<=n;j+=2)
                    if(!q[i][j])
                    {
                        q[i][j]=cnt;
                        int tmp=pre[(i-1)*n+j];
                        int x=(tmp-1)/n+1;
                        int y=(tmp-1)%n+1;
                        q[x][y]=cnt;
                        ++cnt;
                        if(x==i)
                            ++hv;
                        else ++vv;
                    }
            printf("%d\n",vv);
            for(int i=1;i<n;++i)
                for(int j=1;j<=n;++j)
                    if(1!=q[i][j] && q[i][j]==q[i+1][j])
                        printf("%d %d\n",i,j);
            printf("%d\n",hv);
            for(int i=1;i<=n;++i)
                for(int j=1;j<n;++j)
                    if(1!=q[i][j] && q[i][j]==q[i][j+1])
                    {
                        printf("%d %d\n",i,j);
                        ++j;
                    }
        }else printf("No");
    }
    else printf("No");
    /*for(int i=1;i<=n;++i)
        {for(int j=1;j<=n;++j)
            printf("%d ",q[i][j]);
        printf("\n");}*/
    return 0;
}
