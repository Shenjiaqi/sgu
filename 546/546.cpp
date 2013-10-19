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
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
char s[202];
void tr(int a,int b,int n)
{
  for(int i=0;n>0;++i)
    if(s[i]-'0'==a)
      s[i]='0'+b,--n;
}
int main()
{
  freopen("in","r",stdin);
  int n,a,b;
  scanf("%d%d%d\n%s",&n,&a,&b,s);
  if(a+b>n)
    printf("-1");
  else
    {
      int v[3]={0};
      for(int i=0;i<n;++i)
	++v[s[i]-'0'];
      int t(0);
      if(v[0]<=a)
	{
	  if(v[1]<=b)
	    {
	      tr(2,0,a-v[0]);
	      t+=a-v[0];
	      tr(2,1,b-v[1]);
	      t+=b-v[1];
	    }
	  else
	    {
	      int tmp=min(v[1]-b,a-v[0]);
	      tr(1,0,tmp);
	      t+=tmp;
	      tr(2,0,a-v[0]-tmp);
	      t+=a-v[0]-tmp;
	      tr(1,2,v[1]-b-tmp);
	      t+=v[1]-b-tmp;
	    }
	}
      else
	{
	  if(v[1]<=b)
	    {
	      int tmp=min(v[0]-a,b-v[1]);
	      t+=tmp;
	      tr(0,1,tmp);
	      t+=v[0]-a-tmp;
	      tr(0,2,v[0]-a-tmp);
	      t+=b-v[1]-tmp;
	      tr(2,1,b-v[1]-tmp);
	    }
	  else
	    {
	      tr(0,2,v[0]-a);
	      t+=v[0]-a;
	      tr(1,2,v[1]-b);
	      t+=v[1]-b;
	    }
	}
      printf("%d\n%s",t,s);
    }
  return 0;
}
