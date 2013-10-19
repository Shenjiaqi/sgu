#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,p;
long long nn[32],ans,tt[60];
int cyc[60][2],cp;
long long gcd( long long a,long long b ){
    while( b ) b^=a^=b^=a%=b;
    return a;
}
long long pow( int a ){
    long long ret=1;
    for( int i=0;a;a>>=1,i++ )
        if( a&1 )
            ret=ret*nn[i]%p;
    return ret;
}
void ex_gcd( long long &x,long long &y,long long a,long long b ){
    if( !b ) x=1,y=0;
    else{
        ex_gcd( x,y,b,a%b );
        long long t=y;
        y=x-a/b*y,x=t;
    }
}
long long calcnt(){
    long long x,y,t=1;
    for( int i=0;i<cp;i++ ){
        t=t*tt[cyc[i][1]]%p;
        for( long long a=cyc[i][0],b=cyc[i][1];b;b>>=1,a=a*a%p )
            if( b&1 )
                t=t*a%p;
    }
    ex_gcd( x,y,t,p );
    x=( x%p+p )%p;
    return tt[n]*x%p;
}
void dfs( int d,int left ){
    if( !left ){
        long long t=0;        
        for( int i=0;i<cp;i++ ){
            t+=cyc[i][0]/2*cyc[i][1]+cyc[i][1]*(cyc[i][1]-1)/2*cyc[i][0];
            for( int j=i+1;j<cp;j++ )
                t+=cyc[i][1]*cyc[j][1]*gcd( cyc[i][0],cyc[j][0] );
        }
        ans=( ans+calcnt()*pow(t) )%p;
        return;
    }
    if( d==n ) return;
    for( int i=0;i*( n-d )<=left;i++ ){
        if(i) cyc[cp][0]=n-d,cyc[cp++][1]=i;
        dfs( d+1,left-i*( n-d ) );
        if(i) cp--;
    }        
}

int main(){
  freopen("in","r",stdin);
    cin>>n>>nn[0]>>p;    
    for( int i=1;i<32;i++ ) nn[ i ]=nn[ i-1 ]*nn[ i-1 ]%p;
    tt[0]=1;
    for( int i=1;i<=n;i++ ) tt[i]=tt[ i-1 ]*i%p;
    dfs( 0,n );    
    long long x,y;    
    ex_gcd( x,y,tt[n],p );
    x=( x%p+p )%p;    
    ans=ans*x%p;  
    cout<<ans<<endl;
}
