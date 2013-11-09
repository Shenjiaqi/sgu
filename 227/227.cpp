#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define N 50
typedef long double ld;
const ld det=1e-13;
int p[N][3][2];
ld c[N][3];
void gp(ld a,ld b,ld c,
	ld aa,ld bb,ld cc,
	ld &x,ld &y)
{
  ld d=a*bb-aa*b;
  ld xx=aa*c-a*cc;
  ld yy=cc*b-c*bb;
  x=xx/d,y=yy/d;
}
ld dis(ld x,ld y,ld xx,ld yy)
{
  x-=xx,y-=yy;
  return sqrt(x*x+y*y);
}
void gl(ld x,ld y,ld xx,ld yy,
	ld &a,ld &b,ld &c)
{
  ld mx=(x+xx)/2.0;
  ld my=(y+yy)/2.0;
  a=x-xx,b=y-yy;
  c=a*mx+b*my;
}
void gc(int i,ld &x,ld &y,ld &r)
{
  ld a,b,c,aa,bb,cc;
  gl(p[i][0][0],p[i][0][1],p[i][1][0],p[i][1][1],
	 a,b,c);
  gl(p[i][0][0],p[i][0][1],p[i][2][0],p[i][2][1],
     aa,bb,cc);
  gp(a,b,c,aa,bb,cc,x,y);
  r=dis(p[i][0],p[i][1],x,y);
}
void gcp(int a,int b,ld &x,ld &y,ld &xx,ld &yy)
{
  
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    for(int j=0;j<3;++j)
      scanf("%d%d",&p[i][j][0],&p[i][j][1]);
  for(int i=0;i<n;++i)
    gc(i,c[i][0],c[i][1],c[i][2]);
  int ansi(0);
  ld ans[N*N+1][2];
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(j!=i)
	{
	  ld d1=dis(c[i][0],c[i][1],c[j][0],c[j][1]);
	  ld d2=c[i][2]+c[j][2];
	  if(d1<d2+det)
	    {
	      ld x,y,xx,yy;
	      gcp(i,j,x,y,xx,yy);
	      if(check(x,y,i) && check(x,y,j))
		ans[ansi][0]=x,ans[ansi][1]=y,++ansi;
	      if(fabs(d1-d2)>det && check(xx,yy,i) && check(xx,yy,j))
		ans[ansi][0]=xx,ans[ansi][1]=yy,++ansi;
	    }
	}
  printf("%d",ansi);
  for(int i=0;i<ansi;++i)
    printf("\n%.3lf %.3lf",ans[i][0],ans[i][1]);
  return 0;
}
