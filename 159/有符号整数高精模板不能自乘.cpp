#include <cstdio>
#include <cstring>
#define MAXLEN 450//数组长度上限，可以根据需求自行设置
#define BASE_DIGIT 9//运算的进制，9代表以10^9计算
#define BASE 1000000000//10^9进制
#define PRINTCHAR ("%09d")//专长整数输出定义的字符串
#define IsDigit(c) (('0'<=(c))&&((c)<='9'))//判断字符c是否为数字
using namespace std;
char instr[MAXLEN*BASE_DIGIT+1];
short CMP(const int *a,const int *b){//比较数组大整数，也就是大整数的绝对值
    if(a[0]<b[0])//数位少的小
        return -1;
    if(a[0]>b[0])//数位多的大
        return 1;
    for(int i=a[0];i>0;i--)
    {
        if(a[i]<b[i])//高位小的小
            return -1;
        if(a[i]>b[i])//高位大的数大
            return 1;
    }
    return 0;
}
void ADD(const int *a,const int *b,int *c){//数组表示的大整数加法
    memset(c,0,sizeof(int)*MAXLEN);
    int la=a[0],lb=b[0],d=0;
    c[0]=(la>lb?la:lb)+1;
    for(int i=1;i<=c[0];i++)
    {
        c[i]= a[i]+b[i]+d;
        if(i>la)
            c[i]-=a[i];
        else if(i>lb)
            c[i]-=b[i];
        d=0;
        if(c[i]>=BASE)
        {//需要进位
            d=1;
            c[i]-=BASE;
        }
    }
    while(c[0]>1&&c[c[0]]==0)//消去前导零
                             c[0]--;
}
void SUB(const int *a,const int *b,int *c){//减法
    memset(c,0,sizeof(int)*MAXLEN);
    c[0]=a[0];
    int d=0;
    for(int i=1;i<=a[0];i++)
    {
        c[i]=a[i]-b[i]-d;
        d=0;
        if(c[i]<0)
        {//需要借位
            c[i]+=BASE;
            d++;
        }
    }
    while(c[0]>1&&c[c[0]]==0)
        c[0]--;//消去前导零
    return ;
}
void MUL(const int *a,const int *b,int *c){//乘法
    memset(c,0,sizeof(int)*MAXLEN);
    __int64 t=0;
    int l = a[0]+b[0]+1;
    c[0]=l;
    for(int i=1;i<=a[0];i++)
        for(int j=1;j<=b[0];j++)
        {
            /*计算中间结果很可能超出int32范围，故使用int64中转*/
            t=(__int64)c[i+j-1]+(__int64)a[i]*(__int64)b[j];
            c[i+j-1]=t%BASE;
            c[i+j] += t/BASE;//存储进位
        }
    while(c[0]>1&&c[c[0]]==0)
        c[0]--;//消去前导零
}
void MUL(const int *a,int b,int *c){//高精乘单精
    memset(c,0,sizeof(int)*MAXLEN);
    int l = a[0] + 1 ;
    __int64 t=0;
    for(int i=1;i<=l;i++)
    {
        t = (__int64)a[i]*b + (__int64)c[i];
        c[i+1] = t/BASE;
        c[i] = (t%BASE);
    }
    while(c[l]==0&&l>1) l--;
    c[0]=l;
}
void DIV(const int *a,const int *b,int *c,int *d){//除法
        memset(c,0,sizeof(int)*MAXLEN);memset(d,0,sizeof(int)*MAXLEN);
        int *t1 = new int[MAXLEN],*t2 = new int[MAXLEN];
        int la=a[0],lb=b[0],ld=0,min=0,max=0,mid=0,l = la;
        double tdmin=0,tdmax=0,tbmin=b[lb],tbmax=tbmin+1.0;
        if(lb>1)
        {//取两个高位的值，用作试商
            tbmin = tbmin*(double)BASE + (double)b[lb-1];
            tbmax = tbmin+1.0;
        }
        for(int i=l;i>0;i--)
        {
            for(int j=d[0];j>=1;j--)d[j+1]=d[j];d[1]=a[i];
            if(d[d[0]+1]!=0)d[0]++;
            if(CMP(d,b)<0)
                continue;
            ld = d[0];
            tdmin = d[ld];
            int j = 1;
            while(tdmin<tbmin)
            {
                tdmin = tdmin*BASE + d[ld-j];
                j++;
            }
            tdmax = tdmin+1.0;
            max =(int)(tdmax/tbmin)+1;min =(int)(tdmin/tbmax)-1;
            while(true)
            {//二分试商
                mid = (min+max)/2;
                MUL(b,mid,t1);
                if(CMP(d,t1)<0){max = mid-1;continue;}//试商偏高，改变max值
                SUB(d,t1,t2);
                if(CMP(t2,b)>=0){min = mid+1;continue;}//试商偏低，改变min值
                break;//试商成功，此mid值为该位的商值
            }
            c[i]=mid;
            memcpy(d,t2,sizeof(int)*MAXLEN);//t2为余值，赋给d
        }
        delete []t1;delete []t2;
        while(c[l]==0&&l>1) l--;
        c[0]=l;//消去前导零
}
class HarInt{/*超长大整数类，支持正负大整数的基本运算*/
private:
    int numb[MAXLEN];//具体数字，第0位表示数字长度，第一位及以后分别表示数字的高位至低位
    bool flag;
public:
    HarInt(){}/*默认构造函数*/
    ~HarInt(){}/*析构函数*/
    bool Parse(const char *s){/*将一个字符串转化为一个长整数*/
        clear();int l=strlen(s),i=0,nl=1;flag = true;//默认为非负数
        if(s[0]=='-'){i++;flag = false;}//为负数，数值从第2位开始
        for(int j=l-1;j>=i;j-=BASE_DIGIT)
        {//从高位至低位一位一位转
            int n=0,ten=1;
            for(int k=0;(k<BASE_DIGIT&&j-k>=i);k++)
            {
                if(!IsDigit(s[j-k])){clear();return false;}//含非数字字符，赋值失败
                n+=(s[j-k]-'0')*ten;ten*=10;
            }
            numb[nl++]=n;//从第一位开始给数组numb赋值，第0位预留为数字长
        }
        nl--;while(numb[nl]==0&&nl>1)nl--;//消去前导零
        numb[0]=nl;return true;//赋值成功
    }
    void clear(){memset(numb,0,sizeof(int)*MAXLEN);}/*将所有数位置为零*/
    void Parse(const HarInt hi){/*通过复制已知对象赋值*/
        memcpy(numb,hi.numb,sizeof(int)*MAXLEN);
        flag = hi.flag;
    }
    void value(const int a){/*通过一个较小的整形数赋值*/
        int t=a;
        flag=true;if(t<0){flag=false;t*=-1;}
        numb[0]=1;numb[1]=t;
    }
    int operator[](int i){return numb[i];}/*重载[]，访问第i位数字*/
    bool Flag(){return flag;}/*获取当前数的符号*/
    bool isZero(){return (numb[0]==1&&numb[1]==0);}/*是否为0*/
    int Get(){if(scanf("%s",instr)==EOF)return EOF;return Parse(instr);}/*自定义输入函数*/
    void print(char s){/*自定义输出函数*/
        if(!flag)putchar('-');
        printf("%d",numb[numb[0]]);
        for(int i=numb[0]-1;i>=1;i--)
            printf(PRINTCHAR,numb[i]);
        putchar(s);
    }
    friend short HarIntCmp(HarInt,HarInt);//友元比较函数
    friend void DIV(HarInt,HarInt,HarInt&,HarInt&);//友元除法函数
    HarInt& operator+=(const HarInt& a){//重载+=运算符，实现大整数的+=运算
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        if(flag==a.flag)//同号，绝对值直接相加，符号不变
            ADD(n,a.numb,numb);
        else{//异号则绝对值大的减绝对值小的，符号与绝对值大的相同
            int c = CMP(n,a.numb);//比较两数的绝对值
            if(c==0){numb[0]=1;numb[1]=0;flag=true;}//|a|==|b|&&a*b<0则a-b=0;
            else if(c<0){SUB(a.numb,n,numb);flag=a.flag;}//|a|<|b|
            else    SUB(n,a.numb,numb);
        }
        delete []n;n=NULL;
        return *this;
    }
    HarInt& operator-=(const HarInt& a){//重载-=运算符，实现大整数的-=运算
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        if(flag!=a.flag)//异号，绝对值直接相加，符号不变
            ADD(n,a.numb,numb);
        else{//同号，绝对值大减小，符号由两数的大小确定
            int c = CMP(n,a.numb);
            if(c==0){numb[0]=1;numb[1]=0;flag=true;}//0
            else if(c<0){SUB(a.numb,n,numb);flag=!flag;}//a<b符号取反
            else    SUB(n,a.numb,numb);//a>b符号不变
        }
        delete []n;n=NULL;
        return *this;
    }
    HarInt& operator*=(const HarInt& a){//重载*=运算符，实现大整数的*=运算
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        MUL(n,a.numb,numb);//绝对值相乘
        flag = (flag==a.flag);//同号取正，异号取负
        delete []n;n=NULL;
        return *this;
    }
    HarInt& operator/=(const HarInt& a){//重载/=运算符，实现大整数的/=运算
        int *n1 = new int[MAXLEN],*n2 = new int[MAXLEN];
        memcpy(n1,numb,sizeof(int)*MAXLEN);
        DIV(n1,a.numb,numb,n2);//绝对值相除
        delete []n1;delete []n2;
        flag = (flag==a.flag);//同号取正，异号取负
        return *this;
    }
    HarInt& operator%=(const HarInt& a){//重载%=运算符，实现大整数的%=运算
        int *n1 = new int[MAXLEN],*n2 = new int[MAXLEN];
        memcpy(n1,numb,sizeof(int)*MAXLEN);
        DIV(n1,a.numb,n2,numb);
        delete []n1;delete []n2;
        flag = (flag==a.flag);
        return *this;
    }
    HarInt& operator=(const int &a)
    {
        if(a>=0)
        {
            numb[1]=a;
            flag=1;
        }
        else
        {
            numb[1]=-a;
            flag=0;
        }
        numb[0]=1;
    }
};
void DIV(HarInt a,HarInt b,HarInt& c,HarInt& d){//除法，一次运算同时取得商与余数
    c.flag= (a.flag==b.flag);d.flag=c.flag;
    DIV(a.numb,b.numb,c.numb,d.numb);
    return ;
}
short HarIntCmp(HarInt a,HarInt b){
    if(a.Flag()>b.Flag())//正数恒大于负数
        return 1;
    if(a.Flag()<b.Flag())//负数恒小于正数
        return -1;
    if(a[0]<b[0])//数位少的数值小，根据符号判断大小
        return ((!a.Flag())?1:-1);
    if(a[0]>b[0])
        return (a.Flag()?1:-1);
    for(int i=a[0];i>=1;i--)
    {
        if(a[i]<b[i])
            return ((!a.Flag())?1:-1);
        if(a[i]>b[i])
            return (a.Flag()?1:-1);
    }
    return 0;
}
/*比较运算符的重载*/
bool operator<(HarInt a,HarInt b){return (HarIntCmp(a,b)<0);}
bool operator>(HarInt a,HarInt b){return (HarIntCmp(a,b)>0);}
bool operator==(HarInt a,HarInt b){return (HarIntCmp(a,b)==0);}
bool operator!=(HarInt a,HarInt b){return (HarIntCmp(a,b)!=0);}
bool operator<=(HarInt a,HarInt b){return (HarIntCmp(a,b)<=0);}
bool operator>=(HarInt a,HarInt b){return (HarIntCmp(a,b)>=0);}
/*基本运算符的重载*/
HarInt operator+(const HarInt& a,const HarInt& b){HarInt c=a;c+=b;return c;}
HarInt operator+(const HarInt& a,const int b){HarInt c;c.value(b);c+=a;return c;}
HarInt operator-(const HarInt& a,const HarInt& b){HarInt c=a;c-=b;return c;}
HarInt operator-(const HarInt& a,const int b){HarInt c;c.value(b);return (a-c);}
HarInt operator*(const HarInt& a,const HarInt& b){HarInt c=a;c*=b;return c;}
HarInt operator*(const HarInt& a,const int b){HarInt c;c.value(b);c*=a;return c;}
HarInt operator/(const HarInt& a,const HarInt& b){HarInt c=a;c/=b;return c;}
HarInt operator/(const HarInt& a,const int b){HarInt c;c.value(b);return (a/c);}
HarInt operator%(const HarInt& a,const HarInt& b){HarInt c=a;c%=b;return c;}
HarInt operator%(const HarInt& a,const int b){HarInt c;c.value(b);return (a%c);}
int main()
{
    HarInt a,b;
    a=2,b=1;
    b.print('\n');
    a.print('\n');
    int c=9;
    for(int i=1;i<=c;i<<=1)
    {
        if(i&c)
            b*=a;
        a=a*a;
    }
    b.print('\n');
    b=b%3;
    b.print('\n');
    return 0;

}
