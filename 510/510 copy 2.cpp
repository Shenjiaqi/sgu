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
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 25
#define M 30
int p[N+1][N*(N+1)/2+1];
int fa[M];
char ch[M];
char ans[M];
int que(int v)
{
  return v==fa[v]?v:fa[v]=que(fa[v]);
}
void join(int a,int b)
{
  //cout<<"@"<<a<<' '<<b<<endl;
  a=que(a),b=que(b);
  if(a!=b)
    fa[a]=b;
}
void bt(int l,int num,int a,int b,int s)
{
  cout<<"!"<<l<<' '<<num<<endl;
  if(l==0 && num==0)
    return;
  int sh=p[l][num]>>2;
  cout<<sh<<' '<<a<<endl;
  if(sh)
    {
      for(int i=0;i<sh;++i)
	join(a+i,s+i);
      bt(l-sh,num-(l-sh)*sh,b,a,s+sh);
    }
  else bt(l-1,num-l,a,b,s+1);
}
bool dfs(int l,int num)
{
  if(0==(p[l][num]&1))
    {
      int tmp=1;
      for(int i=l;i>0;--i)
	if(num>=(l-i)*i && dfs(l-i,num-(l-i)*i))
	  {
	    tmp|=2;
	    tmp|=i<<2;
	    break;
	  }
      if((tmp&2)==0 && l>0 && num>=l && dfs(l-1,num-l))
	tmp|=2;
      p[l][num]=tmp;
      if(tmp&2)
	cout<<l<<' '<<num<<endl;
    }
  return p[l][num]&2;
}
int main()
{
  int n;
  scanf("%d",&n);
  p[0][0]=3;
  int len=1;
  for(len=1;;++len)
    if(len*(len+1)/2>=n)
      for(int i=len-1;i>=0;--i)
	{
	  if(n==len)
	    {
	      FOR(j,0,len)
		printf("a");
	      return 0;
	    }
	  if(n-len>=(len-1-i)*(i+1) && len>=i+1+1 && dfs(len-i-1-1,n-len-(len-1-i)*(i+1)))
	    {
	      cout<<i<<endl;
	      //cout<<"!"<<len<<' '<<len-2<<' '<<n-len-(len-1-i)*(i+1)<<endl;
	      FOR(j,0,len)
		fa[j]=j;
	      //cout<<"#"<<i<<endl;
	      FOR(j,0,i)
		join(j,j+1);
	      bt(len-i-1-1,n-len-(len-1-i)*(i+1),0,i+1,i+2);
	      char cnt='a';
	      FOR(j,0,len)
		{
		  if(ch[que(j)]==0)
		    ch[que(j)]=cnt++;
		  printf("%c",ch[que(j)]);
		}
	      return 0;
	    }
	}
  return 0;
}
