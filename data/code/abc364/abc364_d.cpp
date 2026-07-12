#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int INF=2e8;
  int n,q;
  std::cin>>n>>q;
  std::vector<int> a(n),b(q),k(q);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<q;i++){
    std::cin>>b[i]>>k[i];
  }
  std::sort(a.begin(),a.end()); //aに2分探索をするので…
  auto isOk=[&](int dist,int base,int kk){ //baseからの距離がdist以下である点の個数cntを求め、cnt>=kkならばtrueを返す
    int left_ind=std::lower_bound(a.begin(),a.end(),base-dist)-a.begin();
    int right_ind=std::upper_bound(a.begin(),a.end(),base+dist)-a.begin();
    right_ind--;
    int cnt=right_ind-left_ind+1; //baseから距離dist内にあるaの要素数
    return cnt>=kk;
  };
  for(int i=0;i<q;i++){
    int ok=INF;
    int ng=-1;
    while(abs(ok-ng)>1){
      int mid=(ok+ng)/2;
      if(isOk(mid,b[i],k[i])){//個数がk[i]以上ならばtrue
        ok=mid;
      }else{
        ng=mid;
      }
    }
    std::cout<<ok<<'\n'; //b[i]からの距離がそのまま答え
  }
  return 0;
}