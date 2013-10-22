#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in.txt","w",stdout);
  int n=20000;
  cout<<n<<endl;
  ll t=1;
  t<<=59;
  srand(7);
  for(int i=0;i<n;++i)
    {
      ll a=rand();
      ll b=rand();
      a<<=31;
      a|=b;
      //cout<<(a&(t-1))<<endl;
      cout<<"100\n";
    }
  return 0;
}
