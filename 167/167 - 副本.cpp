#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 15
#define N 15
#define INF (M*N*1000)
int main()
{
    freopen("in.txt","r",stdin);
    int m,n,k;
    scanf("%d %d %d",&n,&m,&k);
    int v[N+1][M][M];
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
        {
            scanf("%d",&v[i][j][j]);
            if(j)
                for(int a=0;a<j;++a)
                    v[i][a][j]=v[i][j][j]+v[i][a][j-1];
        }
    int p[N+1][M][M][N*M+1][4];
    memset(p,1<<7,sizeof(p));
    for(int i=0;i<m;++i)
        for(int j=i;j<m;++j)
            for(int l=0;l<4;++l)
                p[0][i][j][0][l]=0;
    int ans=-INF;
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            for(int l=j;l<m;++l)
            {
                for(int s=l-j+1;s<=k;++s)
                {
                    for(int u=0;u<=l;++u)
                        for(int v=max(u,j);v<m;++v)
                        {
                            int a=p[i-1][u][v][s-(l-j+1)][0];
                            int b=p[i-1][u][v][s-(l-j+1)][1];
                            int c=p[i-1][u][v][s-(l-j+1)][2];
                            int d=p[i-1][u][v][s-(l-j+1)][3];
                            b=max(a,b);
                            c=max(a,c);
                            d=max(d,max(b,c));
                            if(u<=j && v>=l)
                                p[i][j][l][s][0]=max(a,p[i][j][l][s][0]);
                            if(u>=j && u<=l && v>=l)
                                p[i][j][l][s][1]=max(b,p[i][j][l][s][1]);
                            if(u<=j && v<=l && v>=j)
                                p[i][j][l][s][2]=max(c,p[i][j][l][s][2]);
                            if(u>=j && v<=k)
                                p[i][j][l][s][3]=max(d,p[i][j][l][s][3]);
                        }
                    for(int z=0;z<4;++z)
                        if(p[i][j][l][s][z]>-INF)
                            p[i][j][l][s][z]+=v[i][j][l];
                }
                for(int z=0;z<4;++z)
                    if(ans<p[i][j][l][k][z])
                        ans=p[i][j][l][k][z];
            }
    printf("Oil : %d\n",ans);
    return 0;
}
