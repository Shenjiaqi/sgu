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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 2500
char p[N+70];
struct ele
{
  int ch,va,to;
  ele(int c,int v,int t):ch(c),va(v),to(t){};
};
vector<ele> dp[N+70];
int q[N+70];
void add(int pos,int ch,int va,int to)
{
  dp[pos].push_back(ele(ch,va,to));
}
int main()
{
  freopen("in","r",stdin);
  scanf("%s",p);
  int addd(0);
  for(int i=-1,j=0;;++j)
    {
      if(!p[j])
	{
	  p[++i]=0;
	  break;
	}
      else if(i<0)
	p[++i]=p[j];
      else if(islower(p[i]) && isupper(p[j]))
	{
	  if(p[i]!=tolower(p[j]))
	    {
	      printf("-1");
	      return 0;
	    }
	  --i,++addd;
	}
      else
	p[++i]=p[j];
    }
  //  printf("%s %d\n",p,addd);
  const int inf=1e9;
  q[0]=0;
  for(int i=0,j=1;p[i];++i)
    {
      if(p[i]=='*')
	{
	  bool flg=true;
	  for(int k=j-1;k>=0;--k)
	    if(q[k]<inf)
	      {
		flg=false;
		for(int l=dp[k].size()-1;l>=0;--l)
		{
		  int va=dp[k][l].va+q[k];
		  int to=dp[k][l].to;
		  q[to]=min(q[to],va);
		}
	      }
	  if(flg)
	    {
	      printf("-1");
	      return 0;
	    }
	  add(j,0,1,j);
	  q[j]=0;
	  for(int k=j-1;k>=0;--k)
	    if(q[k]<inf)
	      add(j,0,q[k]+1,k);
	  ++j;
	}
      else if(isupper(p[i]))
	{
	  bool flg=true;
	  int z=tolower(p[i]);
	  for(int k=0;k<j;++k)
	    if(q[k]<inf)
	      {
		int zz=q[k];
		q[k]=inf;
		for(int l=dp[k].size()-1;l>=0;--l)
		  {
		    int ch=dp[k][l].ch;
		    if(0==ch || ch==z)
		      {
			flg=false;
			int va=dp[k][l].va+zz;
			int to=dp[k][l].to;
			q[to]=min(q[to],va);
		      }
		  }
	      }
	  if(flg)
	    {
	      printf("-1");
	      return 0;
	    }
	}
      else
	{
	  bool flg=true;
	  q[j]=0;
	  for(int k=0;k<j;++k)
	    if(q[k]<inf)
	      {
		flg=false;
		add(j,p[i],q[k]+1,k);
		q[k]=inf;
	      }
	  if(flg)
	    {
	      printf("-1");
	      return 0;
	    }
	  ++j;
	}
    }
  if(q[0]<inf)
    printf("%d",q[0]+addd);
  else printf("-1");
  return 0;
}
