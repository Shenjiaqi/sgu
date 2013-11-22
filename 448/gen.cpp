#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int p[17][17];
int main()
{
  int n=12;
  int m=1;
  freopen("in","w",stdout);
  cout<<n<<' '<<m<<endl;
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<n;++j)
	if(i<j)
	  cout<<1<<' ';
	else cout<<0<<' ';
      cout<<endl;
    }
//   for(int i=0;i<n;++i)
//     for(int j=i+1;j<n;++j)
//       if(i==0)
// 	p[i][j]=1;
//       else
// 	p[i][j]=rand()%2;
//   cout<<n<<' '<<m<<endl;
//   for(int i=0;i<n;++i)
//     {
//       for(int j=0;j<n;++j)
// 	{
// 	  if(i<=j)
// 	    cout<<p[i][j];
// 	  else cout<<1-p[j][i];
// 	  cout<<' ';
// 	}
//       cout<<endl;
//     }
  return 0;
}
