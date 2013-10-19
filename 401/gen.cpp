#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  freopen("in","w",stdout);
  int n=50;
  srand(13);
  int w=(rand()%1000)+1;
  int t=(rand()%1000)+1;
  cout<<n<<' '<<w<<' '<<t<<endl;
  for(int i=0;i<n;++i)
    cout<<(1+(rand()%1000))<<' '<<(1+(rand()%1000))<<endl;
  return 0;
}
