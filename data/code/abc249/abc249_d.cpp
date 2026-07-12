#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  std::map<int,long long> map;
  int max_a=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    max_a=std::max(max_a,a[i]);
    map[a[i]]++;
  }
  auto tyowakyusu=[&](int M){ //a*b<=Mを満たす(a,b)の集合をO(MlogM)で返す関数(解析は調和級数で検索)
    std::vector<std::pair<int,int>> ret;
    for(int a=1;a<=M;a++){
      for(int b=1;b<=M/a;b++){
        ret.push_back({a,b});
      }
    }
    return ret;
  };
  std::vector<std::pair<int,int>> vec=tyowakyusu(max_a);
  long long ans=0;
  for(auto [p,q]:vec){
    int r=p*q;
    // std::printf("%d %d %d\n",p,q,r);
    ans+=map[p]*map[q]*map[r];
  }
  std::cout<<ans<<'\n';
  return 0;
}