#include <cstdio>
#define N (1000)
int p[N];
int main()
{
    freopen("in.txt","r",stdin);
    int n(0);
    for(char t;;)
    {
        scanf("%c",&t);
        if(t==' ')
            break;
        p[n++]=t-'0';
    }
    int k;
    scanf("%d",&k);
    int i=0,j=1;
    for(;k>0 && j<n;++j)
    {
        for(;k>0 && i>=0 && p[i]<p[j];)
            --k,--i;
        p[++i]=p[j];
    }
    for(int ii=0;ii<=i-k;++ii)
        printf("%d",p[ii]);
    if(k==0)
        for(int ii=j;ii<n-k;++ii)
            printf("%d",p[ii]);
    return 0;
}
