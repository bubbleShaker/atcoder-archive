#include <iostream>
#include <map>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  std::map<int,int> map;
  map[a]++;
  map[b]++;
  map[c]++;
  if(map.size()==3){
    std::cout<<0<<'\n';
  }else{
    for(auto [val,cnt]:map){
      if(cnt!=2){
        std::cout<<val<<'\n';
        return 0;
      }
    }
  }
  return 0;
}