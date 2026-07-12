#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> h(n);
  for(int i=0;i<n;i++){
    std::cin>>h[i];
  }
  for(int i=1;i<n;i++){
    if(h[0]<h[i]){
      std::cout<<i+1<<'\n';
      return 0;
    }
  }
  std::cout<<-1<<'\n';
  return 0;
}