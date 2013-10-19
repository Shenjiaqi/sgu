#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 50000
string q[N];
int main()
{
  freopen("in","r",stdin);
  int n;
  map<string,int> mapp;
  cin>>n;
  for(int i=0;i<n;++i)
    {
      cin>>q[i];
      mapp[q[i]]=i;
    }
  int la=-1,ma=-1;
  for(int i=0;i<n;++i)
    {
      string tmp;
      cin>>tmp;
      ma=max(mapp[tmp],ma);
      if(ma<=i)
	{
	  sort(q+la+1,q+ma+1);
	  la=ma;
	}
    }
  for(int i=0;i<n;++i)
    cout<<q[i]<<endl;
  return 0;
}
