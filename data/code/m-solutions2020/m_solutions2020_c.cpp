#include <iostream>
#include <vector>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  for(int i=k+1;i<=n;i++){
    if(a[i-k]<a[i]){
      std::cout<<"Yes"<<'\n';
    }else{
      std::cout<<"No"<<'\n';
    }
  }
  return 0;
}