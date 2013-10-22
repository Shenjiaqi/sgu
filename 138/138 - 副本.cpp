#include <cstdio>
#include <cstdlib>
#define N (100)
int p[N];
int main()
{
    freopen("in.txt","w",stdout);
    int n=7;
    int all=19;
    srand(21);
    int a,b;
    a=0;
    for(int i=0;i<all;i+=2)
    {
        for(;a==(b=rand()%n);)
            ;
        if((rand()%7)>2)
            a^=b,b^=a,a^=b;
        ++p[a];
        ++p[b];
    }
    printf("%d\n",n);
    for(int i=0;i<n;++i)
        printf("%d ",p[i]);
}
