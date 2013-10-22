#include <stdio.h>

#define N 1000
#define EQ(a,b,c,d) (a=((a==b)?c:d))

int q[N/4],poi,c;
char str[N+1];

void output(char c)
{
    if(c==EOF)
        return;
    if(poi)
    {
        if(q[poi-1])
        {
            if(c<='z' && c>='a')
                c+='A'-'a';
        }
        else if(c<='Z' && c>='A')
            c+='a'-'A';
    }
    printf("%c",c);
}

int begin()
{
    int state=0,s=0;

    for(;state!=3 &&state!=6;++c)
    {
           // printf("!\n%d",state);
        switch(str[c])
        {
            case 'U':
                EQ(state,0,1,-1);
                break;
            case 'D':
                EQ(state,0,2,-1);
                break;
            case 'P':
                EQ(state,1,3,-1);
                break;
            case 'O':
                EQ(state,2,4,-1);
                break;
            case 'W':
                EQ(state,4,5,-1);
                break;
            case 'N':
                EQ(state,5,6,-1);
                break;
            case '/':
                if(state==0 && s==0)
                    s=1;
                else state=-1;
                break;
            case '>':
                if(state!=6 && state!=3)
                    state=-1;
                break;
            default:
                state=-1;
                break;
        }

        if(state<0)
            return 1;
    }

    if(s)
        --poi;/*TODO*/
    else
    {
        if(state==6)
            q[poi++]=0;
        else q[poi++]=1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);

    scanf("%s",str);

    int tmp;
    while(str[c])
    {
        switch(str[c])
        {
            case '<':
                tmp=c++;
                if(begin())
                    for(;tmp<=c;++tmp)
                        output(str[tmp]);
                break;

            default:
                output(str[c]);
                break;
        }
        ++c;
    }

    return 0;
}
