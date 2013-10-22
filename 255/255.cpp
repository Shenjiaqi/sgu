#include <cstdio>
long long max(long long a,long long b)
{
    return a<b?b:a;
}
long long cc(long long a,long long b)
{
    if(a<b)
        return 0;
    long long r(1),c(1);
    for(;b>0;--b,--a)
    {
        r*=a;
        c*=b;
    }
    //printf("!%I64d\n",r/c);
    return (r/c);
}

int est(long long v)
{
    int f=1,l=100000,r;
    for(;f<=l;)
    {
        int mid=(f+l)/2;
        if(cc(mid-1,3)-cc(mid-2,3)+cc(mid-1-1,2)+cc(mid-1-1,1)-cc(mid-1-2,2)-cc(mid-1-2,1)<v)
            f=mid+1;
        else l=mid-1,r=mid;
    }
    return r;
}
long long estj(long long v,long long a,int i)
{
    int f,l,r;
    for(f=0,l=i-1;f<=l;)
    {
        int mid=(f+l)/2;
        long long b=cc(mid-1,2)-cc(mid-2,2)+cc(mid-1,1)-cc(mid-2,1);
        if(a+b>v)
            l=mid-1;
        else f=mid+1,r=mid;
    }
    return r;
}
long long estk(long long v,long long a,long long b,int j)
{
    int f,l,r;
    for(f=0,l=j-1;f<=l;)
    {
        int mid=(f+l)/2;
        long long c=cc(mid,1)-cc(mid-1,1);
        if(a+b+c>v)
            l=mid-1;
        else f=mid+1,r=mid;
    }
    return r;
}
bool test(long long v)
{
    int r(0);
    for(int i=max(est(v)-3,0);r<2;++i)
    {
        long long a=cc(i-1,3)-cc(i-2,3);
        if(a>v)
            break;
        if(a+cc(i-1-1,2)+cc(i-1-1,1)-cc(i-1-2,2)-cc(i-1-2,1)<v)
            continue;
        for(int j=max(estj(v,a,i)-3,0);r<2 && j<i;++j)
        {
            long long b=cc(j,2)-cc(j-1,2);
            if(a+b>v)
                break;
            for(int k=max(estk(v,a,b,j)-3,0);r<2 && k<j;++k)
            {
                long long c=cc(k,1)-cc(k-1,1);
                if(a+b+c>v)
                    break;
                if(a+b+c==v)
                    ++r;
            }
        }
    }
    return (r==1);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int m;
        scanf("%d",&m);
        printf("%s\n",(test(m)?"YES":"NO"));
    }
    return 0;
}
