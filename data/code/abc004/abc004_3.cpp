#include <iostream>
#include <utility>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  int q=n/5;
  int r=n%5;
  q%=6;
  std::vector<int> vec(7);
  for(int i=1;i<=6;i++){
    vec[i]=(q+i)%6;
    if(vec[i]==0){
      vec[i]=6;
    }
  }
  for(int i=1;i<=r;i++){
    std::swap(vec[i],vec[i+1]);
  }
  for(int i=1;i<=6;i++){
    std::cout<<vec[i]<<((i!=6)?"":"\n");
  }
  return 0;
}