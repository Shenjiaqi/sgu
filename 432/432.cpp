#include <cstdio>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define N 1027
char p[N];
vector<string> q[N];
const char * t1[]={"can","may","must","should"};
const char * t2[]={"is","are"};
const char * th[]={"a","the"};
char t[N],tmp[N];
int is(const char *z)
{
  for(int i=0;z[i];++i)
    {
      if(z[i]>='A' && z[i]<='Z')
	t[i]=z[i]+'a'-'A';
      else t[i]=z[i];
      t[i+1]=0;
    }
  for(int i=0;i<sizeof(t1)/sizeof(t1[0]);++i)
    if(strcmp(t,t1[i])==0)
      return 1;
  for(int i=0;i<sizeof(t2)/sizeof(t2[0]);++i)
    if(strcmp(t,t2[i])==0)
      return 2;
  return 0;
}
bool is_the(const char *z)
{
  for(int i=0;z[i];++i)
    {
      t[i]=z[i];
      if(t[i]<='Z' && t[i]>='A')
  	t[i]+=('a'-'A');
      t[i+1]=0;
    }
  for(int i=0;i<sizeof(th)/sizeof(th[0]);++i)
    if(strcmp(th[i],t)==0)
      return true;
  return false;
}
int main()
{
  for(int i=0,j;EOF!=(j=getchar());++i)
    if(j=='\n')
      --i;
    else p[i]=j;
  int ans(0);
  int sen(0);
  for(int i=0;p[i];)
    {
      for(;p[i]==' ';++i)
	;
      int ii=i;
      tmp[0]=0;
      for(int j=0;;++j,++i)
	{
	  if(p[i]==' ' || p[i]=='.' || p[i]==0)
	    break;
	  tmp[j]=p[i];
	  tmp[j+1]=0;
	}
      q[sen].push_back(tmp);
      if(p[i]=='.')
	++i,++sen;
      // cout<<tmp<<endl;
      if(is(tmp))
	++ans;
    }
  printf("%d\n",ans);
  for(int i=0;i<sen;++i)
    {
      // cout<<i<<' '<<j<<endl;
      for(int k=0;k<q[i].size();++k)
	{
	  int type;
	  if(type=is(q[i][k].c_str()))
	    {
	      int l;
	      for(l=0;l<=k;++l)
		printf("%s ",q[i][l].c_str());
	      printf("%s",type==1?"not":"no");
	      if(l<q[i].size() && type==2 && is_the(q[i][l].c_str()))
		++l;
	      for(;l<q[i].size();++l)
		printf(" %s",q[i][l].c_str());
	      printf(".\n");
	    }
	}
    }
  return 0;
}
