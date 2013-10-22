#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define DET (1e-14)
using namespace std;
inline void check1(int *a,int *b)
{
    double t1=(float)a[0]/a[2];
    double t2=(float)b[0]/b[2];
    if(t1>t2 || (fabs(t1-t2)<DET&&(double)a[1]/a[2]>(double)b[1]/b[2]))
        memcpy(a,b,sizeof(int)*3);
}
inline void check2(int *a,int *b)
{
    double t1=(float)a[1]/a[2];
    double t2=(float)b[1]/b[2];
    if(t1>t2 || (fabs(t1-t2)<DET&&(double)a[0]/a[2]>(double)b[0]/b[2]))
        memcpy(a,b,sizeof(a)*3);
}
bool test(double a1,double a2,double b1,double b2,double aa,double bb)
{
    //printf("%lf %lf %lf %lf %lf %lf\n",a1,a2,b1,b2,aa,bb);
    if(fabs(a1-b1)<(double)DET || fabs(a2-b2)<(double)DET)
        return ((aa+DET>a1 && bb+DET>a2) || (aa+DET>b1 && bb+DET>b2));
    a1-=b1;
    a2-=b2;
    aa-=b1;
    bb-=b2;
    double p1=aa/a1,p2=bb/a2;
    return (p2>=0 && p1<1+DET && p1<p2+DET);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,aa,bb;
    scanf("%d%d%d",&n,&aa,&bb);
    int a[3],b[3];
    scanf("%d%d%d",a,a+1,a+2);
    memcpy(b,a,sizeof(b));
    for(int i=1;i<n;++i)
    {
        int t[3];
        scanf("%d%d%d",t,t+1,t+2);
        check1(a,t);
        check2(b,t);
    }
    double f,l,ans;
    f=0,l=min((double)aa*a[2]/(double)a[0],(double)bb*b[2]/(double)b[1])+1;
    //printf("%d %d %d %d %d %d %d %d\n",aa,a[0],a[1],a[2],bb,b[0],b[1],b[2]);
    for(;l-f>=1e-8;)
    {
        double mid=(f+l)/(double)2.0;
        //printf("%lf\n",mid);
        if(test((double)a[0]/a[2],(double)a[1]/a[2],
                (double)b[0]/b[2],(double)b[1]/b[2],
                (double)aa/mid,(double)bb/mid))
            f=mid+(double)(1e-9),ans=mid;
        else l=mid-(double)(1e-9);
    }
    printf("%.6lf",ans);
    return 0;
}
