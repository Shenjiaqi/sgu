#include <cstdio>
#define N 200000
using namespace std;
bool cmp(const int *a,const int *b)
{
    return (*a<*b);
}
bool cmp2(const int *a,const int *b)
{
    return (*(a+1)<*(b+1));
}
int main()
{
    int m,p[N][4],*r[N*2];
    bool v[N+1];
    scanf("%d",&m);
    for(int i=0,j=0;i<m;++i)
    {
        scanf("%d %d %d %d",p+i,*(p+i)+1,*(p+i)+2,*(p+i)+3);
        r[j++]=&p[i][0];
        r[j++]=&p[i][2];
    }
    sort(r,r+n*2,cmp);
    for(int i=0,j=0,t=1<<31;i<2*n;++i)
    {
        if(t!=*r[i])
            t=*r[i],++j;
        *r[i]=j;
    }
    sort(r,r+n*2,cmp2);
    for(int i=0,j=0,t=1<<31;i<2*n;++i)
    {
        if(t!=*(r[i]+1))
            t=*(r[i]+1),++j;
        *(r[i]+1)=j;
    }
}
