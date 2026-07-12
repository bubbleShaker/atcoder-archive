#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::string> vec;
  
  auto f=[&](auto f,std::string s,int keta)->void{
    if(keta==n){
      vec.push_back(s);
      return;
    }
    f(f,s+"a",keta+1);
    f(f,s+"b",keta+1);
    f(f,s+"c",keta+1);
  };
  
  f(f,"",0);
  
  std::sort(vec.begin(),vec.end());
  for(int i=0;i<vec.size();i++){
    std::cout<<vec[i]<<'\n';
  }
  return 0;
}