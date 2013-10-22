#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N (50)
int p[N+1][N+1][2];
int tra[N+1][N+1];
long long path[N+1][N+1];
int list[N+1],poi;
void bt(int f,int t)
{
    if(tra[f][t])
    {
        bt(f,tra[f][t]);
        bt(tra[f][t],t);
    }
    else
        list[poi++]=f;
}
long long shift(int k)
{
    long long r=1;
    if(k>=32)
    {
        r<<=31;
        k-=31;
    }
    return (r<<k);
}
bool check(long long pa,long long pb,int v,int f,int t)
{
    long long r=pa&pb;
    long long tmp=shift(v);
    r^=tmp;
    if(f==t)
    {
        tmp=shift(f);
        return (r^tmp)==0;
    }
    return r==0;
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
        path[a][b]=shift(a)|shift(b);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(j!=i && k!=i && p[j][i][0] && p[i][k][0] && check(path[j][i],path[i][k],i,j,k))
                {
                    int a=p[j][i][0]+p[i][k][0];
                    int b=p[j][i][1]+p[i][k][1];
                    if(p[j][k][1]==0 || (double)p[j][k][0]/(double)p[j][k][1]<(double)a/(double)b)
                        p[j][k][0]=a,p[j][k][1]=b,tra[j][k]=i,path[j][k]=path[j][i]|path[i][k];
                }
    int r=-1;
    double max=-1;
    for(int i=1;i<=n;++i)
        if(p[i][i][1]>0 && max<(double)p[i][i][0]/(double)p[i][i][1])
            r=i,max=(double)p[i][i][0]/(double)p[i][i][1];
    if(r<0)
        printf("0");
    else
    {
        bt(r,r);
        printf("%d\n",poi);
        for(int i=0;i<poi;++i)
            printf("%d ",list[i]);
    }
    return 0;
}
