#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
int main(){
  const long long INF=1e18;
  long long n,m;
  std::cin>>n>>m;
  std::vector<long long> a(m+1);
  for(long long i=1;i<=m;i++){
    std::cin>>a[i];
  }
  a.push_back(n+1);
  m++;
  std::sort(a.begin(),a.end());
  long long k=INF;
  long long nowIdx=0;
  std::vector<long long> str_vec;
  for(long long i=1;i<=m;i++){
    if(a[i]-nowIdx-1!=0){
      str_vec.push_back(a[i]-nowIdx-1);
      k=std::min(k,a[i]-nowIdx-1);
    }
    nowIdx=a[i];
  }
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  if(k==INF){
    std::cout<<0<<'\n';
  }else{
    long long ans=0;
    for(auto len:str_vec){
      ans+=ceilll(len,k);
    }
    std::cout<<ans<<'\n';
  }
  return 0;
}