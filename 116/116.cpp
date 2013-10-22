#include <cstdio>
#include <algorithm>
using namespace std;
#define N (10000)
int pp[N+1][2];
bool p[N+1];
int q[N],qoi=0;
int main()
{
    for(int i=2;i<=N;++i)
        if(!p[i])
        {
            q[qoi++]=i;
            for(int j=i*i;j<=N;j+=i)
                p[j]=1;
        }
    int ii(0);
    for(ii=0;ii<qoi && q[ii]-1<qoi;++ii)
        q[ii]=q[q[ii]-1];
    int n;
    scanf("%d",&n);
    pp[0][0]=1;
    pp[0][1]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<ii && q[j]<=i;++j)
            if(pp[i-q[j]][0] && (!pp[i][0] || pp[i-q[j]][0]+1<pp[i][0]))
                pp[i][0]=pp[i-q[j]][0]+1,pp[i][1]=q[j];
    if(!pp[n][0])
        printf("0");
    else
    {
        printf("%d\n",pp[n][0]-1);
        int ans[N],iii(0);
        for(int i=n;i;i=i-pp[i][1])
          ans[iii++]=pp[i][1];
        sort(ans,ans+iii);
        for(int i=iii-1;i>=0;--i)
            printf("%d ",ans[i]);
    }
    return 0;
}
