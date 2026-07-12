#include <iostream>
#include <vector>
int main(){
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  int m;
  std::cin>>m;
  std::vector<int> ans;
  while(m!=0){
    for(int i=10;i>=0;i--){
      if(m>=powi(3,i)){
        m-=powi(3,i);
        ans.push_back(i);
        break;
      }
    }
  }
  int n=ans.size();
  std::cout<<n<<'\n';
  for(int i=0;i<n;i++){
    std::cout<<ans[i]<<((i!=n-1)?' ':'\n');
  }
  return 0;
}