#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N (100)
#define M (1000)
int p[M*2+1][3],poi;
int q[M*2+1][3];
int n,m;
int path[N+1][N+1];
int s[N+1];
void add(int a,int b,int v)
{
    p[poi][0]=b,p[poi][1]=s[a],p[poi][2]=v,s[a]=poi++;
    p[poi][0]=a,p[poi][1]=s[b],p[poi][2]=v,s[b]=poi++;
}
int que[N+2];
bool in[N+1],c[N+1];
bool te[N+1];
int d[N+1];
int pp[N+1][N+1];
bool vis[N+1];
bool df(int f,int v)
{
    vis[f]=1;
    if(f==v)
        return true;
    for(int i=1;i<=n;++i)
    {
        if(vis[i] || !pp[f][i])
            continue;
        --pp[i][f],--pp[f][i];
        if(df(i,v))
            return true;
        ++pp[i][f],++pp[f][i]=1;
    }
    return false;
}
void test(int v)
{
    int dd(0),md(0),pd;
    for(int i=1;i<=n;++i)
        if(path[v][i])
        {
            ++dd;
            if(path[v][i]>md)
                md=path[v][i],pd=i;
        }
    if(dd==0)
        c[v]=1;
    else if(md>1)
        c[v]=1;
    else
    {
        memcpy(pp,path,sizeof(pp));
        for(int i=1;i<=n;++i)
            if(pp[i][v])
            {
                --pp[i][v],--pp[v][i];
                memset(vis,0,sizeof(vis));
                if(df(i,v))
                {
                    c[v]=1;
                    break;
                }
                ++pp[i][v],++pp[v][i];
            }
        /*
        for(int i=1;i<=n;++i)
            pp[i][v]=pp[v][i]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    if(pp[j][i]&&pp[i][k])
                        pp[j][k]=1;
        if(dd>1)
        {
            if(md>1 && df(v))
            {
                c[v]=1;
                return;
            }
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    if(j!=i && i!=v && j!=v && path[v][i] && path[v][j] && pp[i][j])
                    {
                        c[v]=1;
                        return;
                    }
        }
        else if(md>1)
        {
            if(df(pd))
                c[v]=1;
        }*/
    }
}
void chek(int v)
{
    int f,l;
    que[f=0]=v;
    l=1;
    memset(in,0,sizeof(in));
    for(;f<l;++f)
        for(int i=s[que[f]];i;i=p[i][1])
            if(in[p[i][0]]==0 && p[i][2])
                in[que[l++]=p[i][0]]=1,p[i][2]=p[(i&1)?(i+1):(i-1)][2]=0;

    for(int i=2;i<=n;++i)
        if(in[i] && i!=v)
            c[i]=1;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    poi=1;
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b,1);
        ++path[a][b],++path[b][a];
        if(a==1)
            ++d[b];
    }
    memcpy(q,p,sizeof(q));
    for(int i=s[1];i;i=p[i][1])
    {
        if(te[p[i][0]])
            continue;
        te[p[i][0]]=1;
        p[i][2]=p[(i&1)?(1+i):(i-1)][2]=0;
        if(!c[p[i][0]]&&!(1&d[p[i][0]]))
        {
            --path[1][p[i][0]],--path[p[i][0]][1];
            test(p[i][0]);
            ++path[1][p[i][0]],++path[p[i][0]][1];
        }
        chek(p[i][0]);
        memcpy(p,q,sizeof(p));
    }
    test(1);
    for(int i=1;i<=n;++i)
        if(c[i] || (d[i]&1))
            printf("%d ",i);
    return 0;
}
