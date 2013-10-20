#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iostream>
using namespace std;
#define N 400
int p[N];
int bel[N];
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  typedef pair<double,int> pp;
  vector<pp> q;
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      q.push_back(pp((double)(p[j]-p[i])/(double)(j-i),j*500+i));
  sort(q.begin(),q.end());
  double minv=0.0;
  int v[3]={0};
  int ddd[3]={0};
  for(int i=0;i<n;++i)
    {
      int j=(i<n/2?0:(((n&1) && (i==n/2))?2:1));
      bel[i]=j;
      v[j]+=p[i];
      ddd[j]+=i;
    }
  double d=0.0;
  minv=v[1]-v[0];
  for(int i=0;i<q.size();++i)
    {
      double tmp,dd;
      dd=q[i].first;
      //for(;i<q.size() && (q[i].first-dd)<1e-11;++i)
	{
	  int a=q[i].second%500;
	  int b=q[i].second/500;
	  if(bel[b]!=bel[a])
	    {
	      v[bel[b]]-=(p[b]-p[a]);
	      v[bel[a]]+=(p[b]-p[a]);
	      ddd[bel[b]]-=(b-a);
	      ddd[bel[a]]+=(b-a);
	      swap(bel[b],bel[a]);
	    }
	}
      tmp=v[1]-v[0]+dd*(ddd[0]-ddd[1]);
      if(tmp<minv)
	minv=tmp,d=dd;
    }
  printf("%.4lf\n",minv);
  vector<double> qq;
  for(int i=0;i<n;++i)
    qq.push_back((double)p[i]-(double)i*d);
  sort(qq.begin(),qq.end());
  double x=qq[n/2];
  for(int i=0;i<n;++i,x+=d)
    printf("%.7lf ",x);
  return 0;
}
