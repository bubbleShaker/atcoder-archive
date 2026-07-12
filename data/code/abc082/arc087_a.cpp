#include <iostream>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::map<int,int> map;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    map[a]++;
  }
  int ans=0;
  for(auto [key,cnt]:map){
    if(cnt>=key){
      ans+=cnt-key;
    }else{
      ans+=cnt;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}