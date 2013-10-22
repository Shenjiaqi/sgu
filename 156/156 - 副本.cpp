#include <cstdio>
#include <cstring>
using namespace std;
#define N (10000)
#define M (100000)
int p[M*2+1][2],poi,d[N+1],s[N+1];
//int q[M*2+1][3],qoi,c[N*2+1],e[N*2+1];
int c[N+1];
int n,m;
//int father[N*2+1];
int ans[N*2+1],ani;
int fa(int v)
{
    return (father[v]==v?v:father[v]=fa(father[v]));
}
void merge(int a,int b)
{
    a=fa(a);
    b=fa(b);
    if(a<b)
        father[a]=b;
    else if(a>b)
        father[b]=a;
}
void add(int a,int b)
{
    ++e[a];
    ++e[b];
    q[++qoi][0]=b,q[qoi][1]=c[a],c[a]=qoi;
    q[++qoi][0]=a,q[qoi][1]=c[b],c[b]=qoi;
}
void df(int v,int f)
{
    merge(v,f);
    for(int i=s[v];i;i=p[i][1])
        if(d[p[i][0]]>2 && father[p[i][0]]==p[i][0])
            df(p[i][0],f);
        else if(d[p[i][0]]==2)
            add(f,p[i][0]),++d[f];
}
/*
void oroad(int v)
{
    for(;c[v];c[v]=q[c[v]][1])
    {
        if(q[c[v]][2])
            continue;
        q[c[v]][2]=1;
        q[(c[v]&1)?c[v]+1:c[v]-1][2]=1;
        oroad(q[c[v]][0]);
    }
    ans[ani++]=v;
}*/
void orroad(int v,int type)
{
    int *z;
    z=type?s:c;
    for(;z[v];z[v]=p[z[v]][1])
    {
        int tmp=p[z[v]][0];
        if(type && d[tmp]==2)
            continue;
        else if(!type && d[tmp]>=2)
            continue;
        else
        {
            int nt;
            if(type==0)
                nt=1;
            else if(type==1)
                type=2;
            else type=0;
            orroad(tmp,nt);
        }
    }
    ans[ani++]=v;
}
/*
int find(int a,int b)
{
    for(int i=s[a];i;i=p[i][1])
        if(d[p[i][0]]>2 && father[p[i][0]]==b)
            return p[i][0];
    return 0;
}*/
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    /*for(int i=1;i<=n;++i)
        father[i]=i;*/
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        ++d[a],++d[b];
        p[++poi][0]=b,p[poi][1]=s[a],s[a]=poi;
        p[++poi][0]=a,p[poi][1]=s[b],s[b]=poi;
    }
    int nn=n+1;
    int sta;
    for(int i=1;i<=n;++i)
        if(father[i]==i && d[i]>2)
        {
            father[nn]=nn;
            df(i,nn++);
        }
        else if(e[i]==2)
        {
            sta=i;
            for(int j=s[i];j;j=p[j][1])
            {
                if(d[p[j][0]]>2)
                    continue;
                int k=c[i];
                for(;k;k=q[k][1])
                    if(q[k][0]==p[j][0])
                        break;
                if(!k)
                    add(i,p[j][0]);
            }
        }
    for(int i=n+1;i<nn;++i)
        if(e[i]&1)
        {
            printf("-1");
            return 0;
        }
    memcpy(c,s,sizeof(c));
    oroad(sta);
    for(int i=ani-2;i>=0;--i)
        printf("%d ",ans[i]);
    /*
    for(int i=ani-2;i>=0;--i)
        if(ans[i]<=n)
            printf("%d ",ans[i]);
        else
        {
            printf("%d ",find(ans[i+1],ans[i]));
            printf("%d ",find(ans[i-1],ans[i]));
        }*/
    return 0;
}
