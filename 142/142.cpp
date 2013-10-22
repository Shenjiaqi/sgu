#include <cstdio>
bool p[1<<21];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d\n",&n);
    const int c=1<<20;
    for(int u=0,i=0;i<n;++i)
    {
        char t;
        scanf("%c",&t);
        u=(u<<1)|(t=='a'?0:1);
        for(int msk=c-1,j=20;msk;msk>>=1,--j)
            if(i+1>=j)
                p[(msk&u)|(msk+1)]=1;
    }
    int i=2;
    for(;p[i];++i)
        ;
    int j=c>>1;
    int ans=19;
    for(;0==(j&i);j>>=1)
        --ans;
    printf("%d\n",ans);
    j>>=1;
    for(;j;j>>=1)
        printf("%c",(j&i?'b':'a'));
    return 0;
}
