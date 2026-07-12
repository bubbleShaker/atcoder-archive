#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::vector<int> plus_dist(n),minus_dist(n);
  //右向き
  for(int i=0;i<n;i++){
    if(i==0){
      plus_dist[i]=std::min(a[i],1);
    }else{
      plus_dist[i]=std::min(plus_dist[i-1]+1,a[i]);
    }
  }
  //左向き 左に見て一番近い1or先頭までの距離の小さい方を記録
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      minus_dist[i]=std::min(a[i],1);
    }else{
      minus_dist[i]=std::min(minus_dist[i+1]+1,a[i]);
    }
  }
  // for(int i=0;i<n;i++){
  //   std::cout<<plus_dist[i]<<((i!=n-1)?' ':'\n');
  // }
  // for(int i=0;i<n;i++){
  //   std::cout<<minus_dist[i]<<((i!=n-1)?' ':'\n');
  // }
  int k_max=0;
  for(int i=0;i<n;i++){
    k_max=std::max(k_max,std::min(plus_dist[i],minus_dist[i])); //小さいほうの最大値を調べる
  }
  std::cout<<k_max<<'\n'; 
}