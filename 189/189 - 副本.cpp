#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
map<string,string> mapp;
char buf[1000];
int val,poi;
char type;
/*
void gl()
{
    for(poi=0;EOF!=scanf("%c",buf+poi) && buf[poi]!='\n';++poi)
        ;
    buf[poi]='\0';
    poi=0;
}
string getstr()
{
    for(;buf[poi]==' ';++poi)
        ;
    type=buf[poi];
    string r;
    switch(type)
    {
        case '$':
            for(++poi;buf[poi]==' ';++poi)
                ;
            for(;((buf[poi]>='a' && buf[poi]<='z') ||
            (buf[poi]>='A' && buf[poi]<='Z') ||
            (buf[poi]<='9' && buf[poi]>='0') ||
            (buf[poi]=='_')) ;++poi)
                r+=buf[poi];
            break;
        case 'p': poi+=5;break;
        case 's': poi+=6;break;
        case '"':
            for(++poi;buf[poi]!='"';++poi)
                r+=buf[poi];
            ++poi;
            break;
        default:
            if(buf[poi]=='-' || (buf[poi]<='9' && buf[poi]>='0'))
            {
                bool neg=0;
                if(buf[poi]=='-')
                {
                    neg=1;
                    for(++poi;buf[poi]==' ';++poi)
                        ;
                }
                val=0;
                for(;buf[poi]<='9' && buf[poi]>='0';++poi)
                    val=val*10 + int(buf[poi]-'0');
                if(neg)
                    val=-val;
            }
            else ++poi;
            break;
    }
    return r;
}
string substr()
{
    getstr();//(
    string tmp=getstr();
    getstr();//,
    int l=mapp[tmp].length();
    int offset,len;
    len=1<<31;
    getstr();
    offset=val;
    getstr();
    if(type==',')
    {
        getstr();
        len=val;
        getstr();//)
    }
    if(offset<0)
        offset+=l;
    if(len==(1<<31))
        len=l-offset;
    if(len<0)
        len+=l-offset;
    return mapp[tmp].substr(offset,len);
}*/
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
    /*int n,m;
    scanf("%d %d",&n,&m);
    for(char t;EOF!=scanf("%c",&t)&&t!='\n';)
        ;
    for(int i=0;i<n;++i)
    {
        gl();
        string tmp=getstr();
        getstr();//=
        mapp[tmp]=getstr();
    }*/
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

    string tmp2,tmp;
    int t1,t2,t3;
    for(int i=0;i<m;++i)
    {
        gl();
        tmp=getstr();
        switch(type)
        {
            case '$':
            /*
                getstr();//=;
                tmp2=getstr();
                if(type=='$')
                    mapp[tmp]=mapp[tmp2];
                else    mapp[tmp]=substr();*/
                  getstr();//=
                tmp2=getstr();
                if(type=='$')
                    mapp[tmp]=mapp[tmp2];
                else
                    mapp[tmp]=substr();
                break;
            case 'p':
                /*getstr();//(
                tmp2=getstr();
                if(type=='$')
                    cout<<mapp[tmp2]<<endl;
                else cout<<substr()<<endl;*/
                getstr();//(
                tmp=getstr();
                if(type=='$')
                    cout<<mapp[tmp]<<endl;
                else
                    cout<<substr()<<endl;
                getstr();//)
                break;
            case 's':
            /*
                getstr();//(
                tmp=getstr();
                getstr();//,
                getstr();
                t1=val;
                getstr();
                t2=mapp[tmp].length();
                t3=1<<31;
                if(type==',')
                {
                    getstr();
                    t3=val;
                    getstr();//)
                }
                if(t1<0)
                    t1+=t2;
                if(t3==(1<<31))
                    t3=t2-t1;
                if(t3<0)
                    t3+=t2-t1;
                getstr();//=
                tmp2=getstr();
                if(type=='$')
                    mapp[tmp].replace(t1,t3,mapp[tmp2]);
                else
                    mapp[tmp].replace(t1,t3,substr());*/
                subset();
                break;
            default:
                break;
        }
        getstr();
    }
    return 0;
}
