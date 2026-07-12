#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  std::vector<bool> exist(2001);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    exist[a[i]]=true;
  }
  for(int i=0;i<=2000;i++){
    if(exist[i]==false){
      std::cout<<i<<'\n';
      return 0;
    }
  }
  return 0;
}