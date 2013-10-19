#include <cstdio>
#include <cstring>
typedef long long ll;
ll num1[64+2][3],num2[64+2][3];
bool changable[128];
ll base=(ll (1e17));
void add(ll *a,ll *b)
{
  for(int i=0;i<3;++i)
    {
      a[i]+=b[i];
      if(a[i]>=base)
	a[i]-=base,++a[i+1];
    }
}
int main()
{
  freopen("in","r",stdin);
  int q,c;
  char nickname[100*2];
  nickname[0]=' ';
  scanf("%d%d\n",&q,&c);
  int l=0;
  for(int tmp;;)
    {
      tmp=getchar();
      if(tmp==EOF || tmp=='\n')
	break;
      if(tmp!=' ' || nickname[l]!=' ')
	nickname[++l]=tmp;
    }
  nickname[++l]=' ';
  nickname[++l]='\0';
  changable['A']=changable['B']=changable['C']=changable['E']=changable['H']=
    changable['K']=changable['M']=changable['O']=changable['P']=
    changable['T']=changable['X']=changable['a']=changable['c']=
    changable['e']=changable['o']=changable['p']=changable['x']=
    changable['y']=1;
  ll (*a)[3],(*b)[3];
  a=num1,b=num2;
  a[0][0]=1;
  q+=2,c+=2;
  //printf("!%s!\n",nickname);
  for(int i=0;i<l;++i)
    {
      memset(b,0,sizeof(num1));
      for(int j=0;j<c;++j)
	{
	  ll tmp[3];
	  memcpy(tmp,a[j],sizeof(tmp));
	  if(changable[nickname[i]])
	    {
	      add(b[j+1],tmp);
	      add(b[j+1],tmp);
	    }
	  else if(nickname[i]==' ')
	    {
	      for(int k=j+1;k<=c;++k)
		add(b[k],tmp);
	      for(;i<l-1 && nickname[i+1]==' ';++i)
		;
	    }
	  else add(b[j+1],tmp);
	}
      ll (*tmp)[3];
      tmp=b,b=a,a=tmp;
    }
  ll ans[3]={0};
  for(int i=q;i<=c;++i)
    add(ans,a[i]);
  int z;
  for(z=0;ans[z]==0;++z)
    ans[z]=base-(ll)1;
  if(z<3)
    --ans[z];
  for(z=2;z>0 && ans[z]==0;--z)
    ;
  printf("%lld",ans[z]);
  for(--z;z>=0;--z)
    printf("%lld",ans[z]);
  return 0;
}
