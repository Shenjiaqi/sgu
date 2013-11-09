#include <cstdio>
#include <cstdlib>
using namespace std;
#define N 4
#define M (N*N)
int p[N*N][2];
int cmp(const void *a,const void *b )
{
    int c=*(int*)a;
    int d=*(int*)b;
    return c-d;
}
int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            scanf("%d",&p[4*i+j][1]);
            p[4*i+j][0]=i*(N*N)+(i&1?-j:j);
        }
    qsort(p,N*N,sizeof(p[0]),cmp);
    int r(0);
    for(int i=1;i<N*N;++i)
        if(p[i][1])
            for(int j=0;j<i;++j)
                if(p[j][1] && p[j][1]>p[i][1])
                    ++r;
    printf("%s",(r&1?"YES":"NO"));
    return 0;
}

