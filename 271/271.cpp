#include <cstdio>
#include <iostream>
#include <deque>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 100000
#define N 40000
char name[M+N+1][7];
int p[1+(N+M+1)][5],poi;
int main()
{
  freopen("in.txt","r",stdin);
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int pre=0,qi=0,det=0;
  for(int i=1;i<=n;++i)
    {
      scanf("\n%s",name+i);
      ++poi,p[poi][0]=n+1-i;
      p[poi][1]=poi-1;
      p[poi-1][2]=poi;
      ++det;
      if(det>k)
	{
	  int tmp=qi;
	  qi=(p[qi][1]==pre?p[qi][2]:p[qi][1]);
	  pre=tmp;
	  --det;
	}
    }
//   for(int i=poi,j=0;i;)
//     {
//       printf("%s\n",name[p[i][0]]);
//       int tmp=i;
//       i=(j==p[i][1]?p[i][2]:p[i][1]);
//       j=tmp;
//     }
  for(int i=0;i<m;++i)
    {
      char t;
      scanf("\n%c",&t);
      if(t=='A')
	{
	  ++n;
	  scanf("DD(%s",name[n]);
	  name[n][strlen(name[n])-1]='\0';
	  if(p[poi][2]==0)
	    p[poi][2]=n;
	  else p[poi][1]=n;
	  p[n][0]=n;
	  p[n][1]=poi;
	  poi=n;
	  ++det;
	  if(det>k)
	    {
	      int tmp=qi;
	      qi=(pre==p[qi][1]?p[qi][2]:p[qi][1]);
	      pre=tmp;
	      --det;
	    }
	}
      else
	{
	  scanf("OTATE");
	  if(n && k>1)
	    {
	      int nxti=(pre==p[qi][1]?2:1);
	      int nxt=p[qi][nxti];
	      p[qi][nxti]=poi;
	      if(p[poi][1]==0)
		p[poi][1]=qi;
	      else
		p[poi][2]=qi;
	      poi=nxt;
	      if(p[nxt][1]==qi)
		p[nxt][1]=0;
	      else p[nxt][2]=0;
	    }
	}
    }
  for(int i=poi,j=0;i;)
    {
      printf("%s\n",name[p[i][0]]);
      int tmp=i;
      i=(j==p[i][1]?p[i][2]:p[i][1]);
      j=tmp;
    }
  return 0;
}
