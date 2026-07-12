#include <iostream>
#include <string>
int main(){
  long long n,k;
  std::cin>>n>>k;
  for(int i=0;i<k;i++){
    if(n%200==0){
      n/=200;
    }else{
      std::string s=std::to_string(n);
      s+="200";
      n=std::stoll(s);
    }
  }
  std::cout<<n<<'\n';
  return 0;
}