#include <cstdio>
#include <cstdlib>
using namespace std;

bool check(int v)
{
    int nd(0);
    for(int i=v;i;i/=10)
        ++nd;
    if(nd&1 || nd==0)
        return 0;
    int l,r;
    l=r=0;
    for(int i=v,j=0;i;i/=10,++j)
        if(j<nd/2)
            r+=i%10;
        else l+=i%10;
    if(r==l || abs(l-r)>9)
        return 0;
    for(int i=0,j=v;i<nd;++i,j/=10)
    {
        int k=j%10;
        for(int m=0;m<=9;++m)
            if(i<nd/2)
            {
                if(l==r-k+m)
                    return 1;
            }
            else if(l-k+m==r && !(i==nd-1 && m==0))
                return 1;
    }
    return 0;
}
int main()
{/*
    freopen("out.txt","w",stdout);

    for(int i=100;i<1000;++i)
    {
        int a=0;
        for(int j=0;j<1000;++j)
            if(check(i*1000+j))
                ++a;
        printf("%d ,",a);
        //if((i%100)==0)
            //printf("\n");
    }*/
    freopen("in.txt","r",stdin);
    int a,b;
    scanf("%d %d",&a,&b);
    int r(0);
    for(int i=a;i<=b;++i)
        if(check((i)))
            ++r;
    printf("%d\n",r);
    return 0;
}
