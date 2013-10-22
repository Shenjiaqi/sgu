#include <stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    long long p[31]={0};
    p[0]=1;
    for(int i=1;i<=k;++i)
        for(int j=0;j<i;++j)
            p[i]+=p[j]*p[i-j-1];
    printf("%I64d %d",p[k],k+1);
    return 0;
}
