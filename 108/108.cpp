#include <stdio.h>
#include <stdlib.h>

#define N ((1<<6)-1)

bool p[N];
int c[5000][2];
int di[10000];

int cmp1(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int cmp2(const void *a,const void *b)
{
    return *((int*)a+1)-*((int*)b+1);
}

int main()
{
    freopen("in.txt","r",stdin);

    for(int i=0;i<10000;++i)
        di[i]=i%10+(i%100)/10+(i%1000)/100+i/1000;

	int n,k;
	scanf("%d %d\n",&n,&k);
	for(int i=0;i<k;++i)
	{
	    scanf("%d",c[i]);
		c[i][1]=i;
    }

	qsort(c,k,sizeof(c[0]),cmp1);

	int g=0,poi=0;
	for(int i=0;i<n;++i)
	{
		if(p[i&N]==0)
		{
			++g;

			while(poi<k && g==c[poi][0])
			    c[poi++][0]=i+1;
		}
		else
			p[i&N]=0;

        int tmp=i+di[(i+1)/10000]+di[(i+1)%10000];
		if(tmp<n)
			p[tmp&N]=1;
	}

	qsort(c,k,sizeof(c[0]),cmp2);

	printf("%d\n%d",g,c[0][0]);

	for(int i=1;i<k;++i)
		printf(" %d",c[i][0]);

	return 0;
}
