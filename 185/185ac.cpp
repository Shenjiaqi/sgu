#include <cstdio>
#include <cstring>
#define N 401
#define INF (~(1<<31))
int p[N+1][N+1];
bool q[N+1][N+1];
bool bq[N+1][N+1];
int r[2][N+1];
int *dis;
int n,m,S,T;
void add(int a,int b)
{
    bq[a][b]=q[a][b]=1;
}
void sp(int s)
{
    memset(dis,1<<6,(sizeof(int)*(1+N)));
    bool vis[N+1]={0};
    dis[s]=0;
    for(;;)
    {
        int minv=1<<30,minl=s;
        for(int i=1;i<=n;++i)
            if(!vis[i] && minv>dis[i])
                minv=dis[i],minl=i;
        if(vis[minl])
            break;
        vis[minl]=1;
        for(int i=1;i<=n;++i)
            if(!vis[i] && p[minl][i] && p[minl][i]+dis[minl]<dis[i])
                dis[i]=p[minl][i]+dis[minl];
    }
}
int mf()
{
    int pre[N+1];
    int que[N+1];
    bool vis[N+1];
    int ans=0;
    for(;ans<2;)
    {
        memset(vis,0,sizeof(vis));
        que[0]=S;
        vis[S]=1;
        int f=0,l=1;
        for(;f<l && !vis[T];++f)
        {
            int maxl=que[f];
            for(int i=1;i<=n;++i)
                if(!vis[i] && q[maxl][i])
                    vis[i]=1,pre[i]=maxl,que[l++]=i;
        }
        if(!vis[T])
            break;
        ++ans;
        for(int i=T;i!=S;i=pre[i])
            q[pre[i]][i]=0,q[i][pre[i]]=1;
    }
    return ans;
}
bool pt(int v)
{
    if(v==S)
    {
        printf("%d ",v);
        return 1;
    }
    for(int i=1;i<=n;++i)
        if(bq[i][v] && q[v][i] && pt(i))
        {
            q[v][i]=0;
            printf("%d ",v);
            return 1;
        }
    return 0;
}
void cm()
{
    dis=*r;
    sp(S);
    dis=*(r+1);
    sp(T);
    int l=r[0][T];
    bool in[N+1]={0};
    for(int i=1;i<=n;++i)
        if(r[0][i]+r[1][i]==l)
            in[i]=1;
    for(int i=1;i<=n;++i)
        if(in[i])
            for(int j=1;j<=n;++j)
                if(in[j] && p[i][j] && r[0][j]-r[0][i]==p[i][j])
                    add(i,j);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    S=1,T=n;
    for(int i=0;i<m;++i)
    {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        p[a][b]=p[b][a]=d;
    }
    cm();
    if(mf()<2)
        printf("No solution");
    else
    {
        pt(T);
        printf("\n");
        pt(T);
    }
    return 0;
}
