#include <iostream>
#include <string>
int main(){
  long long n;
  std::cin>>n;
  std::string str=std::to_string(n);
  long long m=str.size()-1;
  long long q=m/3;
  long long ans=q*n;
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  for(long long i=1;i<=q;i++){
    ans-=powll(10,i*3)-1;
  }
  std::cout<<ans<<'\n';
  return 0;
}