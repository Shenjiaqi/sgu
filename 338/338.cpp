#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const ld eps=1e-11;
ld p[23][30];
ld wc[23];
bool stb[23];
ld wb[23];
ld pb[23];
ld wca[23][23];
ld eba[23][23][23];
ld pba[23][23][23];
bool stc[23][23][23];
ld ea[23][23];
bool sa[23][23];
ld pa[23][23];
int main()
{
  for(int i=0;i<22;++i)
    {
      p[i][0]=1;
      for(int j=1;j<30;++j)
	{
	  p[i][j]=0;
	  for(int k=max(j-6,0);k<min(i+1,j);++k)
	    p[i][j]+=p[i][k];
	  p[i][j]/=6;
	}
    }
  for(int i=21;i>21-6;--i)
    {
      wc[i]=0;
      for(int j=i;j<=21;++j)
	wc[i]+=p[i-1][j];
      wc[22]=1;
    }
  for(int i=21;i>21-6;--i)
    {
      ld w=1.0-wc[i];
      wb[i]=0;
      for(int j=i+1;j<=21;++j)
	wb[i]+=wb[j];
      wb[i]/=6;
      pb[i]=p[21-6][i];
      if(wb[i]>=w-eps)
	stb[i]=false;
      else
	{
	  stb[i]=true;
	  wb[i]=w;
	}
    }
  for(int i=21-5;i<=21;++i)
    if(!stb[i])
      {
	for(int j=i+1;j<=21;++j)
	  pb[j]+=pb[i]/6.0;
	pb[i]=0;
      }
  stb[22]=true;
  for(int i=21;stb[i];--i)
    pb[22]+=pb[i];
  pb[22]=1-pb[22];
  int x;
  scanf("%d",&x);
  for(int i=19;i<=22;++i)
    for(int j=21-5;j<=22;++j)
      {
	int l=min(i,j);
	if(l==22)
	  {
	    for(int k=21-5;k<=21;++k)
	      {
		stc[i][j][k]=true;
		eba[i][j][k]=1;
		pba[i][j][k]=p[21-6][k];
	      }
	    continue;
	  }
	for(int k=21;k>=l;--k)
	  {
	    pba[i][j][k]=p[l-1][k];
	    ld e1=((i==22 || k>=i)?x:-x)+((j==22 || k>=j)?1:-1);
	    ld e2=0;
	    for(int o=1;o<=6;++o)
	      {
		if(o+k<=21)
		  e2+=eba[i][j][o+k]/6.0;
		else e2+=-(ld)(1+x)/6.0;
	      }
	    if(e2>=e1-eps)
	      {
		stc[i][j][k]=false;
		eba[i][j][k]=e2;
	      }
	    else
	      {
		stc[i][j][k]=true;
		eba[i][j][k]=e1;
	      }
	  }
	for(int k=l;k<=21;++k)
	  if(!stc[i][j][k])
	    {
	      for(int o=k+1;o<=21;++o)
		pba[i][j][o]+=pba[i][j][k]/6.0;
	      pba[i][j][k]=0;
	    }
	stc[i][j][22]=true;
	for(int k=21;stc[i][j][k];--k)
	  pba[i][j][22]+=pba[i][j][k];
	pba[i][j][22]=1-pba[i][j][22];
      }
  // for(int i=19;i<=21;++i)
  //   cout<<i<<' '<<pba[19][19][i]<<' '<<pba[20][19][i]<<endl;
  for(int i=19;i<=22;++i)
    {
      for(int j=21;j>21-6;--j)
	{
	  ld s1=0;
	  for(int k=j;k<=21;++k)
	    s1+=pba[i][j][k];
	  s1=1.0-s1;
	  ld s2=0;
	  for(int k=j+1;k<=21;++k)
	    s2+=ea[i][k]/6.0;
	  pa[i][j]=p[21-6][j];
	  if(s2>=s1-eps)
	    {
	      sa[i][j]=false;
	      ea[i][j]=s2;
	    }
	  else
	    {
	      sa[i][j]=true;
	      ea[i][j]=s1;
	    }
	}
      for(int j=21-5;j<=21;++j)
	if(!sa[i][j])
	  {
	    for(int k=j+1;k<=21;++k)
	      pa[i][k]+=pa[i][j]/6.0;
	    pa[i][j]=0;
	  }
    }
  ld ans=0;
  for(int i=19;i<=22;++i)
    for(int j=21-5;j<=21;++j)
      if(sa[i][j])
	{
	  ans+=pb[i]*pa[i][j]*ea[i][j];
	}
  printf("%.11lf\n",(double)ans);
  return 0;
}
