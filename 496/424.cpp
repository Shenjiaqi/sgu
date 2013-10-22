#include <cstdio>
#define N 5000
int p[N][4];
typedef long long ll;
bool check(int a,int b)
{
  if( (p[a][0]==p[b][0]&&p[a][1]==p[b][1]) ||
      (p[a][2]==p[b][2]&&p[a][3]==p[b][3]) ||
      (p[a][0]==p[b][2]&&p[a][1]==p[b][3]) ||
      (p[a][2]==p[b][0]&&p[a][3]==p[b][1]))
    {
      ll x1=p[a][0]-p[a][2],y1=p[a][1]-p[a][3];
      ll x2=p[b][0]-p[b][2],y2=p[b][1]-p[b][3];
      if(x1*x2+y1*y2==0)
	{
	  return true;
	}
    }
  return false;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3);
  int ans(0);
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      if(check(i,j))
	++ans;
  printf("%d",ans);
  return 0;
}
