#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int p[100000][4];
int q[100000][2];
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c!=*d)
    return *c-*d;
  return *(c+1)-*(d+1);
}
bool is[100000];
int num[100000];
int get1(int f,int l,int v)
{
  for(;f<=l;)
    {
      int m=(f+l)>>1;
      if(q[m][0]<v)
	f=m+1;
      else l=m-1;
    }
  return f;
}
int get2(int f,int l,int v)
{
  for(;f<=l;)
    {
      int m=(f+l)>>1;
      if(q[m][0]>v)
	l=m-1;
      else f=m+1;
    }
  return l;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<n;++i)
    {
      scanf("%d%d",*(p+i),*(p+i)+1);
      p[i][2]=(i-1+n)%n;
      p[i][3]=(i+1)%n;
    }
  int cc=0;
  for(int i=0,j=0;j<n;)
    {
      int nxt=p[i][3];
      int pre=p[i][2];
      if(p[nxt][0]==p[i][0] && p[pre][0]==p[i][0])
	p[pre][3]=nxt,p[nxt][2]=pre,j=0;
      else ++j;
      cc=i=nxt;
    }
  //for(int i=cc;;i=p[i][3])
  //{cout<<p[i][0]<<' '<<p[i][1]<<endl;if(p[i][3]==cc)break;}
  for(int i=0;i<m;++i)
    scanf("%d%d",*(q+i),*(q+i)+1);
  qsort(q,m,sizeof(q[0]),cmp);
  for(int i=cc;;i=p[i][3])
    {
      int x1=p[i][0],y1=p[i][1];
      int x2=p[p[i][3]][0],y2=p[p[i][3]][1];
      if(x1>x2)
	x1^=x2,y1^=y2,
	  x2^=x1,y2^=y1,
	  x1^=x2,y1^=y2;
      int a=get1(0,m-1,x1);
      int b=get2(0,m-1,x2);
      if(x1==x2)
	{
	  if(y1>y2)
	    y1^=y2,y2^=y1,y1^=y2;
	  for(int j=a;j<m && j<=b;++j)
	    if(q[j][1]<=y2 && q[j][1]>=y1)
	      is[j]=true;
	  else if(q[j][1]<y1)
	     ++num[j];
	}
      else
	{
	  for(int j=a;j<m && j<=b;++j)
	    {
	      ll yy1=y1,yy2=y2,x=q[j][0],xx1=x1,xx2=x2,y_=q[j][1];
	      ll tmp=(yy1*(x-xx2)-yy2*(x-xx1)-y_*(xx1-xx2))*(xx1<xx2?-1:1);
	      if(tmp==0)
		is[j]=true;
	      if(tmp>0 && q[j][0]!=p[i][0])
		++num[j];
	    }
	}
      if(p[i][3]==cc)
	break;
    }
  //for(int i=0;i<m;++i)
  //cout<<num[i]<<' '<<q[i][0]<<' '<<q[i][1]<<endl;
  for(int i=0;i<m;++i)
    if(1&num[i])
      is[i]=true;
  int ans(0);
  for(int i=0;i<m;++i)
    if(is[i])
      ++ans;
  cout<<(ans>=k?"YES":"NO");
  return 0;
}
