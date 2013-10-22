#include <cstdio>
#include <set>
using namespace std;
#define N (10)
int p[N][3];
int main()
{
    freopen("in.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d%d",*(p+i),*(p+i)+1);
    }
    for(int i=1;;++i)
    {
        int k=-1;
        for(int j=0;j<n;++j)
        {
            if(p[j][2]<i && p[j][0])
            {
                if(k==-1 || p[k][0]<p[j][0] || (p[k][0]==p[j][0] && p[k][1]>p[j][1]))
                    k=j;
            }
        }
        if(k>=0)
        {
            printf("%d %d %d\n",i,k,p[k][0]);
            m-=p[k][0];
            p[k][2]=i+p[k][1];
        }
        if(m<=0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
