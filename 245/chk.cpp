#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
int ccc;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)

#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define DOW0(i,x) for(i=x;i>=0;i--)
#define DOW1(i,x) for(i=x;i>=1;i--)
#define DOW(i,a,b) for(i=a;i>=b;i--)
using namespace std;


void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%I64d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%I64d%I64d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%I64d%I64d%I64d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}


void PR(int x) {printf("%d\n",x);}
void PR(i64 x) {printf("%I64d\n",x);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {printf("%llu\n",x);}
void PR(double x) {printf("%.4lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

struct point
{
    int x,y;

    point(){}
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};

const int INF=1<<29;
const int N=305;
int attack[N][N],reach[N][N],cost[N];
char g[N][N];
int n,m,lose;
map<char,int> Map;

vector<point> GoP(point s,int flag)
{
    vector<point> ans;
    if(g[s.x-1][s.y-1]!='#') ans.pb(point(s.x-1,s.y-1));
    if(g[s.x-1][s.y+1]!='#') ans.pb(point(s.x-1,s.y+1));
    return ans;
}

vector<point> GoR(point s,int flag)
{
    vector<point> ans;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};
    int i;
    point t;
    FOR0(i,4)
    {
        t=point(s.x+dx[i],s.y+dy[i]);
        while(g[t.x][t.y]=='.')
        {
            if(flag&&!attack[t.x][t.y]) break;
            ans.pb(t);
            t.x+=dx[i];
            t.y+=dy[i];
        }
        ans.pb(t);
    }
    return ans;
}

vector<point> GoK(point s,int flag)
{
    vector<point> ans;
    int dx[]={-2,-2,-1,1,2,2,1,-1};
    int dy[]={-1,1,2,2,1,-1,-2,-2};
    int i;
    FOR0(i,8) ans.pb(point(s.x+dx[i],s.y+dy[i]));
    return ans;
}


vector<point> GoB(point s,int flag)
{
    vector<point> ans;
    int dx[]={-1,-1,1,1};
    int dy[]={-1,1,1,-1};
    int i;
    point t;
    FOR0(i,4)
    {
        t=point(s.x+dx[i],s.y+dy[i]);
        while(g[t.x][t.y]=='.')
        {
            if(flag&&!attack[t.x][t.y]) break;
            ans.pb(t);
            t.x+=dx[i];
            t.y+=dy[i];
        }
        ans.pb(t);
    }
    return ans;
}

vector<point> GoQ(point s,int flag)
{
    vector<point> ans;
    int dx[]={-1,-1,-1,0,1,1,1,0};
    int dy[]={-1,0,1,1,1,0,-1,-1};
    int i;
    point t;
    FOR0(i,8)
    {
        t=point(s.x+dx[i],s.y+dy[i]);
        while(g[t.x][t.y]=='.')
        {
            if(flag&&!attack[t.x][t.y]) break;
            ans.pb(t);
            t.x+=dx[i];
            t.y+=dy[i];
        }
        ans.pb(t);
    }
    return ans;
}

vector<point> GoM(point s,int flag)
{
    vector<point> ans;
    int dx[]={-1,-1,-1,0,1,1,1,0};
    int dy[]={-1,0,1,1,1,0,-1,-1};
    int i;
    FOR0(i,8) ans.pb(point(s.x+dx[i],s.y+dy[i]));
    return ans;
}

vector<point> Go(char c,point s,int flag)
{
    if(c=='P') return GoP(s,flag);
    else if(c=='R') return GoR(s,flag);
    else if(c=='K') return GoK(s,flag);
    else if(c=='B') return GoB(s,flag);
    else if(c=='Q') return GoQ(s,flag);
    else if(c=='M') return GoM(s,flag);
}

void copy(int a[N][N],int b[N][N])
{
    int i,j;
    for(i=0;i<=n+3;i++) for(j=0;j<=m+3;j++)
    {
        a[i][j]=b[i][j];
    }
}

int deal(char c,int sx,int sy)
{
    queue<point> Q;
    vector<point> p,q;
    int a[N][N]={0},visit[N][N]={0};
    int i,j,k,ans=0,temp;
    point u;
    for(i=0;i<=n+3;i++) for(j=0;j<=m+3;j++)
    {
        if(g[i][j]!='#'&&g[i][j]!='.')
        {
            p=Go(g[i][j],point(i,j),0);
            FOR0(k,SZ(p)) a[p[k].x][p[k].y]++;
        }
        else if(g[i][j]=='#') a[i][j]=INF;
    }
    copy(attack,a);
    // for(int i=2;i<2+n;++i){
    //   for(int j=2;j<2+m;++j)
    // 	if(attack[i][j]<300)
    // 	cout<<a[i][j]<<' ';
    // 	else cout<<0<<' ';cout<<endl;}
    q=Go(c,point(sx,sy),1);
    FOR0(i,SZ(q))
    {
        if(g[q[i].x][q[i].y]=='#') continue;
        if(visit[q[i].x][q[i].y]) continue;
        temp=0;
        clr(reach,0);
        copy(attack,a);
        if(!attack[q[i].x][q[i].y])
        {
            Q.push(q[i]);
            reach[q[i].x][q[i].y]=1;
        }
        else
        {
            reach[q[i].x][q[i].y]=2;
        }
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            if(g[u.x][u.y]=='#') continue;
            if(g[u.x][u.y]!='.')
            {
                temp+=cost[Map[g[u.x][u.y]]];
                ans=max(ans,temp);
                p=Go(g[u.x][u.y],u,0);
                FOR0(j,SZ(p))
                {
                    attack[p[j].x][p[j].y]--;
                    if(!attack[p[j].x][p[j].y]&&reach[p[j].x][p[j].y]==2)
                    {
                        reach[p[j].x][p[j].y]=1;
                        Q.push(p[j]);
                    }
                }
            }
            p=Go(c,u,1);
            FOR0(j,SZ(p))
            {
                if(!attack[p[j].x][p[j].y]&&!reach[p[j].x][p[j].y])
                {
                    reach[p[j].x][p[j].y]=1;
                    Q.push(p[j]);
                }
                else if(attack[p[j].x][p[j].y]&&!reach[p[j].x][p[j].y])
                {
                    reach[p[j].x][p[j].y]=2;
                }
            }
        }
        for(k=2;k<=n+1;k++) for(j=2;j<=m+1;j++) if(reach[k][j])
        {
            visit[k][j]=1;
            if(reach[k][j]==2) ans=max(ans,temp+cost[Map[g[k][j]]]-lose);
        }
    if(ans==9267 &&ccc==0)
      {
	cout<<c<<endl;
      for(int i=2;i<2+n;++i){++ccc;
	for(int j=2;j<2+m;++j)
	  cout<<visit[i][j];cout<<endl;}
      }
    }
    return ans;
}

int main()
{
    RD(n,m);
    Map['P']=0;Map['R']=1;Map['K']=2;
    Map['B']=3;Map['Q']=4;Map['M']=5;
    int i,j;
    FOR0(i,6) RD(cost[i]);
    RD(lose);
    for(i=2;i<=n+1;i++) RD(g[i]+2);
    for(i=0;i<=n+3;i++) g[i][0]=g[i][1]=g[i][m+2]=g[i][m+3]='#';
    for(i=0;i<=m+3;i++) g[0][i]=g[1][i]=g[n+2][i]=g[n+3][i]='#';
    int sx,sy;
    FOR0(i,n+2) FOR0(j,m+2) if(g[i][j]=='@') sx=i,sy=j,g[i][j]='.';
    int ans=0;
    //ans=max(ans,deal('R',sx,sy));
    //ans=max(ans,deal('B',sx,sy));
    ans=max(ans,deal('K',sx,sy));
    // cout<<ans<<endl;
    ans=max(ans,deal('Q',sx,sy));
    PR(ans);
}
