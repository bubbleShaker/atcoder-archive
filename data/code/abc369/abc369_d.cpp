#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  const long long INF=4e18;
  int n;
  std::cin>>n;
  std::vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  //dp[0][i]:偶数番目にi番目を倒した時の最大経験値
  //dp[1][i]:奇数番目にi番目を倒した時の最大経験値
  std::vector dp(2,std::vector<long long>(n+1));
  dp[0][0]=0;
  dp[1][0]=-INF;
  for(int i=1;i<=n;i++){
    dp[0][i]=std::max(dp[0][i-1],dp[1][i-1]+2*a[i]);
    dp[1][i]=std::max(dp[1][i-1],dp[0][i-1]+a[i]);
  }
  std::cout<<std::max(dp[0][n],dp[1][n])<<'\n';
  return 0;
}