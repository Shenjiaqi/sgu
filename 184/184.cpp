#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int P,M,C,K,R,V;
    scanf("%d%d%d%d%d%d",&P,&M,&C,&K,&R,&V);
    printf("%d",min(min(P/K,M/R),C/V));
    return 0;
}
