#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define N 400
#define INF (~(1<<31))
int p[N+1][N+1];
int r[2][N+1];
int *dis;
int s[N+1],x[N+1];
int q[N*N*2+1][3],poi;
int d[N+1];
int n,m,S,T;
void add(int a,int b)
{
    ++poi;
    q[poi][0]=b,q[poi][1]=s[a],q[poi][2]=1,s[a]=poi;
    ++poi;
    q[poi][0]=a,q[poi][1]=s[b],q[poi][2]=1,s[b]=poi;
}
void sp(int s)
{
    memset(dis,1<<6,sizeof(r[0]));
    bool vis[N]={0};
    dis[s]=0;
    for(;;)
    {
        int minv=1<<30,minl=0;
        for(int i=1;i<=n;++i)
            if(!vis[i] && minv>dis[i])
                minv=dis[i],minl=i;
        if(vis[minl])
            break;
        vis[minl]=1;
        for(int i=1;i<=n;++i)
            if(p[minl][i] && p[minl][i]+dis[minl]<dis[i])
                dis[i]=p[minl][i]+dis[minl];
    }
}
bool bfs()
{
    memset(d,0,sizeof(d));
    memcpy(x,s,sizeof(x));
    d[S]=1;
    int *que=dis,f,l;
    f=0,l=1;
    que[0]=S;
    for(;f<l;++f)
        for(int i=x[que[f]];i;i=q[i][1])
            if(q[i][2]>0 && !d[q[i][0]])
            {
                d[q[i][0]]=1+d[que[f]];
                que[l++]=q[i][0];
            }
    return (d[T]>0);
}
int dfs(int v,int f)
{
    if(v==T)
        return f;
    int r=f,i=x[v];
    for(;i;i=q[i][1])
    {
        if(q[i][2]<=0 || d[q[i][0]]!=d[v]+1)
            continue;
        int tmp=dfs(q[i][0],min(f,q[i][2]));
        q[i][2]-=tmp;
        q[i+((i&1)?1:-1)][2]+=tmp;
        f-=tmp;
        if(f==0)
            break;
    }
    x[v]=i;
    return (r-f);
}
int mf()
{
    int ans=0;
    for(;bfs();)
        for(int tmp;tmp=dfs(S,INF);)
        {
            ans+=tmp;
            if(ans>=2)
                return ans;
        }
    return ans;
}
void pt(int v)
{
    printf("%d ",v);
    for(int i=s[v];i;i=q[i][1])
        if(q[i][2]==0)
        {
            pt(q[i][0]);
            s[v]=q[i][1];
            return;
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        p[a][b]=p[b][a]=d;
    }
    S=1,T=n;
    dis=*r;
    sp(S);
    dis=*(r+1);
    sp(T);
    int l=r[0][n];
    bool in[N+1]={0};
    for(int i=1;i<=n;++i)
        if(r[0][i]+r[1][i]==l)
            in[i]=1;
    for(int i=1;i<=n;++i)
        if(in[i])
            for(int j=1;j<=n;++j)
                if(in[j] && p[i][j] && r[0][j]-r[0][i]==p[i][j])
                    add(i,j);
    if(mf()<2)
        printf("No solution");
    else
    {
        pt(S);
        printf("\n");
        pt(S);
    }
    return 0;
}
