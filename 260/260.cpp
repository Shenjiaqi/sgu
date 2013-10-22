#include <cstdio>
#include <cstring>
#define N (200)
#define S ((1+N)/sizeof(int)+2)
int p[N+1][S];
int q[N+1][S];
int ans[N+1];
int aans[N+1];
int n;
inline void sp(int i,int j)
{
    p[i][j/32]|=(1<<(j%32));
}
inline bool gp(int i,int j)
{
    return (p[i][j/32]&(1<<(j%32)));
}
int gf1(int i)
{
    int r=0;
    for(;r<S;++r)
        if(p[i][r])
            return (r*32+__builtin_ctz(p[i][r]));
    return S*32+1;
}
bool test()
{
    for(int i=1;i<=n;++i)
    {
        int j=gf1(i);
        if(j>S*32)
        {
            if(ans[i])
                return 0;
        }
        else
        {
            for(int k=1;k<=n;++k)
                if(k!=i && gp(k,j))
                {
                    for(int z=0;z<S;++z)
                        p[k][z]^=p[i][z];
                    ans[k]^=ans[i];
                }
        }
    }
    return 1;
}
void pr()
{
    int r[N+1]={0};
    int num(0);
    for(int i=1;i<=n;++i)
        if(ans[i])
        {
            int t=gf1(i);
            if(t<=S*32)
                r[t]=1,++num;
        }
    printf("%d\n",num);
    for(int i=1;i<=n;++i)
        if(r[i])
            printf("%d ",i);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        for(int j=1;j<=t;++j)
        {
            int tt;
            scanf("%d",&tt);
            sp(tt,i);
        }
    }
    for(int i=1;i<=n;++i)
        scanf("%d",ans+i);
    memcpy(q,p,sizeof(q));
    memcpy(aans,ans,sizeof(aans));
    /*for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
            printf("%d ",(int)gp(i,j));
        printf("\n");
    }*/
    if(test())
        pr();
    else
    {
        memcpy(p,q,sizeof(p));
        for(int i=1;i<=n;++i)
            ans[i]=aans[i]?0:1;
        if(test())
            pr();
        else printf("-1");
    }
    return 0;
}
