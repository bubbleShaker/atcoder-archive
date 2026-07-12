#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  bool is_ok=true;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    if(i>=1){
      if(a[i-1]!=a[i]){
        is_ok=false;
      }
    }
  }
  if(is_ok){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}