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
int p[N+1][N*(N+1)/2+1][2];
int fa[M];
char ch[M];
char ans[M];
int q[M][2];
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
// void bt(int l,int num,int a,int b,int s)
// {
//   cout<<"!"<<l<<' '<<num<<endl;
//   if(l==0 && num==0)
//     return;
//   int sh=p[l][num]>>2;
//   cout<<sh<<' '<<a<<endl;
//   if(sh)
//     {
//       for(int i=0;i<sh;++i)
// 	join(a+i,s+i);
//       bt(l-sh,num-(l-sh)*sh,b,a,s+sh);
//     }
//   else bt(l-1,num-l,a,b,s+1);
// }
int dfs(int l,int num,int lim,int lev)
{
  //cout<<l<<' '<<num<<' '<<lim<<' '<<lev<<endl;
  q[lev][0]=q[lev][1]=l;
  if(l<=lim && num==0)
    return lev+1;
  if(p[l][num][1]!=lim)
    {
      p[l][num][1]=lim;
      int r;
      for(int i=l-1;i>=0;--i)
	if(num>=(l-i)*(i+1) && (r=dfs(l-i-1,num-(l-i)*(i+1),lim,lev+1)))
	  {
	    q[lev][1]=i;
	    p[l][num][0]=i+1;
	    return r;
	  }
      for(int i=l-1;i>=0;--i)
	if(num>=(l-i)*i && lev>0 && num-(l-i)*i==0 && l-i<=lim)
	  {
	    q[lev][1]=i;
	    p[l][num][0]=i+1;
	    return dfs(l-i,0,lim,lev+1);
	  }
    }
  return p[l][num][0];
}
int main()
{
  int n;
  scanf("%d",&n);
  int len=1;
  int r;
  for(len=1;;++len)
    if(len*(len+1)/2>=n)
      {
	if(r=dfs(len-1,n-len,len,0))
	  {
	    // cout<<len<<endl;
	    // FOR(j,0,r)
	    //   cout<<q[j][0]<<' '<<q[j][1]<<endl;
	    FOR(j,0,len)
	      fa[j]=j;
	    if(r>1 && q[r-1][0])
	      {
		FOR(j,0,max(1,r-2))
		  {
		    FOR(k,0,q[j][1])
		      join(k,k+len-q[j][0]);
		  }
		if(r>2)
		  FOR(j,0,q[r-2][1])
		    {
		      join(len-q[0][0]+q[0][1]+j,len-q[r-2][0]+j);
		      //cout<<len-q[0][0]+q[0][1]+j<<' '<<len-q[r-2][0]+j<<'!'<<endl;
		    }
		FOR(j,0,q[r-1][1])
		  {
		    join(j,len-q[r-1][0]+j);
		    // cout<<"!"<<j<<' '<<len-q[r-1][0]+j<<endl;
		  }
	      }
	    else
	      {
		FOR(j,0,r)
		  FOR(k,0,q[j][1])
		  join(k,len-q[j][0]+k);
	      }
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
