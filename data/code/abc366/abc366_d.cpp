#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector a(n+1,std::vector<std::vector<long long>>(n+1,std::vector<long long>(n+1)));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        std::cin>>a[i][j][k];
      }
    }
  }
  std::vector base_rsw(n+1,std::vector<std::vector<long long>>(n+1,std::vector<long long>(n+1)));
  for(int x=1;x<=n;x++){
    std::vector<std::vector<long long>>& rsw=base_rsw[x];
    std::vector<std::vector<long long>>& na=a[x];
    
    //列方向への累積和
    for(int i=0;i<=n;i++){
      for(int j=1;j<=n;j++){
        rsw[i][j]+=na[i][j]+rsw[i][j-1];
      }
    }
    //行方向への累積和
    for(int j=0;j<=n;j++){
      for(int i=1;i<=n;i++){
        rsw[i][j]+=rsw[i-1][j];
      }
    }
  }
  int q;
  std::cin>>q;
  while(q--){
    int lx,rx,ly,ry,lz,rz;
    std::cin>>lx>>rx>>ly>>ry>>lz>>rz;
    long long ret=0;
    for(int x=lx;x<=rx;x++){
      std::vector<std::vector<long long>>& rsw=base_rsw[x];
      ret+=rsw[ry][rz]+rsw[ly-1][lz-1]-rsw[ly-1][rz]-rsw[ry][lz-1];
      // std::cout<<"ret is "<<ret<<'\n';
    }
    std::cout<<ret<<'\n';
  }
  return 0;
}