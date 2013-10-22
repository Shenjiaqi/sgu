#include <cstdio>
#define N 3
int n,p[N][N],q[N][N],r[N][N];
bool fill(int x,int y)
{
    if(x>=n)
    {
        if(r[n-1][n-1]==p[n-1][n-1])
            return 1;
        else return 0;
    }
    for(int i=(p[x][y]?1:0);i<10;++i)
    {
        bool b=0;
        q[x][y]=i;
        r[x][y]=0;
        if(x)
        {
            if(q[x][y]<q[x-1][y])
            {
                if(r[x-1][y]<p[x-1][y])
                {
                    i=q[x-1][y];
                    continue;
                }
                ++r[x][y];
            }
            else if(q[x][y]==q[x-1][y])
            {
                if(r[x-1][y]!=p[x-1][y])
                    continue;
            }
            else if(r[x-1][y]+1!=p[x-1][y])
                return 0;
        }
        if(y)
        {
            if(q[x][y]<q[x][y-1])
            {
                if(x==n-1 && r[x][y-1]<p[x][y-1])
                {
                    i=q[x][y-1];
                    continue;
                }
                ++r[x][y];
            }
            else if(q[x][y]==q[x][y-1])
            {
                if(x==n-1 && r[x][y-1]!=p[x][y-1])
                    continue;
            }
            else
            {
                if(x==n-1)
                {
                    if(r[x][y-1]+1!=p[x][y-1])
                        return 0;
                }
                else if(r[x][y-1]+1>p[x][y-1])
                    return 0;
                ++r[x][y-1],b=1;
            }
        }
        if(r[x][y]>p[x][y])
        {
            if(b) --r[x][y-1];
            continue;
        }
        if(fill((y==n-1?x+1:x),(y==n-1?0:y+1)))
            return 1;
        if(b) --r[x][y-1];
    }
    return 0;
}
bool solv()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            int tmp=4;
            if(i==0 || i==n-1)
                --tmp;
            if(j==0 || j==n-1)
                --tmp;
            if(p[i][j]>tmp)
                return 0;
        }
    if(fill(0,0))
        return 1;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",*(p+i)+j);
    if(solv())
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                printf("%d",q[i][j]);
                printf("%c",(j==n-1?'\n':' '));
            }
    else printf("NO SOLUTION");
    return 0;
}
