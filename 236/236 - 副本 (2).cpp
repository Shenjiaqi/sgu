#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;
#define N (50)
int p[N+1][N+1][2];
int tra[N+1][N+1];
map<long long,int> path[N+1][N+1];
int list[N+1],poi;
void bt(int f,int t)
{
    int tmp=path[f][t].begin()->second;
    if(tmp)
    {
        bt(f,tmp);
        bt(tmp,t);
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
        path[a][b][shift(a)|shift(b)]=0;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(j!=i && k!=i && p[j][i][0] && p[i][k][0])
                {
                    int a=p[j][i][0]+p[i][k][0];
                    int b=p[j][i][1]+p[i][k][1];
                    double l1;
                    if(p[j][k][1])
                        l1=(double)p[j][k][0]/(double)p[j][k][1];
                    double l2=(double)a/(double)b;
                    if(p[j][k][1]==0 || l1<l2+1e-13)
                    {
                        bool c=0;
                        if(fabs(l1-l2)<1e-13)
                            c=1;
                        for(map<long long,int>::iterator ii=path[j][i].begin();ii!=path[j][i].end();++ii)
                            for(map<long long,int>::iterator ij=path[i][k].begin();ij!=path[i][k].end();++ij)
                            {
                                long long t1,t2;
                                t1=ii->first,t2=ij->first;
                                long long tmp=(t1&t2)^shift(i);
                                if(j==k)
                                    tmp^=shift(j);
                                if(tmp==0)
                                {
                                    if(!c)
                                        path[j][k].clear();
                                    c=1;
                                    if(path[j][k].find(ii->first|ij->first)==path[j][k].end())
                                        p[j][k][0]=a,p[j][k][1]=b,path[j][k][ii->first|ij->first]=i;
                                }
                            }
                    }
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
