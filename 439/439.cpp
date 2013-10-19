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
#define N 1000001
#define M 1000001
char a[1+N],b[1+M];
int aa[21][N],bb[21][M];
int pa[2][N];
int pb[2][M];
int numa[N];
int numb[N];
bool v['Z'-'A'+1];
int idx[N+1];
int n,m;
int dfs(int b,int a,int c,int z)
{
  //cout<<a<<' '<<b<<' '<<c<<endl;
  if(aa[min(c,z)][a]==bb[c][b])
    return 0;
  if(c==0)
    return 1;
  int tmp=dfs(b,a,c-1,z);
  if(tmp>=2)
    return tmp;
  return (tmp+dfs((b+(1<<(c-1)))%m,(a+(1<<(c-1)))%n,c-1,z));
}
int main()
{
  freopen("in","r",stdin);
  //freopen("out","w",stdout);
  scanf("%d %d\n%s\n%s",&m,&n,b,a);
  for(int i=0;i<n;++i)
    {
      ++numa[a[i]-'A'];
      v[a[i]-'A']=true;
    }
  for(int i=1;i<='Z'-'A';++i)
    numa[i]+=numa[i-1];
  for(int i=n-1;i>=0;--i)
    pa[0][--numa[a[i]-'A']]=i;
  int na=0;
  for(int i=0;i<n;++i)
    {
      if(i && a[pa[0][i]]!=a[pa[0][i-1]])
	++na;
      aa[0][pa[0][i]]=na;
    }
  memset(numa,0,sizeof(int)*('Z'-'A'+1));
  for(int i=0;i<m;++i)
    if(v[b[i]-'A'])
      ++numb[b[i]-'A'];
  for(int i=1;i<='Z'-'A';++i)
    numb[i]+=numb[i-1];
  int kb=numb['Z'-'A'];
  for(int i=m-1;i>=0;--i)
    if(v[b[i]-'A'])
      pb[0][--numb[b[i]-'A']]=i;
  memset(numb,0,sizeof(int)*('Z'-'A'+1));
  int nb=0;
  memset(bb,1<<7,sizeof(bb));
  for(int i=0;i<kb;++i)
    {
      if(i && b[pb[0][i]]!=b[pb[0][i-1]])
	++nb;
      bb[0][pb[0][i]]=nb;
    }
  int ca;
  int z1,z2;
  z1=z2=-1;
  for(int i=1,j=1;j<n;++i,j<<=1)
    {
      int f,t;
      t=i&1,f=1-t;
      if(na<n-1)
	{
	  for(int k=0;k<n;++k)
	    ++numa[aa[i-1][k]];
	  for(int k=1;k<=na;++k)
	    numa[k]+=numa[k-1];
	  for(int k=n-1;k>=0;--k)
	    {
	      int tmp=(pa[f][k]-j+n)%n;
	      pa[t][--numa[aa[i-1][tmp]]]=tmp;
	    }
	  memset(numa,0,sizeof(int)*(1+na));
	  na=0;
	  for(int k=0;k<n;++k)
	    {
	      if(k && (aa[i-1][pa[t][k]]!=aa[i-1][pa[t][k-1]] || aa[i-1][(pa[t][k]+j)%n]!=aa[i-1][(pa[t][k-1]+j)%n]))
		++na;
	      aa[i][pa[t][k]]=na;
	    }
	  z1=i,z2=t;
	  ca=i;
	}
      nb=0;
      for(int k=0;k<kb;++k)
	{
	  int tmp=bb[i-1][(pb[f][k]-j+m)%m];
	  if(tmp>=0)
	    {
	      nb=max(nb,tmp);
	      ++numb[tmp];
	    }
	}
      for(int k=1;k<=nb;++k)
	numb[k]+=numb[k-1];
      int kkb=numb[nb];
      for(int k=kb-1;k>=0;--k)
	{
	  int tmp=bb[i-1][(pb[f][k]-j+m)%m];
	  if(tmp>=0)
	    pb[t][--numb[tmp]]=(pb[f][k]-j+m)%m;
	}
      memset(numb,0,sizeof(int)*(1+nb));
      kb=0;
      int zz1,zz2;
      if(na==n-1)
	zz1=z1,zz2=z2;
      else zz1=i-1,zz2=t;
      for(int k=0,l=0;k<n && l<kkb;)
	{
	  int x1=bb[i-1][pb[t][l]];
	  int x2=aa[zz1][pa[zz2][k]];
	  if(x1<x2)
	    ++l;
	  else if(x2<x1)
	    ++k;
	  else
	    {
	      x1=bb[i-1][(pb[t][l]+j)%m];
	      x2=aa[zz1][(pa[zz2][k]+j)%n];
	      if(x1<x2)
		++l;
	      else if(x1>x2)
		++k;
	      else
		{
		  bb[i][pb[t][l]]=aa[zz1][pa[zz2][k]];
		  pb[t][kb]=pb[t][l];
		  ++l,++kb,++k;
		}
	    }
	}
      if(kb==0 && na==n-1)
	{
	  //cout<<z1<<' '<<z2<<endl;
	  break;
	}
    }
  int poi=pa[(ca&1)][0];
  printf("%s",(a+poi));
  a[poi]='\0';
  printf("%s",a);
  int ans=-1;
  for(int i=0;i<m;++i)
    {
      int ta=(ans<0?m:min(ans,m-ans));
      int tb=min(i,m-i);
      if(ta>tb)
	{
	  int l=0;
	  for(int j=n,k,x=i,y=poi;j && l<2;j-=k)
	    {
	      k=j&(-j);
	      l+=dfs(x,y,__builtin_ctz(k),z1);
	      x=(x+k)%m,y=(y+k)%n;
	    }
	  if(l<2)
	    ans=i;
	  //cout<<l<<' '<<i<<endl;
	}
    }
  printf("\n%s",(b+ans));
  b[ans]='\0';
  printf("%s",b);
  return 0;
}
