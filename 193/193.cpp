#include <cstdio>
#define N 20001
int p[N],n;
int main()
{
    for(;;)
    {
        int t;
        t=getchar();
        if(t<='9' && t>='0')
            p[n++]=(int)(t-'0');
        else break;
    }
    for(int i=0,j=n-1;i<j;++i,--j)
        p[i]^=p[j],p[j]^=p[i],p[i]^=p[j];
    bool even=!(p[0]&1);
    for(int i=n-1;i>=0;--i)
    {
        if(i && (p[i]&1))
            p[i-1]+=10;
        p[i]>>=1;
    }
    if(!p[n-1])
        --n;
    if(even)
    {
        int v=(p[0]&1)?2:1;
        for(int i=0;i<n;++i)
            if(p[i]>=v)
            {
                p[i]-=v;
                break;
            }
            else
            {
                p[i]+=(10-v);
                v=1;
            }
        if(!p[n-1])
            --n;
    }
    for(int i=n-1;i>=0;--i)
        printf("%d",p[i]);
    return 0;
}
