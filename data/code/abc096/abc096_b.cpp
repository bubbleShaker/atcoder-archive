#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  std::vector<long long> vec(3);
  for(int i=0;i<3;i++){
    std::cin>>vec[i];
  }
  int k;
  std::cin>>k;
  std::sort(vec.begin(),vec.end());
  long long ans=0;
  for(int i=0;i<3;i++){
    if(i!=2){
      ans+=vec[i];
    }else{
      ans+=vec[i]*powll(2,k);
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}