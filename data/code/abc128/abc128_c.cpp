#include <iostream>
#include <vector>
int main(){
  std::cin.tie(nullptr);//標準入力時に出力ストリームバッファのフラッシュ(バッファの初期化)をしないようにする。そのため入力処理を高速化できる。
  std::ios_base::sync_with_stdio(false);//<cstdio>での入出力関数(scanf,prinfなど)と<iostream>での入出力関数(std::std::cin,std::std::coutなど)のストリームの同期を解除する。同期処理が無くなり、入出力の処理を高速化できる。
  int n,m;
  std::cin>>n>>m;
  std::vector<std::vector<int>> s(m);
  for(int i=0;i<m;i++){
    int k;
    std::cin>>k;
    for(int j=0;j<k;j++){
      int val;
      std::cin>>val;
      val--;
      s[i].push_back(val);
    }
  }
  std::vector<int> p(m);
  for(int i=0;i<m;i++){
    std::cin>>p[i];
  }
  int ans=0;
  for(int bit=0;bit<(1<<n);bit++){
    bool isOk=true;
    for(int i=0;i<m;i++){
      int cnt=0;
      for(auto val:s[i]){
        if(bit&(1<<val)){
          cnt++;
        }
      }
      if(cnt%2!=p[i]){
        isOk=false;
        break;
      }
    }
    if(isOk){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}