#include<stdio.h>
#include<algorithm>
#include<string.h>
#include <iostream>
using namespace std;
struct fp
{
  int x,y;
}px[100011];
bool first_x(fp a,fp b)
{
  if(a.x==b.x)
    return a.y<b.y;
  else
    return a.x<b.x;
}
bool first_y(fp a,fp b)
{
  if(a.y==b.y)
    return a.x<b.x;
  else
    return a.y<b.y;
}

int cal[100011];
const long long bigp=1000000007;
long long hash[100011],mi2[100011];
int check(int n)
{
  int i,cnt=0;
  for(i=1;i<=n;++i)
    cnt+=cal[i];
  hash[n+1]=0;
  for(i=n;i>=1;--i)
    hash[i]=(hash[i+1]*2+cal[i])%bigp;
  for(i=1;i<=n&&cnt>1;)
    {
      int j,cnt2=cnt;
      long long nowhash=0;
      for(j=i;j<=n;++j)
        {
	  cnt-=cal[j];
	  nowhash=(nowhash*2+cal[j])%bigp;
	  if(nowhash==(hash[j+1]-hash[min(n+1,2*j-i+2)]*mi2[j-i+1]%bigp+bigp)%bigp)
	    break;
        }
      if(j<=n)
	{i=j+1;cout<<"!!"<<i<<endl;}
      else
        {
	  cnt=cnt2;
	  break;
        }
    }
  if(i>n||cnt<=1)
    return 1;
    
  int l=i;
  hash[0]=0;
  for(i=1;i<=n;++i)
    hash[i]=(hash[i-1]*2+cal[i])%bigp;
  for(int i=1;i<=n;++i)
    cout<<cal[i]<<' ';cout<<endl;
  for(i=n;i>=l&&cnt>1;)
    {
      cout<<"!"<<i<<' '<<l<<endl;
      int j;
      long long nowhash=0;
      for(j=i;j>=l;--j)
        {
	  cnt-=cal[j];
	  nowhash=(nowhash*2+cal[j])%bigp;
	  if(nowhash==(hash[j-1]-hash[max(l-1,2*j-i-2)]*mi2[i-j+1]%bigp+bigp)%bigp)
	    break;
        }
      if(j>=l)
	{
	  i=j-1;cout<<i<<"!"<<endl;
	}
      else
	return 0;
    }
  return 1;
}

int main()
{
  int i,j,n,r,c;
  freopen("in.txt","r",stdin);
  scanf("%d%d%d",&r,&c,&n);
  for(i=0;i<n;++i)
    scanf("%d%d",&px[i].x,&px[i].y);
    
  mi2[0]=1;
  for(i=1;i<=max(r,c);++i)
    mi2[i]=mi2[i-1]*2%bigp;
    
  sort(px,px+n,first_x);
  int len0;
  for(len0=1;len0<n&&px[len0].x==px[0].x;++len0);
  for(i=len0;i<n;i+=len0)
    {
      for(j=i;j<n&&px[j].x==px[i].x;++j);
      if(j-i!=len0)
        {
	  printf("NO\n");
	  return 0;
        }
      for(j=0;j<len0;++j)
	if(px[j].y!=px[i+j].y)
	  {
	    printf("NO\n");
	    return 0;
	  }
    }
  for(i=0;i<len0;++i)
    cal[px[i].y]=1;
  if(!check(c))
    {
      printf("NO\n");
      return 0;
    }
    
  sort(px,px+n,first_y);
  for(len0=1;len0<n&&px[len0].y==px[0].y;++len0);
  for(i=len0;i<n;i+=len0)
    {
      for(j=i;j<n&&px[j].y==px[i].y;++j);
      if(j-i!=len0)
        {
	  printf("NO\n");
	  return 0;
        }
      for(j=0;j<len0;++j)
	if(px[j].x!=px[i+j].x)
	  {
	    printf("NO\n");
	    return 0;
	  }
    }
  memset(cal,0,sizeof(cal));
  for(i=0;i<len0;++i)
    cal[px[i].x]=1;
  if(!check(r))
    {
      printf("NO\n");
      return 0;
    }
    
  printf("YES\n");
  return 0;
}
