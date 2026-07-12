#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  auto s=[&](int n){
    int ret=0;
    std::string ss=std::to_string(n);
    for(int i=0;i<ss.size();i++){
      ret+=(ss[i]-'0');
    }
    return ret;
  };
  if(n%s(n)==0){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}