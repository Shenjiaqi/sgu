#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define N 300
#define INF 32001
int p[N][5];
double u[N*N/2+N*2+2];
double m[N*N/2+N*2+2];
int col[N*N/2+N*2+2];
int pos(int f,int l,double k)
{
    for(;f<=l;)
    {
        int m=(f+l)>>1;
        if(fabs(u[m]-k)<1e-13)
            return m;
        if(u[m]<k)
            f=m+1;
        else l=m-1;
    }
    return f;
}
double cr(int a,int b)
{
    double x1=p[a][0],y1=p[a][1],x2=p[a][2],y2=p[a][3];
    double x1_=p[b][0],y1_=p[b][1],x2_=p[b][2],y2_=p[b][3];
    double tmp=(y2_-y1_)*(x2-x1) - (x2_-x1_)*(y2-y1);
    if(fabs(tmp)<1e-13)
        return INF;
    tmp=( ( (y1-y1_)*(x2-x1)*(x2_-x1_) + x1_*(y2_-y1_)*(x2-x1) - x1*(x2_-x1_)*(y2-y1) ) /
             ( tmp ) );
    if(tmp>x1 && tmp<x2 && tmp<x2_ && tmp>x1_)
        return tmp;
    return INF;
}
double mid(int c,double x)
{
    double x1=p[c][0],y1=p[c][1],x2=p[c][2],y2=p[c][3];
    return (y1+(y2-y1)*(x-x1)/(x2-x1));
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int r=0;
    for(int i=0;i<n;++i)
    {
        char t;
        scanf("%d %d %d %d %c",*(p+r),*(p+r)+1,*(p+r)+2,*(p+r)+3,&t);
        if(p[r][0]!=p[r][2])
        {
            p[i][4]=((t=='R')?0:((t=='G')?1:2));
            u[(r<<1)]=p[r][0],u[(r<<1)+1]=p[r][2];
            if(p[r][0]>p[r][2])
            {
                p[r][0]^=p[r][2],p[r][2]^=p[r][0],p[r][0]^=p[r][2];
                p[r][1]^=p[r][3],p[r][3]^=p[r][1],p[r][1]^=p[r][3];
            }
            ++r;
        }
    }
    int l=r<<1;
    for(int i=0;i<r;++i)
        for(int j=i+1;j<r;++j)
            if(!(p[i][0]>=p[j][2] || p[i][2]<=p[j][0]))
            {
                double tmp=cr(i,j);
                if(tmp<INF-(1e-13))
                    u[l++]=tmp;
            }
    sort(u,u+l);
    l=(int)(unique(u,u+l)-u);
    for(int i=0;i<l;++i)
        m[i]=INF;
    for(int i=0;i<r;++i)
        for(int s=pos(0,l,p[i][0]);s<l && u[s]<p[i][2];++s)
        {
            double tmp=mid(i,(double)(u[s]+u[s+1])/2.0);
            //printf("!%d %d %d %d %d %lf %lf\n",s,p[i][0],p[i][2],u[s],u[s+1],m[s],tmp);
            if(tmp<m[s])
                m[s]=tmp,col[s]=p[i][4];
        }
    double ans[3]={0};
    for(int i=0;i<l-1;++i)
        if(m[i]<INF)
        {
            //printf("%d %d %lf %lf\n",i,col[i],u[i],u[i+1]);
            ans[col[i]]+=(u[i+1]-u[i]);
        }
    printf("R %.2lf\nG %.2lf\nB %.2lf",ans[0],ans[1],ans[2]);
    return 0;
}
