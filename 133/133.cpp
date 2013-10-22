#include <stdio.h>
#include <stdlib.h>

#define N (16000)

int p[N][2],n;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    freopen("in.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d %d",p+i,*(p+i)+1);

    qsort(p,n,sizeof(p[0]),cmp);

    int t,ans;

    ans=0,t=p[0][1];
    for(int i=1;i<n;++i)
        if(t<p[i][1])
            t=p[i][1];
        else ++ans;

    printf("%d",ans);

    return 0;
}
