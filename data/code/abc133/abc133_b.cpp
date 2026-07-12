#include <iostream>
#include <vector>
int main(){
  int n,d;
  std::cin>>n>>d;
  std::vector<std::vector<int>> x(n,std::vector<int>(d));
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      std::cin>>x[i][j];
    }
  }
  int ans=0;
  auto isOk=[&](int val){
    for(int i=0;i<127;i++){
      if(i*i==val){
        return true;
      }
    }
    return false;
  };
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int val=0;
      for(int k=0;k<d;k++){
        val+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      if(isOk(val)){
        ans++;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}