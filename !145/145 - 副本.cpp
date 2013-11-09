#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
#define N (100)
#define K (500)
int p[N+1];
int n,m,k;
int q[N*N*2+1][3],s[N+1],poi,S,T;
int plen[N+1];
void add(int f,int t,int c)
{
    q[++poi][0]=t,q[poi][2]=c,q[poi][1]=s[f],s[f]=poi;
    q[++poi][0]=f,q[poi][2]=c,q[poi][1]=s[t],s[t]=poi;
}
void sp()
{
    bool vis[N+1]={0};
    memset(plen,1<<6,sizeof(plen));
    plen[T]=0;
    for(;;)
    {
        int v,minl=1<<30;
        for(int i=1;i<=n;++i)
            if(!vis[i] && minl>plen[i])
                v=i,minl=plen[i];
        if(minl==(1<<30))
            break;
        vis[v]=1;
        for(int i=s[v];i;i=q[i][1])
            if(!vis[q[i][0]] && plen[q[i][0]]>minl+q[i][2])
                plen[q[i][0]]=minl+q[i][2];
    }
}
int mc,num;
bool vis[N+1];
void dfs(int i,int c)
{
    vis[i]=1;
    if(c+plen[i]<=mc)
    {
        if(i==T)
            ++num;
        else
            for(int j=s[i];j && num<=k;j=q[j][1])
                if(!vis[q[j][0]])
                    dfs(q[j][0],c+q[j][2]);
    }
    vis[i]=0;
}
int ans[N+1],nnn;
bool pt(int v,int c,int nn)
{
    if(c+plen[v]>mc)
        return 0;
    if(v==T)
    {
        if(c!=mc)
            return 0;
        printf("%d %d\n",mc,nn);
        ans[nn]=v;
        nnn=nn;
        return 1;
    }
    vis[v]=1;
    for(int i=s[v];i;i=q[i][1])
        if(!vis[q[i][0]] && pt(q[i][0],c+q[i][2],nn+1))
        {
            ans[nn]=v;
            return 1;
        }
    vis[v]=0;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i)
    {
        int x,y,mon;
        scanf("%d %d %d",&x,&y,&mon);
        add(x,y,mon);
        mc=max(mc,mon);
    }
    mc*=n;
    scanf("%d %d",&S,&T);
    sp();
    int f,l;
    for(f=0,l=mc;f<=l;)
    {
        mc=(f+l)>>1;
        num=0;
        dfs(S,0);
        if(num>=k)
            l=mc-1;
        else
            f=mc+1;
    }
    mc=l+1;
    pt(S,0,1);
    for(int i=1;i<=nnn;++i)
        printf("%d ",ans[i]);
    return 0;
}
