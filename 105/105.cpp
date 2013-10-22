#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",(n/3)*2+((n%3==0)?0:(n%3)-1));
    return 0;
}
