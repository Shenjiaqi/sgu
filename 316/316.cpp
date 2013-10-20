#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    int p[7][2];
    for(int i=1;i<=n;++i)
        p[i][0]=100,p[i][1]=0;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        if(p[b][0]>0)
            p[a][1]+=3;
        p[b][0]-=8;
    }
    for(int i=1;i<=n;++i)
        cout<<p[i][0]<<' '<<(max(p[i][0]/2,0)+p[i][1])<<endl;
    return 0;
}
