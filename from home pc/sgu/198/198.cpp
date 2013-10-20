#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define DETA (1e-13)
#define N (300)
double dist(double x1,double y1,double x2,double y2)
{
    x1-=x2,y1-=y2;
    return sqrt(x1*x1+y1*y1);
}
int n;
double p[N+1][3],x,y,r;
double q[N*N+1][2];
int s[N+1],l;
bool vis[N+1];
double deg[N*N*2+1];
int de[N*N*2+1],poi,c[N+1];
void add(int i,int j)
{
    q[++l][0]=j,q[l][1]=s[i],s[i]=l;
    q[++l][0]=i,q[l][1]=s[j],s[j]=l;
}
double cr(double x1,double y1,double x2,double y2)
{
    double tmp= acos((x1*x2+y2*y1)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
    //printf("%lf %lf %lf %lf %lf\n",x1,y1,x2,y2,tmp);
    if(x1*y2-x2*y1<0)
        return -tmp;
    return tmp;
}
bool df(int v,int z,double d)
{
    bool add=true;
    for(int i=c[v];i;i=de[i])
    {
        double tmp=fabs(deg[i]-d);
        if(tmp>(double)3.0-DETA)
            return 1;
        else if(tmp<DETA)
            add=false;
    }
    if(add)
        deg[++poi]=d,de[poi]=c[v],c[v]=poi;
    if(vis[v])
        return 0;
    vis[v]=1;
    for(int i=s[v];i;i=q[i][1])
    {
        int j=q[i][0];
        if(j==z)
            continue;
        //printf("!%d %d\n",v,j);
        double tmp=cr(p[v][0]-x,p[v][1]-y,p[j][0]-x,p[j][1]-y);
        if(df(j,v,d+tmp))
            return 1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf%lf",*(p+i),*(p+i)+1,*(p+i)+2);
    scanf("%lf%lf%lf",&x,&y,&r);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(dist(p[i][0],p[i][1],p[j][0],p[j][1])-p[i][2]-p[j][2]<r*(double)2.0-DETA)
                add(i,j);
                //printf("%d %d\n",i,j);}
    for(int i=1;i<=n;++i)
    {
        if(!vis[i] && df(i,i,(double)0))
        {
            printf("NO");
            return 0;
        }
        //memset(vis,0,sizeof(vis));
        poi=0;
    }
    printf("YES");
    return 0;
}
