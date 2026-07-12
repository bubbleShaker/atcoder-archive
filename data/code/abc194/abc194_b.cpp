#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  const int INF=1e9;
  int n;
  std::cin>>n;
  std::vector<int> a(n),b(n);
  int ans=INF;
  for(int i=0;i<n;i++){
    std::cin>>a[i]>>b[i];
    ans=std::min(ans,a[i]+b[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        continue;
      }
      ans=std::min(ans,std::max(a[i],b[j]));
      ans=std::min(ans,std::max(a[j],b[i]));
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}