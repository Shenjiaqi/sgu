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
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 1000000
char c[]={'O','_','.',',','-','~','=','\'','^','"'};
int key[128];
int num[]={0,2,3,5,7,11,13,17,19,23};
int carry[10];
char input[N+1];
int ii;
int ix[N][2],xi;
int output[N][2],oi;
char buf[N+1];
int bi;
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    ++c,++d;
  return *c-*d;
}
void dfs(int v,int l)
{
  if(v && l<10)
    {
      if(l+1<10)
	dfs(v/(1+num[l]),l+1);
      for(int i=v%(1+num[l]);i;--i)
	printf("%c",c[l]);
    }
}
void out(int c,int t)
{
  if(t==1)
    printf("%d",c);
  else if(c==0)
    printf("O");
  else
    dfs(c,1);
}
int main()
{
  freopen("in","r",stdin);
  carry[0]=1;
  for(int i=1;i<10;++i)
    carry[i]=carry[i-1]*(1+num[i]);
  int numofnum(0);
  for(int i=1;i<sizeof(c)/sizeof(char);++i)
    key[c[i]]=i;
  for(;scanf("%c",buf+bi)!=EOF;++bi)
    ;
  for(int i=0;i<bi;)
    {
      char tmp=buf[i];
      if(tmp<='9' && tmp>='0')
	{
	  output[oi][1]=i;
	  ++numofnum;
	  ll val=(ll)(tmp-'0');
	  ++i;
	  if(tmp>'0')
	    for(;bi>i && buf[i]<='9' && buf[i]>='0' && (val*(ll)10+(ll)(buf[i]-'0'))<carry[9];++i)
	      val=val*(ll)10+(ll)(buf[i]-'0');
	  output[oi][0]=val;
	  ix[oi][1]=0;
	  ix[oi][0]=ii;
	  ++oi;
	}
      else if(tmp=='O')
	{
	  ++numofnum;
	  output[oi][1]=i;
	  output[oi][0]=0;
	  ix[oi][1]=1;
	  ix[oi][0]=ii;
	  ++i;
	  ++oi;
	  }
      else if(key[tmp])
	{
	  ++numofnum;
	  output[oi][1]=i;
	  int pre=key[tmp];
	  int numb(1);
	  ll val(0);
	  for(++i;bi>i && key[buf[i]] && key[buf[i]]<=pre;++i)
	    {
	      if(pre==key[buf[i]])
		{
		  ++numb;
		  if(numb>num[pre])
		    {
		      --numb;
		      break;
		    }
		  /*if(val+numb*carry[pre]>maxnum)
		    break;*/
		}
	      else
		{
		  val+=numb*carry[pre-1];
		  pre=key[buf[i]];
		  numb=1;
		}
	    }
	  output[oi][0]=val+numb*carry[pre-1];
	  ix[oi][1]=1;
	  ix[oi][0]=ii;
	  ++oi;
	}
      else
	{
	  input[ii]=tmp;
	  ++ii;
	  ++i;
	}
    }
  if(numofnum&1)
    qsort(output,oi,sizeof(output[0]),cmp);
  //for(int i=0;i<oi;++i)
  //cout<<output[i][0]<<' '<<output[i][1]<<endl;
  for(int i=0,j=0;i<ii || j<oi;)
    if(j<oi && ix[j][0]==i)
      {
	out(output[j][0],ix[j][1]);
	++j;
      }
    else if(i<ii)
      {
	printf("%c",input[i]);
	++i;
      }
  return 0;
}
