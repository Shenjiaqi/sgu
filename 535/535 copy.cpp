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
vector<vector<char> > q;
vector<vector<ppi> > qoi[2];
int main()
{
  freopen("in","r",stdin);
  scanf("%s",p);
  q.resize(1);
  qoi.resize(1);
  int add=0;
  for(int i=0,j=0;p[i]!='\0';++i)
    {
      if(islower(p[i]))
	q[j].push_back(p[i]);
      else if(isupper(p[i]))
	{
	  char z=tolower(p[i]);
	  if(q[j].size()>0)
	    {
	      if(q[j][q[j].size()-1]!=z)
		{
		  printf("-1");
		  return 0;
		}
	      else q[j].pop_back(),++add;
	    }
	  else
	    {
	      for(int k=0;k<qoi.size();++k)
		FR(l,qoi[k])
		  {
		    int tmp=l->first;
		    typeof(l) lll=l++;
		    if(tmp<0)
		      {
			if(k>0 && q[k-1][q[k-1].size()-1]==z)
			  qoi[k-1].push_back(ppi(q[k-1].size()-1,l->second+1));
			q[k].erase(lll);
		      }
		    else if(p[k][tmp]!=z)
		      {
			if(!(lll->first==0 && k>0))
			  qoi[k].erase(lll);
		      }
		    else
		      {
			++(lll->second),--(lll->first);
			if(lll->first==0 && k)
			  qoi[k].erase(lll);
		      }
		  }
	    }
	}
      else
	{
	  q.resize(++j);
	  qoi.resize(j);
	  qoi.push_back(ppi(-1,0));
	  qoi[j-1].push_back(ppi(q[j].size()-1,0));
	}
    }
  int minval=1e9+1;
  FR(i,qoi[0])
    if(i->first<0 && i->second<minval)
      minval=i->second;
  if(minval>=1e9)
    printf("-1");
  else printf("%d",(minval+add));
  return 0;
}
