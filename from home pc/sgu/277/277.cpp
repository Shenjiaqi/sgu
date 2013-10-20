#include <cstdio>
#include <set>
#include <cmath>
using namespace std;
#define N (100000)
#define PI (3.141593)
#define DET (1e-13)
typedef long long ll;
int p[N+3][2];
double x,y;
ll area;
int n;
double angle(int a)
{
    double xa=p[a][0],ya=p[a][1];
    xa-=x,ya-=y;
    if(fabs(xa)<DET && fabs(ya)<DET)
        return 0;
    double ang=acos(xa/sqrt(xa*xa+ya*ya));
    if(ya<0)
        return ((double)2.0*PI-ang);
    return ang;
}
struct cmp
{
    bool operator()(int a,int b)
    {
        double a1=angle(a);
        double a2=angle(b);
        if(fabs(a1-a2)<DET)
            return a<b;
        return a1<a2;
    }
};
inline ll cross(ll x1,ll y1,ll x2,ll y2)
{
    return (x1*y2-y1*x2);
}
ll cal(int a,int b,int c)
{
    ll x1=p[a][0]-p[c][0],y1=p[a][1]-p[c][1];
    ll x2=p[b][0]-p[c][0],y2=p[b][1]-p[c][1];
    ll tmp=cross(x1,y1,x2,y2);
    if(tmp<0)
        return -tmp;
    return tmp;
}
set<int,cmp> sett;
bool test(int a,int b,int c)
{
    double x1=p[a][0],y1=p[a][1];
    double x2=p[c][0],y2=p[c][1];
    double xx=p[b][0],yy=p[b][1];
    return (((y1-yy)*(x2-x1)+(y2-y1)*(xx-x1))*((y1-y)*(x2-x1)+((y2-y1)*(x-x1))))<0;
}
int main()
{
    freopen("in.txt","r",stdin);
    x=y=0;
    for(int i=0;i<3;++i)
    {
        scanf("%d%d",*(p+i),*(p+i)+1);
        x+=p[i][0],y+=p[i][1];
    }
    area=cal(0,1,2);
    x/=3.0,y/=3.0;
    for(int i=0;i<3;++i)
        sett.insert(i);
    scanf("%d",&n);
    set<int,cmp>::iterator ite,ite1,ite2;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&p[i+3][0],&p[i+3][1]);
        ite=sett.insert(i+3).first;
        ite1=ite2=ite;
        if(ite1==sett.begin())
            ite1=sett.end();
        --ite1;
        ++ite2;
        if(ite2==sett.end())
            ite2=sett.begin();
        //for(set<int,cmp>::iterator ii=sett.begin();ii!=sett.end();++ii )printf("!%d ",*ii);printf("\n");
        if((x!=p[i][0]||y!=p[i][1])&&test(*ite1,*ite,*ite2))
        {
            if(fabs(angle(*ite)-angle(*ite1))<DET)
            {
                int tt=*ite1;
                sett.erase(ite1);
                ite1=ite;
                if(ite1==sett.begin())
                    ite1=sett.end();
                --ite1;
                area+=cal(*ite1,*ite,*ite2)-cal(tt,*ite2,*ite1);
            }
            else
                area+=cal(*ite1,*ite,*ite2);

            ite2=ite1;
            if(ite2==sett.begin()) ite2=sett.end();
            --ite2;

            for(int c=*ite;;)
            {
                int a=*ite1;
                int b=*ite2;
                if(cross(p[a][0]-p[c][0],p[a][1]-p[c][1],p[b][0]-p[c][0],p[b][1]-p[c][1])>=0)
                {
                    area+=cal(c,a,b);
                    sett.erase(ite1);
                    ite1=ite2;
                    if(ite2==sett.begin())
                        ite2=sett.end();
                    --ite2;
                }
                else break;
            }

            ite1=ite;
            ++ite1;
            if(ite1==sett.end())
                ite1=sett.begin();
            ite2=ite1;
            ++ite2;
            if(ite2==sett.end())
                ite2=sett.begin();
            for(int c=*ite;;)
            {
                int a=*ite1;
                int b=*ite2;
                if(cross(p[a][0]-p[c][0],p[a][1]-p[c][1],p[b][0]-p[c][0],p[b][1]-p[c][1])<=0)
                {
                    area+=cal(c,a,b);
                    sett.erase(ite1);
                    ite1=ite2;
                    ++ite2;
                    if(ite2==sett.end())
                        ite2=sett.begin();
                }
                else break;
            }
        }
        else sett.erase(ite);
        printf("%I64d\n",area);
        //printf("!%d\n",sett.size());
    }
    return 0;
}
