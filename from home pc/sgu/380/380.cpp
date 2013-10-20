#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
#define N 100007
int p[N];
int n;
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  map<int,int> map1,map2;
  map<int,int>::iterator ite;
  for(int i=0,j=n-1;;)
    {
      if(i>=j)
	{
	  printf("YES");
	  return 0;
	}
      if(BET(p[i+1],p[j],p[j-1]))
	++i;
      else if(BET(p[j-1],p[i],p[i+1]))
	{
	  for(;;)
	    {
	      ite=map2.begin();
	      if(ite==map2.end())
		break;
	      if(ite->first>=p[j-1])
		map2.erase(ite);
	      else break;
	    }
	  map2[p[j-1]]=j;
	  for(;;)
	    {
	      ite=map1.begin();
	      if(ite==map1.end())
		break;
	      if(ite->first<=p[j])
		map1.erase(ite);
	      else break;
	    }
	  map1[p[j]]=j;
	}
    }
  return 0;
}
