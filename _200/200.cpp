#include <cstdio>
#define T (100)
#define M (100)
#define V (4)
#define BASE (30)
int main()
{
  freopen("in","r",stdin);
  int t,m;
  scanf("%d%d",&t,&m);
  const int primes[T] = {
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
503, 509, 521, 523, 541 };
  int matr[M][V]={0};
  for(int i=0;i<m;++i)
    {
      int v;
      scanf("%d",&v);
      for(int j=0;v>1;++j)
	{
	  int r=0;
	  for(;(v%primes[j])==0;++r)
	    v/=primes[j];
	  if(r&1)
	    matr[i][j/BASE]|=1<<(j%BASE);
	}
    }
  int rank=0;
  for(int i=0;i<m;++i)
    {
      int pos=0;
      for(;pos<4 && matr[i][pos]==0;++pos)
	;
      if(pos<4)
	{
	  int v=matr[i][pos]&(-matr[i][pos]);
	  for(int j=i+1;j<m;++j)
	    if(matr[j][pos]&v)
	      for(int k=0;k<4;++k)
		matr[j][k]^=matr[i][k];
	}
      else ++rank;
    }
  int ans[4]={0};
  ans[0]=1;
  const int carry=100000000;
  for(int i=0;i<rank;++i)
    {
      for(int j=0,c=0;j<4;++j)
	{
	  ans[j]=(ans[j]<<1)+c;
	  if(ans[j]>=(carry))
	    {
	      c=ans[j]/carry;
	      ans[j]%=carry;
	    }
	  else c=0;
	}
    }
  for(int i=0;i<4;++i)
    if(ans[i]==0)
      ans[i]=carry-1;
    else
      {
	ans[i]-=1;
	break;
      }
  int p=3;
  for(;p>0 && 0==ans[p];--p)
    ;
  printf("%d",ans[p]);
  for(--p;p>=0;--p)
    printf("%08d",ans[p]);
  return 0;
}
