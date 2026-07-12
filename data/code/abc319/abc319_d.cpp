#include <iostream>
#include <vector>
int main(){
  const long long INF=4e18;
  int n,m;
  std::cin>>n>>m;
  std::vector<long long> l(n);
  for(int i=0;i<n;i++){
    std::cin>>l[i];
  }
  auto is_ok=[&](long long width){ //幅widthの時にm行以下にすることができるならtrue
    int cnt=1;//列のカウント
    long long sum=0;//行の列の長さの合計
    for(int i=0;i<n;i++){
      if(l[i]>width){
        return false;
      }
      if(sum+l[i]>width){
        sum=l[i]+1;
        cnt++;
      }else{
        sum+=l[i]+1;
      }
    }
    return cnt<=m;
  };
  long long ok=INF;
  long long ng=0;
  while(abs(ok-ng)>1){
    long long mid=(ok+ng)/2;
    if(is_ok(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  std::cout<<ok<<'\n';
  return 0;
}