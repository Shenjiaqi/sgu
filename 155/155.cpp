#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
#define N (50000)
int p[N][3];
int q[N][3];
int cmp(const void *a,const void *b)
{
    int *c,*d;
    c=(int *)a,d=(int *)b;
    return *(c+1)-*(d+1);
}
struct cmp1
{
    bool operator()(const int a,const int b)
    {
        return p[a][0]<p[b][0];
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",*(p+i),*(p+i)+1);
        p[i][2]=i;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    set<int,cmp1> sett;
    sett.insert(0);
    for(int i=1;i<n;++i)
    {
        set<int,cmp1>::iterator ite,t2;
        t2=ite=(sett.insert(i)).first;
        int lr=0;
        if(ite==sett.begin())
        {
            ++t2;
            lr=1;
        }
        else
        {
            ++ite;
            if(ite==sett.end())
                --t2,lr=2;
            else if(!q[p[*ite][2]][1])
            {
                --t2;
                if(p[*t2][0]==p[i][0])
                {
                    printf("NO");
                    return 0;
                }
                lr=1,t2=ite;
            }
            else
            {
                if(p[*ite][0]==p[i][0])
                {
                    printf("NO");
                    return 0;
                }
                --t2,lr=2;
            }
        }
        int tmp=*t2;
        if(p[tmp][1]>=p[i][1] || p[tmp][0]==p[i][0])
        {
            printf("NO");
            return 0;
        }
        tmp=p[tmp][2];
        q[tmp][lr]=p[i][2]+1;
        q[p[i][2]][0]=tmp+1;
    }
    printf("YES");
    for(int i=0;i<n;++i)
        printf("\n%d %d %d",q[i][0],q[i][1],q[i][2]);
    return 0;
}
