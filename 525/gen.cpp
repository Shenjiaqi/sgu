#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
  freopen("in.txt","w",stdout);
  int n,m;
  n=1000,m=20000;
  cout<<n<<' '<<m<<endl;
  srand(10);
  for(int i=0;i<m;++i)
    {
      int a=1+(rand()%n);
      int b=(rand()%(n))+1;
      cout<<a<<' '<<b<<endl;
    }
  return 0;
}
