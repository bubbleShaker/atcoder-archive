#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::vector<int>> a(3,std::vector<int>(n+1));
  for(int i=1;i<=2;i++){
    for(int j=1;j<=n;j++){
      std::cin>>a[i][j];
    }
  }
  std::vector<std::vector<int>> dp(3,std::vector<int>(n+1));//dp[i][j]:マス(i,j)で持ちうる最大アメ数
  dp[1][1]=a[1][1];
  for(int j=2;j<=n;j++){
    dp[1][j]+=dp[1][j-1]+a[1][j];
  }
  dp[2][1]=dp[1][1]+a[2][1];
  for(int j=2;j<=n;j++){
    dp[2][j]=std::max(dp[2][j-1],dp[1][j])+a[2][j];
  }
  std::cout<<dp[2][n]<<'\n';
  return 0;
}