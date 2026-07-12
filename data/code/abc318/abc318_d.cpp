#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  int old_n=n;
  bool has_dummy=false;
  if(n%2){
    has_dummy=true;
    n++;
  }
  std::vector d(n,std::vector<long long>(n));
  for(int i=0;i<old_n-1;i++){
    for(int j=i+1;j<old_n;j++){
      std::cin>>d[i][j];
    }
  }
  std::vector<bool> is_used(n);//n人分
  long long sum=0;//コスト
  long long ans=0;//答え
  auto dfs=[&](auto dfs,int first,int second)->void{
    // std::cout<<first<<" "<<second<<",";
    is_used[first]=true; //使う人を確認済みにする
    is_used[second]=true;
    sum+=d[first][second]; //{first,second}を使ったコストの計算
    bool finised=true;
    for(int i=0;i<n;i++){ //n人全てを見たかどうかを確認
      if(is_used[i]==false){
        finised=false;
      }
    }
    if(finised){ //n人全てを見ているなら答えの更新
      ans=std::max(ans,sum);
      // std::cout<<'\n';
    }else{
      int nfirst; //次のpairのfirst
      for(int i=0;i<n;i++){ 
        if(is_used[i]==false){ //使われていない人の中で最小の人を選ぶ
          nfirst=i;
          break;
        }
      }
      for(int nsecond=nfirst+1;nsecond<n;nsecond++){ //次のpairのsecondを決める
        if(is_used[nsecond]==false){ //nsecondが使われていないなら
          dfs(dfs,nfirst,nsecond); //{nfirst,nsecond}を使う遷移を考える
        }
      }
    }
    is_used[first]=false; //抜ける時に確認済みを外す
    is_used[second]=false;
    sum-=d[first][second]; //コストの計算も使用分を戻す
  };
  for(int i=1;i<n;i++){ //firstを0に固定してsecondをfor文で決める
    dfs(dfs,0,i);
  }
  std::cout<<ans<<'\n';
  return 0;
}