#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
#define N 801
typedef pair<int,int> ppi;
char name[N*2][17];
char q[N*2][N][17];
int p[N*2][N*2];
int pp[N*2][N*2];
int in[N*2];
int s[N*2];
int op[N*2];
int n;
void dfs(int v)
{
  for(;s[v]<n && op[p[v][s[v]]]>=0;++s[v])
    {
      int t=p[v][s[v]];
      int c=op[t];
      if(pp[t][v]<pp[t][c])
	{
	  op[t]=v;
	  ++s[v];
	  dfs(c);
	  return ;
	}
    }
  op[p[v][s[v]]]=v;
  ++s[v];
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
	pp[i][p[i][j]]=j;
      }
  memset(op,1<<7,sizeof(op));
  for(int i=0;i<n;++i)
    dfs(i);
  printf("YES");
  for(int i=n;i<2*n;++i)
    printf("\n%s %s",name[op[i]],name[i]);
  return 0;
}
