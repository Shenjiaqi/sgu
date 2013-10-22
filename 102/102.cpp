#include <stdio.h>
int gcd(int a,int b)
{
    for(int c;c=a%b;)
        a=b,b=c;
    return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;++i)
        if(gcd(n,i)==1)
            ++sum;
    printf("%d",sum);
    return 0;
}
