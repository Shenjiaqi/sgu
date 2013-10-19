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
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
const ll base=1e9;
int ans[10003],ansi;
void pt(vector<int> &v)
{
  int i=v.size()-1;
  if(i<0)
    printf("0");
  else
    {
      printf("%d",v[i]);
      for(--i;i>=0;--i)
	printf("%09d",v[i]);
    }
  printf("\n");
}
int cmp(vector<int> &a,vector<int> &b)
{
  int la=a.size();
  int lb=b.size();
  if(la!=lb)
    return la-lb;
  for(int i=la-1;i>=0;--i)
    if(a[i]!=b[i])
      return a[i]-b[i];
  return 0;
}
void mul(vector<int> &r,vector<int> &a,ll v)
{
  r.clear();
  for(int i=0;i<a.size();++i)
    {
      ll tmp=(ll)a[i]*v;
      if(r.size()<=i)
	r.resize(i+1);
      tmp+=r[i];
      r[i]=tmp%base;
      if(tmp>=base)
	{
	  if(r.size()<=i+1)
	    r.resize(i+2);
	  r[i+1]+=tmp/base;
	}
    }
}
int div(vector<int> &a,vector<int> &b,int m)
{
  int r(0);
  vector<int>tmp;
  for(int f=0,l=m+1;f<=l;)
    {
      int mid=(f+l)>>1;
      mul(tmp,b,mid);
      int c=cmp(a,tmp);
      if(c>0)
	r=mid,f=mid+1;
      else if(c==0)
	return mid;
      else l=mid-1;
    }
  return r;
}
void sub(vector<int> &a,vector<int> &b)
{
  for(int i=0;i<a.size();++i)
    {
      if(i<b.size())
	a[i]-=b[i];
      if(a[i]<0)
	--a[i+1],a[i]+=base;
    }
  for(;a.size()>1 && a[a.size()-1]==0;)
    a.resize(a.size()-1);
}
void dfs(vector<int> &a,int b,int l,vector<int> &bb)
{
  vector<int> tmp;
  if(cmp(a,bb)>0)
    {
      mul(tmp,bb,b);
      dfs(a,b,l+1,tmp);
    }
  int c=div(a,bb,b);
  ans[l]=c;
  mul(tmp,bb,c);
  sub(a,tmp);
}
int main()
{
  freopen("in","r",stdin);
  int b;
  char tmp[3001];
  scanf("%s\n%d",tmp,&b);
  if(b==1)
    {
      printf("%s",tmp);
      return 0;
    }
  vector<int> a;
  for(int i=strlen(tmp);i>0;i-=9)
    {
      int j=0;
      for(int k=max(i-9,0);k<i;++k)
	j=j*10+(tmp[k]-'0');
      a.push_back(j);
    }
  vector<int> bb;
  bb.push_back(1);
  dfs(a,b,0,bb);
  int po,neg;
  po=neg=0;
  for(int i=10000;i>=0;--i)
    {
      int tpo=min(po,neg)+ans[i];
      int tneg=min(po+1,neg+(b==ans[i+1]?1:-1))+b-ans[i];
      po=tpo,neg=tneg;
    }
  //cout<<po<<' '<<neg<<endl;
  printf("%d",min(po,neg));
  return 0;
}
