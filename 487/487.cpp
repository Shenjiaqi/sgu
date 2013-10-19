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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 1000
int p[N*4+1][3],s[N],poi;
vector<int> ans;
bool vis[N];
int num;
void add(int f,int t)
{
  int tmp=(f-1)>>2;
  ++poi,p[poi][0]=t,p[poi][1]=s[tmp],s[tmp]=poi,p[poi][2]=f;
}
void elr(int v)
{
  if(!vis[v])
    ++num,vis[v]=true;
  for(int i=s[v],pre=0;i;i=p[i][1])
    if(p[i][0]>0)
      {
	p[i][0]=-p[i][0];
	int tmp=i+((i&1)?1:-1);
	p[tmp][0]=-p[tmp][0];
	elr((-1-p[i][0])>>2);
      }
  ans.push_back(v);
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0,f,t;i<2*n;++i)
    {
      scanf("%d%d",&f,&t);
      add(f,t);
      add(t,f);
    }
  elr(0);
  if(num<n)
    printf("No");
  else
    {
      printf("Yes\n");
      for(int i=ans.size()-1;i>0;--i)
	{
	  int l=s[ans[i]];
	  for(;l;l=p[l][1])
	    if(p[l][0]<=0 && ((-p[l][0]-1)>>2)==ans[i-1])
	      {
		printf("%d %d ",p[l][2],-p[l][0]);
		p[l][0]=1;
		p[l+((l&1)?1:-1)][0]=1;
		break;
	      }
	  //if(l==0)
	  //printf("!");
	}
      
    }
  return 0;
}
