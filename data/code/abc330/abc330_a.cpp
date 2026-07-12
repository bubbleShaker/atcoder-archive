#include <iostream>
#include <vector>
int main(){
  int n,l;
  std::cin>>n>>l;
  std::vector<int> a(n);
  int ans=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    if(a[i]>=l){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}