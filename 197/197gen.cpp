#include <cstdio>
bool check(int a,int b,int n)
{
    for(int i=1;i<n;++i,a>>=1,b>>=1)
        if( ((a&1) == (b&1)) && ((a&1)==((a&2)>>1)) && ((b&2)==(a&2)) )
            return 0;
    return 1;
}
int gen(int n)
{
    int r(0);
    for(int i=0;i<(1<<n);++i)
        for(int j=0;j<(1<<n);++j)
            if(check(i,j,n))
                ++r;
    return r;
}
int main()
{
    freopen("out.txt","w",stdout);
    for(int i=1;i<=5;++i)
        printf("%d %d\n",i,gen(i));
    return 0;
}
