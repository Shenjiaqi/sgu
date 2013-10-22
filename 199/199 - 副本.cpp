#include <cstdio>
#include <cstdlib>
#define N 100000
int main()
{
    freopen("in.txt","w",stdout);
    int n=N/1,max=N;
    printf("%d\n",n);
    for(int i=0;i<n;++i)
        printf("%d %d\n",rand()%max,rand()%max);
    return 0;
}
