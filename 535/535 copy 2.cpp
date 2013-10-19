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
#include <cctype>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 2500
char p[N+7];
class ele
{
public:
  char c;
  int add;
  int to;
  ele(char cc,int aa,int tt){c=cc,add=aa,to=tt;};
};
vector<vector<ppi> >a;
int b[2][N+7];
void goo(int &f,int &t,int s,char z)
{
  memset(b[t],1<<6,sizeof(b[t][0])*(s+1));
  for(int j=s;j>=0;--j)
    if(b[f][j]<inf)
      for(int k=0;k<a[j].size();++k)
	if(a[j][k].c<0)
	  b[f][to]=min(b[f][to],b[f][j]);
  for(int j=0;j<=s;++j)
    {
      int to=a[j][k].to;
      int val=a[j][k].add+b[f][j];
      if(a[j][k].c==0 || a[j][k].c==z)
	b[t][to]=min(b[to],val);
    }
  swap(f,t);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%s",p);
  int ans=0;
  for(int i=-1,j=0;;)
    {
      if(p[j]==0)
	{
	  p[++i]=0;
	  break;
	}
      else if(i<0)
	p[++i]=p[j++];
      else if(islower(p[i]) && isupper(p[j]))
	{
	  if(p[i]!=tolower(p[j]))
	    {
	      printf("-1");
	      return 0;
	    }
	  --i,++j;
	  ++ans;
	}
      else
	p[++i]=p[j++];
    }
  a.resize(1);
  int f,t;
  f=0,t=1;
  memset(b[t],1<<6;sizeof(b[t]));
  int inf=b[t][0];
  b[0][0]=0;
  for(int i=0;p[i];++i)
    {
      if(islower(p[i]))
	{
	  int s=a.size();
	  a.resize(s+1);
	  b.resize(s+1);
	  b[f][s]=inf;
	  if(i==0 || !islower(p[i-1]))
	    {
	      for(int j=0;j<s;++j)
		{
		  int tmp=b[f][j];
		  b[f][j]=inf;
		  if(tmp<inf)
		    a[s].push_back(ele(p[i],tmp+1,j));
		}
	    }
	  else
	    a[s].push_back(ele(p[i],1,s-1));
	}
      else if(p[i]=='*')
	{
	  int s=a.size();
	  a.resize(s+1);
	  a[s].push_back(ele(0,1,s));
	  a[s].push_back(ele(0,1,s-1));
	  b[f][s-1]=min(b[f][s-1],1);
	  for(int j=s-2,k=1;j>=0;--j,++k)
	    {
	      a[s].push_back(ele(-1,k,j));
	      b[f][j]=min(b[f][j],k);
	    }
	  b[f][s]=0;
	}
      else
	{
	  char z=tolower(p[i]);
	  if(i==0)
	    {
	      printf("-1");
	      return 0;
	    }
	  if(!isupper(p[i-1]))
	    b[f][a.size()-1]=0;
	  goo(f,t,a.size()-1);
	}
    }
  if(b[f][0]<inf)
    printf("%d",b[f][0]+ans);
  else printf("-1");
  return 0;
}
