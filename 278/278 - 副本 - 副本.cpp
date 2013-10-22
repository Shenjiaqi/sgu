#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstring>
#define DET (1e-13)
using namespace std;
#define N (75000)
int p[N+1][3];
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    double tc=(double)(*c)/(*(c+2)),td=(double)(*d)/(*(d+2));
    if(fabs(tc-td)<DET)
    {
        tc=(double)*(c+1)/(*(c+2)),td=(double)*(d+1)/(*(d+2));
        if(fabs(tc-td)<DET)
            return 0;
        return tc>td?-1:1;
    }
    return tc<td?-1:1;
}
bool test(double a1,double a2,double b1,double b2,double c1,double c2)
{
    //printf("%lf %lf %lf %lf %lf %lf\n",a1,a2,b1,b2,c1,c2);
    if(c1<a1 || c2<b2)
        return 0;
    if((a1<=c1 && a2<=c2)||(b1<=c1&&b2<=c2))
        return 1;
    if(fabs(a1-b1)<DET)
        return 0;
    double p1=(c1-b1)/(a1-b1);
    double p2=(c2-b2)/(a2-b2);
    return (p1<=1 && p2>=0 && p1<=p2);
}
double cal(double f,double l,double a1,double a2,double b1,double b2,double aa,double bb)
{
    //f=0,l=max((double)aa*p[0][2]/p[0][0],(double)bb*p[u][2]/(double)p[u][1])+1;
    if(a1>aa/f || b2>bb/f)
        return f;
    double ans=f;
    for(;f<l-(1e-13);)
    {
        double m=(f+l)/(double)2.0;
        if(test(a1,a2,b1,b2,aa/m,bb/m))
            ans=m,f=m+(1e-11);
        else
            l=m-(1e-11);
    }
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,aa,bb;
    scanf("%d%d%d",&n,&aa,&bb);
    for(int i=0;i<n;++i)
        scanf("%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2);
    qsort(p,n,sizeof(p[0]),cmp);
    int u=0;
    for(int j=1;j<n;++j)
    {
        for(;j<n;++j)
        {
            double t1=(double)p[u][1]/p[u][2];
            double t2=(double)p[j][1]/p[j][2];
            if(t1<t2+DET)
                continue;
            else break;
        }
        if(j<n)
        {
            ++u;
            p[u][0]=p[j][0],p[u][1]=p[j][1],p[u][2]=p[j][2];
        }
        else break;
    }
    double ans=0;
    for(int i=0,j=u;i<=u;)
    {
        ans=cal(ans,max((double)aa*p[i][2]/p[i][0],(double)bb*p[j][2]/(double)p[j][1])+1
                ,(double)p[i][0]/p[i][2],(double)p[i][1]/p[i][2],
                (double)p[j][0]/p[j][2],(double)p[j][1]/p[j][2],aa,bb);
        --j;
        if(j<=i)
            ++i,j=u;
        if(i>=u)
            break;
    }
    printf("%.6lf",ans);
    return 0;
}
