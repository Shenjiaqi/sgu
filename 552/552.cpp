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
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  vector<string> tmp;
  map<string,int> mapp;
  for(int i=0;i<n;++i)
    {
      int k;
      scanf("%d",&k);
      tmp.resize(k);
      for(int j=0;j<k;++j)
	cin>>tmp[j];
      sort(tmp.begin(),tmp.end());
      for(int j=1;j<(1<<k);++j)
	{
	  string ttmp;
	  for(int l=1,c=0;l<=j;l<<=1,++c)
	    if(l&j)
	      {
		if(ttmp.length()>0)
		  ttmp+=" ";
		ttmp+=tmp[c];
	      }
	  ++mapp[ttmp];
	}
    }
  int m;
  scanf("%d",&m);
  for(int i=0;i<m;++i)
    {
      int k;
      scanf("%d",&k);
      tmp.resize(k);
      for(int j=0;j<k;++j)
	cin>>tmp[j];
      sort(tmp.begin(),tmp.end());
      string ttmp;
      for(int j=0;j<k;++j)
	{
	  if(ttmp.length()>0)
	    ttmp+=" ";
	  ttmp+=tmp[j];
	}
      map<string,int>::iterator ite;
      ite=mapp.find(ttmp);
      if(ite==mapp.end())
	printf("0\n");
      else printf("%d\n",(ite->second));
    }
  return 0;
}
