#include <cstdio>
#include <algorithm>
using namespace std;
#define N (1000)
int p[N][N];
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",*(p+i)+j);
    for(int j=m-1;j>=0;--j)
        for(int i=n-1;i>=0;--i)
        {
            int v=p[i][j];
            if(j<m-1)
            {
                if(i>0)
                    v=p[i-1][j+1];
                else v=p[i][j+1];
            }
            if(i<n-1)
                v=min(v,p[i+1][j]);
            p[i][j]=min(v,p[i][j]);
        }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            printf("%d ",p[i][j]);
        printf("\n");
    }
    return 0;
}
