#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int main(){
  const long long INF=2e14+1;
  int n;
  long long M;
  std::cin>>n>>M;
  std::vector<long long> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  if(std::accumulate(a.begin(),a.end(),0LL)<=M){
    std::cout<<"infinite"<<'\n';
    return 0;
  }

  auto isOk=[&](long long mid){//総和がM円以下ならtrue
    long long sum=0;
    for(int i=0;i<n;i++){
      sum+=std::min(mid,a[i]);
    }
    return sum>M;
  };
  long long ok=INF;
  long long ng=0;
  while(abs(ok-ng)>1){
    long long mid=(ok+ng)/2;
    if(isOk(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  std::cout<<ng<<'\n';
  return 0;
}