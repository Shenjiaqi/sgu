#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const string tmp[]={"R1","R2","R4","R8","R16","R32","R64"};
const string gr()
{
  return tmp[rand()%(sizeof(tmp)/sizeof(tmp[0]))];
}
int main()
{
  int n=7;
  int k=6;
  srand(n);
  cout<<gr();
  for(int i=1;i<n;++i)
    {
      cout<<gr();
    }
  return 0;
}
