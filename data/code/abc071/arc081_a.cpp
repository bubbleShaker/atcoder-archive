#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> vec;
  std::map<long long,int> map;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    map[a]++;
    if(map[a]==2){
      vec.push_back(a);
      map[a]=0;
    }
  }
  std::sort(vec.rbegin(),vec.rend());
  if(vec.size()<2){
    std::cout<<0<<'\n';
  }else{
    std::cout<<vec[0]*vec[1]<<'\n';
  }
  return 0;
}