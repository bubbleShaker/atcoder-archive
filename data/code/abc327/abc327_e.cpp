#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
int main(){
  const int INF=1e9;
  int n;
  std::cin>>n;
  std::vector<double> p(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>p[i];
  }
  std::vector<std::vector<double>> dp(n+1,std::vector<double>(n+1));//dp[i][j]:1~i個目の中からj個選んだ時の与式の最大値
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      if(1<=j&&j<=i-1){
        dp[i][j]=std::max(0.9*dp[i-1][j-1]+p[i],dp[i-1][j]);
      }else if(i==j){
        dp[i][j]=0.9*dp[i-1][j-1]+p[i];
      }
    }
  }
  auto calc_bunbo=[&](double k){
    double ret=0;
    for(int i=1;i<=(int)k;i++){
      ret+=pow(0.9,k-i);
    }
    return ret;
  };
  double ans=-(double)INF;
  for(int k=1;k<=n;k++){
    ans=std::max(ans,dp[n][k]/calc_bunbo(k)-1200/std::sqrt(k));
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans<<'\n';
  return 0;
}