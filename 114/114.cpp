#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 15000

struct poi{
    double pos;
    long long num;
}p[N];

bool cmp(const poi &a,const poi &b)
{
    return a.pos < b.pos;
}

int main()
{
    freopen("in.txt","r",stdin);

    int n;
    scanf("%d",&n);

    long long t;
    t=0;

    for(int i=0;i<n;++i)
    {
        scanf("\n%lf %I64D",&p[i].pos,&p[i].num);
        t+=p[i].num;
    }

    sort(p,p+n,cmp);

    int c;
    c=0;
    t/=2;
    for(long long k=p[c].num;k<t;)
        k+=p[++c].num;

    printf("%.5lf",p[c].pos);

    return 0;
}
