#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

map<string,string> mapp;
char buf[1000],poi;
char type;
int val;
string getstr()
{
    for(;buf[poi]!='\0' && buf[poi]==' ';++poi)
        ;
    string tmp;

    type=buf[poi];
    switch(type)
    {
        case '$':
            for(++poi;buf[poi]==' ';++poi)
                ;
            for(;buf[poi]!=' ' && buf[poi]!='=' && buf[poi]!='(' && buf[poi]!=')'
            &&buf[poi]!=',' &&buf[poi]!=';' && buf[poi]!='"';++poi )
                tmp+=buf[poi];
            break;
        case 'p': poi+=5;break;
        case 's': poi+=6;break;
        case ';':
        case ',':
        case '(':
        case '=':
        case ')': ++poi;break;
        case '"':
            for(++poi;buf[poi]!='"';++poi)
                tmp+=buf[poi];
            ++poi;
            break;
        default:
            bool neg=0;
            if(buf[poi]=='-')
                neg=1,++poi;
            for(;buf[poi]==' ';++poi)
                ;
            val=0;
            for(;buf[poi]<='9' && buf[poi]>='0';++poi)
                val=val*10+buf[poi]-'0';
            if(neg)
                val=-val;
            break;
    }
    return tmp;
}
string substr()
{
    getstr();//(
    string tmp=getstr();
    getstr();//,
    getstr();//off
    int off=val;
    getstr();//,|)
    int l,len=1<<30;
    l=mapp[tmp].length();
    if(type==',')
    {
        getstr();
        len=val;
        getstr();//)
    }
    if(off<0)
        off=l+off;
    if(len==(1<<30))
        len=l-off;
    string r;
    if(len>=0)
        r=mapp[tmp].substr(off,len);
    else r=mapp[tmp].substr(off,l-off+len);
    return r;
}
void gl()
{
    for(int i=0;;++i)
    {
        buf[i]='\0';
        if(EOF==scanf("%c",buf+i) || buf[i]=='\n')
            break;
    }
    poi=0;
}
void subset()
{
    getstr();//(
    string tmp=getstr();//name
    getstr();//,
    getstr();//off
    int off=val;
    getstr();//,|)
    int l,len=1<<30;
    l=mapp[tmp].length();
    if(type==',')
    {
        getstr();
        len=val;
        getstr();//)
    }
    getstr();//=
    string tmp1=getstr();//s
    string tmp2;
    if(type=='$')
        tmp2=mapp[tmp1];
    else tmp2=substr();
    if(off<0)
        off+=l;
    if(len==(1<<30))
        len=l-off;
    if(len<0)
        mapp[tmp].replace(off,l-off+len,tmp2);
    else mapp[tmp].replace(off,len,tmp2);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    for(char t;;)
        if(scanf("%c",&t)==EOF || t=='\n')
            break;
    for(int i=0;i<n;++i)
    {
        gl();
        string varname=getstr();
        getstr();//=
        mapp[varname]=getstr();
        getstr();//;
    }
    for(int i=0;i<m;++i)
    {
        gl();
        string tmp=getstr(),tmp2;
        switch(type)
        {
            case 'p':
                getstr();//(
                tmp=getstr();
                if(type=='$')
                    cout<<mapp[tmp]<<endl;
                else
                    cout<<substr()<<endl;
                getstr();//)
                break;
            case '$':
                getstr();//=
                tmp2=getstr();
                if(type=='$')
                    mapp[tmp]=mapp[tmp2];
                else
                    mapp[tmp]=substr();
                break;
            case 's':
                subset();
                break;
            default: break;
        }
        getstr();//;
    }
    return 0;
}
