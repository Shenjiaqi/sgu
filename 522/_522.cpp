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
const int N=407;
int n,x,y;
int p[N][2];
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    ++c,++d;
  return *c-*d;
}
int main()
{
  scanf("%d%d%d",&n,&x,&y);
  FOR(i,0,n)
    scnaf("%d%d",&p[i][0],&p[i][1]);
  int nx,ny,px,py;
  nx=ny=px=py=0;
  FOR(i,0,n)
    {
      p[i][0]-=x,p[i][1]-=y;
      if(p[i][0]<0)
	++nx;
      else if(p[i][0]>0)
	++px;
      if(p[i][1]<0)
	++ny;
      else if(p[i][1]>0)
	++py;
    }
  if((nx&&px)||(ny&&py))
    printf("-1");
  else
    {
      qsort(p,n,sizeof(p[0]),cmp);
      vector<int,ppi> pos;
      for(int i=0;i<n;)
	{
	  int j=i+1;
	  for(;p[i][0]==p[j][0];++j)
	    ;
	  pos.PB(MP(pos[i][0],MP(p[i][1],p[j-1][1])));
	}
      for(int i=pos.size()-2;i>=0;--i)
	pos[i].SEC.FIR=min(pos[i].SEC.FIR,pos[i+1].SEC.FIR);
      
    }
  return 0;
}
