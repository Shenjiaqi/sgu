#include <cstdio>
#define N 10000
int main()
{
    freopen("in.txt","r",stdin);
    int p[N];
    int n;
    scanf("%d",&n);
    double all(0);
    for(int i=0;i<n;++i)
    {
        scanf("%d",p+i);
        all+=p[i];
    }
    double r(0);
    for(int i=0,j=0;i<n;++i)
    {
        double tmp=(double)(100*p[i])/all;
        r+=tmp-(int)tmp;
        printf("%d ",((int)(tmp)+(int)(r+(1e-13))));
        r-=(int)(r);
    }
    return 0;
}
