#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int main()
{
  int n,m;
  n=25,m=25;
  freopen("in","w",stdout);
  cout<<n<<' '<<m<<endl;
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	cout<<(rand()%77777>1?'*':'.');
      cout<<endl;
    }
  return 0;
}
