#include <cstdio>
#include <cstdlib>
#define N (100000)
int p[N+1];
int g[N+1];
int need[4],n;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",need+1,need+2,need+3,&n);
    for(int i=1;i<=n;++i)
    {
        char t;
        scanf("%c",&t);
        int k(0),p0(0),n0(0);
        for(int j=1;j<=3;++j)
        {
            scanf("%c",&t);
            k=(k<<1)|(t=='B'?1:0);
            if(t=='B') ++n0;
            if(!p0 && t=='B')
                p0=j;
        }
        p[i]=k;
        if(n0==1 && need[p0]>0)
            need[g[i]=p0]-=2;
    }
    for(int i=1;i<=n;++i)
    {
        if(g[i]) continue;
        int p0[3],n0(0);
        for(int j=1,k=1<<2;k;++j,k>>=1)
            if(k&p[i])
                p0[n0++]=j;
        if(n0==2)
            for(int j=0;j<2;++j)
                if(need[p0[j]]>=2)
                {
                    need[g[i]=p0[j]]-=2;
                    break;
                }
    }
    for(int i=1;i<=n;++i)
    {
        if(g[i]) continue;
        int n0(0);
        for(int j=1,k=1<<2;k;++j,k>>=1)
            if(k&p[i])
                ++n0;
        if(n0==3)
            for(int j=1;j<=3;++j)
                if(need[j]>=2)
                {
                    need[g[i]=j]-=2;
                    break;
                }
    }
    for(int i=1;i<=n;++i)
    {
        if(g[i])
            continue;
        for(int j=1;j<4;++j)
            if(need[j]>0)
            {
                --need[g[i]=j];
                break;
            }
    }
    static const char op[]={'P','P','O','S'};
    for(int i=1;i<4;++i)
        if(need[i]>0)
        {
            printf("no solution");
            return 0;
        }
    for(int i=1;i<=n;++i)
        printf("%c",op[g[i]]);
    return 0;
}
