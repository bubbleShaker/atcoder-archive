#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> h(n);
  for(int i=0;i<n;i++){
    std::cin>>h[i];
  }
  int idx=0;
  for(int i=0;i<n-1;i++){
    if(h[i+1]>h[i]){
      idx++;
    }else{
      break;
    }
  }
  std::cout<<h[idx]<<'\n';
  return 0;
}