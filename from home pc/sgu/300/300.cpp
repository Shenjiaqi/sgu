#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define N (4000)
#define DET (1e-14)
typedef long long ll;
bool bet(ll a,ll b,ll m)
{
  if(a>b)
    a^=b,b^=a,a^=b;
  return (a<=m && m<=b);
}
bool cross(int x1,int y1,int x2,int y2,int xx1,int yy1,int xx2,int yy2)
{
  ll a=y1-y2,d=yy1-yy2;
  ll b=x2-x1,e=xx2-xx1;
  ll c=b*(ll)y1+(ll)x1*a,f=e*(ll)yy1+d*(ll)xx1;
  ll tmp=a*e-b*d;
  if(tmp==0)
    return 0;
  ll x=(c*e-b*f)/tmp;
  ll y=(a*f-c*d)/tmp;
  //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<xx1<<' '<<yy1<<' '<<xx2<<' '<<yy2<<'!'<<x<<endl;
  return (bet(x1,x2,x) && bet(xx1,xx2,x) && bet(y1,y2,y) && bet(yy1,yy2,y));
}
int p[N+1][3];
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  int ans(0);
  for(int i=0;i<n;++i)
    {
      cin>>p[i][0]>>p[i][1];
      if(i)
        ans+=(abs(p[i][0]-p[i-1][0])+abs(p[i][1]-p[i-1][1]));
      p[i][2]=ans;
      //cout<<j<<endl;
    }
  for(int i=1;i<n;++i)
    for(int j=i+2;j<n;++j)
      {
        if(cross(p[i-1][0],p[i-1][1],
             p[i][0],p[i][1],
             p[j-1][0],p[j-1][1],
             p[j][0],p[j][1]))
          {
            if(p[i][0]==p[i-1][0])
              ans=min(ans,p[j-1][2]+abs(p[i][0]-p[j-1][0])-
                  (p[i-1][2]+abs(p[j][1]-p[i-1][1])));
            else
              ans=min(ans,p[j-1][2]+abs(p[i][1]-p[j-1][1])-
                  (p[i-1][2]+abs(p[j][0]-p[i-1][0])));
            //cout<<i<<' '<<j<<' '<<ans<<endl;
          }
      }
  cout<<ans;
  return 0;
}
