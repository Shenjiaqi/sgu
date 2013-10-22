#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N (102)
int p[(N+2)*(N+2)+1][3],s[N+3],poi;
int bk[(N+2)*(N+2)+1][3];
int in[N+1],out[N+1],n,m,S,T,q[N*N][3],w[(3+N)][(3+N)];
int c[N+3],d[N+3];
void add(int u,int v,int z)
{
    p[++poi][0]=v,p[poi][1]=z,p[poi][2]=s[u],s[u]=poi;
    p[++poi][0]=u,p[poi][1]=0,p[poi][2]=s[v],s[v]=poi;
}
int ma;
bool bfs()
{
    memcpy(c,s,sizeof(c));
    memset(d,0,sizeof(d));
    int que[N+3],f,l;
    f=0,l=1;
    que[f]=S;
    d[S]=1;
    for(;f<l;++f)
    {
        int v=que[f];
        for(int i=c[v];i;i=p[i][2])
            if(p[i][1]>0 && d[p[i][0]]==0)
            {
                d[p[i][0]]=d[v]+1;
                que[l++]=p[i][0];
            }
    }
    return (d[T]>0);
}
int dfs(int v,int f)
{
    if(v==T)
        return f;
    int r=f;
    int i=c[v];
    for(;i;i=p[i][2])
        if(d[v]+1==d[p[i][0]])
        {
            int tmp=dfs(p[i][0],min(f,p[i][1]));
            f-=tmp;
            p[i][1]-=tmp;
            p[(i&1)?(i+1):(i-1)][1]+=tmp;
            if(f==0)
                break;
        }
    c[v]=i;
    return (r-f);
}
int mf()
{
    int r=ma;
    for(;bfs();)
        for(int tmp;(tmp=dfs(S,r));)
        {
            r-=tmp;
            if(r==0)
                return ma;
        }
    return (ma-r);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    S=n+1,T=n+2;
    int s0,t0;
    s0=n+3,t0=n+4;
    for(int i=0;i<m;++i)
    {
        int u,v,z,c;
        scanf("%d %d %d %d",&u,&v,&z,&c);
        q[i][0]=u,q[i][1]=v,q[i][2]=z;
        if(c==0)
            add(u,v,z);
        else
        {
            in[v]+=z;
            out[u]+=z;
        }
    }
    for(int i=1;i<=n;++i)
        if(in[i]<out[i])
            add(i,T,out[i]-in[i]);
        else if(in[i]>out[i])
            add(S,i,in[i]-out[i]);
    add(s0,1,~(1<<31));
    add(n,t0,~(1<<31));
    add(t0,s0,~(1<<31));
    ma=0;
    for(int i=s[S];i;i=p[i][2])
        ma+=p[i][1];
    int tmp=mf();
    if(tmp>=ma)
    {
        tmp=p[s[s0]][1];
        if(tmp<ma)
        {
            s[1]=p[s[1]][2];
            s[n]=p[s[n]][2];
            S=1,T=n;
            int tt=mf();
            if(tt+tmp<ma)
            {
                printf("Impossible");
                return 0;
            }
        }
        printf("%d\n",ma);
        for(int i=1;i<=n;++i)
            for(int j=s[i];j;j=p[j][2])
                w[i][p[j][0]]=p[j][1];
        for(int i=0;i<m;++i)
            printf("%d ",(q[i][2]-w[q[i][0]][q[i][1]]));
    }
    else printf("Impossible");
    return 0;
}
