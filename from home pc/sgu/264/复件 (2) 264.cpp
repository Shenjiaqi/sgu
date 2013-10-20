#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
#define N 800
typedef pair<int,int> ppi;
char name[N*2][17];
char q[N*2][N][17];
int p[N*2][N*2];
int in[N*2];
int s[N*2];
int op[N*2];
int n;
int gs(int v)
{
  for(;s[v]<n && in[p[v][s[v]]];++s[v])
    ;
  return s[v];
}
void dfs(int v)
{
  int i=gs(v);
  if(i<n)
    {
      int t=p[v][i];
      if(!in[t])
	{
	  op[v]=t;
	  in[v]=in[t]=true;
	  int j=gs(t);
	  if(j<n)
	    dfs(p[t][j]);
	}
    }
}
int main()
{
  scanf("%d",&n);
  map<string,int> mapm,mapf;
  for(int i=0;i<n*2;++i)
    {
      scanf("%s",name+i);
      string tmp(name[i]);
      if(i<n)
	mapm[tmp]=i;
      else mapf[tmp]=i;
      for(int j=0;j<n;++j)
	scanf("%s",*(q+i)+j);
    }
  for(int i=0;i<2*n;++i)
    for(int j=0;j<n;++j)
      {
	string tmp(q[i][j]);
	p[i][j]=(i<n?mapf[tmp]:mapm[tmp]);
      }
  memset(op,1<<7,sizeof(op));
  for(;;)
    {
      bool fg=true;
      for(int i=0;i<n;++i)
	if(!in[i])
	  {
	    int j=gs(i);
	    if(j<n)
	      {
		int t=p[i][j];
		if(!in[t])
		  {
		    int k=gs(t);
		    if(k<n && i==p[t][k])
		      {
			//cout<<i<<' '<<t<<endl;
			fg=false;
			in[i]=in[t]=true;
			op[i]=t;
			//op[t]=i;
		      }
		  }
	      }
	  }
      if(fg)
	break;
    }
  for(int i=0;i<n;++i)
    if(op[i]<0)
      dfs(i);
  printf("YES");
  for(int i=0;i<n;++i)
    printf("\n%s %s",name[i],name[op[i]]);
  return 0;
}
