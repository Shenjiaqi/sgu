#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 15
#define N 15
#define INF (M*N*1000)
int v[N+1][M][M];
int p[N+1][M][M][N*M+1][4];
int pre[N+1][M][M][N*M+1][4];
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,n,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
        {
            scanf("%d",&v[i][j][j]);
            if(j)
                for(int a=0;a<j;++a)
                    v[i][a][j]=v[i][j][j]+v[i][a][j-1];
        }
    memset(p,1<<7,sizeof(p));
    for(int i=0;i<=n;++i)
        for(int j=0;j<m;++j)
            for(int l=j;l<m;++l)
                for(int z=0;z<4;++z)
                    p[i][j][l][0][z]=0;
    int ans=-INF,ansi,ansj,ansl,ansz;
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            for(int l=j;l<m;++l)
            {
                for(int s=l-j+1;s<=min(k,m*(i-1)+l-j+1);++s)
                {
                    for(int u=0;u<=l;++u)
                        for(int v=max(u,j);v<m;++v)
                        {
                            int a=p[i-1][u][v][s-(l-j+1)][0];
                            int b=max(a,p[i-1][u][v][s-(l-j+1)][1]);
                            int c=max(a,p[i-1][u][v][s-(l-j+1)][2]);
                            int d=p[i-1][u][v][s-(l-j+1)][3];
                            d=max(d,max(b,c));
                            if(d<=-INF)
                                continue;
                            if(u>=j && v<=l && a>p[i][j][l][s][0])
                                p[i][j][l][s][0]=a,pre[i][j][l][s][0]=(u<<7)|(v<<2);
                            if(u>=j && u<=l && v>=l && b>p[i][j][l][s][1])
                                p[i][j][l][s][1]=b,pre[i][j][l][s][1]=(u<<7)|(v<<2)|(b==a?0:1);
                            if(u<=j && v<=l && v>=j && c>p[i][j][l][s][2])
                                p[i][j][l][s][2]=c,pre[i][j][l][s][2]=(u<<7)|(v<<2)|(c==a?0:2);
                            if(u<=j && v>=l && d>p[i][j][l][s][3])
                                p[i][j][l][s][3]=d,pre[i][j][l][s][3]=(u<<7)|(v<<2)|(d==max(b,c)?(b>c?(b==a?0:1):(c==a?0:2)):3);
                        }
                    for(int z=0;z<4;++z)
                        if(p[i][j][l][s][z]>-INF)
                            p[i][j][l][s][z]+=v[i][j][l];
                           // printf("%d %d %d %d %d %d\n",i,j,l,s,z,p[i][j][l][s][z]);}
                }
                for(int z=0;z<4;++z)
                    if(ans<p[i][j][l][k][z])
                        ans=p[i][j][l][k][z],ansi=i,ansj=j,ansl=l,ansz=z;
            }
    printf("Oil : %d\n",ans);
    bool ma[N+1][M]={0};
    for(int i=k;i>0;)
    {
        for(int j=ansj;j<=ansl;++j)
            ma[ansi][j]=1;
        int tmp=pre[ansi][ansj][ansl][i][ansz];
        i-=ansl-ansj+1;
        --ansi;
        ansj=tmp>>7;
        ansl=(tmp>>2)&((1<<4)-1);
        ansz=tmp&((1<<2)-1);
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            if(ma[i][j])
                printf("%d %d\n",i,j+1);
    return 0;
}
