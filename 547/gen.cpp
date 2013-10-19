#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 200
int fa[N+1];
int que(int i)
{
  return (i==fa[i]?i:fa[i]=que(fa[i]));
}
int join(int a,int b)
{
  a=que(a);
  b=que(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in","w",stdout);
  srand(time(NULL));
  int n=200;
  cout<<n<<endl;
  int d1=(rand()%(int)(n/3));
  int c1=(rand()%(n))+1;
  int d2=(rand()%(n/3));
  int c2=rand()%n+1;
  cout<<d1<<' '<<c1<<' '<<d2<<' '<<c2<<endl;
  for(int i=0;i<n;++i)
    cout<<(1+(rand()%1000))<<' ';
  cout<<endl;
  for(int i=0;i<=N;++i)
    fa[i]=i;
  for(int i=1;i<n;)
    {
      int a=(rand()%n)+1;
      int b=(rand()%n)+1;
      if(que(a)!=que(b))
	{
	  cout<<a<<' '<<b<<endl;
	  join(a,b);
	  ++i;
	}
    }
  return 0;
}
