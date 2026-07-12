#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::vector<std::pair<int,int>>> syogen(n);
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    for(int j=0;j<a;j++){
      int x,y;
      std::cin>>x>>y;
      x--;
      syogen[i].push_back({x,y});
    }
  }
  int ans=0;
  for(int bit=0;bit<(1<<n);bit++){//0…不親切,1…正直者とする
    std::bitset<15> bitset(bit);
    bool isOk=true;
    for(int per=0;per<n;per++){
      if(!bitset[per]){//perが不親切なら考慮しない
        continue;
      }
      for(auto [x,y]:syogen[per]){
        if(bitset[x]!=y){//親切な人の証言が矛盾したら、このbitsetについては考えない
          isOk=false;
          break;
        }
        if(!isOk){
          break;
        }
      }
    }
    if(isOk){//矛盾がないならchmax(ans,bitset.count)をする
      ans=std::max(ans,(int)bitset.count());
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}