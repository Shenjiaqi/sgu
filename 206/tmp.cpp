const int maxn=20,INF=2147483647;
int w[maxn][maxn];
int lx[maxn]={0},ly[maxn]={0}; //顶标
int linky[maxn];
int visx[maxn],visy[maxn];
int lack;
bool find(int x){
  visx[x]=true;
  for(int y=0;y<maxn; y++){
    if(visy[y])continue;
    int t=lx[x]+ly[y]-w[x][y];
    if(t==0){
      visy[y]=true;
      if(linky[y]==-1||find(linky[y])){
	linky[y]=x;
	return true;
      }
    }
    else if(lack>t)lack=t;
  }
  return false;
}
void KM(){
  memset(linky,-1,sizeof(linky));
  for(int i=0;i<maxn; i++)
    for(int j=0;j<maxn; j++)
      if(w[i][j]>lx[i])
	lx[i]=w[i][j]; //初始化顶标
  for(int x=0;x<maxn; x++){
    for(;;){
      memset(visx,0,sizeof(visx));
      memset(visy,0,sizeof(visy));
      lack=INF;
      if(find(x))break;
      
      for(int i=0;i<maxn; i++){
	if(visx[i])lx[i]-=lack;
	if(visy[i])ly[i]+=lack;
      }
    }
  }
}
