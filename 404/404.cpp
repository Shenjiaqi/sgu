#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int k=((n%m)-1+m)%m;
  string ans;
  for(int i=0;i<=k;++i)
    cin>>ans;
  cout<<ans;
  return 0;
}
