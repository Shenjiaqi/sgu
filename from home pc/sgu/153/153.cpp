#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int k;
    scanf("%d",&k);
    int p[1<<10];
    bool q[(1<<11)+9];
    for(;k--;)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int z=1;
        int u[9];
        u[0]=1;
        for(int i=1;i<=m;++i)
        {
            scanf("%d",u+i);
            if(z<u[i])
                z=u[i];
        }
        memset(p,0,sizeof(p));
        int mo=1,i=0;
        for(;mo<=n;++mo)
        {
            q[mo]=0;
            for(int j=0;j<=m;++j)
                if(mo-u[j]>0 && !q[mo-u[j]])
                {
                    q[mo]=1;
                    break;
                }
            i=((i<<1)|q[mo])&((1<<(1+z))-1);
            if(p[i])
                break;
            if(mo>z)
                p[i]=mo;
        }
        //for(int d=1;d<=mo;++d)printf("%d ",q[d]);printf("\n");
        printf("%s",(mo>n?q[n]:q[((n-p[i])%(mo-p[i]))+p[i]])?"FIRST":"SECOND");
        printf(" PLAYER MUST WIN");
        if(k)
            printf("\n");
    }
    return 0;
}
