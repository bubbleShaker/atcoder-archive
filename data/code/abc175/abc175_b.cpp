#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> l(n);
  for(int i=0;i<n;i++){
    std::cin>>l[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        std::set<int> set;
        set.insert(l[i]);
        set.insert(l[j]);
        set.insert(l[k]);
        if(set.size()!=3){
          continue;
        }
        int max=std::max({l[i],l[j],l[k]});
        int sum=l[i]+l[j]+l[k]-max;
        if(max<sum){
          ans++;
          // std::cerr<<i+1<<" "<<j+1<<" "<<k+1<<'\n';
        }
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}