#include <iostream>
#include <vector>
int main(){
  int n,k,q;
  std::cin>>n>>k>>q;
  std::vector<int> win_cnt(n+1);
  for(int i=1;i<=q;i++){
    int a;
    std::cin>>a;
    win_cnt[a]++;
  }
  for(int i=1;i<=n;i++){
    if(q-win_cnt[i]>=k){
      std::cout<<"No"<<'\n';
    }else{
      std::cout<<"Yes"<<'\n';
    }
  }
  return 0;
}