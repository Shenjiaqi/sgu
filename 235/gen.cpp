#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<ld,ld> ppld;
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 307
char p[N][N];
int main()
{
  int n=300;
  int m=50;
  cout<<n<<endl<<m<<endl;
  srand(time(NULL));
  FOR(i,0,n)
    FOR(j,0,n)
    {
      int t=rand()%100;
      if(t>50)
	p[i][j]='.';
      else if(t>20)
	p[i][j]='B';
      else p[i][j]='W';
    }
  p[rand()%n][rand()%n]='Q';
  FOR(i,0,n)
    printf("%s\n",p[i]);
  return 0;
}
