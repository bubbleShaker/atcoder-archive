#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
int main(){
  int n;
  long long k;
  std::cin>>n>>k;
  std::vector<std::pair<long long,long long>> ab(n);
  for(int i=0;i<n;i++){
    std::cin>>ab[i].first>>ab[i].second;
  }
  std::sort(ab.begin(),ab.end());
  long long now_villege=0;
  long long now_money=k;
  for(int i=0;i<n;i++){
    if(now_villege+now_money>=ab[i].first){
      now_money-=ab[i].first-now_villege;
      now_money+=ab[i].second;
      now_villege=ab[i].first;
    }else{
      break;
    }
  }
  now_villege+=now_money;
  std::cout<<now_villege<<'\n';
  return 0;
}