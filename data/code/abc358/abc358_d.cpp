#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<long long> b(m);
  std::multiset<long long> set;
  for(int i=0;i<n;i++){
    long long a;
    std::cin>>a;
    set.insert(a);
  }
  for(int i=0;i<m;i++){
    std::cin>>b[i];
  }
  std::sort(b.begin(),b.end());
  long long ans=0;
  for(int i=0;i<m;i++){
    auto it=set.lower_bound(b[i]);
    if(it==set.end()){
      std::cout<<-1<<'\n';
      return 0;
    }else{
      ans+=*it;
      set.erase(it);
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}