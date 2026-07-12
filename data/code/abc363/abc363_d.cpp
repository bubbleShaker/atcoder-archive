#include <iostream>
#include <string>
#include <vector>
int main(){
  long long n;
  std::cin>>n;
  if(n<=10){ //nが10以下の場合は例外処理
    std::cout<<n-1<<'\n';
    return 0;
  }
  long long sum=0;//既に見た回文数の個数の合計
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  for(int k=1;;k++){ //k:回文数の桁数
    long long cnt=1;//k桁の回文数の個数を求める
    for(int i=0;i<ceili(k,2);i++){
      if(k==1){ //1桁の時は例外処理
        cnt=10;
        break;
      }
      if(i==0){
        cnt*=9;
      }else{
        cnt*=10;
      }
    }
    // std::cout<<"cnt is "<<cnt<<'\n';
    if(sum+cnt<n){ //今の桁数にn番目の回文数が含まれていない場合
      sum+=cnt;//次の桁に遷移する
      // std::cout<<"sum is "<<sum<<'\n';
    }else{ //今の桁数にn番目の回文数が含まれている場合
      long long l=n-sum;//k桁でl番目に大きい回文数を求める
      // std::cout<<"l is "<<l<<'\n';
      if(k==2){ //k=2の時も例外処理
        std::cout<<l<<l<<'\n';
        return 0; //終了
      }
      long long base_num=l+powll(10,ceili(k,2)-1)-1;
      // std::cout<<"base_num is "<<base_num<<'\n';
      std::string base_str=std::to_string(base_num);
      std::vector<int> ans(k);
      for(int i=0;i<base_str.size();i++){ //回文数の作成
        ans[i]=base_str[i]-'0';
        ans[k-i-1]=base_str[i]-'0';
      }
      for(int i=0;i<k;i++){ //答えの出力
        std::cout<<ans[i];
      }
      std::cout<<'\n';
      return 0; //プログラム終了
    }
  }
  return 0;
}