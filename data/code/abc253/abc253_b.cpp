#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
int main(){
  int h,w;
  std::cin>>h>>w;
  std::vector<std::string> s(h);
  for(int i=0;i<h;i++){
    std::cin>>s[i];
  }
  std::vector<std::pair<int,int>> xy(2);
  int idx=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='o'){
        xy[idx].first=i;
        xy[idx].second=j;
        idx++;
      }
    }
  }
  std::cout<<std::abs(xy[0].first-xy[1].first)+std::abs(xy[0].second-xy[1].second)<<'\n';
  return 0;
}