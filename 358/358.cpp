#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  vector<int> a,b;
  for(int i=0;i<3;++i)
    {
      for(int j=0;j<3;++j)
	{
	  int t;
	  cin>>t;
	  a.push_back(t);
	}
      sort(a.begin(),a.end());
      b.push_back(a[1]);
      a.clear();
    }
  sort(b.begin(),b.end());
  cout<<b[1];
  return 0;
}
