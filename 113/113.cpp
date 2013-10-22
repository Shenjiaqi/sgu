#include <stdio.h>

#define Z 100000

bool pa[100000];
int pri[9592],poi;

int te(int t)
{
    int i;
    for(i=0;i<poi && t>pri[i] && t%pri[i];++i)
        ;

    if(i>=poi || t<=pri[i])
        return 1;

    return 0;
}

int test(int t)
{
    int i;
    for(i=0;i<poi && t>pri[i] && t%pri[i];++i)
        ;

    if(i>=poi || t<=pri[i])
        return 0;

    return te(t/pri[i]);
}

int main()
{
    for(int i=2;i<Z;++i)
        if(pa[i]==0)
        {
            pri[poi++]=i;
            for(int j=i*i;j>0 && j<Z;j+=i)
                pa[j]=1;
        }

    int n;
    scanf("%d",&n);

    while(n--)
    {
        int t;
        scanf("%d",&t);

        printf("%s\n",test(t)?"Yes":"No");
    }

    return 0;
}
