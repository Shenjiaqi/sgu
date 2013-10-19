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
int p[10];
int n,m,k;
vector< int > block;
map<vector<int>,int> mapp;
int o[20][20];
void fil(vector<int> &t,int r)
{
  t.clear();
  t.push_back(r);
  for(;r<n && p[r];++r)
    t.push_back(p[r]);
}
void pt(int r,int c,int b)
{
  //cout<<1<<' '<<r<<' '<<c<<' '<<b<<endl;
  int zz[27]={0};
  for(int i=c;i<c+b;++i)
    {
      if(r>0)
	zz[o[r-1][c]]=1;
      if(r+1<n)
	zz[o[r+1][c]]=1;
    }
  if(c+b<m)
    zz[o[r][c+b]]=1;
  if(c>0)
    zz[o[r][c-1]]=1;
  for(int i=1;i<26;++i)
    if(zz[i]==0)
      {
	//cout<<c<<' '<<(c+b)<<(char)(i+'a'-1)<<endl;
	for(int j=c;j<c+b;++j)
	  o[r][j]=i;
	break;
      }
}
void pt2(int r,int c,int b)
{
  //cout<<2<<' '<<r<<' '<<c<<' '<<b<<endl;
  int zz[27]={0};
  for(int i=r;i<r+b;++i)
    {
      if(c>0)
	zz[o[i][c-1]]=1;
      if(c+1<m)
	zz[o[i][c+1]]=1;
    }
  if(r>0)
    zz[o[r-1][c]]=1;
  if(r+b<n)
    zz[o[r+b][c]]=1;
  for(int i=1;i<26;++i)
    if(zz[i]==0)
      {
	for(int j=r;j<r+b;++j)
	  o[j][c]=i;
	break;
      }
}
bool dfs(int r)
{
  for(;r<n && p[r]==((1<<m)-1);++r)
    ;
  if(r>=n)
    return true;
  vector<int> tmp;
  fil(tmp,r);
  if(mapp[tmp])
    return false;
  int z=(~p[r])&((1<<m)-1);
  int cs=__builtin_ctz(z);
  int cn=0;
  for(int i=1<<cs;i&z;i<<=1,++cn)
    ;
  int rn=n-r;
  for(int i=0;i<block.size();++i)
    {
      int b=block[i];
      if(b<=cn)
	{
	  p[r]|=(((1<<b)-1)<<cs);
	  if(dfs(r))
	    {
	      pt(r,cs,b);
	      return true;
	    }
	  fil(tmp,r);
	  mapp[tmp]=1;
	  p[r]^=(((1<<b)-1)<<cs);
	}
      if(b<=rn)
	{
	  for(int j=r;j<r+b;++j)
	    p[j]|=(1<<cs);
	  if(dfs(r))
	    {
	      pt2(r,cs,b);
	      return true;
	    }
	  fil(tmp,r);
	  for(int j=r;j<r+b;++j)
	    p[j]^=(1<<cs);
	}
    }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  cin>>n>>m>>k;
  int brick[5];
  for(int i=0;i<k;++i)
    cin>>brick[i];
  sort(brick,brick+k);
  bool v[1001]={0};
  v[0]=1;
  for(int i=0;i<k;++i)
    if(!v[brick[i]])
      {
	for(int j=0;j<=1000-brick[i];++j)
	  if(v[j])
	    v[j+brick[i]]=true;
      }
    else brick[i]=0;
  for(int i=0;i<k;++i)
    if(brick[i] && brick[i]<=max(n,m))
      block.push_back(brick[i]);
  bool r=false;
  if(n>m)
    n^=m,m^=n,n^=m,r=true;
  for(int i=0;i<20;++i)
    for(int j=0;j<20;++j)
      o[i][j]=26;
  if(dfs(0))
    {
      cout<<"YES";
      if(!r)
	for(int i=0;i<n;++i)
	  {
	    cout<<endl;
	    for(int j=0;j<m;++j)
	      cout<<(char)('a'+o[i][j]-1);
	  }
      else for(int i=0;i<m;++i)
	     {
	       cout<<endl;
	       for(int j=0;j<n;++j)
		 cout<<(char)('a'+o[j][i]-1);
	     }
    }
  else cout<<"NO";
  return 0;
}
