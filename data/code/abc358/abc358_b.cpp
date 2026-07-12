#include <iostream>
#include <vector>
int main(){
  int n,a;
  std::cin>>n>>a;
  std::vector<int> t(n),ans(n);
  for(int i=0;i<n;i++){
    std::cin>>t[i];
  }
  ans[0]=t[0]+a;
  for(int i=1;i<n;i++){
    if(t[i]<=ans[i-1]){// 順番待ちにいる場合
      ans[i]=ans[i-1]+a;
    }else{// 順番を待たずに手続きを開始する場合
      ans[i]=t[i]+a;
    }
  }
  for(int i=0;i<n;i++){
    std::cout<<ans[i]<<'\n';
  }
  return 0;
}