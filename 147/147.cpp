#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define SWP(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
#define INF (~(1<<31))
int n,p1,q1,p2,q2,p3,q3,ans;
bool judge()
{
    if(abs(p1-p2)<abs(q1-q2))
    {
        SWP(p1,q1);
        SWP(p2,q2);
        SWP(p3,q3);
    }
    if(p1>p2)
    {
        SWP(p1,p2);
        SWP(q1,q2);
    }
    ans=INF;
    int z=p2-p1-((p2-p1-abs(q2-q1))>>1);
    int a=p1+1,b=p2;
    for(int i=p1+1;i<p2;++i)
    {
        int step=min(i-p1,p2-i);
        int a=abs(p3-i);
        if(step*2>=p2-p1-1 || a>step || ans<=step)
            continue;
        int qu=(((i-p1)<z)?(q1+(q2>q1?(i-p1):(p1-i))):(q2+(q2>q1?(p2-i):(i-p2))));
        int qd=(((p2-i)<z)?(q2-(q2>q1?(p2-i):(i-p2))):(q1-(q2>q1?(i-p1):(p1-i))));
        if(qu<qd)
            SWP(qu,qd);
        qu=min(qu,n);
        qd=max(qd,1);
        if(q3<=qu && q3>=qd)
        {
            if(max(qu-q3,q3-qd)>=step || a==step)
                ans=step;
        }
        else
        {
            int l1=abs(qu-q3);
            int l2=abs(qd-q3);
            if(l1>l2)
                SWP(l1,l2);
            if((l1<=step && l2>=step) || (l1<=step && a==step))
                ans=step;
        }
    }
    if(ans<INF)
        return 1;
    ans=max(0,p2-p1-1);
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d\n%d %d\n%d %d\n%d %d",&n,&p1,&q1,&p2,&q2,&p3,&q3);
    bool tmp=judge();
    printf("%s\n%d",(tmp?"YES":"NO"),ans);
    return 0;
}
