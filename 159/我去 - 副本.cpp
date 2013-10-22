#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXNUMLEN 500
#define MOD (1000000000)
#include <string.h>
#include <iostream>
#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

int read(bignum_t a,istream& is=cin){
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>buf))	return 0;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}

int comp(const bignum_t a,const bignum_t b){
	int i;
	if (a[0]!=b[0])
		return a[0]-b[0];
	for (i=a[0];i;i--)
		if (a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}

int comp(const bignum_t a,const int b){
	int c[12]={1};
	for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}

int comp(const bignum_t a,const int c,const int d,const bignum_t b){
	int i,t=0,O=-DEPTH*2;
	if (b[0]-a[0]<d&&c)
		return 1;
	for (i=b[0];i>d;i--){
		t=t*DEPTH+a[i-d]*c-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	for (i=d;i;i--){
		t=t*DEPTH-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	return t>0;
}

void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

void add(bignum_t a,const int b){
	int i=1;
	for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]-=b[i])<0)
			a[i+1]--,a[i]+=DEPTH;
	for (;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const int b){
	int i=1;
	for (a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const bignum_t b,const int c,const int d){
	int i,O=b[0]+d;
	for (i=1+d;i<=O;i++)
		if ((a[i]-=b[i-d]*c)<0)
			a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
	for (;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t c,const bignum_t a,const bignum_t b){
	int i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for (c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
			if ((c[i+j-1]+=a[i]*b[j])>=DEPTH)
				c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for (c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}

void mul(bignum_t a,const int b){
	int i;
	for (a[1]*=b,i=2;i<=a[0];i++){
		a[i]*=b;
		if (a[i-1]>=DEPTH)
			a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t b,const bignum_t a,const int c,const int d){
	int i;
	memset((void*)b,0,sizeof(bignum_t));
	for (b[0]=a[0]+d,i=d+1;i<=b[0];i++)
		if ((b[i]+=a[i-d]*c)>=DEPTH)
			b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH;
	for (;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for (;!b[b[0]]&&b[0]>1;b[0]--);
}

void div(bignum_t c,bignum_t a,const bignum_t b){
	int h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
	for (i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
		for (h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}

void div(bignum_t a,const int b,int& c){
	int i;
	for (c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}
void set(bignum_t a,int v)
{
    a[0]=1;
    a[1]=v;
    if(a[1]>MAX)
    {
        a[++a[0]]=a[1]/MAX;
        a[1]%=MAX;
    }
}
void cpy(bignum_t a,bignum_t b)
{
    memcpy(b,a,sizeof(int)*(b[0]+1));
}
void gcd( bignum_t a, bignum_t b,bignum_t &x)
{
    bignum_t y,tmp,tmp1,tmp2;
    set(y,1);
    set(x,0);
    for(;;)
    {
        div(tmp,a,b);//tmp=a/b
        mul(tmp1,tmp,x);//tmp1=tmp*x
        cpy(tmp2,y);//tmp2=y
        sub(y,tmp2,tmp1);//y=tmp2-tmp1
        mul(tmp1,b,tmp);//tmp1=b*tmp
        sub(tmp,a,tmp1);//tmp=a-tmp1
        cpy(a,b),cpy(b,tmp);//
        cpy(tmp,y),cpy(y,x),cpy(x,tmp);
    }
}/*
int n,b,ans;
bignum_tan[6];
void solv(int p1,int p2)
{
    if(p1==0)
        return;
    static bignum_tnc,na,nb;
    nc=1;
    na=1;
    nb=1;
    static bignum_tc,d,e;
    c=p1;
    d=p2;
    e=b;
    for(int i=1;i<=n;i<<=1)
    {
        if(i&n)
            na*=c,nb*=d,nc*=e;
        c=c*c;
        d=d*d;
        e=e*e;
    }
    gcd(na,nb,c);
    c.prt("c");
    na.prt("na");
    c.dr(na,d);
    d.prt("d");
    if(d.neg)
        d+=na;
    d.prt("d");

    nb*=d;
    nb.dr(na,c);
    c.prt("c");



    e=b;
    nc.dr(e,NULL);
    an[ans]=d*nb;
    if(cmp(an[ans].num,nc.num)>=0)
        ++ans;
    na-=d;
    an[ans]=na*nb;
    e=1;
    an[ans]+=e;
    if(cmp(an[ans].num,nc.num)>=0)
        ++ans;
}
static const int ii[][2]={
    //0     1     2     3     4     5     6     7     8     9
    {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{2,3},{0,0},{0,0},{0,0},
    //10    11    12    13    14    15    16    17    18    19
    {2,5},{0,0},{3,4},{0,0},{2,7},{3,5},{0,0},{0,0},{2,9},{0,0},
    //20    21    22    23    24    25    26    27     28     29    30
    {4,5},{3,7},{2,11},{0,0},{3,8},{0,0},{2,13},{0,0},{4,7},{0,0},{0,0},
    //31    32     33    34    35     36
    {0,0},{0,0},{3,11},{2,17},{5,7},{4,9}
};
void ptr(int i)
{
    if(an[i].iszero())
        printf("0");
    else
    {
        static char str[2007];
        int poi=0;
        int *a=an[i].num;
        int l=a[0];
        for(;l>0;)
        {
            long long r=0;
            for(int i=l;i>0;--i)
            {
                long long tmp=a[i];
                tmp+=r*MOD;
                r=tmp%b;
                tmp/=b;
                a[i]=tmp;
            }
            r%=(long long)b;
            str[poi++]=(char)(r<10?r+'0':r-10+'A');
            for(;l>0 && !a[l];--l)
                ;
        }
        for(;poi>1 && str[poi-1]=='0';--poi)
            ;
        for(int i=poi-1;i>=0;--i)
            printf("%c",str[i]);
    }
    printf("\n");
}
*/
int main()
{
    /*
    freopen("in.txt","r",stdin);
    scanf("%d %d",&b,&n);
    if(b!=30)
    {
        if(ii[b][0])
            solv(ii[b][0],ii[b][1]);
    }
    else
    {
        solv(2,15);
        solv(6,5);
        solv(10,3);
    }
    printf("%d\n",ans+(n==1?2:0));
    if(n==1)
        printf("0\n1\n");
    for(int i=0;i<ans;++i)
        ptr(i);*/
    return 0;
}
