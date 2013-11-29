#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 307
#define M 307
char p[N][M];
int main()
{
  int n,m;
  n=30,m=30;
  cout<<n<<' '<<m<<endl;;
  srand(time(NULL));
  for(int i=0;i<7;++i)
    {
      if(i)
	cout<<' ';
      cout<<(1+(rand()%10000));
    }
  cout<<endl;
  const char c[]={'P','R','K','B','Q','M','.','#','.','R','R','K','K','K','K','K','K','K','K','.','.','.','.','.','.','.','.','.','.'};
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      p[i][j]=c[rand()%(int)(sizeof(c)/sizeof(c[0]))];
  p[3][3]='@';
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	cout<<p[i][j];
      cout<<endl;
    }
  return 0;
}
