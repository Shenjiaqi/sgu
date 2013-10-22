#include <cstdio>
#include <cstdlib>
using namespace std;
#define N 16000
#define K 100
int p[N][3];
int nn[K];
int q[K][2];
int k;
int n;
int cmp(const void *a,const void *b)
{
    int *c=(int*)a;
    int *d=(int*)b;
    return (*(1+d)-*(1+c));
}
int cmp2(const void *a,const void *b)
{
    int *c=(int*)a;
    int *d=(int*)b;
    return (*(c+2)-*(d+2));
}
int cmp3(const void *a,const void *b)
{
    int *c=(int*)a;
    int *d=(int*)b;
    return (*(c)-*(d));
}
int gpos(int v)
{
    int f,l;
    f=0;l=k-1;
    for(;f<=l;)
    {
        int mid=(f+l)>>1;
        if(q[mid][0]>=v)
            l=mid-1;
        else f=mid+1;
    }
    if(f>=k)
        f=k-1;
    return f;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d",nn+i);
        n+=nn[i];
    }
    for(int i=0;i<k;++i)
    {
        scanf("%d",*(q+i));
        q[i][1]=i;
    }
    qsort(q,k,sizeof(q[0]),cmp3);
    for(int i=0;i<n;++i)
    {
        scanf("%d",*(p+i));
        p[i][2]=i+1;
    }
    for(int i=0;i<n;++i)
        scanf("%d",*(p+i)+1);
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;++i)
    {
        int tmp=gpos(p[i][0]);
        for(;tmp>=0 && (!nn[q[tmp][1]] || q[tmp][0]>=p[i][0]);--tmp)
            ;
        if(tmp>=0)
        {
            p[i][0]=q[tmp][1]+1;
            --nn[q[tmp][1]];
        }
        else p[i][0]=-1;
    }
    qsort(p,n,sizeof(p[0]),cmp2);
    for(int i=0,j=0;i<n;++i)
    {
        if(p[i][0]>0)
            printf("%d",p[i][0]);
        else
        {
            for(;nn[j]<=0;++j)
                ;
            printf("%d",j+1);
            --nn[j];
        }
        if(i!=n-1)
            printf(" ");
    }
    return 0;
}
