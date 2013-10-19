#include <cstdio>
unsigned int gcd(unsigned int a,unsigned int b)
{
  return (b==0?a:gcd(b,a%b));
}
int main()
{
  unsigned int n,u;
  scanf("%u",&n);
  u=(n+1)/(unsigned int )2+(unsigned int)1;
  int d=gcd(n,u);
  unsigned int ans;
  ans=1+d*((n/d)/2);
  printf("%u",ans);
  return 0;
}
