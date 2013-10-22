#include <cstdio>
#include <iostream>
using namespace std;
void p(int i,int k,bool dir)
{
  if(dir)
    {
      if(i==1)
	{
	  if(k>0)
	    printf("+1");
	}
      else if(k>1)
	{
	  p(i-1,k,true);
	  printf("+%d",i);
	  p(i-1,k-1,false);
	}
      else
	{
	  p(i-1,k,true);
	  printf("++%d",i-1);
	}
    }
  else
    {
      if(i==1)
	{
	  if(k>0)
	    printf("-1");
	}
      else if(k>1)
	{
	  p(i-1,k-1,true);
	  printf("-%d",i);
	  p(i-1,k,false);
	}
      else
	{
	  printf("--%d",i);
	  p(i-1,k,false);
	}
    }
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  p(n,k,true);
  printf("-%d",n);
  return 0;
}
