#include <cstdio>
#define N (100000)
int p[N+1][4];
int left[N+2][4];
int need[4],n;
int g[N+1];
bool df(int l)
{
    if(l>n)
    {
        if(need[1]>0 || need[2]>0 || need[3]>0)
            return 0;
        return 1;
    }
    int r=0;
    for(int i=1;i<4;++i)
    {
        if(need[i]>left[l][i])
             return 0;
        if(need[i]<=0)
            ++r;
    }
    if(r==3)
        return 1;
    for(int i=1;i<4;++i)
        if(need[i]>0)
        {
            need[i]-=p[l][i];
            g[l]=i;
            if(df(l+1))
                return 1;
            need[i]+=p[l][i];
        }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
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
    for(int i=n;i>0;--i)
        for(int j=1;j<4;++j)
            left[i][j]=left[i+1][j]+p[i][j];
    if(!df(1))
        printf("no solution");
    else
    {
        static const char q[]={'P','P','O','S'};
        for(int i=1;i<=n;++i)
            printf("%c",q[g[i]]);
    }
    return 0;
}
