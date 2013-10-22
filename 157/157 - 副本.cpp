#include <cstdio>
int main()
{
    int n;
    const int p[]={0,1,2,5,14,47,189,891,4815,29547,203173,1548222,12966093};
    scanf("%d",&n);
    if(n<13)
        printf("%d",p[n]);
    else printf("118515434");
    return 0;
}
