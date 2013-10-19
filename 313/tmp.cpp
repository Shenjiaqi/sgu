#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","r",stdin);
  int n,l;
  cin>>n>>l;
  typedef pair<int,int> pp;
  vector<pp> a,b;
  a.resize(n),b.resize(n);
  for(int i=0;i<n;++i)
    {
      cin>>a[i].first;
      a[i].second=i+1;
    }
  for(int i=0;i<n;++i)
    {
      cin>>b[i].first;
      b[i].second=i+1;
    }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int off=0;
  ll mino=(ll)1<<62;
  for(int i=0;i<n;++i)
    {
      ll s(0);
      for(int j=0;j<n;++j)
	{
	  int tmp=abs(a[j].first-b[(i+j)%n].first);
	  s+=min(tmp,l-tmp);
	}
      if(mino>s)
	mino=s,off=i;
    }
  cout<<mino<<endl;
  for(int i=0;i<n;++i)
    cout<<b[(i+off)%n].second<<' ';
  return 0;
}
