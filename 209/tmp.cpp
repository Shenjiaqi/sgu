#include <cstdio>
double set(double a)
{
  return a*111;
}
int main()
{
  double a,b,c,d;
  a=33333,b=777777777;
  c=a,d=b;
  c=set(a);
  d=set(b);
  printf("%d",(int)(a/b==c/d));
  return 0;
}
