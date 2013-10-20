#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in.txt","r",stdin);
  ll h,w,xc,yc,xt,yt;
  char s;
  cin>>h>>w>>xc>>yc>>xt>>yt>>s;
  ll ans(0);
  if(h==1 || w==1)
    {
      if(h==1)
	swap(h,w),swap(xc,yc),swap(xt,yt);
      if(xc>xt)
	xc=h-xc+1,xt=h-xt+1;
      if(s=='C')
	++xc,++ans;
      if(xc<xt)
	{
	  ans+=(h-xt)*2LL;
	  if(xc+1==xt)
	    ans+=1;
	  else
	    {
	      ll tmp=xt-2LL-xc;
	      ans+=tmp*2LL;
	      if(tmp&1)
		ans+=3LL;
	      else ans+=2LL;
	    }
	}
    }
  else
    {
      if(xc>xt)
	xc=h-xc+1,xt=h-xt+1;
      if(yc>yt)
	yc=w-yc+1,yt=w-yt+1;
      if(s=='C')
	{
	  if(yt-yc>xt-xc)
	    ++yc;
	  else ++xc;
	  ++ans;
	}
      if(((yt-yc+xt-xc)&1)==0)
	{
	  if(yc!=yt || xc!=xt)
	    {
	      ll tmp1=(h+w-xt-yt)*2LL + (xt-xc+yt-yc-1)*2LL;
	      if(xt-xc<yt-yc)
		swap(xt,yt),swap(xc,yc),swap(w,h);
	      ll tmp2=0LL;
	      if(xt-xc!=yt-yc)
		{
		  tmp2=(yt-yc)*2LL;
		  xc+=(yt-yc);
		  yt=yc;
		  tmp2+=( (yt-1+h-xt)*2LL + (xt-xc-1)*2LL );
		}
	      ans+=max(tmp1,tmp2);
	    }
	}
      else ans=0;
    }
  cout<<ans;
  return 0;
}


