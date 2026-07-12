#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::map<int,int> map;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    map[a]++;
  }
  std::vector<int> vec;
  for(auto [key,cnt]:map){
    vec.push_back(cnt);
  }
  std::sort(vec.begin(),vec.end());
  if(map.size()<=k){
    std::cout<<0<<'\n';
  }else{
    int ans=0;
    for(int i=0;i<map.size()-k;i++){
      ans+=vec[i];
    }
    std::cout<<ans<<'\n';
  }
  return 0;
}