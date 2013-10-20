#include <cstdio>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
typedef long long ll;
void df(ll v,int l,int lim)
{
  if(l<lim)
    {
      df(v/10,l+1,lim);
      printf("%c",('A'+(char)(v%10)));
      if(l==6)
	printf("+");
      else if(l==3)
	printf("=");
    }
  else printf("\n");
}
int main()
{
  freopen("out.txt","w",stdout);
  map<ll,int> mapp;
  for(int i=100;i<1000;++i)
    {
      int tt[10]={0},tti=0;
      ll z=1;
      for(int j=i;j;j/=10)
	{
	  if(tt[j%10]==0)
	    tt[j%10]=++tti;
	  z=z*10+tt[j%10]-1;
	}
      for(int j=100;j<1000-i;++j)
	{
	  ll zz=z;
	  int tmp[10]={0};
	  int ti=tti;
	  memcpy(tmp,tt,sizeof(tmp));
	  for(int k=j;k;k/=10)
	    {
	      if(tmp[k%10]==0)
		tmp[k%10]=++ti;
	      zz=zz*10+tmp[k%10]-1;
	    }
	  for(int l=i+j;l;l/=10)
	    {
	      if(tmp[l%10]==0)
		tmp[l%10]=++ti;
	      zz=zz*10+tmp[l%10]-1;
	    }
	  ++mapp[zz];
	}
    }
  int count=0;
  for(map<ll,int>::iterator ite=mapp.begin();ite!=mapp.end();++ite)
    if(ite->second==1)
      {
	df(ite->first,0,9);
	++count;
	if(count>2000)
	  break;
      }
  cout<<count<<endl;
  return 0;
}
