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
  multimap<int,int> mapp;
  for(int i=0;i<n-2;++i)
    {
      char t;
      int g;
      cin>>t>>g;
      if(t=='d')
	mapp.insert(make_pair(g,i));
      else
	for(;mapp.size()>=g;)
	  mapp.erase(mapp.begin());
    }
  char t;
  int g;
  cin>>t>>g;
  if(g<=mapp.size())
    {
      int a(0);
      vector<int> p;
      for(;mapp.size()>0;mapp.erase(mapp.begin()))
	a+=mapp.begin()->first,p.push_back(mapp.begin()->second);
      cout<<a<<endl<<p.size()<<endl;
      sort(p.begin(),p.end());
      for(int i=0;i<p.size();++i)
	cout<<(2+p[i])<<' ';
    }
  else cout<<-1;
  return 0;
}
