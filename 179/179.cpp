#include <cstdio>
#include <cstring>
using namespace std;
#define N 10000
int main()
{
    freopen("in.txt","r",stdin);
    char p[N+1];
    scanf("%s",p);
    int n=strlen(p);
    int i=n-1,t(0);
    for(int j=0;i>=0;--i)
    {
        if(p[i]==')')
            ++j;
        else
        {
            if(j>1)
                break;
            --j,++t;
        }
    }
    if(i<0)
        printf("No solution");
    else
    {
        p[i]=')';
        p[i+1]='(';
        i+=2;
        int k=n-i-2*t;
        for(int j=i;j<n-2*t;++j)
            p[j+2*t]=p[j];
        for(int j=i;j<t+i;++j)
            p[j]='(';
        for(int j=t+i;j<i+2*t;++j)
            p[j]=')';
        printf("%s",p);
    }
    return 0;
}
