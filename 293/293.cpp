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
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
#define N 2005
char p[2*N];
char q[2*N];
int qc[255];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  char tmp,tmp2;
  scanf("\n%c",&tmp);
  p[0]=tmp;
  ++qc[(int)tmp];
  vector<pp> ans;
  ans.push_back(pp(0,0));
  for(int i=1;i<n;++i)
    {
      scanf("%c%c",&tmp,&tmp2);
      p[2*i-1]=tmp,p[2*i]=tmp2;
      ++qc[(int)tmp],++qc[(int)tmp2];
      q[i]=(qc['Q']&1)?'Q':'C';
      int nq,nc;
      nq=qc[(int)'Q'];
      nc=qc[(int)'C'];
      //cout<<nq<<' '<<nc<<endl;
      if(nq&1)
	--nq;
      else --nc;
      for(int j=0;j<min(nq,nc);j+=2)
	{
	  q[j]='Q';
	  q[j+1]='C';
	  q[2*i-j]='Q';
	  q[2*i-j-1]='C';
	}
      tmp=nq>nc?'Q':'C';
      for(int j=min(nq,nc),k=abs(nq-nc);k>0;++j,k-=2)
	q[2*i-j]=q[j]=tmp;
      /*for(int j=0;j<=2*i;++j)
	printf("%c",p[j]);
      printf("\n");
      for(int j=0;j<=2*i;++j)
	printf("%c",q[j]);
	printf("\n\n");*/
      vector<int> det;
      for(int j=0;j<=2*i;++j)
	if(p[j]!=q[j])
	  det.push_back(j+1);
      if(det.size()>4)
	{
	  printf("He");
	  return 0;
	}
      if(det.size()==0)
	ans.push_back(pp(0,0)),
	  ans.push_back(pp(0,0));
      else if(det.size()==2)
	{
	  ans.push_back(pp(0,0));
	  ans.push_back(pp(det[0],det[1]));
	}
      else
	{
	  if(det[0]==det[1])
	    ans.push_back(pp(det[0],det[2])),
	      ans.push_back(pp(det[1],det[3]));
	  else ans.push_back(pp(det[0],det[1])),
		 ans.push_back(pp(det[2],det[3]));
	}
      memcpy(p,q,sizeof(p));
    }
  printf("Qc\n");
  for(int i=0;i<ans.size();++i)
    printf("%d %d\n",ans[i].first,ans[i].second);
  return 0;
}
