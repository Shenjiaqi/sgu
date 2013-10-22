#include <cstdio>
#define M 1000
int p[M+1];
int main()
{
    freopen("in.txt","r",stdin);
    int a,alpha,beta,gamma,m,k;
    scanf("%d %d %d %d %d %d",&a,&alpha,&beta,&gamma,&m,&k);
    int x=a%m,i(1);
    p[x]=-1;
    for(;i<=k;++i)
    {
        x=((alpha*x*x)%m+(beta*x)%m+gamma)%m;
        if(p[x])
            break;
        p[x]=i;
    }
    if(i<k)
    {
        int t;
        if(p[x]<0)
            t=i;
        else t=i-p[x];
        i=(k-i)%t;
        for(int j=0;j<i;++j)
            x=((alpha*x*x)%m+(beta*x)%m+gamma)%m;
    }
    printf("%d",(k==0?a:x));
    return 0;
}
