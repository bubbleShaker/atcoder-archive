#include <iostream>
#include <algorithm>
int main(){
  int n,m,X,Y;
  std::cin>>n>>m>>X>>Y;
  int max_x=-100,min_y=100;
  for(int i=0;i<n;i++){
    int x;
    std::cin>>x;
    max_x=std::max(max_x,x);
  }
  for(int i=0;i<m;i++){
    int y;
    std::cin>>y;
    min_y=std::min(min_y,y);
  }
  if(max_x>min_y){
    std::cout<<"War"<<'\n';
  }else{
    for(int z=max_x+1;z<=min_y;z++){
      if(X<z&&z<=Y){
        std::cout<<"No War"<<'\n';
        return 0;
      }
    }
    std::cout<<"War"<<'\n';
  }
  return 0;
}