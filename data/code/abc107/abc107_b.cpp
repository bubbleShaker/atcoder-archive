#include <iostream>
#include <vector>
#include <string>
#include <set>
int main(){
  int h,w;
  std::cin>>h>>w;
  std::vector<std::string> a(h);
  for(int i=0;i<h;i++){
    std::cin>>a[i];
  }
  std::set<int> row_set,col_set;
  for(int i=0;i<h;i++){
    bool can_erase=true;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        can_erase=false;
      }
    }
    if(can_erase){
      row_set.insert(i);
    }
  }
  for(int j=0;j<w;j++){
    bool can_erase=true;
    for(int i=0;i<h;i++){
      if(a[i][j]=='#'){
        can_erase=false;
      }
    }
    if(can_erase){
      col_set.insert(j);
    }
  }
  for(int i=0;i<h;i++){
    if(row_set.count(i)){
      continue;
    }
    for(int j=0;j<w;j++){
      if(!col_set.count(j)){
        std::cout<<a[i][j];
      }
    }
    std::cout<<'\n';
  }
  return 0;
}