#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  long long INF=1e18;
  int n,k;
  std::cin>>n>>k;
  std::vector<long long> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  auto isOk=[&](long long x){ //x個のプロジェクトを作成可能ならばtrueを返す
    long long sum=0;
    for(int i=0;i<n;i++){
      sum+=std::min(a[i],x);
    }
    return sum>=x*k;
  };
  long long ok=1;//最低1つは必ず作れる
  long long ng=INF/k;
  while(abs(ok-ng)>1){
    long long mid=(ok+ng)/2;
    if(isOk(mid)){ //mid個のプロジェクトが作成可能ならばtrue
      ok=mid;
    }else{
      ng=mid;
    }
  }
  std::cout<<ok<<'\n';
  return 0;
}