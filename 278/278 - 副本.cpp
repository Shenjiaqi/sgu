#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define DET (1e-10)
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
bool test(double a1,double a2,double b1,double b2,double c1,double c2)
{
    if(c1<a1 || c2<b2)
        return 0;
    if((a1<=c1 && a2<=c2)||(b1<=c1&&b2<=c2))
        return 1;
    double p1=(c1-b1)/(a1-b1);
    double p2=(c2-b2)/(a2-b2);
    return (p1<=1 && p2>=0 && p1<=p2);
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
    if(fabs((double)a[0]/a[2]-(double)b[0]/b[2])<DET &&
       fabs((double)a[1]/a[2]-(double)b[1]/b[2])<DET)
       printf("%.6lf",min((double)aa/a[0],(double)bb/a[1])*(double)a[2]);
    else
    {
        double f,l,ans;
        f=0,l=max((double)aa*a[2]/a[0],(double)bb*b[2]/(double)b[1])+1;
        for(;f<l-(1e-13);)
        {
            double m=(f+l)/(double)2.0;
            if(test((double)a[0]/a[2],(double)a[1]/a[2],
                    (double)b[0]/b[2],(double)b[1]/b[2],
                    (double)aa/m,(double)bb/m))
                ans=m,f=m+(1e-11);
            else l=m-(1e-14);
        }
        printf("%.6lf",ans);
    }
    return 0;
}
