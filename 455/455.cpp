#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,c;
inline ll nxt(ll v)
{
  return (v*a+(v%b))%c;
}
int main()
{
  freopen("in.txt","r",stdin);
  cin>>a>>b>>c;
  ll f,l;
  f=l=1;
  for(ll i=1,j=0;;++j)
    {
      if(j>2000000)
	{
	  cout<<-1;
	  return 0;
	}
      f=nxt(f);
      l=nxt(l);
      l=nxt(l);
      if(f==l)
	break;
    }
  f=1;
  ll c(0);
  for(;f!=l && c<=2000000;++c)
    f=nxt(f),l=nxt(l);
  f=nxt(f);
  ++c;
  for(;f!=l && c<=2000000;++c)
    f=nxt(f);
  if(c<=2000000)
    cout<<c;
  else cout<<-1;
  return 0;
}
