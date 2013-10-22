#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N (100000)
#define M (14)
int p[N+1];
int giv[N+1];
int need[4],n;
int type[9];
int pos[4];
int q[M*M*2+1][3],qoi;
int s[M+1],x[M+1],d[M+1],que[M+1],S,T;
int g[4][8];
bool bfs()
{
    memset(d,0,sizeof(d));
    memcpy(x,s,sizeof(x));
    int f,l;
    f=0,l=1;
    d[que[0]=S]=1;
    for(;f<l;++f)
        for(int i=x[que[f]];i;i=q[i][1])
            if(!d[q[i][0]] && q[i][2]>0)
                d[que[l++]=q[i][0]]=1+d[que[f]];
    return d[T];
}
int dfs(int v,int f)
{
    if(v==T)
        return f;
    int r=f,i=x[v];
    for(;i;i=q[i][1])
        if(d[q[i][0]]==1+d[v]&&q[i][2]>0)
        {
            int tmp=dfs(q[i][0],min(q[i][2],f));
            q[i][2]-=tmp;
            f-=tmp;
            q[(i&1)?(i+1):(i-1)][2]+=tmp;
            if(f==0)
                break;
        }
    x[v]=i;
    return r-f;
}
void dinic()
{
    for(;bfs();)
        for(;dfs(S,N*2);)
            ;
}
void lk(int a,int b,int v)
{
    q[qoi][0]=b,q[qoi][1]=s[a],q[qoi][2]=v,s[a]=qoi++;
    q[qoi][0]=a,q[qoi][1]=s[b],q[qoi][2]=0,s[b]=qoi++;
}
int main()
{
    freopen("in.txt","r",stdin);
    for(int i=1;i<4;++i)
        scanf("%d",need+i);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        char t;
        scanf("%c",&t);
        int k(0);
        for(int j=1;j<=3;++j)
        {
            scanf("%c",&t);
            k=(k<<1)|(t=='B'?1:0);
        }
        ++type[p[i]=k];
    }
    qoi=1;
    S=9,T=S+1;
    for(int i=1;i<4;++i)
    {
        pos[i]=T+i;
        lk(S,pos[i],need[i]>>1);
    }
    for(int i=1;i<8;++i)
        if(type[i])
        {
            for(int k=1<<2,j=1;k;++j,k>>=1)
                if(k&i)
                    lk(pos[j],i,type[i]);
            lk(i,T,type[i]);
        }
    dinic();
    for(int i=1;i<4;++i)
        for(int j=s[pos[i]];j;j=q[j][1])
            if(q[j+1][2]>0 && q[j][0]<8)
                g[i][q[j][0]]+=q[j+1][2];
    for(int i=1;i<4;++i)
        for(int j=1;j<8;++j)
            need[i]-=2*g[i][j];
    int all(0);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<4;++j)
            if(g[j][p[i]]>0)
            {
                --g[j][p[i]],giv[i]=j;
                break;
            }
        if(!giv[i])
            ++all;
    }
    int ned(0);
    for(int i=1;i<4;++i)
        if(need[i]>0)
            ned+=need[i];
    if(all<ned)
        printf("no solution");
    else
    {
        char op[]={'S','P','O','S'};
        for(int i=1;i<=n;++i)
        {
            if(!giv[i])
                for(int j=1;j<4;++j)
                    if(need[j]>0)
                    {
                        --need[giv[i]=j];
                        break;
                    }
            printf("%c",op[giv[i]]);
        }
    }
    return 0;
}
