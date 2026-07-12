#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  std::vector<int> a(3);
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  int ans=0;
  while(std::max(a[0],a[1])<a[2]){
    a[0]++;
    a[1]++;
    ans++;
  }
  int diff=a[2]-std::min(a[0],a[1]);
  if(diff%2==0){
    ans+=diff/2;
  }else{
    ans+=diff/2+2;
  }
  std::cout<<ans<<'\n';
  return 0;
}