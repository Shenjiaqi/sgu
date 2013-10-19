#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100000
#define M ((1+N)/2*3)
list<ppi> p[N+1];
int q[(M+sizeof(int)-1)/sizeof(int)+1];
void filt(int a)
{
  for(typeof(p[a].begin()) i=p[a].begin();i!=p[a].end();)
    {
      int tmp=i->second;
      if(q[tmp/sizeof(int)]&(1<<(tmp%sizeof(int))))
	{
	  typeof(i) tmp=i++;
	  p[a].erase(tmp);
	}
      else ++i;
    }
}
bool chk(int a,int z)
{
  FR(i,p[a])
    if(i->first==z)
      return true;
  return false;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  FOR(i,0,m)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      if(p[a].size()<3)
	p[a].push_back(ppi(b,i+1));
      if(p[b].size()<3)
	p[b].push_back(ppi(a,i+1));
    }
  int z=1;
  int cnt=0;
  FOR(i,0,n)
    if(p[i+1].size()>2)
      {
	z=i+1;
	++cnt;
      }
  char buf[10];
  for(int a,b;EOF!=scanf("%s%d",buf,&a);)
    {
      if(buf[0]=='L')
	{
	  scanf("%d",&b);
	  if(a==b)
	    printf("0\n");
	  else
	    {
	      if(a==z)
		swap(a,b);
	      if(b==z)
		{
		  filt(a);
		  if(p[a].size()==0)
		    printf("-1\n");
		  else if(chk(a,z))
		    printf("1\n");
		  else
		    {
		      filt(p[a].begin()->first);
		      if(chk(p[a].begin()->first,z))
			printf("2\n");
		      else printf("-1\n");
		    }
		}
	      else
		{
		  filt(a);filt(b);
		  if(p[a].size()==0 || p[b].size()==0)
		    printf("-1\n");
		  else
		    {
		      if(chk(a,b))
			printf("1\n");
		      else
			{
			  int c=-1;
			  if(chk(a,z))
			    c=1;
			  else
			    {
			      filt(p[a].begin()->first);
			      if(chk(p[a].begin()->first,z))
				c=2;
			    }
			  if(c>0)
			    {
			      if(chk(b,z))
				c+=1;
			      else
				{
				  filt(p[b].begin()->first);
				  if(chk(p[b].begin()->first,z))
				    c+=2;
				  else c=-1;
				}
			    }
			  printf("%d\n",c);
			}
		    }
		}
	    }
	}
      else
	q[a/sizeof(int)]|=(1<<(a%sizeof(int)));
    }
  return 0;
}
