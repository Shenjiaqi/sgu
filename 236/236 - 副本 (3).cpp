#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N (50)
int bk[N+1][N+1][2];
int p[N+1][N+1][2];
int q[N+1][N+1][2];
int tra[N+1][N+1];
long long path[N+1][N+1];
int list[N+1],poi;
bool vis[N+1];
bool bt(int f,int la,int lb,int r,int lev)
{
    if(la<0 || lb<0 || lev>ll)
        return 0;
    if(la==0 && lb==0)
        return 1;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]==0 && bk[f][i][0] && lb>=q[f][r][1] && la>=q[f][r][0])
        {
            vis[i]=1;
            list[lev]=i;
            if(bt(i,la-bk[f][i][0],lb-bk[f][i][1],r,lev+1))
                return 1;
            vis[i]=0;
        }
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&p[a][b][0],&p[a][b][1]);
        path[a][b]=1;
        q[a][b]=p[a][b][1];
    }
    memcpy(bk,p,sizeof(p));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
            {
                if(j!=i && k!=i && p[j][i][0] && p[i][k][0])
                {
                    int a=p[j][i][0]+p[i][k][0];
                    int b=p[j][i][1]+p[i][k][1];
                    double tmp=(double)p[j][k][0]/(double)p[j][k][1];
                    double tmp0=(double)a/(double)b;
                    if(p[j][k][1]==0 || tmp<tmp0 || (fabs(tmp-tmp0)<1e-13 && path[j][k]>path[j][i]+path[i][k]))
                        p[j][k][0]=a,p[j][k][1]=b,tra[j][k]=i,path[j][k]=path[j][i]+path[i][k];
                }
                if(q[j][i][0] && q[i][k][0] && (q[j][k][0]==0 || q[j][k][0]>q[j][i][0]+q[i][k][0]))
                    q[j][k][0]=q[j][i][0]+q[i][k][0];
                if(q[j][i][1] &&)
            }
    int r=-1;
    double max=-1;
    int ll=N+1;
    for(int i=1;i<=n;++i)
    {
        if(p[i][i][1]>0)
        {
            double tmp=(double)p[i][i][0]/(double)p[i][i][1];
            if(max<(tmp-1e-13) || (fabs(max-tmp)<1e-13 && path[i][i]<ll) )
                r=i,max=(double)p[i][i][0]/(double)p[i][i][1],ll=path[i][i];
        }
    }
    if(r<0)
        printf("0");
    else
    {
        printf("%d\n",ll);
        bt(r,p[r][r][0],p[r][r][1]);
        for(int i=0;i<poi;++i)
            printf("%d ",list[i]);
    }
    return 0;
}
