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
#define L 2000
#define K 2000
char buf[L+1];
int k;
char ans[L+1];
void cp(char *a,char *cand,int s,int l,int len)
{
  if(!ans[0])
    for(int i=0;i<l;++i,s=(s+1)%len)
      a[i]=cand[s];
  else
    for(int i=0;i<l;++i,s=(s+1)%len)
      if(a[i]!=cand[s])
	{
	  if(a[i]>cand[s])
	    for(;i<l;++i,s=(s+1)%len)
	      a[i]=cand[s];
	  break;
	}
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d\n%s",&k,buf);
  int l=strlen(buf);
  for(int i=l>>1;i>0;--i)
    {
      int diff(0);
      for(int j=0;j<i;++j)
	if(buf[j]!=buf[j+i])
	  ++diff;
      if(diff<=k)
	memcpy(ans,buf,sizeof(char)*(i<<1));
      for(int j=1;j<l;++j)
	{
	  if(buf[j-1]!=buf[(j-1+i)%l])
	    --diff;
	  if(buf[(j+i-1)%l]!=buf[(j+i+i-1)%l])
	    ++diff;
	  if(diff<=k)
	    cp(ans,buf,j,i<<1,l);
	}
      if(ans[0])
	break;
    }
  printf("%s",ans);
  return 0;
}
