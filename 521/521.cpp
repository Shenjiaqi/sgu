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
#define N 100005
int p[N][5];
int q[N];
int n;
int cmp(const void * a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    return *(c+1)-*(d+1);
  return *c-*d;
}
void solv(int v)
{
  map<int,int> mapp;
  mapp[(int)1e9]=0;
  map<int,int>::iterator ite,tite;
  qsort(p,n,sizeof(p[0]),cmp);
  for(int i=n-1;i>=0;)
    {
      int k=i;
      for(int j=p[i][0];i>=0 && p[i][0]==j;--i)
	{
	  ite=mapp.upper_bound(p[i][1]);
	  p[i][v]=1+ite->second;
	}
      for(;k>i;--k)
	{
	  mapp[p[k][1]]=p[k][v];
	  ite=mapp.find(p[k][1]);
	  if(ite!=mapp.begin())
	    {
	      --ite;
	      for(;;)
		{
		  bool z=(ite==mapp.begin());
		  if(ite->second<=p[k][v])
		    {
		      tite=ite;
		      --ite;
		      mapp.erase(tite);
		    }
		  else break;
		  if(z)
		    break;
		}
	    }
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    {
      scanf("%d%d",*(p+i),*(p+i)+1);
      p[i][2]=i;
    }
  solv(3);
  for(int i=0;i<n;++i)
    p[i][0]=-p[i][0],p[i][1]=-p[i][1];
  solv(4);
  vector<int> a,b;
  int mm(0);
  for(int i=0;i<n;++i)
    {
      p[i][3]+=p[i][4];
      mm=max(p[i][3],mm);
    }
  for(int i=0;i<n;++i)
    if(p[i][3]==mm)
      {
	a.push_back(p[i][2]);
	++q[p[i][4]];
      }  
  sort(a.begin(),a.end());
  printf("%d",(int)a.size());
  for(int i=0;i<a.size();++i)
    printf(" %d",(1+a[i]));
  printf("\n");
  for(int i=0;i<n;++i)
    if(p[i][3]==mm && 1==q[p[i][4]])
      b.push_back(p[i][2]);
  sort(b.begin(),b.end());
  printf("%d",(int)b.size());
  for(int i=0;i<b.size();++i)
    printf(" %d",(1+b[i]));
  return 0;
}
