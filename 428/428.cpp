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
void df(ll v,int l)
{
  if(l)
    {
      df(v/10,l-1);
      printf("%c",('A'+(char)(v%10)));
      if(l==4)
	printf("+");
      else if(l==8)
	printf("=");
    }
  else printf("\n");
}
void cal(ll &v,int i,int tmp[],int &ti)
{
  int z[10],zi=0;
  for(;i;i/=10)
    z[zi++]=i%10;
  for(int j=zi-1;j>=0;--j)
    {
      if(tmp[z[j]]==0)
	tmp[z[j]]=++ti;
      v=v*10+tmp[z[j]]-1;
    }
}
int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  map<ll,int> mapp;
  for(int i=1000;i<10000;++i)
    {
      int tmp1[10]={0};
      int t1=0;
      ll z1=1;
      cal(z1,i,tmp1,t1);
      for(int j=1000;j<10000-i;++j)
	{
	  int tmp2[10];
	  memcpy(tmp2,tmp1,sizeof(tmp2));
	  int t2=t1;
	  ll z2=z1;
	  cal(z2,j,tmp2,t2);
	  cal(z2,i+j,tmp2,t2);
	  ++mapp[z2];
	}
    }
  int count(0);
  for(map<ll,int>::iterator ite=mapp.begin();ite!=mapp.end();++ite)
    {
      if(ite->second==1)
	{
	  //df(ite->first,12);
	  cout<<ite->first<<',';
	  if(count%10==0 && count)
	    cout<<'\n';
	  ++count;
	  if(count>=1000)
	    break;
	}
    }
  cout<<"\n"<<count;
  return 0;
}
