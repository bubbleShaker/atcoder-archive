#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
int main(){
  const int INF=1e9+1;
  int n;
  std::cin>>n;
  std::vector<std::pair<int,int>> xy(n);
  for(int i=0;i<n;i++){
    std::cin>>xy[i].first>>xy[i].second;
  }
  std::sort(xy.begin(),xy.end());
  auto is_ok=[&](int k){ //距離k以上となる点対が存在するならtrue
    int idx=-1;//idx以下の点は今見ている点とx座標がk以上離れている
    int y_max=-INF,y_min=INF;
    for(int now=0;now<n;now++){
      while(idx<n-1&&xy[idx+1].first<=xy[now].first-k){//今見ている点とk以上離れているなら更新
        idx++;
        y_max=std::max(y_max,xy[idx].second); //x座標がk以上離れている点のyの最大値を更新
        y_min=std::min(y_min,xy[idx].second); //x座標がk以上離れている点のyの最大値を更新
      }
      if(y_max>=xy[now].second+k||y_min<=xy[now].second-k){ //x座標がk以上離れている点でy座標がk以上離れている点がある場合
        return true; //距離k以上となる点対が存在するのてtrue
      }
    }
    // std::cout<<"k is "<<k<<'\n';
    // std::cout<<"y_max is "<<y_max<<",y_min is "<<y_min<<'\n';
    return false; //最後まで見て存在しなかったのでfalse
  };
  int ok=0; //距離0以上となる点対は必ず存在する
  int ng=INF;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(is_ok(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  std::cout<<ok<<'\n';
  return 0;
}