#include <iostream>
#include <vector>
#include <bitset>
int main(){
  int n,q;
  std::cin>>n>>q;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  //穴iにいた2^0日後の場所:dp[0][i]
  //穴iにいた2^1日後の場所:dp[1][i]
  //穴iにいた2^2日後の場所:dp[2][i]
  //穴iにいた2^3日後の場所:dp[3][i]
  std::vector dp(60,std::vector<int>(n+1));
  //初期値の代入
  for(int i=1;i<=n;i++){
    dp[0][i]=a[i]; //穴iの1日後の場所
  }
  //前計算
  //1日後の1日後は2日後
  //dp[1][i]=dp[0][dp[0][i]]
  //2日後の2日後は4日後
  //dp[2][i]=dp[1][dp[1][i]]
  //4日後の4日後は8日後
  //dp[3][i]=dp[2][dp[2][i]]
  for(int i=1;i<=59;i++){
    for(int j=1;j<=n;j++){
      dp[i][j]=dp[i-1][dp[i-1][j]];
    }
  }
  //場所xにいる時、y日後にいる場所を求める
  //例:穴2にいた13日後の場所
  //13=2^3+2^2+2^0
  //穴2にいた8日後の場所はdp[3][2]=3
  //穴3にいた4日後の場所はdp[2][3]=7
  //穴7にいた1日後の場所はdp[0][7]=3
  auto calc=[&](int x,int y){
    int ret=x;
    std::bitset<60> bitset(y);
    for(int i=59;i>=0;i--){
      if(bitset[i]){
        ret=dp[i][ret];
      }
    }
    return ret;
  };
  while(q--){
    int x,y;
    std::cin>>x>>y;
    std::cout<<calc(x,y)<<'\n';
  }
  return 0;
}