#include <cstdio>
#define N (100000)
int p[N+1][4];
int need[4],n;
int g[N+1];
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d%d",need+1,need+2,need+3,&n);
    for(int i=1;i<=n;++i)
    {
        char t;
        scanf("%c",&t);
        for(int j=1;j<4;++j)
        {
            scanf("%c",&t);
            p[i][j]=(t=='B'?2:1);
            if(p[i][j]==2) ++p[i][0];
        }
    }

    for(int i=1;i<=n;++i)
        if(p[i][0]==1)
            for(int j=1;j<4;++j)
                if(p[i][j]==2 && need[j]>0)
                {
                    need[g[i]=j]-=2;
                    break;
                }
    for(int i=1;i<=n;++i)
        if(!g[i] && p[i][0]==2)
            for(int j=1;j<4;++j)
                if(p[i][j]==2 && need[j]>1)
                {
                    need[g[i]=j]-=2;
                    break;
                }
    for(int i=1;i<=n;++i)
        if(!g[i] && p[i][0]==3)
            for(int j=1;j<4;++j)
                if(need[j]>1)
                {
                    need[g[i]=j]-=2;
                    break;
                }
    for(int i=1;i<=n;++i)
        if(!g[i])
            for(int j=1;j<4;++j)
                if(need[j]>0)
                {
                    --need[g[i]=j];
                    break;
                }
    static const char q[]={'S','P','O','S'};
    for(int i=1;i<4;++i)
        if(need[i]>0)
        {
            printf("no solution");
            return 0;
        }
    for(int i=1;i<=n;++i)
        printf("%c",q[g[i]]);
    return 0;
}
