#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int main()
{
  scanf("%d",&n);
  int od=n,ev=n+1;
  if(ev&1)
    swap(od,ev);
  for(int i=0;i<(n-1)/2;++i)
    {
      queue<int> r,rr;
      for(int j=i;j<n-i;++j)
	{
	  int v=i*n+j+1;
	  if(0!=((i+j)&1))
	    rr.push(v);
	  else r.push(v);
	  v=(n-1-i)*n+j+1;
	  if(0!=((n-1-i+j)&1))
	    rr.push(v);
	  else r.push(v);
	}
      if(rr.size())
	{
	  printf("%d",ev);
	  ev+=2;
	  for(;!rr.empty();rr.pop())
	    printf(" %d",rr.front());
	}
      if(r.size())
	{
	  printf("\n%d",od);
	  od+=2;
	  for(;!r.empty();r.pop())
	    printf(" %d",r.front());
	}
      for(int j=i+1;j<n-1-i;++j)
	{
	  int v=j*n+n-1-i+1;
	  if(1!=((n-1-i+j)&1))
	    rr.push(v);
	  else r.push(v);
	  v=j*n+i+1;
	  if(1!=((i+j)&1))
	    rr.push(v);
	  else r.push(v);
	}
      if(rr.size())
	{
	  printf("\n%d",ev);
	  ev+=2;
	  for(;!rr.empty();rr.pop())
	    printf(" %d",rr.front());
	}
      if(r.size())
	{
	  printf("\n%d",od);
	  od+=2;
	  for(;!r.empty();r.pop())
	    printf(" %d",r.front());
	  printf("\n");
	}
    }
  if((n&1)==0)
    {
      int i=(n-1)/2;
      printf("%d %d\n",ev,i*n+i+1+1);
      printf("%d %d %d",od,i*n+i+1,(i+1)*n+i+1+1);
    }
  return 0;
}
