#include <iostream>
#include <set>
int main(){
  const int MAX=1e5;
  long long n;
  std::cin>>n;
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  std::set<long long> set;
  for(long long a=2;a<=MAX;a++){
    for(int b=2;;b++){
      if(powll(a,b)>n){
        break;
      }
      set.insert(powll(a,b));
    }
  }
  std::cout<<n-set.size()<<'\n';
  return 0;
}