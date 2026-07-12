#include <iostream>
#include <string>
int main(){
  long long n;
  std::cin>>n;
  int ans=0;
  for(int i=1;;i++){
    std::string tmp;
    tmp+=std::to_string(i);
    tmp+=std::to_string(i);
    if(std::stoll(tmp)<=n){
      ans++;
    }else{
      break;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}