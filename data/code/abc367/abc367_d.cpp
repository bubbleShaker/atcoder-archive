#include <iostream>
#include <vector>
int main(){
  int n;
  long long m;
  std::cin>>n>>m;
  std::vector<long long> a(n);
  std::vector<long long> dist(2*n+10);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<2*n-2;i++){
    dist[i+1]=dist[i]+a[i%n];
    dist[i+1]%=m; //mod mでの値に変換
  }
  std::vector<long long> rsw(m); //m通りの累積和を保持しておく
  for(int i=0;i<n;i++){
    rsw[dist[i]]++; //最初のn個を見ておく
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    ans+=rsw[dist[i]]-1;
    rsw[dist[i]]--;
    rsw[dist[i+n]]++;
  }
  std::cout<<ans<<'\n';
  return 0;
}