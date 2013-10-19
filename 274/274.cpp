#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define LEN (100)
bool letter[256];
bool oth[256];
bool issym(const char & c)
{
  return (letter[(int)c]|oth[(int)c]);
}
int word(const char str[],int off)
{
  for(;str[off]!='\0' && issym(str[off]);++off)
    ;
  return off;
}
int prefix(const char str[],int off)
{
  off=word(str,off);
  if(str[off]=='.')
    {
      if(!issym(str[off+1]))
	return off;
      return prefix(str,off+1);
    }
  return off;
}
int suffix(const char str[],int off)
{
  off=prefix(str,off);
  if(str[off]!='\0')
    return off;
  int r=1;
  for(;letter[(int)str[off-r]];++r)
    ;
  if((r==3 || r==4) && str[off-r]=='.')
    return off;
  return -1;
}
bool address(const char str[])
{
  if(!issym(str[0]))
    return 0;
  int p=prefix(str,0);
  if(str[p]!='@')
    return 0;
  if(!issym(str[p+1]))
    return 0;
  p=suffix(str,p+1);
  return (p==strlen(str));
}
int main()
{
  freopen("in","r",stdin);
  for(int i=(int)'a';i<=(int)'z';++i)
    letter[i]=1,letter[i+'A'-'a']=1;
  for(int i=0;i<=9;++i)
    oth[i+'0']=1;
  oth[(int)'_']=1,oth[(int)'-']=1;
  int n;
  scanf("%d\n",&n);
  char tmp[LEN+1];
  for(int i=0;i<n;++i)
    {
      for(int j=0;;++j)
	{
	  tmp[j]='\0';
	  int z=getchar();
	  if(z==EOF || z==(int)'\n')
	    break;
	  tmp[j]=(char)z;
	}
      printf("%s\n",(address(tmp)?"YES":"NO"));
    }
  return 0;
}
