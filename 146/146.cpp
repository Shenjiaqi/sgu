#include <cstdio>
int main()
{
    freopen("in.txt","r",stdin);
    double l;
    int n;
    scanf("%lf%d",&l,&n);
    long long ll=(long long)(l*(double)(1e4)+0.5);
    long long a=0;
    for(int i=0;i<n;++i)
    {
        long long t,v;
        scanf("%I64d%I64d",&t,&v);
        a=(a+((t*v)%ll)*(long long)10000)%ll;
    }
    if(ll-a<a)
        a=ll-a;
    l=(double)a/(double)(1e4);
    printf("%.4lf",l);
    return 0;
}
