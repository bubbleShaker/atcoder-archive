#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<long long> a(k);
  for(int i=0;i<k;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  long long cost=0; //初期解
  for(int i=0;i<k-1;i+=2){
    cost+=a[i+1]-a[i];
  }
  long long ans=cost;
  // std::cout<<ans<<'\n';
  if(k%2==0){ //偶数なら一意
    std::cout<<ans<<'\n';
  }else{
    for(int i=k-2;i>=1;i-=2){
      cost+=a[i+1]-a[i];
      cost-=a[i]-a[i-1];
      // std::cout<<cost<<'\n';
      ans=std::min(ans,cost); //最小値の更新
    }
    std::cout<<ans<<'\n';
  }
  return 0;
}