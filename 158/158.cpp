#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300
#define M 300
#define L 5000
float p[N];
float q[M];
int l,m,n;
int getp(float v)
{
    int f=0,l=n-1;
    for(;f<=l;)
    {
        int mid=(f+l)>>1;
        if(p[mid]<v)
            f=mid+1;
        else l=mid-1;
    }
    if(f>=n)
        f=n-1;
    for(;f>=0 && p[f]>=v;--f)
        ;
    return f;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d\n%d",&l,&m);
    for(int i=0;i<m;++i)
        scanf("%f",q+i);
    //sort(q,q+m);
    scanf("%d",&n);
    p[0]=0;
    for(int i=1;i<n;++i)
        scanf("%f",p+i);
    sort(p,p+n);
    float s=l-p[n-1];
    float maxsum=0,pos=0;
    for(float i=0;i<=s;)
    {
        float sum=0,mindis=L*M;
        for(int j=0;j<m;++j)
        {
            int k=getp(q[j]-i);
            float tmp=M*L;
            if(k>=0)
                tmp=q[j]-i-p[k];
            if(k!=n-1)
                tmp=min(tmp,p[k+1]+i-q[j]);
            sum+=tmp;
            float t;
            if(k>=0 && k<n-1)
            {
                if((p[k+1]+p[k])/2<=q[j]-i)
                    t=q[j]-i-(p[k+1]+p[k])/2;
                else t=q[j]-i-p[k];
            }
            else if(k<0)
                t=0;
            else t=q[j]-i-p[k];
            if(t>(1e-13))
                mindis=min(mindis,t);
        }
        if(sum>maxsum)
            maxsum=sum,pos=i;
        if(s-i<1e-13)
            break;
        if(M*L-mindis<1e-13)
            i=s;
        else i+=mindis;
    }
    printf("%f %f",pos,maxsum);
    return 0;
}
