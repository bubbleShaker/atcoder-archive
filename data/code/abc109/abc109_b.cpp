#include <iostream>
#include <vector>
#include <string>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::string> w(n);
  std::map<std::string,int> map;
  for(int i=0;i<n;i++){
    std::cin>>w[i];
    map[w[i]]++;
  }
  for(auto [str,cnt]:map){
    if(cnt>=2){
      std::cout<<"No"<<'\n';
      return 0;
    }
  }
  for(int i=1;i<n;i++){
    if(w[i][0]!=w[i-1][w[i-1].size()-1]){
      std::cout<<"No"<<'\n';
      return 0;
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}