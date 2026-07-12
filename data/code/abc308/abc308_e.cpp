#include <iostream>
#include <vector>
#include <string>
#include <bitset>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::string s;
  std::cin>>s;
  const int CHAR_MAX=3;
  const int SET_MAX=(1<<4); //2^4 
  std::vector dp(n,std::vector<std::vector<long long>>(CHAR_MAX,std::vector<long long>(SET_MAX+1))); //setは今使っている値のビットを立てて保持
  auto make_bit=[&](int val){ //ビット列に変換 0→0,1→10,2→100 
    return 1<<val;
  };
  for(int i=0;i<n;i++){
    int chr;
    if(s[i]=='M'){
      chr=0;
    }else if(s[i]=='E'){
      chr=1;
    }else if(s[i]=='X'){
      chr=2;
    }
    
    if(i==0){
      if(chr==0){
        dp[i][chr][make_bit(a[i])]++;
      }
    }else{
      dp[i]=dp[i-1]; //前の状態をコピー
      for(int dp_chr=0;dp_chr<3;dp_chr++){
        if(dp_chr==chr){ //見ているcharと更新するcharが等しいなら、遷移を考える
          if(chr==0){ //chr=0(si=M)ならば
            dp[i][dp_chr][make_bit(a[i])]++; //今見ている状態を記録
          }else{ //si=Eまたはsi=Xならば、前の状態からの遷移を全探索
            for(int prev_set=0;prev_set<=SET_MAX;prev_set++){
              std::bitset<4> prev_bitset(prev_set);
              std::bitset<4> ai_bitset(make_bit(a[i]));
              std::bitset<4> new_bitset=prev_bitset|ai_bitset;
              int new_set=(int)new_bitset.to_ullong(); //intにキャスト
              // int new_set=prev_set|make_bit(a[i]); //今のaiを使用済みにする
              dp[i][dp_chr][new_set]+=dp[i-1][dp_chr-1][prev_set]; //prev_setで遷移が存在するならそこから新しい遷移を考える
            }
          }
        }
      }
    }
  }
  auto calc_mex=[&](int val){ //小さい桁から見て最初の0がmex
    std::bitset<4> bitset(val);
    for(int i=0;i<=3;i++){
      if(!bitset[i]){
        return i;
      }
    }
    return -1;
  };
  long long ans=0;
  for(int set=0;set<=SET_MAX;set++){
    int mex=calc_mex(set);
    ans+=(long long)mex*dp[n-1][2][set];
  }
  std::cout<<ans<<'\n';
  return 0;
}