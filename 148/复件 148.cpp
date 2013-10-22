#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 15000
int main()
{
    freopen("in.txt","w",stdout);
    int n=N;
    printf("%d\n",n);
    for(int i=1;i<n;++i)
    {
        printf("%d %d %d\n",0,1,0);
    }
    printf("0 2 2");
    return 0;
}
