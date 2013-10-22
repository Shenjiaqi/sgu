#include <cstdio>
#include <algorithm>
using namespace std;
#define N 6000
int p[N],*q[N];
int n;
bool cmp(const int *a,const int *b)
{
    return *a<*b;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        double t;
        scanf("%lf",&t);
        p[i]=(int)(t*1000000-2000000);
        q[i]=p+i;
    }
    sort(q,q+n,cmp);
    printf("yes\n");
    for(int i=0,j=n-1,k=0;i<=j;)
    {
        if(k>0)
        {
            k+=*q[i];
            printf("%d ",(int)(q[i]-p+1));
            ++i;
        }
        else
        {
            k+=*q[j];
            printf("%d ",(int)(q[j]-p+1));
            --j;
        }
    }
    return 0;
}
