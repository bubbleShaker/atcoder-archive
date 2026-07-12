#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::map<int,int> map;
  long long zero_cnt=0;
  long long ans=0;
  for(int i=n-1;i>=0;i--){
    if(a[i]==0){
      ans+=n-(i+1);
      zero_cnt++;
      continue;
    }
    int max_sqrt=1;
    for(int d=1;d*d<=a[i];d++){ //a[i]以下のa[i]を割り切れる最大の平方数を考える
      if(a[i]%(d*d)==0){
        max_sqrt=d*d;
      }
    }
    ans+=map[a[i]/max_sqrt]+zero_cnt;
    map[a[i]/max_sqrt]++;
  }
  std::cout<<ans<<'\n';
  return 0;
}