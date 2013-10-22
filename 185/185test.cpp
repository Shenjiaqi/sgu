#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define N 400
#define INF (~(1<<31))
int main()
{
    freopen("in.txt","w",stdout);
    int n=400,m=400;
    printf("%d %d\n",n,n);

    printf("%d %d 1\n",1,2);
    int mid=(n-2)/2+1;
    for(int i=2;i<mid;++i)
        printf("%d %d 1\n",i,i+1);

    printf("%d %d 1\n",mid,n);
    printf("%d %d 1\n",1,mid+1);

    for(int i=mid+1;i<n;++i)
        printf("%d %d 1\n",i,i+1);
    return 0;
}
