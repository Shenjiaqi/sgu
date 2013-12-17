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
const int N=400;
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
    scanf("%d%d",&p[i][0],&p[i][1]);
  int px,nx,py,ny;
  px=nx=py=ny=0;
  FOR(i,0,n)
    {
      p[i][0]-=x,p[i][1]-=y;
      if(p[i][0]>0)
	++px;
      else if(p[i][0]<0)
	++nx;
      if(p[i][1]>0)
	++py;
      else if(p[i][1]<0)
	++ny;
    }
  if((px && nx ) || (py&&ny))
    printf("-1");
  else
    {
      FOR(i,0,n)
	{
	  p[i][0]=abs(p[i][0]);
	  p[i][1]=abs(p[i][1]);
	}
      int area;
      vector<char> ans;
      qsort(p,n,sizeof(p[0]),cmp);
      vector<pair<int,ppi> > pos;
      for(int i=0;i<n;)
	{
	  int j=i+1;
	  for(;j<n && p[i][0]==p[j][0];++j)
	    ;
	  pos.PB(MP(p[i][0],ppi(p[i][1],p[j-1][1])));
	  i=j;
	}
      int nowX,nowY;
      nowX=nowY=0;
      nowY=1;
      ans.PB('W');
      for(i,0,pos.size())
	{
	  for(;nowX<pos[i].FIR-1;++nowX)
	    ans.PB('E'),hi[nowX]=nowY;
	  for(;nowY<pos[i].SEC.SEC;++nowY)
	    ans.PB('W');
	  for(;nowX<pos[i].FIR;++nowX)
	    ans.PB('E'),hi[nowX]=nowY;
	}
      if(nowX<1)
	ans.PB('E'),hi[nowX++]=nowY;
      for(int i=pos.size()-1;i>=0;--i)
	{
	  for(;nowY>pos[i].SEC.FIR;--nowY)
	    ans.PB('S');
	  for(;nowX>(i>0?p[i-1].FIR:0);--nowX)
	    {
	      for(;hi[nowX]<=nowY;--nowY)
		ans.PB('S');
	      ans.PB('W');
	      area+=(hi[nowX-1]-nowY);
	    }
	}

      printf("%d\n",area);
      FR(i,ans)
	{
	  if(*i=='W' || *i=='E')
	    {
	      if(nx)
		printf("%c",*i=='W'?'E':'W');
	      else printf("%c",*i);
	    }
	  else if(ny)
	    printf("%c",*i=='N'?'S':'N');
	  else printf("%c",*i);
	}
    }
  return 0;
}
