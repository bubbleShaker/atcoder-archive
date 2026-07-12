#include <iostream>
#include <vector>
int main(){
  int n,d;
  std::cin>>n>>d;
  std::vector<int> t(n);
  for(int i=0;i<n;i++){
    std::cin>>t[i];
  }
  for(int i=0;i<n-1;i++){
    if(t[i+1]-t[i]<=d){
      std::cout<<t[i+1]<<'\n';
      return 0;
    }
  }
  std::cout<<-1<<'\n';
  return 0;
}