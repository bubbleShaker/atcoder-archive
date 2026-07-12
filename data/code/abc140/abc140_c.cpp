#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  std::vector<int> a(n,INF);
  for(int i=0;i<n-1;i++){
    int b;
    std::cin>>b;
    a[i]=std::min(a[i],b);
    a[i+1]=b;
  }
  int ans=std::accumulate(a.begin(),a.end(),0);
  std::cout<<ans<<'\n';
  return 0;
}