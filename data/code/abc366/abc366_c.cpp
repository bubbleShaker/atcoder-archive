#include <iostream>
#include <map>
int main(){
  int q;
  std::cin>>q;
  std::map<int,int> map;
  int ret=0;
  while(q--){
    int t;
    std::cin>>t;
    if(t==1){
      int x;
      std::cin>>x;
      map[x]++;
      if(map[x]==1){
        ret++;
      }
    }else if(t==2){
      int x;
      std::cin>>x;
      map[x]--;
      if(map[x]==0){
        ret--;
      }
    }else if(t==3){
      std::cout<<ret<<'\n';
    }
  }
  return 0;
}