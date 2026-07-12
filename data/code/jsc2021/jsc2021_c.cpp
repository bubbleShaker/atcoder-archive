#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  int a,b;
  std::cin>>a>>b;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  auto get_yakusu=[&](int y){
    std::vector<int> ret;
    for(int i=1;i*i<=y;i++){
      if(y%i==0){
        ret.push_back(i);
        if(i==y/i){
          continue;
        }
        ret.push_back(y/i);
      }
    }
    return ret;
  };
  int ans=0;
  for(int y=b;y>=a+1;y--){
    std::vector<int> y_yakusu=get_yakusu(y);
    std::sort(y_yakusu.rbegin(),y_yakusu.rend());
    for(int i=0;i<y_yakusu.size();i++){
      int min_val=y_yakusu[i]*ceili(a,y_yakusu[i]);
      // std::cout<<"y_yakusu is "<<y_yakusu[i]<<'\n';
      // std::cout<<"min_val "<<min_val<<'\n';
      if(a<=min_val&&min_val<y){
        ans=std::max(ans,y_yakusu[i]);
      }
      // std::cout<<"ans is "<<ans<<'\n';
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}