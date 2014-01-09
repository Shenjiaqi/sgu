#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long double ld;
const ld d=6000;
ld p[4][2];
ld dis(ld x1,ld y1,ld x2,ld y2)
{
  x1-=x2;
  y1-=y2;
  return sqrtl(x1*x1+y1*y1);
}
int main()
{
  int n=1;
  p[0][0]=p[0][1]=d/2.0/sqrtl(2.0);
  p[1][0]=p[1][1]=d-p[0][0];
  p[2][1]=p[0][0],p[2][0]=d-p[0][0];
  ld s1=700;
  ld s2=300;
  p[0][0]+=s1;
  p[0][1]-=s2;
  p[1][0]-=s1;
  p[1][1]+=s2;
  for(int i=0;i<3;++i)
    cout<<(p[i][0]/d)<<' '<<(p[i][1]/d)<<endl;
  ld cnt=0;
  for(int i=0;i<d;++i)
    for(int j=0;j<d;++j)
      {
	ld x=(ld)i+.5,y=(ld)j+.5;
	if(dis(x,y,p[0][0],p[0][1])<=d/2 ||
	   dis(x,y,p[1][0],p[1][1])<=d/2 || 
	   dis(x,y,p[2][0],p[2][1])<=d/2
	   )
	  cnt+=1;
      }
  cout<<cnt<<endl;
  printf("%d",(int)(cnt*100/(d*d)));
  return 0;
}
