#include <cstdio>
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d %d",&n,&m);
    if(m>12 || m<=0 || month[m]<n || n<=0)
        printf("Impossible");
    else
    {
        int r=n;
        for(int i=1;i<m;++i)
            r+=month[i];
        r%=7;
        printf("%d",(r?r:7));
    }
    return 0;
}
