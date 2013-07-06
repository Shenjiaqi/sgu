#include <cstdio>
#include <iostream>
using namespace std;
#define N 200000
int p[N][2];
int q[N][4];
int main()
{
  freopen("in.txt","r",stdin);
  int n,d;
  scanf("%d%d",&n,&d);
  for(int i=0;i<n;++i)
    scanf("%d%d",&p[i][0],&p[i][1]);
  q[0][0]=p[0][1],q[0][2]=0;
  for(int i=1;i<n;++i)
    if(p[i][1]>q[i-1][0])
      q[i][0]=p[i][1],q[i][2]=i;
    else q[i][0]=q[i-1][0],q[i][2]=q[i-1][2];
  q[n-1][1]=p[n-1][1],q[n-1][3]=n-1;
  for(int i=n-2;i>=0;--i)
    if(p[i][1]>q[i+1][1])
      q[i][1]=p[i][1],q[i][3]=i;
    else q[i][1]=q[i+1][1],q[i][3]=q[i+1][3];
  int maxv=-1;
  int a=-2,b=-2;
  for(int f=0,t=0;t<n;++f)
    {
      for(;t<n && p[t][0]-p[f][0]<d;++t)
	;
      if(t<n && maxv<q[f][0]+q[t][1])
	maxv=q[f][0]+q[t][1],a=q[f][2],b=q[t][3];
    }
  ++a,++b;
  cout<<a<<' '<<b<<endl;
  return 0;
}
