#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  int max=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    max=std::max(max,a[i]);
  }
  int cnt_max=0;
  int ans;
  for(int k=2;k<=max;k++){
    int cnt=0;
    for(int i=0;i<n;i++){
      if(a[i]%k==0){
        cnt++;
      }
    }
    if(cnt>cnt_max){
      cnt_max=cnt;
      ans=k;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}