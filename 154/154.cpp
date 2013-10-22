#include <cstdio>
int t0(int n)
{
    int r(0);
    for(;n;n/=5)
        r+=n/5;
    return r;
}
int can(int q)
{
    for(int i=0,j=~(1<<31);i<=j;)
    {
        int mid=(i+j)>>1;
        int tmp=t0(mid);
        if(tmp>q)
            j=mid-1;
        else if(tmp<q)
            i=mid+1;
        else
        {
            for(;mid%5;--mid)
                ;
            return mid;
        }
    }
    return 0;
}
int main()
{
    int q;
    scanf("%d",&q);
    int t=can(q);
    if(t0(t)!=q)
        printf("No solution");
    else printf("%d",(t>0?t:1));
    return 0;
}
