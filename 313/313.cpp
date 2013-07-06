#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>
#include <list>
using namespace std;
#define N 50000
int a[N],b[N];
int p[N*7][3],poi;
int s[N];
bool chg[N];
int q[N+1],qf,ql;
int n,l;
int md(int a,int b)
{
  int t=abs(a-b);
  return min(t,l-t);
}
int cmp(const void *c,const void *d)
{
  int *cc=(int*)c,*dd=(int*)d;
  if(*cc==*dd)
    {
      ++cc,++dd;
      if(*cc==*dd)
	++cc,++dd;
    }
  return *cc-*dd;
}
void add(int pos,int k,int val)
{
  p[poi][0]=pos,p[poi][1]=k,p[poi][2]=val;
  ++poi;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&l);
  for(int i=0;i<n;++i)
    scanf("%d",a+i);
  for(int i=0;i<n;++i)
    scanf("%d",b+i);
  for(int i=0;i<n;++i)
    --a[i],--b[i];
  sort(a,a+n);
  sort(b,b+n);
  for(int i=0;i<n;++i)
    cout<<a[i]<<' ';cout<<endl;
  int det(0);
  int now(0);
  for(int i=0,z;i<n;++i)
    {
      int c=(b[i]+(l-1)/2)%l;
      int f=0,t=n-1;
      for(;f<=t;)
	{
	  int m=(f+t)/2;
	  if(c>=a[m])
	    f=m+1;
	  else t=m-1;
	}
      f%=n;
      t=(f-i+n)%n;
      if(t)
	add(t,f,md(a[f],b[i])-md(a[(f-1+n)%n],b[i]));
      if(i)
	for(int j=(f+1)%n,c=1;j!=(1+z)%n;j=(j+1)%n,++c)
	  add(t+c,j,abs(a[j]-a[(j-1+n)%n]));
      z=f;
      s[i]=-abs(a[i]-a[(i-1+n)%n]);
      det+=s[i];
      now+=md(a[i],b[i]);
    }
  qsort(p,poi,sizeof(p[0]),cmp);
  int mink=l+1;
  int kk=0;
  cout<<det<<endl;
  for(int i=0;i<poi;++i)
    cout<<p[i][0]<<' '<<p[i][1]<<' '<<p[i][2]<<endl;
  for(int i=1,j=0;i<n;++i)
    {
      for(;j<poi && p[j][0]<=i;++j)
	{
	  int k=p[j][1];
	  int v=p[j][2];
	  if(s[k]!=v)
	    det+=(v-s[k]),s[k]=v;
	}
      cout<<det<<' '<<now<<endl;
      now+=det;
      if(now<mink)
	kk=i,mink=now;
    }
  printf("%d\n",mink);
  for(int i=0;i<n;++i)
    printf("%d ",(1+(i+kk)%n));
  return 0;
}
