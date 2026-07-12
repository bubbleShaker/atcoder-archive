#include <iostream>
#include <string>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::string ret;
  while(n>0){
    ret+=std::to_string(n%k);
    n/=k;
  }
  std::cout<<ret.size()<<'\n';
  return 0;
}