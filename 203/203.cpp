#include <cstdio>
#define N (500000)
typedef long long ll;
ll p[N*2+1][3];
int poi;
int n;
struct cmp
{
  bool operator()(int a,int b)
  {
    if(p[a][0]==p[b][0])
      return a<b;
    return p[a][0]<p[b][0];
  }
};
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
    scanf("%I64d",*(p+i));
  poi=n+1;
  int p1=1,p2=n+1;
  ll ans(0);
  for(int i=1;i<n;++i)
    {
      int a,b;
      if(p2>=poi || (p1<=n && p[p1][0]<p[p2][0]))
	a=p1++;
      else a=p2++;
      if(p2>=poi || (p1<=n && p[p1][0]<p[p2][0]))
	b=p1++;
      else b=p2++;
      ans+=p[poi][0]=p[a][0]+p[b][0];
      p[poi][1]=a,p[poi][2]=b;
      ++poi;
    }
  printf("%I64d",ans);
  return 0;
}
