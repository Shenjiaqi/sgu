#include <iostream>
using namespace std;
#define N 100
int score[N];
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;++i)
    {
      int a,b;
      cin>>a>>b;
      for(int j=0;j<n;++j)
	{
	  int c,d;
	  cin>>c>>d;
	  if((a>b && c>d) || (a==b && c==d) || (a<b && c<d))
	    score[j]+=2;
	  if( (a-b) == (c-d) )
	    score[j]+=3;
	  if(a==c)
	    ++score[j];
	  if(b==d)
	    ++score[j];
	}
    }
  for(int i=0;i<n;++i)
    cout<<score[i]<<' ';
  return 0;
}
