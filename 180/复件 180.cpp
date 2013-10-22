#include <cstdio>
#include <algorithm>
using namespace std;
#define N 65537
int main()
{
    freopen("in.txt","w",stdout);
    int n=N;
    printf("%d\n",n);
    for(int i=0;i<n;++i)
    {
        printf("%d ",n+1-i);
    }
    return 0;
}
