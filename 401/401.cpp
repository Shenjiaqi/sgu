#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define N 500
const double det=1e-12;
const ll off=(ll)1e12;
ll w[N];
ll v[N];
ll p[N];
ll q[N];
ll len[N];
ll u,t;
int n;
int ttt=0;
ll cal(int i)
{
  double time=(double)p[i]/(double)off;
  double wid=w[i];
  double velo=v[i];
  double a=(double)u*time;
  double b=(a-wid)*(a+wid);
  double c=velo*time;
  if(b>0)
    c+=sqrt(b);
  ll r=c*(double)off;
  if(b<0 && r>0)
    --r;
  return r;
}
int main()
{
  freopen("in","r",stdin);
  cin>>n>>u>>t;
  for(int i=0;i<n;++i)
    cin>>w[i]>>v[i];
  ll ww=0;
  for(int i=0;i<n;++i)
    ww+=w[i];
  if(ww>t*u)
    printf("-1");
  else
    {
      ll s=0;
      for(int i=0;i<n;++i)
	{
	  q[i]=(w[i]*off)/u;
	  s+=q[i];
	}
      ll zz=0;
      for(int i=0;i<n;++i)
	zz+=v[i];
      s=t*off-s;
      ll left=s;
      for(int i=0;i<n;++i)
	{
	  p[i]=q[i]+s*v[i]/zz;
	  left-=s*v[i]/zz;
	}
      p[0]+=left;
      for(int i=0;i<n;++i)
	len[i]=cal(i);
      //cout<<"!"<<len[0]<<endl;
      /*for(int i=0;i<n;++i)
	if(q[i]*u-w[i]<0)
	{
	printf("%17lf %17lf",q[i]*u,w[i]);
	return 1;
	}*/
      ll d=s/(ll)n+1;
      for(;d!=(d&(-d));d^=(d&(-d)))
	;
      for(;d;d>>=1)
	for(;;)
	  {
	    bool brk=true;
	    for(int i=0;i<n;++i)
	      for(int j=0;j<n && p[i]>q[i];++j)
		if(i!=j)
		  {
		    ll chg=min(p[i]-q[i],d);
		    ll t1=len[i]+len[j];
		    p[i]-=chg,p[j]+=chg;
		    ll t2=cal(i);
		    ll t3=cal(j);
		    if(t2+t3>t1)
		      len[i]=t2,len[j]=t3,brk=false;
		    else p[i]+=chg,p[j]-=chg;
		  }
	    if(brk)
	      break;
	    /*
	      int ki,kj;
	      ll mm=0;
	      for(int i=0;i<n;++i)
	      if(p[i]>q[i])
	      for(int j=0;j<n;++j)
	      if(i!=j)
	      {
	      ll chg=min(p[i]-q[i],d);
	      ll t1=len[i]+len[j];
	      p[i]-=chg,p[j]+=chg;
	      ll t2=cal(i)+cal(j);
	      p[i]+=chg,p[j]-=chg;
	      if(t2-t1>mm)
	      mm=t2-t1,ki=i,kj=j;
	      }
	      if(mm<1)
	      break;
	      ll tmp=min(p[ki]-q[ki],d);
	      //ll old=len[ki]+len[kj];
	      p[ki]-=tmp,p[kj]+=tmp;
	      len[ki]=cal(ki),len[kj]=cal(kj);
	    */
	    //printf("%.17lf %.20lf %.20lf %.20lf %d %d %.20lf\n",d,old,len[ki]+len[kj],(len[ki]+len[kj])-old,ki,kj,mm);
	  }
      //if(ttt==1)
      //return 1;
      //for(int i=0;i<n;++i)
      //cout<<len[i]<<endl;
      s=0;
      for(int i=0;i<n;++i)
	s+=len[i];
      double length=(double)s/(double)off;
      //cout<<s<<endl;
      length=sqrt(length*length+(double)((ww)*(ww)));
      printf("%.10lf\n",length);
      length=0.0;
      for(int i=0;i<n;++i)
	{
	  if(p[i]<0 || p[i]<q[i])
	    return 1;
	  printf("%.10lf ",(double)p[i]/(double)off);
	}
    }
  return 0;
}
