#include <stdio.h>

const int N = 2048;
int n,bas,top;
int g[N][N];
int a[N];

void dfs(int idx,int sum)
{
    if (idx == n) {
        if (a[idx-1] || n == 1) {
            for (int i = 0;i < n;i++) {
                g[top][i] = a[i];
            }
            top++;
        }
        return ;
    }
    for (int i = 0;i < bas;i++) {
        a[idx] = i;
        int tmp = 0;
        for (int j = 0;j <= idx;j++) {
            tmp += a[j] * a[idx-j];
        }
        if ((sum + tmp) % bas == i) {
            dfs(idx + 1,(sum + tmp) / bas);
        }
    }
}

int main()
{
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d%d",&bas,&n);
    dfs(0,0);
    printf("%d\n",top);
    for (i = 0;i < top;i++) {
        for (j = n - 1;j >= 0;j--) {
            if (g[i][j] >= 10) {
                printf("%c",g[i][j] - 10 + 'A');
            }else {
                printf("%d",g[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
