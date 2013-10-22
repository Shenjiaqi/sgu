#include <cstdio>
#include <cmath>
#define N (20)
#define M (1000)
#define T (50)
int main()
{
    freopen("in.txt","r",stdin);
    int n,t;
    scanf("%d%d",&n,&t);
    int p[N],v[N];
    for(int i=0;i<n;++i)
        scanf("%d",p+i);
    for(int i=0;i<n;++i)
        scanf("%d",v+i);
    int a[N]={0};
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if((v[i]^v[j])<0)
            {
                int vel=fabs(v[i]-v[j]);
                int d=fabs(p[i]-p[j]);
                if((p[i]<p[j] && v[i]<0) || (p[i]>p[j]&&v[i]>0))
                    d=M-d;
                int aa=(vel*t-d+M)/M;
                a[i]+=aa;
                a[j]+=aa;
            }
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    return 0;
}
