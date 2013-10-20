#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
#define N 80
#define DET (1e-8)
#define MINA (1e-8)
#define PI (3.1415927)
typedef pair<double,double> pp;
typedef pair<pp,pp> ele;
int n;
int line[N][4];
bool cross(int a,int b,double &x,double &y)
{
  double x1=line[a][3]-line[a][1],x2=line[a][0]-line[a][2];
  double x3=line[a][0]*x1+line[a][1]*x2;
  double y1=line[b][3]-line[b][1],y2=line[b][0]-line[b][2];
  double y3=line[b][0]*y1+line[b][1]*y2;
  double tmp=x1*y2-y1*x2;
  if(fabs(tmp)<DET)
    return 0;
  x=(x3*y2-x2*y3)/tmp;
  y=(x1*y3-y1*x3)/tmp;
  return 1;
}

bool equ(pp a,pp b)
{
    double x1,y1,x1_,y1_;
    x1=(a).first,y1=(a).second;
    x1_=(b).first,y1_=(b).second;
    return !(fabs(x1-x1_)>DET || fabs(y1-y1_)>DET);
}
double angle(pp a,pp b)
{
  if(equ(a,b))
    return 0;
  double x1=b.first-a.first,y1=b.second-a.second;
  double tmp= acos((x1)/sqrt(x1*x1+y1*y1));
  //printf("%lf %lf %lf\n",x1,y1,tmp);
  if(y1<0)
    return ((PI)*2.0-tmp);//greater than pi
  return tmp;
}
void pr(ele point)
{

      printf("%lf %lf %lf %lf \n",point.first.first,point.first.second
             ,point.second.first,point.second.second);
}
struct cmp
{
public:
  bool operator()(ele a,ele b)
  {
    if(!equ(a.first,b.first))
      return (a.first<b.first);
    double ang1,ang2;
    ang1=angle(a.first,a.second);
    ang2=angle(b.first,b.second);
    //pr(a);
    //pr(b);
    //printf("!%lf %lf\n",ang1,ang2);
    return ang1<ang2;
  }
};
map< ele , int,cmp> mapp;
double calarea(pp a,pp b,pp c)
{
  double x1=b.first-a.first,y1=b.second-a.second;
  double x2=c.first-a.first,y2=c.second-a.second;
  return (double)0.5*fabs(x1*y2-y1*x2);
}
bool checkcross(pp a,pp b,pp c)
{
  double x1=b.first-a.first,y1=b.second-a.second;
  double x2=c.first-a.first,y2=c.second-a.second;
  if( x1*y2-x2*y1<=0)
    return 0;
  return 1;
}

double cal(ele a)
{
  double sum(0);
  pp r=a.first;
  for(;;)
    {
      ele point=make_pair(a.second,a.first);
      ele point2=make_pair(a.second,a.second);
      map<ele,int,cmp>::iterator ite= mapp.upper_bound(point);
      map<ele,int,cmp>::iterator ite2=mapp.lower_bound(point2);
      bool f1,f2;
      f1=f2=1;
      ele b,b2;
      if(ite==mapp.end())
        f1=0;
      else b=(*ite).first;
      if(ite2==mapp.end())
        f2=0;
      else b2=(*ite2).first;
      //pr(a);
      //pr(b2);
      if(f1 && !equ(a.second,b.first))
        f1=0;
      if(f2 && !equ(a.second,b2.first))
        f2=0;
      //printf("!%lf %lf %lf %lf %d\n",b.first.first,b.first.second,b.second.first,b.second.second,(int)f1);
      //printf("!!%lf %lf %lf %lf %d\n",b2.first.first,b2.first.second,b2.second.first,b2.second.second,(int)f2);

      if(!f1)
        {
          if(f2)
            b=b2,f1=1,ite=ite2;
          else return 0;
        }
      if(equ(b.second,r))
        break;
    //printf("!!!%lf\n",sum);
      if(checkcross(a.second,b.second,a.first))
        return 0;
      sum+=calarea(r,b.first,b.second);
      a=b;
      mapp.erase(ite);
    }
  return sum;
}

int main()
{
    freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d%d%d%d",*(line+i),*(line+i)+1,*(line+i)+2,*(line+i)+3);
  for(int i=0;i<n;++i)
    {
        vector< pp > point;
        for(int j=0;j<n;++j)
            if(i!=j)
            {
              double x,y;
              if(cross(i,j,x,y))
                point.push_back(pp(x,y));
            }
        sort(point.begin(),point.end());
        vector< pp >::iterator ite=unique(point.begin(),point.end(),equ);
        point.resize(ite-point.begin());
        int all=point.size();
        for(int j=0;j<all-1;++j)
            mapp[ make_pair(point[j],point[j+1]) ]=1,
            mapp [ make_pair(point[j+1],point[j])]=1;
    }

    /*for(map<ele,int,cmp>::iterator ite=mapp.begin();ite!=mapp.end();++ite)
        {
            ele point=(*ite).first;
            pr(point);
        }
    for(int i=0;i<1;++i)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        ele tmp=(*(mapp.upper_bound(ele(pp(a,b),pp(c,d))))).first;
        printf("!");
        pr(tmp);
    }return 0;*/
  vector<double> area;
  for(int i=0; !mapp.empty();++i)
    {
      ele point;
      map<ele,int,cmp>::iterator ite=mapp.begin();
      //--ite;
      point=(*ite).first;
      mapp.erase(ite);
      //printf("%lf %lf %lf %lf \n",point.first.first,point.first.second,point.second.first,point.second.second);
      double tmp=cal(point);
      if(tmp>MINA)
        area.push_back(tmp);
	//printf("%lf\n",tmp);
    }
  sort(area.begin(),area.end());
  printf("%d\n",(int)area.size());
  for(vector<double>::iterator ite=area.begin();ite!=area.end();++ite)
    printf("%.9lf\n",(*ite+1e-9));
  return 0;
}
