#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Doubling{
private:
  T n;
  vector<vector<T>> dp;
  void init(){
    //今回は日数の最大値が10^9なので、2^29程度まで計算すればよい
    //日数の最大値が10^18とかなら、2^59程度まで計算することになりそう…?
    dp.resize(30,vector<T>(n+1));
    auto sumDigit=[&](int num){
      int ret=0;
      while(num>0){
        ret+=num%10;
        num/=10;
      }
      return ret;
    };
    //初期値の代入
    for(int i=1;i<=n;i++){
      dp[0][i]=i-sumDigit(i);
    }
    //前計算
    for(int i=1;i<=29;i++){
      for(int j=1;j<=n;j++){
        dp[i][j]=dp[i-1][dp[i-1][j]];
      }
    }
  }
public:
  Doubling(T num):n(num){
    init();
  }
  //場所xにいる時、y日後にいる場所を求める
  T calcPos(T x,T y){
    T curPos=x;
    for(int d=29;d>=0;d--){
      if(y&(1<<d)){
        curPos=dp[d][curPos];
      }
    }
    return curPos;
  }
};
int main(){
  int n,k;
  cin>>n>>k;
  Doubling<int> dling(n);
  for(int i=1;i<=n;i++){
    cout<<dling.calcPos(i,k)<<endl;
  }
  return 0;
}