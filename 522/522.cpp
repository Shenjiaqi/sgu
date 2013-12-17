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

      vector<ppi> pos;
      FOR(i,0,n)
	pos.PB(MP(p[i][0],p[i][1]));
      // cout<<pos.size()<<endl;
      // FR(i,pos)
      // 	cout<<i->FIR<<' '<<i->SEC<<endl;
      pos.PB(MP(0,1));
      pos.PB(MP(1,0));
      pos.PB(MP(1,1));
      sort(pos.begin(),pos.end());
      int nowX,nowY;
      nowX=nowY=0;
      int lx=pos[pos.size()-1].FIR;
      vector<int> hi;
      for(int i=0;nowX<lx;)
	{
	  if(nowX==pos[i].FIR)
	    {
	      nowY=max(nowY,pos[i].SEC);
	      ++i;
	    }
	  else
	    {
	      hi.PB(nowY);
	      ++nowX;
	    }
	}
      // FR(i,pos)
      // 	cout<<i->FIR<<' '<<i->SEC<<endl;
      int c=hi.size()-1;
      hi[c]=max(hi[c],pos[pos.size()-1].SEC);
      vector<int> lw;
      nowX=lx,nowY=1e9;
      for(int i=pos.size()-1;nowX>0;)
	{
	  if(i>=0 && nowX==pos[i].FIR)
	    {
	      nowY=min(pos[i].SEC,nowY);
	      --i;
	    }
	  else
	    {
	      nowY=min(nowY,min(nowX>1?hi[nowX-2]-1:0,hi[nowX-1]-1));
	      lw.PB(nowY);
	      --nowX;
	    }
	}
      reverse(lw.begin(),lw.end());
      // cout<<hi.size()<<' '<<lw.size()<<endl;
      assert(hi.size()==lw.size());

      int area=0;
      FOR(i,0,hi.size())
	area+=hi[i]-lw[i];
      printf("%d\n",area);
      vector<char> ans;
      nowX=nowY=0;
      FR(i,hi)
	{
	  for(;nowY<*i;++nowY)
	    ans.PB('N');
	  ans.PB('E');
	  ++nowX;
	}
      for(int i=lw.size()-1;i>=0;--i)
	{
	  for(;nowY>lw[i];--nowY)
	    ans.PB('S');
	  ans.PB('W');
	  --nowX;
	}
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
