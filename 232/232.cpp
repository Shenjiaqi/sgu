#include <cstdio>
#include <cstring>
using namespace std;
#define N (150000)
typedef long long ll;
int n,k;
char str[N+1];
int *r,*rr,r1[N],r2[N];
int *rank,*rrank,ra1[N],ra2[N];
int num[N];
int nxt(int v)
{
    return (int)(((ll)k*(ll)(v))%(ll)n);
}
int main()
{
    freopen("in.txt","r",stdin);
    r=r1,rr=r2;
    rank=ra1,rrank=ra2;
    scanf("%d %d\n%s",&n,&k,str);
    bool v[10]={0};
    for(int i=0;i<n;++i)
        v[str[i]-'0']=1;
    int list[10];
    int l=-1;
    for(int i=0;i<10;++i)
        if(v[i])
            list[i]=++l;
    for(int i=0;i<n;++i)
        ++num[rank[i]=list[str[i]-'0']];
    for(int i=1;i<=l;++i)
        num[i]+=num[i-1];
    for(int i=n-1;i>=0;--i)
        r[--num[rank[i]]]=i;
    memset(num,0,sizeof(int)*(l+1));
    for(int i=0;i<n;++i)
        ++num[rank[i]=list[str[i]-'0']];
    for(int i=2;i<=n;i<<=1)
    {
        /*for(int j=0;j<n;++j)
            printf("%d ",rank[j]);printf("\n");*/
        /*memset(num,0,sizeof(int)*(l+1));

        for(int j=0;j<n;++j)
        {
            //b[j]=(r[j]-nxt(i>>1)+n)%n;
            ++num[rank[j]];
        }*/
        for(int j=1;j<=l;++j)
            num[j]+=num[j-1];
        int *tmp=r;
        r=rr,rr=tmp;
        for(int j=n-1;j>=0;--j)
        {
            int t=(rr[j]-nxt(i>>1)+n)%n;
            r[--num[rank[t]]]=t;
        }
        tmp=rank,rank=rrank,rrank=tmp;
        memset(num,0,sizeof(int)*(l+1));
        ++num[rank[r[0]]=l=0];
        for(int j=1;j<n;++j)
        {
            int a=r[j-1];
            int b=r[j];
            int c=nxt(i>>1);
            if(rrank[a]==rrank[b] && rrank[(a+c)%n]==rrank[(b+c)%n])
                rank[b]=l;
            else rank[b]=++l;
            ++num[l];
        }
    }
    //printf("%d %d\n",r[0],r[n-1]);
    //printf("%d\n",r[n-1]);
    for(int i=r[n-1],j=0;j<n;++j,i=(i+k)%n)
        printf("%c",str[i]);
    return 0;
}
