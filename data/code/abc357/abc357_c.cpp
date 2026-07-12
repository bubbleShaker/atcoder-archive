#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  auto make_str=[&](int n){
    std::string ret;
    for(int i=0;i<n;i++){
      ret+=".";
    }
    return ret;
  };
  std::vector<std::vector<std::string>> carpet(n+1);
  for(int k=0;k<=n;k++){//レベルkのカーペットを考える
    carpet[k].resize(powi(3,k));//行数を初期化
    if(k==0){
      carpet[0][0]+="#";
      continue;
    }
    for(int i=0;i<3;i++){
      for(int l=0;l<powi(3,k-1);l++){
        for(int j=0;j<3;j++){
          if(i==1&&j==1){
            carpet[k][i*powi(3,k-1)+l]+=make_str(powi(3,k-1));
          }else{
            carpet[k][i*powi(3,k-1)+l]+=carpet[k-1][l];
          }
        }
      }
    }
  }
  for(int i=0;i<carpet[n].size();i++){
    std::cout<<carpet[n][i]<<'\n';
  }
  return 0;
}