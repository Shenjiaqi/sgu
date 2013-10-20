#include <cstdio>
int main()
{
  int n;
  int p[4]={0};
  scanf("%d",&n);
  char buf[107];
  char mm[256];
  for(int i='a';i<'d';++i)
    mm[i]=i-'a';
  for(int i=0;i<n;++i)
    {
      scanf("\n%s",buf);
      if(buf[0]=='w')
	printf("%d\n",p[mm[buf[8]]]);
      else if(buf[1]=='^')
	{
	  if(buf[4]<='9' && buf[4]>='0')
	    p[mm[buf[0]]]=buf[4]-'0';
	  else p[mm[buf[0]]]=p[mm[buf[4]]];
	}
      else mm[buf[0]]=mm[buf[3]];
    }
  return 0;
}
