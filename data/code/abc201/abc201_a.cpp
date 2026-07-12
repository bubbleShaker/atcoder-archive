#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  std::vector<int> a(3);
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  if(a[2]-a[1]==a[1]-a[0]){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}