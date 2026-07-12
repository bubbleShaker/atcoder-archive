#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n),w(n);
  std::map<int,std::vector<int>> map;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    std::cin>>w[i];
    map[a[i]].push_back(w[i]);
  }
  int ans=0;
  for(auto [key,vec]:map){
    if(vec.size()==1){
      continue;
    }
    std::sort(vec.begin(),vec.end());
    int sum=std::accumulate(vec.begin(),vec.end(),0);//intなら0,long longなら0LLにすることに注意
    ans+=sum-vec[vec.size()-1];
  }
  std::cout<<ans<<'\n';
  return 0;
}