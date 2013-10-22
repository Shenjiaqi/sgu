#include <cstdio>
#include <cstring>
#include <cstdarg>
#define TS (8)
using namespace std;
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_OUTPUTF
static bool idlist[1000];
static int indent=0;

void addx(int x)
{
	idlist[x]=true;//idlist.insert(x);
}
void delx(int x)
{
	idlist[x]=false;//idlist.erase(x);
}
void addid()
{
	++indent;
}
void delid()
{
	--indent;
}
void nchars(FILE *file,int n,const char *c)
{
	for(int i=0;i<n;++i)
		fprintf(file,c,n);
}
void mprint(int pos,bool h,FILE *file ,const char * fmt, ...)
{
#define BUFSIZE (10001)
#ifdef DBG_ORMODE_TABLE
	int l=strlen(fmt);
	if(l>=sizeof(buf))
	{
		PE;
		return;
	}
#endif
	static char ft[BUFSIZE];
	const char * format;
	if(!h)
	{
		format=ft;
		int l=strlen(fmt);
		int j=0;
		for(int i=0;fmt[i];++i)
		{
			if(fmt[i]=='%')
			{
				ft[j++]='%';
				for(;fmt[i] && fmt[i]>'z' && fmt[i]<'a';)
					ft[j++]=fmt[++i];
				if(fmt[i])
					ft[j++]=fmt[++i];
				else break;
				ft[j++]=' ';
			}
			else if(fmt[i]=='\\')
				if(fmt[++i]=='\0')
					break;
		}
		ft[j]='\0';
	}
	else format=fmt;
	static char buff[BUFSIZE];
	va_list ap;
	va_start(ap,fmt);
	vsnprintf(buff,BUFSIZE,format,ap);
	va_end(ap);
	if(h)
	{
		for(int i=0,j=0;i<indent;++i)
		{
			if(i==pos && idlist[pos])
			{
				fprintf(file,"+");
				nchars(file,TS-2,"-");
				if(i!=indent-1)
				{
					fprintf(file,"-");
					for(;i<indent-1;++i)
						nchars(file,TS,"-");
					nchars(file,TS-1,"-");
				}
				fprintf(file,">");
				break;
			}
			else if(idlist[i])
			{
				fprintf(file,"|");
				nchars(file,TS-1," ");
			}
			else nchars(file,TS," ");
		}
	}
	fprintf(file,"%s",buff);
}
