#include <cstdio>
#include <cstring>
using namespace std;
#define N (10000)
#define M (100000)
int p[M*2+1][3],poi,d[N+1],s[N+1];
int c[N+1];
int n,m;
bool vis[N+1];
int ans[N*2+1],ani;
int df(int v)
{
    vis[v]=1;
    int r(1);
    for(int i=s[v];i;i=p[i][1])
        if(d[p[i][0]]>2 && !vis[p[i][0]])
            r+=df(p[i][0]);
    return r;
}
void oroad(int v,int type)
{
    vis[v]=1;
    int *z;
    z=(d[v]==2 || !type)?s:c;
    for(;z[v];z[v]=p[z[v]][1])
    {
        if(vis[p[z[v]][0]]) //if(p[z[v]][2])
            continue;
        if(d[v]>2 && type==1 && d[p[z[v]][0]]>2)
            continue;
        if(d[v]>2 && type==0 && d[p[z[v]][0]]==2)
            continue;
        vis[p[z[v]][0]]=1;
        oroad(p[z[v]][0],d[v]==2?0:1);
    }
    //if(sta!=v)
        printf("%d ",v);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        ++d[a],++d[b];
        p[++poi][0]=b,p[poi][1]=s[a],s[a]=poi;
        p[++poi][0]=a,p[poi][1]=s[b],s[b]=poi;
    }
    int sta(0);
    for(int i=1;i<=n;++i)
        if(!vis[i] && d[i]>2)
        {
            sta=i;
            if(df(i)&1)
            {
                printf("-1");
                return 0;
            }
        }
    memset(vis,0,sizeof(vis));
    memcpy(c,s,sizeof(c));
    oroad(1,0);
    return 0;
}
