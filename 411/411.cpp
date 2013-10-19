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
#define N 2000
char buf[2][N+1];
int n[2];
struct zz{int a[26];};
vector< zz > v[2];
int vi[2];
char tmp[N+1];
char res[N+1];
void add(int t,char * s,int num)
{
  //cout<<num<<endl;
  for(int i=0,j=0;i<num;++i)
    {
      int z=s[i]-'a';
      if(v[t][j].a[z])
	j=v[t][j].a[z];
      else
	{
	  int lt=v[t].size();
	  v[t].resize(lt+1);
	  for(int k=0;k<26;++k)
	    v[t][lt].a[k]=0;
	  v[t][j].a[z]=lt,j=lt;
	}
    }
}
int ge(int t,char *s,int num)
{
  int r(0);
  for(int i=0,j=0;i<num;++i,++r)
    {
      int z=s[i]-'a';
      if(v[t][j].a[z])
	j=v[t][j].a[z];
      else break;
    }
  return r;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%s\n%s",buf[0],buf[1]);
  n[0]=strlen(buf[0]);
  n[1]=strlen(buf[1]);
  int ans(0);
  for(int i=0;i<2;++i)
    {
      v[i].resize(1);
      for(int j=0;j<26;++j)
	v[i][0].a[j]=0;
    }
  for(int i=0;i<2;++i)
    {
      for(int j=0;j<n[i];++j)
	{
	  if(i==1 && (n[1]-j)*2-1<=ans)
	    break;
	  int k=0;
	  for(;j-k>=0 && j+k+1<n[i] && buf[i][j-k]==buf[i][j+k+1];++k)
	    ;
	  memcpy(tmp,buf[i]+j+1,k);
	  if(i==0)
	    add(0,tmp,k);
	  else if(ans<2*k)
	    {
	      int t=ge(0,tmp,k);
	      if(2*t>ans)
		ans=2*t,memcpy(res,tmp,t),res[t]='\0';
	    }
	  for(k=0;j-k-1>=0 && j+k+1<n[i] && buf[i][j-k-1]==buf[i][j+k+1];++k)
	    ;
	  memcpy(tmp,buf[i]+j,k+1);
	  if(i==0)
	    add(1,tmp,k+1);
	  else if(ans<2*k+1)
	    {
	      int t=ge(1,tmp,k+1);
	      if(2*t-1>ans)
		ans=2*t-1,memcpy(res,tmp,t),res[t]='\0';
	    }
	}
    }
  if(ans&1)
    {
      for(int i=ans/2;i>0;--i)
	printf("%c",res[i]);
      printf("%s",res);
    }
  else
    {
      for(int i=ans/2-1;i>=0;--i)
	printf("%c",res[i]);
      printf("%s",res);
    }
  return 0;
}
