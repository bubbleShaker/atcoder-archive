#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  const int INF=2e9;
  int n,k;
  std::cin>>n>>k;
  std::vector a(n+1,std::vector<int>(n+1));
  int max_a=0,min_a=INF;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      std::cin>>a[i][j];
      max_a=std::max(max_a,a[i][j]);
      min_a=std::min(min_a,a[i][j]);
    }
  }
  auto is_ok=[&](int x){ //x以下の中央値となる区間が存在したらtrueを返す
    std::vector<std::vector<int>> rsw(n+1,std::vector<int>(n+1));
    std::vector<std::vector<int>> vec(n+1,std::vector<int>(n+1));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(a[i][j]>x){
          vec[i][j]=1;
        }
      }
    }
    //列方向への累積和
    for(int i=0;i<=n;i++){
      for(int j=1;j<=n;j++){
        rsw[i][j]+=vec[i][j]+rsw[i][j-1];
      }
    }
    //行方向への累積和
    for(int j=0;j<=n;j++){
      for(int i=1;i<=n;i++){
        rsw[i][j]+=rsw[i-1][j];
      }
    }
    //区間内にxより大きい要素が(k*k)/2+1個未満あるような区間があるならばtrue
    for(int si=0;si<=n-k;si++){
      for(int sj=0;sj<=n-k;sj++){
        int migisitaX=si+k;
        int migisitaY=sj+k;
        int hidariueX=si+1;
        int hidariueY=sj+1;
        int more_than_x=rsw[migisitaX][migisitaY]+rsw[hidariueX-1][hidariueY-1]-rsw[hidariueX-1][migisitaY]-rsw[migisitaX][hidariueY-1];
        if(more_than_x<(k*k)/2+1){
          return true;
        }
      }
    }
    return false;
  };
  int ok=max_a;
  int ng=min_a-1;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(is_ok(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  std::cout<<ok<<'\n';
  return 0;
}