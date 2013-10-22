#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define N (400)
#define M (1000)
#define DETA ((double)(1e-13))
int n;
double p[N][3];
int cmp(const void *a,const void *b)
{
    double *c=(double *)a+2;
    double *d=(double *)b+2;
    return (*c<*d?-1:1);
}
double mt(double a,double b,double c,double d)
{
    return (a*d-b*c);
}
int cr(double x1,double y1,double x2,double y2,double &xx1,double &yy1,double &xx2,double &yy2)
{
    int crr(0);
    for(int i=0;i<n;++i)
    {
        double x11,y11,x22,y22;
        x11=p[i][0],y11=p[i][1],x22=p[(i+1)%n][0],y22=p[(i+1)%n][1];
        double t1=y2-y1,t2=x1-x2,t3=x2*(y2-y1)+(x1-x2)*y2;
        double t11=y22-y11,t22=x11-x22,t33=x22*(y22-y11)+(x11-x22)*y22;
        double tmp;
        if(fabs(tmp=mt(t1,t2,t11,t22))<DETA)
        {
            if(fabs(t11*(x1-x11)+t22*(y1-y11))<DETA)
                return 0;
            else continue;
        }
        double tmpx=mt(t3,t2,t33,t22);
        double tmpy=mt(t1,t3,t11,t33);
        tmpx/=tmp;
        tmpy/=tmp;
        if(tmpx<(min(max(x11,x22),max(x1,x2))+DETA)
           && tmpx>(max(min(x1,x2),min(x11,x22))-DETA)
           && tmpy<(min(max(y11,y22),max(y1,y2))+DETA)
           && tmpy>(max(min(y1,y2),min(y11,y22))-DETA))
        {
            if(crr==0)
                xx1=tmpx,yy1=tmpy,++crr;
            else if(crr==1 && (fabs(xx1-tmpx)>DETA || fabs(yy1-tmpy)>DETA))
                xx2=tmpx,yy2=tmpy,++crr;
            //printf("!%lf %lf\n",tmpx,tmpy);
        }
    }
    return crr;
}
int check(double x,double y)
{
    int cr(0);
    double tx1,ty1,tx2,ty2;
    for(int i=0;i<n;++i)
    {
        double x1,y1,x2,y2;
        x1=p[i][0],y1=p[i][1],x2=p[(i+1)%n][0],y2=p[(i+1)%n][1];
        if(fabs(y2-y1)<DETA)
        {
            if(fabs(y2-y)<DETA && (x<(max(x1,x2)+DETA)) && (x>(min(x1,x2)-DETA)))
                return 2;
            continue;
        }
        double xx=(y-y1)*(x2-x1)/(y2-y1)+x1;
        if(fabs(xx-x)<DETA && y<max(y1,y2)+DETA && y>min(y1,y2)-DETA)
            return 2;
        if( xx>x && y<max(y1,y2)+DETA && y>min(y1,y2)-DETA
           && (xx<max(x1,x2)+DETA) && (xx>min(x1,x2)-DETA) )
        {
            if(fabs(xx-x1)>DETA || fabs(y-y1)>DETA)
            {
                if(fabs(xx-x2)>DETA || fabs(y-y2)>DETA)
                    ++cr;
                else
                {
                    y1-=y;
                    y2=p[(i+2)%n][1]-y;
                    if(y1*y2<0)
                        ++cr;
                }
            }
        }
    }
    return (cr==1?1:3);
}
double dis(double x1,double y1,double x2,double y2)
{
    x1-=x2;
    y1-=y2;
    return sqrt(x1*x1+y1*y1);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    double lx;
    int plx;
    lx=300001;
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf",*(p+i),*(p+i)+1);
        if(lx>p[i][0])
            lx=p[i][0],plx=i;
    }
    for(int i=0;i<n;++i)
    {
        if(i==plx)
            continue;
        if(fabs(p[i][0]-p[plx][0])<DETA)
            p[i][2]=atan((p[i][1]-p[plx][1])/DETA);
        else p[i][2]=atan((p[i][1]-p[plx][1])/(p[i][0]-p[plx][0]));
        if(p[i][2]<lx)
            lx=p[i][2]-1.0;
    }
    p[plx][2]=lx;
    qsort(p,n,sizeof(p[0]),cmp);
    int m;
    scanf("%d",&m);
    double x1,y1,x2,y2,xx,yy,xx1,yy1,dist;
    for(int i=0;i<m;++i)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        int pos1=check(x1,y1);
        int pos2=check(x2,y2);
        //printf("%d %d\n",pos1,pos2);
        if( (pos1==1 && pos2==1) || (pos1==1 && pos2==2) || (pos1==2 && pos2==1) ||
           (pos1==2 && pos2==2 && 1==check((x1+x2)/2.0,(y1+y2)/2.0)))
           dist=dis(x1,y1,x2,y2);
        else if((pos1==3 && pos2==1) || (pos1==1 && pos2==3))
        {
            if(pos1==3)
            {
                double tmp;
                tmp=x1,x1=x2,x2=tmp;
                tmp=y1,y1=y2,y2=tmp;
            }
            cr(x1,y1,x2,y2,xx,yy,xx1,yy1);
            //printf("!%lf %lf\n",xx,yy);
            dist=dis(xx,yy,x1,y1);
        }
        else if( !(pos1==2 && pos2==2))
        {
            int tmp;
            if((tmp=cr(x1,y1,x2,y2,xx,yy,xx1,yy1))==2 )
                dist=dis(xx,yy,xx1,yy1);
            else dist=0;

            //printf("%d %lf %lf %lf %lf\n",tmp,xx,yy,xx1,yy1);
        }
        else dist=0;
        printf("%.2lf\n",dist);
    }
    return 0;
}
