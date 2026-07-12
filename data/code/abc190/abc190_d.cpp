#include <iostream>
#include <vector>
#include <utility>
#include <set>
int main(){
  long long n;
  std::cin>>n;
  auto calc_yakusu=[&](long long n){
    std::vector<std::pair<long long,long long>> ret;
    for(long long i=1;i*i<=n;i++){
      if(n%i==0){
        ret.push_back({i,n/i});
        if(i!=(n/i)){
          ret.push_back({n/i,i});
        }
      }
    }
    return ret;
  };
  std::vector<std::pair<long long,long long>> yakusu=calc_yakusu(2*n);
  std::set<std::pair<long long,long long>> ans_set;
  for(auto [x,y]:yakusu){
    long long a=(y-x+1)/2;
    long long l=(x+y-1)/2;
    if((y-x+1)%2||(x+y-1)%2){
      continue;
    }
    if(a<=l){
      ans_set.insert({a,l});
    }
  }
  std::cout<<ans_set.size()<<'\n';
  return 0;
}