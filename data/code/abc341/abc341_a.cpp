#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::string s;
  for(int i=0;i<2*n+1;i++){
    if(i%2==0){
      s+='1';
    }else{
      s+='0';
    }
  }
  std::cout<<s<<'\n';
  return 0;
}