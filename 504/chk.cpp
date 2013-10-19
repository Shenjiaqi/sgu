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
using namespace std;
typedef long long ll;
#define N 700
char p[N][N+1];
int h,w;
bool ispa(int i,int a,int b)
{
  for(;a<b;++a,--b)
    if(p[i][a]!=p[i][b])
      return false;
  return true;
}
bool ispb(int j,int a,int b)
{
  for(;a<b;++a,--b)
    if(p[a][j]!=p[b][j])
      return false;
  return true;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&h,&w);
  for(int i=0;i<h;++i)
    scanf("%s",*(p+i));
  int ans=0;
  int rc[4];
  for(int i=0;i<h;++i)
    for(int j=0;j<w;++j)
      for(int t=ans;i+t<h && j+t<w;++t)
	{
	  int ii=i;
	  for(;ii<=i+t && ispa(ii,j,j+t);++ii)
	    ;
	  if(ii>i+t)
	    {
	      ii=j;
	      for(;ii<=j+t && ispb(ii,i,i+t);++ii)
		;
	      if(ii>j+t)
		ans=t,rc[0]=i,rc[1]=j,rc[2]=i+t,rc[3]=j+t;
	    }
	}
  for(int i=0;i<4;++i)
    cout<<(1+rc[i])<<' ';
  cout<<endl;
  return 0;
}
