#include <cstdio>
#define N (5000)
#define SWP(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
int main()
{
    freopen("in.txt","r",stdin);
    char a[N+1],b[N+1];
    scanf("%s%s",a,b);
    int ans=0,i=0;
    for(;a[i];++i)
        if(a[i]!=b[i])
        {
            int j=i;
            for(;b[j] && a[i]!=b[j];++j)
                ++ans;
            if(b[j]=='\0')
            {
                printf("-1");
                return 0;
            }
            SWP(b[i],b[j]);
        }
    if(b[i])
        printf("-1");
    else
        printf("%d",ans);
    return 0;
}
