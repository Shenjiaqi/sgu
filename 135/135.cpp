#include <cstdio>
int main()
{
    long long n;
    scanf("%I64d",&n);
    printf("%I64d",1+(((1+n)*n)>>1));
    return 0;
}
