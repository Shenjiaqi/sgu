#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define N (50)
int p[N+1][N+1][2],tra[N+1][N+1];
long long path[N+1][N+1];
int list[N],poi;
int n,m;
long long shift(int v)
{
    long long r=1;
    if(v>=32)
        r<<=31,v-=31;
    return (r<<v);
}
bool check(int a,int b,int c)
{
    long long t1;
    t1=(path[a][b]&path[b][c])^shift(b);
    if(a==c)
        t1^=shift(a);
    return (t1==0);
}
void bt(int f,int t)
{
    if(tra[f][t])
    {
        bt(f,tra[f][t]);
        bt(tra[f][t],t);
    }
    else list[poi++]=f;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&p[a][b][0],&p[a][b][1]);
        path[a][b]=shift(a)|shift(b);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(p[j][i][1] && p[i][k][1] && check(j,i,k))
                {
                    int a=(p[j][i][0]+p[i][k][0]),b=(p[j][i][1]+p[i][k][1]);
                    double t1=(double)a/(double)b;
                    double t2=-1;
                    if(p[j][k][1])
                        t2=p[j][k][0]/p[j][k][1];
                    if(t2<t1)
                        p[j][k][0]=a,p[j][k][1]=b,path[j][k]=path[j][i]|path[i][k],tra[j][k]=i;
                }
    int r=-1;
    double ma=-1;
    for(int i=1;i<=n;++i)
    {
        if(p[i][i][1])
        {
            double tmp=(double)p[i][i][0]/(double)p[i][i][1];
            if(ma<tmp )
                r=i,ma=tmp;
        }
    }
    //printf("%d %d %d\n",r,p[r][r][0],p[r][r][1]);
    //return 0;
    if(r<0)
    {
        printf("0");
    }
    else
    {
        bt(r,r);
        printf("%d\n",poi);
        for(int i=0;i<poi;++i)
            printf("%d ",list[i]);
    }
    return 0;
}
