#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N (1000)
int p[N];
int q[N];
int poi[N];
int n,m,y;
bool cmp(int a,int b)
{
    double c=p[a],d=p[b];
    c=c*(double)m/(double)y;
    d=d*(double)m/(double)y;
    c-=(int)c;
    d-=(int)d;
    if(fabs(c-d)<1e-15)
        return a<b;
    return c>d;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&y);
    int mm=m;
    for(int i=0;i<n;++i)
    {
        scanf("%d",p+i);
        q[i]=p[i]*m/y;
        mm-=q[i];
        poi[i]=i;
    }
    sort(poi,poi+n,cmp);
    //for(int i=0;i<n;++i) printf("%d ",poi[i]);printf("\n");
    for(int i=0;mm >0 && i<n;++i,--mm)
        ++q[poi[i]];
    q[0]+=mm;
    for(int i=0;i<n;++i)
        printf("%d ",q[i]);
    return 0;
}
