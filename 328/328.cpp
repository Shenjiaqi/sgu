#include <cstdio>
#include <iostream>
using namespace std;
#define N 100000
int cal(int l,int r,int len)
{
  if(len==0)
    return 0;
  if(l==0 && r==0)
    return (len&1);
  if(l==0 || r==0)
    return len;
  return (l==r?1:0);
}
int main()
{
  int n;
  freopen("in.txt","r",stdin);
  scanf("%d\n",&n);
  int l(0);
  int a(0);
  int j(0);
  for(int i=0;i<n;)
    {
      char t;
      scanf("%c",&t);
      if(t=='0' || t=='1' || t=='2')
	{
	  ++i;
	  int k=(int)(t-'0');
	  if(k==0)
	    ++l;
	  else
	    {
	      if(l)
		a^=cal(j,k,l);
	      l=0,j=k;
	    }
	}
    }
  if(l)
    a^=cal(j,0,l);
  printf("%s",(a?"FIRST":"SECOND"));
  return 0;
}
