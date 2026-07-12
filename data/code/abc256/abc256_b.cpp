#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::reverse(a.begin(),a.end());
  int ans=0;
  for(int i=1;i<n;i++){
    a[i]+=a[i-1];
  }
  for(int i=0;i<n;i++){
    if(a[i]>=4){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}