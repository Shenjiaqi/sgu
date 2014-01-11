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
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 3007
int n,t;
ld ans[N];
float pb[N];
int main()
{
  scanf("%d%d",&n,&t);
  FOR(i,0,n)
    scanf("%f",pb+i);
  ans[n]=0;
  for(int i=n-1;i>=0;--i)
    {
      ld mul=1.0;
      ld sum=pb[i]/((ld)1.0-pb[i]);
      ld pre=pb[i]*(ld)t/((ld)1.0-pb[i]);
      ld minv=sum*(ld)2.0+pre+(ans[i+1]+(ld)1.0+t);
      for(int j=i+1;j<n;++j)
	{
	  sum+=mul*pb[j];
	  pre+=mul*pb[j]*((ld)t-(j-i)+ans[j]);
	  mul*=((ld)1.0-pb[j]);
	  ld tmp=sum*2.0*(j-i+(ld)1.0)+pre+mul*(ans[j+1]+j-i+(ld)1.0+t);
	  minv=min(minv,tmp);
	}
      ans[i]=minv;
    }
  printf("%.13lf",(double)ans[0]);
  return 0;
}
