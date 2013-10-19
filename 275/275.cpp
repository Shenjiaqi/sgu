#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define N 100
ll p[N];
bool r[64][N];
int n;
bool q[64];
bool s[64][N];
bool test(ll v)
{
    int num(0);
    for(int i=0;i<64;++i,v>>=1)
        if(v&1)
        {
            for(int j=0;j<n;++j)
                s[num][j]=r[i][j];
            q[num++]=1;
        }
    for(int i=0;i<num;++i)
    {
        int j=0;
        for(;j<n && !s[i][j];++j)
            ;
        if(j<n)
            for(int k=0;k<num;++k)
                if(k!=i && s[k][j])
                {
                    for(int l=j;l<n;++l)
                        s[k][l]^=s[i][l];
                    q[k]^=q[i];
                }
    }
    for(int i=0;i<num;++i)
        if(q[i])
        {
            int j=0;
            for(;j<n && !s[i][j];++j)
                ;
            if(j>=n)
                return 0;
        }
    return 1;
}

int main()
{
    scanf("%d",&n);
    ll m(0);
    for(int i=0;i<n;++i)
    {
        scanf("%I64d",p+i);
        m=max(m,p[i]);
    }
    for(;m!=(m&(-m));)
        m-=(m&(-m));
    for(ll i=1,j=0;j<64;i<<=1,++j)
        for(int k=0;k<n;++k)
            r[j][k]=p[k]&i;
    ll ans(0);
    for(;m;m>>=1)
        if(test(ans|m))
            ans|=m;
    printf("%I64d",ans);
    return 0;
}
